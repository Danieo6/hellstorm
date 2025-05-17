#include "hellstorm.h"

#include <godot_cpp/core/class_db.hpp>

void HellStorm::_bind_methods() {
	ClassDB::bind_method(D_METHOD("test"), &HellStorm::test);
}

void HellStorm::test() {
	UtilityFunctions::print("Welcome to HellStorm!");
}

HellStorm::HellStorm() {

}
