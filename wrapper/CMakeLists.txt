file(GLOB WRAPPER_LIB_SRC
    ${CMAKE_CURRENT_LIST_DIR}/*.c
    ${CMAKE_CURRENT_LIST_DIR}/*.cpp
)

add_library(wrapper STATIC
    ${WRAPPER_LIB_SRC}
)

target_include_directories(wrapper PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(wrapper PUBLIC
    arduino
)
