#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

string reverseWords(const string& sentence) {
    // Queue of stacks to store characters of each word
    queue<stack<char>> q;
    // string word="";

    // for(int i=0;i<sentence.length();i++){
    //     if(sentence[0]==' '){
    //         while(sentence[i]==' '){
    //             i++;
    //         }
    //     }

    //     if(sentence[i]==' '){
    //         stack<char>st;
    //         for (char w : word) {
    //             s.push(w);  
    //         }
    //         word="";
    //         q.push(st);

    //     }else{
    //        word+=sentence[i];
    //     }
    // }
    
    // Split sentence into words
    string word;
    for (char c : sentence) {
        if (c == ' ') {
            // Process the word when space is encountered
            stack<char> s;
            for (char w : word) {
                s.push(w);  // Push characters of word onto stack
            }
            q.push(s);  // Push the stack onto the queue
            word.clear();  // Clear word for the next word
        } else {
            word.push_back(c);  // Build the word character by character
        }
    }
    
    // Process the last word
    stack<char> lastWord;
    for (char w : word) {
        lastWord.push(w);
    }
    q.push(lastWord);
    
    // Reassemble the reversed sentence
    string reversedSentence;
    while (!q.empty()) {
        stack<char> wordStack = q.front();
        q.pop();
        while (!wordStack.empty()) {
            reversedSentence.push_back(wordStack.top());
            wordStack.pop();
        }
        reversedSentence.push_back(' ');  // Add space between words
    }
    
    // Remove trailing space
    reversedSentence.pop_back();
    
    
    return reversedSentence;
}

int main() {
    string sentence = "Hello world! This is a sample sentence.";
    string reversed = reverseWords(sentence);
    cout << "Reversed sentence: " << reversed << endl;
    return 0;
}
