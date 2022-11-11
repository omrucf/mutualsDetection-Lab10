#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> MTRX;

class graph
{
  MTRX adjMTRX;
  MTRX Groups;

  vector<bool> visited;
  vector<int> finished;
  vector<int> LG;
  
  int LGPos;

public:
  graph();
  graph(int, int);
  graph(MTRX);

  graph transpose();

  vector<int> DFST(int);

  void DFS(int);
  void setGroups();
  void setLargest();
  void getGroups();
  void getLargest();
};

#endif /*GRAPH_H*/