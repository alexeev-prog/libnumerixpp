#include <iostream>
#include <string>

#include "libnumerixpp/computerscience/core.hpp"
#include "libnumerixpp/core/common.hpp"
#include "libnumerixpp/libnumerixpp.hpp"

auto main() -> int {
	credits();
	println("LIBNUMERIXPP");

	int const decimal_number = 777;
	std::string binary_number = computerscience::convertDecimalToBinary(decimal_number);
	int const decimal_number2 = computerscience::convertBinaryToDecimal(binary_number);
	std::string hexadecimal_number = computerscience::convertDecimalToHexadecimal(decimal_number);
	int const decimal_number3 = computerscience::convertHexadecimalToDecimal(hexadecimal_number);
	std::string const hexadecimal_number2 = computerscience::convertBinaryToHexadecimal(binary_number);
	std::string const binary_number2 = computerscience::convertHexadecimalToBinary(hexadecimal_number);
	long long const bytes = 1024 * 1024;

	std::cout << "Convert decimal " << decimal_number << " to binary: " << binary_number << '\n';
	std::cout << "Convert binary " << binary_number << " to decimal: " << decimal_number2
			  << '\n';
	std::cout << "Convert decimal " << decimal_number << " to hexadecimal: " << hexadecimal_number
			  << '\n';
	std::cout << "Convert hexadecimal " << hexadecimal_number << " to decimal: " << decimal_number3
			  << '\n';
	std::cout << "Convert binary " << binary_number << " to hexadecimal: " << hexadecimal_number2
			  << '\n';
	std::cout << "Convert hexadecimal " << hexadecimal_number << " to binary: " << binary_number2
			  << '\n';
	std::cout << "Convert " << bytes << ": " << computerscience::humanizeBytesSize(bytes)
			  << '\n';

	return 0;
}
