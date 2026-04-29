#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

enum ThreatLevel { SAFE, WARNING, CRITICAL };

struct Node {
    int id;
    ThreatLevel threat;
    int traffic;
    double packetDrop;
    bool isFirewall; // <--- Added for Firewall Module
};

extern int n;
extern std::vector<Node> nodes;
extern std::vector<std::vector<std::pair<int, int>>> graph;

void generateGraph();
void initializeNodes();

#endif