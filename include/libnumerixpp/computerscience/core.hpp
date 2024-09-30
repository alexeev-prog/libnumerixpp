/**
 * @file
 * @brief Core utils for computer science
 * @authors alxvdev
 */
#ifndef LIBNUMERIXPP_COMPUTERSCIENCE_CORE_HPP
#define LIBNUMERIXPP_COMPUTERSCIENCE_CORE_HPP

#pragma once

#include <string>

/**
 * @brief	   Basic Computer science utils
 * @include example-3.cpp
 */
namespace computerscience {

/**
 * @brief	   convert decimal to binary
 *
 * @param[in]  decimal	The decimal
 *
 * @return	   binary number string
 */
auto convert_decimal_to_binary(int decimal) -> std::string;

/**
 * @brief	   convert binary to decimal
 *
 * @param	   binary  The binary
 *
 * @return	   decimal integer
 */
auto convert_binary_to_decimal(std::string &binary) -> int;

/**
 * @brief	   convert decimal to hexadecimal
 *
 * @param[in]  decimal	The decimal
 *
 * @return	   hexadecimal number string
 */
auto convert_decimal_to_hexadecimal(int decimal) -> std::string;

/**
 * @brief	   convert hexadecimal to decimal
 *
 * @param	   hexadecimal	The hexadecimal
 *
 * @return	   decimal integer
 */
auto convert_hexadecimal_to_decimal(std::string &hexadecimal) -> int;

/**
 * @brief	   convert binary to hexadecimal
 *
 * @param	   binary  The binary
 *
 * @return	   hexadecimal number string
 */
auto convert_binary_to_hexadecimal(std::string &binary) -> std::string;

/**
 * @brief	   convert hexadecimal to binary
 *
 * @param[in]  hexadecimal	The hexadecimal
 *
 * @return	   binary number string
 */
auto convert_hexadecimal_to_binary(std::string hexadecimal) -> std::string;

/**
 * @brief	   Scale bytes to its proper format
 *
 * @param[in]  bytes   The bytes
 * @param[in]  suffix  The suffix
 *
 * @return	   humanized size
 */
auto humanize_bytes_size(long long bytes, const std::string &suffix = "B") -> std::string;
}  // namespace computerscience

#endif	// LIBNUMERIXPP_COMPUTERSCIENCE_CORE_HPP
