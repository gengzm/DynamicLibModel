
set(SRC_DIR     ${PROJECT_SOURCE_DIR}/Src)

# ��̬��
file(GLOB TEST_LIB_SRC
    ${SRC_DIR}/Add.cpp
)
set(TEST_LIB TEST_LIB)
add_library(${TEST_LIB} SHARED ${SRC_DIR}/Add.cpp)#
target_include_directories(${TEST_LIB} PRIVATE ${SRC_DIR} ) 
target_link_libraries(${TEST_LIB} PRIVATE)
set_target_properties(${TEST_LIB} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Bin) # ���õ�ǰ�⶯̬�����·��
set_target_properties(${TEST_LIB} PROPERTIES DEBUG_POSTFIX "_d")

# ��̬��
add_library(${TEST_LIB}_static STATIC ${SRC_DIR}/Add.cpp)#
target_include_directories(${TEST_LIB}_static PRIVATE ${SRC_DIR} ) 
set_target_properties(${TEST_LIB}_static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Lib) # ���õ�ǰ�⾲̬�����·��
set_target_properties(${TEST_LIB}_static PROPERTIES OUTPUT_NAME ${TEST_LIB})

file(GLOB LIB_INCLUDE_FILES
    ${SRC_DIR}/Add.h
)
file(COPY ${LIB_INCLUDE_FILES} DESTINATION ${PROJECT_SOURCE_DIR}/Include)
add_definitions(-D_EXPORTING)