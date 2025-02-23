
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