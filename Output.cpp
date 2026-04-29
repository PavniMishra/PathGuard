#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Output.h"
#include "Graph.h"
#include "Cyber.h"
using namespace std;

void saveOutput(int src, int dest) {
    ofstream file("output.json");

    file << "{\n";

    // Nodes
    file << "  \"nodes\": [\n";
    for (int i = 0; i < n; i++) {
        string threat;
        if      (nodes[i].threat == CRITICAL)
             threat = "CRITICAL";
        else if (nodes[i].threat == WARNING)  
            threat = "WARNING";
        else                                  
             threat = "SAFE";

        file << "    {\"id\": " << i
             << ", \"name\": \"" << char('A' + i) << "\""
             << ", \"traffic\": " << nodes[i].traffic
             << ", \"drop\": " << nodes[i].pkt_drop_rate
             << ", \"threat\": \"" << threat << "\"}";
        if (i < n - 1) file << ",";
        file << "\n";
    }
    file << "  ],\n";

    // Edges
    file << "  \"edges\": [\n";
    bool firstEdge = true;
    for (int i = 0; i < n; i++) {
        for (auto edge : graph[i]) {
            if (edge.first > i) {
                if (!firstEdge) file << ",\n";
                file << "    {\"from\": " << i
                     << ", \"to\": " << edge.first
                     << ", \"weight\": " << edge.second << "}";
                firstEdge = false;
            }
        }
    }
    file << "\n  ],\n";

    // Source and destination entered by user 
    file << "  \"source\": " << src << ",\n";
    file << "  \"dest\": "   << dest << "\n";

    file << "}\n";
    file.close();
    cout << "\nOutput saved to output.json\n";
}
