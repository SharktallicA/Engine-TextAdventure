/*
    Program TUI menu interface
    Khalid Ali 2019
    http://khalidali.co.uk
*/

#ifndef ENGINE_TEXTADVENTURE_MENU_H
#define ENGINE_TEXTADVENTURE_MENU_H

#include "GameIO.h"

//Enumerated possible commands the player can use
enum Command { GoNorth, GoEast, GoSouth, GoWest, ShowMap, Quit, ShowHelp, RetryInput };

//Text user interface for the program's operation
class Menu
{
private:
    //Instance of the game loading/writing utility
    GameIO ldr;

    //Instance of  currently loaded game
    Game* game;

    //Gets and interprets player input into an enumerated option
    Command getInput(void)
    {
        char input = toupper(Utility::getStr()[0]);

        if (input == 'N') return GoNorth;
        else if (input == 'E') return GoEast;
        else if (input == 'S') return GoSouth;
        else if (input == 'W') return GoWest;
        else if (input == 'M') return ShowMap;
        else if (input == 'H') return ShowHelp;
        else if (input == 'Q') return Quit;
        else return RetryInput;
    }

    //Prints out all possible commands at the player's disposal
    void printCmdList(bool showMap)
    {
        string cmds = "Command list: N-north, E-east, S-south, W-west,\n";
        cmds += "H-list commands, Q-quit";

        //if game allows map printing, add that too!
        if (showMap)
            cmds += ", M-show map";

        cout << cmds << endl << endl;
    }

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

            if (!game->current)
                throw "FATAL ERROR: cannot load game!";
        }
        catch(char* msg) { throw msg; }
    }

    //Program loop component
    bool Run(void)
    {
        //Print request for user command input
        cout << "You're at " << game->current->GetName() << "!" << endl;
        cout << "CMD: ";
        Command cmd = getInput();

        //Evaluate command's actions
        if (cmd == Quit) return false;
        else if (cmd == RetryInput)
            cout << "Invalid command!" << endl << endl;
        else if (cmd == ShowMap)
            cout << game->current->GetNeighbours() << endl << endl;
        else if (cmd == ShowHelp)
            printCmdList(true);
        else
        {
            PlaceData* next;

            if (cmd == GoNorth) next = game->current->GoTo(North);
            else if (cmd == GoEast) next = game->current->GoTo(East);
            else if (cmd == GoSouth) next = game->current->GoTo(South);
            else if (cmd == GoWest) next = game->current->GoTo(West);

            if (!next->place)
                cout << "There is nothing in that direction!" << endl << endl;
            else
            {
                cout << "You " << game->travelMethod << "ed " << next->cost << " " << game->distanceUnit << "s to " << next->place->GetName() << "!" << endl << endl;
                game->current = next->place;
            }
        }

        return true;
    }
};

#endif //ENGINE_TEXTADVENTURE_MENU_H