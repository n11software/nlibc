cmake_minimum_required(VERSION 3.10)
project(nlibc C CXX ASM)

set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

SET(CMAKE_SYSTEM_NAME Generic)

SET(CMAKE_SYSTEM_PROCESSOR x86_64)
SET(CMAKE_CROSSCOMPILING 1)

enable_language(ASM)
set(CMAKE_C_COMPILER "x86_64-hydra-gcc")
set(CMAKE_CXX_COMPILER "x86_64-hydra-g++")
set(CMAKE_ASM_COMPILER "x86_64-hydra-gcc")

# Specify the freestanding environment
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostdlib -ffreestanding -Wno-builtin-declaration-mismatch -I${CMAKE_SOURCE_DIR}/include")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nostdlib -ffreestanding -Wno-builtin-declaration-mismatch -I${CMAKE_SOURCE_DIR}/include")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostdlib")


# Include your custom headers directory
include_directories(BEFORE ${CMAKE_SOURCE_DIR}/include)

# Collect sources
file(GLOB_RECURSE LIBC_SOURCES src/*.cpp)
file(GLOB_RECURSE LIBC_HEADERS include/*.h)

# Add libraries
add_library(c STATIC ${LIBC_SOURCES})

# Specify the CRT startup assembly files
set(CRT_SOURCES
    crt0.s
    crti.s
    crtn.s
)

# Compile each assembly file separately
foreach(SRC ${CRT_SOURCES})
    get_filename_component(OBJ_NAME ${SRC} NAME_WE)
    add_custom_command(
        OUTPUT ${CMAKE_BINARY_DIR}/${OBJ_NAME}.o
        COMMAND ${CMAKE_ASM_COMPILER} -c ${CMAKE_SOURCE_DIR}/${SRC} -o ${CMAKE_BINARY_DIR}/${OBJ_NAME}.o
        DEPENDS ${SRC}
    )
    list(APPEND CRT_OBJECTS ${CMAKE_BINARY_DIR}/${OBJ_NAME}.o)
endforeach()

# Create a target that ensures the object files get built
add_custom_target(crt_objs ALL DEPENDS ${CRT_OBJECTS})

# Set properties
set_target_properties(c PROPERTIES PUBLIC_HEADER "${LIBC_HEADERS}")

# Install rules
install(TARGETS c LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
