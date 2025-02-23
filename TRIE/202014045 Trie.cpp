#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int count;
    Node* children[28];

    Node() {
        for (int i = 0; i < 28; ++i) {
            children[i] = nullptr;
        }
        count = 0;
    }
} *root;

bool nochildren(Node* as) {
    for (int i = 0; i < 28; i++) {
        if (as->children[i]) {
            return false;
        }
    }
    return true;
}

void createEdge(Node* u, Node* v, int c) {
    u->children[c] = v;
}

void deledge(Node* u, char c, int d) {
    int rp;
    if (d == 0) return;
    if (c == '@') rp = 26;
    else if (c == '.') rp = 27;
    else rp = (int)c - 65;

    Node* v = u->children[rp];
    u->children[rp] = nullptr;
    delete v; // Correctly use delete instead of free()
}

bool isjun(Node* u) {
    if (!nochildren(u)) return true;
    if (u->count > 0) return true;
    return false;
}

void insert(string s) {
    Node* u = root;
    int len = s.size();

    for (int i = 0; i < len; i++) {
        char c = s[i];
        int ki;
        if (c == '@') ki = 26;
        else if (c == '.') ki = 27;
        else ki = (int)c - 65;

        if (u->children[ki] == nullptr) {
            Node* v = new Node();  // Correct node initialization
            createEdge(u, v, ki);
        }
        u = u->children[ki];
    }
    u->count++;
}

int Delete(Node* p, int d, string key) {
    if (d == key.length()) {
        if (p->count == 0) return 0;
        if (!nochildren(p)) {
            p->count--;
            return 0;
        }
        if (p->count > 1) {
            p->count--;
            return 0;
        }
        return 1;
    }

    if (p == nullptr) {
        return 0;
    }

    int a = Delete(p->children[key[d] - 'A'], d + 1, key);
    if (a == 1) {
        deledge(p, key[d], a);
        if (isjun(p)) return 0;
        else return 1;
    }

    return 0;
}

Node* search(Node* root, string key) {
    Node* pCrawl = root;

    for (int i = 0; i < key.length(); i++) {
        int ki;
        if (key[i] == '@') ki = 26;
        else if (key[i] == '.') ki = 27;
        else ki = key[i] - 'A';
        if (!pCrawl->children[ki])
            return nullptr;

        pCrawl = pCrawl->children[ki];
    }

    return (pCrawl);
}

void printLexicographic(Node* cur, string &s) {

    if (cur->count > 0) {
        for (int i = 0; i < cur->count; i++) {
            cout << s << endl;
        }
    }

    for (int i = 0; i < 28; i++) {
        char cc;
        if (i < 26)
            cc = (char)(i + 65);
        else if (i == 26) cc = '@';
        else if (i == 27) cc = '.';

        if (cur->children[i]) {
            s.push_back(cc);            
            printLexicographic(cur->children[i], s);  
            s.pop_back();               
        }
    }
}




int main() {
    int a, b, k;
    string ff, fff;
    string d = "";
    root = new Node();  // Initialize the root node

    cin >> a;

    for (int i = 0; i < a; i++) {
        cin >> ff;
        for (k = 0; k < ff.length(); k++) {
            d = d + ff[k];
            if (ff[k] == '@') break;
        }

        if (ff[k + 1] == 'G') {
            d = "GMAIL.COM" + d;
            insert(d);
        } else if (ff[k + 1] == 'H') {
            d = "HOTMAIL.COM" + d;
            insert(d);
        } else if (ff[k + 1] == 'Y') {
            d = "YAHOO.COM" + d;
            insert(d);
        }
        d.clear();
    }

    cin >> b;
    for (int j = 0; j < b; j++) {
        cin >> fff;
        cout << "Query " << j + 1 << " :";
        Node* x = search(root, fff);
        if (x == nullptr) {
            cout << "No result found" << endl;
        } else {
            printLexicographic(x, fff);
        }
        cout << endl << endl;
    }

    return 0;
}

/*
10
THE@GMAIL.COM
THEIR@YAHOO.COM
A@HOTMAIL.COM
ANY@GMAIL.COM
ABAR@YAHOO.COM
THEY@GMAIL.COM
BY@YAHOO.COM
BYE@GMAIL.COM
AIUB@HOTMAIL.COM
CU@GMAIL.COM
3
HOTMAIL.COM
YAHOO.COM
GMAIL.COM
*/






WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. 
word may contain dots '.' where dots can be matched with any letter.
Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]


class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }

    bool searchUtil(string word, int index, TrieNode* node) {
        if (index == word.length()) return node->isEndOfWord;

        char c = word[index];
        if (c == '.') {
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] && searchUtil(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int idx = c - 'a';
            if (node->children[idx]) {
                return searchUtil(word, index + 1, node->children[idx]);
            } else {
                return false;
            }
        }
    }

    bool search(string word) {
        return searchUtil(word, 0, root);
    }
};

int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("at");
    wordDictionary.addWord("and");
    wordDictionary.addWord("an");
    wordDictionary.addWord("add");

    cout << "Search a: " << wordDictionary.search("a") << endl; // false
    cout << "Search .at: " << wordDictionary.search(".at") << endl; // true
    cout << "Search an.: " << wordDictionary.search("an.") << endl; // true
    cout << "Search a.d.: " << wordDictionary.search("a.d.") << endl; // true
    cout << "Search b.: " << wordDictionary.search("b.") << endl; // false
    cout << "Search a.d: " << wordDictionary.search("a.d") << endl; // false
    cout << "Search .: " << wordDictionary.search(".") << endl; // false

    return 0;
}
