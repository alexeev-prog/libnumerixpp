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
	for root, dirs, files in os.walk(os.getcwd()):
		if len(set(root.split('/')).intersection(IGNORED_DIRS)) > 0:
			continue
		for file in files: 
			if file.endswith(cpp_extensions):
				print(f"{BOLD}Format {file}: {root}/{file}{NC}")
				os.system(f'codespell -w {root}/{file}')
				os.system(f'clang-tidy --fix {root}/{file}')
				os.system(f"{CLANG_FORMAT} -i -style=file {root}/{file}")
				print(f"{GREEN}Formatting completed successfully: {root}/{file}{NC}")
				convert_file(f'{root}/{file}', "4", "tabs")


if __name__ == '__main__':
	main()
