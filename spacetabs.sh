#!/bin/bash

# Define color codes for output
RED='\e[31m'
GREEN='\e[32m'
YELLOW='\e[33m'
NC='\e[0m' # No Color

# Function to display usage instructions
usage() {
    echo -e "${YELLOW}Usage: $0 <file> <tab_size> <conversion_type>${NC}"
    echo -e "<conversion_type>: spaces or tabs"
    exit 1
}

# Function to display error messages
error() {
    echo -e "${RED}Error: $1${NC}"
    exit 1
}

# Function to perform conversion
convert_tabs() {
    local file="$1"
    local tab_size="$2"
    local conversion_type="$3"
    
    if [[ "$conversion_type" == "spaces" ]]; then
        echo -e "${GREEN}Converting tabs to spaces...${NC}"
        expand -t "$tab_size" "$file" > "${file}.tmp" && mv "${file}.tmp" "$file"
    elif [[ "$conversion_type" == "tabs" ]]; then
        echo -e "${GREEN}Converting spaces to tabs...${NC}"
        unexpand -t "$tab_size" "$file" > "${file}.tmp" && mv "${file}.tmp" "$file"
    else
        error "Invalid conversion type: $conversion_type. Use 'spaces' or 'tabs'."
    fi
}

# Main script execution
if [[ "$#" -ne 3 ]]; then
    usage
fi

FILE="$1"
TAB_SIZE="$2"
CONVERSION_TYPE="$3"

# Check if the provided file exists
if [[ ! -f "$FILE" ]]; then
    error "File not found: $FILE"
fi

# Validate tab size is a positive integer
if ! [[ "$TAB_SIZE" =~ ^[1-9][0-9]*$ ]]; then
    error "Tab size must be a positive integer."
fi

# Perform the conversion
convert_tabs "$FILE" "$TAB_SIZE" "$CONVERSION_TYPE"

echo -e "${GREEN}Conversion completed successfully: $FILE${NC}"
