string(REGEX MATCH "demo(.+)" D_NAME ${CMAKE_CURRENT_SOURCE_DIR})
aux_source_directory(. ${D_NAME}_SRCS)
include_directories(${UNZIP_INCLUDE_DIR})
add_nge_executable(${D_NAME} ${${D_NAME}_SRCS} LIBRARIES ${UNZIP_LIBRARIES})

add_resource(${D_NAME}_all_res fonts
  GBK14
  ASC14)
add_resource(${D_NAME}_all_res database
  data.zip)

copy_res_files(${D_NAME} ${${D_NAME}_all_res})
