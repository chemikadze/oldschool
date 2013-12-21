project(cmakeqtgui)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(cmakeqtgui_SRCS cmakeqtgui.cpp main.cpp)
qt4_automoc(${cmakeqtgui_SRCS})
add_executable(cmakeqtgui ${cmakeqtgui_SRCS})
target_link_libraries(cmakeqtgui ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
