#include <iostream>
#include <vector>
#include "Graph.h"
#include "Cyber.h"
#include "Colours.h"
using namespace std;

void initializeFirewall() {
    // Pehle 2 nodes ko firewall protected mark karo
    for (int i = 0; i < n; i++) {
        nodes[i].isFirewall = false;  // default
    }

    // Node B aur D ko firewall protected banao
    nodes[1].isFirewall = true;  // Node B
    nodes[3].isFirewall = true;  // Node D

    cout << BOLD << CYAN << "\n===== FIREWALL PROTECTION =====\n" << RESET;
    cout << GREEN << BOLD << "  Firewall Active on Node B\n" << RESET;
    cout << GREEN << BOLD << "  Firewall Active on Node D\n" << RESET;
    cout << BOLD << CYAN << "================================\n" << RESET;
}

void printFirewallStatus() {
    cout << BOLD << CYAN << "\n===== FIREWALL STATUS =====\n" << RESET;
    for (int i = 0; i < n; i++) {
        if (nodes[i].isFirewall) {
            cout << GREEN << BOLD
                 << "  Node " << char('A' + i)
                 << " | FIREWALL PROTECTED | "
                 << getThreatLabel(nodes[i].threat)
                 << RESET << "\n";
        } else {
            string color;
            if      (nodes[i].threat == CRITICAL) color = RED;
            else if (nodes[i].threat == WARNING)  color = YELLOW;
            else                                   color = GREEN;
            cout << color
                 << "  Node " << char('A' + i)
                 << " | No Firewall       | "
                 << getThreatLabel(nodes[i].threat)
                 << RESET << "\n";
        }
    }
    cout << BOLD << CYAN << "===========================\n" << RESET;
}