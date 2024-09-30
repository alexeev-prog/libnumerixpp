/**
 * @file
 * @brief Core utils for mathematics
 * @authors alxvdev
 */
#ifndef LIBNUMERIXPP_MATHEMATICS_CORE_HPP
#define LIBNUMERIXPP_MATHEMATICS_CORE_HPP

#pragma once

/**
 * @brief	   Basic mathematics utils
 * @include example-2.cpp
 */
namespace mathematics {
/**
 * @brief	   Algorithm for fast exponentiation "'Old' approximation"
 *
 * @details	   If accuracy is not important to you and the degrees are in
 *			   the range from -1 to 1, you can use this method (see also
 *			   'another' approximation: anotherApproximatePower()). This
 *			   method is based on the algorithm used in the 2005 game Quake
 *			   III Arena. He raised the number x to the power -0.5, i.e.
 *			   found the value: \f$\frac{1}{\sqrt{x}}\f$
 *
 * @param[in]  base		 The base
 * @param[in]  exponent	 The exponent
 *
 * @return	   raised value
 */
auto old_approximate_power(double base, double exponent) -> double;

/**
 * @brief	   Algorithm for fast exponentiation "'Another' approximation"
 *
 * @details	   Speed increase: ~9 times. Accuracy: <1.5%. Limitations:
 *			   accuracy drops rapidly as the absolute value of the degree
 *			   increases and remains acceptable in the range [-10, 10] (see
 *			   also 'old' approximation: oldApproximatePower()).
 *
 * @param[in]  base		 The base
 * @param[in]  exponent	 The exponent
 *
 * @return	   raised value
 */
auto another_approximate_power(double base, double exponent) -> double;

/**
 * @brief	   Algorithm: Binary exponentiation
 * @details	   Speed increase: ~7.5 times on average, the advantage remains
 *			   until numbers are raised to a power of 134217728, Speed
 *			   increase: ~7.5 times on average, the advantage remains until
 *			   the numbers are raised to the power of 134217728. Error:
 *			   none, but it is worth noting that the multiplication
 *			   operation is not associative for floating point numbers, i.e.
 *			   1.21 * 1.21 is not the same as 1.1 * 1.1 * 1.1 * 1.1,
 *			   however, when compared with standard functions, errors do not
 *			   arise, as mentioned earlier. Restrictions: the degree must be
 *			   an integer not less than 0
 *
 * @param[in]  base		 base
 * @param[in]  exponent	 exponent
 *
 * @return	   raised value
 */
auto binary_power(double b, unsigned long long e) -> double;

/**
 * @brief	   Algorithm: "Dividing fast power"
 *
 * @details	   Speed increase: ~3.5 times. Accuracy: ~13%. The code below
 *			   contains checks for special input data. Without them, the
 *			   code runs only 10% faster, but the error increases tenfold
 *			   (especially when using negative powers).
 *
 * @param[in]  base		 The base
 * @param[in]  exponent	 The exponent
 *
 * @return	   raised value
 */
auto fast_power_dividing(double base, double exponent) -> double;

/**
 * @brief	   Algorithm: "Fractional fast power"
 * @details	   Speed increase: ~4.4 times. Accuracy: ~0.7%
 *
 * @param[in]  base		 The base
 * @param[in]  exponent	 The exponent
 *
 * @return	   raised value
 */
auto fast_power_fractional(double base, double exponent) -> double;

/**
 * @brief	   Adds a percent to number.
 *
 * @param[in]  number	   The number
 * @param[in]  percentage  The percentage
 *
 * @return	   number
 */
auto add_percent_to_number(double number, double percentage) -> double;

/**
 * @brief	   Gets the number square (N^2).
 *
 * @param[in]  num	 The number
 *
 * @return	   The number square.
 */
auto square_it_up(double num) -> double;

/**
 * @brief	   Gets the square root.
 *
 * @param[in]  num	 The number
 *
 * @return	   The square root.
 */
auto get_square_root(double num) -> double;

/**
 * @brief	   Getting the modulus of a number without a comparison operation
 *
 * @param[in]  x	 number
 *
 * @return	   modulus of number
 */
auto intabs(int x) -> int;
}  // namespace mathematics

#endif	// LIBNUMERIXPP_MATHEMATICS_CORE_HPP
