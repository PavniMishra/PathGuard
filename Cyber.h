#ifndef CYBER_H
#define CYBER_H

#include <string>
#include "Graph.h"

void detectThreats();
std::string getThreatLabel(ThreatLevel level);
void initializeFirewall();   // <--- New
void printFirewallStatus();  // <--- New

#endif