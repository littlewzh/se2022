cmake_minimum_required(VERSION 3.5)

project(verifyapp LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_PREFIX_PATH "/home/wzh/Qt5.14.2/5.14.2/gcc_64")
find_package(Qt5 COMPONENTS Widgets REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/src)
aux_source_directory(src SRC_LIST)
add_executable(verifyapp
    main.cpp
    ${SRC_LIST}
)
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
target_link_libraries(verifyapp PRIVATE Qt5::Widgets)


