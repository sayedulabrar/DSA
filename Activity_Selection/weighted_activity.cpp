#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Job {
    int start;
    int end;
    int profit;
};

bool compareJobs(const Job& a, const Job& b) {
    return a.start < b.start;
}

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), compareJobs);
        
        unordered_map<int, int> memo;
        return helper(jobs, 0, memo);
    }
    
    int helper(vector<Job>& jobs, int index, unordered_map<int, int>& memo) {
        if (index == jobs.size()) {
            return 0;
        }
        if (memo.count(index)) {
            return memo[index];
        }
        
        int nextIndex = findNextJob(jobs, index);
        
        maxProfit = max(jobs[index].profit + helper(jobs, nextIndex, memo), helper(jobs, index + 1, memo));

        memo[index] = maxProfit;
        
        return maxProfit;
    }
    // The function findNextJob returns the index of the next job whose start time is greater than or equal to the end time of the current job (main job),

int findNextJob(const vector<Job>& jobs, int index) {
    int left = index + 1, right = jobs.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (jobs[mid].start == jobs[index].end) {
            return mid;
        } else if (jobs[mid].start > jobs[index].end) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

};














Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at length 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at length 11, bursting the balloons [10,16] and [7,12]



[[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
if we don't consider min end our answer will be wrong.Becase if we don't take minimum end we might face a case where we are shooting ans arrow and in the over lapping case  6-7 and 8-12 comes for 1-10 as we sorted based on first.Now we can't shoot these 2 with same arrow even though they overlap.So we are taking minimum end every time to avoid this scene.If we do it based on end we will take minimum end all the time and if an end > it assigns new arrow and it solves the issue.It's not same as activity selection.

bool comp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) {
        return 0;
    }

    // Sort points based on the end of the intervals
    sort(points.begin(), points.end(), comp);
    
    int arrows = 1;  // We need at least one arrow initially
    int end = points[0][1];  // Set the end to the end of the first interval

    // Iterate through the points
    for (int i = 1; i < points.size(); ++i) {
        // If the start of the current point is greater than the end of the last arrow
        if (points[i][0] > end) {
            arrows++;  // We need a new arrow
            end = points[i][1];  // Update the end to the end of the current interval
        }
    }

    return arrows;
}