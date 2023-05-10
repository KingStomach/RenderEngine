project (RenderEngine)

include_directories("${PROJECT_SOURCE_DIR}/include")
aux_source_directory("${PROJECT_SOURCE_DIR}/source" DIR_SRCS)

message("Render Manager found: ${RENDER_MANAGER_INCLUDE_DIR}")

add_executable(${PROJECT_NAME} ${DIR_SRCS})

target_link_libraries(${PROJECT_NAME} RenderManager)
target_include_directories(${PROJECT_NAME} PUBLIC ${RENDER_TOOL_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${RENDER_MANAGER_INCLUDE_DIR})