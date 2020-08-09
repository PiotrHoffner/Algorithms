cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GTestDir ${CMAKE_CURRENT_SOURCE_DIR}/../binarySearch/build)

if(${CMAKE_SOURCE_DIR} MATCHES ${CMAKE_CURRENT_SOURCE_DIR})
  add_subdirectory(${GTestDir}/googletest-src
                   ${GTestDir}/googletest-build
                   EXCLUDE_FROM_ALL)
endif()

add_executable(areEqual-ut areEqual.cpp areEqualTests.cpp)
add_executable(bubbleSort-ut areEqual bubbleSort.cpp bubbleSortTests.cpp)
target_link_libraries(areEqual-ut gtest_main)
target_link_libraries(bubbleSort-ut gtest_main)

enable_testing()
add_test(NAME areEqualTests COMMAND areEqual-ut)
add_test(NAME bubbleSortTests COMMAND bubbleSort-ut)
