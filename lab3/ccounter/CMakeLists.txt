
project(ccounter)

set(HEDEAR_FILES Ccounter.h)
set(SOURCE_FILES Ccounter.cpp)

add_library(libccounter STATIC ${SOURCE_FILES})
target_include_directories(libccounter PUBLIC .)

add_executable(ccounter ${SOURCE_FILES} main.cpp)

target_link_libraries(ccounter libccounter)

