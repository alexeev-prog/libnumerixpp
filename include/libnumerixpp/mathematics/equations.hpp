/**
 * @file
 * @brief Mathematics utils for equations
 * @authors alxvdev
 */
#ifndef LIBNUMERIXPP_MATHEMATICS_EQUATIONS_HPP
#define LIBNUMERIXPP_MATHEMATICS_EQUATIONS_HPP

#pragma once

/**
 * @brief namespace for equation solving namespace
 * @include example-4.cpp
 */
namespace mathematics::equations {

	/**
	 * @brief	   Function for solving equations by the method of successive
	 *			   approximations.
	 *
	 * @details	   When solving an equation (\f$x = \Phi(x)\f$), under some
	 *			   additional conditions, the method of successive
	 *			   approximations can be used. Its essence boils down to
	 *the fact that the initial position x0 is specified for the root of the
	 *equation, after which, using an iterative procedure, each subsequent
	 *approximation is calculated based on the previous one in accordance with the
	 *formula @f$x_{n + 1} = \Phi(x_{n})\f$. Example equations: @f$x = 0,5 *
	 *\cos(x)\f$;
	 *			   @f$x = \exp(-x)\f$; @f$x = (x^{2} + 6) / 5\f$.
	 *
	 * @param[in]  f	 The f
	 * @param[in]  x0	 The x 0
	 * @param[in]  n	 n value
	 *
	 * @return	   equation root
	 */
	auto successive_approximations_finding_root(double (*f_eq)(double), double x0, int n) -> double;

	/**
	 * @brief	   Function for solving equations by the method of half
	 *division.
	 *
	 * @details	   The half division method for solving an algebraic equation of
	 *the form f(x) = 0 implies that the sought root is localized in the interval a
	 *<= x <= b, and at the boundaries of the root search interval the function f(x)
	 *must take values of different signs (which can be written as the condition
	 *f(a)f(b) < 0).
	 *
	 * @param[in]  f_hd_eq	The f_eq function for half division
	 * @param[in]  a		a value
	 * @param[in]  b		b value
	 * @param[in]  dx		dx value
	 *
	 * @return	   equation root
	 */
	auto half_division_finding_root(double (*f_hd_eq)(double), double a, double b,
									double dx) -> double;

	/**
	 * @brief	   Function f for determining the right side of solved equations
	 *
	 * @param[in]  x	 x value
	 *
	 * @return	   value
	 */
	auto f_eq(double x) -> double;

	/**
	 * @brief	   Function g for determining the right side of solved equations
	 *
	 * @param[in]  x	 x value
	 *
	 * @return	   value
	 */
	auto g_eq(double x) -> double;

	/**
	 * @brief	   Function h for determining the right side of solved equations
	 *
	 * @param[in]  x	 x value
	 *
	 * @return	   value
	 */
	auto h_eq(double x) -> double;

	/**
	 * @brief	   Function f for determining the right side of solved equations
	 * (half division)
	 *
	 * @param[in]  x	 x value
	 *
	 * @return	   value
	 */
	auto f_hd_eq(double x) -> double;

	/**
	 * @brief	   Function g for determining the right side of solved equations
	 * (half division)
	 *
	 * @param[in]  x	 x value
	 *
	 * @return	   value
	 */
	auto g_hd_eq(double x) -> double;

	/**
	 * @brief	   Function h for determining the right side of solved equations
	 * (half division)
	 *
	 * @param[in]  x	 x value
	 *
	 * @return	   value
	 */
	auto h_hg_eq(double x) -> double;

}  // namespace mathematics::equations

#endif	// LIBNUMERIXPP_MATHEMATICS_EQUATIONS_HPP
