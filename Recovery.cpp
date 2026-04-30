#include <iostream>
#include <vector>
#include "Graph.h"
#include "Cyber.h"
#include "Colors.h"
using namespace std;

void recoverNodes(int rounds) {
    cout << BOLD << CYAN << "\n===== NODE RECOVERY SIMULATION =====" <<endl<< RESET;

    for (int r = 1; r <= rounds; r++) {
        cout << BOLD << GREEN << "\nRecovery Round " << r << ":"<<endl << RESET;

        bool anyRecovery = false;

        for (int i = 0; i < n; i++) {
            // CRITICAL to WARNING
            if (nodes[i].threat == CRITICAL) {
                nodes[i].threat = WARNING;
                anyRecovery = true;
                cout << YELLOW << "  Node " << char('A' + i)
                     << " CRITICAL -> WARNING (recovering...)\n" << RESET;
            }
            // WARNING to SAFE
            else if (nodes[i].threat == WARNING) {
                nodes[i].threat = SAFE;
                anyRecovery = true;
                cout << GREEN << "  Node " << char('A' + i)
                     << " WARNING -> SAFE (recovered!)\n" << RESET;
            }
        }

        //print updated status
        cout << BOLD << "\n  Network Status after Recovery Round " << r << ":\n" << RESET;
        for (int i = 0; i < n; i++) {
            string color;
            if      (nodes[i].threat == CRITICAL) color = RED;
            else if (nodes[i].threat == WARNING)  color = YELLOW;
            else                                   color = GREEN;

            cout << color << "  Node " << char('A' + i) << " -> " << getThreatLabel(nodes[i].threat) << RESET << "\n";
        }

        if (!anyRecovery) {
            cout << GREEN << BOLD << "\n  All nodes recovered! Network fully SAFE."<<endl << RESET;
            break;
        }
    }

    cout << BOLD << CYAN << "=====================================" <<endl<< RESET;
}