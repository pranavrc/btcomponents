project(btcomponents)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_INSTALL_PREFIX}/share/kde4/apps/cmake/modules/)

find_package(Qt4 REQUIRED)
find_package(GluonCommon REQUIRED)
find_package(Gluon REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ${PROJECT_SOURCE_DIR} ${GLUON_INCLUDES})

set(btAsset_SRCS
    src/assetprivate.cpp
    src/asset.cpp
    )

set(resourceComponent_SRCS
    )

set(treeComponent_SRCS
    src/treeprivate.cpp
    src/tree.cpp
    )


qt4_automoc(${btAsset_SRCS} ${resourceComponent_SRCS} ${treeComponent_SRCS})

find_library(LIBBT
    NAMES
        libbtlib.so
    PATHS
        c:/repo/gluon-bt/src/gluon-bt-lib/qtcreator-build/ 
        /usr/lib
)
message("-- Found libbtlib:" ${LIBBT})

find_path(LIBBTPATH
    NAMES
        libbtlib.so
    PATHS
        c:/repo/gluon-bt/src/gluon-bt-lib/qtcreator-build/
        /usr/lib
)
message("-- Found libbt's path:" ${LIBBTPATH})

add_library(btlib SHARED IMPORTED)
set_property(TARGET btlib PROPERTY IMPORTED_LOCATION ${LIBBT})
set_property(TARGET btlib PROPERTY IMPORTED_IMPLIB ${LIBBT})

add_definitions(-DMAKE_BTCOMPONENT_LIB)

ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

add_library(asset_behaviortree SHARED ${btAsset_SRCS})
target_link_libraries(asset_behaviortree ${QT_QTCORE_LIBRARY} ${GLUON_LIBRARY} btlib)

#add_library(component_resource SHARED ${resourceComponent_SRCS})
#target_link_libraries(component_resource ${QT_QTCORE_LIBRARY} ${GLUON_LIBRARY} btlib)

add_library(component_behaviortree SHARED ${treeComponent_SRCS})
target_link_libraries(component_behaviortree ${QT_QTCORE_LIBRARY} ${GLUON_LIBRARY} btlib)
