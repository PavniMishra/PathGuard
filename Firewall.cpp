#include <iostream>
#include <vector>
#include "Graph.h"
#include "Cyber.h"
#include "Colors.h"
using namespace std;

void initializeFirewall() {
    for (int i = 0; i < n; i++) {
        nodes[i].isFirewall = false;
    }

    int protected1 = rand() % n;
    int protected2;
    
    do {
        protected2 = rand() % n;
    } while (protected2 == protected1);

    nodes[protected1].isFirewall = true;
    nodes[protected2].isFirewall = true;

    cout << BOLD << CYAN << "\n===== FIREWALL PROTECTION =====\n" << RESET;
    cout << GREEN << BOLD << "  [SHIELD] Node " << char('A' + protected1) << " is protected\n" << RESET;
    cout << GREEN << BOLD << "  [SHIELD] Node " << char('A' + protected2) << " is protected\n" << RESET;
    cout << BOLD << CYAN << "================================\n" << RESET;
}

void printFirewallStatus() {
    cout << BOLD << CYAN << "\n===== NODE SECURITY STATUS =====\n" << RESET;

    for (int i = 0; i < n; i++) {
        char nodeName = 'A' + i;
        string threat = getThreatLabel(nodes[i].threat);

        if (nodes[i].isFirewall) {
            cout << GREEN << BOLD
                 << "  Node " << nodeName
                 << "  |  Firewall: ON   |  Threat: " << threat
                 << RESET << "\n";
        } else {
            // Color reflects threat severity
            string threatColor;
            if      (nodes[i].threat == CRITICAL) threatColor = RED;
            else if (nodes[i].threat == WARNING)  threatColor = YELLOW;
            else                                   threatColor = GREEN;

            cout << threatColor
                 << "  Node " << nodeName
                 << "  |  Firewall: OFF  |  Threat: " << threat
                 << RESET << "\n";
        }
    }

    cout << BOLD << CYAN << "================================\n" << RESET;
}