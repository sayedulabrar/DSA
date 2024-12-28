Given two arrays representing children’s greed factor and cookie sizes, the goal is to maximise the number of content children.

Each child i has a greed factor of g[i], which is the minimum size of a cookie that will make the child content. Each cookie j has a size 
of s[j]. If s[j] >= g[i], we can assign cookie j to child i, making the child content. Each child can only receive one cookie.

#include <vector>   
#include <algorithm>
#include <iostream>

using namespace std;

// Function to find the maximum
// number of content children
int findContentChildren(vector<int>& greed, vector<int>& cookieSize) {
    // Get the size of
    // the greed array
    int n = greed.size();

    // Get the size of
    // the cookieSize array
    int m = cookieSize.size();

    // Sort the greed factors in ascending
    // order to try and satisfy the
    // least greedy children first
    sort(greed.begin(), greed.end());

    // Sort the cookie sizes in ascending
    // order to use the smallest cookies first
    sort(cookieSize.begin(), cookieSize.end());

    // Initialize a pointer for the
    // cookieSize array, starting
    // from the first cookie
    int l = 0;

    // Initialize a pointer for the
    // greed array, starting from
    // the first child
    int r = 0;

    // Iterate while there are
    // cookies and children
    // left to consider
    while (l < m && r < n) {
        // If the current cookie can
        // satisfy the current child's greed
        if (greed[r] <= cookieSize[l]) {
            // Move to the next child,
            // as the current child is satisfied
            r++;
        }
        // Always move to the next cookie
        // whether the current child
        // was satisfied or not
        l++;
    }

    // The value of r at the end of
    // the loop represents the number
    // of children that were satisfied
    return r;
}


int main() {
    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> cookieSize = {4, 2, 1, 2, 1, 3};
    
    cout << "Array Representing Greed: ";
    for(int i = 0; i < greed.size(); i++){
        cout << greed[i] << " ";
    }
    cout << endl;
    cout << "Array Representing Cookie Size: ";
    for(int i = 0; i < cookieSize.size(); i++){
        cout << cookieSize[i] << " ";
    }
    
    int ans = findContentChildren(greed, cookieSize);
    
    cout << endl << "No. of kids assigned cookies "<< ans;
    cout << endl;

    return 0;
}
       



Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in 
Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum 
number of coins and/or notes needed to make the change.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int V = 49;  // Change value
    vector<int> ans;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = sizeof(coins) / sizeof(coins[0]);

    for (int i = n - 1; i >= 0; i--) {
        if(V==0) break;
        if (V >= coins[i]) {
            int count = V / coins[i];  // Calculate how many coins/notes of coins[i] are needed
            V %= coins[i];             // Calculate the remaining amount
            for (int j = 0; j < count; j++) {
                ans.push_back(coins[i]);
            }
        }
    }

    cout << "The minimum number of coins is " << ans.size() << endl;
    cout << "The coins are: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

BUT IF THIS WAS NOT INDIAN CURRENCY BUT CAN BE ANYTHING WE NEEDED TO USE DP AS INDIANCURRECY ARE JUST MULTIPLE OF SMALLER.
see all.cpp:209 .


At a lemonade stand, each lemonade costs $5.
Given an array representing a queue of customers and the value of bills they hold, determine if it is possible to provide correct change 
to each customer. Customers can only pay with 5$, 10$ or 20$ bills and we initially do not have any change at hand. Return true, if it is
possible to provide correct change for each customer otherwise return false.
                            
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Function to find whether each customer can 
// be provided with correct change
bool lemonadeChange(vector<int>& bills) {
    
    // Initialize a counter
    // for $5 bills
    int five = 0; 
    
    // Initialize a counter
    // for $10 bills
    int ten = 0;   
    
    // Iterate through each customer's bill
    for(int i = 0; i < bills.size(); i++){
        
        // If the customer's
        // bill is $5
        if(bills[i] == 5){
            
            // Increment the
            // count of $5 bills
            five++;  
        }
        
        // If the customer's
        // bill is $10
        else if(bills[i] == 10){
            
            // Check if there are $5
            // bills available to give change
            if(five){
                 // Use one $5 bill
                 // to give change
                five--; 
                // Receive one $10 bill
                ten++;   
            }
            
            // If no $5 bill
            // available, return false
            else return false;  
        }
        
        // If the customer's
        // bill is $20
        else {
            // Check if there are both
            // $5 and $10 bills
            // available to give change
            if(five && ten){
                 // Use one $5 bill
                five--; 
                // Use one $10 bill
                ten--;   
            }
            // If there are not enough $10 bills,
            // check if there are at least
            // three $5 bills available
            else if (five >= 3){
                // Use three $5 bills
                // to give change
                five -= 3;  
            }
            // If unable to give
            // change, return false
            else return false;  
        }
    }
    
    // Return true if all customers
    // are served with correct change
    return true;  
}


int main() {
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << "Queues of customers: ";
    for(int bill : bills){
        cout << bill << " ";
    }
    cout << endl;
    bool ans = lemonadeChange(bills);
    if(ans)
        cout << "It is possible to provide change for all customers." << endl;
    else
        cout << "It is not possible to provide change for all customers." << endl;
    return 0;
}
                            


There is one meeting room in a firm. You are given two arrays, start and end each of size N.For an index ‘i’, start[i] denotes the 
starting time of the ith meeting while end[i]  will denote the ending time of the ith meeting. Find the maximum number of meetings that can
be accommodated if only one meeting can happen in the room at a  particular time. Print the order in which these meetings will be performed.


#include <bits/stdc++.h>
using namespace std;

struct meeting {
   int start;
   int end;
   int pos;
};

