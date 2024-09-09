 ***********maximum sum of a subarray with length k********

int maxSumSubarray(std::vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0, right = 0;
    int windowSum = 0;
    int maxSum = INT_MIN;

    while (right < n) {
        windowSum += nums[right];
        if (right - left + 1 == k) { // Window size is k
            maxSum = std::max(maxSum, windowSum);
            windowSum -= nums[left]; // Move left pointer to shrink window
            left++;
        }
        right++; // Move right pointer to expand window
    }

// we took  2 pointer because we can also find range index of the subarray.
    return maxSum;
}


******LONGEST SUBSTRING WITHOUT REPEATING CHARACTER*****


Version 1 :
int lengthOfLongestSubstring(std::string s) {
    int n = s.length();
    string window="";
    int left = 0, right = 0;
    int maxLen = 0;

    while (right < n) {
        if (window.find(s[right]) == string::npos) {
            window+=s[right];
            maxLen = std::max(maxLen,window.length());
            
        } else {
            left=window.find(s[right])+1;// start after the repeating char
            window=window.substr(left,window.length()-left+1);
            window+=s[right];
            
        }
        right++;
    }
    return maxLen;
}



Version 2 :

    int lengthOfLongestSubstring(std::string s) {
        int n = s.length();
        std::unordered_map<char, int> seen;
        int left = 0, right = 0;
        int maxLen = 0;

        while (right < n) {
            if (seen.find(s[right]) == seen.end() || seen[s[right]] < left) { // to ensure that when encountering a repeating character, we're checking if its last occurrence is within the current substring being considered.passin 1st part of condition means it's  repeating then we check if it's outside the string that is being considered.
                seen[s[right]] = right;
                maxLen = std::max(maxLen, right - left + 1);
            } else {
                left = seen[s[right]] + 1;
                seen[s[right]] = right;
            }
            right++;
        }
        return maxLen;
    }



***********Element Appearing More Than 25% In Sorted Array*******


int findSpecialInteger(vector<int>& arr) {
    int n = arr.size();
    int windowSize = n / 4;

    for (int i = 0; i < n - windowSize; ++i) {
        if (arr[i] == arr[i + windowSize]) {
            return arr[i];
        }
    }

    // If no such element is found, the last element will always satisfy the condition
    return arr.back();
}




**************Trapping Rain Water****************
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.


class Solution {
public:
int trap(const vector<int>& heights) {
    vector<int>bars=heights;
    int n=heights.size();
    // base case
    if (n <= 2) {
        return 0;
    }
 
    int water = 0;
 
    // `left[i]` stores the maximum height of a bar to the left
    // of the current bar
    int left[n-2];
    int maxleft=bars[0];
    // process bars from left to right
    for (int i = 1; i < n - 1; i++) {
        maxleft=max(maxleft,bars[i-1]);
        left[i] = maxleft;
    }
 
    // `right` stores the maximum height of a bar to the right
    // of the current bar
    int right = bars[n-1];
 
    // process bars from right to left
    for (int i = n - 2; i >= 1; i--)
    {
        right = max(right, bars[i+1]);
 
        // check if it is possible to store water in the current bar
        if (min(left[i], right) > bars[i]) {
            water += min(left[i], right) - bars[i];
        }
    }
 
    return water;
}
};


**************another variation of Trapping Rain Water****************
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int buyPrice = prices[0];
        int maxProfit = 0; //karon minPrice er prices[0] same.So profit 0.
        
        for (int i = 1; i < prices.size(); ++i) {
            buyPrice = min(buyPrice, prices[i-1]);//as buy,sell sameday not possible
            maxProfit = max(maxProfit, prices[i] - buyPrice);
        }
        
        return maxProfit;
    }
};

209.Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int window=0;
        int left=0;
        bool found=false;
        int minlen=nums.size()+1;
        for(int r=0;r<nums.size();r++){
             window+=nums[r];
            while(window>=target){
                found=true;
                minlen=min(minlen,r-left+1);
                window-=nums[left];
                left++;

            }
        }
        return found? minlen:0;
        
    }
};











30.Input: s = "barfoothefoobarman", words = ["foo","bar"]

Output: [0,9]

Explanation:

The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
The output order does not matter. Returning [9,0] is fine too.


