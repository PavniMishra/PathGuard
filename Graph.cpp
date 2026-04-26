#include <iostream>
#include <cstdlib>
#include <vector>
#include "Graph.h"

using namespace std;

void generateGraph() {
graph.clear();
graph.resize(n);

// basic connections (like a chain)
for (int i = 0; i < n - 1; i++) {
int risk = rand() % 9 + 1;
graph[i].push_back(make_pair(i + 1, risk));
graph[i + 1].push_back(make_pair(i, risk));
}

// extra random connections
for (int i = 0; i < n; i++) {
for (int j = i + 2; j < n; j++) {
if (rand() % 2 == 1) {
int risk = rand() % 9 + 1;
graph[i].push_back(make_pair(j, risk));
graph[j].push_back(make_pair(i, risk));
}
}
}
}

void displayGraph() {
cout << "\nNetwork Graph:\n";

for (int i = 0; i < n; i++) {
cout << "Node " << char('A' + i) << " -> ";

for (int j = 0; j < graph[i].size(); j++) {
cout << char('A' + graph[i][j].first)
<< "(" << graph[i][j].second << ") ";
}

cout << endl;
}
}