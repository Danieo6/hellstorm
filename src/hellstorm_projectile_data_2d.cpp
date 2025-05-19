#include "./hellstorm_projectile_data_2d.h"

#include <godot_cpp/core/class_db.hpp>

void HellStormProjectileData2D::_bind_methods() {
	// Display
	ClassDB::bind_method(D_METHOD("set_texture", "texture"), &HellStormProjectileData2D::set_texture);
	ClassDB::bind_method(D_METHOD("get_texture"), &HellStormProjectileData2D::get_texture);
	ClassDB::bind_method(D_METHOD("set_material", "material"), &HellStormProjectileData2D::set_material);
	ClassDB::bind_method(D_METHOD("get_material"), &HellStormProjectileData2D::get_material);
	ClassDB::bind_method(D_METHOD("set_initial_angle", "speed"), &HellStormProjectileData2D::set_initial_angle);
	ClassDB::bind_method(D_METHOD("get_initial_angle"), &HellStormProjectileData2D::get_initial_angle);

	// Motion
	ClassDB::bind_method(D_METHOD("set_initial_linear_speed", "speed"), &HellStormProjectileData2D::set_initial_linear_speed);
	ClassDB::bind_method(D_METHOD("get_initial_linear_speed"), &HellStormProjectileData2D::get_initial_linear_speed);
	ClassDB::bind_method(D_METHOD("set_min_linear_speed", "speed"), &HellStormProjectileData2D::set_min_linear_speed);
	ClassDB::bind_method(D_METHOD("get_min_linear_speed"), &HellStormProjectileData2D::get_min_linear_speed);
	ClassDB::bind_method(D_METHOD("set_max_linear_speed", "speed"), &HellStormProjectileData2D::set_max_linear_speed);
	ClassDB::bind_method(D_METHOD("get_max_linear_speed"), &HellStormProjectileData2D::get_max_linear_speed);
	ClassDB::bind_method(D_METHOD("set_acceleration", "acceleration"), &HellStormProjectileData2D::set_acceleration);
	ClassDB::bind_method(D_METHOD("get_acceleration"), &HellStormProjectileData2D::get_acceleration);
	ClassDB::bind_method(D_METHOD("set_local_rotation_speed", "rotation_speed"), &HellStormProjectileData2D::set_local_rotation_speed);
	ClassDB::bind_method(D_METHOD("get_local_rotation_speed"), &HellStormProjectileData2D::get_local_rotation_speed);

	// Physics
	ClassDB::bind_method(D_METHOD("set_collision_shape", "shape"), &HellStormProjectileData2D::set_collision_shape);
	ClassDB::bind_method(D_METHOD("get_collision_shape"), &HellStormProjectileData2D::get_collision_shape);
	ClassDB::bind_method(D_METHOD("set_collision_mask", "mask"), &HellStormProjectileData2D::set_collision_mask);
	ClassDB::bind_method(D_METHOD("get_collision_mask"), &HellStormProjectileData2D::get_collision_mask);
	ClassDB::bind_method(D_METHOD("set_collide_with_bodies", "enable"), &HellStormProjectileData2D::set_collide_with_bodies);
	ClassDB::bind_method(D_METHOD("is_collide_with_bodies"), &HellStormProjectileData2D::get_collide_with_bodies);
	ClassDB::bind_method(D_METHOD("set_collide_with_areas", "enable"), &HellStormProjectileData2D::set_collide_with_areas);
	ClassDB::bind_method(D_METHOD("is_collide_with_areas"), &HellStormProjectileData2D::get_collide_with_areas);

	// Behaviour
	ClassDB::bind_method(D_METHOD("set_hit_callback_name", "name"), &HellStormProjectileData2D::set_hit_callback_name);
	ClassDB::bind_method(D_METHOD("get_hit_callback_name"), &HellStormProjectileData2D::get_hit_callback_name);
	ClassDB::bind_method(D_METHOD("set_meta", "meta"), &HellStormProjectileData2D::set_meta);
	ClassDB::bind_method(D_METHOD("get_meta"), &HellStormProjectileData2D::get_meta);

	// Display
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "texture", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "set_texture", "get_texture");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "material", PROPERTY_HINT_RESOURCE_TYPE, "Material"), "set_material", "get_material");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "initial_angle"), "set_initial_angle", "get_initial_angle");

	// Motion
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Motion/initial_linear_speed"), "set_initial_linear_speed", "get_initial_linear_speed");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Motion/min_linear_speed"), "set_min_linear_speed", "get_min_linear_speed");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Motion/max_linear_speed"), "set_max_linear_speed", "get_max_linear_speed");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Motion/acceleration"), "set_acceleration", "get_acceleration");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Motion/local_rotation_speed"), "set_local_rotation_speed", "get_local_rotation_speed");

	// Physics
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "Physics/collision_shape", PROPERTY_HINT_RESOURCE_TYPE, "Shape2D"), "set_collision_shape", "get_collision_shape");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "Physics/collision_mask", PROPERTY_HINT_LAYERS_2D_PHYSICS, ""), "set_collision_mask", "get_collision_mask");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "Physics/collide_with_bodies"), "set_collide_with_bodies", "is_collide_with_bodies");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "Physics/collide_with_areas"), "set_collide_with_areas", "is_collide_with_areas");

	// Behaviour
	ADD_PROPERTY(PropertyInfo(Variant::STRING_NAME, "Behaviour/hit_callback_name"), "set_hit_callback_name", "get_hit_callback_name");
	ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY, "Behaviour/meta"), "set_meta", "get_meta");
}

// Display
void HellStormProjectileData2D::set_texture(const Ref<Texture2D> &p_texture) {
	_texture = p_texture;
}

Ref<Texture2D> HellStormProjectileData2D::get_texture() const  {
	return _texture;
}

void HellStormProjectileData2D::set_material(const Ref<Material> &p_material) {
	_material = p_material;
}

Ref<Material> HellStormProjectileData2D::get_material() const  {
	return _material;
}

void HellStormProjectileData2D::set_initial_angle(const float p_angle) {
	_initial_angle = p_angle;
}

float HellStormProjectileData2D::get_initial_angle() const {
	return _initial_angle;
}

// Motion
void HellStormProjectileData2D::set_initial_linear_speed(const float p_speed) {
	_initial_linear_speed = p_speed;
}

float HellStormProjectileData2D::get_initial_linear_speed() const {
	return _initial_linear_speed;
}

void HellStormProjectileData2D::set_min_linear_speed(const float p_speed) {
	_min_linear_speed = p_speed;
}

float HellStormProjectileData2D::get_min_linear_speed() const {
	return _max_linear_speed;
}

void HellStormProjectileData2D::set_max_linear_speed(const float p_speed) {
	_max_linear_speed = p_speed;
}

float HellStormProjectileData2D::get_max_linear_speed() const {
	return _max_linear_speed;
}

void HellStormProjectileData2D::set_acceleration(const float p_acceleration) {
	_acceleration = p_acceleration;
}

float HellStormProjectileData2D::get_acceleration() const {
	return _acceleration;
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

HellStormProjectileData2D::HellStormProjectileData2D() {
	_initial_linear_speed = 0;
	_min_linear_speed = 0;
	_max_linear_speed = 1200;
	_acceleration = 200;

	_collision_mask = 1;
	_collide_with_bodies = true;
	_collide_with_areas = false;

	_hit_callback_name = "_on_hellstorm_projectile_hit";
}

HellStormProjectileData2D::~HellStormProjectileData2D() {}
