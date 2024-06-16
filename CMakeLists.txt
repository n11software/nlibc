cmake_minimum_required(VERSION 3.10)
project(nlibc C CXX ASM)

# Specify the freestanding environment
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostdlib -ffreestanding -Wno-builtin-declaration-mismatch -I${CMAKE_SOURCE_DIR}/include")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nostdlib -ffreestanding -Wno-builtin-declaration-mismatch -I${CMAKE_SOURCE_DIR}/include")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")

enable_language(ASM)

# Include your custom headers directory
include_directories(BEFORE ${CMAKE_SOURCE_DIR}/include)

# Collect sources
file(GLOB_RECURSE LIBC_SOURCES src/*.cpp)
file(GLOB_RECURSE LIBC_HEADERS include/*.h)

# Add libraries
add_library(crt0 STATIC crt0.s)
add_library(crti STATIC crti.s)
add_library(crtn STATIC crtn.s)
add_library(C SHARED ${LIBC_SOURCES})

# Set properties
set_target_properties(C PROPERTIES PUBLIC_HEADER "${LIBC_HEADERS}")

# Install rules
install(TARGETS C LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
