# SPDX-License-Identifier: MIT
# SPDX-Author: Roman Koch <koch.romam@gmail.com>
# SPDX-Copyright: 2024 Roman Koch <koch.romam@gmail.com>

cmake_minimum_required(VERSION 3.10)

project(da)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

set(SOURCES
    ${SRC_DIR}/heartbeat/application_heartbeat.cpp
)

set(HEADERS
    ${SRC_DIR}/heartbeat/application_heartbeat.hpp
)

set(INCLUDE_DIRS
    ${SRC_DIR}
    ${SRC_DIR}/heartbeat
)

add_executable(heartbeat ${SRC_DIR}/heartbeat.cpp ${SOURCES} ${HEADERS})
target_include_directories(heartbeat PRIVATE ${INCLUDE_DIRS})

set(CMAKE_INSTALL_PREFIX "/usr")

install(TARGETS heartbeat
    RUNTIME DESTINATION bin
    #LIBRARY DESTINATION lib
    #ARCHIVE DESTINATION lib
)
