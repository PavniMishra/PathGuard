#include <iostream>
#include <vector>
#include <iomanip>
#include "Graph.h"
#include "Cyber.h"
#include "Colours.h"
using namespace std;

void showDashboard(int src, int dest) {
    int sNodes = 0, wNodes = 0, cNodes = 0;

    for (int i = 0; i < n; i++) {
        if      (nodes[i].threat == SAFE)     sNodes++;
        else if (nodes[i].threat == WARNING)  wNodes++;
        else                                  cNodes++;
    }

    // Unique weighting for the health score
    int integrityScore = 100 - (int)(((wNodes * 100.0 / n) * 0.4) + ((cNodes * 100.0 / n) * 0.9));
    if (integrityScore < 0) integrityScore = 0;

    //Differentiating nodes accorsing to colour 
    cout << BOLD << CYAN << "\n---NETWORK SECURITY STATUS---\n" << RESET;
    cout << "Active Nodes: : " << n << "\n";
    cout << GREEN << "Secure Nodes   : " << sNodes << RESET << "\n";
    cout << YELLOW << "Risk Flagged   : " << wNodes << RESET << "\n";
    cout << RED << "Total Failures : " << cNodes << RESET << "\n";
    cout << BOLD << CYAN << "--------------------------------------\n" << RESET;
    
    string statusText = (integrityScore >= 70) ? "STABLE" : (integrityScore >= 40 ? "AT RISK" : "COMPROMISED");
    cout << "System Integrity: " << integrityScore << "/100 [" << statusText << "]\n";
    cout << BOLD << CYAN << "======================================\n" << RESET;
}