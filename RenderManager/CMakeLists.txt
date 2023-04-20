project (RenderManager)

set(RENDER_MANAGER_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include" CACHE STRING INTERNAL FORCE)

find_package(OpenGL REQUIRED)
message("OpenGL found: ${OpenGL_FOUND}")

include_directories("${PROJECT_SOURCE_DIR}/include")
aux_source_directory("${PROJECT_SOURCE_DIR}/source" DIR_SRCS)
add_library(${PROJECT_NAME} ${DIR_SRCS})

message("glad found: ${GLAD_INCLUDE_DIR}")
message("glfw found: ${GLFW_INCLUDE_DIR}")
message("Render Tool found: ${RENDER_TOOL_INCLUDE_DIR}")

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glad)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

target_include_directories(${PROJECT_NAME} PUBLIC ${GLAD_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${GLFW_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${RENDER_TOOL_INCLUDE_DIR})