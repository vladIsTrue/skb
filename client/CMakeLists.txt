cmake_minimum_required(VERSION 3.16)

project(client VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets SvgWidgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets SvgWidgets Network)

set(PROJECT_SOURCES
    mainwindow.h mainwindow.cpp mainwindow.ui
    aspectratiowidget.h aspectratiowidget.cpp
    crosshairitem.h crosshairitem.cpp
    network.h network.cpp

    main.cpp

    svg/svg.qrc
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    svgcrosshair.h svgcrosshair.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                              Qt${QT_VERSION_MAJOR}::SvgWidgets
                                              Qt${QT_VERSION_MAJOR}::Network)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
