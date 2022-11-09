#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

using namespace std;

class graph
{
public:
  vector<vector<int>> adjMTRX;;
  vector<bool> visited;
  vector<int> finished;

  graph();
  graph(const graph &);
  graph(int, int);

  void DFS(int);

  graph transpose();
};

#endif /*GRAPH_H*/