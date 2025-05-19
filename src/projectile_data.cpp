#include "./projectile_data.h"

#include <godot_cpp/core/class_db.hpp>

void ProjectileData::_bind_methods() {
	// Display
	ClassDB::bind_method(D_METHOD("set_texture", "texture"), &ProjectileData::set_texture);
	ClassDB::bind_method(D_METHOD("get_texture"), &ProjectileData::get_texture);
	ClassDB::bind_method(D_METHOD("set_material", "material"), &ProjectileData::set_material);
	ClassDB::bind_method(D_METHOD("get_material"), &ProjectileData::get_material);
	ClassDB::bind_method(D_METHOD("set_initial_angle", "speed"), &ProjectileData::set_initial_angle);
	ClassDB::bind_method(D_METHOD("get_initial_angle"), &ProjectileData::get_initial_angle);

	// Motion
	ClassDB::bind_method(D_METHOD("set_initial_linear_speed", "speed"), &ProjectileData::set_initial_linear_speed);
	ClassDB::bind_method(D_METHOD("get_initial_linear_speed"), &ProjectileData::get_initial_linear_speed);
	ClassDB::bind_method(D_METHOD("set_min_linear_speed", "speed"), &ProjectileData::set_min_linear_speed);
	ClassDB::bind_method(D_METHOD("get_min_linear_speed"), &ProjectileData::get_min_linear_speed);
	ClassDB::bind_method(D_METHOD("set_max_linear_speed", "speed"), &ProjectileData::set_max_linear_speed);
	ClassDB::bind_method(D_METHOD("get_max_linear_speed"), &ProjectileData::get_max_linear_speed);
	ClassDB::bind_method(D_METHOD("set_acceleration", "acceleration"), &ProjectileData::set_acceleration);
	ClassDB::bind_method(D_METHOD("get_acceleration"), &ProjectileData::get_acceleration);

	// Physics
	ClassDB::bind_method(D_METHOD("set_collision_shape", "shape"), &ProjectileData::set_collision_shape);
	ClassDB::bind_method(D_METHOD("get_collision_shape"), &ProjectileData::get_collision_shape);
	ClassDB::bind_method(D_METHOD("set_collision_mask", "mask"), &ProjectileData::set_collision_mask);
	ClassDB::bind_method(D_METHOD("get_collision_mask"), &ProjectileData::get_collision_mask);
	ClassDB::bind_method(D_METHOD("set_collide_with_bodies", "enable"), &ProjectileData::set_collide_with_bodies);
	ClassDB::bind_method(D_METHOD("is_collide_with_bodies"), &ProjectileData::get_collide_with_bodies);
	ClassDB::bind_method(D_METHOD("set_collide_with_areas", "enable"), &ProjectileData::set_collide_with_areas);
	ClassDB::bind_method(D_METHOD("is_collide_with_areas"), &ProjectileData::get_collide_with_areas);

	// Behaviour
	ClassDB::bind_method(D_METHOD("set_hit_callback_name", "name"), &ProjectileData::set_hit_callback_name);
	ClassDB::bind_method(D_METHOD("get_hit_callback_name"), &ProjectileData::get_hit_callback_name);
	ClassDB::bind_method(D_METHOD("set_meta", "meta"), &ProjectileData::set_meta);
	ClassDB::bind_method(D_METHOD("get_meta"), &ProjectileData::get_meta);

	// Display
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "texture", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "set_texture", "get_texture");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "material", PROPERTY_HINT_RESOURCE_TYPE, "Material"), "set_material", "get_material");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "initial_angle"), "set_initial_angle", "get_initial_angle");

	// Motion
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Motion/initial_linear_speed"), "set_initial_linear_speed", "get_initial_linear_speed");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Motion/min_linear_speed"), "set_min_linear_speed", "get_min_linear_speed");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Motion/max_linear_speed"), "set_max_linear_speed", "get_max_linear_speed");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Motion/acceleration"), "set_acceleration", "get_acceleration");

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
void ProjectileData::set_texture(const Ref<Texture2D> &p_texture) {
	_texture = p_texture;
}

Ref<Texture2D> ProjectileData::get_texture() const  {
	return _texture;
}

void ProjectileData::set_material(const Ref<Material> &p_material) {
	_material = p_material;
}

Ref<Material> ProjectileData::get_material() const  {
	return _material;
}

void ProjectileData::set_initial_angle(const float p_angle) {
	_initial_angle = p_angle;
}

float ProjectileData::get_initial_angle() const {
	return _initial_angle;
}

// Motion
void ProjectileData::set_initial_linear_speed(const float p_speed) {
	_initialLinearSpeed = p_speed;
}

float ProjectileData::get_initial_linear_speed() const {
	return _initialLinearSpeed;
}

void ProjectileData::set_min_linear_speed(const float p_speed) {
	_minLinearSpeed = p_speed;
}

float ProjectileData::get_min_linear_speed() const {
	return _maxLinearSpeed;
}

void ProjectileData::set_max_linear_speed(const float p_speed) {
	_maxLinearSpeed = p_speed;
}

float ProjectileData::get_max_linear_speed() const {
	return _maxLinearSpeed;
}

void ProjectileData::set_acceleration(const float p_acceleration) {
	_acceleration = p_acceleration;
}

float ProjectileData::get_acceleration() const {
	return _acceleration;
}

// Physics
void ProjectileData::set_collision_shape(const Ref<Shape2D> &p_shape) {
	_collisionShape = p_shape;
}

Ref<Shape2D> ProjectileData::get_collision_shape() const {
	return _collisionShape;
}

void ProjectileData::set_collision_mask(const unsigned int p_mask) {
	_collisionMask = p_mask;
}

unsigned int ProjectileData::get_collision_mask() const {
	return _collisionMask;
}

void ProjectileData::set_collide_with_bodies(const bool p_value) {
	_collideWithBodies = p_value;
}

bool ProjectileData::get_collide_with_bodies() const {
	return _collideWithBodies;
}

void ProjectileData::set_collide_with_areas(const bool p_value) {
	_collideWithAreas = p_value;
}

bool ProjectileData::get_collide_with_areas() const {
	return _collideWithAreas;
}

void ProjectileData::set_hit_callback_name(const StringName p_name) {
	_hit_callback_name = p_name;
}

StringName ProjectileData::get_hit_callback_name() const {
	return _hit_callback_name;
}

void ProjectileData::set_meta(const Dictionary p_meta) {
	_meta = p_meta;
}

Dictionary ProjectileData::get_meta() const {
	return _meta;
}

ProjectileData::ProjectileData() {
	_initialLinearSpeed = 0;
	_minLinearSpeed = 0;
	_maxLinearSpeed = 1200;
	_acceleration = 200;

	_collisionMask = 1;
	_collideWithBodies = true;
	_collideWithAreas = false;
}

ProjectileData::~ProjectileData() {}
