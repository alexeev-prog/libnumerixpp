# Создаем свою простую (C++) библиотеку с документацией, CMake и блекджеком
В мире программирования создание собственных библиотек - это не просто возможность пополнения своего портфолио или способ структурировать код, а настоящий акт творческого самовыражения (и иногда велосипедостроения). Каждый разработчик иногда использовал в нескольких своих проектах однообразный код, который приходилось каждый раз перемещать. Да и хотя-бы как упаковать свои идеи и знания в удобный и доступный формат, которым можно будет поделиться с сообществом.

Если вы ловили себя на мысли: "А почему мне бы не создать свою полноценную библиотеку?", то я рекомендую прочитать вам мою статью.

Эту статью вы можете использовать как шпаргалку для создания проектов, и не только библиотек.

Некоторые из вас могут подумать что мы изобретаем велосипед. А я в ответ скажу - сможете ли вы прямо сейчас, без подсказок, только по памяти, нарисовать велосипед без ошибок?

---

Сразу говорю - я не профессионал в C++, и вы всегда можете поправить меня в комментариях. Благодарю!

Язык программирования С++ представляет высокоуровневый компилируемый язык программирования общего назначения со статической типизацией, который подходит для создания самых различных приложений. На сегодняшний день С++ является одним из самых популярных и распространенных языков.

Своими корнями он уходит в язык Си, который был разработан в 1969—1973 годах в компании Bell Labs программистом Деннисом Ритчи (Dennis Ritchie). В начале 1980-х годов датский программист Бьерн Страуструп (Bjarne Stroustrup), который в то время работал в компании Bell Labs, разработал С++ как расширение к языку Си. Фактически вначале C++ просто дополнял язык Си некоторыми возможностями объектно-ориентированного программирования. И поэтому сам Страуструп вначале называл его как "C with classes" ("Си с классами"). Но называть его так - значит упускать много конструкций из виду. Помимо ООП, есть пространства имен, шаблоны, огромная стандартная библиотека и так далее. В принципе, я думаю, не надо углубляться в историю языка. Но стоит знать, что с 1998 до 2011 года C++ развивался довольно медленно, но в 2011 вышел стандарт C++11, в котором было реализовано множество нового функционала.

С++ повсюду. Код, написанный на C++, можно найти в вашем телефоне, в вашей стиральной машине, в вашем автомобиле, в самолетах, в банках и вообще везде, где только можно представить.

Одной из важнейших особенностей C++ является предсказуемое управление памятью. Тут нет сборки мусора, которая в конечном итоге происходит (или нет). Когда и как память будет освобождена и возвращена операционной системе - абсолютно детерминировано. Хотя все всегда было абсолютно детерминировано, было также довольно легко выстрелить себе в ногу и испортить все, не высвобождая память или наоборот пытаясь высвободить ее дважды или даже больше раз...

А также C++ невероятно экономичен и быстрый. Посмотрите на довольный известный график снизу:

