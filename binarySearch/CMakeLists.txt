cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set gtest standalone directory
set(GTestDir ${CMAKE_CURRENT_SOURCE_DIR}/../_gtest)

# Make gtest directory
if(NOT EXISTS ${GTestDir})
  execute_process(COMMAND mkdir ${GTestDir})
  execute_process(COMMAND echo +++ _gtest dir has been created +++)
endif()

# Copy CMakeLists.txt.in gtest file to gtest directory
if(NOT EXISTS ${GTestDir}/CMakeLists.txt.in)
  execute_process(COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt.in ${GTestDir}/CMakeLists.txt.in)
  execute_process(COMMAND echo +++ CMakeLists.txt.in has been copied +++)  
endif()

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in ${GTestDir}/googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${GTestDir}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${GTestDir}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${GTestDir}/googletest-download/googletest-src
                 ${GTestDir}/googletest-download/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${GTestDir}/googletest-download/googletest-src/googletest/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(main binarySearch.cpp main.cpp)
add_executable(BSTests binarySearch.cpp BSTests.cpp)
target_link_libraries(BSTests gtest_main)
enable_testing()
add_test(NAME BSTests COMMAND BSTests)
