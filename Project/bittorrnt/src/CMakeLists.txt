FILE(GLOB_RECURSE DIR_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
SET(exe_name BitDownload.bin)
ADD_EXECUTABLE(${exe_name} ${DIR_SRCS})
TARGET_LINK_LIBRARIES(${exe_name} pthread curl)