cmake_minimum_required(VERSION 3.14)
project(VectorRange)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")

file(GLOB SOURCES "Sources/*.c")
file(GLOB INCLUDE "Headers/*.h")
file(GLOB EXC "main.c")
file(GLOB EXC_TEST "Tests/*.cpp")

add_library(lib ${INCLUDE} ${SOURCES})
add_executable(main ${EXC})
target_link_libraries(main lib m)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests ${EXC_TEST})
target_link_libraries(tests lib gtest_main)
