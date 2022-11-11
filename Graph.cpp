#include "Graph.h"

graph::graph(const graph &g)
{
    adjMTRX = g.adjMTRX;

    vector<bool> temp(g.adjMTRX.size(), false);

    visited = temp;
}

graph::graph(int R, int C)
{
    MTRX temp(R, vector<int>(C));

    adjMTRX = temp;

    vector<bool> V(R, false);

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
    graph Transpose(adjMTRX.at(0).size(), adjMTRX.size());

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

        cout << n << " ";

        visited.at(n) = true;

        for (vector<int>::size_type j = adjMTRX.at(n).at(0); j < adjMTRX.at(n).size(); j++)
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

void graph::getGroups()
{
    for (vector<int>::size_type i = 0; i < adjMTRX.size(); i++)
    {
        if (!visited.at(i))
        {
            DFS(i);
        }
    }
    cout << "finished is:\n";
    for (vector<int>::iterator it = finished.begin(); it != finished.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    graph TRNSPS = this->transpose();

    MTRX Groups;
    for (int i = finished.size() - 1; i >= 0; i--)
    {
        Groups.push_back(TRNSPS.DFST(finished.at(i)));
    }
    cout << "\nGroups:\n";
    int c = 1;
    for (MTRX::size_type i = 0; i < Groups.size(); i++)
    {
        if (!Groups.at(i).empty())
        {
            cout << "Group " << c << ": {";
            for (auto j = Groups.at(i).begin(); j != Groups.at(i).end(); j++)
            {
                cout << *j;
                
                if(j != Groups.at(i).end()-1)
                    cout << ",";
            }
            cout << "}";
            cout << endl;
            c++;
        }
    }

    int pos = 0,
        max = 0;
    for (int i = 0; i < Groups.size(); i++)
    {
        if (Groups.at(i).size() > max)
        {
            max = Groups.at(i).size();
            pos = i;
        }
    }

    vector<int> LG = Groups.at(pos);

    cout << "Largest group:\n";

    cout << "{";
    for (auto i = LG.begin(); i != LG.end(); i++)
    {
        cout << *i;

        if(i != LG.end() - 1)
            cout << ",";
    }
cout << "}";
    cout << endl;
}
