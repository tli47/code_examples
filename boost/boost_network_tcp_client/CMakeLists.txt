cmake_minimum_required(VERSION 2.8)

project(boost_network_tcp_client)

set (BOOST_ROOT "c:/boost162")

find_package(Boost 1.62.0 REQUIRED COMPONENTS filesystem system)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} wsock32 ws2_32)
