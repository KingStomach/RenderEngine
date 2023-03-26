include_directories("${RE_APPLICATION_DIR}/include")
include_directories("${RE_MODULES_MANAGER_DIR}/include")
#include_directories("${RE_RENDER_MANAGER_DIR}/include")

MESSAGE("project path:" ${PROJECT_SOURCE_DIR})
MESSAGE("ModuleManager path:" ${RE_MODULES_MANAGER_DIR})
MESSAGE("RenderManager path:" ${RE_RENDER_MANAGER_DIR})

add_library(ModuleManager ModuleManager.cpp ModuleCommand.cpp)
target_link_libraries(ModuleManager RenderManager)
target_include_directories(ModuleManager PUBLIC "${RE_RENDER_MANAGER_DIR}/include")