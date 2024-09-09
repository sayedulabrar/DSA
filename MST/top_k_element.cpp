******priority queue is a queue .So it pop from top******

a.second > b.second : it ensures high frequency have higher priority and pop at last.

a.second < b.second : it ensures smallest frequency higher priority and pop at last.


class Solution {
public:
vector<int> topKFrequent(vector<int>& nums, int k) {
    // Step 1: Build frequency map
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    // Step 2: Insert elements into min-heap (priority queue) of size k
   bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&compare)> minHeap(compare);

    for (auto entry : freqMap) {
        minHeap.push(entry);
        if (minHeap.size() > k) {
            minHeap.pop(); // Maintain min-heap size k
        }
    }

    // Step 3: Extract top k elements from min-heap
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().first);
        minHeap.pop();
    }
    // Reverse the result because it's stored in ascending order in the min-heap
    reverse(result.begin(), result.end());
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
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0) return result;

        auto cmp = [&nums1, &nums2](pair<int, int>& a, pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < min(k, static_cast<int>(nums1.size())); ++i) {
            pq.push({i, 0});
        }

        while (k-- > 0 && !pq.empty()) {
            auto [i, j] = pq.top();
            pq.pop();
            result.push_back({nums1[i], nums2[j]});
            if (j + 1 < nums2.size()) {
                pq.push({i, j + 1});
            }
        }

        return result;
    }
};
