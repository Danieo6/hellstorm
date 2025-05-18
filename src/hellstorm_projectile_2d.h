#pragma once

#include <algorithm>

#include <godot_cpp/variant/rid.hpp>
#include <godot_cpp/classes/rendering_server.hpp>
#include <godot_cpp/classes/physics_server2d.hpp>
#include <godot_cpp/classes/physics_direct_space_state2d.hpp>
#include <godot_cpp/classes/physics_shape_query_parameters2d.hpp>

#include "projectile_data.h"

using namespace godot;

struct HellStormProjectileConfig2D {
	Transform2D transform;
	RID canvas;
	RID space;
};

class HellStormProjectile2D {
	private:
		RenderingServer *rs = nullptr;
		PhysicsServer2D *ps = nullptr;
		Rect2 _rect;
		RID _canvas;
		RID _space;
		Ref<PhysicsShapeQueryParameters2D> _physics_query;

		double _lifetime = 0;
		bool _isQueuedForDeletion = false;

		void _projectile_draw(const int p_idx);
		void _check_for_collisions();
		void _handle_collision(const Dictionary &p_hit);

	public:
		RID rid;
		Ref<ProjectileData> data;
		Transform2D transform;

		void instantiate();
		void destroy();
		bool is_queued_for_deletion();
		void projectile_process(const int p_idx, const double p_delta);

		HellStormProjectile2D(
				const HellStormProjectileConfig2D &p_projectileConfig,
				const Ref<ProjectileData> &p_projectileData);
		~HellStormProjectile2D();
};
