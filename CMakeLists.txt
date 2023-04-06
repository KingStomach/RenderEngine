cmake_minimum_required (VERSION 3.3)
set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(RenderEngine)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_definitions(-DGAME_ENGINE_ASSERT_ENABLE)
endif()

add_subdirectory(Application)
add_subdirectory(External)
add_subdirectory(Tool)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} RenderApplication)

#add_subdirectory(ModuleManager)
#add_subdirectory(RenderManager)
#add_executable(RenderEngine "Application/main.cpp")
#target_link_libraries(RenderEngine Application ModuleManager)