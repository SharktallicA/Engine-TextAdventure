/*
    Engine-TextAdventure
    Khalid Ali 2019
    http://khalidali.co.uk
*/

#include "Utility.h"
#include "GameIO.h"

using namespace std;

int main(void)
{
    try
    {
        GameIO ldr;
        Game* game = ldr.LoadGame("../Examples/UE.xml");

        cout << game->start->GetName() << endl;
    }
    catch(char* msg) { cout << msg; }
    Utility::pause();
    return 0;
}