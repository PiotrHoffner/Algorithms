cmake_minimum_required(VERSION 3.10)

# Set up project-name variable
project(QuickSort)

# Use C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set up shortcut-variables for directories
set(ProjectDir ${CMAKE_CURRENT_SOURCE_DIR})
set(GTestDownloadDir ${ProjectDir}/../_gtest/googletest-download)

# Set coloured message variables
string(ASCII 27 Esc)
set(Yellow "${Esc}[1;33m")
set(Green "${Esc}[1;32m")
set(ColourReset "${Esc}[m")

message("${Green}>> ${PROJECT_NAME}: started CMakeLists.txt <<${ColourReset}")

# Download and configure googletest if not found
if(NOT EXISTS ${GTestDownloadDir})
  message("${Yellow}>> ${PROJECT_NAME}: googletest-download dir not found. Configuring /googletest/CMakeLists.txt <<${ColourReset}")
  execute_process(COMMAND mkdir -p build WORKING_DIRECTORY ${ProjectDir}/../googletest)
  add_subdirectory(${ProjectDir}/../googletest ${ProjectDir}/../googletest/build)
  message("${Green}>> ${PROJECT_NAME}: googletest configured <<${ColourReset}")
endif()

# Add GTest subdirectories if CMake was invoked from here
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
  add_subdirectory(${GTestDownloadDir}/googletest-src
                   ${GTestDownloadDir}/googletest-build
                   EXCLUDE_FROM_ALL)
endif()

# Set source file lists (must run cmake .. after new file addition)
file(GLOB_RECURSE SRC_LIST RELATIVE ${ProjectDir} "src/*.cpp")
file(GLOB_RECURSE TEST_SRC_LIST RELATIVE ${ProjectDir} "tests/*.cpp")

# Compile library from source list
include_directories(src)
add_library(${PROJECT_NAME}-lib ${SRC_LIST})
# target_compile_options(${PROJECT_NAME}-lib PUBLIC -Wall -Wextra -Werror -Wpedantic -Wconversion -Wsign-conversion)

# Build main if main.cpp exists
if(EXISTS ${ProjectDir}/main.cpp)
  add_executable(${PROJECT_NAME} main.cpp)
  # target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wextra -Werror -Wpedantic -Wconversion -Wsign-conversion)
  target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib pthread)
endif()

# Build unit tests
add_executable(${PROJECT_NAME}-ut ${TEST_SRC_LIST})
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib gtest_main)
# target_compile_options(${PROJECT_NAME}-ut PUBLIC -Wall -Wextra -Werror -Wpedantic -Wconversion -Wsign-conversion)

# Configure ctest
enable_testing()
add_test(NAME ${PROJECT_NAME}Tests COMMAND ${PROJECT_NAME}-ut)

## >> Use target_link_libraries instead << ##
## link_libraries(gmock)                   ##
## link_libraries(gtest_main)              ##
