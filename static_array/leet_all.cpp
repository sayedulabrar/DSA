88. Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Index to iterate through nums1
        int j = n - 1; // Index to iterate through nums2
        int k = m + n - 1; // Index to insert elements into nums1
        
        // Merge nums1 and nums2 by comparing elements from the end
        //1.if m>n no problem as m-n will remmain as it is which is sorted
        //2.m<n no problem as even if all n element is of nums2 then remaining m are already sorted.Overlapping will never happen as if k o nums1 get picked then the k element place is already handled and we need to handle the remaining m - k.
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        
        // If there are remaining elements in nums2, copy them to nums1
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};



26. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int k = 0; 
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[k]) {
                nums[++k] = nums[i];              
            }
        }
        
        return k+1;
    }
};


80. Remove some duplicates in-place such that each unique element appears at most twice.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int k = 0; 
        int same=1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[k]) {
                nums[++k] = nums[i]; 
                same=1;
            }else if(same<2){
                    ++same;
                    nums[++k] = nums[i];                
                }
            }
            return k+1;
        }   
};

189. Rotate Array k times

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();  
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};


Best Time to Buy and Sell Stock 1 time
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int minP = 1e9;
        int maxP = 0;
        
        for (int i = 0; i < prices.size(); ++i) {
            minP = min(minP, prices[i]);
            maxP = max(maxP, prices[i] - minP);
        }
        
        return maxP;
    }
};
Best Time to Buy and Sell Stock II any number of times to make max profit

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){//local maxima-local minima
                profit+=prices[i]-prices[i-1];
            }
        }
        return profit;
        
    }
};

55. Jump Game

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

[3, 2, 1, 0, 4, 1], the function will return false because it is not possible to reach the end of the array as it will stuck at reachable 3 at index 3 and in next iteration i=4 where it will return false.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int reachable = 0;
        
        for(int i=0;i<n;++i)
        {
            if(reachable < i)
                return false;
            reachable = max(reachable,i+nums[i]);
        }
        return true;        
    }
};


45 .Jump game 2

This solution uses farthest to represent the farthest index you can reach at any given moment. The last_jump_end variable is 
updated with farthest since farthest ensures that we can reach the index it represents at that moment.This way we can get how many 
jumps needed.

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        int jumps = 0;
        int farthest = 0;
        int last_jump_end = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            if (i == last_jump_end) {
                jumps++;
                last_jump_end = farthest;
            }
        }
        
        return jumps;
    }
};


Example 1:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
Example 2:

Input: citations = [1,3,1]
Output: 1



class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n=citations.size();
        for(int i=0;i<n;i++){
            int h=n-i;
            if(citations[i]>=h) return h;
        }
        return 0;
    }
};


// 6 5 3  1 0 
// > > >= here citations become less than 3 and papers > 3 so we return i not position i+1; As we can have h  papers >= h citations;
// 1 2 3  4 5
// It said h papers with citations >= h.So even if there are papers with same number of citations it won't matter. 3 3 3 3 2 1  .Here at position 2 we get citations[i]>=i+1 last .After that citations remain at 3 but paper number crosses 3.So then we willthe index i.

**remove an element from vector and get random.**
    bool remove(int val) {
        // Find the index of val
        int index = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) {
                index = i;
                break;
            }
        }
        
        // If val not found, return false
        if (index == -1)
            return false;
        
        // Swap val with the last element and pop_back
        nums[index] = nums.back();
        nums.pop_back();
        
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }



238. Product of Array Except Self

class Solution {
public:
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 0); // Initialize result array with 1s
    int totalProduct = 1;
    vector<int> zeroIndices;

    // Calculate total product and store zero indices
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 0) {
            zeroIndices.push_back(i);
        } else {
            totalProduct *= nums[i];
        }
    }
    // If there's only one zero, calculate result
    if (zeroIndices.size() == 1) {
        result[zeroIndices[0]] = totalProduct;
    } else if (zeroIndices.size() > 1) { // If there are multiple zeros, all result elements will be 0
        return result;
    } else { // If there are no zeros, divide each element by totalProduct
        for (int i = 0; i < n; ++i) {
            result[i] = totalProduct / nums[i];
        }
    }

    return result;
}
};



134. Gas Station
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

totalgass < totalcost not possible ever.
the key logic is about checking gas availability at every station and resetting the start position when you can’t proceed.
The tank += gas[i] - cost[i]; approach keeps track of whether you have enough gas at each station and ensures that 
if you can''t proceed from a certain station, you move the starting point forward.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int tank = 0;
        int start = 0;
        
        for (int i = 0; i < gas.size(); ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];
            
            // If at any station, the tank becomes negative,
            // reset the start to the next station and reset the tank
            if (tank < 0) {
                start = (i + 1)%gas.size();
                tank = 0;
            }
        }
        
        // If total gas is less than total cost, it's impossible to complete the circuit
        if (totalGas < totalCost)
            return -1;
        
        return start;
    }
};

6. Zigzag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a
 fixed font for better legibility)

P   A   H   N  
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string result="";
        vector<vector<char>>v(numRows);

        int k=0;
        bool increasing=true;
        int i=0;
        while(i<s.length()){
            v[k].push_back(s[i]);
            if(increasing) k++;
            else k--;

            if(k==numRows) k=k-2; increasing=false;
            else if(k==-1) k=k+2; increasing=true;

        i++;
        }


        for(int i=0;i<numRows;i++){
          for(int k=0;k<v[i].size();k++){
            result+=v[i][k];
          }
        }
        return result;
        
    }
};

**Max area beiween 2 poles**
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

**why we move pointer with the lower height?
The width (distance between the two poles) is always shrinking as you move the pointers towards each other.
Therefore, to maximize the area, you need to increase the height of the poles you''re considering, because:
Area = height × width
As the width (right - left) decreases, increasing the height is the only way to potentially get a larger area.



class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        
        while (left < right) {
            int currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currentArea);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
    }
};







15. Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and 
nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

cant we just use a 2d loop to create all possible 2 number combo and from map check if -(sum of those 2 present ) in the nums array.
for(i--n-3)
 for(i+1--n-2)
  search for the complementary sum of these 2 num in map.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates
            
            int target = -nums[i];
            unordered_map<int, int> numMap;
            
            for (int j = i + 1; j < n; ++j) {
                int complement = target - nums[j];
                
                if (numMap.find(complement) != numMap.end()) {
                    result.push_back({nums[i], complement, nums[j]});
                    while (j + 1 < n && nums[j] == nums[j + 1]) ++j; // Skip duplicates as we don't want same triplet again.And here 
                    // no problem as in next iteration j will increase by 1 if in range and that last of duplicates will be avoided .
                }
                
                numMap[nums[j]] = j; // we need it here else it's current element can end up be the 2nd and 3rd element too .
            }
        }
        
        return result;
    }
};
