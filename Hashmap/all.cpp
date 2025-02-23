
****It is the solution of if ransomnote can be created using magazine's characters.****
bool canConstruct(string ransomNote, string magazine) {

    if(magazine.size()<ransomNote.size()) return false;

    // Hashmap to store character frequencies in magazine
    unordered_map<char, int> magFreq;
    unordered_map<char, int>ransomFreq;

    // Populate magFreq with character frequencies from magazine
    for (char c : magazine)
        magFreq[c]++;

    
    // Check if ransomNote can be constructed from magazine
    for (char c : ransomNote) {
        // If character not present or frequency less in magazine, return false
        if (magFreq.find(c) != magFreq.end() && magFreq[c]>0){ 
            magFreq[c]--;
            }
        else return false;
    }

    return true;
}



It is easier as both should have same frequency of char for both .So we can use single map and check char 
frequency.
bool isAnagram(string s, string t) {
    // If the lengths of the strings are different, they can't be anagrams
    if (s.size() != t.size())
        return false;
    
    // Hashmap to store character frequencies in string s
    unordered_map<char, int> freq;

    // Populate freq with character frequencies from string s
    for (char c : s)
        freq[c]++;
    
    // Iterate through each character in string t
    for (char c : t) {
        // If character exists in s and its frequency is greater than 0, decrement the count
        if (freq.find(c) != freq.end() && freq[c] > 0) {
            freq[c]--;
        } else {
            return false;
        }
    }

    // If all characters in s are accounted for in t, they are anagrams
    return true;
}



****Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the 
same character, but a character may map to itself.
IT IS LIKE ONE TO ONE MAPPING.****
bool isIsomorphic(string s, string t) {
    unordered_map<char, char> sToT;
    unordered_map<char, char> tToS;

    for (int i = 0; i < s.size(); ++i) {
        char sChar = s[i];
        char tChar = t[i];

        if (sToT.find(sChar) == sToT.end() && tToS.find(tChar) == tToS.end()) {
            sToT[sChar] = tChar;
            tToS[tChar] = sChar;
        } else if (sToT.find(sChar) != sToT.end() && sToT[sChar] == tChar &&
                   tToS.find(tChar) != tToS.end() && tToS[tChar] == sChar) {
            continue;
        } else {
            return false;
        }
    }

    return true;
}

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
bool wordPattern(string pattern, string s) {
    unordered_map<char, string> patternToWord;
    unordered_map<string, char> wordToPattern;
    
    stringstream ss(s);
    vector<string> words;
    string word="";
    while (getline(ss,word,' ')) {
        words.push_back(word);
    }
    
    if (pattern.size() != words.size())
        return false;
    
    for (int i = 0; i < pattern.size(); ++i) {
        char patternChar = pattern[i];
        string currentWord = words[i];
        
        if (patternToWord.find(patternChar) == patternToWord.end() && wordToPattern.find(currentWord) == wordToPattern.end()) {
            patternToWord[patternChar] = currentWord;
            wordToPattern[currentWord] = patternChar;
        } else if (patternToWord.find(patternChar) != patternToWord.end() && patternToWord[patternChar] == currentWord &&
                   wordToPattern.find(currentWord) != wordToPattern.end() && wordToPattern[currentWord] == patternChar) {
            continue;
        } else {
            return false;
        }
    }
    
    return true;
}



the answer is the common prefix of left and right in their binary representation.Because rest of will have 0/1 and resulting to 0.
For example,
0b0101 (left)
0b0111 (right)
0b0100 (answer)
Approach
Keep shifting right to find the common prefix
class Solution {
public:
    // time/space: O(log(min(m, n)))/O(1)
    int rangeBitwiseAnd(int left, int right) {
        int m = left, n = right;
        int shift = 0;
        while (m != n) {
            m >>= 1, n >>= 1;
            shift++;
        }
        return (m << shift); because ans needs to be same length ans max(m,n).
    }
};


