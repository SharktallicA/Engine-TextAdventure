/*
    Engine-TextAdventure
    Khalid Ali 2019
    http://khalidali.co.uk
*/

#include "Misc/Utility.h"
#include "Engine/GameLoader.h"

using namespace std;

int main(void)
{
    GameLoader* ldr;
    try
    {
        ldr = new GameLoader("../Examples/UE.xml");
    }
    catch(char* msg) { cout << msg; }
    Utility::pause();
    return 0;
}