#ifndef RELIABILITY_H
#define RELIABILITY_H

#include <vector>
#include <string>
using namespace std;

// Calculates the integrity score of a chosen route
int calculateReliability(vector<int>& route);

// Outputs the security trust rating to the console
void printReliability(int score, string label);

#endif