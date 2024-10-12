cmake_minimum_required(VERSION 3.16)

project(cpp-be VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()
qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appcpp-be
    src/main.cpp
)

qt_add_qml_module(appcpp-be
    URI cpp-be
    VERSION 1.0
    QML_FILES
        src/Main.qml
    SOURCES
        src/main.h
        src/models/model.cpp
        src/models/model.h
        src/controllers/controller.cpp
        src/controllers/controller.h
        src/views/view.cpp
        src/views/view.h
    INCLUDE
        include/server.h
)








# find_package(Boost REQUIRED COMPONENTS filesystem)
# target_link_libraries(appcpp-be PRIVATE Boost::filesystem)


find_package(boost_filesystem REQUIRED CONFIG)
target_link_libraries(appcpp-be PRIVATE Boost::filesystem)


# find_package(Boost REQUIRED COMPONENTS system)
# target_link_libraries(appcpp-be PRIVATE Boost::system)



find_package(boost_system REQUIRED CONFIG)
target_link_libraries(appcpp-be PRIVATE Boost::system)





















find_package(asio REQUIRED CONFIG)
target_link_libraries(appcpp-be PRIVATE asio)

# find_package(OpenCV CONFIG REQUIRED)
# target_link_libraries(appcpp-be PRIVATE opencv_ml opencv_dnn opencv_core opencv_flann)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appcpp-be PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appcpp-be
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appcpp-be
    PRIVATE Qt6::Quick
    # PRIVATE asio::asio
)

include(GNUInstallDirs)
install(TARGETS appcpp-be
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
