cmake_minimum_required(VERSION 3.2)


#init project version and name
SET(PROJECT_BUILD_NUMBER "999")

IF(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    SET(PROJECT_BUILD_NUMBER $ENV{TRAVIS_BUILD_NUMBER})
ENDIF()

file (STRINGS ".version" PROJECT_VERSION)
file (STRINGS ".project_name" PROJECT_NAME)

#init project
project (${PROJECT_NAME} VERSION ${PROJECT_VERSION}.${PROJECT_BUILD_NUMBER})


#set compiler global options
set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )


#global settings
include_directories("${CMAKE_SOURCE_DIR}/src/include")

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-parameter")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_subdirectory(src)

