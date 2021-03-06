/*
    Location data encapsulation
    Khalid Ali 2019
    http://khalidali.co.uk
*/

#ifndef ENGINE_TEXTADVENTURE_PLACE_H
#define ENGINE_TEXTADVENTURE_PLACE_H

#include <string>
#include <vector>
#include "PlaceData.h"

using namespace std;

//Possible directions of travel
enum Direction { North = 0, East = 1, South = 2, West = 3 };

//Encapsulates data needed to define a place and its position on the map
class Place
{
private:
    //Place's name (duh)
    string name = "";

    //Linked-list map hardpoints (order: N, E, S, W)
    vector<PlaceData*> adjs;

public:
    Place(string nName)
    {
        adjs = vector<PlaceData*>(4);
        name = nName;
    }

    //Defines the layout of places adjacent to this place
    void MapPlaces(PlaceData* n, PlaceData* e, PlaceData* s, PlaceData* w)
    {
        //Remapping places should not be allowed
        if (adjs[0] || adjs[1] || adjs[2] || adjs[3])
            throw "ILLEGAL CALL: adjacent Places in " + name + " already mapped!";

        adjs[0] = n;
        adjs[1] = e;
        adjs[2] = s;
        adjs[3] = w;
    }

    //Returns this place's name
    string GetName(void) { return name; }

    //Returns this place's neighbours as a one-line string
    string GetNeighbours()
    {
        string result = name + "'s neighbours: ";

        if (adjs[0]) result += "(N) " + adjs[0]->place->GetName() + " ";
        if (adjs[1]) result += "(E) " + adjs[1]->place->GetName() + " ";
        if (adjs[2]) result += "(S) " + adjs[2]->place->GetName() + " ";
        if (adjs[3]) result += "(W) " + adjs[3]->place->GetName() + " ";

        return result;
    }

    //Returns data pertaining to neighbour at given direction
    PlaceData* GoTo(Direction dir) { return adjs[dir]; }
};

#endif //ENGINE_TEXTADVENTURE_PLACE_H