include_directories(${cpp-fractal_SOURCE_DIR}/libs/include)
include_directories(${cpp-fractal_SOURCE_DIR}/main/include)

FILE(GLOB SOURCES *.cpp)

add_executable(cpp-fractal ${SOURCES})

target_link_libraries(cpp-fractal libs)