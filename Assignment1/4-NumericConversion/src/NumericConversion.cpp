/*
 * File: NumericConversion.cpp
 * ---------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the numeric-conversion problem
 * in which you implement the functions intToString and stringToInt.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "math.h"
using namespace std;

/* Function prototypes */

string intToString(int n);
int stringToInt(string str);

/* constants */
string STRING_SENTINEL = "-999";
int INT_SENTINEL = -999;

/* Main program */

int main() {
   while (true) {
       string ask;
       while (true){
            ask = getLine("Convert to String or to Int?");
            cout << "(Once you've chosen, enter -999 to return to start.)" << endl;
            if (ask=="String" || ask=="Int") break;
       }
       if (ask=="String"){
           while (true) {

               string check = getLine("Enter an integer");
               if (check==STRING_SENTINEL) break;
               int conv = stringToInt(check);
               cout << conv << endl;
           }
       } else {
           while (true) {
               int check = getInteger("Enter an integer");
               if (check==INT_SENTINEL) break;
               string conv = intToString(check);
               cout << conv << endl;
           }
       }
   }
       return 0;
}

string intToString(int n){
    if (n<10 && n>=0){
        return string(1,'0'+n);
    } else if (n>-10 && n<0){
        return '-'+string(1,'0'-n);
    } else if (n<=-10){
        return intToString(n/10)+string(1,'0'+(-n%10));
    } else {
        return intToString(n/10)+string(1,'0'+n%10);
    }
}
int stringToInt(string str){
    if (str[0]=='-'){
        if (str.length()==2){
            return -(str[1]-'0');
        } else {
            return -pow(10,str.length()-2)*(str[1]-'0')+stringToInt('-'+str.substr(2,str.length()-2));
        }
    }
    if (str.length()==1){
        return str[0]-'0';
    } else {
        return pow(10,str.length()-1)*(str[0]-'0')+stringToInt(str.substr(1,str.length()-1));
    }
}
