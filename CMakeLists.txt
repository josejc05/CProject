cmake_minimum_required(VERSION 3.26)
project(ParkingSimulator C)

set(CMAKE_C_STANDARD 11)

add_executable(ParkingSimulator
        src/main.c
        src/game.c
        src/map.c
        src/vehicle.c
        src/list.c
        src/input.c
        src/ui.c
        src/sound.c
        src/utils.c
        src/main.c
)

target_include_directories(ParkingSimulator PRIVATE include)

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
