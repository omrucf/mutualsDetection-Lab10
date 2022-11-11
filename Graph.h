#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> MTRX;

class graph
{
  MTRX adjMTRX;
  vector<bool> visited;
  vector<int> finished;

public:
  graph();
  graph(const graph &);
  graph(int, int);
  graph(MTRX);

  graph transpose();

  vector<int> DFST(int);

  void DFS(int);
  void getGroups();
};

#endif /*GRAPH_H*/