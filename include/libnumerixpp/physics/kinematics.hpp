/**
 * @file
 * @brief Physics utils for kinematics
 * @authors alxvdev
 */
#ifndef LIBNUMERIXPP_PHYSICS_KINEMATICS_HPP
#define LIBNUMERIXPP_PHYSICS_KINEMATICS_HPP

#pragma once

/**
 * @brief	   Namespace of kinematics (physics)
 *
 * @todo	   Add more kinematics equations
 */
namespace physics::kinematics {

	/**
	 * @brief	   Calculates the path.
	 *
	 * This function is based on basic formule: S = v * t
	 * where:
	 *	+ S - path (m)
	 *	+ v - speed (m/s)
	 *	+ t - time (s)
	 *
	 * @param[in]  speed  The speed
	 * @param[in]  time	  The time
	 *
	 * @return	   The path.
	 */
	auto calculate_path(double speed, double time) -> double;

	/**
	 * @brief	   Calculates the speed.
	 *
	 * This function is based on basic formule: S = v * t
	 * where:
	 *	+ S - path (m)
	 *	+ v - speed (m/s)
	 *	+ t - time (s)
	 *
	 * @param[in]  path	 The path
	 * @param[in]  time	 The time
	 *
	 * @return	   The speed.
	 */
	auto calculate_speed(double path, double time) -> double;

	/**
	 * @brief	   Calculates the time.
	 *
	 * This function is based on basic formule: S = v * t
	 * where:
	 *	+ S - path (m)
	 *	+ v - speed (m/s)
	 *	+ t - time (s)
	 *
	 * @param[in]  path	  The path
	 * @param[in]  speed  The speed
	 *
	 * @return	   The time.
	 */
	auto calculate_time(double path, double speed) -> double;

	/**
	 * @brief	   Calculates the final velocity.
	 *
	 * This function is based on the basic kinematics equation: v = u + at
	 * where:
	 *	+ v - final velocity (m/s)
	 *	+ u - start speed (m/s)
	 *	+ a - acceleration (m/s^2)
	 *	+ t - time (s)
	 *
	 * @param[in]  initial_velocity	 The initial velocity
	 * @param[in]  acceleration		 The acceleration
	 * @param[in]  time				 The time
	 *
	 * @return	   The final velocity.
	 */
	auto calculate_final_velocity(double initial_velocity, double acceleration,
								  double time) -> double;

	/**
	 * @brief	   Calculates the final position.
	 *
	 * This function is based on the kinematics equation: s = u*t + 0.5 * a * t^2
	 * where:
	 *	+ s - final position (m)
	 *	+ u - start speed (m/s)
	 *	+ a - acceleration (m/s^2)
	 *	+ t - time (s)
	 *
	 * @param[in]  initial_position	 The initial position
	 * @param[in]  initial_velocity	 The initial velocity
	 * @param[in]  acceleration		 The acceleration
	 * @param[in]  time				 The time
	 *
	 * @return	   The final position.
	 */
	auto calculate_final_position(double initial_position, double initial_velocity,
								  double acceleration, double time) -> double;
}  // namespace physics::kinematics

#endif	// LIBNUMERIXPP_PHYSICS_KINEMATICS_HPP
