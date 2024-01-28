cmake_minimum_required(VERSION 3.14)

project(flush_close LANGUAGES CXX DESCRIPTION "QFile flush vs close" VERSION 0.1.0.0)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

qt_add_executable(${PROJECT_NAME}
  main.cpp
)

target_include_directories( ${PROJECT_NAME} PUBLIC
)

target_link_libraries(${PROJECT_NAME} PUBLIC Qt::Core)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION /usr/bin)
