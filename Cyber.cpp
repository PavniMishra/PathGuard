#include <iostream>
#include <vector>
#include "Cyber.h"
#include "Colours.h"

using namespace std;

void detectThreats() {
    for (int i = 0; i < n; i++) {
        // Basic threat logic based on random simulation
        if (nodes[i].isFirewall) {
            nodes[i].threat = SAFE; // Firewalls keep nodes safe
        } else {
            int risk = rand() % 100;
            if (risk > 70) nodes[i].threat = CRITICAL;
            else if (risk > 40) nodes[i].threat = WARNING;
            else nodes[i].threat = SAFE;
        }
    }
}

string getThreatLabel(ThreatLevel level) {
    if (level == CRITICAL) return "CRITICAL";
    if (level == WARNING) return "WARNING";
    return "SAFE";
}

void initializeFirewall() {
    for (int i = 0; i < n; i++) {
        nodes[i].isFirewall = false; 
    }

    // Assigning protection to specific nodes
    nodes[1].isFirewall = true;  // Node B
    nodes[3].isFirewall = true;  // Node D

    cout << BOLD << CYAN << "\n===== FIREWALL PROTECTION ACTIVE =====\n" << RESET;
    cout << GREEN << "  [PROXIED] Node B Protected\n";
    cout << GREEN << "  [PROXIED] Node D Protected\n" << RESET;
    cout << BOLD << CYAN << "=======================================\n" << RESET;
}

void printFirewallStatus() {
    cout << BOLD << CYAN << "\n--- FIREWALL STATUS REPORT ---\n" << RESET;
    for (int i = 0; i < n; i++) {
        if (nodes[i].isFirewall) {
            cout << GREEN << BOLD << "  Node " << char('A' + i)
                 << " | FIREWALL PROTECTED | " << getThreatLabel(nodes[i].threat) << RESET << "\n";
        } else {
            string color = (nodes[i].threat == CRITICAL) ? RED : (nodes[i].threat == WARNING) ? YELLOW : GREEN;
            cout << color << "  Node " << char('A' + i)
                 << " | No Firewall        | " << getThreatLabel(nodes[i].threat) << RESET << "\n";
        }
    }
}