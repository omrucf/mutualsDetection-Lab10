/*
Name: Omar Yossuf
SID: 900212166
Instructor: Nada GabAllah
Course: CSCE 2203
Section #03
Lab: 10
Date: Nov 11th, 2022
*/

/*
 ///////////////////PSEUDOCODE\\\\\\\\\\\\\\\\\\\
    for(i = 0 -> size of adjmatrix)
    {
        if(node is not visited)
        do
            DFS(node);
            node = visited
    }

    for(i = 0 -> size of adjmatrix)
    {
        for(j = 0 -> size of the first row in adjmatrix)
        {
            switch all nodes at i and j
        }
    }


 */


#include "Graph.h"

int main()
{
    MTRX TEST_ =                                    // same graph as the slides example
        {
          // a  b  c  d  e  f  g  h  i  j  k
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
    graph test_1(TEST_);
    cout << "Running..\n";

    cout << endl;

    // cout << "Test_1..\n";

    // cout << endl;

    cout << "Groups:\n";
    test_1.setGroups();
    test_1.PrintGroups();

    cout << endl;

    cout << "Largest Group: ";
    test_1.setLargest();
    test_1.PrintLargest();

    cout << endl;

    MTRX TEST_2 =                                 
        {
          // a  b  c  d  e  f  g  h  i  j  k
            {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // a
            {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // b
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // c
            {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1}, // d
            {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1}, // e
            {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1}, // f
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, // g
            {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1}, // h
            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // i
            {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1}, // j
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}  // k
        };
    graph test_2(TEST_2);
    cout << "Test_2..\n";

    cout << endl;

    cout << "Groups:\n";
    test_2.setGroups();
    test_2.PrintGroups();

    cout << endl;

    cout << "Largest Group: ";
    test_2.setLargest();
    test_2.PrintLargest();

    cout << endl;

    return 0;
}