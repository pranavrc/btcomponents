project(btcomponents-testapp)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_INSTALL_PREFIX}/share/kde4/apps/cmake/modules/)

find_package(Qt4 REQUIRED)
find_package(GluonCommon)
find_package(Gluon)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ${GLUON_INCLUDES})

set(btcomponents-testapp_SRCS btcomponents-testapp.cpp main.cpp)
qt4_automoc(${btcomponents-testapp_SRCS})
add_executable(btcomponents-testapp ${btcomponents-testapp_SRCS})
target_link_libraries(btcomponents-testapp ${GLUON_LIBRARY} ${QT_QTCORE_LIBRARY})
