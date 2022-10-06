# Set the project name
project (Lib)

find_package(SDL2 REQUIRED)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${SDL2_INCLUDE_DIRS})
# Add a library with the above sources
add_library(${PROJECT_NAME} src/Engine/MainEngine.cpp src/Engine/Actor.cpp include/Engine/Actor.h)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_link_libraries (${PROJECT_NAME} Eigen3::Eigen)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
