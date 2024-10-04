/**
 * @file
 * @brief Mathematics utils for statistics
 * @authors alxvdev
 */

#pragma once

#include <cmath>
#include <cstddef>
#include <vector>

/**
 * @brief Statistics namespace
 */
namespace mathematics::statistics {

	/**
	 * @brief	   Gets the average.
	 *
	 * @param	   numbers	The numbers
	 * @param[in]  length	The length
	 *
	 * @return	   The average.
	 */
	auto get_average(const double numbers[], int length) -> double;

	/**
	 * @brief	   calculate factorial
	 *
	 * @param[in]  n	 number
	 *
	 * @return	   factorial
	 */
	auto factorial(size_t n) -> size_t;

	/**
	 * @brief	   get combinations
	 *
	 * @param[in]  n	 n value
	 * @param[in]  k	 k value
	 *
	 * @return	   { description_of_the_return_value }
	 */
	auto combinations(size_t n, size_t k) -> size_t;

	/**
	 * @brief	   variance
	 *
	 * @param[in]  data	 The data
	 *
	 * @return	   value
	 */
	auto variance(const std::vector<double> &data) -> double;

	/**
	 * @brief	   probability
	 *
	 * @param[in]  favorable_outcomes  The favorable outcomes
	 * @param[in]  total_outcomes	   The total outcomes
	 *
	 * @return	   result
	 */
	auto probability(size_t favorable_outcomes, size_t total_outcomes) -> double;

	/**
	 * @brief	   conditional probability
	 *
	 * @param[in]  a_and_b	A and b
	 * @param[in]  b		b value
	 *
	 * @return	   value
	 */
	auto conditional_probability(size_t a_and_b, size_t b) -> double;
}  // namespace mathematics::statistics
