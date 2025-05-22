#pragma once

#include <godot_cpp/classes/resource.hpp>

using namespace godot;

class HellStormTrajectory2D : public Resource {
	public:
		enum TrajectoryType2D {
			TRAJECTORY_LINEAR = 0,
			TRAJECTORY_SINUSOIDAL = 1,
			TRAJECTORY_CURVED = 2
		};

	protected:
		TrajectoryType2D _type;

	public:
		TrajectoryType2D get_type();
};

class LinearTrajectoryConfig2D : public HellStormTrajectory2D {
	GDCLASS(LinearTrajectoryConfig2D, Resource);

	private:
		float _initial_speed;
		float _min_speed;
		float _max_speed;
		float _acceleration;

	protected:
		static void _bind_methods();

	public:
		void set_initial_speed(const float p_speed);
		float get_initial_speed() const;

		void set_min_speed(const float p_speed);
		float get_min_speed() const;

		void set_max_speed(const float p_speed);
		float get_max_speed() const;

		void set_acceleration(const float p_acceleration);
		float get_acceleration() const;

	LinearTrajectoryConfig2D();
};

class SinusoidalTrajectoryConfig2D : public LinearTrajectoryConfig2D {
	GDCLASS(SinusoidalTrajectoryConfig2D, LinearTrajectoryConfig2D);

	protected:
		static void _bind_methods();

	private:
		double _mod;
		double _offset;

	public:
		void set_mod(double p_mod);
		double get_mod() const;

		void set_offset(double p_offset);
		double get_offset() const;

		SinusoidalTrajectoryConfig2D();
};

class CurvedTrajectoryConfig2D : public LinearTrajectoryConfig2D {
	GDCLASS(CurvedTrajectoryConfig2D, LinearTrajectoryConfig2D);

	protected:
		static void _bind_methods();

	private:
		float _angular_speed;

	public:
		void set_angular_speed(float p_speed);
		float get_angular_speed() const;

		CurvedTrajectoryConfig2D();
};
