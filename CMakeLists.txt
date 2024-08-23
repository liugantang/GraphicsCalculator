cmake_minimum_required(VERSION 3.30)
project(GraphicCalculator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/usr/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Charts
        REQUIRED)

add_executable(GraphicCalculator main.cpp
        MainWindow.cpp
        MainWindow.h
        MainWindowPrivate.h
        DrawPanel.cpp
        DrawPanel.h
        DrawPanelPrivate.h
        LinerArgumentsGenerator.cpp
        LinerArgumentsGenerator.h
        LinerArgumentsGeneratorPrivate.h
        FunctionDefinitions.h)
target_link_libraries(GraphicCalculator
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Charts
)

