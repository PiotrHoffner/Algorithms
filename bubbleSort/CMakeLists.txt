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

message("${Green}>> bubbleSort: started binarySearch CMakeLists.txt <<${ColourReset}")

if(NOT EXISTS ${GTestDownloadDir})
  message("${Yellow}>> bubbleSort: googletest-download dir not found. Configuring /googletest/CMakeLists.txt <<${ColourReset}")
  execute_process(COMMAND mkdir -p build WORKING_DIRECTORY ${MainDir}/googletest)
  add_subdirectory(${MainDir}/googletest ${MainDir}/googletest/build)
  message("${Green}>> bubbleSort: googletest configured <<${ColourReset}")
endif()

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
  add_subdirectory(${GTestDownloadDir}/googletest-src
                   ${GTestDownloadDir}/googletest-build
                   EXCLUDE_FROM_ALL)
endif()

add_executable(areEqual-ut areEqual.cpp areEqualTests.cpp)
add_executable(bubbleSort-ut areEqual bubbleSort.cpp bubbleSortTests.cpp)
target_link_libraries(areEqual-ut gtest_main)
target_link_libraries(bubbleSort-ut gtest_main)

enable_testing()
add_test(NAME areEqualTests COMMAND areEqual-ut)
add_test(NAME bubbleSortTests COMMAND bubbleSort-ut)
