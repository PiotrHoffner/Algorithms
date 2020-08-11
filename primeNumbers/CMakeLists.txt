cmake_minimum_required(VERSION 3.10)

# Set up project-name variable
project(PrimeNumbers)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set up shortcut-variables for directories
set(GTestDownloadDir ${CMAKE_CURRENT_SOURCE_DIR}/../_gtest/googletest-download)
set(MainDir ${CMAKE_CURRENT_SOURCE_DIR}/..)

# Set coloured message variables
string(ASCII 27 Esc)
set(Yellow "${Esc}[1;33m")
set(Green "${Esc}[1;32m")
set(ColourReset "${Esc}[m")

message("${Green}>> ${PROJECT_NAME}: started CMakeLists.txt <<${ColourReset}")

# Download and configure googletest if not found
if(NOT EXISTS ${GTestDownloadDir})
  message("${Yellow}>> ${PROJECT_NAME}: googletest-download dir not found. Configuring /googletest/CMakeLists.txt <<${ColourReset}")
  execute_process(COMMAND mkdir -p build WORKING_DIRECTORY ${MainDir}/googletest)
  add_subdirectory(${MainDir}/googletest ${MainDir}/googletest/build)
  message("${Green}>> ${PROJECT_NAME}: googletest configured <<${ColourReset}")
endif()

# Add subdirectory if CMake was invoked here
if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
  add_subdirectory(${GTestDownloadDir}/googletest-src
                   ${GTestDownloadDir}/googletest-build
                   EXCLUDE_FROM_ALL)
endif()

# Set source list
set(SRC_LIST GenPrimeNumbers.cpp IsPrimeNumber.cpp)
set(TEST_SRC_LIST GenPrimeNumbersTests.cpp
                  IsPrimeNumberTests.cpp)

## target_include_directories(src)

# compile library from source list
add_library(${PROJECT_NAME}-lib ${SRC_LIST})
target_compile_options(${PROJECT_NAME}-lib PUBLIC -Wall -Wextra -Werror -Wpedantic -Wconversion -Wsign-conversion)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wextra -Werror -Wpedantic -Wconversion -Wsign-conversion)

# Link library to main
if(UNIX)
  target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib pthread)
else(UNIX)
  target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
endif(UNIX)

link_libraries(gmock)
## link_libraries(gtest_main)

# UT binary related options
add_executable(${PROJECT_NAME}-ut ${TEST_SRC_LIST})
target_compile_options(${PROJECT_NAME}-ut PUBLIC -Wall -Wextra -Werror -Wpedantic -Wconversion -Wsign-conversion)
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib gtest_main)

# ctest related options
enable_testing()
add_test(NAME ${PROJECT_NAME}Tests COMMAND ${PROJECT_NAME}-ut)
