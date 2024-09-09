
The first solution requires more information (start index and TrieNode pointer) to uniquely identify the subproblems, 
while the second solution only needs the start index.

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
        string key = to_string(start) + "," + (curr == nullptr ? "#" : to_string(reinterpret_cast<uint64_t>(curr)));//create unique key for each node as there can be various node with same start but different prefix and more.
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



int main() {
    Solution solution;

    // Example usage:
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << (solution.wordBreak(s1, wordDict1) ? "true" : "false") << endl;

    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << (solution.wordBreak(s2, wordDict2) ? "true" : "false") << endl;

    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << (solution.wordBreak(s3, wordDict3) ? "true" : "false") << endl;

    return 0;
}




class Solution {
private:
    unordered_map<string, bool> memo;

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return wordBreakHelper(s, 0, wordSet);
    }

    bool wordBreakHelper(const string& s, int start, const unordered_set<string>& wordSet) {
        string key = to_string(start);
        if (memo.count(key)) {
            return memo[key];
        }

        if (start == s.length()) {
            // memo[key] = true;
            return true;
        }


// So in lr dp we check in the range where i will cut and cost will be lower.Here i can cut at anywhere in that range
//But here i can't.Because i have to cut such a way that it's valid word.

//So even though there are similarity they have 2 different goal.One is to find minimum cost cut point.
//Another is to cut so that we get valid word.So we check validity of the word and then the remaining is new subproblem.
        for (int end = start + 1; end <= s.length(); end++) {
            string word = s.substr(start, end - start);
            if (wordSet.count(word) && wordBreakHelper(s, end, wordSet)) {
                memo[key] = true;
                return true;
            }
        }

        memo[key] = false;
        return false;
    }
};