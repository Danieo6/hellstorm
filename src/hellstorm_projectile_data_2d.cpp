#include "./hellstorm_projectile_data_2d.h"

#include <godot_cpp/core/class_db.hpp>

void HellStormProjectileData2D::_bind_methods() {
	// Display
	ClassDB::bind_method(D_METHOD("set_texture", "texture"), &HellStormProjectileData2D::set_texture);
	ClassDB::bind_method(D_METHOD("get_texture"), &HellStormProjectileData2D::get_texture);
	ClassDB::bind_method(D_METHOD("set_material", "material"), &HellStormProjectileData2D::set_material);
	ClassDB::bind_method(D_METHOD("get_material"), &HellStormProjectileData2D::get_material);
	ClassDB::bind_method(D_METHOD("set_cell_width", "width"), &HellStormProjectileData2D::set_cell_width);
	ClassDB::bind_method(D_METHOD("get_cell_width"), &HellStormProjectileData2D::get_cell_width);
	ClassDB::bind_method(D_METHOD("set_cell_height", "height"), &HellStormProjectileData2D::set_cell_height);
	ClassDB::bind_method(D_METHOD("get_cell_height"), &HellStormProjectileData2D::get_cell_height);
	ClassDB::bind_method(D_METHOD("set_cell_count", "count"), &HellStormProjectileData2D::set_cell_count);
	ClassDB::bind_method(D_METHOD("get_cell_count"), &HellStormProjectileData2D::get_cell_count);
	ClassDB::bind_method(D_METHOD("set_current_cell", "cell"), &HellStormProjectileData2D::set_current_cell);
	ClassDB::bind_method(D_METHOD("get_current_cell"), &HellStormProjectileData2D::get_current_cell);
	ClassDB::bind_method(D_METHOD("set_animation_speed", "speed"), &HellStormProjectileData2D::set_animation_speed);
	ClassDB::bind_method(D_METHOD("get_animation_speed"), &HellStormProjectileData2D::get_animation_speed);
	ClassDB::bind_method(D_METHOD("set_enable_animation_loop", "loop"), &HellStormProjectileData2D::set_enable_animation_loop);
	ClassDB::bind_method(D_METHOD("get_enable_animation_loop"), &HellStormProjectileData2D::get_enable_animation_loop);
	ClassDB::bind_method(D_METHOD("set_initial_angle", "speed"), &HellStormProjectileData2D::set_initial_angle);
	ClassDB::bind_method(D_METHOD("get_initial_angle"), &HellStormProjectileData2D::get_initial_angle);

	// Motion
	ClassDB::bind_method(D_METHOD("set_trajectory_config", "config"), &HellStormProjectileData2D::set_trajectory_config);
	ClassDB::bind_method(D_METHOD("get_trajectory_config"), &HellStormProjectileData2D::get_trajectory_config);
	ClassDB::bind_method(D_METHOD("set_local_rotation_speed", "rotation_speed"), &HellStormProjectileData2D::set_local_rotation_speed);
	ClassDB::bind_method(D_METHOD("get_local_rotation_speed"), &HellStormProjectileData2D::get_local_rotation_speed);

	// Physics
	ClassDB::bind_method(D_METHOD("set_collision_shape", "shape"), &HellStormProjectileData2D::set_collision_shape);
	ClassDB::bind_method(D_METHOD("get_collision_shape"), &HellStormProjectileData2D::get_collision_shape);
	ClassDB::bind_method(D_METHOD("set_collision_mask", "mask"), &HellStormProjectileData2D::set_collision_mask);
	ClassDB::bind_method(D_METHOD("get_collision_mask"), &HellStormProjectileData2D::get_collision_mask);
	ClassDB::bind_method(D_METHOD("set_collide_with_bodies", "enable"), &HellStormProjectileData2D::set_collide_with_bodies);
	ClassDB::bind_method(D_METHOD("get_collide_with_bodies"), &HellStormProjectileData2D::get_collide_with_bodies);
	ClassDB::bind_method(D_METHOD("set_collide_with_areas", "enable"), &HellStormProjectileData2D::set_collide_with_areas);
	ClassDB::bind_method(D_METHOD("get_collide_with_areas"), &HellStormProjectileData2D::get_collide_with_areas);
	ClassDB::bind_method(D_METHOD("set_enable_interpolation", "enable"), &HellStormProjectileData2D::set_enable_interpolation);
	ClassDB::bind_method(D_METHOD("get_enable_interpolation"), &HellStormProjectileData2D::get_enable_interpolation);

	// Behaviour
	ClassDB::bind_method(D_METHOD("set_hit_callback_name", "name"), &HellStormProjectileData2D::set_hit_callback_name);
	ClassDB::bind_method(D_METHOD("get_hit_callback_name"), &HellStormProjectileData2D::get_hit_callback_name);
	ClassDB::bind_method(D_METHOD("set_meta", "meta"), &HellStormProjectileData2D::set_meta);
	ClassDB::bind_method(D_METHOD("get_meta"), &HellStormProjectileData2D::get_meta);
	ClassDB::bind_method(D_METHOD("set_enable_destroy_after_boundary_leave", "enable"), &HellStormProjectileData2D::set_enable_destroy_after_boundary_leave);
	ClassDB::bind_method(D_METHOD("get_enable_destroy_after_boundary_leave"), &HellStormProjectileData2D::get_enable_destroy_after_boundary_leave);
	ClassDB::bind_method(D_METHOD("set_enable_destroy_after_time", "enable"), &HellStormProjectileData2D::set_enable_destroy_after_time);
	ClassDB::bind_method(D_METHOD("get_enable_destroy_after_time"), &HellStormProjectileData2D::get_enable_destroy_after_time);
	ClassDB::bind_method(D_METHOD("set_destroy_after_time", "time"), &HellStormProjectileData2D::set_destroy_after_time);
	ClassDB::bind_method(D_METHOD("get_destroy_after_time"), &HellStormProjectileData2D::get_destroy_after_time);

	// Display
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "texture", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "set_texture", "get_texture");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "initial_angle"), "set_initial_angle", "get_initial_angle");

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "Display/material", PROPERTY_HINT_RESOURCE_TYPE, "Material"), "set_material", "get_material");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "Display/cell_width"), "set_cell_width", "get_cell_width");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "Display/cell_height"), "set_cell_height", "get_cell_height");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "Display/current_cell"), "set_current_cell", "get_current_cell");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Display/animation_speed"), "set_animation_speed", "get_animation_speed");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "Display/animation_loop"), "set_enable_animation_loop", "get_enable_animation_loop");

	// Motion
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "Motion/trajectory_config", PROPERTY_HINT_RESOURCE_TYPE, "LinearTrajectoryConfig2D"), "set_trajectory_config", "get_trajectory_config");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Motion/local_rotation_speed"), "set_local_rotation_speed", "get_local_rotation_speed");

	// Physics
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "Physics/collision_shape", PROPERTY_HINT_RESOURCE_TYPE, "Shape2D"), "set_collision_shape", "get_collision_shape");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "Physics/collision_mask", PROPERTY_HINT_LAYERS_2D_PHYSICS, ""), "set_collision_mask", "get_collision_mask");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "Physics/collide_with_bodies"), "set_collide_with_bodies", "get_collide_with_bodies");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "Physics/collide_with_areas"), "set_collide_with_areas", "get_collide_with_areas");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "Physics/enable_physics_interpolation"), "set_enable_interpolation", "get_enable_interpolation");

	// Behaviour
	ADD_PROPERTY(PropertyInfo(Variant::STRING_NAME, "Behaviour/hit_callback_name"), "set_hit_callback_name", "get_hit_callback_name");
	ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY, "Behaviour/meta"), "set_meta", "get_meta");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "Behaviour/enable_destroy_after_boundary_leave"), "set_enable_destroy_after_boundary_leave", "get_enable_destroy_after_boundary_leave");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "Behaviour/enable_destroy_after_time"), "set_enable_destroy_after_time", "get_enable_destroy_after_time");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Behaviour/destroy_after_time"), "set_destroy_after_time", "get_destroy_after_time");
}

