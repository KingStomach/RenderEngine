project (RenderApplication)

find_package(OpenGL REQUIRED)
message("OpenGL found: ${OpenGL_FOUND}")

include_directories("${PROJECT_SOURCE_DIR}/include")
add_library(${PROJECT_NAME} "source/GameApplication.cpp" "source/Winodw.cpp")

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glad)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

message("glad found: ${GLAD_INCLUDE_DIR}")
message("glfw found: ${GLFW_INCLUDE_DIR}")

target_include_directories(${PROJECT_NAME} PUBLIC ${GLAD_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${GLFW_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${RENDER_TOOL_INCLUDE_DIR})