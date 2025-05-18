#pragma once

#include <queue>
#include <unordered_map>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/rid.hpp>

#include "./projectile_data.h"
#include "./hellstorm_projectile_2d.h"

using namespace godot;

class HellStormServer2D : public Node {
	GDCLASS(HellStormServer2D, Node);

	private:
		bool _isInitialized = false;

		RID _canvas;
		RID _space;

		std::queue<HellStormProjectile2D*> _projectileBuffer;
		std::queue<HellStormProjectile2D*> _projectileTrashBuffer;
		std::unordered_map<uint64_t, HellStormProjectile2D*> _projectiles;

		void _server_process();
		void _handle_projectile_buffer();

	protected:
		static void _bind_methods();
		void _notification(const int p_what);

	public:
		void initialize(
			const RID &p_canvas,
			const RID &p_space
		);

		RID spawn_projectile(
			const Ref<ProjectileData> &p_projectileData,
			const Transform2D &p_transform
		);

		int get_projectiles_count();

		HellStormServer2D();
};
