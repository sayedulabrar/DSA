You have to reach stat to end.Each time you can change a single char.If after changing that string is not in bank than that choice is invalid.So use valid choices to reach end with min moves.
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.find(end) == bankSet.end()) return -1; // end is not in bank

        unordered_set<string> visited;
        visited.insert(start);
        queue<string> q;
        q.push(start);

        int mutations = 0;
        vector<char> genes = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();

                if (curr == end) return mutations; // found the end gene

                // Mutate current gene
                for (int j = 0; j < curr.size(); ++j) {
                    char original = curr[j];
                    for (char g : genes) {
                        curr[j] = g;
                        if (visited.find(curr) != visited.end() || bankSet.find(curr) == bankSet.end()) continue;
                        visited.insert(curr);
                        q.push(curr);
                    }
                    curr[j] = original; // revert back for next mutation
                }
            }
            mutations++;
        }

        return -1; // end gene not reachable
    }
};
