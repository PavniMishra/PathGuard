#include <iostream>
#include <ctime>
#include <chrono>
#include "Graph.h"
#include "Cyber.h"
#include "Dijk.h"
#include "Colors.h"
#include "Attack.h"
#include "Dashboard.h"
#include "Output.h"
#include "Recovery.h"
#include "Firewall.h"

using namespace std;

int n = 5;
vector<vector<pair<int,int> > > graph;

int main()
{

srand(time(0));

generateGraph();

initializeNodes();
detectThreats();
initializeFirewall();
printNodeStatus();

char s,d;

cout << "\nEnter Origin Node (A-E): ";
cin >> s;

cout << "Enter Destination Node (A-E): ";
cin >> d;

int src = toupper(s) - 'A';
int dest = toupper(d) - 'A';
saveOutput(src, dest);

showDashboard(src,dest);

cout << "\nRunning Path Analysis...\n";

auto start = chrono::high_resolution_clock::now();

dijk(src,dest);

auto end = chrono::high_resolution_clock::now();

double time_taken = chrono::duration<double,micro>(end - start).count();

cout << "Time: " << time_taken << " us\n";

propagateAttack(3);
printFirewallStatus();

showDashboard(src,dest);
dijk(src,dest);

recoverNodes(2);

showDashboard(src,dest);
dijk(src,dest);

return 0;

}