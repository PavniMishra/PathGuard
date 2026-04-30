#include <iostream>
#include <vector>
#include <climits>
#include "Graph.h"
#include "Cyber.h"
#include "Colors.h"
#include "Reliability.h"
using namespace std;

void printPath(vector<int>& parent, int target) {
    vector<int> route;
    while(target != -1) {
        route.push_back(target);
        target = parent[target];
    }

    for(int i = route.size() - 1; i >= 0; i--) {
        cout << char('A' + route[i]);
        if(i != 0) cout << " -> ";
    }
}

void dijk(int startNode, int endNode) {
    vector<int> totalrisk(n, INT_MAX);
    vector<bool> processed(n, false);
    vector<int> trackBack(n, -1);

    totalrisk[startNode] = 0;

    for(int count = 0; count < n - 1; count++) {
        int u = -1;
        int minRisk = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(!processed[i] && totalrisk[i] < minRisk) {
                minRisk = totalrisk[i];
                u = i;
            }
        }

        if (u == -1 || nodes[u].threat == CRITICAL) {
            if(u != -1) processed[u] = true;
            continue;
        }

        processed[u] = true;

        for(auto& connection : graph[u]) {
            int v = connection.first;
            int baseWeight = connection.second;

            if (!processed[v] && nodes[v].threat != CRITICAL) {
                int totalCost = baseWeight;
                // Remove routes passing through warning zones
                if (nodes[v].threat == WARNING) totalCost *= 2; 

                if (totalrisk[u] + totalCost < totalrisk[v]) {
                    totalrisk[v] = totalrisk[u] + totalCost;
                    trackBack[v] = u;
                }
            }
        }
    }

    if (totalrisk[endNode] == INT_MAX) {
        cout << RED << BOLD << "Security Protocol: No safe route identified\n" << RESET;
    } else {
        cout << CYAN << BOLD << "Optimized Secure Path: ";
        printPath(trackBack, endNode);
        cout << RESET << "\n" << GREEN << "Total Operational Cost: " << totalrisk[endNode] << RESET << "\n";

        vector<int> finalPath;
        int curr = endNode;
        while (curr != -1) {
            finalPath.push_back(curr);
            curr = trackBack[curr];
        }
        printReliability(calculateReliability(finalPath), "Sentinel-Route ");
    }
}