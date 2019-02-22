//
// Created by root on 19/02/19.
//

#ifndef ENGINE_TEXTADVENTURE_GAMELOADER_H
#define ENGINE_TEXTADVENTURE_GAMELOADER_H

#include "../Structures/Game.h"
#include "../pugixml/pugixml.hpp"

using namespace pugi;

class GameLoader
{
private:
    //
    xml_document doc;

    //Attempts to load game <Details> data from game file
    void loadGameData(void)
    {
        try
        {
            game = new Game;
            game->gameName = doc.child("Game").attribute("name").as_string();
            game->travelMethod = doc.child("Game").child("Details").child("TravelMethod").child_value();
            game->distanceUnit = doc.child("Game").child("Details").child("DistanceUnit").child_value();
        }
        catch(...) { throw "FATAL ERROR: cannot load <Details> from game file!"; }
    }

    //
    void loadMapData(void)
    {

    }

    //
    void loadEnemyData(void)
    {

    }

public:
    Game* game;

    GameLoader(string loc)
    {
        //Attempt XML document parse to see if we can proceed
        xml_parse_result rst = doc.load_file(loc.c_str());
        if (!rst) throw "FATAL ERROR: cannot load game file " + loc + "!";

        //Attempt load data from XML document
        loadGameData();
    }
};

#endif //ENGINE_TEXTADVENTURE_GAMELOADER_H