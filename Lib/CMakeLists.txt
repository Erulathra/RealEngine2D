project(Lib)


find_package(spdlog REQUIRED)
find_package(SDL2 REQUIRED)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

include_directories(${SDL2_INCLUDE_DIRS})


# Add source files
file(GLOB_RECURSE SOURCE_FILES
        *.c
        *.cpp)

# Add header files
file(GLOB_RECURSE HEADER_FILES
        *.h
        *.hpp)

add_library(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} Eigen3::Eigen spdlog::spdlog)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)
