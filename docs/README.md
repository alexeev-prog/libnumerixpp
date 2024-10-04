@mainpage
# libnumerixpp

<p align="center">A Powerful C++ Library for High-Performance Numerical Computing</p>
<br>
<p align="center">
	<img src="https://img.shields.io/github/languages/top/alexeev-prog/libnumerixpp?style=for-the-badge">
	<img src="https://img.shields.io/github/languages/count/alexeev-prog/libnumerixpp?style=for-the-badge">
	<img src="https://img.shields.io/github/license/alexeev-prog/libnumerixpp?style=for-the-badge">
	<img src="https://img.shields.io/github/stars/alexeev-prog/libnumerixpp?style=for-the-badge">
	<img src="https://img.shields.io/github/issues/alexeev-prog/libnumerixpp?style=for-the-badge">
	<img src="https://img.shields.io/github/last-commit/alexeev-prog/libnumerixpp?style=for-the-badge">
</p>

> [!CAUTION]
> At the moment, libnumerixpp is under active development (alpha), many things may not work, and this version is not recommended for use (all at your own risk).<

> Powerful, Modular, and Extensible C++ Library for Numerical Computations in Mathematics, Physics, and Computer Science

libnumerixpp is a **powerful** 💪, **modular** 🧱, and **well-documented** 📚 C++ library that provides a comprehensive set of tools for numerical computations in *mathematics, physics, and computer science*. This library aims to simplify complex calculations and enable efficient problem-solving across a wide range of domains.

Unlike other numerical libraries that often focus on a specific domain, libnumerixpp offers a unique, multi-disciplinary approach 🔍, seamlessly integrating mathematics, physics, and computer science functionalities into a single, cohesive solution. This makes it an invaluable resource for researchers, scientists, engineers, and developers who need to perform advanced numerical computations as part of their work.

libnumerixpp follows the principles of **modularity** 🧱, **extensibility** 🔍, and **code quality** ✨. The library is designed to be easily integrated into a wide range of projects, with a focus on maintainability, testability, and performance.

Unlike many numerical libraries that are limited to a single domain, libnumerixpp stands out with its multi-disciplinary approach 🔍, seamlessly combining mathematics, physics, and computer science functionalities into a single, cohesive solution. This makes it an invaluable tool for researchers, scientists, engineers, and developers who need to perform advanced numerical computations as part of their work.

The library's robust infrastructure 🏗️, including comprehensive documentation, extensive unit tests, and a flexible build system, ensures that users can trust the reliability and quality of the provided functionalities. Additionally, the intuitive and user-friendly API 🤗 simplifies complex calculations, allowing users to focus on solving their problems rather than wrestling with the underlying implementation details.

---

