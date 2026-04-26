#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>
#include <cctype>
#include "Graph.h"
#include "Cyber.h"
#include "Dijk.h"
#include "Colours.h"
#include "Attack.h"
#include "Dashboard.h"
#include "Recovery.h"

using namespace std;

// External variables defined in Graph.h
int n = 5; 
vector<vector<pair<int,int>>> graph;

int main() {
    srand(time(0));
    generateGraph();
    
    initializeNodes();
    detectThreats();
    printNodeStatus();

    char s, d;
    int src, dest;

    // Validate Origin Node Input
    while (true) {
        cout << "\nEnter Origin Node (A-E): ";
        cin >> s;
        src = toupper(s) - 'A';
        
        // Ensure index is within the range [0, n-1]
        if (src >= 0 && src < n) {
            break;
        }
        cout << RED << "Error: Invalid Origin Node! Please enter a character between A and " 
             << (char)('A' + n - 1) << "." << RESET << endl;
    }

    // Validate Destination Node Input
    while (true) {
        cout << "Enter Destination Node (A-E): ";
        cin >> d;
        dest = toupper(d) - 'A';
        
        // Ensure index is within the range [0, n-1]
        if (dest >= 0 && dest < n) {
            break;
        }
        cout << RED << "Error: Invalid Destination Node! Please enter a character between A and " 
             << (char)('A' + n - 1) << "." << RESET << endl;
    }

    // Display initial Security Dashboard
    showDashboard(src, dest);

    cout << BOLD << CYAN << "\n>> EXECUTING SECURE ROUTING ANALYSIS <<\n" << RESET;
    auto t1 = chrono::high_resolution_clock::now();
    dijk(src, dest);
    auto t2 = chrono::high_resolution_clock::now();
    
    cout << "Processing Time: " << chrono::duration<double, micro>(t2 - t1).count() << " us\n";

    // Simulate an attack and re-evaluate
    propagateAttack(2);
    showDashboard(src, dest);
    dijk(src, dest);

    // Execute the Protection Module (Instant Restoration)
    recoverNodes(2);
    showDashboard(src, dest);
    dijk(src, dest);

    return 0;
}