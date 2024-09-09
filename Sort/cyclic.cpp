as we ignored the negative and outofbound but sorted the positive numbers then the we can consider those negative and outofbound nubers to be 
taking place of missing positive .But even if those are not in array then we can easily find it normally. {3, -1, 4, 1} to {1, -1, 4, 3}


int firstMissingPositive(vector<int>& arr) {
    int i = 0;
    while (i < arr.size()) {
        int correct = arr[i] - 1; // as it start from 1 if value arr[i] index will be arr[i]-1.
        if (arr[i] > 0 && arr[i] <= arr.size() && arr[i] != arr[correct]) {
            swap(arr[i], arr[correct]);
        } else {
            i++;
        }
    }

    // Search for the first missing positive
    for (int index = 0; index < arr.size(); index++) {
        if (arr[index] != index + 1) {
            return index + 1;
        }
    }

    // If all positive integers from 1 to arr.size() are present, return arr.size() + 1
    return arr.size() + 1;
}




Duplicate finding and missing number using cyclic sort
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            int correct = nums[i] - 1;
            if (nums[i] != nums[correct]) {
                swap(nums[i],nums[correct]);
            } else {
                i++;
            }
        }

        // search for first missing number
        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] != index + 1) {
                return vector<int>{nums[index], index + 1};
            }
        }
        return vector<int>{-1, -1};
    }


};

nums=2 1 7 4 4 6 3
-->
1 2 ..
1 2 ..
1 2 3 4 4 6 7
..
..
so duplicate shob serially ashbe.So if i want to find the duplicate then we can find it by checking 
index+1!=nums[index] and it will be the place where missing number is too.

           