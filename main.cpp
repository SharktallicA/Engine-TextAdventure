/*
    Engine-TextAdventure
    Khalid Ali 2019
    http://khalidali.co.uk
*/

#include "Utility.h"
#include "Menu.h"

using namespace std;

int main(void)
{
    try
    {
        Menu mnu;
        while (mnu.Run());
    }
    catch(char* msg) { cout << msg; }

    Utility::pause();
    return 0;
}