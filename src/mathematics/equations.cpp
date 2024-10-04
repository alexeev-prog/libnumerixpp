/**
 * @file
 * @brief Mathematics utils for equations
 * @authors alxvdev
 */
#include <cmath>

namespace mathematics::equations {
	auto successive_approximations_finding_root(double (*f_eq)(double), double x0,
												int n) -> double {
		double x = x0;

		for (int i = 1; i <= n; i++) {
			x = f_eq(x);
		}

		return x;
	}

	auto half_division_finding_root(double (*f_hd_eq)(double), double a, double b,
									double dx) -> double {
		double x = (a + b) / 2;

		while ((b - a) / 2 > dx) {
			if (f_hd_eq(a) == 0) {
				return a;
			}

			if (f_hd_eq(b) == 0) {
				return b;
			}

			if (f_hd_eq(x) == 0) {
				return x;
			}

			if (f_hd_eq(a) * f_hd_eq(x) > 0) {
				a = x;
			} else {
				b = x;
			}

			x = (a + b) / 2;
		}

		return x;
	}

	auto f_hd_eq(double x) -> double { return 0.5 * cos(x) - x; }

	auto g_hd_eq(double x) -> double { return exp(-x) - x; }

	auto h_hg_eq(double x) -> double { return x * x - 5 * x + 6; }

	auto f_eq(double x) -> double { return 0.5 * cos(x); }

	auto g_eq(double x) -> double { return exp(-x); }

	auto h_eq(double x) -> double { return (x * x + 6) / 5; }
}  // namespace mathematics::equations
