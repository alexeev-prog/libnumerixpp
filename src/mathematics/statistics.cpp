/**
 * @file
 * @brief Mathematics utils for statistics
 * @authors alxvdev
 */
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <vector>

namespace mathematics::statistics {
	auto get_average(const double numbers[], int length) -> double {
		double sum = 0;

		for (int i = 0; i < length; i++) {
			sum += numbers[i];
		}

		return sum / length;
	}

	auto factorial(size_t n) -> size_t {
		if (n == 0) {
			return 1;
		}
		return n * factorial(n - 1);
	}

	auto combinations(size_t n, size_t k) -> size_t {
		return factorial(n) / (factorial(k) * factorial(n - k));
	}

	auto median(std::vector<double> data) -> double {
		std::sort(data.begin(), data.end());
		const size_t size = data.size();
		if (size % 2 == 0) {
			return (data[size / 2 - 1] + data[size / 2]) / 2.0;
		}
		return data[size / 2];
	}

	auto probability(size_t favorable_outcomes, size_t total_outcomes) -> double {
		return static_cast<double>(favorable_outcomes) / total_outcomes;
	}

	auto conditional_probability(size_t a_and_b, size_t b) -> double {
		return static_cast<double>(a_and_b) / b;
	}
}  // namespace mathematics::statistics
