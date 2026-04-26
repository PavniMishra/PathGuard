#include <iostream>
#include "Reliability.h"
#include "Cyber.h"
#include "Colours.h"
using namespace std;

int calculateReliability(vector<int>& route) {
    if (route.empty()) return 0;

    int securityIndex = 100;
    for (int nodeID : route) {
        
        //Calculating risk on the basis of Threat Label assigned 
        if      (nodes[nodeID].threat == CRITICAL) securityIndex -= 38;
        else if (nodes[nodeID].threat == WARNING)  securityIndex -= 12;
    }

    if (securityIndex < 0) return 0;
    else return securityIndex;
}

//Printing Reliability of the path 
void printReliability(int score, string label) {
    string color = (score >= 80) ? GREEN : (score >= 50 ? YELLOW : RED);
    string rating = (score >= 80) ? "HIGHLY TRUSTED" : (score >= 50 ? "DEGRADED" : "UNSAFE");

    cout << color << BOLD << "Route Trust Rating: " << score << "/100 (" << rating << ")" << RESET << "\n";
}