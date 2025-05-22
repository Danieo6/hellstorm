#include "./hellstorm_projectile_trajectory_config_2d.h"

#include <godot_cpp/core/class_db.hpp>

HellStormTrajectory2D::TrajectoryType2D HellStormTrajectory2D::get_type() {
	return _type;
}

void LinearTrajectoryConfig2D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_initial_speed", "speed"), &LinearTrajectoryConfig2D::set_initial_speed);
	ClassDB::bind_method(D_METHOD("get_initial_speed"), &LinearTrajectoryConfig2D::get_initial_speed);
	ClassDB::bind_method(D_METHOD("set_min_speed", "speed"), &LinearTrajectoryConfig2D::set_min_speed);
	ClassDB::bind_method(D_METHOD("get_min_speed"), &LinearTrajectoryConfig2D::get_min_speed);
	ClassDB::bind_method(D_METHOD("set_max_speed", "speed"), &LinearTrajectoryConfig2D::set_max_speed);
	ClassDB::bind_method(D_METHOD("get_max_speed"), &LinearTrajectoryConfig2D::get_max_speed);
	ClassDB::bind_method(D_METHOD("set_acceleration", "acceleration"), &LinearTrajectoryConfig2D::set_acceleration);
	ClassDB::bind_method(D_METHOD("get_acceleration"), &LinearTrajectoryConfig2D::get_acceleration);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "initial_speed"), "set_initial_speed", "get_initial_speed");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "min_speed"), "set_min_speed", "get_min_speed");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_speed"), "set_max_speed", "get_max_speed");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "acceleration"), "set_acceleration", "get_acceleration");
}

void LinearTrajectoryConfig2D::set_initial_speed(const float p_speed) {
	_initial_speed = p_speed;
}

float LinearTrajectoryConfig2D::get_initial_speed() const {
	return _initial_speed;
}

void LinearTrajectoryConfig2D::set_min_speed(const float p_speed) {
	_min_speed = p_speed;
}

float LinearTrajectoryConfig2D::get_min_speed() const {
	return _max_speed;
}

void LinearTrajectoryConfig2D::set_max_speed(const float p_speed) {
	_max_speed = p_speed;
}

float LinearTrajectoryConfig2D::get_max_speed() const {
	return _max_speed;
}

void LinearTrajectoryConfig2D::set_acceleration(const float p_acceleration) {
	_acceleration = p_acceleration;
}

float LinearTrajectoryConfig2D::get_acceleration() const {
	return _acceleration;
}

LinearTrajectoryConfig2D::LinearTrajectoryConfig2D() {
	_type = TRAJECTORY_LINEAR;
	_initial_speed = 0;
	_min_speed = 0;
	_max_speed = 1200;
	_acceleration = 200;
}

void SinusoidalTrajectoryConfig2D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_mod", "mod"), &SinusoidalTrajectoryConfig2D::set_mod);
	ClassDB::bind_method(D_METHOD("get_mod"), &SinusoidalTrajectoryConfig2D::get_mod);
	ClassDB::bind_method(D_METHOD("set_offset", "offset"), &SinusoidalTrajectoryConfig2D::set_offset);
	ClassDB::bind_method(D_METHOD("get_offset"), &SinusoidalTrajectoryConfig2D::get_offset);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "mod"), "set_mod", "get_mod");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "offset"), "set_offset", "get_offset");
}

void SinusoidalTrajectoryConfig2D::set_mod(double p_mod) {
	_mod = p_mod;
}

double SinusoidalTrajectoryConfig2D::get_mod() const {
	return _mod;
}

void SinusoidalTrajectoryConfig2D::set_offset(double p_offset) {
	_offset = p_offset;
}

double SinusoidalTrajectoryConfig2D::get_offset() const {
	return _offset;
}

SinusoidalTrajectoryConfig2D::SinusoidalTrajectoryConfig2D() {
	_type = TRAJECTORY_SINUSOIDAL;
	_mod = 2.5;
	_offset = 0.0;
}

void CurvedTrajectoryConfig2D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_angular_speed", "speed"), &CurvedTrajectoryConfig2D::set_angular_speed);
	ClassDB::bind_method(D_METHOD("get_angular_speed"), &CurvedTrajectoryConfig2D::get_angular_speed);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angular_speed"), "set_angular_speed", "get_angular_speed");
}

void CurvedTrajectoryConfig2D::set_angular_speed(float p_speed) {
	_angular_speed = p_speed;
}

float CurvedTrajectoryConfig2D::get_angular_speed() const {
	return _angular_speed;
}

CurvedTrajectoryConfig2D::CurvedTrajectoryConfig2D() {
	_type = TRAJECTORY_CURVED;
	_angular_speed = 5.0;
}
