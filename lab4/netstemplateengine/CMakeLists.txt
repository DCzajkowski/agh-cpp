cmake_minimum_required(VERSION 2.8.4)
project(simpletemplateengine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(HEDEAR_FILES SimpleTemplateEngine.h)
set(SOURCE_FILES SimpleTemplateEngine.cpp)

include_directories("/usr/local/Cellar/boost/1.57.0/include/boost")

add_library(libsimpletemplateengine STATIC ${SOURCE_FILES})
target_include_directories(libsimpletemplateengine PUBLIC .)

add_executable(simpletemplateengine ${SOURCE_FILES} main.cpp)

target_link_libraries(simpletemplateengine libsimpletemplateengine)
