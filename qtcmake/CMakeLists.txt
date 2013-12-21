project(qtcmake)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(qtcmake_SRCS qtcmake.cpp main.cpp)
qt4_automoc(${qtcmake_SRCS})
add_executable(qtcmake ${qtcmake_SRCS})
target_link_libraries(qtcmake ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
