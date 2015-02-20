/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the coin-flipping problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
using namespace std;

/* function prototypes */
void flipCoin();
void printResults();
/* ivars */
int flips = 0;
int heads = 0;

int main() {
    while (true){
            flipCoin();
            if (heads == 3) break;
            }
    printResults();
    return 0;
}
void flipCoin() {
    bool flip = randomBool(); /* heads is true */
    if (flip){
        heads++;
        cout << "Heads" << endl;
    } else {
        cout << "Tails" << endl;
    }
    flips++;
    }
void printResults() {
    cout << "It took " << flips << " flips to get 3 consecutive heads." << endl;
}

