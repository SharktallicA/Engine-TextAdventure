/*
    Program menu functionality
    Khalid Ali 2019
    http://khalidali.co.uk
*/

#ifndef ENGINE_TEXTADVENTURE_MENU_H
#define ENGINE_TEXTADVENTURE_MENU_H

#include "GameIO.h"

//
class Menu
{
private:
    //
    GameIO ldr;

    //
    Game* game;

    //
    Place* current;

public:
    Menu(void)
    {
        try
        {
            cout << "Engine-TextAdventure" << endl;
            cout << "Khalid Ali 2019" << endl;
            cout << "http://khalidali.co.uk" << endl << endl;
            Utility::pause();
            //Utility::clear();

            game = ldr.LoadGame("../Examples/UE.xml");
            current = game->start;

            if (!current)
                throw "FATAL ERROR: cannot load game!";
        }
        catch(char* msg) { throw msg; }
    }

    bool Run(void)
    {
        return false;
    }
};

#endif //ENGINE_TEXTADVENTURE_MENU_H