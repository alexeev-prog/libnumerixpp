# Создаем свою библиотеку на C++ с математикой и блекджеком: часть 2
В мире программирования создание собственных библиотек - это не просто возможность пополнения своего портфолио или способ структурировать код, а настоящий акт творческого самовыражения (и иногда велосипедостроения). Каждый разработчик иногда использовал в нескольких своих проектах однообразный код, который приходилось каждый раз перемещать. Да и хотя-бы как упаковать свои идеи и знания в удобный и доступный формат, которым можно будет поделиться с сообществом.

Если вы ловили себя на мысли: "А почему мне бы не создать свою полноценную библиотеку?", то я рекомендую прочитать вам мою статью.

Эту статью вы можете использовать как шпаргалку для создания проектов, и не только библиотек.

Некоторые из вас могут подумать что мы изобретаем велосипед. А я в ответ скажу - сможете ли вы прямо сейчас, без подсказок, только по памяти, нарисовать велосипед без ошибок?

Добро пожаловать во вторую, скорее всего финальную часть статьи! Здесь мы окончательно допишем код, исправим некоторые ошибки.

---

Первая часть доступна по [ссылке](https://habr.com/ru/companies/timeweb/articles/845074/).

В этой статье мы добавим в нашу библиотеку больше функционала. Я сразу говорю, наша библиотека создана just for fun и just for learning, мы не собираемся конкурировать с крупными библиотеками.

Репозиторий с исходным кодом доступен по [этой ссылке](https://github.com/alxvdev/libnumerixpp).

Не будем медлить, начнем прямо сейчас!

# Отличие статистических от динамических библиотек
Стоит перед началом поговорить о самом устройстве библиотек. Разделяются они на два типа - статистические и динамические.

Библиотеки бывают двух видов — статические и динамические. Код первых при компиляции полностью входит в состав исполняемого файла, что делает программу легко переносимой. Код динамических библиотек не входит в исполняемый файл, последний содержит лишь ссылку на библиотеку. Если динамическая библиотека будет удалена или перемещена в другое место, то программа работать не будет. С другой стороны, использование динамических библиотек позволяет сократить размер исполняемого файла. Также если в памяти находится две программы, использующие одну и туже динамическую библиотеку, то последняя будет загружена в память лишь единожды.

Динамическая библиотека это фактически исполняемый файл (т.е. DLL и EXE в Windows имеют одинаковый формат). Динамическая линковка запускается в момент создания процесса (когда вы запускаете исполняемый файл на выполнение), линкуются между собой несколько исполняемых файлов каждый раз, когда создается новый процесс. Так же возможна динамическая линковка уже после запуска, т.е. новая библиотека может быть подгружена в адресное пространство ужа работающего процесса.

Сделать из статической библиотеки динамическую в принципе можно - необходимо ее (статически) слинковать в динамическую библиотеку, при этом будет создана динамическая библиотека и статическая стаб-библиотека, которую можно использовать в проекте вместо статической библиотеки, чтобы вызывать функции из динамической библиотеки.

Статическую библиотеку создать проще. Она создается из обычных объектных файлов путем их архивации с помощью утилиты ar.

Объектные файлы для динамической библиотеки компилируются особым образом. Они должны содержать так называемый позиционно-независимый код (position independent code). Наличие такого кода позволяет библиотеке подключаться к программе, когда последняя загружается в память. Это связано с тем, что библиотека и программа не являются единой программой, а значит как угодно могут располагаться в памяти относительно друг друга. Компиляция объектных файлов для динамической библиотеки должна выполняться с опцией -fPIC компилятора C++.

# Инструменты C++
Итак, создав С++ проект приходится не только писать код, но и анализировать, обустраивать и улучшать вес проект. В этой части статьи, перед началом работы, я расскажу о нескольких популярных инструментах для работы с C++ кодом и не только. И только потом мы приступим к непосредственному программированию

## Valgrind - поиск ошибок работы с памятью
Если вы пишете код на C/C++, то поиск утечек памяти, ошибки работы с массивами, неправильное обращение с памятью могут доставить большие проблемы. А если вы еще и пишете библиотеку, то к этому вопросу надо подходить внимательно и с особым подходом.

Для решения таких проблем существует Valgrind. Он гибок, работает везде, находит неинициализированные данные с точностью до одного бита. Из недостатков можно отметить только низкую скорость работы.

Перейдем к примеру:

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_test(int i) {
	int delta = 128;
	char* mem = malloc(1024);
	printf("%s %s\n", mem, i + delta);
	// free(mem);
}

void main() {
	for (int i = 0; i < 10; i++) {
		run_test(i);
	}
}
```

Компилируем и запускаем через valgrind:

```bash
gcc -O0 -g test.c -o test
valgrind ./test
```

Результат:

```
==1948== HEAP SUMMARY:
==1948==     in use at exit: 10,240 bytes in 10 blocks
==1948==   total heap usage: 11 allocs, 1 frees, 11,264 bytes allo...
==1948==
==1948== LEAK SUMMARY:
==1948==    definitely lost: 10,240 bytes in 10 blocks
==1948==    indirectly lost: 0 bytes in 0 blocks
==1948==      possibly lost: 0 bytes in 0 blocks
==1948==    still reachable: 0 bytes in 0 blocks
==1948==         suppressed: 0 bytes in 0 blocks
```

Видим, что память утекла. Запускаем с --leak-check=full:

```
==2047== 10,240 bytes in 10 blocks are definitely lost in loss recor...
==2047==    at 0x4C2AF1F: malloc (in /usr/lib/valgrind/vgpreload_mem...
==2047==    by 0x400561: run_test (vgcheck.c:8)
==2047==    by 0x4005AF: main (vgcheck.c:18)
```

Теперь раскомментируем вызов free и уберем инициализацию переменной delta. Посмотрим, увидит ли Valgrind обращение к неинициализированной памяти:

```
==2102== Conditional jump or move depends on uninitialised value(s)
==2102==    at 0x4E8003C: vfprintf (in /usr/lib/libc-2.25.so)
==2102==    by 0x4E87EA5: printf (in /usr/lib/libc-2.25.so)
==2102==    by 0x4005CA: run_test (vgcheck.c:10)
==2102==    by 0x4005F4: main (vgcheck.c:18)
```

Видит. Запустим с --track-origins=yes чтобы найти, откуда именно пришла неинициализированная переменная:

```
==2205== Conditional jump or move depends on uninitialised value(s)
==2205==    at 0x4E800EE: vfprintf (in /usr/lib/libc-2.25.so)
==2205==    by 0x4E87EA5: printf (in /usr/lib/libc-2.25.so)
==2205==    by 0x4005CA: run_test (vgcheck.c:10)
==2205==    by 0x4005F4: main (vgcheck.c:18)
==2205==  Uninitialised value was created by a stack allocation
==2205==    at 0x400586: run_test (vgcheck.c:6)
```

Как видите, Valgrind нашел место объявления неинициализированной переменой с точностью до имени файла и номера строчки.

Теперь исправим все ошибки:

```
==2239== HEAP SUMMARY:
==2239==     in use at exit: 0 bytes in 0 blocks
==2239==   total heap usage: 11 allocs, 11 frees, 11,264 bytes allo...
==2239==
==2239== All heap blocks were freed -- no leaks are possible
```

Ну разве не красота?

## Анализ кода

### cppcheck
cppcheck - это проект статического анализа с открытым исходным кодом, ориентированный в первую очередь на нахождение реальных ошибок в коде с минимальным количеством ложных срабатываний.

cppcheck перестраховывается, причём планка адекватности высока. Большинство проверок cppcheck по умолчанию не включает. Среди них следующие категории проверок, каждая из которых может включаться/выключаться независимо:

 + error — явные ошибки, которые анализатор считает критическими и обычно они приводят к багам (включено по умолчанию);
 + warning — предупреждения, здесь даются сообщения о небезопасном коде;
 + style — стилистические ошибки, сообщения появляются в случае неаккуратного кодирования (больше похоже на рекомендации);
 + performance — проблемы производительности, здесь cppcheck предлагает варианты, как сделать код быстрее (но это не  всегда даёт прирост производительности);
 + portability — ошибки совместимости, обычно связано с различным поведением компиляторов или систем разной разрядности;
 + information — информационные сообщения, возникающие в ходе проверки (не связаны с ошибками в коде);
 + unusedFunction — попытка вычислить неиспользуемые функции (мёртвый код), не умеет работать в многопоточном режиме;
 + missingInclude — проверка на недостающий #include (например, используем random, а подключить stdlib.h забыли).

Включаются проверки параметром --enable, список категорий проверок перечисляется через запятую. Например:

```
cppcheck -q -j4 --enable=warning,style,performance,portability ./source
```

Существует ключевое слово all, которое включает все перечисленные проверки.

Примечание. Параметры -j и режим проверки unusedFunction несовместимы, поэтому -j выключит проверку unusedFunction, даже если она указана явно.

Пример команды, которая «гоняет» код по всем правилам:

```
cppcheck -q --enable=all ./source
```

И это ещё не всё. Если ваша программа безошибочна с точки зрения анализатора, попробуйте запустить cppcheck с параметром --inconclusive. Данный режим действительно включает все возможные проверки, даже ошибки с малой вероятностью, которые cppcheck пропускает по умолчанию.

Таким образом, самый подробный режим проверки:

```
cppcheck -q --enable=all --inconclusive ./source
```

Не забывайте о кроссплатформенности!

Cppcheck изначально создавался как инструмент, работающий с разными операционными системами и платформами. Поэтому нужно обязательно следить за тем, для какой платформы написана программа и какой режим проверки использует cppcheck. Платформа переключается параметром --platform.

Различные платформы:

+ unix32 — все 32-разрядные unix (включая Linux);
 + unix64 — все 64-разрядные unix;
 + win32A — семейство 32-разрядных Windows с кодировкой ASCII;
 + win32W — семейство 32-разрядных Windows с кодировкой UNICODE;
 + win64 — семейство 64-разрядных Windows.

Если нужно проверить код, который был написан для Win32, используя Linux, нужно обязательно указать платформу:

```
cppcheck --platform=win32A ./source
```

## clang-format
Clang-format — это инструмент для автоматического форматирования кода на C/C++/Objective-C.

Данный инструмент позволяет быстро форматировать ваш код. Для его использования нужно ввести следующую команду:

```bash
clang-format --style=Google --dump-config > .clang-format
```

Она создаст конфиг .clang-format, который потребуется для форматирования. В данном примере мы выбрали стиль гугла, но я его немного поредактировал, вы можете просмотреть его [по этой ссылке](https://github.com/alxvdev/libnumerixpp/blob/main/.clang-format).

Но это еще не все. Нам нужно написать скрипт, который будет форматировать весь код при помощи конфига clang-format (и заодно менять пробелы на табы, т.к. табы рулят :) ):

```python
#!/usr/bin/env python3
# Python program to format C/C++ files using clang-format 
import os
import subprocess

# Define color codes for output
RED = '\033[31m'
GREEN = '\033[32m'
YELLOW = '\033[33m'
NC = '\033[0m'  # No Color
BOLD = '\033[1m'  # No Color

# File Extension filter. You can add new extension 
cpp_extensions = (".cxx",".cpp",".c", ".hxx", ".hh", ".cc", ".hpp") 
IGNORED_DIRS = ['build', '.git', 'cmake', 'docs']

CLANG_FORMAT = 'clang-format'
SPACETABS = './space-tabs.sh'

print(f'libnumerixpp code-formatter: {CLANG_FORMAT}; Extensions: {" ".join(cpp_extensions)}')


def print_usage():
	"""Print the usage instructions."""
	print(f"{YELLOW}Usage: convert_tabs(file_path, tab_size, conversion_type){NC}")
	print(f"<conversion_type>: 'spaces' or 'tabs'")


def print_error(message):
	"""Print error messages."""
	print(f"{RED}Error: {message}{NC}")


def validate_positive_integer(value):
	"""Validate if the value is a positive integer."""
	try:
		int_value = int(value)
		if int_value < 1:
			raise ValueError
		return int_value
	except ValueError:
		print_error("Tab size must be a positive integer.")
		return None


def file_exists(file_path):
	"""Check if the file exists."""
	if not os.path.isfile(file_path):
		print_error(f"File not found: {file_path}")
		return False
	return True


def convert_tabs(file_path, tab_size, conversion_type):
	"""Convert tabs to spaces or spaces to tabs based on conversion type."""
	try:
		if conversion_type == "spaces":
			print(f"{BOLD}Converting tabs to spaces...{NC}")
			subprocess.run(["expand", "-t", str(tab_size), file_path], stdout=open(f"{file_path}.tmp", "w"))
		elif conversion_type == "tabs":
			print(f"{BOLD}Converting spaces to tabs...{NC}")
			subprocess.run(["unexpand", "-t", str(tab_size), file_path], stdout=open(f"{file_path}.tmp", "w"))
		else:
			print_error(f"Invalid conversion type: {conversion_type}. Use 'spaces' or 'tabs'.")
			return

		os.replace(f"{file_path}.tmp", file_path)
		print(f"{GREEN}Conversion completed successfully: {file_path}{NC}")
	except Exception as e:
		print_error(f"Conversion failed: {str(e)}")


def convert_file(file_path, tab_size, conversion_type):
	"""Main function to manage conversion."""
	tab_size = validate_positive_integer(tab_size)
	if tab_size is None:
		return
	
	if not file_exists(file_path):
		return

	convert_tabs(file_path, tab_size, conversion_type)
	

def main():
	# Set the current working directory for scanning c/c++ sources (including 
	# header files) and apply the clang formatting 
	# Please note "-style" is for standard style options 
	# and "-i" is in-place editing 
	for root, dirs, files in os.walk(f'{os.getcwd()}/src'):
		for file in files: 
			if file.endswith(cpp_extensions):
				print(f"{BOLD}Format {file}: {root}/{file}{NC}")
				os.system(f"{CLANG_FORMAT} -i -style=file {root}/{file}")
				print(f"{GREEN}Formatting completed successfully: {root}/{file}{NC}")
				convert_file(f'{root}/{file}', "4", "tabs")


if __name__ == '__main__':
	main()
```

# Структура проекта
Давайте сразу рассмотрим обновленную структуру системы сборки CMake. В прошлой части вы посоветовали сделать CMakeLists.txt для каждой директории. А мы поступим немного по другому - вместо самостоятельного создания всех файлов будем использовать инструмент [cmake-init](https://github.com/friendlyanon/cmake-init).

Разработчик утверждает, что cmake-init имеет следующие фичи:

 + Простой в использовании и настройки - разные пути использования (Вам нужна библиотека только для заголовков? При появлении запроса выберите h. Статическая/общая библиотека? Просто выберите s при появлении запроса.)
 + Современный CMake, покрытие кода, анализ и форматирование (clang-format), статистический анализ (clang-tidy), динамический анализ (sanitizers, valgrind).

cmake-init требует следующие зависимости:

 + Python 3.8 or newer
 + CMake 3.20 or newer (3.21 or newer for C17 or newer projects)
 + [Catch2 c++ library](https://github.com/catchorg/Catch2)
 + git
 + clang-tidy 14 (optional)
 + cppcheck (optional)
 + LCOV (optional)
 + clang-format 14 (optional)
 + codespell (optional)
 + Package managers: Conan or vcpkg (optional)

Самый простой способ - установить cmake-init через pip:

```bash
pip install cmake-init
```

Для того, чтобы создать проект при помощи cmake-init, нужно ввести следующую команду:

```bash
cmake-init <название проекта>
```

После чего у вас спросят следующие параметры проекта:

```
cmake-init is going to generate a C++ project

Use only characters matching the [0-9a-zA-Z-_] pattern
Project name (example):

Use Semantic Versioning, because CMake naturally supports that. Visit
https://semver.org/ for more information.
Project version (0.1.0):

Short description:

Homepage URL (https://example.com/):

C++ standard to use. Defaults to 17.
C++ standard (11/14/17/20):

Type of the target this project provides. A static/shared library will be set
up to hide every symbol by default (as it should) and use an export header to
explicitly mark symbols for export/import, but only when built as a shared
library.
Target type ([E]xecutable or [h]eader-only or [s]tatic/shared):

This will require you to download clang-tidy locally.
Add clang-tidy to local dev preset ([Y]es/[n]o):

This will require you to download cppcheck locally.
Add cppcheck to local dev preset ([Y]es/[n]o):

Choosing Conan requires it to be installed. Choosing vcpkg requires the
VCPKG_ROOT environment variable to be setup to vcpkg's root directory.
Package manager to use ([N]one/[c]onan/[v]cpkg):

Initialized empty Git repository in /home/alexeev/Desktop/example/.git/

The project is ready to be used with git. If you are using GitHub, you may
push the project with the following commands from the project directory:

    git add .
    git commit -m "Initial commit"
    git remote add origin https://github.com/<your-account>/<repository>.git
    git push -u origin master

To get started with developing the project, make sure you read the generated
HACKING.md and BUILDING.md files for how to build the project as a developer or
as a user respectively. There are also some details you may want to fill in in
the README.md, CONTRIBUTING.md and .github/workflows/ci.yml files.

Now make sure you have at least CMake 3.20 installed for local development, to
make use of all the nice Quality-of-Life improvements in newer releases:
https://cmake.org/download/

For more tips, like integration with package managers, please see the Wiki:
https://github.com/friendlyanon/cmake-init/wiki

You are all set. Have fun programming and create something awesome!
```

И теперь вы можете начинать работу. Архитектура сгенерированного проекта очень схожа с прошлой, но сама система сборки улучшена, и появилась директория test, в которой находятся тесты с использованием библиотеки Catch2 (catch2 потребуется установить, если у вас Linux, то используйте ваш пакетный менеджер). Я же не стал начинать с нуля, просто скопировал нужные мне файлы и директории (CMakeLists, cmake/, различные файлы).

CMakeLists.txt теперь выглядит у меня так:

```cmake
cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    libnumerixpp
    VERSION 0.1.1
    DESCRIPTION "A Powerful C++ Library for High-Performance Numerical Computing"
    HOMEPAGE_URL "https://alxvdev.github.io/libnumerixpp"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    libnumerixpp_libnumerixpp
    src/libnumerixpp.cpp
    src/core/common.cpp
    src/mathematics/equations.cpp
    src/mathematics/core.cpp
    src/mathematics/quadratic_equations.cpp
    src/mathematics/statistics.cpp
    src/physics/core.cpp
    src/physics/kinematics.cpp
    src/computerscience/core.cpp
)
add_library(libnumerixpp::libnumerixpp ALIAS libnumerixpp_libnumerixpp)

include(GenerateExportHeader)
generate_export_header(
    libnumerixpp_libnumerixpp
    BASE_NAME libnumerixpp
    EXPORT_FILE_NAME export/libnumerixpp/libnumerixpp_export.hpp
    CUSTOM_CONTENT_FROM_VARIABLE pragma_suppress_c4251
)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(libnumerixpp_libnumerixpp PUBLIC LIBNUMERIXPP_STATIC_DEFINE)
endif()

set_target_properties(
    libnumerixpp_libnumerixpp PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
    VERSION "${PROJECT_VERSION}"
    SOVERSION "${PROJECT_VERSION_MAJOR}"
    EXPORT_NAME libnumerixpp
    OUTPUT_NAME libnumerixpp
)

target_include_directories(
    libnumerixpp_libnumerixpp ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_include_directories(
    libnumerixpp_libnumerixpp SYSTEM
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/export>"
)

target_compile_features(libnumerixpp_libnumerixpp PUBLIC cxx_std_17)

find_package(fmt REQUIRED)
target_link_libraries(libnumerixpp_libnumerixpp PRIVATE fmt::fmt)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT libnumerixpp_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of libnumerixpp"
  )
endif()

include(cmake/dev-mode.cmake)
```

Вам надо будет также изменить его под ваши требования. Блок ниже обозначает файлы, входящие в состав библиотеки:

```
add_library(
    libnumerixpp_libnumerixpp
    src/libnumerixpp.cpp
    src/core/common.cpp
    src/mathematics/equations.cpp
    src/mathematics/core.cpp
    src/mathematics/quadratic_equations.cpp
    src/mathematics/statistics.cpp
    src/physics/core.cpp
    src/physics/kinematics.cpp
    src/computerscience/core.cpp
)
```

А также я решил оставить скрипт build.sh, но немного улучшив его:

```bash
#!/bin/bash

# Define colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Project information
PROJECT_NAME="libnumerixpp"
BUILD_DIR="build"

# Functions
function print_header() {
	echo -e "${YELLOW}#######################################################################${NC}"
	echo -e "${YELLOW}### ${1}${NC}"
	echo -e "${YELLOW}#######################################################################${NC}"
}

function print_step() {
	currdate=$(date +"%Y-%m-%d %H:%M:%S")
	echo -e "${currdate} ${BLUE}[ * ] ${1}${NC}"
}

function print_debug() {
	currdate=$(date +"%Y-%m-%d %H:%M:%S")
	echo -e "${currdate} ${PURPLE}[ * ] ${1}${NC}"
}

function print_success() {
	currdate=$(date +"%Y-%m-%d %H:%M:%S")
	echo -e "${currdate} ${GREEN}[ ✓ ] ${1}${NC}"
}

function print_error() {
	currdate=$(date +"%Y-%m-%d %H:%M:%S")
	echo -e "${currdate} ${RED}[ ✗ ] ${1}${NC}"
}

currdate=$(date +"%Y-%m-%d %H:%M:%S")
clear
echo -e "libnumerixpp build @ ${currdate}\n"

if [ "$1" == "help" ]; then
	echo "Usage: build.sh <doxygen/BUILD_SHARED_LIBS>"
	exit
elif [ "$1" == "doxygen" ]; then
	print_header "Generate docs with doxygem"
	print_step "Generating..."
	doxygen
	print_success "Docs generation complete."
fi

print_header "Cleaning up previous build"
if [ -d "$BUILD_DIR" ]; then
	print_step "Removing $BUILD_DIR directory..."
	rm -rf "$BUILD_DIR"
	print_success "Removed $BUILD_DIR directory."
else
	print_success "No previous build found."
fi

# Formatting code
print_header "Formatting code"
print_step "Format and cleaning code..."
./format-code.py
print_success "Code formatted."

# Create build directory
print_header "Creating build directory"
print_step "Creating $BUILD_DIR directory..."
mkdir -p "$BUILD_DIR"
print_success "Created $BUILD_DIR directory."

# Configure the project
print_header "Configuring the project"
print_step "Running CMake in $BUILD_DIR..."
cd "$BUILD_DIR"

if [ "$1" == "BUILD_SHARED_LIBS" ]; then
	cmake .. -DBUILD_SHARED_LIBS=ON -Dlibnumerixpp_DEVELOPER_MODE=ON
else
	cmake .. -Dlibnumerixpp_DEVELOPER_MODE=ON
fi

if [ $? -eq 0 ]; then
	print_success "CMake configuration completed successfully."
else
	print_error "CMake configuration failed."
	exit 1
fi

# Build the project
print_header "Building the project"
print_step "Building the project in $BUILD_DIR..."
make
if [ $? -eq 0 ]; then
	print_success "Project build completed successfully."
else
	print_error "Project build failed."
	exit 1
fi

# Install the project
print_header "Installing the project"
print_step "Installing the project..."
sudo make install
if [ $? -eq 0 ]; then
	print_success "Project installation completed successfully."
else
	print_error "Project installation failed."
	exit 1
fi

print_header "Build completed successfully"
echo -e "${CYAN}The ${PROJECT_NAME} library has been built and installed.${NC}"
echo "Build dir: build/"
```

Просто и со вкусом. Но некоторым может не понравиться данный os-specified способ, поэтому можно выполнить команду:

```bash
cmake --build build/ # -DBUILD_SHARED_LIBS=ON -Dlibnumerixpp_DEVELOPER_MODE=ON (параметры)
```

В итоге структура проекта такая:

```
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
│   └── en
│       └── index.md
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

Все разные директории cmake, test, новые .md файлы, разные файлы настроек утилит и CMake - все они сгенерированы cmake-init.

## Тестирование при помощи Catch2

Немного рассмотрим директорию test, которая содержит тесты, как я уже говорил:

```
test
├── CMakeLists.txt
└── source
    └── libnumerixpp_test.cpp
```

[Catch2](https://github.com/catchorg/Catch2) — это современный фреймворк модульного тестирования C++ с открытым исходным кодом. Он прост в использовании, выразителен и расширяем. Catch2 предоставляет простой и интуитивно понятный синтаксис для написания тестов, позволяя вам писать как читаемые, так и поддерживаемые тесты.

Catch2 упрощает написание автоматизированных тестов для кода C++, позволяя разработчикам убедиться, что их код работает правильно, и обнаружить ошибки и регрессии до того, как они попадут в производство. Фреймворк предоставляет ряд функций, включая мощный макрос утверждений, автоматическое обнаружение тестов, богатый вывод, гибкий интерфейс командной строки и поддержку написания параметризованных тестов.

Catch2 широко используется в сообществе C++ и рекомендуется многими разработчиками как надежный и эффективный фреймворк для тестирования.

Давайте рассмотрим пример использования Catch2.

Допустим у нас есть функция для получения факториала:

```cpp
unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}
```

Для того, чтобы протестировать эту функцию, дополним код:

```cpp
#include <catch2/catch_test_macros.hpp>

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(0) == 1 );
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}
```

При сборке появится ошибка:

```
Example.cpp:9: FAILED:
  REQUIRE( Factorial(0) == 1 )
with expansion:
  0 == 1
```

Теперь стоит исправить нашу функцию:

```cpp
unsigned int Factorial( unsigned int number ) {
	return number > 1 ? Factorial(number-1)*number : 1;
}
```

---

Полностью посмотреть возможности Catch2 можно по [ссылке](https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md). А мы переходим непосредственно к написанию кода.

# Тесты, тесты, тесты
Раз мы подключили тестирование, почему бы не использовать его? Ниже я покажу текущий файл тестов (test/source/libnumerixpp_test.cpp) с базовыми кейсами, и по ходу статьи мы будем добавлять туда больше функционала:

```cpp
#include "libnumerixpp/libnumerixpp.hpp"

#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <string>

#include "libnumerixpp/core/common.hpp"
#include "libnumerixpp/mathematics/core.hpp"
#include "libnumerixpp/mathematics/quadratic_equations.hpp"
#include "libnumerixpp/physics/core.hpp"
#include "libnumerixpp/physics/kinematics.hpp"

TEST_CASE("Check physics module", "[physics]") {
	double speed = 10.0;
	double time = 5.0;

	double path = physics::kinematics::calculatePath(speed, time);

	REQUIRE(path == 50.0);
	REQUIRE(physics::kinematics::calculateSpeed(path, time) == 10.0);
	REQUIRE(physics::kinematics::calculateSpeed(path, time) == speed);
	REQUIRE(physics::kinematics::calculateTime(path, speed) == time);
	REQUIRE(physics::kinematics::calculateFinalVelocity(10.0, 10.0, 10.0) == 110.0);
	REQUIRE(physics::kinematics::calculateFinalPosition(10.0, 10.0, 10.0, 10.0) == 610.0);
}

TEST_CASE("Check mathematics-quadratic", "[mathematics-quadratic]") {
	double num = 100.0;
	double a = -2;
	double b = 5;
	double c = 5;
	double d = mathematics::quadratic::calculateDiscriminant(a, b, c);
	double nump = mathematics::add_percent_to_number(100.0, 10.0);

	REQUIRE(mathematics::square_it_up(num) == 10000);
	REQUIRE(mathematics::get_square_root(num) == 10);
	REQUIRE(d == 65.0);
	REQUIRE(mathematics::quadratic::calculateRootsByDiscriminant(d, a, b) ==
			(std::vector<double>){ -0.76556443707463728, 3.26556443707463728 });
	REQUIRE(nump == 110.0);
	REQUIRE(mathematics::intabs(-10) == 10);
}
```

# Модуль информатики (или же Computer Science)
Я решил ввести новый модуль, под названием `computerscience`. Он включает в себя инструменты для разных вычислений, связанных с информатикой.

В директории src создадим поддиректорию computerscience, и в ней уже создадим файл core.cpp:

```bash
mkdir -p src/computerscience
touch src/computerscience/core.cpp
```

Теперь давайте реализуем базовые функции:

```cpp
/**
 * @file
 * @brief Core utils for computer science (informatics)
 * @authors alxvdev
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

namespace computerscience {
	std::string convertDecimalToBinary(int decimal) {
		std::string binary;

		if (decimal == 0)
			return "0";

		while (decimal > 0) {
			binary = std::to_string(decimal % 2) + binary;
			decimal /= 2;
		}

		return binary;
	}

	int convertBinaryToDecimal(std::string& binary) {
		int decimal = 0;

		for (char bit : binary) {
			decimal = decimal * 2 + (bit - '0');
		}

		return decimal;
	}

	std::string convertDecimalToHexadecimal(int decimal) {
		std::string hexadecimal;
		const char hexDigits[] = "0123456789ABCDEF";

		while (decimal > 0) {
			hexadecimal = hexDigits[decimal % 16] + hexadecimal;
			decimal /= 16;
		}

		return hexadecimal.empty() ? "0" : hexadecimal;
	}

	int convertHexadecimalToDecimal(std::string& hexadecimal) {
		int decimal = 0;

		for (char digit : hexadecimal) {
			decimal = decimal * 16 + (isdigit(digit) ? digit - '0' : toupper(digit) - 'A' + 10);
		}

		return decimal;
	}

	std::string convertBinaryToHexadecimal(std::string& binary) {
		std::string hexadecimal;
		const char hexDigits[] = "0123456789ABCDEF";

		if (binary.empty())
			return "0";

		int binaryLength = static_cast<int>(binary.length());

		while (binaryLength % 4 != 0) {
			binary = "0" + binary;
			binaryLength++;
		}

		for (int i = 0; i < binaryLength; i += 4) {
			int decimal = 0;

			for (int j = 0; j < 4; j++) {
				decimal = decimal * 2 + (binary[i + j] - '0');
			}

			hexadecimal += hexDigits[decimal];
		}

		return hexadecimal;
	}

	std::string convertHexadecimalToBinary(std::string hexadecimal) {
		std::string binary;
		std::string binaryDigit = "";

		if (hexadecimal.empty())
			return "0";

		for (char digit : hexadecimal) {
			int value = (isdigit(digit)) ? digit - '0' : toupper(digit) - 'A' + 10;
			binaryDigit = "";

			for (int i = 0; i < 4; i++) {
				binaryDigit = std::to_string(value % 2) + binaryDigit;
				value /= 2;
			}

			binary += binaryDigit;
		}

		while (!binary.empty() && binary[0] == '0') {
			binary.erase(0, 1);
		}

		return binary.empty() ? "0" : binary;
	}

	std::string humanizeBytesSize(long long bytes, const std::string& suffix = "B") {
		double factor = 1024.0;
		std::string units[] = {"", "K", "M", "G", "T", "P"};

		int i = 0;

		while (bytes >= factor) {
			bytes /= factor;
			i++;
		}

		std::stringstream ss;
		ss << std::fixed << std::setprecision(2) << static_cast<double>(bytes) << units[i] << suffix;
		return ss.str();
	}
}
```

Мы создаем пространство имен computerscience, в которое помещаем код функций. Разберем их подробнее:

```cpp
std::string convertDecimalToBinary(int decimal) {
	std::string binary;

	if (decimal == 0)
		return "0";

	while (decimal > 0) {
		binary = std::to_string(decimal % 2) + binary;
		decimal /= 2;
	}

	return binary;
}
```

Выше вы видите функцию конвертации числа из десятиричной системы исчисления в двоичную. Очень легкая функция, мы просто делим число на 2, остаток записываем, и так бесконечно, пока не дойдем до 1 или 0.

Остальные функции примерно одинаковы, кроме трех. Из них две функции конвертации мы рассмотрим прямо сейчас:

```cpp
std::string convertBinaryToHexadecimal(std::string& binary) {
	std::string hexadecimal;
	const char hexDigits[] = "0123456789ABCDEF";

	if (binary.empty())
		return "0";

	int binaryLength = static_cast<int>(binary.length());

	while (binaryLength % 4 != 0) {
		binary = "0" + binary;
		binaryLength++;
	}

	for (int i = 0; i < binaryLength; i += 4) {
		int decimal = 0;

		for (int j = 0; j < 4; j++) {
			decimal = decimal * 2 + (binary[i + j] - '0');
		}

		hexadecimal += hexDigits[decimal];
	}

	return hexadecimal;
}

std::string convertHexadecimalToBinary(std::string hexadecimal) {
	std::string binary;
	std::string binaryDigit = "";

	if (hexadecimal.empty())
		return "0";

	for (char digit : hexadecimal) {
		int value = (isdigit(digit)) ? digit - '0' : toupper(digit) - 'A' + 10;
		binaryDigit = "";

		for (int i = 0; i < 4; i++) {
			binaryDigit = std::to_string(value % 2) + binaryDigit;
			value /= 2;
		}

		binary += binaryDigit;
	}

	while (!binary.empty() && binary[0] == '0') {
		binary.erase(0, 1);
	}

	return binary.empty() ? "0" : binary;
}
```

Эти две функции нужны для конвертации hex в двоичный формат и наоборот. В первом мы сначала конвертируем в десятичную, и только потом в hex.

И последняя функция - конвертирование байтов в человекочитаемый размер:

```cpp
std::string humanizeBytesSize(long long bytes, const std::string& suffix = "B") {
	double factor = 1024.0;
	std::string units[] = {"", "K", "M", "G", "T", "P"};

	int i = 0;

	while (bytes >= factor) {
		bytes /= factor;
		i++;
	}

	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << static_cast<double>(bytes) << units[i] << suffix;
	return ss.str();
}
```

Вообще, эта функция это переписанный на C++ python-код ниже:

```python
def convert_to_human_size(bytes_size: int, suffix: str="iB") -> str:
	"""
	Вспомогательная функция конвертации байтов в человекочитаемый формат.

	:param bytes_size: размер байтов
	:type bytes_size: int
	:param suffix: суффикс наименования размера
	:type suffix: str
	
	:rtype: str
	:return: читаемый размер
	"""
	factor: int = 1024 												# Фактор деления

	for unit in ['', 'K', 'M', 'G', 'T', 'P']:
		if bytes_size < factor:
			return f"{bytes_size:.2f}{unit}{suffix}"
			
		bytes_size /= factor
```

Теперь создадим .hpp файл в директории include/libnumerixpp/computerscience:

```cpp
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
 * @brief      Basic Computer science utils
 * @include example-3.cpp
 */
namespace computerscience {

	/**
	 * @brief      convert decimal to binary
	 *
	 * @param[in]  decimal  The decimal
	 *
	 * @return     binary number string
	 */
	std::string convertDecimalToBinary(int decimal);

	/**
	 * @brief      convert binary to decimal
	 *
	 * @param      binary  The binary
	 *
	 * @return     decimal integer
	 */
	int convertBinaryToDecimal(std::string& binary);

	/**
	 * @brief      convert decimal to hexadecimal
	 *
	 * @param[in]  decimal  The decimal
	 *
	 * @return     hexadecimal number string
	 */
	std::string convertDecimalToHexadecimal(int decimal);

	/**
	 * @brief      convert hexadecimal to decimal
	 *
	 * @param      hexadecimal  The hexadecimal
	 *
	 * @return     decimal integer
	 */
	int convertHexadecimalToDecimal(std::string& hexadecimal);

	/**
	 * @brief      convert binary to hexadecimal
	 *
	 * @param      binary  The binary
	 *
	 * @return     hexadecimal number string
	 */
	std::string convertBinaryToHexadecimal(std::string& binary);

	/**
	 * @brief      convert hexadecimal to binary
	 *
	 * @param[in]  hexadecimal  The hexadecimal
	 *
	 * @return     binary number string
	 */
	std::string convertHexadecimalToBinary(std::string hexadecimal);

	/**
	 * @brief      Scale bytes to its proper format
	 *
	 * @param[in]  bytes   The bytes
	 * @param[in]  suffix  The suffix
	 *
	 * @return     humanized size
	 */
	std::string humanizeBytesSize(long long bytes, const std::string& suffix = "B");
}

#endif // LIBNUMERIXPP_COMPUTERSCIENCE_CORE_HPP
```

И вы могли заметить что упоминается файл example-3.cpp, который не упоминался в прошлой статье. Это третий файл примера использования:

```cpp
#include <iostream>
#include <vector>
#include "libnumerixpp/libnumerixpp.hpp"
#include "libnumerixpp/core/common.hpp"
#include "libnumerixpp/computerscience/core.hpp"

#include <string>

int main() {
	credits();
	println("LIBNUMERIXPP");

	int decimalNumber = 777;
	std::string binaryNumber = computerscience::convertDecimalToBinary(decimalNumber);
	int decimalNumber2 = computerscience::convertBinaryToDecimal(binaryNumber);
	std::string hexadecimalNumber = computerscience::convertDecimalToHexadecimal(decimalNumber);
	int decimalNumber3 = computerscience::convertHexadecimalToDecimal(hexadecimalNumber);
	std::string hexadecimalNumber2 = computerscience::convertBinaryToHexadecimal(binaryNumber);
	std::string binaryNumber2 = computerscience::convertHexadecimalToBinary(hexadecimalNumber);
	long long bytes = 1024 * 1024;

	std::cout << "Convert decimal " << decimalNumber << " to binary: " << binaryNumber << std::endl;
	std::cout << "Convert binary " << binaryNumber << " to decimal: " << decimalNumber2 << std::endl;
	std::cout << "Convert decimal " << decimalNumber << " to hexadecimal: " << hexadecimalNumber << std::endl;
	std::cout << "Convert hexadecimal " << hexadecimalNumber << " to decimal: " << decimalNumber3 << std::endl;
	std::cout << "Convert binary " << binaryNumber << " to hexadecimal: " << hexadecimalNumber2 << std::endl;
	std::cout << "Convert hexadecimal " << hexadecimalNumber << " to binary: " << binaryNumber2 << std::endl;
	std::cout << "Convert " << bytes << ": " << computerscience::humanizeBytesSize(bytes) << std::endl;

	return 0;
}
```

И напишем тесты:

```cpp
TEST_CASE("Check computerscience", "[computerscience]") {
	int decimalNumber = 777;
	std::string binaryNumber = computerscience::convertDecimalToBinary(decimalNumber);
	int decimalNumber2 = computerscience::convertBinaryToDecimal(binaryNumber);
	std::string hexadecimalNumber = computerscience::convertDecimalToHexadecimal(decimalNumber);
	int decimalNumber3 = computerscience::convertHexadecimalToDecimal(hexadecimalNumber);
	std::string hexadecimalNumber2 = computerscience::convertBinaryToHexadecimal(binaryNumber);
	std::string binaryNumber2 = computerscience::convertHexadecimalToBinary(hexadecimalNumber);
	long long bytes = 1024 * 1024;

	REQUIRE(binaryNumber == "001100001001");
	REQUIRE(decimalNumber2 == 777);
	REQUIRE(hexadecimalNumber == "309");
	REQUIRE(decimalNumber3 == 777);
	REQUIRE(hexadecimalNumber2 == "309");
	REQUIRE(binaryNumber2 == "1100001001");
	REQUIRE(computerscience::humanizeBytesSize(bytes) == "1.00MB");
}
```

# Модуль математики
Продолжим улучшать модуль математики.

Добавим небольшую функцию модуля числа без операции сравнения (в mathematics/core.cpp):

```cpp
int intabs(int x) {
	// mov %eax, %edx
	// sar $0x1f, %edx
	int minus_flag = x>>0x1F;

	// xor %edx, %eax
	int y = minus_flag ^ x;

	y -= minus_flag;

	return y;
}
```

На данный момент это единственный новый метод в mathematics/core. Сейчас мы рассмотрим новый файл - equations.cpp!

## Модуль уравнений
Большинство реализаций функций были взяты из книги Васильева А.Н. "Программирование на C++ в примерах и задачах".

В частности, в данном модуле будут следующие элементы:

 + решение алгебраических уравнений;
 + построение интерполяционных полиномов;
 + вычислении интегралов;
 + решении дифференциальных уравнений.

### Метод последовательных приближений
При решении уравнения (вида ниже) при некоторых дополнительных условиях может использовать метод последовательных приближений. Суть его сводится к тому, что задается начальное положение x0 для корня уравнения, после чего, используя итерационную процедуру, каждое следующее приближение вычисляется на основе предыдущего в соответствии с формулой Xn+1 = Ф(Xn).

![](https://habrastorage.org/webt/qa/yx/p8/qayxp81ueuekivdgtjqrxt_yr40.png)

В коде ниже демонстрируется функция для вычисления алгебраического уравнения x = 0.5 * cos(x), x = exp(-x) и x(x^2 + 6) / 5. Файл находится по пути src/mathematics/equations.cpp

```cpp
/**
 * @file
 * @brief Mathematics utils for equations
 * @authors alxvdev
 */
#include <cmath>

namespace mathematics::equations {
	double successiveApproximationsFindingRoot(double (*f_eq)(double), double x0, int n) {
		double x = x0;

		for (int i = 1; i <= n; i++) {
			x = f_eq(x);
		}

		return x;
	}

	double f_eq(double x) {
		return 0.5 * cos(x);
	}

	double g_eq(double x) {
		return exp(-x);
	}

	double h_eq(double x) {
		return (x * x + 6) / 5;
	}
}
```

Заголовочный файл include/mathematics/equations.cpp:

```cpp
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
	 * @brief      Function for solving equations by the method of successive
	 *             approximations.
	 *
	 * @details    When solving an equation (\f$x = \Phi(x)\f$), under some
	 *             additional conditions, the method of successive
	 *             approximations can be used. Its essence boils down to the
	 *             fact that the initial position x0 is specified for the root
	 *             of the equation, after which, using an iterative procedure,
	 *             each subsequent approximation is calculated based on the
	 *             previous one in accordance with the formula @f$x_{n + 1} =
	 *             \Phi(x_{n})\f$. Example equations: @f$x = 0,5 * \cos(x)\f$;
	 *             @f$x = \exp(-x)\f$; @f$x = (x^{2} + 6) / 5\f$.
	 *
	 * @param[in]  f  	 The f
	 * @param[in]  x0    The x 0
	 * @param[in]  n     n value
	 *
	 * @return     equation root
	 */
	double successiveApproximationsFindingRoot(double (*f_eq)(double), double x0, int n);

	/**
	 * @brief      Function f for determining the right side of solved equations
	 *
	 * @param[in]  x     x value
	 *
	 * @return     value
	 */
	double f_eq(double x);

	/**
	 * @brief      Function g for determining the right side of solved equations
	 *
	 * @param[in]  x     x value
	 *
	 * @return     value
	 */
	double g_eq(double x);

	/**
	 * @brief      Function h for determining the right side of solved equations
	 *
	 * @param[in]  x     x value
	 *
	 * @return     value
	 */
	double h_eq(double x);
}

#endif // LIBNUMERIXPP_MATHEMATICS_EQUATIONS_HPP
```

И создадим файл examples/example-4.cpp, где будет содержаться использование этой и других функций из ветки решения уравнений:

```cpp
#include <iostream>
#include <string>
#include "libnumerixpp/libnumerixpp.hpp"
#include "libnumerixpp/core/common.hpp"
#include "libnumerixpp/mathematics/core.hpp"
#include "libnumerixpp/mathematics/equations.hpp"

void test_eq_sa(double (*f_eq)(double), double x0, std::string eq) {
	int iterations = 100;

	double z;

	std::cout << "Equation solution " << eq << ":\t";

	z = mathematics::equations::successiveApproximationsFindingRoot(f_eq, x0, iterations);

	std::cout << z << std::endl;

	std::cout << "Check finding solution:\t";

	std::cout << z << " = " << f_eq(z) << std::endl;

	for (int i; i <= 50; i++) {
		std::cout << "-";
	}

	std::cout << std::endl;
}

int main() {
	credits();
	println("LIBNUMERIXPP");

	test_eq_sa(mathematics::equations::f_eq, 0, "x=0.5cos(x)");
	test_eq_sa(mathematics::equations::g_eq, 0, "x=exp(-x)");
	test_eq_sa(mathematics::equations::h_eq, 1, "x=(x*x+6)/5");

	return 0;
}
```

При сборке (через скрипт build.sh, который мы создали в прошлой части) и запуске example-4 вы увидите следующий вывод:

```
libnumerixpp v0.1.1 - A powerful C++ Library for High-Performance Numerical Computing
Licensed by Apache License
Developed&maintained by @alxvdev

LIBNUMERIXPP
Equation solution x=0.5cos(x):	0.450184
Check finding solution:	0.450184 = 0.450184

Equation solution x=exp(-x):	0.567143
Check finding solution:	0.567143 = 0.567143

Equation solution x=(x*x+6)/5:	2
Check finding solution:	2 = 2
```

И также напишем тесты:

```cpp
TEST_CASE("Check mathematics-equations", "[mathematics-equations]") {
	double z_f = mathematics::equations::successiveApproximationsFindingRoot(
		mathematics::equations::f_eq, 0.0, 100);
	double z_g = mathematics::equations::successiveApproximationsFindingRoot(
		mathematics::equations::g_eq, 0.0, 100);
	double z_h = mathematics::equations::successiveApproximationsFindingRoot(
		mathematics::equations::h_eq, 1.0, 100);

	REQUIRE(z_f == mathematics::equations::f_eq(z_f));
	REQUIRE(z_g == mathematics::equations::g_eq(z_g));
	REQUIRE(z_h == mathematics::equations::h_eq(z_h));
}
```

## Метод половинного деления
Метод половинного деления для писка решения алгебраического уравнения вида f(x) = 0 подразумевает, что искомый корень локализован в интервале a <= x <= b, причем на границах интервала поиска корня функция f(x) должна принимать значения разных знаков (что может быть записано в виде условия f(a)f(b) < 0).

Суть метода состоит в таких действиях. Вычисляется значение функции f(x) в центральной точке интервала поиска решения, которая определяется как x = (a + b) / 2. Интерес представляет знак функции в этой точке: в нее сдвигается одна из границ интервала поиска корня. А именно: если в центральной точке интервала значение функции положительно, то в центр смещается та граница, где функция положительна. Если же отрицательна, то сдвигается та граница, где функция отрицательна. В результате после каждой такой операции интервал поиска корня уравнения уменьшается ровно в два раза, и при этом функция f(x) на границах нового интервала поиска корня принимает значения разных знаков.

```cpp
double halfDivisionFindingRoot(double (*f_hd_eq)(double), double a, double b, double dx) {
	double x = (a + b) / 2;

	while ((b - a) / 2 > dx) {
		if (f_hd_eq(a) == 0) return a;

		if (f_hd_eq(b) == 0) return b;

		if (f_hd_eq(x) == 0) return x;

		if (f_hd_eq(a) * f_hd_eq(x) > 0) {
			a = x;
		} else {
			b = x;
		}

		x = (a + b) / 2;
	}

	return x;
}

double f_hd_eq(double x) { return 0.5 * cos(x) - x; }

double g_hd_eq(double x) { return exp(-x) - x; }

double h_hg_eq(double x) { return x * x - 5 * x + 6; }

double f_eq(double x) { return 0.5 * cos(x); }
```

---

Переходим к новому подмодулю - statistics: mathematics/statistics.cpp.

## Модуль вероятности и статистики
Данный модуль отвечает за высчитывание вещей, которые являются частью блока вероятности и статистики в математике.

Не буду долго томить, все основные функции указаны ниже:

```cpp
/**
 * @file
 * @brief Mathematics utils for statistics
 * @authors alxvdev
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

namespace mathematics::statistics {
double getAverage(double numbers[], int length) {
	double sum = 0;

	for (int i = 0; i < length; i++) sum += numbers[i];

	return (double)(sum) / length;
}

size_t factorial(size_t n) {
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

size_t combinations(size_t n, size_t k) { return factorial(n) / (factorial(k) * factorial(n - k)); }

double median(std::vector<double> data) {
	std::sort(data.begin(), data.end());
	const size_t size = data.size();
	if (size % 2 == 0) {
		return (data[size / 2 - 1] + data[size / 2]) / 2.0;
	} else {
		return data[size / 2];
	}
}

double probability(size_t favorable_outcomes, size_t total_outcomes) {
	return static_cast<double>(favorable_outcomes) / total_outcomes;
}

double conditional_probability(size_t a_and_b, size_t b) {
	return static_cast<double>(a_and_b) / b;
}
}  // namespace mathematics::statistics
```

И соответственно файл заголовка:

```cpp
/**
 * @file
 * @brief Mathematics utils for statistics
 * @authors alxvdev
 */

#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

/**
 * @brief Statistics namespace
*/
namespace mathematics::statistics {

	/**
	 * @brief      Gets the average.
	 *
	 * @param      numbers  The numbers
	 * @param[in]  length   The length
	 *
	 * @return     The average.
	 */
	double getAverage(double numbers[], int length);

	/**
	 * @brief      calculate factorial
	 *
	 * @param[in]  n     number
	 *
	 * @return     factorial
	 */
	size_t factorial(size_t n);

	/**
	 * @brief      get combinations
	 *
	 * @param[in]  n     n value
	 * @param[in]  k     k value
	 *
	 * @return     { description_of_the_return_value }
	 */
	size_t combinations(size_t n, size_t k);

	/**
	 * @brief      variance
	 *
	 * @param[in]  data  The data
	 *
	 * @return     value
	 */
	double variance(const std::vector<double>& data);

	/**
	 * @brief      probability
	 *
	 * @param[in]  favorable_outcomes  The favorable outcomes
	 * @param[in]  total_outcomes      The total outcomes
	 *
	 * @return     result
	 */
	double probability(size_t favorable_outcomes, size_t total_outcomes);

	/**
	 * @brief      conditional probability
	 *
	 * @param[in]  a_and_b  A and b
	 * @param[in]  b        b value
	 *
	 * @return     value
	 */
	double conditional_probability(size_t a_and_b, size_t b);
}
```

---

```
            ;e`               Alexeev Bronislav ~ git version 2.46.2
           ;QD?`              --------------------------------------
          ;B#R1r`             Project: libnumerixpp (1 branch)
         ;WRMKS|r`            HEAD: 7d74fd5 (main, origin/main)
        :O9KOKS\\*`           Created: 2 weeks ago
       :keXPk6Zc7v|`          Languages:
      :ajyoaZemJJ{]\`                    ● CMake (41.9 %) ● C++ (40.7 %)
     :]z1x}f9@@yujSoc`                   ● Shell (10.9 %) ● Python (6.4 %)
    "7\/LvUQ@@@XoZemXv`       Authors: 80% Alexeev Bronislav 33
   ,\**vooqMBBBkmXEkU9z`               20% Alexeev Bronislav 8
  ,\*}Sx\||?|cFfokqOdHDx`     Last change: 19 seconds ago
 ,L]jc\\\||?*>rr^^|zo$MN]`    URL: git@github.com:alxvdev/libnumerixpp.git
-v7????*>>rrr^^^;;;;;;^\F^`   Commits: 41
                              Churn (1): …/ru/article2.md 1
                                         .clangd 1
                                         cmake/install-rules.cmake 1
                              Lines of code: 1226
                              Size: 492.2 KiB (82 files)
                              License: Apache-2.0
```

# Заключение
Библиотека улучшается. Не стоит думать что это пустое времяпровождение. Кто знает, вдруг вы начнете развивать свою библиотеку, и сотни программистов (и не только программистов) скажут вам спасибо? Верьте в себя, боритесь за себя.

Если у вас есть замечания по статье или по коду - пишите, наверняка есть более опытный и профессиональный программист на C++, который может помочь как и читателям статьи, так и мне. Мы живем ради того чтобы развивать себя и мир, не так-ли?

Буду рад, если вы присоединитесь к моему небольшому [телеграм-блогу](https://t.me/hex_warehouse). Анонсы статей, новости из мира IT и полезные материалы для изучения программирования и смежных областей.

Репозиторий с исходным кодом доступен по [этой ссылке](https://github.com/alxvdev/libnumerixpp).

Первая часть доступна по [ссылке](https://habr.com/ru/companies/timeweb/articles/845074/).

## Источники

 + Васильев А.Н. "Программирование на C++ в задачах и примерах"
 + [Поиск ошибок работы с памятью в C/C++ при помощи Valgrind](https://eax.me/valgrind)
 + [Тонкости анализа C++ при помощи cppcheck](https://habr.com/ru/articles/210256/)
 + [Руководство по CMake для разработчиков библиотек](https://habr.com/ru/articles/683204)
