/*
    Game file XML parser class
    Khalid Ali 2019
    http://khalidali.co.uk
*/

#ifndef ENGINE_TEXTADVENTURE_GAMELOADER_H
#define ENGINE_TEXTADVENTURE_GAMELOADER_H

#include "../Structures/Game.h"
#include "../Structures/Place.h"
#include "../pugixml/pugixml.hpp"

using namespace pugi;

//Inteprets game file XML into a workable format
class GameLoader
{
private:
    //Loaded game XML file
    xml_document doc;

    //Attempts to load game <Details> data from game file
    void loadGameData(void)
    {
        try
        {
            //Initialise Game object and give it <Details> content
            game = new Game;
            game->gameName = doc.child("Game").attribute("name").as_string();
            game->travelMethod = doc.child("Game").child("Details").child("TravelMethod").child_value();
            game->distanceUnit = doc.child("Game").child("Details").child("DistanceUnit").child_value();
        }
        catch(...) { throw "FATAL ERROR: cannot load <Details> from game file!"; }
    }

    //Attempts to load game <Map> data from game file
    void loadMapData(void)
    {
        try
        {
            // 1) Construct basic place objects from traversing all XML Area notes,
            // using only the area's name for constructor purposes at this point

            vector<Place*> places;
            for (xml_node area = doc.child("Game").child("Area"); area; area = area.next_sibling("Area"))
                places.push_back(new Place(area.attribute("name").as_string()));

            // 2) Maps out the relative (north, east, south, west) adjacent places
            // for each Place object; for each Place object in places vector, use the raw
            // place data to find out the names of its neighbours and them link
            // their place objects into the current one (and repeat) until (an up to
            // four-way) doubly-linked list is formed

            //NOT WORKING: ported from Game-TextAdventure
            for (int i = 0; i < places.size(); i++)
            {
                vector<Place*> relativePlaces;

                //find and get the Place object adjacent to the current one
                for (int j = 1; j <= 4; j++)
                {
                    if (raw[i][j] != "-") //work out the relative Place if one is specified in the raw data
                    {
                        for (Place* place : places) if (place->GetName() == raw[i][j]) relativePlaces.push_back(place);
                    }
                    else relativePlaces.push_back(nullptr); //nullptr to represent blank wall
                }

                //call for the mapping of the places to form the linked bonds
                places[i]->MapPlaces(relativePlaces[0], relativePlaces[1], relativePlaces[2], relativePlaces[3]);
            }
        }
        catch(...) { throw "FATAL ERROR: cannot load <Map> from game file!"; }
    }

    //
    void loadEnemyData(void)
    {

    }

public:
    //
    Game* game;

    GameLoader(string loc)
    {
        //Attempt XML document parse to see if we can proceed
        xml_parse_result rst = doc.load_file(loc.c_str());
        if (!rst) throw "FATAL ERROR: cannot load game file " + loc + "!";

        //Attempt load data from XML document
        loadGameData();
        loadMapData();
    }
};

#endif //ENGINE_TEXTADVENTURE_GAMELOADER_H