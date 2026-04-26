#include <iostream>
#include <vector>
#include "Graph.h"
#include "Cyber.h"
#include "Colours.h"
using namespace std;

void propagateAttack(int rounds) {
  cout << BOLD << "\n========================================" << endl;
cout << BOLD << "         ATTACK PROPAGATION             " << endl;
cout << BOLD << "========================================" << endl << RESET;

    for (int r = 1; r <= rounds; r++) {
        cout << BOLD << YELLOW << "Round " << r << ":"<<endl << RESET;

        vector<ThreatLevel> newThreat(n);
        for (int i = 0; i < n; i++) {
            newThreat[i] = nodes[i].threat;
        }

        bool anyChange = false;

        for (int u = 0; u < n; u++) {
            if (nodes[u].threat != CRITICAL) 
                continue;

            for (auto edge : graph[u]) {
                int v = edge.first;

                if (nodes[v].threat == SAFE) {
                    newThreat[v] = WARNING;
                    anyChange = true;
                    cout << YELLOW << "  Node " << char('A' + v) << " SAFE -> WARNING (infected by Node " << char('A' + u) << ")\n" << RESET;
                }
                else if (nodes[v].threat == WARNING) {
                    newThreat[v] = CRITICAL;
                    anyChange = true;
                    cout << RED << "  Node " << char('A' + v)<< " WARNING -> CRITICAL (infected by Node " << char('A' + u) << ")\n" << RESET;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            nodes[i].threat = newThreat[i];
        }

        cout << BOLD << "\n  Network Status after Round " << r << ":" <<endl<< RESET;
        for (int i = 0; i < n; i++) {
            string color;
            if (nodes[i].threat == CRITICAL) 
                {color = RED;}
            else if (nodes[i].threat == WARNING)  
                {color = YELLOW;}
            else                       
               { color = GREEN;}

            cout << color << "  Node " << char('A' + i) << " -> " << getThreatLabel(nodes[i].threat) << RESET << endl;
        }

        if (!anyChange) {
            cout << GREEN << BOLD << "\n  No further propagation possible. Network stable." <<endl<< RESET;
            break;
        }
    }

    cout << BOLD << "\n========================================" << endl << RESET;
    cout << BOLD << "  Re-calculating safest path..." << endl << RESET;
    cout << BOLD << "========================================" << endl << RESET;
}