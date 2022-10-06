# Set the project name
project (Lib)

find_package(SDL2 REQUIRED)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

include_directories(${SDL2_INCLUDE_DIRS})

add_library(${PROJECT_NAME} src/Engine/MainEngine.cpp src/Engine/Actor.cpp include/Engine/Actor.h src/Engine/SinusMovingActor.cpp include/Engine/SinusMovingActor.h)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} Eigen3::Eigen)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