You can join to our [small russian telegram blog](https://t.me/hex_warehouse).

 > You can view docs for libnumerixpp [here](https://alexeev-prog.github.io/libnumerixpp).

 > Current version: 0.1.2

## Key Features 🔑
The libnumerixpp library boasts an impressive array of features that set it apart from its competitors:

Mathematics:
- 🧮 Robust equation solving (including linear, quadratic, and higher-order equations)
- 📊 Comprehensive statistical and probability functions
- 🔬 Powerful trigonometric, exponential, and logarithmic functions
- Unparalleled accuracy and performance 🏆 compared to standard math libraries

Physics:
- 🔍 Detailed kinematics calculations (displacement, velocity, acceleration, and more)
- Intuitive and user-friendly API 🤗 that simplifies complex physical computations
- Seamless integration with the mathematics module 🔗 for interdisciplinary projects

Computer Science:
- 🔢 Efficient number system conversion (decimal, binary, hexadecimal, and more)
- Versatile and extensible design 🧠 that allows for easy integration with other libraries and frameworks
- Extensive documentation and examples 📖 to help users get started quickly

Robust Infrastructure:
- Doxygen-generated documentation 📚 for easy navigation and understanding
- Catch2 unit tests ✅ for ensuring code quality and reliability
- CMake build system 🛠️ for cross-platform compatibility and easy installation
- clang-format code formatting 💅 for consistent and readable code

## Comparison to Alternatives 🤔
To help you decide whether libnumerixpp is the right choice for your project, here's a comparison table with some popular numerical computation libraries:

| Feature | libnumerixpp | Eigen | Boost.Numeric | LAPACK |
| --- | --- | --- | --- | --- |
| Multi-disciplinary Approach | ✅ | ❌ | ❌ | ❌ |
| Equation Solving | ✅ | ❌ | ✅ | ❌ |
| Statistical Functions | ❌ | ❌ | ✅ | ❌ |
| Kinematics Calculations | ✅ | ❌ | ❌ | ❌ |
| Number System Conversion | ✅ | ❌ | ❌ | ❌ |
| Doxygen Documentation | ✅ | ✅ | ✅ | ❌ |
| Unit Tests | ✅ | ✅ | ✅ | ✅ |
| Cross-platform Support | ✅ | ✅ | ✅ | ✅ |
As you can see, libnumerixpp offers a unique combination of features that sets it apart from other popular numerical computation libraries. Its multi-disciplinary approach, comprehensive functionality, and robust infrastructure make it a compelling choice for a wide range of projects.

## Getting Started 🚀

To get started with libnumerixpp, follow these simple steps:

1. Clone the repository:

```bash
git clone https://github.com/libnumerixpp/libnumerixpp.git
```

2. Build the library using the provided script:

```bash
cd libnumerixpp
./build.sh
```

3. Include the nessary modules in your code using [`#include`](https://github.com/alexeev-prog/libnumerixpp/tree/main/include) directives:

```cpp
#include "libnumerixpp/core/common.hpp" // example
```

4. Start using the library functions in your applications! You can view [examples of usage here](https://github.com/alexeev-prog/libnumerixpp/tree/main/examples).

## Examples 💻

<details>
<summary>Mathematics</summary>

```cpp
#include <iostream>
#include <vector>

#include "libnumerixpp/core/common.hpp"
#include "libnumerixpp/libnumerixpp.hpp"
#include "libnumerixpp/mathematics/core.hpp"
#include "libnumerixpp/mathematics/quadratic_equations.hpp"

auto main() -> int {
	credits();
	println("LIBNUMERIXPP");

	// SQUARE AND SQR //

	double const num = 100.0;
	double const num_sq = mathematics::square_it_up(num);
	double const num_sqr = mathematics::get_square_root(num);
	std::cout << "Square " << num << ": " << num_sq << '\n';
	std::cout << "Square root " << num << ": " << num_sqr << '\n';

	std::cout << '\n';

	// CALCULATE QUADRATIC EQUATION BY DISCRIMINANT //

	double const a = -2;
	double const b = 5;
	double const c = 5;

	double const d = mathematics::quadratic::calculateDiscriminant(a, b, c);
	std::vector<double> const roots = mathematics::quadratic::calculateRootsByDiscriminant(d, a, b);

	std::cout << "Quadratic Equation: a=" << a << "; b=" << b << "; c=" << c << '\n';
	std::cout << "D=" << d << '\n';
	std::cout << "Roots:" << '\n';

	for (double const root : roots) {
		std::cout << root << '\n';
	}

	std::cout << '\n';

	// PERCENTAGE //

	double const nump = mathematics::add_percent_to_number(100.0, 10.0);
	std::cout << "100+10%: " << nump << '\n';

	std::cout << '\n';

	// POWER / Algorithms for fast exponentiation //

	double const best_pow_val = 100;
	double const pow_results[5] = { mathematics::oldApproximatePower(10.0, 2.0),
									mathematics::anotherApproximatePower(10.0, 2.0),
									mathematics::binaryPower(10.0, 2),
									mathematics::fastPowerDividing(10.0, 2.0),
									mathematics::fastPowerFractional(10.0, 2.0) };

	std::cout << "0 oldApproximatePower	   : base 10 exponent 2: " << pow_results[0] << '\n';
	std::cout << "1 anotherApproximatePower: base 10 exponent 2: " << pow_results[1] << '\n';
	std::cout << "2 binaryPower			   : base 10 exponent 2: " << pow_results[2]
			  << '\n';
	std::cout << "3 fastPowerDividing	   : base 10 exponent 2: " << pow_results[3] << '\n';
	std::cout << "4 fastPowerFractional	   : base 10 exponent 2: " << pow_results[4] << '\n';

	for (int i = 0; i < sizeof(pow_results) / sizeof(pow_results[0]); i++) {
		double const error = best_pow_val - pow_results[i];

		std::cout << "POW Algorithm #" << i << ": error=" << error << '\n';
	}

	std::cout << '\n';

	// Other //

	std::cout << "-10 number module: " << mathematics::intabs(-10) << '\n';

	return 0;
}
```

```cpp
#include <cmath>
#include <iostream>
#include <string>

#include "libnumerixpp/core/common.hpp"
#include "libnumerixpp/libnumerixpp.hpp"
#include "libnumerixpp/mathematics/equations.hpp"

void test_eq_sa(double (*f_eq)(double), double x0, const std::string &eq) {
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
```

</details>

<details>
<summary>Physics</summary>

```cpp
#include <iostream>

#include "libnumerixpp/core/common.hpp"
#include "libnumerixpp/libnumerixpp.hpp"
#include "libnumerixpp/physics/kinematics.hpp"

auto main() -> int {
	credits();
	println("LIBNUMERIXPP");

	double speed = 10.0;
	double time = 5.0;

	double const path = physics::kinematics::calculate_path(speed, time);
	speed = physics::kinematics::calculate_speed(path, time);
	time = physics::kinematics::calculate_time(path, speed);

	std::cout << "Calculate: speed=" << speed << "m/s" << "; time=" << time << "s"
			  << "; path=" << path << "m" << '\n';

	double const final_velocity = physics::kinematics::calculate_final_velocity(10.0, 10.0, 10.0);
	std::cout << "final velocity (10.0, 10.0, 10.0) = " << final_velocity << '\n';

	double const final_position =
		physics::kinematics::calculate_final_position(10.0, 10.0, 10.0, 10.0);
	std::cout << "final position (10.0, 10.0, 10.0, 10.0) = " << final_velocity << '\n';

	return 0;
}
```

</details>

<details>
<summary>Computer Science</summary>

```cpp
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
	std::string const hexadecimal_number2 =
		computerscience::convertBinaryToHexadecimal(binary_number);
	std::string const binary_number2 =
		computerscience::convertHexadecimalToBinary(hexadecimal_number);
	long long const bytes = 1024 * 1024;

	std::cout << "Convert decimal " << decimal_number << " to binary: " << binary_number << '\n';
	std::cout << "Convert binary " << binary_number << " to decimal: " << decimal_number2 << '\n';
	std::cout << "Convert decimal " << decimal_number << " to hexadecimal: " << hexadecimal_number
			  << '\n';
	std::cout << "Convert hexadecimal " << hexadecimal_number << " to decimal: " << decimal_number3
			  << '\n';
	std::cout << "Convert binary " << binary_number << " to hexadecimal: " << hexadecimal_number2
			  << '\n';
	std::cout << "Convert hexadecimal " << hexadecimal_number << " to binary: " << binary_number2
			  << '\n';
	std::cout << "Convert " << bytes << ": " << computerscience::humanizeBytesSize(bytes) << '\n';

	return 0;
}
```

</details>

## Architecture
libnumerixpp has a modular architecture consisting of the following core components:

 - core: Provides essential data types, error handling functions, and utility tools.
 - mathematics: Implements algorithms for linear algebra, calculus, and geometry.
 - physics: Offers functions for solving problems in the areas of kinematics, mechanics, thermodynamics and electronics.
 - computerscience: Offers functions for converting data and other CS utils

Each module has its own set of header files and source files, ensuring flexibility and the ability to selectively compile the required parts of the library.

```
.
├── build.sh
├── CHANGELOG.md
├── cmake
│   ├── coverage.cmake
│   ├── dev-mode.cmake
│   ├── docs-ci.cmake
│   ├── docs.cmake
│   ├── folders.cmake
│   ├── install-config.cmake
│   ├── install-rules.cmake
│   ├── lint.cmake
│   ├── lint-targets.cmake
│   ├── prelude.cmake
│   ├── project-is-top-level.cmake
│   ├── spell.cmake
│   ├── spell-targets.cmake
│   └── variables.cmake
├── CMakeLists.txt
├── CMakePresets.json
├── CMakeUserPresets.json
├── conanfile.py
├── docs
│   ├── doxygen-styles.css
│   ├── en
│   │   └── index.md
│   ├── man
│   │   └── man3
│   │       ├── common.cpp.3
│   │       ├── computerscience.3
│   │       ├── core.cpp.3
│   │       ├── core.hpp.3
│   │       ├── equations.cpp.3
│   │       ├── equations.hpp.3
│   │       ├── kinematics.cpp.3
│   │       ├── kinematics.hpp.3
│   │       ├── libnumerixpp.cpp.3
│   │       ├── mathematics.3
│   │       ├── mathematics_quadratic.3
│   │       ├── mathematics_statistics.3
│   │       ├── physics.3
│   │       ├── physics_kinematics.3
│   │       ├── quadratic_equations.cpp.3
│   │       ├── quadratic_equations.hpp.3
│   │       ├── statistics.cpp.3
│   │       ├── statistics.hpp.3
│   │       └── todo.3
│   ├── README.md
│   └── ru
│       ├── article2.md
│       ├── article.md
│       └── index.md
├── Doxyfile
├── Doxygen.cmake
├── examples
│   ├── example-1.cpp
│   ├── example-2.cpp
│   ├── example-3.cpp
│   └── example-4.cpp
├── format-code.py
├── include
│   └── libnumerixpp
│       ├── computerscience
│       │   └── core.hpp
│       ├── core
│       │   └── common.hpp
│       ├── export.h
│       ├── libnumerixpp.hpp
│       ├── mathematics
│       │   ├── core.hpp
│       │   ├── equations.hpp
│       │   ├── quadratic_equations.hpp
│       │   └── statistics.hpp
│       └── physics
│           ├── core.hpp
│           └── kinematics.hpp
├── LICENSE
├── README.md
├── spacetabs.sh
├── src
│   ├── computerscience
│   │   └── core.cpp
│   ├── core
│   │   └── common.cpp
│   ├── libnumerixpp.cpp
│   ├── mathematics
│   │   ├── core.cpp
│   │   ├── equations.cpp
│   │   ├── quadratic_equations.cpp
│   │   └── statistics.cpp
│   └── physics
│       ├── core.cpp
│       └── kinematics.cpp
└── test
    ├── CMakeLists.txt
    └── source
        └── libnumerixpp_test.cpp
```

## Tools and Dependencies
linumerixpp utilizes the following tools and libraries:

 - **CMake**: Cross-platform build system
 - **Doxygen**: Documentation generation

## Documentation 📚
Detailed documentation, including user guides, API reference, and code examples, is available in the [docs](https://alexeev-prog.github.io/libnumerixpp/). Or you can see articles or additional info in [en docs dir](https://github.com/alexeev-prog/libnumerixpp/blob/main/docs/en/index.md) or [ru docs dir](https://github.com/alexeev-prog/libnumerixpp/blob/main/docs/ru/index.md).

If you have any questions, suggestions, or encounter issues, please create a new [issue](https://github.com/alexeev-prog/libnumerixpp/issues/new) in the repository. We'll be happy to assist you and improve the library.

You can also write to me on Telegram: [@alexeev_dev](https://t.me/alexeev_dev)

libnumerixpp is an Open Source project, and it only survives due to your feedback and support!

Project releases are available at [this link](https://github.com/alexeev-prog/libnumerixpp/releases).

## Requirements 📋

To use libnumerixpp, you will need the following:

- A C++17 compatible compiler (e.g., GCC 8+, Clang 8+, or MSVC 2019+)
- CMake 3.14 or newer
- Catch2 testing framework (included as a submodule)

## Our Projects 🔧
Check other our projects:

 + [Shegang - functional shell in C for linux](https://github.com/alexeev-prog/shegang).
 + [Hex64 - software for benchmarking](https://github.com/alexeev-prog/hex64)
 + [Pentest 154 - software for simple OSINT and search info about target](https://github.com/alexeev-prog/pentest154)

## Contributing 🤝

We welcome contributions from the community! If you would like to contribute to the libnumerixpp project, please read our [contribution guidelines](CONTRIBUTING.md) and submit a pull request.

## Get Help 🆘

If you encounter any issues or have questions about using libnumerixpp, you can:

- 🐞 Open an issue on the [GitHub repository](https://github.com/alexeev-prog/libnumerixpp/issues)
- 📧 Contact the project maintainers at dev.alexeev@main.ru

## Future Plans 🔮

The libnumerixpp team is continuously working on expanding the library's capabilities and improving its overall performance and usability. Some of our future plans include:

- 🧠 Implementing more advanced mathematical and physical computations, such as differential equations, linear algebra, and fluid dynamics
- ⚡ Adding support for parallel processing and GPU acceleration to boost performance on large-scale computations
- 🎨 Integrating with popular data visualization and scientific computing frameworks, making it easier to use libnumerixpp in complex project workflows

Stay tuned for more updates! 🚀

## Testing 🧪

libnumerixpp uses the Catch2 testing framework to ensure the quality and reliability of the provided functionalities. The unit tests are located in the tests directory of the repository.

To run the tests, you can execute the following command from the project's root directory:

```bash
./build/test/libnumerixpp_test
```

This will run all the available tests and report the results.

## Copyright 📄
libnumerixpp is released under the [Apache License 2.0](https://github.com/alexeev-prog/libnumerixpp/blob/main/LICENSE).

Copyright © 2024 Alexeev Bronislav. All rights reversed.
