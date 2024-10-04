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
> At the moment, libnumerixpp is under active development (alpha), many things may not work, and this version is not recommended for use (all at your own risk).

libnumerixpp is a powerful, cross-platofrm C++ library designed for high-performance numerical computing in the domains of physics, mathematics, and computer science.

You can join to our [small russian telegram blog](https://t.me/hex_warehouse).

 > You can view docs for libnumerixpp [here](https://alexeev-prog.github.io/libnumerixpp).

 > Current version: 0.1.2

## Key Features
 - **Extensive Functionality**: libnumerixpp provides a wide range of functions coverint the core areas of mathematics, physics, and computer science, including:
  - Mathematics: linear algebra, calculus, geometry
  - Physics: kinematics, mechanics, thermodynamics, electronics
  - Computer Science: algorithms, numerical methods, data processing
 - **High Performance**: The library is optimized for maximum performance, leveraging modern techniques such as parallel computing and vectorization
 - **Cross-platform Support**: libnumerixpp supports major operating systems (Windows, Linux, macOS) and can be compiled using various compilers (GCC, CLANG, MSVC).
 - **Ease of Use**: A simple and intuitive API, comprehensive documentation, and numerous examples facilitate the integration of the library into your projects.
 - **Modular Architecture**: libnumerixpp is designed with a modular structure, allowing selective compilation of only the required components.
 - **Extensibility**: The library is open to the developer community, who can contribute improvements and additions.

## Architecture
libnumerixpp has a modular architecture consisting of the following core components:

 - core: Provides essential data types, error handling functions, and utility tools.
 - mathematics: Implements algorithms for linear algebra, calculus, and geometry.
 - physics: Offers functions for solving problems in the areas of kinematics, mechanics, thermodynamics and electronics.

Each module has its own set of header files and source files, ensuring flexibility and the ability to selectively compile the required parts of the library.

## Usage
To use libnumerixpp in your project, follow these steps:

1. Download or clone the repository from github:

```bash
git clone https://github.com/alexeev-prog/libnumerixpp.git
```

2. Set up the build process using build script:

```bash
cd libnumerixpp
./build.sh

# if you want build shared lib
./build.sh BUILD_SHARED_LIBS

# OR
cd libnumerixpp
mkdir build && cd build
cmake .. # or cmake .. -DBUILD_SHARED_LIBS=ON
make install
```

3. Include the nessary modules in your code using [`#include`](https://github.com/alexeev-prog/libnumerixpp/tree/main/include) directives:

```cpp
#include "libnumerixpp/core/common.hpp" // example
```

4. Start using the library functions in your applications! You can view [examples of usage here](https://github.com/alexeev-prog/libnumerixpp/tree/main/examples).

## Examples
Below you can see examples of using libnumerixpp in your project. Also, you can view [examples dir](https://github.com/alexeev-prog/libnumerixpp/tree/main/examples).

### example-1 Speed, Time, Path
Source code: [example-1.cpp](https://github.com/alexeev-prog/libnumerixpp/blob/main/examples/example-1.cpp)

This example shows how to calculate the *speed, path, and time* using the `physics::kinematics`.

### example-2 Math, Quadratic and math
Source code: [example-2.cpp](https://github.com/alexeev-prog/libnumerixpp/blob/main/examples/example-2.cpp)

This example shows how to calculate the *quadratic equations, discriminant, squares* using the `mathematics` and `mathematics::quadratic`.

### example-3 Computer-science
Source code: [example-3.cpp](https://github.com/alexeev-prog/libnumerixpp/blob/main/examples/example-3.cpp)

This example shows how to convert data using the `computerscience' module.

### example-4 Math Equations
Source code: [example-4.cpp](https://github.com/alexeev-prog/libnumerixpp/blob/main/examples/example-4.cpp)

This example shows how to calculate the *equations* using the `mathematics` and `mathematics::equations`.

## Tools and Dependencies
linumerixpp utilizes the following tools and libraries:

 - **CMake**: Cross-platform build system
 - **Doxygen**: Documentation generation

## Documentation
Detailed documentation, including user guides, API reference, and code examples, is available in the [docs](https://alexeev-prog.github.io/libnumerixpp/). Or you can see articles or additional info in [en docs dir](https://github.com/alexeev-prog/libnumerixpp/blob/main/docs/en/index.md) or [ru docs dir](https://github.com/alexeev-prog/libnumerixpp/blob/main/docs/ru/index.md).

If you have any questions, suggestions, or encounter issues, please create a new [issue](https://github.com/alexeev-prog/libnumerixpp/issues/new) in the repository. We'll be happy to assist you and improve the library.

You can also write to me on Telegram: [@alexeev_dev](https://t.me/alexeev_dev)

libnumerixpp is an Open Source project, and it only survives due to your feedback and support!

Project releases are available at [this link](https://github.com/alexeev-prog/libnumerixpp/releases).

## Our Projects
Check other our projects:

 + [Shegang - functional shell in C for linux](https://github.com/alexeev-prog/shegang).
 + [Hex64 - software for benchmarking](https://github.com/alexeev-prog/hex64)
 + [Pentest 154 - software for simple OSINT and search info about target](https://github.com/alexeev-prog/pentest154)

## Project Architecture

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

## Copyright
libnumerixpp is released under the [Apache License 2.0](https://github.com/alexeev-prog/libnumerixpp/blob/main/LICENSE).

Copyright © 2024 Alexeev Bronislav. All rights reversed.
