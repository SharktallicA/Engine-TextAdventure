/*
    Place data transportation
    Khalid Ali 2019
    http://khalidali.co.uk
*/

#ifndef ENGINE_TEXTADVENTURE_PLACECHANGEDATA_H
#define ENGINE_TEXTADVENTURE_PLACECHANGEDATA_H

class Place;

//Allows a given Place at its relative travel-to cost
//to be encapsulated and transported
class PlaceData
{
public:
    Place* place = nullptr;
    int cost = 0;

    PlaceData(Place* nPlace, int nCost)
    {
        place = nPlace;
        cost = nCost;
    }
};

#endif //ENGINE_TEXTADVENTURE_PLACECHANGEDATA_H