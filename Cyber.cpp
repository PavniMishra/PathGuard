#include <iostream>
#include <cstdlib>
#include "Cyber.h"
#include "Graph.h"
#include "Colors.h"

using namespace std;

vector<Node> nodes;

string getThreatLabel(ThreatLevel t) {
if (t == CRITICAL) return "CRITICAL";
if (t == WARNING) return "WARNING";
return "SAFE";
}

void initializeNodes() {
nodes.resize(n);

for (int i = 0; i < n; i++) {
nodes[i].traffic = rand() % 200;
nodes[i].pkt_drop_rate = rand() % 100;
nodes[i].threat = SAFE;
}
}

void detectThreats() {
for (int i = 0; i < n; i++) {

int load = nodes[i].traffic;
int loss = nodes[i].pkt_drop_rate;

if (load > 172 || loss > 82) {
nodes[i].threat = CRITICAL;
}
else if (load > 105 || loss > 58) {
nodes[i].threat = WARNING;
}
else {
nodes[i].threat = SAFE;
}

}
}

void printNodeStatus() {

cout << "\nNode Status:\n";

for (int i = 0; i < n; i++) {

string color;

if (nodes[i].threat == CRITICAL) color = RED;
else if (nodes[i].threat == WARNING) color = YELLOW;
else color = GREEN;

cout << color;
cout << "Node " << char('A' + i);
cout << " Traffic: " << nodes[i].traffic;
cout << " Loss: " << nodes[i].pkt_drop_rate;
cout << " Status: " << getThreatLabel(nodes[i].threat);
cout << RESET << endl;

}
}