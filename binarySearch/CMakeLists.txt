cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GTestDownloadDir ${CMAKE_CURRENT_SOURCE_DIR}/../_gtest/googletest-download)

if(${CMAKE_SOURCE_DIR} MATCHES ${CMAKE_CURRENT_SOURCE_DIR})
  add_subdirectory(${GTestDownloadDir}/googletest-src
                   ${GTestDownloadDir}/googletest-build
                   EXCLUDE_FROM_ALL)
endif()

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(main binarySearch.cpp main.cpp)
add_executable(binarySearchTests binarySearch.cpp BSTests.cpp)
target_link_libraries(binarySearchTests gtest_main)
enable_testing()
add_test(NAME binarySearchTests COMMAND binarySearchTests)
