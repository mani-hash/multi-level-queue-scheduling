#!/bin/bash

# Load .env file
if [ -f .env ]; then
    export $(grep -v '^#' .env | xargs)
else
    echo ".env file not found. Please create one."
    exit 1
fi

# Variables from .env
BUILD_DIR=$BUILD_DIRECTORY
BIN_DIR=$BIN_DIRECTORY
TARGET=$APP_NAME

# Generate config.cmake from .env
generate_config()
{
    echo "Generating config.cmake..."
    echo "set(APP_NAME $APP_NAME)" > config.cmake
    echo "set(BUILD_DIRECTORY $BUILD_DIRECTORY)" >> config.cmake
    echo "set(BIN_DIRECTORY $BIN_DIRECTORY)" >> config.cmake
}

# Function to clean the build and bin directories
clean()
{
    if [ -d "$BUILD_DIR" ]; then
        echo "Removing build directory..."
        rm -rf $BUILD_DIR
    else
        echo "Build directory does not exist. Nothing to clean."
    fi

    if [ -d "$BIN_DIR" ]; then
        echo "Removing bin directory..."
        rm -rf $BIN_DIR
    else
        echo "Bin directory does not exist. Nothing to clean."
    fi

    if [ -f "config.cmake" ]; then
        echo "Removing config.cmake..."
        rm -f config.cmake
    fi
}

# Function to build the project
build()
{
    # Generate config.cmake
    generate_config

    echo "Configuring CMake..."
    mkdir -p $BUILD_DIR
    cd $BUILD_DIR
    cmake ..

    echo "Building the project..."
    cmake --build .
    cd ..
}

# Function to run the executable
run()
{
    if [ ! -f "$BIN_DIR/$TARGET" ]; then
        echo "Executable not found. Building the project first..."
        build
    fi

    echo "Running the executable..."
    ./$BIN_DIR/$TARGET
}

# Main script logic
case "$1" in
    clean)
        clean
        ;;
    run)
        build
        run
        ;;
    *)
        build
        ;;
esac