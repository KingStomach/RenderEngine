include_directories("${RE_APPLICATION_DIR}/include")
include_directories("${RE_MODULES_MANAGER_DIR}/include")
add_library(ModuleManager ModuleManager.cpp)
target_link_libraries(ModuleManager Application)