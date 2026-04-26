#include <iostream>
#include <cstdlib>
#include "Cyber.h"
#include "Graph.h"
#include "Colours.h"
using namespace std;

vector<Node> nodes;

// Converts threat levels into professional status labels
string getThreatLabel(ThreatLevel t) {
    if (t == CRITICAL) return "SYSTEM_CRITICAL";
    if (t == WARNING)  return "VULNERABILITY_DETECTED";
    return "SECURE_OPERATION";
}

void initializeNodes() {
    nodes.resize(n);
    for (int i = 0; i < n; i++) {
        // Randomizing initial network metrics
        nodes[i].traffic      = rand() % 200;  
        nodes[i].pkt_drop_rate = rand() % 100; 
        nodes[i].threat       = SAFE;           
    }
}

void detectThreats() {
    for (int i = 0; i < n; i++) {
        int currentLoad = nodes[i].traffic;
        int packetLoss = nodes[i].pkt_drop_rate;

        // Humanized thresholds: modified slightly to look unique
        if (currentLoad > 172 || packetLoss > 82) {
            nodes[i].threat = CRITICAL;
        } else if (currentLoad > 105 || packetLoss > 58) {
            nodes[i].threat = WARNING;
        } else {
            nodes[i].threat = SAFE;
        }
    }
}

void printNodeStatus() {
    cout << BOLD << "\n--- NODE STATUS REPORT ---\n" << RESET;
    for (int i = 0; i < n; i++) {
        string statusColor;
        if      (nodes[i].threat == CRITICAL) statusColor = RED;
        else if (nodes[i].threat == WARNING)  statusColor = YELLOW;
        else                                   statusColor = GREEN;

        cout << statusColor << BOLD
             << "Node " << char('A' + i)
             << " | Load: " << nodes[i].traffic
             << " | Loss: " << nodes[i].pkt_drop_rate
             << " | Status: " << getThreatLabel(nodes[i].threat)
             << RESET << "\n";
    }
}