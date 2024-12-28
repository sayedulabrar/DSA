88. Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //last index= size - 1 so k=(m+n)-1 as m+n is the size.
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

        int k = 0; // Pointer to track the last unique element
        int i = 1; // Pointer to iterate through the array

        while (i < nums.size()) {
            if (nums[i] != nums[k]) {
                nums[++k] = nums[i];// because for 1 1 2 if we use k++ then at k=0 2 will be placed but it's supposed to be later of 1.
            }
            ++i; 
        }

        return k + 1; // k is the index of the last unique element, so length is k + 1
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
        k %= n;  
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};




45 .Jump game 2

Here at 0 th index of the loop the first farthest is assigned then we continue to update farthest and only when i==last_jump_end which was
mainly jump the value at 0th index and then we assign the present farthest as the next jump end. But for achiving that how can he be sure 
that he can achive it with the jump from at the present i. 
The answer is he has already reached that farthest in one of previous jump or at the present i's jump . So here we will naturally have to use
it and for it we would have jumped <=0 th index's farthest. As there is clearly written we can jump at most X which means we can also jump
<=X no problem. So if we had jumped <=X then we would have touched that index that's responsible for next farthest jump and jumped . 

So in that condition we are just taking advantage of this situation by continuously updating farthest and when the farthest that was 
assigned to last_jump_end ends we assign present farthest.And for it we would have needed one jup as if we jumped from the <=X position
where that current farthest position's jump was present at that index.   So the solution is perfect.

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
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is
3
Example 2:

Input: citations = [1,3,1]
Output: 1
The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited 
at least h times.


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end(), greater<>());
        for(int i = 0; i < n; i++) {
            int h = i + 1;
            if(citations[i] <= h) continue;
            else return h - 1;
        }
        return n;//return n at the end to handle the case where all papers have more citations than their index position
    }
};


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


            if(k==numRows-1) increasing=false;
            else if(k==0) increasing=true;

            if(increasing) k++;
            else k--;

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
//For real world scene this is better like map problems with various data types .



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort the array
        
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int target = -nums[i];
            int low = i + 1, high = n - 1;
            
            while (low < high) {
                int sum = nums[low] + nums[high];
                
                if (sum == target) {
                    result.push_back({nums[i], nums[low], nums[high]});
                    
                    // Skip duplicates for the second and third elements
                    while (low < high && nums[low] == nums[low + 1]) ++low;
                    while (low < high && nums[high] == nums[high - 1]) --high;
                    
                    ++low;
                    --high;
                } else if (sum < target) { //the nums can be -,+. So don't worry think normally.
                    ++low; // Increase the sum
                } else {
                    --high; // Decrease the sum
                }
            }
        }
        
        return result;
    }
};
