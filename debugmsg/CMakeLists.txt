project(qtdebug)
cmake_minimum_required(VERSION 2.8.9)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)
# find_package(Qt5Core)
# find_package(Qt5DBus)

# Tell CMake to create executable
add_executable(qtdebug qtdebug.cpp)

# Use the Widgets module from Qt 5.
qt5_use_modules(qtdebug Core)
