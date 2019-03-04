cmake_minimum_required(VERSION 3.13)
project(Engine_TextAdventure)

set(CMAKE_CXX_STANDARD 14)

add_executable(Engine_TextAdventure main.cpp Utility.h Structures/Place.h Structures/PlaceData.h GameIO.h Structures/Game.h pugixml/pugixml.hpp pugixml/pugixml.cpp Menu.h)