/*
    Place data transport class
    Khalid Ali 2019
    http://khalidali.co.uk
*/

#ifndef ENGINE_TEXTADVENTURE_PLACECHANGEDATA_H
#define ENGINE_TEXTADVENTURE_PLACECHANGEDATA_H

class Place;

//Allows storage and transportation of place object and its cost of travel
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
    ~PlaceData(void) { delete place; }
};

#endif //ENGINE_TEXTADVENTURE_PLACECHANGEDATA_H