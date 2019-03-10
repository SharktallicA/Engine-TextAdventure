/*
    Loaded game data encapsulation
    Khalid Ali 2019
    http://khalidali.co.uk
*/

#ifndef ENGINE_TEXTADVENTURE_GAME_H
#define ENGINE_TEXTADVENTURE_GAME_H

#include <vector>
#include "Place.h"

using namespace std;

//Encapsulates data loaded from XML game file
class Game
{
public:
    ~Game(void) { delete current; }

    //Name of game
    string gameName;
    //Name of player travel method
    string travelMethod;
    //Name of map distance unity
    string distanceUnit;

    //Reference to the current area of the map:
    //When Game is initialised, this serves as the map starting point
    //When playing, it becomes the current location reference
    Place* current;

    //Array of possible enemies that the game can use
    //vector<Enemy> possibleEnemies;
};

#endif //ENGINE_TEXTADVENTURE_GAME_H