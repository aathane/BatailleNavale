cmake_minimum_required(VERSION 3.19)
project(Projet_bataille_navale C)

set(CMAKE_C_STANDARD 99)

add_executable(Projet_bataille_navale main.c fonction.h grid.c show_grid.c Inventory.c Boat.c fire_artillery.c fire_bomb.c fire_tactical.c fire_simple.c is_alive.c grid_boat.c save.c load.c mode_active.c)