https://leetcode.com/problems/minimum-genetic-mutation/

class Solution {
    public:
    
        int gap(const std::string& a ,const std::string &b){
            int change=0;
           for(int i=0;i<min(a.length(),b.length());i++){
            if(a[i]!=b[i]) change++;
           }
           return change;
        }
     int minMutation(std::string startGene, std::string endGene, std::vector<std::string>& bank) {
            std::unordered_set<std::string> bankSet(bank.begin(), bank.end());
            std::queue<std::string> bfs;
            bfs.push(startGene);
            int level = 0;
    
            while (!bfs.empty()) {
                int size = bfs.size();
                level++;
    
                for (int i = 0; i < size; i++) {
                    std::string king = bfs.front();
                    bfs.pop();
    
                    if (king == endGene) {
                        return level -1;
                    }
    
                    std::unordered_set<std::string> toRemove; // Store strings to remove
    
                    for (const auto& considered_string : bankSet) {
                        if (gap(king, considered_string) == 1) {
                            bfs.push(considered_string);
                            toRemove.insert(considered_string); // Mark for removal
                        }
                    }
    
                    // Erase the elements after the iteration
                    for (const auto& str : toRemove) {
                        bankSet.erase(str);
                    }
                }
            }
            return -1; // No solution found
        }
    };
