cmake_minimum_required(VERSION 3.0.0)

project(pointSegment VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core)

find_package(VTK 8.1 REQUIRED)
find_package(PCL 1.9 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})


set(src_file
    main.cpp
    mainwindow.cpp
    meshhandler.cpp
    )
set(moc_file
    mainwindow.h
    meshhandler.h
    )
set(ui_file
    mainwindow.ui
    )

QT5_WRAP_CPP(moc_wrap   ${moc_file})
QT5_WRAP_UI(ui_wrap ${ui_file})

add_executable(${PROJECT_NAME} ${src_file} ${moc_wrap} ${ui_wrap})

target_link_libraries(${PROJECT_NAME} Qt5::Core ${PCL_LIBRARIES} ${VTK_LIBRARIES})
