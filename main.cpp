/*
    Engine-TextAdventure
    Khalid Ali 2019
    http://khalidali.co.uk
*/

#include "Misc/Utility.h"

using namespace std;

int main(void)
{
    cout << "Testing rand..." << endl;
    for (int i = 0; i < 100; i++)
        cout << i + 1 << ": " << Utility::rand64(0, 100) << endl;

    return 0;
}