Example 1:

Input: n = 19
Output: true
Explanation: 2 is square in left side.
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false

bool isHappy(int n) {
    unordered_set<int> seen; // Set to store seen numbers
    
    while (n != 1) {
        // Calculate the sum of squares of digits
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        
        // If the sum is already seen, it means we've entered into a cycle
        if (seen.find(sum) != seen.end())
            return false;
        
        // Otherwise, add the sum to the set of seen numbers and continue
        seen.insert(sum);
        n = sum;
    }
    
    // If we reach here, n is 1, so it's a happy number
    return true;
}




// class Solution {
// public:
//     double myPow(double x, int n) {
        
//         if(n < 0) {
//             x = 1 / x;
//         } 
//         // fix the value of x based on n - or +
        
//         long num = labs(n);//absolute value of num as we have handled it's sign effect already
        
//         double pow = 1;

// So we will do it like this.If there is x^5 then 5=101 and  x^3*(x^2 but not use as in n there is 0)*x .So we need to track active position using 
// num&1 and at the end of each iteration do n>>=1 so that we can ind next digit of num active or not .And x*=x to get the series ....8 4 2 1  
// here from left to right.

//         while(num){ 
//             if(num & 1) { 
//                 pow *= x;
//             }
            
//             x *= x;
//             num >>= 1;
//         }
        
//         return pow;
//     }
// };


string addBinary(string a, string b) {
    string result = "";
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    
    // Iterate through both strings from right to left
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        
        // Add the corresponding bits from both strings
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';
        
        // Append the least significant bit of the sum to the result
        result = to_string(sum % 2) + result;
        
        // Update the carry for the next iteration
        carry = sum / 2;
    }
    
    return result;
}


Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its 
binary representation is 00111001011110000010100101000000.

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    
    // Iterate through each bit of n
    for (int i = 0; i < 32; ++i) {
        // Shift the result to the left by one bit and set the least significant bit if it's set in n
        result = (result << 1) | (n & 1);
        
        // Shift n to the right by one bit to process the next bit
        n >>= 1;
    }
    
    return result;
}

check number of 1 here in n.
   while (n > 0) {
        // Check if the least significant bit of n is 1
        if (n & 1)
            count++;
        
        // Shift n to the right by one bit to process the next bit
        n >>= 1;
    }


every element appears twice except for one. Find that single one.
    int singleNumber(vector<int>& nums) {
    int result = 0;
    
    // XOR all numbers in the array
    for (int num : nums) {
        result ^= num;
    }
    
    return result;
}


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
1 bar ashle ones te num er bits 1 rakhbo kintu twos erta 0 korbo.Tai ~ones AND hoise.
2 bar ashle twos te num er bits 1 rakhbo kintu ones erta 0 korbo.Tai ~twos AND hoise.
So 3 bar ashle ones AND hobe ~twos dara.Tokhon jara two er jonne one silo tara 0 hobe.But single frequenncy afect hobe na as oigula 0 silo        twos te as ~ones gun hoe.So answer paia jabo.
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        
        return ones;
    }
};


Given an array of strings strs, group the anagrams together. You can return the answer in any order.
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        vector<vector<string>> result;
        
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagramMap[sortedStr].push_back(str);
        }
        
        for (auto& pair : anagramMap) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};







128.[100,4,200,1,3,2], the longest consecutive sequence is [1, 2, 3, 4], and its length is 4.


int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0; 

    sort(nums.begin(), nums.end()); 
    int longestStreak = 1; 
    int maxStreak = 1;    

    for (int i = 1; i < nums.size(); i++) {
        // Skip duplicates
        if (nums[i] == nums[i - 1]) continue;

        if (nums[i] - nums[i - 1] == 1) {
            longestStreak++;
            maxStreak = max(maxStreak, longestStreak); 
        } else {
            longestStreak = 1;
        }
    }
    return maxStreak;
}