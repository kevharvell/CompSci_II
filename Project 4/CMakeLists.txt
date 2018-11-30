cmake_minimum_required(VERSION 3.10)
project(Project_4)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project_4 main.cpp InputValidation.hpp InputValidation.cpp Menu.hpp Menu.cpp Barbarian.cpp Barbarian.hpp BlueMen.cpp BlueMen.hpp
        Character.hpp Character.cpp Die.cpp Die.hpp HarryPotter.cpp HarryPotter.hpp List.cpp List.hpp Medusa.cpp Medusa.hpp Vampire.cpp Vampire.hpp Game.cpp Game.hpp)