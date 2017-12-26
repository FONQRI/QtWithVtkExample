#cmake file version 1.0
#author behnam sabaghi
#change time 22 / 7 / 96


cmake_minimum_required(VERSION 2.8)

PROJECT(QtWithVtkExample)


set(CMAKE_PREFIX_PATH "$ENV{QTDIR}")


#project files
file(GLOB coreheaders ./src/*.h)
file(GLOB corecpps ./src/*.cpp)


#set library pathes 
set(CMAKE_BUILD_TYPE Release)



#find pakages
find_package(VTK REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

#working*************** unix
if(UNIX)

    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
    set(CMAKE_AUTOMOC ON)



endif(UNIX)

#working*************** unix

#set configs
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

#includes
include_directories(
    ./src
    ${VTK_INCLUDE_DIRS}
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Gui_INCLUDE_DIRS}
    ${QT_INCLUDE_DIR}
    )
include(${VTK_USE_FILE} ${QT_USE_FILE})



#executable
add_executable(${PROJECT_NAME} MACOSX_BUNDLE main.cpp
    ${VTK_USE_FILE}
    ${coreheaders}
    ${corecpps}


    )

#linking
        target_link_libraries(${PROJECT_NAME}
            Qt5::Core
            Qt5::Widgets



           ${VTK_LIBRARIES}
         
            )


