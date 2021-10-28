cmake_minimum_required(VERSION 3.10)
project(WXRandomPicker VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(SOURCE_FILES source/Main.cpp source/MainApp.cpp source/AppFrame.cpp)

find_package(wxWidgets REQUIRED)
include("${wxWidgets_USE_FILE}")

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${wxWidgets_LIBRARIES})

