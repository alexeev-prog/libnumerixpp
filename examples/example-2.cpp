#include <iostream>
#include <vector>

#include "libnumerixpp/core/common.hpp"
#include "libnumerixpp/libnumerixpp.hpp"
#include "libnumerixpp/mathematics/core.hpp"
#include "libnumerixpp/mathematics/quadratic_equations.hpp"

auto main() -> int {
	credits();
	println("LIBNUMERIXPP");

	// SQUARE AND SQR //

	double const num = 100.0;
	double const num_sq = mathematics::square_it_up(num);
	double const num_sqr = mathematics::get_square_root(num);
	std::cout << "Square " << num << ": " << num_sq << '\n';
	std::cout << "Square root " << num << ": " << num_sqr << '\n';

	std::cout << '\n';

	// CALCULATE QUADRATIC EQUATION BY DISCRIMINANT //

	double const a = -2;
	double const b = 5;
	double const c = 5;

	double const d = mathematics::quadratic::calculateDiscriminant(a, b, c);
	std::vector<double> const roots = mathematics::quadratic::calculateRootsByDiscriminant(d, a, b);

	std::cout << "Quadratic Equation: a=" << a << "; b=" << b << "; c=" << c << '\n';
	std::cout << "D=" << d << '\n';
	std::cout << "Roots:" << '\n';

	for (double const root : roots) {
		std::cout << root << '\n';
	}

	std::cout << '\n';

	// PERCENTAGE //

	double const nump = mathematics::add_percent_to_number(100.0, 10.0);
	std::cout << "100+10%: " << nump << '\n';

	std::cout << '\n';

	// POWER / Algorithms for fast exponentiation //

	double const best_pow_val = 100;
	double const pow_results[5] = { mathematics::oldApproximatePower(10.0, 2.0),
									mathematics::anotherApproximatePower(10.0, 2.0),
									mathematics::binaryPower(10.0, 2),
									mathematics::fastPowerDividing(10.0, 2.0),
									mathematics::fastPowerFractional(10.0, 2.0) };

	std::cout << "0 oldApproximatePower	   : base 10 exponent 2: " << pow_results[0] << '\n';
	std::cout << "1 anotherApproximatePower: base 10 exponent 2: " << pow_results[1] << '\n';
	std::cout << "2 binaryPower			   : base 10 exponent 2: " << pow_results[2]
			  << '\n';
	std::cout << "3 fastPowerDividing	   : base 10 exponent 2: " << pow_results[3] << '\n';
	std::cout << "4 fastPowerFractional	   : base 10 exponent 2: " << pow_results[4] << '\n';

	for (int i = 0; i < sizeof(pow_results) / sizeof(pow_results[0]); i++) {
		double const error = best_pow_val - pow_results[i];

		std::cout << "POW Algorithm #" << i << ": error=" << error << '\n';
	}

	std::cout << '\n';

	// Other //

	std::cout << "-10 number module: " << mathematics::intabs(-10) << '\n';

	return 0;
}
