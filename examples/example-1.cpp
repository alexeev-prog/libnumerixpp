#include <iostream>

#include "libnumerixpp/core/common.hpp"
#include "libnumerixpp/libnumerixpp.hpp"
#include "libnumerixpp/physics/kinematics.hpp"

auto main() -> int {
	credits();
	println("LIBNUMERIXPP");

	double speed = 10.0;
	double time = 5.0;

	double const path = physics::kinematics::calculate_path(speed, time);
	speed = physics::kinematics::calculate_speed(path, time);
	time = physics::kinematics::calculate_time(path, speed);

	std::cout << "Calculate: speed=" << speed << "m/s" << "; time=" << time << "s"
			  << "; path=" << path << "m" << '\n';

	double const final_velocity = physics::kinematics::calculate_final_velocity(10.0, 10.0, 10.0);
	std::cout << "final velocity (10.0, 10.0, 10.0) = " << final_velocity << '\n';

	double const final_position = physics::kinematics::calculate_final_position(10.0, 10.0, 10.0, 10.0);
	std::cout << "final position (10.0, 10.0, 10.0, 10.0) = " << final_velocity << '\n';

	return 0;
}
