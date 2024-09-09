
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

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
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
};




class Solution {
private:
    unordered_map<string, bool> memo;

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (const string& word : wordDict) {
            trie.insert(word);
        }
        return wordBreakHelper(s, 0, trie.root, trie.root);
    }

    bool wordBreakHelper(const string& s, int start, TrieNode* curr, TrieNode* root) {
        string key = to_string(start) + "," + (curr == nullptr ? "#" : to_string(reinterpret_cast<uint64_t>(curr)));
        if (memo.count(key)) {
            return memo[key];
        }

        if (start == s.length()) {
            memo[key] = curr->isEndOfWord;
            return curr->isEndOfWord;
        }

        int index = s[start] - 'a';
        if (!curr->children[index]) {
            memo[key] = false;
            return false;
        }
        curr = curr->children[index];

        if (curr->isEndOfWord) {
            if (wordBreakHelper(s, start + 1, root, root) || wordBreakHelper(s, start + 1, curr, root)) {
                memo[key] = true;
                return true;
            }
        }

        if (wordBreakHelper(s, start + 1, curr, root)) {
            memo[key] = true;
            return true;
        }

        memo[key] = false;
        return false;
    }
};