// Display
void HellStormProjectileData2D::set_texture(const Ref<Texture2D> &p_texture) {
	_texture = p_texture;

	_on_texture_update();
}

void HellStormProjectileData2D::_on_texture_update() {
	if (!_texture.is_null()) {
		_cell_width = _texture->get_size().x;
		_cell_height = _texture->get_size().y;
		_current_cell = 1;
	}
}

Ref<Texture2D> HellStormProjectileData2D::get_texture() const {
	return _texture;
}

void HellStormProjectileData2D::set_material(const Ref<Material> &p_material) {
	_material = p_material;
}

Ref<Material> HellStormProjectileData2D::get_material() const {
	return _material;
}

void HellStormProjectileData2D::set_cell_width(int p_width) {
	_cell_width = p_width;
	_cell_count = _texture->get_size().x / p_width;
}

int HellStormProjectileData2D::get_cell_width() const {
	return _cell_width;
}

void HellStormProjectileData2D::set_cell_height(int p_height) {
	_cell_height = p_height;
}

int HellStormProjectileData2D::get_cell_height() const {
	return _cell_height;
}

void HellStormProjectileData2D::set_cell_count(int p_count) {
	_cell_count = p_count;
}

int HellStormProjectileData2D::get_cell_count() const {
	return _cell_count;
}

