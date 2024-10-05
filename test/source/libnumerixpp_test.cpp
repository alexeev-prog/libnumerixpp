#include <catch2/catch_test_macros.hpp>
#include <vector>

#include "libnumerixpp/computerscience/core.hpp"
#include "libnumerixpp/mathematics/core.hpp"
#include "libnumerixpp/mathematics/equations.hpp"
#include "libnumerixpp/mathematics/quadratic_equations.hpp"
#include "libnumerixpp/mathematics/statistics.hpp"
#include "libnumerixpp/physics/kinematics.hpp"

TEST_CASE("Check physics module", "[physics]") {
	auto speed = 10.0;
	auto time = 5.0;

	auto path = physics::kinematics::calculate_path(speed, time);

	REQUIRE(physics::kinematics::calculate_acceleration_of_rectilinear_motion(10.0, 15.0, 3) ==
			1.66666666666666674);
	REQUIRE(path == 50.0);
	REQUIRE(physics::kinematics::calculate_speed(path, time) == 10.0);
	REQUIRE(physics::kinematics::calculate_path(speed, time) == path);
	REQUIRE(physics::kinematics::calculate_time(path, speed) == time);
	REQUIRE(physics::kinematics::calculate_final_velocity(10.0, 10.0, 10.0) == 110.0);
	REQUIRE(physics::kinematics::calculate_final_position(10.0, 10.0, 10.0, 10.0) == 610.0);
	REQUIRE(physics::kinematics::calculate_speed_of_rectilinear_motion(10.0, 5.0, 5.0) == 35.0);
}

TEST_CASE("Check mathematics-quadratic", "[mathematics-quadratic]") {
	auto num = 100.0;
	auto a = -2;
	auto b = 5;
	auto c = 5;
	auto d = mathematics::quadratic::calculate_discriminant(a, b, c);
	auto nump = mathematics::add_percent_to_number(100.0, 10.0);

	REQUIRE(mathematics::square_it_up(num) == 10000);
	REQUIRE(mathematics::get_square_root(num) == 10);
	REQUIRE(d == 65.0);
	REQUIRE(mathematics::quadratic::calculate_roots_by_discriminant(d, a, b) ==
			(std::vector<double>){ -0.76556443707463728, 3.26556443707463728 });
	REQUIRE(nump == 110.0);
	REQUIRE(mathematics::intabs(-10) == 10);
}

TEST_CASE("Check computerscience", "[computerscience]") {
	int const decimal_number = 777;
	auto binary_number = computerscience::convert_decimal_to_binary(decimal_number);
	int const decimal_number2 = computerscience::convert_binary_to_decimal(binary_number);
	auto hexadecimal_number = computerscience::convert_decimal_to_hexadecimal(decimal_number);
	int const decimal_number3 = computerscience::convert_hexadecimal_to_decimal(hexadecimal_number);
	auto hexadecimal_number2 = computerscience::convert_binary_to_hexadecimal(binary_number);
	long long const bytes = 1024 * 1024;

	REQUIRE(binary_number == "1100001001");
	REQUIRE(decimal_number2 == 777);
	REQUIRE(hexadecimal_number == "309");
	REQUIRE(decimal_number3 == 777);
	REQUIRE(hexadecimal_number2 == "309");
	REQUIRE(computerscience::humanize_bytes_size(bytes) == "1.00MB");
}

TEST_CASE("Check mathematics-equations", "[mathematics-equations]") {
	auto z_f = mathematics::equations::successive_approximations_finding_root(
		mathematics::equations::f_eq, 0.0, 100);
	auto z_g = mathematics::equations::successive_approximations_finding_root(
		mathematics::equations::g_eq, 0.0, 100);
	auto z_h = mathematics::equations::successive_approximations_finding_root(
		mathematics::equations::h_eq, 1.0, 100);

	REQUIRE(z_f == mathematics::equations::f_eq(z_f));
	REQUIRE(z_g == mathematics::equations::g_eq(z_g));
	REQUIRE(z_h == mathematics::equations::h_eq(z_h));
}

TEST_CASE("Check mathematics-statistics", "[mathematics-statistics]") {
	const double numbers[3] = { 1.0, 1.0, 1.0 };
	int const list_length = sizeof(numbers) / sizeof(numbers[0]);
	double const average = mathematics::statistics::get_average(numbers, list_length);

	REQUIRE(average == 1.0);
}
