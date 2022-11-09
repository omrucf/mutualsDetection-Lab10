#include "Graph.h"

graph::graph(const graph &g)
{
    adjMTRX = g.adjMTRX;

    vector<bool> temp(g.adjMTRX.size(), false);

    visited = temp;
}

graph::graph(int R, int C)
{
    vector<vector<int>> temp(R, vector<int>(C));

    adjMTRX = temp;

    vector<bool> V(R, false);

    visited = V;
}

void graph::DFS(int n)
{
    visited[n] = true;
    for (vector<int>::size_type i = 0; i < adjMTRX[n].size(); i++)
    {
        if (adjMTRX[n][i] == 1)
        {
            if (!visited[i])
            {
                DFS(i);
            }
        }
    }
    finished.push_back(n);
}

graph graph::transpose()
{
    graph Transpose(adjMTRX[0].size(), adjMTRX.size());

    for (vector<vector<int>>::size_type i = 0; i < adjMTRX.size(); ++i)
        for (vector<int>::size_type j = 0; j < adjMTRX[0].size(); ++j)
            Transpose.adjMTRX[j][i] = adjMTRX[i][j];

    return Transpose;
}