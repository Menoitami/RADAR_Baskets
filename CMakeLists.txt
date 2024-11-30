cmake_minimum_required(VERSION 3.5)

project(NoskovEvgeniy_CQtProgrammer_test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Basket/basket.h
        Basket/basket.cpp
        additional.h
        BasketWidget/basketwidget.cpp
        BasketWidget/basketwidget.h
        BasketWidget/basketwidget.ui
)

include_directories(
    Basket/
    BasketWidget/
    )

add_executable(BasketChance
    ${PROJECT_SOURCES}
)

target_link_libraries(BasketChance PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(BasketChance PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

option(BUILD_TESTING "Build unit tests" ON)

if(BUILD_TESTING)
    enable_testing()

    add_executable(tests tests/basket_test.cpp)

    # Добавление необходимых исходников и заголовочных файлов
    target_sources(tests PRIVATE
        Basket/basket.cpp
        additional.h
    )

    # Указываем директорию, где находятся заголовочные файлы
    target_include_directories(tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Basket
    )

    # Линкование с библиотеками Qt
    target_link_libraries(tests PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

    # Регистрация теста в CTest
    add_test(NAME MyTests COMMAND tests)

    # Запуск тестов после сборки
    add_custom_command(
        TARGET tests POST_BUILD
        COMMAND $<TARGET_FILE:tests>
    )
endif()
