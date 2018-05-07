cmake_minimum_required(VERSION 3.10)
project(PurpleRain)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v -stdlib=libc++")


# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2TTF REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIR} ${PROJECT_SOURCE_DIR}/sorce/headers)

find_library(SLD2 SDL2)
if (NOT SLD2)
    message(FATAL_ERROR "SLD2 not found")
endif ()
find_library(SDL2_IMAGE SDL2_image)
if (NOT SDL2_IMAGE)
    message(FATAL_ERROR "SDL2_IMAGE not found")
endif ()
if (NOT SDL2TTF_LIBRARY)
    message(FATAL_ERROR "SDL2TTF not found")
endif ()


set(SOURCE_FILES source/src/main.cpp source/headers/main.h source/headers/GameLoop.h source/headers/Scene.h source/src/Scene.cpp source/src/GameLoop.cpp source/headers/Rect.h source/src/Rect.cpp source/src/TextBox.cpp source/headers/TextBox.h)

add_executable(PurpleRain ${SOURCE_FILES})
target_link_libraries(PurpleRain ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2TTF_LIBRARY} ${SLD2} ${SDL2_IMAGE})



