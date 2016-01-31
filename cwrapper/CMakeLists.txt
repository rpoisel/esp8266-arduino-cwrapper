file(GLOB WRAPPER_LIB_SRC
    ${CMAKE_CURRENT_LIST_DIR}/*.c
    ${CMAKE_CURRENT_LIST_DIR}/*.cpp
    ${CMAKE_CURRENT_LIST_DIR}/internal/*.cpp
)

add_library(cwrapper STATIC
    ${WRAPPER_LIB_SRC}
)

target_include_directories(cwrapper PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_include_directories(cwrapper PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/internal
)

target_link_libraries(cwrapper PUBLIC
    arduino
    esp8266wifi
    esp8266webserver
    pubsubclient
)
