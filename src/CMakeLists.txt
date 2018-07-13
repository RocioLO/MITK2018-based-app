cmake_minimum_required(VERSION 3.8)

project(app)

#MITK
find_package(MITK REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake ${CMAKE_MODULE_PATH})
message(STATUS "Cmake modules in: " ${CMAKE_MODULE_PATH})

#find_package(Qt5Widgets REQUIRED)

include_directories( ${CMAKE_BINARY_DIR} )
#include_directories(${CTK_INCLUDE_DIRS})

include(mitkFunctionCheckCompilerFlags)
mitk_create_executable(${PROJECT_NAME} 
         DEPENDS MitkQtWidgets MitkQtWidgetsExt CppMicroServices
         MitkMapperExt MitkCore 
         PACKAGE_DEPENDS Qt5|Core Qt5|Widgets
         WARNINGS_NO_ERRORS
         )

install(TARGETS ${PROJECT_NAME}
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION bin
		)

