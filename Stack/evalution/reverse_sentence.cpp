#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

string reverseWords(const string& sentence) {
    stack<string> words; // Stack to store words
    stringstream ss(sentence); // Use stringstream to split the sentence
    string word;

    // //Use >> when you want to split by whitespace (spaces, tabs, newlines) and don't need to handle multiple delimiters explicitly.
    // while (ss >> word) {
    //     words.push(word);
    // }

    // Split the sentence into words using getline and push them onto the stack
    while (getline(ss, word, ' ')) {
        if (!word.empty()) { // Avoid pushing empty strings (in case of multiple spaces)
            words.push(word);
        }
    }

    string reversedSentence;
    // Pop words from the stack to reverse the sentence
    while (!words.empty()) {
        reversedSentence += words.top() + " ";
        words.pop();
    }

    // Remove the trailing space
    if (!reversedSentence.empty()) {
        reversedSentence.pop_back();
    }

    return reversedSentence;
}

int main() {
    string sentence = "Hello world! This is a sample sentence.";
    string reversed = reverseWords(sentence);
    cout << "Reversed sentence: " << reversed << endl;
    return 0;
}