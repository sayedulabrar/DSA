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



vector<string> generateCombinations(const string& s) {
    int n = s.length();
    queue<string> q;
    q.push("");
    vector<string> total;

    while (!q.empty()) {
        string top = q.front();
        q.pop();

        // If the length of the current combination is less than 3 and
        // the current character is not already present in the combination
        if (top.length() < 3) {
            for (int i = 0; i < n; i++) {
                if (top.find(s[i]) == string::npos) {
                    string child = top + s[i];
                    total.push_back(child);
                    q.push(child);
                }
            }
        }
    }

    return total;
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
        
        for (int i = start; i < candidates.size() && candidates[i] <= target; ++i) {//candidates[i] <= target to avoid unnecessary combination
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1])// i>start means in our considered values we don't take same value twice as for a parent of size 2 it will create multiple duplicate of size 3
                continue;
            current.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, current, result); // Use the number only once
            current.pop_back(); // Backtrack
        }
    }
};