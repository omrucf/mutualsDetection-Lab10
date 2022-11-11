/*
Name: Omar Yossuf
SID: 900212166
Instructor: Nada GabAllah
Course: CSCE 2203
Section #03
Lab: 10
Date: Nov 11th, 2022
*/

#include "Graph.h"

int main()
{
    MTRX TEST =                                // same graph as the slides example
    {
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    graph test(TEST);
    cout << "Running..\n";

    cout << endl;

    cout << "Groups:\n";
    test.setGroups();
    test.PrintGroups();

    cout << endl;

    cout << "Lagest Group: ";
    test.setLargest();
    test.PrintLargest();

    cout << endl;

    return 0;
}