class Solution {
   public: 
      bool static comparator(struct meeting m1, meeting m2) {
      if (m1.end != m2.end) {
                  return m1.end < m2.end;  // Primary: sort by end time
            }
      return m1.start > m2.start;  // Secondary: if end times equal, prefer later start time
    }

// Sorting by descending start time within the same end time ensures that we fill the room's schedule more efficiently by leaving gaps for 
// shorter or earlier meetings. This approach helps maximize the number of non-overlapping meetings in the room.

   void maxMeetings(int s[], int e[], int n) {
      struct meeting meet[n];
      for (int i = 0; i < n; i++) {
         meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
      }

      sort(meet, meet + n, comparator);

      vector < int > answer;

      int limit = meet[0].end;
      answer.push_back(meet[0].pos);

      for (int i = 1; i < n; i++) {
         if (meet[i].start > limit) {
            limit = meet[i].end;
            answer.push_back(meet[i].pos);
         }
      }
      cout<<"The order in which the meetings will be performed is "<<endl;
      for (int i = 0; i < answer.size(); i++) {
         cout << answer[i] << " ";
      }

   }

};
int main() {
   Solution obj;
   int n = 6;
   int start[] = {1,3,0,5,8,5};
   int end[] = {2,4,5,7,9,9};
   obj.maxMeetings(start, end, n);
   return 0;
}





We are given two arrays that represent the arrival and departure times of trains that stop at the platform. We need to find the minimum 
number of platforms needed at the railway station so that no train has to wait.

#include<bits/stdc++.h>
 using namespace std;
 
 int countPlatforms(int n,int arr[],int dep[])
 {
    sort(arr,arr+n);
    sort(dep,dep+n);
 
    int ans=1;
    int count=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j]) //one more platform needed
        {
            count++;
            i++;
        }
        else //one platform can be reduced
        {
            count--;
            j++;
        }
        ans=max(ans,count); //updating the value with the current maximum
    }
    return ans;
 }
 
 int main()
 {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
 }










Given a list of job durations representing the time it takes to complete each job. Implement the Shortest Job First algorithm to find the 
average waiting time for these jobs.

#include <vector>   
#include <algorithm>
#include <iostream>

using namespace std;

// Function to calculate average
// waiting time using Shortest
// Job First algorithm
float shortestJobFirst(vector<int> jobs) {
    // Sort the jobs in ascending order
    sort(jobs.begin(), jobs.end()); 

    // Initialize total waiting time
    float waitTime = 0; 
    // Initialize total time taken
    int totalTime = 0; 
    // Get the number of jobs
    int n = jobs.size(); 

    // Iterate through each job
    // to calculate waiting time
    for(int i = 0; i < n; ++i) {
        
        // Add current total
        // time to waiting time
        waitTime += totalTime; 
        
        // Add current job's
        // time to total time
        totalTime += jobs[i]; 
    }
    
    // Return the average waiting time
    return waitTime / n; 
}

int main() {
    vector<int> jobs = {4, 3, 7, 1, 2};
    
    cout << "Array Representing Job Durations: ";
    for(int i = 0; i < jobs.size(); i++){
        cout << jobs[i] << " ";
    }
    cout << endl;
    
    float ans = shortestJobFirst(jobs);
    cout << "Average waiting time: "<< ans;
    cout << endl;

    return 0;
}
                            
       


The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total 
value obtained is maximized.

Note: We can either take the item as a whole or break it into smaller units.

#include <bits/stdc++.h>

using namespace std;

struct Item {
   int value;
   int weight;
};
class Solution {
   public:
      bool static comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
      }
   // function to return fractionalweights
   double fractionalKnapsack(int W, Item arr[], int n) {

      sort(arr, arr + n, comp);

      int curWeight = 0;
      double finalvalue = 0.0;

      for (int i = 0; i < n; i++) {

         if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
         } else {
            int remain = W - curWeight;
            finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
            break;
         }
      }

      return finalvalue;

   }
};
int main() {
   int n = 3, weight = 50;
   Item arr[n] = { {100,20},{60,10},{120,30} };
   Solution obj;
   double ans = obj.fractionalKnapsack(weight, arr, n);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}



You are given a set of N jobs where each job comes with a deadline and profit. The profit can only be earned upon completing the job within
its deadline. Find the number of jobs done and the maximum profit that can be obtained. Each job takes a single unit of time and only one 
job can be performed at a time.

#include<bits/stdc++.h>

using namespace std;
// A structure to represent a job 
struct Job {
   int id; // Job Id 
   int dead; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};
class Solution {
   public:
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
   //Function to find the maximum profit and the number of jobs done
   pair < int, int > JobScheduling(Job arr[], int n) {

      sort(arr, arr + n, comparison);
      int maxi = arr[0].dead;
      for (int i = 1; i < n; i++) {
         maxi = max(maxi, arr[i].dead);
      }

      int slot[maxi + 1];

      for (int i = 0; i <= maxi; i++)
         slot[i] = -1;

      int countJobs = 0, jobProfit = 0;

// As we have already sorted the array by profit ,at first we will encounter max profits. so we will keep filling the slots <=it's dead 
// line and this way we will fill with the max profits .

      for (int i = 0; i < n; i++) {
         for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               countJobs++;
               jobProfit += arr[i].profit;
               break;
            }
         }
      }

      return make_pair(countJobs, jobProfit);
   }
};
int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
} 






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
            if(i > reachable)
                return false;
            reachable = max(reachable,i+nums[i]);
        }
        return true;        
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
            // reset the start to the next station and reset the tank because before that station the cost > gas and if we include that
            // part we will never get the answer.
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


