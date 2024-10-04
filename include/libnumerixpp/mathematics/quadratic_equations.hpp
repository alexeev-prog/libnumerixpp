/**
 * @file
 * @brief Quadratic utils for mathematics
 * @authors alxvdev
 */
#ifndef LIBNUMERIXPP_MATHEMATICS_QUADRATIC_EQUATIONS_HPP
#define LIBNUMERIXPP_MATHEMATICS_QUADRATIC_EQUATIONS_HPP

#pragma once

#include <vector>

/**
 * mathematics utils for quadratic equations and other
 *
 * @include example-2.cpp
 */
namespace mathematics::quadratic {
	/**
	 * @brief	   Calculates the discriminant.
	 *
	 * @details	   Based on discriminant formula: \f$b^{2} - 4ac\f$
	 *
	 * @param[in]  a	 a
	 * @param[in]  b	 b
	 * @param[in]  c	 c
	 *
	 * @return	   The discriminant.
	 */
	auto calculate_discriminant(double a, double b, double c) -> double;

	/**
	 * @brief	   Calculates the roots by discriminant.
	 *
	 * @details	   Calculate the roots by discriminant \f$\frac{-b +-
	 *			   \sqrt{D}}{2a}\f$. D > 0 = 2 roots, D == 0 = 1 root, D
	 *< 0 = 0 roots.
	 *
	 * @param[in]  discriminant	 The discriminant
	 * @param[in]  a			 a
	 * @param[in]  b			 b
	 *
	 * @return	   The roots by discriminant.
	 */
	auto calculate_roots_by_discriminant(double discriminant, double a,
										 double b) -> std::vector<double>;

	/**
	 * @brief	   Gets the roots by vieta theorem.
	 *
	 * @param[in]  a	 a
	 * @param[in]  b	 b
	 * @param[in]  c	 c
	 *
	 * @return	   The roots by vieta theorem.
	 */
	auto get_roots_by_vieta_theorem(double a, double b, double c) -> std::vector<double>;
}  // namespace mathematics::quadratic

#endif	// LIBNUMERIXPP_MATHEMATICS_QUADRATIC_EQUATIONS_HPP
