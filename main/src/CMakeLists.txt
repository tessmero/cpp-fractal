include_directories(${cpp-fractal_SOURCE_DIR}/libs/include)
include_directories(${cpp-fractal_SOURCE_DIR}/main/include)

set(SOURCES
    main.cpp
    graphics.cpp
    fractal.cpp
)

add_executable(cpp-fractal ${SOURCES})

target_link_libraries(cpp-fractal libs)