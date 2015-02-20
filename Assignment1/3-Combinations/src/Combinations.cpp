/*
 * File: Combinations.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the recursive combinations problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
using namespace std;

/* constants */
int SENTINEL = -1;

/* prototypes */
int c (int n, int k);

int main() {
   while(true){
       int n = getInteger("Enter a row (0 indexed) **ENTER -1 to QUIT**: ");
       if (n==SENTINEL)break;
       int k;
       while (true){
           k = getInteger("Enter a column (0 indexed): ");
           if (k<=n)break;
           cout << "Enter a valid column value (must be less than or equal to the row value)" << endl;
       }

       cout << c(n,k) << endl;
   }
   return 0;
}

int c (int n, int k){
    if (n==k || k==0) {
        return 1;
    } else {
        int n2 = n-1;
        int k2 = k-1;
        return (c(n2,k2)+c(n2,k));
    }
}

