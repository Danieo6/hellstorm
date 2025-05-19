#include "./hellstorm_server_2d.h"

void HellStormServer2D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("initialize", "canvas", "space"), &HellStormServer2D::initialize);
	ClassDB::bind_method(D_METHOD("spawn_projectile", "HellStormProjectileData2D", "transform"), &HellStormServer2D::spawn_projectile);
	ClassDB::bind_method(D_METHOD("get_projectiles_count"), &HellStormServer2D::get_projectiles_count);
}

void HellStormServer2D::_notification(const int p_what) {
	if (p_what != NOTIFICATION_PHYSICS_PROCESS || !_is_initialized) {
		return;
	}

	_server_process();
}

void HellStormServer2D::_server_process() {
	_handle_projectile_buffer();

	auto idx = 0;
	auto delta = get_physics_process_delta_time();
	for (const auto &[k, projectile] : _projectiles) {
		if (projectile->is_queued_for_deletion()) {
			_projectile_trash_buffer.push(projectile);
			continue;
		}

		projectile->projectile_process(idx, delta);
		++idx;
	}

	while(_projectile_trash_buffer.size() > 0) {
		auto projectile_to_destroy = _projectile_trash_buffer.front();
		_projectile_trash_buffer.pop();

		_projectiles.erase(projectile_to_destroy->rid.get_id());
		delete projectile_to_destroy;
	}
}

void HellStormServer2D::_handle_projectile_buffer() {
	while(_projectile_buffer.size() > 0) {
		auto projectile = _projectile_buffer.front();
		_projectile_buffer.pop();

		projectile->instantiate();
		_projectiles[projectile->rid.get_id()] = projectile;
	}
}

void HellStormServer2D::initialize(
	const RID &p_canvas,
	const RID &p_space
) {
	if (_is_initialized) {
		WARN_PRINT("HellStorm is already initialized!");
		return;
	}

	_canvas = p_canvas;
	_space = p_space;

	_is_initialized = true;

	set_physics_process(true);
}

RID HellStormServer2D::spawn_projectile(
	const Ref<HellStormProjectileData2D> &p_projectile_data,
	const Transform2D &p_transform
) {
	auto config = HellStormProjectileConfig2D();
	config.transform = p_transform;
	config.canvas = _canvas;
	config.space = _space;

	auto projectile = new HellStormProjectile2D(config, p_projectile_data);

	_projectile_buffer.push(projectile);

	return projectile->rid;
}

int HellStormServer2D::get_projectiles_count() {
	return _projectiles.size();
}

HellStormServer2D::HellStormServer2D() {}
