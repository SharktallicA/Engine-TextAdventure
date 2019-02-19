//
// Created by root on 19/02/19.
//

#ifndef ENGINE_TEXTADVENTURE_GAMELOADER_H
#define ENGINE_TEXTADVENTURE_GAMELOADER_H

#include "../pugixml/pugixml.hpp"

using namespace std;
using namespace pugi;

class GameLoader
{
private:
    xml_document doc;

    bool loadGameData(void) { return false; }
    bool loadMapData(void) { return false; }
    bool loadEnemyData(void) { return false; }

public:
    GameLoader(string loc)
    {
        //Attempt XML document parse to see if we can proceed
        xml_parse_result rst = doc.load_file(loc.c_str());
        if (!result) throw "FATAL ERROR: cannot load game file " + loc + "!";

        //Attempt load data from XML document
        if (!loadGameData()) throw "FATAL ERROR: game <Details> data invalid!";
        if (!loadMapData()) throw "FATAL ERROR: game <Map> data invalid!";
        if (!loadEnemyData()) throw "FATAL ERROR: game <Enemy> data invalid!";
    }
};

#endif //ENGINE_TEXTADVENTURE_GAMELOADER_H