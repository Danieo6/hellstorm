#include "hellstorm_server_2d.h"
#include "./hellstorm_projectile_2d.h"

void HellStormProjectile2D::instantiate() {
	ERR_FAIL_COND_MSG(data.is_null(), "HellStormProjectileData2D is not defined!");
	ERR_FAIL_COND_MSG(data->get_collision_shape().is_null(), "Collision shape is not defined!");

	_update_texture_region();
	rs->canvas_item_set_parent(rid, _canvas);
	rs->canvas_item_set_transform(rid, transform);
	rs->canvas_item_set_interpolated(rid, data->get_enable_interpolation());
	rs->canvas_item_set_z_index(rid, data->get_z_index());

	_physics_query = Ref(memnew(PhysicsShapeQueryParameters2D));
	_physics_query->set_shape_rid(data->get_collision_shape()->get_rid());
	_physics_query->set_collision_mask(data->get_collision_mask());
	_physics_query->set_collide_with_bodies(data->get_collide_with_bodies());
	_physics_query->set_collide_with_areas(data->get_collide_with_areas());
	_physics_query->set_transform(transform);
}

void HellStormProjectile2D::projectile_process(const int p_idx, const double p_delta) {
	auto destroy_after = data->get_destroy_after_time();
	if (data->get_enable_destroy_after_time() && _lifetime > destroy_after) {
		queue_for_deletion();
		return;
	}

	_check_for_collisions();

	_handle_projectile_rotation(p_delta);

	float linear_speed = data->get_trajectory_config()->get_initial_speed() + data->get_trajectory_config()->get_acceleration() * _lifetime;
	linear_speed = std::clamp(linear_speed, data->get_trajectory_config()->get_min_speed(), data->get_trajectory_config()->get_max_speed());

	auto new_origin = transform.get_origin() + transform[0] * linear_speed * p_delta;
	transform.set_origin(new_origin);

	auto boundary = HellStormServer2D::get_instance()->get_boundary();
	if (data->get_enable_destroy_after_boundary_leave() && !boundary.has_point(transform.get_origin())) {
		queue_for_deletion();
		return;
	}

	_lifetime += p_delta;
	_animation_timer += p_delta;

	_projectile_draw(p_idx, p_delta);
}

void HellStormProjectile2D::queue_for_deletion() {
	if (data->get_enable_animation_after_destruction() && !_is_playing_last_animation) {
		_is_playing_last_animation = true;
		_animation_timer = 0;
		_current_cell = 0;
		return;
	}

	_is_queued_for_deletion = true;
}

void HellStormProjectile2D::destroy() {
	rs->canvas_item_clear(rid);
	rs->free_rid(rid);
}

bool HellStormProjectile2D::is_queued_for_deletion() {
	return _is_queued_for_deletion;
}

void HellStormProjectile2D::_handle_projectile_rotation(const double p_delta) {
	switch (data->get_trajectory_config()->get_type()) {
		case HellStormTrajectory2D::TrajectoryType2D::TRAJECTORY_LINEAR: {
			// Linear motion does not require any rotation
			break;
		}

		case HellStormTrajectory2D::TrajectoryType2D::TRAJECTORY_SINUSOIDAL: {
			auto config = Object::cast_to<SinusoidalTrajectoryConfig2D>(*data->get_trajectory_config());

			double current_angle = Math::sin(_lifetime * config->get_mod() + config->get_offset());
			double previous_angle = Math::sin((_lifetime - p_delta) * config->get_mod() + config->get_offset());
			double diff_angle = current_angle - previous_angle;

			transform = transform.rotated_local(diff_angle);
			break;
		}

		case HellStormTrajectory2D::TrajectoryType2D::TRAJECTORY_CURVED: {
			auto config = Object::cast_to<CurvedTrajectoryConfig2D>(*data->get_trajectory_config());

			float current_angle = _lifetime * config->get_angular_speed();
			float previous_angle = (_lifetime - p_delta) * config->get_angular_speed();
			float diff_angle = current_angle - previous_angle;

			transform = transform.rotated_local(diff_angle);
			break;
		}
		default: {
			WARN_PRINT("[HellStorm] Unsupported trajectory type!");
			break;
		}
	}
}

void HellStormProjectile2D::_projectile_draw(const int p_idx, const double p_delta) {
	if (_animation_timer > data->get_animation_speed()) {
		_animation_timer = 0;
		_current_cell += 1;
	}

	_update_texture_region();

	if (_is_playing_last_animation) {
		if (_current_cell == (data->get_cell_count() - 1)) {
			queue_for_deletion();
		}
		return;
	}

	auto rotation_speed =
		Math::deg_to_rad(data->get_initial_angle()) +
		Math::deg_to_rad(data->get_local_rotation_speed()) * _lifetime * p_delta;

	auto texture_transform = Transform2D().rotated(rotation_speed);
	texture_transform.set_origin(transform.get_origin());

	rs->canvas_item_set_transform(rid, texture_transform);
	rs->canvas_item_set_draw_index(rid, p_idx);
}

void HellStormProjectile2D::_update_texture_region() {
	if (_current_cell >= data->get_cell_count()) {
		if (data->get_enable_animation_loop()) {
			_current_cell = 0;
		} else {
			_current_cell = data->get_cell_count() - 1;
		}
	}

	auto cell_rect = Rect2(
		(real_t) (data->get_cell_width() * _current_cell),
		0,
		(real_t) data->get_cell_width(),
		(real_t) data->get_cell_height()
	);

	rs->canvas_item_clear(rid);
	rs->canvas_item_add_texture_rect_region(rid, _rect, data->get_texture()->get_rid(), cell_rect);
}

void HellStormProjectile2D::_check_for_collisions() {
	if (_is_playing_last_animation) {
		return;
	}

	auto space_state = ps->space_get_direct_state(_space);

	_physics_query->set_transform(transform);

	auto collisions = space_state->intersect_shape(_physics_query);

	for (int i = 0; i < collisions.size(); ++i) {
		_handle_collision(collisions[i]);
	}
}

void HellStormProjectile2D::_handle_collision(const Dictionary &p_hit) {
	queue_for_deletion();

	Object *collider = Object::cast_to<Object>(p_hit["collider"]);

	if (collider->has_method(data->get_hit_callback_name())) {
		collider->call(data->get_hit_callback_name(), transform.get_origin(), data->get_meta());
	}
}

HellStormProjectile2D::HellStormProjectile2D(
	const HellStormProjectileConfig2D &p_projectile_config,
	const Ref<HellStormProjectileData2D> &p_projectile_data
) {
	rs = RenderingServer::get_singleton();
	ps = PhysicsServer2D::get_singleton();

	rid = rs->canvas_item_create();
	data = p_projectile_data;

	transform = p_projectile_config.transform;
	_canvas = p_projectile_config.canvas;
	_space = p_projectile_config.space;
	_current_cell = p_projectile_data->get_current_cell();
	_rect = Rect2(
		-Vector2(data->get_cell_width(), data->get_cell_height()) / 2.0,
		Vector2(data->get_cell_width(), data->get_cell_height())
	);
}

HellStormProjectile2D::~HellStormProjectile2D() {}
