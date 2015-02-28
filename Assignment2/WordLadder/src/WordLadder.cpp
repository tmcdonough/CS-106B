/*
 * File: WordLadder.cpp
 * --------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the word ladder problem
 * on Assignment #2.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
#include "lexicon.h"
#include "queue.h"
#include "simpio.h"
#include "vector.h"
using namespace std;

/* constants */
string SENTINEL = "";
int z = 122;
int a = 97;

/* prototypes */
Lexicon english("EnglishWords.dat");
Lexicon usedWords;
Queue<Vector<string>> q;
Vector<string> findLadder(string start, string end);
Vector<string> getNextLetterWords(string word);

int main() {
    while(true){
        string start;
        string end;
        while(true){
            start = getLine("Enter start word (RETURN to quit): ");
            if (english.contains(start))break;
            if (start==SENTINEL)break;
            cout << "English, please..." << endl;
        }
        if(start==SENTINEL)break;
        while (true){
            end = getLine("Enter destination word: ");
            if (english.contains(end))break;
            cout << "English, please..." << endl;
        }
        Vector<string> ladder = findLadder(start,end);
        string ladderText;
        if (ladder.isEmpty()) {
            ladderText = "Could not find a ladder.";
        } else {
            ladderText = ladder.toString();
        }
        cout << "Found ladder: " << ladderText << endl;
        usedWords.clear();
        q.clear();
    }
	return 0;
}

Vector<string> findLadder(string start, string end){
    Vector<string> startLadder;
    startLadder.add(start); // first we add the starting word to a ladder
    q.add(startLadder); // then we add that ladder to the queue
    while (!q.isEmpty()){ // will loop while there's a ladder to evaluate
        Vector<string> workingLadder = q.dequeue(); // we want to look at the first ladder that was added - so that, for example, if we're evaluating one word ladders and we add a two word, we finish looking at remaining one-words before moving on to the two-word ladders
        string lastWord = workingLadder.get(workingLadder.size()-1); // this will pull the last word from the ladder... this is the word we want to evaluate, to see if either a) it is the solution or b) what words branch out from there
        if (lastWord==end){
            return workingLadder; // if the last word in this ladder is the solution, it must be <= the quickest solution and so we return that ladder.
        }
        Vector<string> nextLetterWords = getNextLetterWords(lastWord); // we get a list of all words that are one letter different from our current word
        for (int i = 0; i < nextLetterWords.size(); i++){ // we then loop through that list
            string nextWord = nextLetterWords.get(i);
            if (!usedWords.contains(nextWord)){ // as long as that word hasn't been used before, we add another ladder to the stack - it is the same as the previous ladder, except with this new one-letter different word appended to the end.
                Vector<string> newLadder = workingLadder;
                newLadder.add(nextWord);
                usedWords.add(nextWord);
                q.enqueue(newLadder);
            }
        }
    }
    startLadder.clear();
    return startLadder;
}

Vector<string> getNextLetterWords(string word){
    Vector<string> returnList;
    for (int i = 0;i<word.length();i++){ // for each character in the word...
        for (int j = a;j<=z;j++){ // for each letter in the alphabet
            char newChar = j; // convert the ascii code for the current letter in the alphabet to a character
            if (newChar==word[i]) continue; // if that letter equals the current letter, skip it.
            string add = word; // make a copy of that word
            add[i] = newChar; // replace the existing letter with this new letter
            if (english.contains(add)) returnList.add(add); // add it to the to-be-returned list
        }
    }
    return returnList;
}
