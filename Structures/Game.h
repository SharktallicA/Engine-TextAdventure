/*
    Loaded game data
    Khalid Ali 2019
    http://khalidali.co.uk
*/

#ifndef ENGINE_TEXTADVENTURE_GAME_H
#define ENGINE_TEXTADVENTURE_GAME_H

#include <vector>
#include "Place.h"

using namespace std;

//Encapsulates data loaded from game XML file
class Game
{
public:
    ~Game(void) { delete start; }

    //Name of game
    string gameName;
    //Name of player travel method
    string travelMethod;
    //Name of map distance unity
    string distanceUnit;

    //Pointer to map via starting area
    Place* start;

    //Array of possible enemies that the game can use
    //vector<Enemy> possibleEnemies;
};

#endif //ENGINE_TEXTADVENTURE_GAME_H