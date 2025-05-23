﻿#pragma once

#include <queue>
#include <unordered_map>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/rid.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include "./hellstorm_projectile_data_2d.h"
#include "./hellstorm_projectile_2d.h"

using namespace godot;

class HellStormServer2D : public Node {
	GDCLASS(HellStormServer2D, Node);

	private:
		static HellStormServer2D *_instance;
		bool _is_initialized = false;

		RID _canvas;
		RID _space;
		Rect2 _boundary;

		std::queue<HellStormProjectile2D*> _projectile_buffer;
		std::queue<HellStormProjectile2D*> _projectile_trash_buffer;
		std::unordered_map<uint64_t, HellStormProjectile2D*> _projectiles;

		void _server_process();
		void _handle_projectile_buffer();

	protected:
		static void _bind_methods();
		void _notification(const int p_what);

	public:
		static HellStormServer2D *get_instance();

		void initialize(
			const RID &p_canvas,
			const RID &p_space
		);

		RID spawn_projectile(
			const Ref<HellStormProjectileData2D> &p_projectile_data,
			const Transform2D &p_transform
		);

		int get_projectiles_count() const;

		void set_boundary(const Rect2 p_boundary);

		Rect2 get_boundary() const;

		HellStormServer2D();
};
