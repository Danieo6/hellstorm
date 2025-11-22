#pragma once

#include "./hellstorm_projectile_trajectory_config_2d.h"

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/shape2d.hpp>

using namespace godot;

class HellStormProjectileData2D : public Resource {
	GDCLASS(HellStormProjectileData2D, Resource);

	protected:
		static void _bind_methods();

	public:
		void set_texture(const Ref<Texture2D> &p_texture);
		Ref<Texture2D> get_texture() const;

		void set_material(const Ref<Material> &p_material);
		Ref<Material> get_material() const;

		void set_cell_width(int p_width);
		int get_cell_width() const;

		void set_cell_height(int p_height);
		int get_cell_height() const;

		void set_cell_count(int p_count);
		int get_cell_count() const;

		void set_current_cell(int p_cell);
		int get_current_cell() const;

		void set_animation_speed(float p_speed);
		float get_animation_speed() const;

		void set_enable_animation_loop(bool p_enable_loop);
		bool get_enable_animation_loop() const;

		void set_initial_angle(const float p_angle);
		float get_initial_angle() const;

		void set_trajectory_config(const Ref<LinearTrajectoryConfig2D> &p_config);
		Ref<LinearTrajectoryConfig2D> get_trajectory_config() const;

		void set_local_rotation_speed(const float p_local_rotation_speed);
		float get_local_rotation_speed() const;

		void set_collision_shape(const Ref<Shape2D> &p_shape);
		Ref<Shape2D> get_collision_shape() const;

		void set_collision_mask(const unsigned int p_mask);
		unsigned int get_collision_mask() const;

		void set_collide_with_bodies(const bool p_value);
		bool get_collide_with_bodies() const;

		void set_collide_with_areas(const bool p_value);
		bool get_collide_with_areas() const;

		void set_enable_interpolation(const bool p_value);
		bool get_enable_interpolation() const;

		void set_hit_callback_name(const StringName p_name);
		StringName get_hit_callback_name() const;

		void set_meta(const Dictionary p_meta);
		Dictionary get_meta() const;

		void set_enable_destroy_after_boundary_leave(const bool p_value);
		bool get_enable_destroy_after_boundary_leave() const;

		void set_enable_destroy_after_time(const bool p_value);
		bool get_enable_destroy_after_time() const;

		void set_destroy_after_time(const double p_time);
		double get_destroy_after_time() const;

		void set_enable_animation_after_destruction(const bool p_value);
		bool get_enable_animation_after_destruction() const;

		HellStormProjectileData2D();
		~HellStormProjectileData2D();

	private:
		Ref<Texture2D> _texture;

		Ref<Material> _material;
		int _cell_width;
		int _cell_height;
		int _cell_count;
		int _current_cell;
		float _initial_angle;
		float _animation_speed;
		bool _enable_animation_loop;

		Ref<LinearTrajectoryConfig2D> _trajectory_config;
		float _local_rotation_speed;

		Ref<Shape2D> _collision_shape;
		unsigned int _collision_mask;
		bool _collide_with_bodies;
		bool _collide_with_areas;
		bool _enable_interpolation;

		StringName _hit_callback_name;
		bool _enable_destroy_after_boundary_leave;
		bool _enable_destroy_after_time;
		float _destroy_after_time;
		bool _enable_animation_after_destruction;
		Dictionary _meta;

		void _on_texture_update();
};
