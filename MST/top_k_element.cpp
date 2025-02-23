

class Solution {
public:
    // todo Custom comparator for the min-heap
    struct compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second; // Compare frequencies
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Build frequency map
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Step 2: Insert elements into min-heap (priority queue) of size k
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> minHeap;

        for (auto entry : freqMap) {
            minHeap.push(entry);
            if (minHeap.size() > k) {
                minHeap.pop(); // Maintain min-heap size of k
            }
        }

        // Step 3: Extract top k elements from min-heap
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }
        // The heap already maintains the top k elements in the correct order, so no need to reverse
        return result;
    }
};







You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 

Constraints:

1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in non-decreasing order.
1 <= k <= 104
k <= nums1.length * nums2.length


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct PairSum {
    int sum;
    int num1;
    int num2;

    PairSum(int s, int a, int b) : sum(s), num1(a), num2(b) {}
};

// todo Min heap comparator (smallest sum first)
struct Compare {
    bool operator()(const PairSum& a, const PairSum& b) {
        return a.sum > b.sum; // Min heap (smallest sum at top)
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<PairSum, vector<PairSum>, Compare> minHeap;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];

                // Push to heap
                minHeap.push(PairSum(sum, nums1[i], nums2[j]));

                // Maintain heap size of k
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
        }

        // Extract results
        vector<vector<int>> result;
        while (!minHeap.empty()) {
            PairSum top = minHeap.top();
            result.push_back({top.num1, top.num2});
            minHeap.pop();
        }

        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    vector<vector<int>> result = sol.kSmallestPairs(nums1, nums2, k);

    for (const auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    return 0;
}
