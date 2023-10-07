
set(SRC_DIR     ${PROJECT_SOURCE_DIR}/Src)

# 动态库
file(GLOB TEST_LIB_SRC
    ${SRC_DIR}/Add.cpp
)
set(TEST_LIB TEST_LIB)
add_library(${TEST_LIB} SHARED ${SRC_DIR}/Add.cpp)#
target_include_directories(${TEST_LIB} PRIVATE ${SRC_DIR} ) 
target_link_libraries(${TEST_LIB} PRIVATE)
set_target_properties(${TEST_LIB} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Bin) # 设置当前库动态库输出路径
set_target_properties(${TEST_LIB} PROPERTIES DEBUG_POSTFIX "_d")

# 静态库
add_library(${TEST_LIB}_static STATIC ${SRC_DIR}/Add.cpp)#
target_include_directories(${TEST_LIB}_static PRIVATE ${SRC_DIR} ) 
set_target_properties(${TEST_LIB}_static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Lib) # 设置当前库静态库输出路径
set_target_properties(${TEST_LIB}_static PROPERTIES OUTPUT_NAME ${TEST_LIB})

file(GLOB LIB_INCLUDE_FILES
    ${SRC_DIR}/Add.h
)
file(COPY ${LIB_INCLUDE_FILES} DESTINATION ${PROJECT_SOURCE_DIR}/Include)
add_definitions(-D_EXPORTING)