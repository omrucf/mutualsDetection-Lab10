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
    { // a  b  c  d  e  f  g  h  i  j  k
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // a
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // b
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // c
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // d
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // e
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // f
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, // g
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, // h
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // i
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1}, // j
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  // k
    };
    graph test(TEST);
    cout << "Running..\n";

    cout << endl;

    cout << "Groups:\n";
    test.setGroups();
    test.PrintGroups();

    cout << endl;

    cout << "Largest Group: ";
    test.setLargest();
    test.PrintLargest();

    cout << endl;

    return 0;
}