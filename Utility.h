/*
    C++ general utility functions
    GNU/Linux port
    Khalid Ali 2019
    https://khalidali.co.uk
*/

#ifndef ENGINE_TEXTADVENTURE_UTILITY_H
#define ENGINE_TEXTADVENTURE_UTILITY_H

#include <iostream>
#include <sstream>
#include <random>

using namespace std;

//Class of static methods that provide utility functions
//for C++ console applications
class Utility
{
private:
    Utility() {} //Ensures Utility cannot be initialised

public:
    //Gets yes (true) or no (false) boolean user input
    static bool getYesNo(void)
    {
        string input = "";
        bool isYes = true;

        cin >> input;

        if (input == "y" || input == "Y" || input == "yes" || input == "Yes" || input == "YES")
            isYes = true;
        else if (input == "n" || input == "N" || input == "no" || input == "No" || input == "NO")
            isYes = false;

        return isYes;
    }

    //Gets string user input
    static string getStr(void)
    {
        string input = "";
        getline(cin, input);
        return input;
    }

    //Gets integer user input
    static int getInt(void)
    {
        string input = "";
        int inputAsInt = -1024;

        cin >> input;
        cin.ignore();

        stringstream stream(input);
        stream >> inputAsInt;

        return inputAsInt;
    }
    //Gets integer user input within specified bounds
    static int getInt(int min, int max)
    {
        string input = "";
        int inputAsInt = -1024;

        cin >> input;
        cin.ignore();

        stringstream stream(input);
        stream >> inputAsInt;

        while (inputAsInt < min || inputAsInt > max)
        {
            cout << "ERROR: you can only enter a whole number between "
            << min << " and " << max << "!" << endl << "Try again: ";

            cin >> input;
            cin.ignore();

            stringstream stream(input);
            stream >> inputAsInt;
        }

        return inputAsInt;
    }

    //Generates random integer using 32-Bit Mersenne Twister 19937
    static int rand32(int min, int max)
    {
        int result;

        random_device rand;
        mt19937 mersenne(rand());
        uniform_int_distribution<int> dist(min, max);
        result = dist(mersenne);

        return result;
    }
    //Generates random integer using 64-Bit Mersenne Twister 19937
    static int rand64(int min, int max)
    {
        int result;

        random_device rand;
        mt19937_64 mersenne(rand());
        uniform_int_distribution<int> dist(min, max);
        result = dist(mersenne);

        return result;
    }
    //Generates random double using 32-Bit Mersenne Twister 19937
    static double rand32(double min, double max)
    {
        double result;

        random_device rand;
        mt19937 mersenne(rand());
        uniform_real_distribution<double> dist(min, max);
        result = dist(mersenne);

        return result;
    }
    //Generates random double using 64-Bit Mersenne Twister 19937
    static double rand64(double min, double max)
    {
        double result;

        random_device rand;
        mt19937_64 mersenne(rand());
        uniform_real_distribution<double> dist(min, max);
        result = dist(mersenne);

        return result;
    }

    //Clears the screen
    static void clear(void)
    {
#ifdef WINDOWS
        system("cls");
#else
        system("clear");
#endif
    }

    //Pauses program for user input - system("pause") replacement
    static char pause(string msg = "Press any key and return to continue...")
    {
        system ("/bin/stty raw");
        cout << msg;
        char in = getchar();
        cout << endl;
        cin.ignore();
        system("/bin/stty cooked");
        return in;
    }
};

#endif //ENGINE_TEXTADVENTURE_UTILITY_H
