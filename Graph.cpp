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

graph::graph(int size)
{
    MTRX temp(size, vector<int>(size));

    adjMTRX = temp;

    vector<bool> V(size, false);

    visited = V;
}

graph::graph(MTRX mtrx)
{
    adjMTRX = mtrx;

    vector<bool> temp(mtrx.size(), false);

    visited = temp;
}

graph graph::transpose()
{

    int size = adjMTRX.size();

    graph Transpose(size);

    for (MTRX::size_type i = 0; i < adjMTRX.size(); ++i)
        for (vector<int>::size_type j = 0; j < adjMTRX.at(0).size(); ++j)
            Transpose.adjMTRX.at(j).at(i) = adjMTRX.at(i).at(j);

    return Transpose;
}

vector<int> graph::DFST(int n)
{
    vector<int> Group;

    if (!visited.at(n))
    {
        Group.push_back(n);

        visited.at(n) = true;

        int size = adjMTRX.size();

        for (vector<int>::size_type j = adjMTRX.at(n).at(0); j < size; j++)
        {
            if (adjMTRX.at(n).at(j) == 1)
            {
                if (!visited.at(j))
                {
                    vector<int> Group_2 = DFST(j);
                    Group.insert(Group.end(), Group_2.begin(), Group_2.end());
                }
            }
        }
    }

    return Group;
}

void graph::DFS(int n)
{
    visited.at(n) = true;
    
    for (vector<int>::size_type i = 0; i < adjMTRX.at(n).size(); i++)
    {
        if (adjMTRX.at(n).at(i) == 1)
        {
            if (!visited.at(i))
            {
                DFS(i);
            }
        }
    }
    finished.push_back(n);
}

void graph::setGroups()
{
     for (vector<int>::size_type i = 0; i < adjMTRX.size(); i++)
    {
        if (!visited.at(i))
        {
            DFS(i);
        }
    }

    graph TRNSPS = this->transpose();

    for (int i = finished.size() - 1; i >= 0; i--)
    {
        Groups.push_back(TRNSPS.DFST(finished.at(i)));
    }
}

void graph::setLargest()
{
    int max = 0;
    LGPos = 0;

    for (int i = 0; i < Groups.size(); i++)
    {
        int tempSize = Groups.at(i).size();
        if (tempSize > max)
        {
            max = tempSize;
            LGPos = i;
        }
    }

    LG = Groups.at(LGPos);
}

void graph::PrintGroups()
{
    int c = 1;
    for (MTRX::size_type i = 0; i < Groups.size(); i++)
    {
        if (!Groups.at(i).empty())
        {
            cout << "\tGroup " << c << ": {";
            for (auto j = Groups.at(i).begin(); j != Groups.at(i).end(); j++)
            {
                cout << *j;

                if (j != Groups.at(i).end() - 1)
                    cout << ",";
            }
            cout << "}";
            cout << endl;
            c++;
        }
    }
}

void graph::PrintLargest()
{
    cout << "{";
    for (auto i = LG.begin(); i != LG.end(); i++)
    {
        cout << *i;

        if (i != LG.end() - 1)
            cout << ",";
    }
    cout << "}";
    cout << endl;
}
