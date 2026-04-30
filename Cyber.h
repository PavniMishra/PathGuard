#ifndef CYBER_H
#define CYBER_H

#include <vector>
#include <string>
using namespace std;

// 3 threat levels
enum ThreatLevel {
    SAFE,
    WARNING,
    CRITICAL
};

struct Node {
    int traffic;
    int pkt_drop_rate;
    ThreatLevel threat; 
        bool isFirewall = false;
};

extern vector<Node> nodes;

void initializeNodes();
void detectThreats();        // detectInfection() rename
void printNodeStatus();
string getThreatLabel(ThreatLevel t);  // helper function

#endif