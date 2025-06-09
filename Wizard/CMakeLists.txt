cmake_minimum_required(VERSION 3.16)

project(Wizard LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Wizard main.cpp
    src/Collider.cpp src/Enemy.cpp src/Game.cpp src/GameSave.cpp src/Goblin.cpp src/Magic.cpp src/Platform.cpp src/Player.cpp
    include/Collider.h include/Enemy.h include/Game.h include/GameSave.h include/Goblin.h include/Magic.h include/Platform.h include/Player.h
    include/Collider.h include/Enemy.h include/Game.h include/GameSave.h include/Goblin.h include/Magic.h include/Menu.h include/MenuPause.h include/Platform.h include/Player.h include/Shot_Magic.h include/Trap.h
    include/Collider.h include/Enemy.h include/Game.h include/GameSave.h include/Goblin.h include/Magic.h include/Menu.h include/MenuPause.h include/Platform.h include/Player.h include/Shot_Magic.h include/Trap.h
    src/Collider.cpp src/Enemy.cpp src/Game.cpp src/GameSave.cpp src/Goblin.cpp src/Magic.cpp src/Menu.cpp src/MenuPause.cpp src/Platform.cpp src/Player.cpp src/Shot_Magic.cpp src/Trap.cpp
    include/Collider.h include/Enemy.h include/Game.h include/GameSave.h include/Goblin.h include/Magic.h include/Menu.h include/MenuPause.h include/Platform.h include/Player.h include/Shot_Magic.h include/Trap.h
    src/Shot_Magic.cpp
    include/Shot_Magic.h
    src/Trap.cpp
    include/Trap.h
    src/Menu.cpp
    include/Menu.h)

set(SFML_DIR "C:/Users/damia/OneDrive/Desktop/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1")
target_link_libraries(Wizard PRIVATE
        ${SFML_DIR}/lib/libsfml-audio.a
        ${SFML_DIR}/lib/libsfml-graphics.a
        ${SFML_DIR}/lib/libsfml-network.a
        ${SFML_DIR}/lib/libsfml-system.a
        ${SFML_DIR}/lib/libsfml-window.a)
target_include_directories(Wizard PRIVATE "${SFML_DIR}/include" "${CMAKE_SOURCE_DIR}/include")



include(GNUInstallDirs)
install(TARGETS Wizard
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


