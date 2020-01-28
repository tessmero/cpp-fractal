include_directories(${cpp-fractal_SOURCE_DIR}/libs/include)
add_executable(cpp-fractal main.cpp)
target_link_libraries(cpp-fractal libs)