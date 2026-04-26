#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility>

using namespace std;

extern int n;
extern vector<vector<pair<int,int> > > graph;

void generateGraph();
void displayGraph();

#endif