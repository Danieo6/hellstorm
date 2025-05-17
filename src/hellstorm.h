#pragma once

#include <godot_cpp/classes/object.hpp>

using namespace godot;

class HellStorm : public Object {
	GDCLASS(HellStorm, Object);

	protected:
		static void _bind_methods();

	public:
		void test();

		HellStorm();
};
