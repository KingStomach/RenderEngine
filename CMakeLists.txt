cmake_minimum_required (VERSION 3.1)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project (RenderEngine)
set(RE_APPLICATION_DIR "${PROJECT_SOURCE_DIR}/Application")
set(RE_MODULES_MANAGER_DIR "${PROJECT_SOURCE_DIR}/ModuleManager")
include_directories("${PROJECT_SOURCE_DIR}/Interface")
include_directories("${RE_MODULES_MANAGER_DIR}/include")
add_subdirectory(Application)
add_subdirectory(ModuleManager)
add_executable(RenderEngine main.cpp)
target_link_libraries(RenderEngine Application)
target_link_libraries(RenderEngine ModuleManager)