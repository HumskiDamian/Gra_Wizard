cmake_minimum_required(VERSION 3.16)

project(Gra LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Gra main.cpp
    src/Bonus.cpp src/Collider.cpp src/Collider_Platform.cpp src/Enemy.cpp src/Game.cpp src/GameSave.cpp src/Goblin.cpp src/Magic.cpp src/Menu.cpp src/Platform.cpp src/Player.cpp src/Shot_Magic.cpp src/Skeleton.cpp src/Trap.cpp
    include/Bonus.h include/Collider.h include/Collider_Platform.h include/Enemy.h include/Game.h include/GameSave.h include/Goblin.h include/Magic.h include/Menu.h include/Platform.h include/Player.h include/Shot_Magic.h include/Skeleton.h include/Trap.h
    Fonts/CalligraphyFLF.ttf Fonts/Fantasy Clipart.ttf Fonts/Fridays.ttf Fonts/halfelven.ttf Fonts/halfelven3d.ttf Fonts/halfelven3dital.ttf Fonts/halfelvenbold.ttf Fonts/halfelvenboldital.ttf Fonts/halfelvencond.ttf Fonts/halfelvencondital.ttf Fonts/halfelvenexpand.ttf Fonts/halfelvenexpandital.ttf Fonts/halfelvenital.ttf Fonts/halfelvenleft.ttf Fonts/IMMORTAL.ttf Fonts/IMMRTLT_.ttf
    image/fire.png image/fire1.png image/goblin.png image/las.jpg image/las1.jpg image/las2.jpg image/szkielet.png image/trap.jpg image/trawa.jpg image/trawa1.png image/water.png image/wizard.png image/wizard_1.png image/zamek.png)

set(SFML_DIR "C:/Users/damia/OneDrive/Desktop/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1")
target_link_libraries(Gra PRIVATE
        ${SFML_DIR}/lib/libsfml-audio.a
        ${SFML_DIR}/lib/libsfml-graphics.a
        ${SFML_DIR}/lib/libsfml-network.a
        ${SFML_DIR}/lib/libsfml-system.a
        ${SFML_DIR}/lib/libsfml-window.a)
    target_include_directories(Gra PRIVATE "${SFML_DIR}/include" "${CMAKE_SOURCE_DIR}/include")

include(GNUInstallDirs)
install(TARGETS Gra
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
