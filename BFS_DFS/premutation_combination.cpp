#include<bits/stdc++.h>
using namespace std;


void generatePermutations(string str) {
    // Sort the string to start with the smallest permutation
    sort(str.begin(), str.end());

    // Print the current permutation and generate the next permutations
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Move {
public:
    string top;
    int start;
    
    Move(string t, int s) : top(t), start(s) {} // Constructor with initializer list
};

vector<string> generateCombinations(string s) {
    sort(s.begin(), s.end());  // Sort to handle duplicates easily
    queue<Move> q;
    q.push(Move("", 0));
    
    vector<string> result;

    while (!q.empty()) {
        Move current = q.front(); // Correct object extraction
        q.pop();

        string top = current.top;
        int start = current.start;

        // If length is 3, store and continue
        if (top.length() == 3) {
            result.push_back(top);
            continue;
        }

        for (int i = start; i < s.length(); i++) {
            // Skip duplicates in the same level
            if (i > start && s[i] == s[i - 1]) continue;

            q.push(Move(top + s[i], i + 1)); // Correct way to create Move object
        }
    }

    return result;
}


*******EFFICIENT SOLUTION************

40. Combination Sum II
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort candidates to handle duplicates
        vector<vector<int>> result;
        vector<int> current;
        dfs(candidates, target, 0, current, result);
        return result;
    }
    
private:
    void dfs(const vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size() ; ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            current.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, current, result); 
            current.pop_back(); // Backtrack
        }
    }
};