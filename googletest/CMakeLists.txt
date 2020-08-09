cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set coloured message variables
string(ASCII 27 Esc)
set(Yellow "${Esc}[1;33m")
set(Green "${Esc}[1;32m")
set(ColourReset "${Esc}[m")

# Set gtest standalone directory
set(GTestDir ${CMAKE_CURRENT_SOURCE_DIR}/../_gtest)

# Make gtest directory
if(NOT EXISTS ${GTestDir})
  message("${Yellow}>> googletest: _gtest dir has not been found <<${ColourReset}")
  execute_process(COMMAND mkdir ${GTestDir})
  execute_process(COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt.in ${GTestDir}/CMakeLists.txt.in)
  message("${Green}>> googletest: _gtest dir has been created <<${ColourReset}")
  message("${Green}>> googletest: CMakeLists.txt.in has been copied <<${ColourReset}")
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
