/**
 * @file
 * @brief Core utils for computer science (informatics)
 * @authors alxvdev
 */
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

namespace computerscience {
auto convert_decimal_to_binary(int decimal) -> std::string {
	std::string binary;

	if (decimal == 0) {
		return "0";
	}

	while (decimal > 0) {
		binary = std::to_string(decimal % 2) + binary;
		decimal /= 2;
	}

	return binary;
}

auto convert_binary_to_decimal(std::string &binary) -> int {
	int decimal = 0;

	for (char const bit : binary) {
		decimal = decimal * 2 + (bit - '0');
	}

	return decimal;
}

auto convert_decimal_to_hexadecimal(int decimal) -> std::string {
	std::string hexadecimal;
	const char hex_digits[] = "0123456789ABCDEF";

	while (decimal > 0) {
		hexadecimal = hex_digits[decimal % 16] + hexadecimal;
		decimal /= 16;
	}

	return hexadecimal.empty() ? "0" : hexadecimal;
}

auto convert_hexadecimal_to_decimal(std::string &hexadecimal) -> int {
	int decimal = 0;

	for (char const digit : hexadecimal) {
		decimal = decimal * 16 + ((isdigit(digit) != 0) ? digit - '0' : toupper(digit) - 'A' + 10);
	}

	return decimal;
}

auto convert_binary_to_hexadecimal(std::string &binary) -> std::string {
	std::string hexadecimal;
	const char hex_digits[] = "0123456789ABCDEF";

	if (binary.empty()) {
		return "0";
	}

	int binary_length = static_cast<int>(binary.length());

	while (binary_length % 4 != 0) {
		binary = "0" + binary;
		binary_length++;
	}

	for (int i = 0; i < binary_length; i += 4) {
		int decimal = 0;

		for (int j = 0; j < 4; j++) {
			decimal = decimal * 2 + (binary[i + j] - '0');
		}

		hexadecimal += hex_digits[decimal];
	}

	return hexadecimal;
}

auto convert_hexadecimal_to_binary(std::string &hexadecimal) -> std::string {
	std::string binary;
	std::string binary_digit;

	if (hexadecimal.empty()) {
		return "0";
	}

	for (char const digit : hexadecimal) {
		int value = ((isdigit(digit)) != 0) ? digit - '0' : toupper(digit) - 'A' + 10;
		binary_digit = "";

		for (int i = 0; i < 4; i++) {
			binary_digit = std::to_string(value % 2) + binary_digit;
			value /= 2;
		}

		binary += binary_digit;
	}

	while (!binary.empty() && binary[0] == '0') {
		binary.erase(0, 1);
	}

	return binary.empty() ? "0" : binary;
}

auto humanize_bytes_size(long long bytes, const std::string &suffix = "B") -> std::string {
	double const factor = 1024.0;
	std::string const units[] = { "", "K", "M", "G", "T", "P" };

	int i = 0;

	while (bytes >= factor) {
		bytes /= factor;
		i++;
	}

	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << static_cast<double>(bytes) << units[i] << suffix;
	return ss.str();
}
}  // namespace computerscience
