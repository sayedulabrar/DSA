tearing a m×n paper grid and minimizing the total area sum after tearing it 
k times.

 int minAreaSum(int r, int c, int limit) {
    if (limit == 0) return r * c;

    if (dp[r][c] != -1)
        return dp[r][c];

    int minArea = r * c;
    
    // Tear horizontally
    for (int i = 1; i <= r / 2; i++) {
        int area1 = min(i * c + minAreaSum(r - i, c, limit - 1), (r - i) * c + minAreaSum(i, c, limit - 1));
        minArea = min(minArea, area1);
    }

    // Tear vertically
    for (int i = 1; i <= c / 2; i++) {
        int area2 = min(r * i + minAreaSum(r, c - i, limit - 1), r * (c - i) + minAreaSum(r, i, limit - 1));
        minArea = min(minArea, area2);
    }

    return dp[r][c] = minArea;
}




here is an array of n numbers. we have to make  different targets from it and we have to print all posible combination to get each target.


int rec(const vector<int>& arr, int level, int left) {
    if (level == arr.size()) {
        if (left == 0) {
            // Print chosen indexes with 1
            for (int i = 0; i < arr.size(); ++i)
                if (chosen[i] == 1)
                    cout << i << " ";
            cout << endl;
            return 1;
        }
        return 0;
    }
    if (dp[level][left] != -1) return dp[level][left];

    int count = 0;
    count += rec(arr, level + 1, left);
    if (left - arr[level] >= 0) {
        chosen[level] = 1;
        count += rec(arr, level + 1, left - arr[level]);
        chosen[level] = -1;
    }
    return dp[level][left] = count;
}




max path sum from 1,1 to m,n in a grid.Only right and top move is allowed.

int rec(int m, int n) {
    // Base case: if we reach the boundary, return the value of that cell
    if (m == 1 && n == 1) return grid[0][0];
    
    // If already computed, return the value from dp
    if (check[m][n] != -1) return dp[m][n];
    
    // Calculate maximum path sum recursively
    int max_sum = 0;
    if (m > 1)
        max_sum = max(max_sum, rec(m - 1, n) + grid[m][n]); // Move top
    if (n > 1)
        max_sum = max(max_sum, rec(m, n - 1) + grid[m][n]); // Move left
    check[m][n]=1;
    return dp[m][n] = max_sum;
}


LCS

int rec(int i, int j) {
    // Base case: if any string reaches its end, return 0
    if (i == a.size() || j == b.size()) return 0;
    
    // If already computed, return the value from dp
    if (dp[i][j] != -1) return dp[i][j];
    
    // If characters match, add 1 to the length of LCS and recurse
    if (a[i] == b[j])
        return dp[i][j] = 1 + rec(i + 1, j + 1);
    // Otherwise, choose the maximum length of LCS by considering both options
    else
        return dp[i][j] = max(rec(i + 1, j), rec(i, j + 1));
}





5. Longest Palindromic Substring
class Solution {
public:
    int maxLen = 1;  // Track the maximum length of a palindrome
    int dp[1001][1001];  // Memoization table to store the length of palindromic substrings
    int startindex = 0;  // Properly initialize startindex to 0

    string longestPalindrome(string s) {
        memset(dp, -1, sizeof(dp));  // Initialize dp table with -1
        f(0, s.size() - 1, s);  // Call the recursive function
        return s.substr(startindex, maxLen);
    }

    // Helper function to check if a substring s[l..r] is a palindrome
    bool isPalindrome(int l, int r, string &s) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    // Recursive function to find the length of the longest palindromic substring for s[l..r]
    int f(int l, int r, string &s) {
        if (l > r) return 0;  // Invalid range
        if (l == r) return 1;  // A single character is always a palindrome of length 1

        if (dp[l][r] != -1) return dp[l][r];  // Return memoized result

        // Check if s[l..r] is a palindrome
        if (isPalindrome(l, r, s)) {
            dp[l][r] = r - l + 1;  // This substring is a palindrome
            if (dp[l][r] > maxLen) {
                maxLen = dp[l][r];
                startindex = l;  // Update startindex only if we find a longer palindrome
            }
        } else {
            dp[l][r] = max(f(l + 1, r, s), f(l, r - 1, s));  // Try excluding characters
        }


        // For destroying palindromic substring and total cost to destroy the string minimum (rest part same)
        //         // Check if s[l..r] is a palindrome
        // if (isPalindrome(l, r, s)) {
        //     dp[l][r] =1;  // This substring is a palindrome
            
        // } else {
        //      dp[l][r]=999999999;
        //     for(int k=l;k<r;k++){
        //        dp[l][r] = min(dp[l][r],f(l, k, s)+ f(k+1, r, s));  // Try excluding characters
        //     }
            
        // }

        return dp[l][r];  // Return the length of the longest palindrome for s[l..r]
    }


};



so for finding maximum square of 1 we used dp.So if a cell has 1 then we will check if its right,diagonal and left and their square size.Now if they dont have 1 they return 0 else they continue recursively to calculate square or each cell.Now if one o the 3 cells return 0 wans at that level it will return 0 .But if the cells return various size square then we will take minium which will ensure that for that length the square is present fully.

class Solution {
public:
int solve(vector<vector<char>>& matrix, int i , int j ,int& maxi,vector<vector<int>>&dp)
{
    // CHECK IF INDEX ARE OUT OF BOUND OR NOT 
    if(i>=matrix.size() || j>=matrix[0].size())
    {
        return 0 ;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int right=solve(matrix,i,j+1,maxi,dp);
    int diagonal=solve(matrix,i+1,j+1,maxi,dp);
    int bottom=solve(matrix,i+1,j,maxi,dp);
    if(matrix[i][j]=='1')
    {
        dp[i][j] = 1+min(right, min(diagonal , bottom));
        maxi=max(dp[i][j],maxi);
        return dp[i][j];
    }
    else
        return 0 ;

}
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        int maxi = 0;
        int s=solve(matrix, 0,0 , maxi,dp);
          return maxi * maxi; 
    }
};