![](https://habrastorage.org/r/w1560/getpro/habr/upload_files/696/78f/beb/69678fbebbe390a2ebd304a6b8327108.png)

Ну а теперь к минусам. Один из главных минусов, который влияет на популярность C++ - плохая реклама. Многие люди настроены негативно по отношению к C++, из-за его сложности. Сколько раз вы слышали "с C легко выстрелить себе в ногу. В C++ это сложнее, но зато вы отстреливаете всю ногу сразу"?

Также довольно большим минусом является отсутствие экосистемы стандартизированных инструментов. Например, доставка и использование библиотек. В JavaScript для этого используется npm, в Python pip, в Haskell есть stack и cabal. То есть у этих языков есть экосистема, которая позволяет без сложностей использовать и публиковать пакеты, и в принципе работать с языком. А у C++ нет таких инструментов-стандартов. Есть конечно Conan, vcpkg, но они мало развиты, и разобщены.

Тем не менее, язык и экосистема растут, сообщество очень большое, а C++ неизбежно повсеместен. Так или иначе, его хотя бы частично можно найти почти в каждом написанном на сегодня программном обеспечении. Я не говорю, что C++ — это молоток, который должен превратить все вокруг вас в гвозди, но его все же стоит изучить и освоить.

Прошу не начинать холивары в комментариях насчет C++, эта статья туториал, а не обзор.

# Особенности C++
Теперь можно перейти к тому, что делает этот язык уникальным. Какие специфические особенности отличают C++ от C и других языков, и как они влияют на процесс разработки.

## Пространства имен
Начнем с относительно легкой вещи - а именно пространства имен. Я не буду сильно углубляться в темы, просто расскажу минимальную информацию. Мы же все таки айтишники, а не сосиски в тесте.

Пространство имен позволяет сгруппировать функционал в отдельные контейнеры. Пространство имен представляет блок кода, который содержит набор компонентов (функций, классов и т.д.) и имеет некоторое имя, которое прикрепляется к каждому компоненту из этого пространства имен. Полное имя каждого компонента — это имя пространства имен, за которым следует оператор :: (оператор области видимости или scope operator) и имя компонента. Примером может служить оператор cout, который предназначен для вывода строки на консоль и который определен в пространстве имен std. Соответственно чтобы обратиться к этому оператору, применяется выражение std::cout.

```cpp
#include <iostream>

int main() {
	std::cout << "Hello, Habr!" << std::endl;

	return 0;
}
```

Но также можно создавать и свои пространства:

```cpp
#include <iostream>
 
namespace hello {
    const std::string message{"hello work"};
    void print(const std::string& text) {
        std::cout << text << std::endl;
    }
}
 
int main() {
    hello::print(hello::message);   // hello work
}
```

Директива using позволяет ссылаться на любой компонент пространства имен без использования его имени:

```cpp
#include <iostream>
 
namespace console
{
    const std::string message{"hello"};
    void print(const std::string& text)
    {
        std::cout << text << std::endl;
    }
}
 
using namespace console;    // подключаем все компоненты пространства console
 
int main()
{
    print(message); // указывать пространство имен не требуется
}
```

А также можно делать псевдонимы:

```cpp
namespace fs = boost::filesystem;
// fs::path ...
```

## ООП
Объектно-ориентированное программирование - очень обширная область. Имеет множество псевдоформальных формулировок написанными людьми разной степени эксперности. Множество принципов, паттернов делают ООП сложным для понимания новичкам.

У нас статья не об ООП, так что сильно углубляться не будем. Вот пример класса:

```cpp
class User {
private:
    int userid;
    std::string password;
    double cash;
public:
    void top_up_account(double sum) {
        cash += sum;
    }

    double withdraw_funds(double sum) {
        if (cash < sum)
            return 0;

        cash -= sum;

        return cash;
    }
}
```

## Перегрузка функций
C++ позволяет определять функции с одним и тем же именем, но разным набором параметров. Подобная возможность и называется function overloading. Компилятор уже сам выбирает нужный тип функции.

При этом различные версии функции могут также отличаться по возвращаемому типу. Однако компилятор при выборе ориентируется именно на кол-во параметров и их тип.

Простейший пример:

```cpp
#include <iostream>

int max(int, int);
double max(double, double, double);

int main() {
    int result1 = {max(1, 3)};
    double result2 = {max(3.0000001, 3.000001)};

    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;

    return 0;
}

int max(int a, int b) {
    return (a >= b ? a : b);
}

double sum(double a, double b) {
    return (a >= b ? a : b);
}
```

Функции могут отличаться и количеством аргументом, и их типом и так далее.

Но стоит учитывать что функция с параметрами-ссылками и обычными параметрами считаются одинаковыми. Но если в одной функции параметр является константой и ссылкой/указателем, то эти функции уже будут различаться компилятором.

## Шаблоны
Концепция шаблонов возникла из известного принципа программирования DRY (Dont't repeat yourself, не повторяйся). Шаблоны позволяют определить конструкции, которые используют определенные типы, но на момент написания кода точно не известно, что это будут за типы. То есть, шаблоны позволяют определить универсальные конструкции, которые не зависят от конкретных типов.

Полностью шаблоны расписывать не буду, а порекомендую прочитать [эту статью](https://habr.com/ru/articles/599801/). В ней наиболее полно рассказывается о всех возможностях шаблонов.

## Количество аргументов
C++ имеет следующий вид функции с принятием аргументов:

```cpp
int example_function() {} // функция не принимает аргументов
int example_function(void) {} // функция тоже не принимает аргументов. Это создано для обратной совместимости с C, т.к. в C код `int example_function() {}` означает что она принимает сколько угодно значений, поэтому для пустых функций принято было использовать void
int example_function(...) {} // сколько угодно аргументов
```

# Создаем репозиторий
Каждая уважающая себя библиотека должна иметь три вещи:

1. Репозиторий
2. Документацию
3. Относительно понятный код

Не буду расписывать создание репозитория, и почему нужно использовать git-репозиторий, думаю вы это знаете. Моя цель показать примерную структуру проекта.

Один из самых важных файлов - `.gitignore`. Этот файл содержит в себе список директорий и файлов, которые следует игнорировать. Вот мой .gitignore из [моего репозитория](https://github.com/alxvdev/libnumerixpp):

```bash
# Prerequisites
*.d

# Compiled Object files
*.slo
*.lo
*.o
*.obj

# Precompiled Headers
*.gch
*.pch

# Compiled Dynamic libraries
*.so
*.dylib
*.dll

# Fortran module files
*.mod
*.smod

# Compiled Static libraries
*.lai
*.la
*.a
*.lib

# Executables
*.exe
*.out
*.app

# Cmake build
build/
```

А также нам нужно будет создать файл .github/workflows/static.yml, но это будет позже, когда мы будем создавать документацию.

Сама структура проекта такова:

```
├── build.sh
├── CHANGELOG.md
├── CMakeLists.txt
├── docs
│   ├── doxygen-styles.css
│   ├── en
│   │   └── index.md
│   └── ru
│       ├── article.md
│       └── index.md
├── Doxyfile
├── examples
│   ├── example-1.cpp
│   └── example-2.cpp
├── include
│   └── libnumerixpp
│       ├── core
│       │   └── common.hpp
│       ├── libnumerixpp.hpp
│       ├── mathematics
│       │   ├── core.hpp
│       │   └── quadratic_equations.hpp
│       └── physics
│           ├── core.hpp
│           └── kinematics.hpp
├── LICENSE
├── README.md
└── src
    ├── core
    │   └── common.cpp
    ├── libnumerixpp.cpp
    ├── mathematics
    │   ├── core.cpp
    │   └── quadratic_equations.cpp
    └── physics
        ├── core.cpp
        └── kinematics.cpp
```

Рассмотрим ее:

 + build.sh - простой баш-скрипт для сборки проекта
 + CMakeLists.txt - файл сборки CMake
 + docs - директория с документацией. doxygen-styles.css это кастомные css-стили для doxygen, а директории en и ru нужны для разных переводов.
 + Doxyfile - файл конфигурации Doxygen
 + examples - директория с примерами работы библиотеки
 + include - директория с заголовочными файлами библиотеки
 + src - директория с исходным кодом: core - базовый функционал, mathematics - математика, physics - физика.

# Система сборки CMake

![](https://habrastorage.org/r/w1560/getpro/habr/post_images/629/110/019/6291100193702d4032d7e69ecc4f04f4.png)

CMake — кроcсплатформенная утилита для автоматической сборки программы из исходного кода. При этом сама CMake непосредственно сборкой не занимается, а представляет из себя front-end. В качестве back-end'a могут выступать различные версии make и Ninja. Так же CMake позволяет создавать проекты для CodeBlocks, Eclipse, KDevelop3, MS VC++ и Xcode.

Для того что бы собрать проект средствами CMake, необходимо в корне дерева исходников разместить файл CMakeLists.txt, хранящий правила и цели сборки, и произвести несколько простых шагов.

Больше о CMake вы можете прочитать в [этой статье](https://habr.com/ru/articles/155467/).

Инструкция по сборке cmake хранится в файле CMakeLists.txt:

```bash
cmake_minimum_required(VERSION 3.10)

project(libnumerixpp VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (EXECUTABLE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

file(GLOB_RECURSE EXAMPLE_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp)

add_library(libnumerixpp SHARED ${SOURCE_FILES})

set_target_properties(libnumerixpp PROPERTIES OUTPUT_NAME "numerixpp")

target_include_directories(libnumerixpp 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

foreach(EXAMPLE_SOURCE_FILE ${EXAMPLE_SOURCE_FILES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE_FILE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE_FILE})
    target_link_libraries(${EXAMPLE_NAME} PRIVATE libnumerixpp)
endforeach()

install(TARGETS libnumerixpp
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/
    DESTINATION include
)
```

Код выше - это и есть файл сборки CMake моего проекта. Рассмотрим его:

1. `cmake_minimum_required` - минимальная версия CMake
2. `project(libnumerixpp VERSION 0.1.0)` - название и версия проекта
3. `set(CMAKE_CXX_STANDARD 17)` - устанавливаем стандарт C++17
4. `set(CMAKE_CXX_STANDARD_REQUIRED ON)` - требуем чтобы компилятор поддерживал выбранный стандарт C++
5. `set (EXECUTABLE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)` - устанавливаем каталог вывода для исполняемых файлов
6. `set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)` - устанавливаем каталог вывода для библиотек
7. `file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)` - находим все C++ файлы в директории src
8. `file(GLOB_RECURSE EXAMPLE_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp)` - находит все C++ файлы в директории examples
9. `add_library(libnumerixpp SHARED ${SOURCE_FILES})` - создаем динамическую библиотеку с именем libnumerixpp
10. `set_target_properties(libnumerixpp PROPERTIES OUTPUT_NAME "numerixpp")` - задаем имя выходного файла на numerixpp (CMake автоматически прибавит префикс lib к названию файла библиотеки)
11. `target_include_directories(...)` - добавляем каталог include в качестве общедоступного каталога.
12. `foreach(EXAMPLE_SOURCE_FILE ${EXAMPLE_SOURCE_FILES}) ... endforeach()` - перебираем все исходные файлы из директории examples и подключаем к ним библиотеку
13. `install(...)` - установка библиотеки в систему
14. `install(DIRECTORY include/` - настраиваем установку заголовочных файлов библиотеки

Итак, для сборки надо использовать команду:

```bash
cd build
cmake ..
make
sudo make install
```

Но для облегчения этой задачи напишем простой bash-скрипт:

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

if [ "$1" == "clean" ]; then
    # Clean up previous build
    print_header "Cleaning up previous build"
    if [ -d "$BUILD_DIR" ]; then
        print_step "Removing $BUILD_DIR directory..."
        rm -rf "$BUILD_DIR"
        print_success "Removed $BUILD_DIR directory."
    else
        print_success "No previous build found."
    fi
fi

# Create build directory
print_header "Creating build directory"
print_step "Creating $BUILD_DIR directory..."
mkdir -p "$BUILD_DIR"
print_success "Created $BUILD_DIR directory."

# Configure the project
print_header "Configuring the project"
print_step "Running CMake in $BUILD_DIR..."
cd "$BUILD_DIR"
cmake ..
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

Не волнуйтесь, весь код мы напишем позже.

# Создание документации при помощи Doxygen
В этом разделе я расскажу о системе документирования исходных текстов Doxygen, которая на сегодняшний день, по имеющему основания заявлению разработчиков, стала фактически стандартом для документирования программного обеспечения, написанного на языке C++, а также получила пусть и менее широкое распространение и среди ряда других языков.

Устанавливается Doxygen просто:

```bash
sudo pacman -S doxygen # Arch
sudo apt install doxygen # Ubuntu/Debian
```

Суть автоматизированного софта для генерации документации такая: на вход подаются файлы исходного кода, комментированные особым образом, а на выходе мы получаем структуированный формат документации.

Рассматриваемая система Doxygen как раз и выполняет эту задачу: она позволяет генерировать на основе исходного кода, содержащего комментарии специального вида, красивую и удобную документацию, содержащую в себе ссылки, диаграммы классов, вызовов и т.п. в различных форматах: HTML, LaTeX, CHM, RTF, PostScript, PDF, man-страницы.

В большинстве случаев Doxygen используется для документации программного обеспечения, написанного на языке C++, однако на самом деле данная система поддерживает гораздо большое число других языков: C, Objective-C, C#, PHP, Java, Python, IDL, Fortran, VHDL, Tcl, и частично D.

Итак, сначала нам нужно будет перейти в рабочую директорию и создать Doxyfile - файл конфигурации:

```bash
doxygen -g
```

В Doxyfile содержится краткое описание проекта, его версия и подобные вещи. Некоторые значения желательно сразу изменить.

Вот основные значения:

```bash
PROJECT_NAME           = "Project Name"             # Имя проекта
PROJECT_NUMBER         = 0.1.0                      # Версия проекта
PROJECT_BRIEF          = "Yet another project"      # Краткое описание проекта
OUTPUT_DIRECTORY       = docs                       # Куда складывать сгенерированную документацию
OUTPUT_LANGUAGE        = English                    # Язык документации
GENERATE_LATEX         = YES                        # Генерация LaTeX
INPUT                  = src include                # Директории, где искать файлы
RECURSIVE              = YES                        # Рекурсивный обход директорий
USE_MATHJAX            = YES                        # Использование mathjax (для latex в html)
```

 + PROJECT_NAME - название проекта.
 + PROJECT_NUMBER - версия проекта. Я придерживаюсь схемы "major.minor.patch".
 + PROJECT_BRIEF - краткое описание проекта.
 + OUTPUT_DIRECTORY - директория, куда будет записываться созданная документация.
 + OUTPUT_LANGUAGE - язык документации (доступные значения: Afrikaans, Arabic, Armenian, Brazilian, Bulgarian, Catalan, Chinese, Chinese-Traditional, Croatian, Czech, Danish, Dutch, English (United States), Esperanto, Farsi (Persian), Finnish, French, German, Greek, Hindi, Hungarian, Indonesian, Italian, Japanese, Japanese-en (Japanese with English messages), Korean, Korean-en (Korean with English messages), Latvian, Lithuanian, Macedonian, Norwegian, Persian (Farsi), Polish, Portuguese, Romanian, Russian, Serbian, Serbian-Cyrillic, Slovak, Slovene, Spanish, Swedish, Turkish, Ukrainian and Vietnamese).
 + GENERATE_LATEX - позволяет генерировать LaTeX.
 + INPUT - директории, откуда будет браться исходный код. Разделяются пробелами.
 + RECURSIVE - рекурсивный обход директорий.
 + USE_MATHJAX - для использования latex-формул в html.

Больше настроек вы можете посмотреть в [этой статье](https://habr.com/ru/articles/252443/).

## Кастомизация
Дефолтный стиль, мягко говоря, некрасивый. Поэтому мы будем использовать кастомную css-тему:

```bash
HTML_STYLESHEET        = ./docs/doxygen-styles.css # путь до css стилей
```

Данный файл стилей вы можете скачать [отсюда](https://raw.githubusercontent.com/jothepro/doxygen-awesome-css/refs/heads/main/doxygen-awesome.css).

Посмотреть, что получилось у меня, вы можете по [ссылке](https://alxvdev.github.io/libnumerixpp). А мой Doxyfile [здесь](https://github.com/alxvdev/libnumerixpp/blob/main/Doxyfile).

## Форма написания комментариев
Документация кода в Doxygen осуществляется при помощи документирующего блока. При этом существует два подхода к его размещению. Он может быть размещен перед или после объявления или определения класса, члена класса, функции, пространства имён и т.д.

Для того, чтобы doxygen правильно создал документацию, стоит следовать стилистике написания комментариев. Рассмотрим пример:

```cpp
/**
 * @brief      Calculates the roots by discriminant.
 *
 * @details    Calculate the roots by discriminant \f$\frac{-b +-
 *             \sqrt{D}}{2a}\f$. D > 0 = 2 roots, D == 0 = 1 root, D < 0 = 0
 *             roots.
 *             
 * @todo Example Todo
 * @warning This is a test
 * @see Ref
 *
 * @param[in]  discriminant  The discriminant
 * @param[in]  a             a
 * @param[in]  b             b
 *
 * @return     The roots by discriminant.
 */
std::vector<double> calculateRootsByDiscriminant(double discriminant, double a, double b);
```

 + @brief - краткое описание
 + @details - детали, подробное описание
 + @todo - что-то нужно доделать. Doxygen генерирует отдельную страницу со списком всех @todo
 + @warning - предупреждение
 + @ref - ссылка на связанный класс или метод
 + @param - передаваемый параметр, имеет направление ([in], [out], [in,out])
 + @return - возвращаемое значение

Также мы используем latex-формулу: чтобы обозначить ее, надо в начале и в конце вставить `\f$`. Для создания latex-формул можно использовать [онлайн редактор latex](https://latexeditor.lagrida.com/).

Также существуют следующие метки:

 + @authors - автор/ы
 + @version - версия
 + @date - дата
 + @bug - известные ошибки
 + @copyright - лицензия
 + @example - файл примера работы
 + @throws - исключение во время работы
 + @mainpage Title — комментарий содержит текст для титульного листа документации
 + @file fname — описание конкретного файла
 + @deprecated — помечает класс или метод устаревшим. Как и с @todo, Doxygen генерирует отдельную страницу со списком всех устаревших классов и методов

В действительности, Doxygen поддерживает куда больше команд. Например, он позволяет писать многостраничную (@page) документацию с разделами (@section) и подразделами (@subsection), указывать версии методов и классов (@version), и не только.

Больше можно прочитать [здесь](https://habr.com/ru/articles/252101/).

## Деплой документации на github-pages
Для начала создадим репозиторий на GitHub. Откройте главную вкладку репозитория.

![](https://habrastorage.org/r/w1560/getpro/habr/upload_files/361/57b/b30/36157bb305d2cc9b52f0415fcc879917.png)

Перейдите на вкладку Settings и откройте раздел Pages:

![](https://habrastorage.org/r/w1560/getpro/habr/upload_files/8ea/a5d/fd3/8eaa5dfd38f145a20fffe1dfb9d2dc8b.png)

В этом разделе выберете Static HTML и нажмите кнопку Configure.

![](https://habrastorage.org/r/w1560/getpro/habr/upload_files/f8e/24b/40d/f8e24b40d0d63c69c3ab7b0aea39b16d.png)

Откроется файл конфигурации задачи для CI/CD пайплайна. Все настройки хранятся в static.yaml файле. С помощью пайплайна можно вызывать системные команды. Вызов всех команд описывается с помощью шагов. Описание шагов начинается после строки steps. Путь к этой строке: jobs -> deploy -> steps.

Первые два шага по умолчанию выглядят так:

![](https://habrastorage.org/r/w1560/getpro/habr/upload_files/e27/cc2/ec7/e27cc2ec74ba9151ee5a074a427a4c94.png)

При обновлении GitHub Pages может что-то поменяться, но я не думаю, что будет сложно понять, где надо писать свои шаги.

Теперь требуется добавить шаги с установкой Doxygen. В качестве системы используется Ubuntu, а значит пакеты устанавливаются через apt.

```yml
# Install Doxygen
- name: Install Doxygen
  run: sudo apt install doxygen && doxygen --version
# Create documentation   
- name: Create documentation     
  run: doxygen
```

Документация создается, но надо ее развернуть. Для этого необходимо указать путь к папке с index.html в шаге Upload artifact. Путь к главной странице сайта: ./html/index.html. Тогда этот шаг будет выглядеть так:

![](https://habrastorage.org/r/w1560/getpro/habr/upload_files/c7e/5b5/8e4/c7e5b58e4b99d12b4eda29bc68839e71.png)

Я же указал в конфигурации Doxyfile, что документация сохраняется в docs, поэтому я указываю путь ./docs/html/index.html.

На этом настройка закончена. Ссылка на документацию находится в раздел Settings -> Pages. То есть `<username>.github.io/<reponame>`.

 > P.S. инструкция взята с [этой статье](https://habr.com/ru/articles/799051/)

...

# Пишем код
Итак, у вас должна быть следующая структура:

```
.
├── include
│   └── libnumerixpp
│       ├── core
│       │   └── common.hpp
│       ├── libnumerixpp.hpp
│       ├── mathematics
│       │   ├── core.hpp
│       │   └── quadratic_equations.hpp
│       └── physics
│           ├── core.hpp
│           └── kinematics.hpp
└── src
    ├── core
    │   └── common.cpp
    ├── libnumerixpp.cpp
    ├── mathematics
    │   ├── core.cpp
    │   └── quadratic_equations.cpp
    └── physics
        ├── core.cpp
        └── kinematics.cpp
```

Я буду писать библиотеку для вычислений по физике и математике (называться она будет libnumerixpp). Исходный код будет храниться в [моем репозитории](https://github.com/alxvdev/libnumerixpp)

Модульная и расширяемая структура позволит в последствии добавлять больше функционала. В директории include существует поддиректория libnumerixpp, именно там и хранятся основные заголовочные файлы.

Начнем с примера - файл libnumerixpp.cpp:

```cpp
/**
 * @file
 * @brief A Powerful C++ Library for High-Performance Numerical Computing
 * @version 0.1.0
 * @date 2024-09-21
 * @authors alxvdev
 * @copyright Apache 2.0 License
 */
#include <iostream>

void println(std::string string) {
    std::cout << string << std::endl;
}
```

И его заголовочного файла libnumerixpp.hpp:

```cpp
#ifndef LIBNUMERIXPP_HPP
#define LIBNUMERIXPP_HPP

#include <string>

#pragma once

/**
 * @brief      Print string with new line
 *
 * @param[in]  string  The string
 */
void println(std::string string);

#endif // LIBNUMERIXPP_HPP
```

Комментарии-документацию я вывожу именно в include-файлах.

# Блок ядра библиотеки
Директория core/ - это базовый модуль, в котором будут содержаться некоторые основные функции нашей библиотеки.

Итак, core/common.cpp:

```cpp
/**
 * @file
 * @brief Core common utils for libnumerixpp
 * @authors alxvdev
 */
#include <chrono>
#include <functional>
#include <iostream>

void credits(void) {
    std::cout << "libnumerixpp v0.1.0 - A powerful C++ Library for High-Performance Numerical Computing" << std::endl;
    std::cout << "Licensed by Apache License" << std::endl;
    std::cout << "Developed&maintained by @alxvdev" << std::endl;
    std::cout << std::endl;
}
```

А теперь его заголовочный файл:

```cpp
/**
 * @file
 * @brief Core common utils for libnumerixpp
 * @authors alxvdev
 */
#ifndef LIBNUMERIXPP_COMMON_HPP
#define LIBNUMERIXPP_COMMON_HPP

#pragma once

/**
 * @brief      print credits
 */
void credits(void);

#endif // LIBNUMERIXPP_COMMON_HPP

```

## Физика
Т.к. модуль физики на данный момент меньше чем модуль математики, начнем именно с него.

Создадим базовый файл physics/core.cpp:

```cpp
/**
 * @file
 * @brief Core utils for physics
 * @authors alxvdev
 */

namespace physics {
}
```

Здесь ничего на данный момент нету, просто пустой namespace physics. Позже мы его дополним.

И по традиции, physics/core.hpp:

```cpp
/**
 * @file
 * @brief Core utils for physics
 * @authors alxvdev
 */
#ifndef LIBNUMERIXPP_PHYSICS_CORE_HPP
#define LIBNUMERIXPP_PHYSICS_CORE_HPP

#pragma once

/**
 * @brief Basic physics utils
 * 
 * @include example-1.cpp
 */
namespace physics {
}

#endif // LIBNUMERIXPP_PHYSICS_CORE_HPP
```

Следующий шаг - уже настоящий функционал модуля. Для примера я взял базовую кинематику. Рассмотрим файл physics/kinematics.cpp:

```cpp
/**
 * @file
 * @brief Physics utils for kinematics
 * @authors alxvdev
 */
#include "libnumerixpp/physics/core.hpp"

namespace physics::kinematics {

    double calculatePath(double speed, double time) {
        return speed * time;
    }

    double calculateSpeed(double path, double time) {
        return path / time;
    }

    double calculateTime(double path, double speed) {
        return path / speed;
    }

    double calculateFinalVelocity(double initial_velocity, double acceleration, double time) {
        return initial_velocity + acceleration * time;
    }

    double calculateFinalPosition(double initial_position, double initial_velocity, double acceleration, double time) {
        return initial_position + initial_velocity * time + 0.5 * acceleration * time * time;
    }
}
```

Здесь вы видите 5 функций. Первые три являются разными подвидами одной формулы: S = v * t (путь равен скорости умноженной на время). А вот две оставшиеся поинтереснее:

calculateFinalVelocity высчитывает конечную скорость объекта, используя формулу: v = u + at, где:

 + v - конечная скорость (м/c)
 + u - начальная скорость (м/c)
 + a - ускорение (м/с)
 + t - время, в течение которого действовало ускорение (с)

calculateFinalPosition высчитывает конечную позицию объекта, используя формулу: s = s0 + v0 * t + 0.5 * a * t^2, где:

 + s - конечное положение
 + s0 - начальное положение
 + v0 - начальная скорость
 + a - ускорение
 + t - время

Код простой, но база сделана. Если вам понравится данная статья, я могу сделать 2 часть, где мы добавим больше функционала.

И не забудем про файл physics/kinematics.hpp:

```cpp
/**
 * @file
 * @brief Physics utils for kinematics
 * @authors alxvdev
 */
#ifndef LIBNUMERIXPP_PHYSICS_KINEMATICS_HPP
#define LIBNUMERIXPP_PHYSICS_KINEMATICS_HPP

#pragma once

/**
 * @brief      Namespace of kinematics (physics)
 *
 * @todo       Add more kinematics equations
 */
namespace physics::kinematics {

    /**
     * @brief      Calculates the path.
     * 
     * This function is based on basic formule: S = v * t
     * where:
     *  + S - path (m)
     *  + v - speed (m/s)
     *  + t - time (s)
     *
     * @param[in]  speed  The speed
     * @param[in]  time   The time
     *
     * @return     The path.
     */
    double calculatePath(double speed, double time);

    /**
     * @brief      Calculates the speed.
     * 
     * This function is based on basic formule: S = v * t
     * where:
     *  + S - path (m)
     *  + v - speed (m/s)
     *  + t - time (s)
     *
     * @param[in]  path  The path
     * @param[in]  time  The time
     *
     * @return     The speed.
     */
    double calculateSpeed(double path, double time);

    /**
     * @brief      Calculates the time.
     * 
     * This function is based on basic formule: S = v * t
     * where:
     *  + S - path (m)
     *  + v - speed (m/s)
     *  + t - time (s)
     *
     * @param[in]  path   The path
     * @param[in]  speed  The speed
     *
     * @return     The time.
     */
    double calculateTime(double path, double speed);

    /**
     * @brief      Calculates the final velocity.
     * 
     * This function is based on the basic kinematics equation: v = u + at
     * where:
     *  + v - final velocity (m/s)
     *  + u - start speed (m/s)
     *  + a - accelaration (m/s^2)
     *  + t - time (s)
     *
     * @param[in]  initial_velocity  The initial velocity
     * @param[in]  acceleration      The acceleration
     * @param[in]  time              The time
     *
     * @return     The final velocity.
     */
    double calculateFinalVelocity(double initial_velocity, double acceleration, double time);

    /**
     * @brief      Calculates the final position.
     *
     * This function is based on the kinematics equation: s = u*t + 0.5 * a * t^2
     * where:
     *  + s - final position (m)
     *  + u - start speed (m/s)
     *  + a - acceleration (m/s^2)
     *  + t - time (s)
     *
     * @param[in]  initial_position  The initial position
     * @param[in]  initial_velocity  The initial velocity
     * @param[in]  acceleration      The acceleration
     * @param[in]  time              The time
     *
     * @return     The final position.
     */
    double calculateFinalPosition(double initial_position, double initial_velocity, double acceleration, double time);
}

#endif // LIBNUMERIXPP_PHYSICS_KINEMATICS_HPP
```

Перейдем к следующему модулю.

## Математика
Итак, начнем с mathematics/core.cpp:

```cpp
/**
 * @file
 * @brief Core utils for mathematics
 * @authors alxvdev
 */
#include <math.h>

namespace mathematics {
    
    double oldApproximatePower(double base, double exponent) {
        union {
            double d;
            long long i;
        } u = { base };

        long long magicNum = 4606853616395542500L;

        u.i = (long long)(magicNum + exponent * (u.i - magicNum));

        return u.d;
    }

    double binaryPower(double base, unsigned long long exponent) {
        double v = 1.0;
        
        while(exponent != 0) {
            if((exponent & 1) != 0)
                v *= base;

            base *= base;
            exponent >>= 1;
        }

        return v;
    }

    double fastPowerDividing(double base, double exponent) {
        if(base == 1.0 || exponent == 0.0)
            return 1.0;

        double eAbs = fabs(exponent);
        double el = ceil(eAbs);
        double basePart = oldApproximatePower(base, eAbs / el);
        double result = binaryPower(basePart, (unsigned long long)el);

        if(exponent < 0.0) {
            return 1.0 / result;
        }
        
        return result;
    }

    double anotherApproximatePower(double base, double exponent) {
        union {
            double d;
            int x[2];
        } u = { base };

        u.x[1] = (int)(exponent * (u.x[1] - 1072632447) + 1072632447);
        u.x[0] = 0;

        return u.d;
    }

    double fastPowerFractional(double base, double exponent) {
        if(base == 1.0 || exponent == 0.0)
            return 1.0;

        double absExp = fabs(exponent);
        unsigned long long eIntPart = (long long)absExp;
        double eFractPart = absExp - eIntPart;
        double result = oldApproximatePower(base, eFractPart) * binaryPower(base, eIntPart);

        if(exponent < 0.0)
            return 1.0 / result;

       return result;
    }

    double add_percent_to_number(double number, double percentage) {
        double oneperc = number / 100;
        double result = number + (oneperc * percentage);

        return result;
    }

    double square_it_up(double num) {
        return num * num;
    }

    double get_square_root(double num) {
        if (num <= 0)
            return 0;

        int exp = 0;

        num = frexp(num, &exp);

        if (exp & 1) {
            exp--;
            num *= 2;
        }

        double y = (1 + num) / 2;
        double z = 0;

        while (y != z) {
            z = y;
            y = (y + num / y) / 2;
        }

        return ldexp(y, exp / 2);
    }
}
```

В начале вы можете увидеть разные виды возведения числа в степень, мы их рассмотрим ниже. А вот в конце находятся более простые функции - для добавления процента к числу, возведения в квадрат, и получения квадратного корня. Функция получения квадратного корня работает так: если входное число меньше или ровно 0, возвращаем 0. Далее используем frexp() для выделения мантиссы и порядка числа num. Мантиссу помещаем в переменную num, а порядок числа - в exp. Если порядок числа exp является нечетным, то его уменьшают на 1 и мантиссу num умножают на 2. Это необходимо для того, чтобы привести число к виду, когда мантисса находится в диапазоне [0.5, 1) (от 0.5 включая до 1 не включая). Затем инициализируются две перемнные: y=начальное значение, равно среднему между 1 и мантиссой num, и z=0. Далее выполняется итеративный цикл вычисления квадратного корня. После возвращаем результат, умноженный но соответствующую степень 2, вычисленную ранее на основе порядке exp.

А теперь, чтобы перейти к методам возведения в степень, создадим mathematics/core.hpp:

```cpp
/**
 * @file
 * @brief Core utils for mathematics
 * @authors alxvdev
 */
#ifndef LIBNUMERIXPP_MATHEMATICS_CORE_HPP
#define LIBNUMERIXPP_MATHEMATICS_CORE_HPP

#pragma once

/**
 * @brief      Basic mathematics utils
 * @include example-2.cpp
 */
namespace mathematics {
    /**
     * @brief      Algorithm for fast exponentiation "'Old' approximation"
     *
     * @details    If accuracy is not important to you and the degrees are in
     *             the range from -1 to 1, you can use this method (see also
     *             'another' approximation: anotherApproximatePower()). This
     *             method is based on the algorithm used in the 2005 game Quake
     *             III Arena. He raised the number x to the power -0.5, i.e.
     *             found the value: \f$\frac{1}{\sqrt{x}}\f$
     *
     * @param[in]  base      The base
     * @param[in]  exponent  The exponent
     *
     * @return     raised value
     */
    double oldApproximatePower(double base, double exponent);
    
    /**
     * @brief      Algorithm for fast exponentiation "'Another' approximation"
     *
     * @details    Speed increase: ~9 times. Accuracy: <1.5%. Limitations:
     *             accuracy drops rapidly as the absolute value of the degree
     *             increases and remains acceptable in the range [-10, 10] (see
     *             also 'old' approximation: oldApproximatePower()).
     *
     * @param[in]  base      The base
     * @param[in]  exponent  The exponent
     *
     * @return     raised value
     */
    double anotherApproximatePower(double base, double exponent);

    /**
     * @brief      Algorithm: Binary exponentiation
     * @details    Speed increase: ~7.5 times on average, the advantage remains
     *             until numbers are raised to a power of 134217728, Speed
     *             increase: ~7.5 times on average, the advantage remains until
     *             the numbers are raised to the power of 134217728. Error:
     *             none, but it is worth noting that the multiplication
     *             operation is not associative for floating point numbers, i.e.
     *             1.21 * 1.21 is not the same as 1.1 * 1.1 * 1.1 * 1.1,
     *             however, when compared with standard functions, errors do not
     *             arise, as mentioned earlier. Restrictions: the degree must be
     *             an integer not less than 0
     *
     * @param[in]  base      base
     * @param[in]  exponent  exponent
     *
     * @return     raised value
     */
    double binaryPower(double b, unsigned long long e);

    /**
     * @brief      Algorithm: "Dividing fast power"
     *
     * @details    Speed increase: ~3.5 times. Accuracy: ~13%. The code below
     *             contains checks for special input data. Without them, the
     *             code runs only 10% faster, but the error increases tenfold
     *             (especially when using negative powers).
     *
     * @param[in]  base      The base
     * @param[in]  exponent  The exponent
     *
     * @return     raised value
     */
    double fastPowerDividing(double base, double exponent);

    /**
     * @brief      Algorithm: "Fractional fast power"
     * @details    Speed increase: ~4.4 times. Accuracy: ~0.7%
     *
     * @param[in]  base      The base
     * @param[in]  exponent  The exponent
     *
     * @return     raised value
     */
    double fastPowerFractional(double base, double exponent);

    /**
     * @brief      Adds a percent to number.
     *
     * @param[in]  number      The number
     * @param[in]  percentage  The percentage
     *
     * @return     number
     */
    double add_percent_to_number(double number, double percentage);

    /**
     * @brief      Gets the number square (N^2).
     *
     * @param[in]  num   The number
     *
     * @return     The number square.
     */
    double square_it_up(double num);

    /**
     * @brief      Gets the square root.
     *
     * @param[in]  num   The number
     *
     * @return     The square root.
     */
    double get_square_root(double num);
}

#endif // LIBNUMERIXPP_MATHEMATICS_CORE_HPP
```

### Заново изобретаем std::pow
В этом разделе я покажу реализации нескольких нестандартных алгоритмов для возведения числа в степень. Реализация и описание способ взяты из [этой статьи на хабре](https://habr.com/ru/articles/584662/).

Скорость алгоритмов сравнивается с std::pow.

![](https://habrastorage.org/r/w1560/getpro/habr/upload_files/cd4/660/447/cd46604474f82fde278d880fd92a5c1c.png)

#### Алгоритм: "Старая аппроксимация"
Этот метод основан на алгоритме, использованном в игре Quake III Arena 2005 года. Он возводил число x в степень -0.5.

 + Увеличение скорости: в ~11 раз.
 + Погрешность: <2%.
 + Ограничения: приемлемая точность только для степеней от -1 до 1.

```cpp
double oldApproximatePower(double base, double exponent) {
    union {
        double d;
        long long i;
    } u = { base };

    long long magicNum = 4606853616395542500L;

    u.i = (long long)(magicNum + exponent * (u.i - magicNum));

    return u.d;
}
```

magicNum = это магическое число. Вы можете узнать о нем подробнее в [этой статье](https://habr.com/ru/company/infopulse/blog/336110/).

#### Алгоритм: Бинарное возведение в степень
Увеличение скорости: в среднем в ~7.5 раз, преимущество сохраняется до возведения чисел в степень 134217728.

Погрешность: нет, но стоит отметить, что операция умножения не ассоциативна для чисел с плавающей точкой, т.е. 1.21 * 1.21 не то же самое, что 1.1 * 1.1 * 1.1 * 1.1, однако при сравнении со стандартными функциями погрешности, как уже сказано ранее, не возникает.

Ограничения: степень должна быть целым числом не меньше 0

```cpp
double binaryPower(double base, unsigned long long exponent) {
    double v = 1.0;
    
    while(exponent != 0) {
        if((exponent & 1) != 0)
            v *= base;

        base *= base;
        exponent >>= 1;
    }

    return v;
}
```

Широко известный алгоритм для возведения любого числа в целую степень с абсолютной точностью. Принцип действия прост: есть целая степень e, чтобы получить число b в этой степени нужно возвести это число во все степени 1, 2, 4, … 2n (в коде этому соответствует `base *= base`), каждый раз сдвигая биты e вправо (e >>= 1) пока оно не равно 0 и тогда, когда последний бит e не равен нулю ((exponent & 1) != 0), домножать результат v на полученное base.

#### Алгоритм: "Делящая быстрая степень"
Увеличение скорости: в ~3.5 раз

Погрешность: ~13%

Примечание: в коде ниже присутствуют проверки для особых входных данных. Без них код работает всего на 10% быстрее, но погрешность возрастает в десятки раз (особенно при использовании отрицательных степеней).

```cpp
double fastPowerDividing(double base, double exponent) {
    if(base == 1.0 || exponent == 0.0)
        return 1.0;

    double eAbs = fabs(exponent);
    double el = ceil(eAbs);
    double basePart = oldApproximatePower(base, eAbs / el);
    double result = binaryPower(basePart, (unsigned long long)el);

    if(exponent < 0.0) {
        return 1.0 / result;
    }
    
    return result;
}
```

#### Алгоритм: "Дробная быстрая степень"
Увеличение скорости: в ~4.4 раза

Погрешность: ~0.7%

```cpp
double fastPowerFractional(double base, double exponent) {
    if(base == 1.0 || exponent == 0.0)
        return 1.0;

    double absExp = fabs(exponent);
    unsigned long long eIntPart = (long long)absExp;
    double eFractPart = absExp - eIntPart;
    double result = oldApproximatePower(base, eFractPart) * binaryPower(base, eIntPart);

    if(exponent < 0.0)
        return 1.0 / result;

   return result;
}
```

По сути, любое число состоит из суммы двух частей: целой и дробной. Целую можно использовать для возведения основания в степень при помощи бинарного возведения, а дробную - при помощи “старой” аппроксимации.

#### Алгоритм: "Другая аппроксимация"
Увеличение скорости: в ~9 раз

Погрешность: <1.5%

Ограничения: точность стремительно падает при повышении абсолютного значения степени и остается приемлемой в промежутке [-10, 10]

```cpp
double anotherApproximatePower(double base, double exponent) {
    union {
        double d;
        int x[2];
    } u = { base };

    u.x[1] = (int)(exponent * (u.x[1] - 1072632447) + 1072632447);
    u.x[0] = 0;

    return u.d;
}
```

#### Сравнение

![](https://habrastorage.org/r/w1560/getpro/habr/upload_files/291/4e7/f68/2914e7f683101fb28c37a435c140f816.png)

![](https://habrastorage.org/r/w1560/getpro/habr/upload_files/9ac/6d0/343/9ac6d034339c1f68d81fc31fee5bfa5f.png)

![](https://habrastorage.org/r/w1560/getpro/habr/upload_files/89d/9b8/ced/89d9b8cedc688817d35986835621b9cc.png)

Каждый из перечисленных методов дает различную точность и скорость. Поэтому, прежде чем использовать стандартную функцию возведения в степень, стоит проанализировать какие у вас будут входные данные, и насколько вам важна точность. Выбор правильного метода может существенно ускорить работу вашей программы.

![](https://habrastorage.org/r/w1560/getpro/habr/upload_files/1bf/0cd/7c2/1bf0cd7c287128052773610ef7e9e00f.png)

### Квадратные уравнения
Продолжим улучшение модуля математики - на этот раз займемся квадратными уравнениями.

Создадим файл mathematics/quadratic_equations.cpp:

```cpp
/**
 * @file
 * @brief Math utils for quadratic
 * @authors alxvdev
 */
#include <vector>
#include "libnumerixpp/mathematics/core.hpp"

namespace mathematics::quadratic {

    double calculateDiscriminant(double a, double b, double c) {
        double d = mathematics::square_it_up(b) - 4 * a * c;

        return d;
    }

    std::vector<double> calculateRootsByDiscriminant(double discriminant, double a, double b) {
        std::vector<double> roots;

        if (discriminant > 0) {
            double x1 = (-b + get_square_root(discriminant)) / (2 * a);
            double x2 = (-b - get_square_root(discriminant)) / (2 * a);

            roots.push_back(x1);
            roots.push_back(x2);
        } else if (discriminant == 0) {
            double x1 = -b + get_square_root(discriminant) / (2 * a);
            roots.push_back(x1);
        }

        return roots;
    }
    
    std::vector<double> getRootsByVietaTheorem(double a, double b, double c) {
        std::vector<double> roots;

        if (a == 0)
            return roots;

        double roots_sum = -(b / a);
        double roots_mul = c / a;

        roots.push_back(roots_sum);
        roots.push_back(roots_mul);

        return roots;
    }
}
```

Функция calculateDiscriminant высчитывает дискриминант по формуле D = b^2 - 4ac.

Функция calculateRootsByDiscriminant высчитывает корни уравнения. На вход принимает дискриминант, переменные a и b. На выходе возвращает vector (массив с неясным количеством элементов, проще говоря) типа double. Если дискриминант больше 0, то корня два, высчитываем их по формуле: -b +- квадратный корень из дискриминанта / 2a. Если дискриминант равен 0, то корень 1. А если дискриминант равен нулю - то корней нет.

Функция getRootsByVietaTheorem "получает корни" по теореме Виета. Теорема Виета гласит, если a != 0, значит: x1 + x2 = - b / a И x1 * x2 = c / a. В данной функции мы как раз и получаем их. А вот реализацию поиска корней я решил пока не делать.

И следующим шагом мы создаем файл mathematics/quadratic_equations.hpp:

```cpp
/**
 * @file
 * @brief Quadratic utils for mathematics
 * @authors alxvdev
 */
#ifndef LIBNUMERIXPP_MATHEMATICS_QUADRATIC_EQUATIONS_HPP
#define LIBNUMERIXPP_MATHEMATICS_QUADRATIC_EQUATIONS_HPP

#pragma once

#include <vector>
#include "libnumerixpp/mathematics/core.hpp"

/**
 * mathematics utils for quadratic equations and other
 *
 * @include example-2.cpp
 */
namespace mathematics::quadratic {
    /**
     * @brief      Calculates the discriminant.
     *
     * @details    Based on discriminant formula: \f$b^{2} - 4ac\f$
     *
     * @param[in]  a     a
     * @param[in]  b     b
     * @param[in]  c     c
     *
     * @return     The discriminant.
     */
    double calculateDiscriminant(double a, double b, double c);

    /**
     * @brief      Calculates the roots by discriminant.
     *
     * @details    Calculate the roots by discriminant \f$\frac{-b +-
     *             \sqrt{D}}{2a}\f$. D > 0 = 2 roots, D == 0 = 1 root, D < 0 = 0
     *             roots.
     *
     * @param[in]  discriminant  The discriminant
     * @param[in]  a             a
     * @param[in]  b             b
     *
     * @return     The roots by discriminant.
     */
    std::vector<double> calculateRootsByDiscriminant(double discriminant, double a, double b);

    /**
     * @brief      Gets the roots by vieta theorem.
     *
     * @param[in]  a     a
     * @param[in]  b     b
     * @param[in]  c     c
     *
     * @return     The roots by vieta theorem.
     */
    std::vector<double> getRootsByVietaTheorem(double a, double b, double c);
}

#endif // LIBNUMERIXPP_MATHEMATICS_QUADRATIC_EQUATIONS_HPP
```

Мы закончили разработку модулей. Пора перейти к примерам.

## Примеры
В данной части статьи мы создадим файлы example-1.cpp и example-2.cpp в директории examples. В этих файлах будут содержаться примеры работы библиотеки.

Напишем example-1.cpp, где мы будем тестировать модуль физики:

```cpp
#include <iostream>
#include "libnumerixpp/libnumerixpp.hpp"
#include "libnumerixpp/core/common.hpp"
#include "libnumerixpp/physics/core.hpp"
#include "libnumerixpp/physics/kinematics.hpp"

int main() {
    credits();
    say_hello("LIBNUMERIXPP");

    double speed = 10.0;
    double time = 5.0;

    double path = physics::kinematics::calculatePath(speed, time);
    speed = physics::kinematics::calculateSpeed(path, time);
    time = physics::kinematics::calculateSpeed(path, speed);

    std::cout << "Calculate: speed=" << speed << "m/s" << "; time=" << time << "s" << "; path=" << path << "m" << std::endl; 

    double finalVelocity = physics::kinematics::calculateFinalVelocity(10.0, 10.0, 10.0);
    std::cout << "final velocity (10.0, 10.0, 10.0) = " << finalVelocity << std::endl;

    double finalPosition = physics::kinematics::calculateFinalPosition(10.0, 10.0, 10.0, 10.0);
    std::cout << "final position (10.0, 10.0, 10.0, 10.0) = " << finalVelocity << std::endl;

    return 0;
}
```

При сборке данный файл выведет:

```
libnumerixpp v0.1.0 - A powerful C++ Library for High-Performance Numerical Computing
Licensed by Apache License
Developed&maintained by @alxvdev

LIBNUMERIXPP
Calculate: speed=10m/s; time=5s; path=50m
final velocity (10.0, 10.0, 10.0) = 110
final position (10.0, 10.0, 10.0, 10.0) = 110
```

А теперь второй файл - example-2.cpp, где будут примеры использования модуля математики:

```cpp
#include <iostream>
#include <vector>
#include "libnumerixpp/libnumerixpp.hpp"
#include "libnumerixpp/core/common.hpp"
#include "libnumerixpp/mathematics/core.hpp"
#include "libnumerixpp/mathematics/quadratic_equations.hpp"

int main() {
    credits();
    println("LIBNUMERIXPP");

    // SQUARE AND SQR //

    double num = 100.0;
    double num_sq = mathematics::square_it_up(num);
    double num_sqr = mathematics::get_square_root(num);
    std::cout << "Square " << num << ": " << num_sq << std::endl;
    std::cout << "Square root " << num << ": " << num_sqr << std::endl;

    std::cout << std::endl;

    // CALCULATE QUADRATIC EQUATION BY DISCRIMINANT //

    double a = -2;
    double b = 5;
    double c = 5;

    double d = mathematics::quadratic::calculateDiscriminant(a, b, c);
    std::vector<double> roots = mathematics::quadratic::calculateRootsByDiscriminant(d, a, b);

    std::cout << "Quadratic Equation: a=" << a << "; b=" << b << "; c=" << c << std::endl;
    std::cout << "D=" << d << std::endl;
    std::cout << "Roots:" << std::endl;

    for (double root : roots) {
        std::cout << root << std::endl;
    }

    std::cout << std::endl;

    // PERCENTAGE //

    double nump = mathematics::add_percent_to_number(100.0, 10.0);
    std::cout << "100+10%: " << nump << std::endl;

    std::cout << std::endl;
 
    // POWER / Algorithms for fast exponentiation //

    double bestPowVal = 100;
    double pow_results[5] = {
        mathematics::oldApproximatePower(10.0, 2.0),
        mathematics::anotherApproximatePower(10.0, 2.0),
        mathematics::binaryPower(10.0, 2),
        mathematics::fastPowerDividing(10.0, 2.0),
        mathematics::fastPowerFractional(10.0, 2.0)
    };

    std::cout << "0 oldApproximatePower    : base 10 exponent 2: " << pow_results[0] << std::endl;
    std::cout << "1 anotherApproximatePower: base 10 exponent 2: " << pow_results[1] << std::endl;
    std::cout << "2 binaryPower            : base 10 exponent 2: " << pow_results[2] << std::endl;
    std::cout << "3 fastPowerDividing      : base 10 exponent 2: " << pow_results[3] << std::endl;
    std::cout << "4 fastPowerFractional    : base 10 exponent 2: " << pow_results[4] << std::endl;

    for (int i = 0; i < sizeof(pow_results) / sizeof(pow_results[0]); i++) {
        double error = bestPowVal - pow_results[i];

        std::cout << "POW Algorithm #" << i << ": error=" << error << std::endl;
    }

    return 0;
}
```

При компиляции данный файл выведет:

```
libnumerixpp v0.1.0 - A powerful C++ Library for High-Performance Numerical Computing
Licensed by Apache License
Developed&maintained by @alxvdev

LIBNUMERIXPP
Square 100: 10000
Square root 100: 10

Quadratic Equation: a=-2; b=5; c=5
D=65
Roots:
-0.765564
3.26556

100+10%: 110

0 oldApproximatePower    : base 10 exponent 2: 100.673
1 anotherApproximatePower: base 10 exponent 2: 99.711
2 binaryPower            : base 10 exponent 2: 100
3 fastPowerDividing      : base 10 exponent 2: 100
4 fastPowerFractional    : base 10 exponent 2: 96.3496
POW Algorithm #0: error=-0.672563
POW Algorithm #1: error=0.289001
POW Algorithm #2: error=0
POW Algorithm #3: error=0
POW Algorithm #4: error=3.65044
```

Вот и все. С программированием мы закончили - настало очередь украшательств.

# Украшаем репозиторий
Итак, любой проект будет привлекательнее с грамотно оформленным README. У меня в проекте он выглядит [так](https://github.com/alxvdev/libnumerixpp/blob/main/README.md).

Документация поможет пользователям и разработчикам. Да, если им сильно нужно - они могут и просто скачать или почитать код, но многих отсутствие нормальной документации или хотя-бы нормального README файла отпугивает. Что вы бы выбрали - хорошо заполненный и документированный репозиторий или такой же репозиторий, но без какой либо информации? Я думаю, ответ очевиден.

Давайте разберем README поэтапно. Начнем с шапки:

```md
# libnumerixpp

<p align="center">A Powerful C++ Library for High-Performance Numerical Computing</p>
<br>
<p align="center">
    <img src="https://img.shields.io/github/languages/top/alxvdev/libnumerixpp?style=for-the-badge">
    <img src="https://img.shields.io/github/languages/count/alxvdev/libnumerixpp?style=for-the-badge">
    <img src="https://img.shields.io/github/license/alxvdev/libnumerixpp?style=for-the-badge">
    <img src="https://img.shields.io/github/stars/alxvdev/libnumerixpp?style=for-the-badge">
    <img src="https://img.shields.io/github/issues/alxvdev/libnumerixpp?style=for-the-badge">
    <img src="https://img.shields.io/github/last-commit/alxvdev/libnumerixpp?style=for-the-badge">
</p>

> [!CAUTION]
> At the moment, libnumerixpp is under active development (alpha), many things may not work, and this version is not recommended for use (all at your own risk).

libnumerixpp is a powerful, cross-platofrm C++ library designed for high-performance numerical computing in the domains of physics, mathematics, and computer science.

You can join to our [small russian telegram blog](https://t.me/hex_warehouse).

You can view docs for libnumerixpp [here](https://alxvdev.github.io/libnumerixpp).
```

Вверху мы указываем заголовок, название проекта. Ниже описание и бейджи. Бейджи нужны для общей статистики проекта - лицензия, язык, звезды и т.д. Замените `/alxvdev/libnumerixpp` на свой юзернейм и репозиторий.

После мы вставляем предупреждение в виде цитаты, что проект в стадии разработки и может быть не стабилен.

Ниже также детали, и другие важные вещи, на которые сразу стоит обратить внимания. У меня это ссылка на телеграм-канал и на документацию.

Идем дальше:

```md
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
```

Основные возможности. Здесь можно перечислить, что может ваш проект, какие у него преимущества.

Далее вы можете также создавать разные блоки, рассказывающие, например, о структуре.

Желательно еще дать инструкции по установке и сборке. Посмотрите, как сделано в [моем репозитории](https://github.com/alxvdev/libnumerixpp?tab=readme-ov-file#usage).

Следующим шагом я бы сделал ссылки на примеры использование, зависимости и инструменты, а также раздел документации и поддержки:

```md
## Examples
Below you can see examples of using libnumerixpp in your project. Also, you can view [examples dir](./examples).

### example-1 Speed, Time, Path
Source code: [example-1.cpp](./examples/example-1.cpp)

This example shows how to calculate the *speed, path, and time* using the `physics::kinematics`.

### example-2 Math, Quadratic and math
Source code: [example-2.cpp](./examples/example-2.cpp)

This example shows how to calculate the *quadratic equations, discriminant, squares* using the `mathematics` and `mathematics::quadratic`.

## Tools and Dependencies
linumerixpp utilizes the following tools and libraries:

 - **CMake**: Cross-platform build system
 - **Doxygen**: Documentation generation

## Documentation
Detailed documentation, including user guides, API reference, and code examples, is available in the [docs](https://alxvdev.github.io/libnumerixpp/). Or you can see articles or additional info in [en docs dir](./docs/en/index.md) or [ru docs dir](./docs/ru/index.md).

If you have any questions, suggestions, or encounter issues, please create a new [issue](https://github.com/alxvdev/libnumerixpp/issues/new) in the repository. We'll be happy to assist you and improve the library.

You can also write to me on Telegram: [@alexeev_dev](https://t.me/alexeev_dev)

libnumerixpp is an Open Source project, and it only survives due to your feedback and support!

Project releases are available at [this link](https://github.com/alxvdev/libnumerixpp/releases).
```

И в самом конце можно указать копирайты:

```md
## Copyright
libnumerixpp is released under the [Apache License 2.0](LICENSE).

Copyright © 2024 Alexeev Bronislav. All rights reversed.
```

Я хочу сказать, что это не требования, а мои рекомендации. Вы можете сделать по другому.

И небольшое наставление по коммитам. По некоторым правилам, коммит должен быть в повелительном наклонении, потому что это, как бы указание разработчику, что надо делать. Но это не указание, это также рекомендации, вы вольны использовать что хотите (или что захочет ваша команда).

## Описание коммитов
| Название | Описание                                                        |
|----------|-----------------------------------------------------------------|
| build    | Сборка проекта или изменения внешних зависимостей               |
| sec      | Безопасность, уязвимости                                        |
| ci       | Настройка CI и работа со скриптами                              |
| docs     | Обновление документации                                         |
| feat     | Добавление нового функционала                                   |
| fix      | Исправление ошибок                                              |
| perf     | Изменения направленные на улучшение производительности          |
| refactor | Правки кода без исправления ошибок или добавления новых функций |
| revert   | Откат на предыдущие коммиты                                     |
| style    | Правки по кодстайлу (табы, отступы, точки, запятые и т.д.)      |
| test     | Добавление тестов                                               |

Пример:

```bash
git commit -m "feat: add line output"          # en, добавьте вывод строки
git commit -m "feat: добавьте вывод строки"    # ru
```

Больше информации об оформлении репозитория вы можете увидеть [в моей старой статье](https://habr.com/ru/articles/774922/).

![](https://habrastorage.org/r/w1560/getpro/habr/upload_files/a82/0fd/7b2/a820fd7b20a187308ed578fa5384e5c9.png)

---

Вот и все. Минимальный комплект минимальной библиотеки. Надеюсь, я сподвиг вас к чему-то большему. Пишите, творите, публикуйте!

# Заключение
Спасибо за внимание! Это был довольно интересный опыт для меня, т.к. это мой первый большой проект на языке C++, где я попытался его изучить более подробно.

Если у вас есть замечания по статье или по коду - пишите, наверняка есть более опытный и профессиональный программист на C++, который может помочь как и читателям статьи, так и мне.

Ссылка на мой репозиторий реализации командного интерпретатора [здесь](https://github.com/alxvdev/libnumerixpp).

Буду рад, если вы присоединитесь к моему небольшому [телеграм-блогу](https://t.me/hex_warehouse). Анонсы статей, новости из мира IT и полезные материалы для изучения программирования и смежных областей.

P.S. вы можете прорекламировать свою библиотеку в комментариях, если она интересная и может кому-то пригодиться.

## Источники

 + [Язык программирования C++ / Metanit](https://metanit.com/cpp/tutorial/1.1.php)
 + [Просто о шаблонах C++](https://habr.com/ru/articles/599801/)
 + [Ускоряем pow](https://habr.com/ru/articles/584662)
 + [Doxygen / eax.me](https://eax.me/doxygen/)
 + [Автодокументация Doxygen и ее публикация на Github Pages](https://habr.com/ru/articles/799051/)
