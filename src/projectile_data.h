#pragma once

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/shape2d.hpp>

using namespace godot;

class ProjectileData : public Resource {
	GDCLASS(ProjectileData, Resource);

	private:
		Ref<Texture2D> _texture;
		Ref<Material> _material;
		float _initial_angle;

		float _initialLinearSpeed;
		float _minLinearSpeed;
		float _maxLinearSpeed;
		float _acceleration;

		Ref<Shape2D> _collisionShape;
		unsigned int _collisionMask;
		bool _collideWithBodies;
		bool _collideWithAreas;

		StringName _hit_callback_name = "_on_hellstorm_projectile_hit";
		Dictionary _meta;

	protected:
		static void _bind_methods();

	public:
		void set_texture(const Ref<Texture2D> &p_texture);
		Ref<Texture2D> get_texture() const;

		void set_material(const Ref<Material> &p_material);
		Ref<Material> get_material() const;

		void set_initial_angle(const float p_angle);
		float get_initial_angle() const;

		void set_initial_linear_speed(const float p_speed);
		float get_initial_linear_speed() const;

		void set_min_linear_speed(const float p_speed);
		float get_min_linear_speed() const;

		void set_max_linear_speed(const float p_speed);
		float get_max_linear_speed() const;

		void set_acceleration(const float p_acceleration);
		float get_acceleration() const;

		void set_collision_shape(const Ref<Shape2D> &p_shape);
		Ref<Shape2D> get_collision_shape() const;

		void set_collision_mask(const unsigned int p_mask);
		unsigned int get_collision_mask() const;

		void set_collide_with_bodies(const bool p_value);
		bool get_collide_with_bodies() const;

		void set_collide_with_areas(const bool p_value);
		bool get_collide_with_areas() const;

		void set_hit_callback_name(const StringName p_name);
		StringName get_hit_callback_name() const;

		void set_meta(const Dictionary p_meta);
		Dictionary get_meta() const;

		ProjectileData();
		~ProjectileData();
};
