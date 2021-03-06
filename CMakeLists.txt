cmake_minimum_required(VERSION 3.8)
project(FinalProject-DARKWHITE)

if (WIN32)
    set(FREEGLUT_INCLUDE_DIRS "C:/Program\ Files/Common\ Files/freeglut/include")
    set(FREEGLUT_LIBRARY_DIRS "C:/Program\ Files/Common\ Files/freeglut/lib")
endif (WIN32)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wno-deprecated -Werror=return-type")

find_package (OpenGL REQUIRED)

if (APPLE OR UNIX)
    find_package(GLUT REQUIRED)
endif (APPLE OR UNIX)

if (WIN32)
    include_directories(${OPENGL_INCLUDE_DIR}  ${FREEGLUT_INCLUDE_DIRS})
    link_directories(${FREEGLUT_LIBRARY_DIRS})
elseif (APPLE)
    include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})
elseif (UNIX)
    include_directories(${OPENGL_INCLUDE_DIR} ${FREEGLUT_INCLUDE_DIRS})
endif ()

file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )
add_executable(graphics ${SOURCE_FILES} healthBuff.cpp healthBuff.h circle.h circle.cpp rect.h rect.cpp shapes.h
        shapes.cpp Button.h Button.cpp mans.h mans.cpp background.cpp background.h building.cpp building.h zombie.cpp zombie.h Bullet.cpp Bullet.h)

if (WIN32)
    target_link_libraries (graphics ${OPENGL_LIBRARIES} freeglut)
elseif (APPLE OR UNIX)
    target_link_libraries (graphics ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
endif ()