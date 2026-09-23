cmake_minimum_required(VERSION 4.4.3)

# https://github.com/Kitware/CMake/blob/v4.4.3/Help/dev/experimental.rst
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "f35a9ac6-8463-4d38-8eec-5d6008153e7d")
set(CMAKE_CXX_MODULE_STD ON)
function(_add_executable target)
    add_executable(${target})
endfunction()

project(zombie_class VERSION 0.1 LANGUAGES CXX)

_add_executable(zombie_class)

target_compile_features(zombie_class PRIVATE cxx_std_23)

# C++ Modules support
target_sources(zombie_class
    PRIVATE
    zombie.h
    PRIVATE FILE_SET modules TYPE CXX_MODULES BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES
)

# Deployment settings
include(GNUInstallDirs)
set(CMAKE_INSTALL_PREFIX "/opt/zombie_class" CACHE PATH "Install path prefix" FORCE)
install(TARGETS zombie_class
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)























































#https://github.com/Kitware/CMake/blob/v4.2.3/Help/dev/experimental.rst
#####  下面的配置，让zombie_class链接部署到/opt/lib下面的libutils  #####
#target_include_directories(zombie_class PRIVATE /opt/include)  # -I /opt/utils/include 自定义头文件搜索路径
# target_link_directories(zombie_class PRIVATE /opt/utils/lib)  # -L /opt/utils/lib 设置链接路径
# target_link_libraries(zombie_class PRIVATE utils)             # -lutils           设置链接库名

# set_target_properties(zombie_class PROPERTIES
#     INSTALL_RPATH_USE_LINK_PATH  True                           # 使用链接路径作为安装文件的RPath，等价于"-Wl,-rpath=/opt/utils/lib"
# )

#add_library(zombie_class SHARED
#  utils.cpp
#)

#set_target_properties( zombie_class PROPERTIES
#    PUBLIC_HEADER utils.cppm
#    VERSION   2.5.1
#    SOVERSION 2
#    LIBRARY_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/lib"
#)

#install(TARGETS zombie_class
#    LIBRARY DESTINATION /opt/utils/lib
#    PUBLIC_HEADER DESTINATION  /opt/utils/modules
#)

#add_custom_command(TARGET zombie_class
#    POST_BUILD
#    COMMAND cmake --install "${CMAKE_CURRENT_BINARY_DIR}"
#)

# set(MODULE_LIB_DIR /opt/utils/)  # 模块库目录的设置
# set(ZOMBIE_CLASS_MODULE_FILES
#     ${MODULE_LIB_DIR}/utils.cppm          # 模块库的模块文件
#     math.cppm                             # 模块文件
# )
# source_group("zombie_class" FILES ${ZOMBIE_CLASS_MODULE_FILES})
#
# target_sources(zombie_class
#     PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES
#         BASE_DIRS   # 配置BASE_DIRS，用于组织构建输出目录，以便构建不同目录中(同名的)模块文件.
#             ${MODULE_LIB_DIR}
#             ${CMAKE_CURRENT_SOURCE_DIR}
#         FILES
#             ${ZOMBIE_CLASS_MODULE_FILES}
# )
