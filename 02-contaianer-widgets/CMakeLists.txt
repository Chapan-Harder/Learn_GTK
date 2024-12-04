cmake_minimum_required(VERSION 3.30.3)
project(Contaianer_Widgets)

set(CMAKE_CXX_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)


include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(Contaianer_Widgets src/main.cpp)

target_link_libraries(Contaianer_Widgets ${GTK3_LIBRARIES})