void HellStormProjectileData2D::set_current_cell(int p_cell) {
	_current_cell = p_cell;
}

int HellStormProjectileData2D::get_current_cell() const {
	return _current_cell;
}

void HellStormProjectileData2D::set_animation_speed(float p_speed) {
	_animation_speed = p_speed;
}

float HellStormProjectileData2D::get_animation_speed() const {
	return _animation_speed;
}

void HellStormProjectileData2D::set_enable_animation_loop(bool p_loop) {
	_enable_animation_loop = p_loop;
}

bool HellStormProjectileData2D::get_enable_animation_loop() const {
	return _enable_animation_loop;
}

void HellStormProjectileData2D::set_initial_angle(const float p_angle) {
	_initial_angle = p_angle;
}

float HellStormProjectileData2D::get_initial_angle() const {
	return _initial_angle;
}

// Motion
void HellStormProjectileData2D::set_trajectory_config(const Ref<LinearTrajectoryConfig2D> &p_config) {
	_trajectory_config = p_config;
}

Ref<LinearTrajectoryConfig2D> HellStormProjectileData2D::get_trajectory_config() const {
	return _trajectory_config;
}

void HellStormProjectileData2D::set_local_rotation_speed(const float p_local_rotation_speed) {
	_local_rotation_speed = p_local_rotation_speed;
}

float HellStormProjectileData2D::get_local_rotation_speed() const {
	return _local_rotation_speed;
}

// Physics
void HellStormProjectileData2D::set_collision_shape(const Ref<Shape2D> &p_shape) {
	_collision_shape = p_shape;
}

Ref<Shape2D> HellStormProjectileData2D::get_collision_shape() const {
	return _collision_shape;
}

void HellStormProjectileData2D::set_collision_mask(const unsigned int p_mask) {
	_collision_mask = p_mask;
}

unsigned int HellStormProjectileData2D::get_collision_mask() const {
	return _collision_mask;
}

void HellStormProjectileData2D::set_collide_with_bodies(const bool p_value) {
	_collide_with_bodies = p_value;
}

bool HellStormProjectileData2D::get_collide_with_bodies() const {
	return _collide_with_bodies;
}

void HellStormProjectileData2D::set_collide_with_areas(const bool p_value) {
	_collide_with_areas = p_value;
}

bool HellStormProjectileData2D::get_collide_with_areas() const {
	return _collide_with_areas;
}

void HellStormProjectileData2D::set_enable_interpolation(const bool p_value) {
	_enable_interpolation = p_value;
}

bool HellStormProjectileData2D::get_enable_interpolation() const {
	return _enable_interpolation;
}

void HellStormProjectileData2D::set_hit_callback_name(const StringName p_name) {
	_hit_callback_name = p_name;
}

StringName HellStormProjectileData2D::get_hit_callback_name() const {
	return _hit_callback_name;
}

void HellStormProjectileData2D::set_meta(const Dictionary p_meta) {
	_meta = p_meta;
}

Dictionary HellStormProjectileData2D::get_meta() const {
	return _meta;
}

void HellStormProjectileData2D::set_enable_destroy_after_boundary_leave(const bool p_value) {
	_enable_destroy_after_boundary_leave = p_value;
}
bool HellStormProjectileData2D::get_enable_destroy_after_boundary_leave() const {
	return _enable_destroy_after_boundary_leave;
}

void HellStormProjectileData2D::set_enable_destroy_after_time(const bool p_value) {
	_enable_destroy_after_time = p_value;
}

bool HellStormProjectileData2D::get_enable_destroy_after_time() const {
	return _enable_destroy_after_time;
}

void HellStormProjectileData2D::set_destroy_after_time(const double p_time) {
	_destroy_after_time = p_time;
}

double HellStormProjectileData2D::get_destroy_after_time() const {
	return _destroy_after_time;
}

HellStormProjectileData2D::HellStormProjectileData2D() {
	_on_texture_update();

	_animation_speed = 0;
	_enable_animation_loop = true;

	_collision_mask = 1;
	_collide_with_bodies = true;
	_collide_with_areas = false;

	_hit_callback_name = "_on_hellstorm_projectile_hit";
	_enable_interpolation = true;
	_enable_destroy_after_boundary_leave = true;
	_enable_destroy_after_time = false;
	_destroy_after_time = 0.0;
}

HellStormProjectileData2D::~HellStormProjectileData2D() {}
