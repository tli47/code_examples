cmake_minimum_required(VERSION 2.8)

project(boost_network_udp_server)
set (BOOST_ROOT "c:/boost162")

find_package(Boost 1.62.0 REQUIRED COMPONENTS filesystem system)

#set (Boost_LIBRARIES "c:/boost162/lib")

if(Boost_FOUND)

    MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
    MESSAGE( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
    MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")

endif()


include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} wsock32 ws2_32)
