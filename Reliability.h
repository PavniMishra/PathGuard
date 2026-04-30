#ifndef RELIABILITY_H
#define RELIABILITY_H

#include <vector>
#include <string>  // Fixed: Added this so 'string' is recognized

using namespace std;

// Calculates the integrity score of a chosen route
int calculateReliability(vector<int>& route);

// Outputs the security trust rating to the console
void printReliability(int score, string label);

#endif
// (Make sure there is a blank line right here at the very end!)[cite: 2]