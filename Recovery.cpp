#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"
#include "Cyber.h"
#include "Colours.h"

using namespace std;

/**
 * Protection Module: Instant Restoration
 * This function bypasses intermediate degraded states and restores 
 * CRITICAL and WARNING nodes directly to SAFE status.
 */
void recoverNodes(int rounds) {
    cout << BOLD << GREEN << "\n[+] INITIATING INSTANT PROTECTION & RESTORATION [+]\n" << RESET;

    for (int r = 1; r <= rounds; r++) {
        bool repairDone = false;

        for (int i = 0; i < n; i++) {
            // Check if node needs restoration
            if (nodes[i].threat == CRITICAL || nodes[i].threat == WARNING) {
                
                // 1. Identify the current status before changing it
                string oldStatus = (nodes[i].threat == CRITICAL) ? "CRITICAL" : "WARNING";
                
                // 2. Directly restore to SAFE status
                nodes[i].threat = SAFE; 
                repairDone = true;
                
                // 3. Display the transition in the output
                cout << "  Protection Module: Node " << char('A' + i) 
                     << " (" << oldStatus << ") restored directly to SECURE status.\n";
            }
        }

        // If no nodes needed repair in this round, exit early
        if (!repairDone) {
            break;
        }
    }
}