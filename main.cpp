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
  
graph(int size)
{
   initialize vector adjMTRX to have the given size

   initialize vector visited to have the same size and all elements to be false
}

graph(vector of vector of int mtrx)
{
    let adjMTRX vector to be the same as the given vector mtrx

   initialize vector visited to have the same size and all elements to be false
}

transpose()
{

   create a graph called transpose

    for (i <- 0 to size of matrix - 1)
        for (j <- 0 to size of matrix - 1)
            set adjMTRX[j][i] of graph transpose to adjMTRX[i][j];

    return transpose;
}

DFST(int n)
{
    create a vector named Group

    if (n is not visited)
    {
        Group.push_back(n);

        let n be visited 

        for (j <- 0 to matrix size - 1)
        {
            if (adjMTRX[n][j] is 1)
            {
                if (j is not visited)
                {
                    create a vector named group2 to be equal to the returned vector of DFST(j)
                    Group.push_back(elements in group 2)
                }
            }
        }
    }

    return Group;
}

DFS(int n)
{
    let n be visited 
    
    for (i <- 0 to matrix size - 1)
    {
        if (adjMTRX[n][i] is 1)
        {
            if (i is not visited)
            {
                DFS(i);
            }
        }
    }
    finished.push_back(n);
}

setGroups()
{
     for (i <- 0 to matrix size - 1)
    {
        if (i is not visited)
        {
            DFS(i);
        }
    }

    create a graph named TRNSPS to be equal to the returned graph from the transpose() function

    for (i <- finished.size() - 1 to 0)
    {
        Groups.push_back(TRNSPS.DFST(finished[i]));
    }
}

setLargest()
{
    int max <- 0;
    LGPos <- 0;

    for (i <- 0 to Groups size)
    {
        int tempSize <- Groups[i].size();
        if (tempSize > max)
        {
            max <- tempSize;
            LGPos <- i;
        }
    }

    LG <- Groups[LGPos];
}

PrintGroups()
{
    intitialize counter to 0

    for (i <- 0 to Groups size)
    {
        if (Groups[i] is not empty)
        {
            print group at position i from groups
            counter <- counter + 1;
        }
    }
}

void graph::PrintLargest()
{
    print largest group LG
}

 */


#include "Graph.h"

int main()
{
    MTRX TEST_1 =                                    // same graph as the slides example
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
    graph test_1(TEST_1);
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

    MTRX TEST_2 =               // example 1 in slides
    {
      // a  b  c  d  e 
        {0, 1, 0, 0, 0}, // a
        {0, 0, 1, 1, 0}, // b
        {0, 0, 0, 0, 1}, // c
        {1, 0, 0, 0, 0}, // d
        {0, 0, 0, 0, 0}  // e
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