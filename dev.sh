#!/bin/bash

COMMAND=$1
CLASS_PATH=$2

if [[ "$COMMAND" != "make:class" ]]; then
    echo "Invalid command. Use: ./dev.sh make:class ClassName or ./dev.sh make:class Lib/ClassName"
    exit 1
fi

if [[ -z "$CLASS_PATH" ]]; then
    echo "Error: No class name provided."
    exit 1
fi

# Extract directory and class name
dir="$(dirname "$CLASS_PATH")"
classname="$(basename "$CLASS_PATH")"
namespace_name="$(echo "$dir" | sed 's#/#::#g')"

# Ensure the class is inside a subdirectory
if [[ "$dir" == "." ]]; then
    echo "Error: Class must be inside a subdirectory."
    exit 1
fi

# Define paths
SRC_DIR="src/$dir"
INCLUDE_DIR="include/$dir"
CPP_FILE="$SRC_DIR/$classname.cpp"
HEADER_FILE="$INCLUDE_DIR/$classname.h"

# Create directories if they don't exist
mkdir -p "$SRC_DIR"
mkdir -p "$INCLUDE_DIR"

# Create header file
if [[ ! -f "$HEADER_FILE" ]]; then
    cat > "$HEADER_FILE" <<EOF
#ifndef ${classname^^}_H
#define ${classname^^}_H

namespace $namespace_name
{

    class $classname 
    {
        public:
            $classname();
            ~${classname}();
    };

} // namespace $namespace_name

#endif // ${classname^^}_H
EOF
    echo "Created: $HEADER_FILE"
else
    echo "Header file already exists: $HEADER_FILE"
fi

# Create source file
if [[ ! -f "$CPP_FILE" ]]; then
    cat > "$CPP_FILE" <<EOF
#include "$classname.h"

namespace $namespace_name
{

    $classname::$classname()
    {
        // Constructor implementation
    }

    $classname::~${classname}()
    {
        // Destructor implementation
    }

} // namespace $namespace_name
EOF
    echo "Created: $CPP_FILE"
else
    echo "Source file already exists: $CPP_FILE"
fi