reset,loop start,
            word Existance check,seen freq handle (use cut off freq),count==0 handle
             if not exist move left,reset count,seen.
        move right

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int strSize = words[0].size();
        int wordCount = words.size();

        unordered_map<string, int> wordFreq;
        for (const string& word : words)
            wordFreq[word]++;


        for (int i = 0; i < strSize; ++i) { 
        // This loop is for the case where the starting  of the index at any between 0 to strSize .
        // it can be 0,0+strsize... 1,1+strSize... 2,2+strSize...  upto strsize-1 as it's index. 
            int left = i, right = i, count = wordCount;
            unordered_map<string, int> seen;
            while (right + strSize <= s.size()) { 
                // to cover full string starting from right.
                string word = s.substr(right, strSize);
                if (wordFreq.find(word) != wordFreq.end()) {
                    seen[word]++;
                    if (seen[word] <= windowFreq[word]) count--;
                
                    while (seen[word] > wordFreq[word]) { 
                        //window left theke cut kortesi freq balance korte.Ai part very important as it ensures no repetative words are inserted as it will destroy our answer.We want same freq as words.Here we will not reset window because if in words there are freq of words >1 and the appear before this position then we will overlook them and will miss potential answer.
                        string leftWord = s.substr(left, strSize);
                        seen[leftWord]--;
                        if (seen[leftWord] < windowFreq[leftWord]) count++;//if leftword was word then here it would make seen[word]==wordFreq[word],
                        //But for other words it will just decrease the covered count.So we have to do count++ to indicate we have to cover it which
                        //we deleted.                    
                        left += strSize;
                    }
                    if (count == 0) {
                        //already cover hoise .So save the info.We are not using while because we don't need it here.Because we don't have unnecessary char like the one below.So if we do it multiple times we might miss potential answer.
                        result.push_back(left);
                        string leftWord = s.substr(left, strSize);
                        seen[leftWord]--;
                        count++;//not checking as min freq can be 1 if present in words
                        left += strSize;
                    }
                } else { 
                    // wordfreqte nai kono word means all previous seen reset AS we need to reach count 0 continuously,not subsequence.
                    seen.clear();
                    count = wordCount;
                    left = right + strSize;// to avoid the word that wasn't found.
                }
                right += strSize; // to go track next word.
            }
        }

        return result;
    }
};



Aitae jemon ensure kora lagse continuous string cover every word and freq same oita porertae ensure kora lage nai.Tai aitae amra freq balance
na hoa porjonto cut korsi .But porertae jehetu continuous string na tai amra cut kora shuru korsi only when count==0 ,ar aitae count==0 mane 
amra ekta solution paisi porerta khujo.




76 .Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string 

class Solution {
public:
    string minWindow(string s, string t) {
        // Create a map to store the frequency of characters in t
        unordered_map<char, int> tFreq;
        for (char c : t) {
            tFreq[c]++;
        }
        
        // Initialize the count of missing characters from t
        int count = t.length();
        int start = 0, minStart = 0, minLength = INT_MAX;
        
        // Create a map to store the frequency of characters in the current window
        unordered_map<char, int> windowFreq;
        for (int end = 0; end < s.length(); end++) {
            // Add the current character to the window
            char c = s[end];
            
            // Only increment windowFreq[c] if the character is present in tFreq
            if (tFreq.count(c)) {
                windowFreq[c]++;
                
                // If the frequency in the window is less than or equal to its frequency in t,
                // decrement the count
                if (windowFreq[c] <= tFreq[c]) {
                    count--;
                }
            }
            
             SQUIZZING THE SOLUTION 
            while (count == 0) {
                // Update the minimum length window if the current window is smaller
                int length = end - start + 1;
                if (length < minLength) {
                    minStart = start;
                    minLength = length;
                }
                
                // Remove the leftmost character from the window
                c = s[start];
                
                // Only decrement windowFreq[c] if the character is present in tFreq
                if (tFreq.count(c)) {
                    windowFreq[c]--;
                    
                    // else we don't want to increment count when removing the character from the window, because we still have enough occurrences of that character in the window to satisfy the requirement.
                    if (windowFreq[c] < tFreq[c]) {
                        count++;
                    }
                }
                start++;
            }
        }
        
        // If no valid window is found, return an empty string
        return minLength == INT_MAX ? "" : s.substr(minStart, minLength);
    }
};



max_ending_here represents the maximum sum of a subarray ending at the current position.
If adding the current element (nums[i]) to the current subarray (max_ending_here + nums[i]) results in a sum larger than the current element itself
(nums[i]), it means it's beneficial to include the current element in the subarray.
If adding the current element doesn't improve the sum, it means that starting a new subarray from the current element (nums[i]) might result in a 
larger sum. So, the algorithm resets max_ending_here to the current element (nums[i]).
The maximum sum subarray seen so far (max_so_far) is updated at each step by taking the maximum of the current max_so_far and max_ending_here

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int max_ending_here = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            max_ending_here = max(nums[i], max_ending_here + nums[i]);
            maxsum = max(maxsum, max_ending_here);
        }
        
        return maxsum;
    }
};



class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();

        int maxSum = A[0], currentMax = A[0];
        int minSum = A[0], currentMin = A[0];
        int totalSum = A[0];

        for (int i = 1; i < n; ++i) {
            totalSum += A[i];

            // Kadane's algorithm for maximum subarray sum
            currentMax = max(A[i], currentMax + A[i]);
            maxSum = max(maxSum, currentMax);

            // Kadane's algorithm for minimum subarray sum
            currentMin = min(A[i], currentMin + A[i]);
            minSum = min(minSum, currentMin);
        }
        // Maximum circular subarray sum can be either the maximum subarray sum or
        // the total sum minus the minimum subarray sum
        int maxCircularSum = max(maxSum, totalSum - minSum);

        return maxCircularSum;
    }
};
