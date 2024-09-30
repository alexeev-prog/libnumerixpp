/**
 * @file
 * @brief Physics utils for kinematics
 * @authors alxvdev
 */

namespace physics::kinematics {

auto calculate_path(double speed, double time) -> double { return speed * time; }

auto calculate_speed(double path, double time) -> double { return path / time; }

auto calculate_time(double path, double speed) -> double { return path / speed; }

auto calculate_final_velocity(double initial_velocity, double acceleration, double time) -> double {
	return initial_velocity + acceleration * time;
}

auto calculate_final_position(double initial_position, double initial_velocity, double acceleration,
							  double time) -> double {
	return initial_position + initial_velocity * time + 0.5 * acceleration * time * time;
}
}  // namespace physics::kinematics
