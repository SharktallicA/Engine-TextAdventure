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
        Place* current = game->start;

        if (!current)
            cout << "Not here!\n";
        else
        {
            cout << current->GetName() << " here!\n";
        }
    }
    catch(char* msg) { cout << msg; }
    Utility::pause();
    return 0;
}