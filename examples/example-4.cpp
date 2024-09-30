#include <cmath>
#include <iostream>
#include <string>

#include "libnumerixpp/core/common.hpp"
#include "libnumerixpp/libnumerixpp.hpp"
#include "libnumerixpp/mathematics/equations.hpp"

void test_eq_sa(double (*f_eq)(double), double x0, const std::string& eq) {
	int const iterations = 100;

	double z = NAN;

	std::cout << "Equation solution " << eq << ":\t";

	z = mathematics::equations::successiveApproximationsFindingRoot(f_eq, x0, iterations);

	std::cout << z << '\n';

	std::cout << "Check finding solution:\t";

	std::cout << z << " = " << f_eq(z) << '\n';

	for (int i = 0; i <= 50; i++) {
		std::cout << "-";
	}

	std::cout << '\n';
}

auto main() -> int {
	credits();
	println("LIBNUMERIXPP");

	test_eq_sa(mathematics::equations::f_eq, 0, "x=0.5cos(x)");
	test_eq_sa(mathematics::equations::g_eq, 0, "x=exp(-x)");
	test_eq_sa(mathematics::equations::h_eq, 1, "x=(x*x+6)/5");

	return 0;
}
