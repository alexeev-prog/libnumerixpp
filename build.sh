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

if [ "$1" == "format" ]; then
	# Formatting code
	print_header "Formatting code"
	print_step "Format and cleaning code..."
	./format-code.py
	print_success "Code formatted."
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
