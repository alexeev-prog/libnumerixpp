/**
 * @file
 * @brief Math utils for quadratic
 * @authors alxvdev
 */
#include <vector>

#include "libnumerixpp/mathematics/core.hpp"

namespace mathematics::quadratic {

auto calculate_discriminant(double a, double b, double c) -> double {
	double const d = mathematics::square_it_up(b) - 4 * a * c;

	return d;
}

auto calculate_roots_by_discriminant(double discriminant, double a,
									 double b) -> std::vector<double> {
	std::vector<double> roots;

	if (discriminant > 0) {
		double const x1 = (-b + get_square_root(discriminant)) / (2 * a);
		double const x2 = (-b - get_square_root(discriminant)) / (2 * a);

		roots.push_back(x1);
		roots.push_back(x2);
	} else if (discriminant == 0) {
		double const x1 = -b + get_square_root(discriminant) / (2 * a);
		roots.push_back(x1);
	}

	return roots;
}

auto get_roots_by_vieta_theorem(double a, double b, double c) -> std::vector<double> {
	std::vector<double> roots;

	if (a == 0) {
		return roots;
	}

	double const roots_sum = -(b / a);
	double const roots_mul = c / a;

	roots.push_back(roots_sum);
	roots.push_back(roots_mul);

	return roots;
}
}  // namespace mathematics::quadratic
