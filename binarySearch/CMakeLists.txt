cmake_minimum_required(VERSION 3.10)

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

message("${Green}>> binarySearch: started binarySearch CMakeLists.txt <<${ColourReset}")

# Download and configure googletest if not found
if(NOT EXISTS ${GTestDownloadDir})
  message("${Yellow}>> binarySearch: googletest-download dir not found. Configuring /googletest/CMakeLists.txt <<${ColourReset}")
  execute_process(COMMAND mkdir -p build WORKING_DIRECTORY ${MainDir}/googletest)
  add_subdirectory(${MainDir}/googletest ${MainDir}/googletest/build)
  message("${Green}>> binarySearch: googletest configured <<${ColourReset}")
endif()

# Add subdirectory if CMake was invoked here
if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
  add_subdirectory(${GTestDownloadDir}/googletest-src
                   ${GTestDownloadDir}/googletest-build
                   EXCLUDE_FROM_ALL)
endif()

# Now simply link against gtest or gtest_main as needed. 
# add_executable(main binarySearch.cpp main.cpp)
add_executable(binarySearchTests binarySearch.cpp BSTests.cpp)
target_link_libraries(binarySearchTests gtest_main)

enable_testing()
add_test(NAME binarySearchTests COMMAND binarySearchTests)
