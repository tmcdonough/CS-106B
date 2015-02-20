/*
 * File: Obenglobish.java
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Obenglobish problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

/* Main program */

/* prototypes */
string obenglobish(string word);
bool isVowel(char letter);
bool isPronVowel(string word, int positionOfLetter);

int main() {
   while (true){
       string word = getLine("Enter a word: ");
       if (word=="") break;
       string trans = obenglobish(word);
       cout << word << " -> " << trans << endl;
   }
   return 0;
}

string obenglobish(string word){
    for (int i = 0; i < word.length(); i++){
        if (isPronVowel(word,i)){
            word.insert(i,"ob");
            i+=2;
        }
    }
    return word;
}

bool isVowel(char letter){
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') return true;
    return false;
}

bool isPronVowel(string word, int positionOfLetter){
    if (!isVowel(word[positionOfLetter])) return false;
    if (isVowel(word[positionOfLetter-1])) return false; /* returns false if the preceeding letter is a vowel. */
    if (positionOfLetter<(word.length()-1)) return true; /* the other case is if it's an e at the end of a word - if the positio is less than the length, it cannot be at end of the word... */
    if (word[positionOfLetter]=='e') return false; /* if it hasn't already returned true, then it is a vowel that is at the end of the word. So if it's also an e, we know it's silent. */
    return true; /* in all other cases we return true */
}
