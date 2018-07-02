cmake_minimum_required(VERSION 3.5)

SET(CMAKE_BUILD_TYPE "Debug")  
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")  
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
add_definitions(-std=c++11)

#include_directories("/home/uestc/Software/gflags/install/include")
include_directories("/home/user/lua-5.3.4/install/include")
#link_directories("/home/uestc/Software/gflags/install/lib")
link_directories("/home/user/lua-5.3.4/install/lib")

project(handoverServer)

SET(LIB_NAME mylib)
SET(CMAKE_VERBOSE_MAKEFILE ON)    
#SET(ROOT_PATH ".")  
#SET(PROTO_DIR ${ROOT_PATH}/proto)

#find_package(Protobuf REQUIRED)

file(GLOB_RECURSE ALL_LIBRARY_HDRS "include/*.h")
file(GLOB_RECURSE ALL_LIBRARY_SRCS "src/*.cpp")


#file(GLOB_RECURSE ALL_PROTOS ${PROTO_DIR}/*.proto)

#set(ALL_PROTO_SRCS)
#set(ALL_PROTO_HDRS)

# foreach(ABS_FIL ${ALL_PROTOS})
  # file(RELATIVE_PATH REL_FIL ${PROJECT_SOURCE_DIR} ${ABS_FIL}) #PROJECT_SOURCE_DIR是工程的根目录
                                #FILE(RELATIVE_PATH variable directory file)
  # get_filename_component(DIR ${REL_FIL} DIRECTORY)
  # get_filename_component(FIL_WE ${REL_FIL} NAME_WE)

  # list(APPEND ALL_PROTO_SRCS "${PROJECT_BINARY_DIR}/${DIR}/${FIL_WE}.pb.cc")#添加新元素到列表
  # list(APPEND ALL_PROTO_HDRS "${PROJECT_BINARY_DIR}/${DIR}/${FIL_WE}.pb.h")
    message(STATUS "PROJECT_BINARY_DIR path : ${PROJECT_BINARY_DIR}") 
    message(STATUS "DIR path : ${DIR}")
    message(STATUS "FIL_WE : ${FIL_WE}")
    message(STATUS "PROTOBUF_PROTOC_EXECUTABLE : ${PROTOBUF_PROTOC_EXECUTABLE}")  
  # add_custom_command(
    # OUTPUT "${PROJECT_BINARY_DIR}/${DIR}/${FIL_WE}.pb.cc"
           # "${PROJECT_BINARY_DIR}/${DIR}/${FIL_WE}.pb.h"
    # COMMAND  ${PROTOBUF_PROTOC_EXECUTABLE}
    # ARGS --cpp_out  ${PROJECT_BINARY_DIR} -I
      # ${PROJECT_SOURCE_DIR} ${ABS_FIL}
    # DEPENDS ${ABS_FIL}
    # COMMENT "Running C++ protocol buffer compiler on ${ABS_FIL}"
    # VERBATIM
  # )
# endforeach()

# set_source_files_properties(${ALL_PROTO_SRCS} ${ALL_PROTO_HDRS} PROPERTIES GENERATED TRUE)
# list(APPEND ALL_LIBRARY_HDRS ${ALL_PROTO_HDRS})
# list(APPEND ALL_LIBRARY_SRCS ${ALL_PROTO_SRCS})
#message(STATUS "ALL_LIBRARY_HDRS : ${ALL_LIBRARY_HDRS}")
#message(STATUS "ALL_LIBRARY_SRCS : ${ALL_LIBRARY_SRCS}")


add_library(${LIB_NAME} STATIC ${ALL_LIBRARY_HDRS} ${ALL_LIBRARY_SRCS})

target_include_directories(${LIB_NAME} PUBLIC
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:include>
)
# target_link_libraries(${LIB_NAME} -lprotobuf)
# target_link_libraries(${LIB_NAME} -lglog)
target_link_libraries(${LIB_NAME} -llua)
 target_link_libraries(${LIB_NAME} -ldl)

#target_link_libraries(${LIB_NAME} -l:libprotobuf.a)
#target_link_libraries(${LIB_NAME} -l:libglog.a)

#aux_source_directory(. DIR_SRC)

file(GLOB_RECURSE ALL_EXECUTABLES "*_main.cpp")
#message(STATUS "ALL_EXECUTABLES : ${ALL_EXECUTABLES}")

add_executable(${PROJECT_NAME} ${ALL_EXECUTABLES})

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/>
)


TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${LIB_NAME})
# target_link_libraries(${PROJECT_NAME} -levent)
target_link_libraries(${PROJECT_NAME} -pthread)
# target_link_libraries(${PROJECT_NAME} -lglog)
# target_link_libraries(${PROJECT_NAME} gflags)


#target_link_libraries(${PROJECT_NAME} -l:libevent.a)
#target_link_libraries(${PROJECT_NAME} -l:libglog.a)




