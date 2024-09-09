******priority queue is a queue .So it pop from top******

a.second > b.second : it ensures high frequency have higher priority and pop at last.

a.second < b.second : it ensures smallest frequency higher priority and pop at last.


class Solution {
public:
    // Custom comparator for the min-heap
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



class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Max-heap to store the pairs with their sums, we want to keep the k smallest
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        // Iterate over all combinations of nums1 and nums2
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
                
                // Push the current pair (sum, {i, j}) into the heap
                maxHeap.push({sum, {i, j}});
                
                // If the heap size exceeds k, pop the largest sum pair
                if (maxHeap.size() > k) {
                    maxHeap.pop();
                }
            }
        }

        // Collect the result from the heap
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            auto [sum, indices] = maxHeap.top();
            maxHeap.pop();
            result.push_back({nums1[indices.first], nums2[indices.second]});
        }

        // Since the max-heap stores elements in reverse order, we reverse the result
        reverse(result.begin(), result.end());

        return result;
    }
};
