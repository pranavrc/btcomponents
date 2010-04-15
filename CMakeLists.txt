project(btcomponents)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_INSTALL_PREFIX}/share/kde4/apps/cmake/modules/)

find_package(Qt4 REQUIRED)
find_package(GluonCore REQUIRED)
find_package(GluonEngine REQUIRED)

set(_Init_LIB_SUFFIX "")
if ("${QT_QTCORE_LIBRARY}" MATCHES lib64)
   set(_Init_LIB_SUFFIX 64)
endif ("${QT_QTCORE_LIBRARY}" MATCHES lib64)
if ("${QT_QTCORE_LIBRARY}" MATCHES lib32)
   set(_Init_LIB_SUFFIX 32)
endif ("${QT_QTCORE_LIBRARY}" MATCHES lib32)

set(LIB_SUFFIX		    ${_Init_LIB_SUFFIX} CACHE STRING "The suffix of the system-wide library path")
set(LIB_INSTALL_DIR         ${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}    CACHE PATH "The subdirectory relative to the install prefix where libraries will be installed.")

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ${PROJECT_SOURCE_DIR} ${GLUON_ENGINE_INCLUDES} ${GLUON_CORE_INCLUDES})

set(btAsset_SRCS
    src/assetprivate.cpp
    src/asset.cpp
    )

set(treeAsset_SRCS
    src/treeprivate.cpp
    src/tree.cpp
    )

set(characterComponent_SRCS
	src/characterprivate.cpp
	src/character.cpp
	src/btcharacterscriptable.cpp
    src/btnodescriptable.cpp
    )

set(viewConeComponent_SRCS
	src/viewcone.cpp
	src/viewconeprivate.cpp
   )

set(perceptionAtomComponent_SRCS
	src/perceptionatom.cpp
	src/perceptionatomprivate.cpp
   )

set(perceptionInfoComponent_SRCS
	src/perceptioninfo.cpp
	src/perceptioninfoprivate.cpp
	src/btperceptioninfoscriptable.cpp
   )

qt4_automoc(
	${btAsset_SRCS} 
	${treeAsset_SRCS} 
	${characterComponent_SRCS} 
	${viewConeComponent_SRCS} 
	${perceptionAtomComponent_SRCS} 
	${perceptionInfoComponent_SRCS}
	)

find_library(LIBBT
    NAMES
        libbtlib.so
    PATHS
        c:/repo/gluon-bt/src/gluon-bt-lib/qtcreator-build/
        /usr/lib
        /usr/lib64
)
message("-- Found libbtlib:" ${LIBBT})

find_path(LIBBTPATH
    NAMES
        libbtlib.so
    PATHS
        c:/repo/gluon-bt/src/gluon-bt-lib/qtcreator-build/
        /usr/lib
        /usr/lib64
)
message("-- Found libbt's path:" ${LIBBTPATH})

add_library(btlib SHARED IMPORTED)
set_property(TARGET btlib PROPERTY IMPORTED_LOCATION ${LIBBT})
set_property(TARGET btlib PROPERTY IMPORTED_IMPLIB ${LIBBT})

find_library(LIBSCRIPTASSET
    NAMES
        libgluon_asset_script.so
    PATHS
        c:/repo/gluon-bt/src/gluon-bt-lib/qtcreator-build/
        /usr/lib/gluon
        /usr/lib64/gluon
)
message("-- Found libgluon_asset_script:" ${LIBSCRIPTASSET})

find_path(LIBSCRIPTASSETPATH
    NAMES
        libgluon_asset_script.so
    PATHS
        c:/repo/gluon-bt/src/gluon-bt-lib/qtcreator-build/
        /usr/lib/gluon
        /usr/lib64/gluon
)
message("-- Found libgluon_asset_script's path:" ${LIBBTPATH})

add_library(scriptasset SHARED IMPORTED)
set_property(TARGET scriptasset PROPERTY IMPORTED_LOCATION ${LIBSCRIPTASSET})
set_property(TARGET scriptasset PROPERTY IMPORTED_IMPLIB ${LIBSCRIPTASSET})

add_definitions(-DMAKE_BTCOMPONENT_LIB)
add_definitions(-DMAKE_GLUON_LIB)

ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

add_library(gluon_plugin_asset_behaviortree_sub SHARED ${treeAsset_SRCS})
target_link_libraries(gluon_plugin_asset_behaviortree_sub ${QT_QTCORE_LIBRARY} ${GLUON_CORE_LIBS} ${GLUON_ENGINE_LIBS} btlib)

add_library(gluon_plugin_asset_behaviortree SHARED ${btAsset_SRCS})
target_link_libraries(gluon_plugin_asset_behaviortree ${QT_QTCORE_LIBRARY} ${GLUON_CORE_LIBS} ${GLUON_ENGINE_LIBS} btlib gluon_plugin_asset_behaviortree_sub)

add_library(gluon_plugin_component_behaviortree SHARED ${characterComponent_SRCS})
target_link_libraries(gluon_plugin_component_behaviortree ${QT_QTCORE_LIBRARY} ${GLUON_CORE_LIBS} ${GLUON_ENGINE_LIBS} btlib gluon_plugin_asset_behaviortree_sub scriptasset)

add_library(gluon_plugin_component_viewcone SHARED ${viewConeComponent_SRCS})
target_link_libraries(gluon_plugin_component_viewcone ${QT_QTCORE_LIBRARY} ${GLUON_CORE_LIBS} ${GLUON_ENGINE_LIBS} btlib gluon_plugin_component_behaviortree)

add_library(gluon_plugin_component_perceptionatom SHARED ${perceptionAtomComponent_SRCS})
target_link_libraries(gluon_plugin_component_perceptionatom ${QT_QTCORE_LIBRARY} ${GLUON_CORE_LIBS} ${GLUON_ENGINE_LIBS} btlib gluon_plugin_component_behaviortree)

add_library(gluon_plugin_component_perceptioninfo SHARED ${perceptionInfoComponent_SRCS})
target_link_libraries(gluon_plugin_component_perceptioninfo ${QT_QTCORE_LIBRARY} ${QT_QTSCRIPT_LIBRARY} ${GLUON_CORE_LIBS} ${GLUON_ENGINE_LIBS} btlib gluon_plugin_component_behaviortree)

install(
    TARGETS
    gluon_plugin_asset_behaviortree
    gluon_plugin_asset_behaviortree_sub
    gluon_plugin_component_behaviortree
	gluon_plugin_component_viewcone
	gluon_plugin_component_perceptionatom
	gluon_plugin_component_perceptioninfo
    DESTINATION ${LIB_INSTALL_DIR}
)

add_subdirectory(testapp)
