
set(SRC_DIR ${PROJECT_SOURCE_DIR}/Src)

set(TEST_LIB TEST_LIB)

# empty Example
file (GLOB Empty_SOURCE_EXAMPLE
    
    )
set(Example_Empty Example_Empty)
add_executable(${Example_Empty} ${Empty_SOURCE_EXAMPLE} ./Example_Empty.cpp )
link_directories(${PROJECT_SOURCE_DIR}/Bin)
target_include_directories(${Example_Empty} PRIVATE ${SRC_DIR}  ${PROJECT_SOURCE_DIR}/Include)
target_link_libraries(${Example_Empty}  PRIVATE TEST_LIB)

message(TEST_LIB="${TEST_LIB}")