# Set the project name
project (Lib)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
# Add a library with the above sources
add_library(${PROJECT_NAME} src/MainEngine.cpp )
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
