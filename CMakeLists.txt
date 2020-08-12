cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set coloured message variables
string(ASCII 27 Esc)
set(Yellow "${Esc}[1;33m")
set(Green "${Esc}[1;32m")
set(ColourReset "${Esc}[m")

# Set up shortcut-variables for directories
set(GTestDownloadDir ${CMAKE_CURRENT_SOURCE_DIR}/_gtest/googletest-download)
set(MainDir ${CMAKE_CURRENT_SOURCE_DIR})

# Configure _gTest if not exists
if(NOT EXISTS ${GTestDownloadDir})
  message("${Yellow}>> Algorithms: _gtest dir has not been found <<${ColourReset}")
  add_subdirectory(${MainDir}/googletest)
  message("${Green}>> Algorithms: googletest has been configured <<${ColourReset}")
endif()

# Add subdirectory if CMake was invoked here
if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
  add_subdirectory(${GTestDownloadDir}/googletest-src
                   ${GTestDownloadDir}/googletest-build
                   EXCLUDE_FROM_ALL)
endif()

project(Algorithms)
add_subdirectory(binarySearch)
add_subdirectory(bubbleSort)
add_subdirectory(fibonacci)
add_subdirectory(nwd)
add_subdirectory(palindrome)
add_subdirectory(primeNumbers)
enable_testing()
