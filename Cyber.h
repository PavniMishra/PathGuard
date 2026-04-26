#ifndef CYBER_H
#define CYBER_H
#include <vector>
#include <string>

using namespace std;

enum ThreatLevel { SAFE, WARNING, CRITICAL };

struct Node {
    int traffic;
    int pkt_drop_rate;
    ThreatLevel threat;
};

extern vector<Node> nodes;

void initializeNodes();
void detectThreats();
void printNodeStatus();
string getThreatLabel(ThreatLevel t);
#endif