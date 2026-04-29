#include <iostream>
#include "Graph.h"
#include "Cyber.h"
#include "Dijk.h"
#include "Colours.h"
#include "Dashboard.h"

using namespace std;

int main() {
    srand(time(0));
    generateGraph();
    initializeNodes();
    
    // --- New Firewall Flow ---
    initializeFirewall(); 
    detectThreats();
    printFirewallStatus();
    // -------------------------

    char s, d;
    cout << "\nEnter Origin Node (A-E): ";
    cin >> s;
    int src = toupper(s) - 'A';
    
    cout << "Enter Destination Node (A-E): ";
    cin >> d;
    int dest = toupper(d) - 'A';

    showDashboard(src, dest);
    dijk(src, dest);

    return 0;
}