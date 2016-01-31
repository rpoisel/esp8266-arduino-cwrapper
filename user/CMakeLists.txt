file(GLOB USER_LIB_SRC
    ${CMAKE_CURRENT_LIST_DIR}/*.c
    ${CMAKE_CURRENT_LIST_DIR}/*.cpp
)

add_library(user_code STATIC
    ${USER_LIB_SRC}
)

target_include_directories(user_code PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(user_code PUBLIC
    cwrapper
)
