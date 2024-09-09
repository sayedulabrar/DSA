#include <bits/stdc++.h>
using namespace std;


int FirstOccurrence(int arr[], int size, int x) {
    // If the array is empty, return -1
    if (size == 0) 
        return -1;

    // If the first element is the target, return its index
    if (arr[0] == x) 
        return 0;

    if(arr[size-1]==x && arr[size-2]<x) return size-1;

    int l = 1, h = size - 2;
    while (l <= h) {
        int mid = (h + l) / 2;
        if (arr[mid] == x && arr[mid - 1] < x)
            return mid; // Found first occurrence
        else if (x > arr[mid])
            l = mid + 1;
        else
            h = mid - 1;  //  as we took mid-1 so we are checking mid and mid-1 which is left side and h=mid-1 take us left .
    }

    return -1; // Not found
}




//number smaller than or equal x
// loop break hole h thake <x and l thake >x er paileto mid direct send.

int SmallerThanOrEqualTox(int arr[],int l,int h,int x,int n)
//Make sure target is in the l,h range before starting the search.
{   // if 1st number >x then all number >x.So not present.
    if(arr[0]>x) return -1;

    while(l<=h)
    {
    int mid=(h+l)/2 ;
    if(arr[mid]==x) //no and condition so at last it is else if
    {
     return mid;
        
    }else if(x>arr[mid])
    {
        l=mid+1;
    }
    else 
    { 
        h=mid-1;  
    }

    }
    return h;
}



int GreaterThanOrEqualTox(int arr[], int size, int x) {
    // If the array is empty, return -1
    if (size == 0) 
        return -1;

    // If the first element is greater than or equal to x, return the first index
    if (arr[0] >= x) 
        return 0;

    // If the last element is smaller than x, no element is greater than or equal to x
    if (arr[size - 1] < x) 
        return -1;

    // Binary search for the first element greater than or equal to x
    int l = 0, h = size - 1;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        
        if (arr[mid] == x) {
            return mid; // Return mid as it's the index where arr[mid] == x
        } else if (arr[mid] < x) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    // If no exact match is found, return the index of the smallest element greater than x
    return l >= size ? -1 : l;
}




int lastOccurrence(int arr[], int size, int x) {
    // If the array is empty, return -1
    if (size == 0) 
        return -1;

    // If the last element is the target, return its index
    if (arr[size - 1] == x) 
        return size - 1; 

    // Check if x is the only element in the array
    if (arr[0] == x && arr[1] > x) 
        return 0;

    int l = 1, h = size - 2; // Start the search from index 1
    while (l <= h) {
        int mid = (h + l) / 2;
        if (arr[mid] == x && arr[mid + 1] > x) // Corrected condition
            return mid; // Found last occurrence
        else if (x < arr[mid]) // Adjusted condition
            
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1; // Not found
}



int total(int arr[],int l,int h,int x,int n)
{
    x*(lastOccurrence-FirstOccurrence+1);

}
double biSection(double low, double high, double x){
    double mid = (high+low)/2.0;
    if(high-low<0.0001) return mid;

    if(mid*mid==x)  return mid;
    if(mid*mid>x)   return biSection(low,mid,x);
    return biSection(mid,high,x);
}




int search_infinite_array{ 
    int start = 0;
    int end = 1;

        // condition for the target to lie in the range
        while (target > arr[end]) {
            int temp = end + 1; // this is my new start
            // double the box value
            // end = previous end + sizeofbox*2
            end = end + (end - start + 1) * 2;
            start = temp;
        }
        return binarySearch(arr, target, start, end);

    }


int mountain_peak(){
int n=arr.size();
if(arr[0]>arr[1]) return 0;
if(arr[n-1]>arr[n-2]) return n-1;
while(start<=end){
if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]) return mid;
if(arr[mid]<arr[mid+1]) start=mid+1;
else if(arr[mid]>arr[mid+1]) end=mid-1;
}


}






int main()
{
	int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
	int n = sizeof(arr) / sizeof(int);

	int x = 8;
	printf("First Occurrence = %d\t",first(arr, 0, n - 1, x, n));
	printf("\nLast Occurrence = %d\n",last(arr, 0, n - 1, x, n));
	printf("\ntotal Occurrence = %d\n",total(arr, 0, n - 1, x, n));
	printf("total numbers smaller than x Occurrence = %d\t",smaller(arr, 0, n - 1, x, n)+1);
	double xx=8.0;
	cout<<"Square root of "<<x<<" is : "<<biSection(0.0, xx, xx)<<endl;


	return 0;
}




33. Search in Rotated Sorted Array
class Solution {
public:
int findPivot(const vector<int>& nums) {
    int start = 0, end = nums.size() - 1;

    // Handle the case where the array is not rotated
    if (nums[start] < nums[end]) {
        return 0;
    }

    // Check if start or end is the pivot
    if (nums[start] > nums[start + 1]) {
        return start + 1;
    }
    if (nums[end - 1] > nums[end]) {
        return end;
    }

    // Binary search for the pivot
    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Check if mid is the pivot
        if (nums[mid] > nums[mid + 1]) {
            return mid + 1;
        }
        if (nums[mid - 1] > nums[mid]) {
            return mid;
        }

        // Adjust search range
        if (nums[mid] >= nums[start]) { ///>= to handle duplicates
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return 0; // Default return for a non-rotated array
}

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        // Check if the array is rotated
        if (nums[0] > nums[n - 1]) {
            int pivot = findPivot(nums);
            // Binary search in the appropriate half
            if (target >= nums[0] && target <= nums[pivot - 1]) {
                return binarySearch(nums, 0, pivot - 1, target);
            } else {
                return binarySearch(nums, pivot, n - 1, target);
            }
        } else {
            // Array is not rotated, perform normal binary search
            return binarySearch(nums, 0, n - 1, target);
        }
    }


    int binarySearch(const vector<int>& nums, int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }
};
















split the array into m subarray and minimize the maxsum of those m subarray .
int splitArray(int[] nums, int m) {
        int start = 0;
        int end = 0;

        for (int i = 0; i < nums.length; i++) {
            start = Math.max(start, nums[i]); // in the end of the loop this will contain the max item of the array
            end += nums[i];
        }

        // binary search
        while (start < end) {
            // try for the middle as potential ans
            int mid = start + (end - start) / 2;

            // calculate how many pieces you can divide this in with this max sum
            int sum = 0;
            int pieces = 1;
            for(int num : nums) {
                if (sum + num > mid) {
                    // you cannot add this in this subarray, make new one
                    // say you add this num in new subarray, then sum = num
                    sum = num;
                    pieces++;
                } else {
                    sum += num;
                }
            }

            if (pieces > m) {
                start = mid + 1;
            } else if(pieces<m){
                end = mid-1;
            }else{
                end=mid;
            }//suppose it reached m and end becomes mid then we will try to go farther to right to find if there exist any solution smaller.so it works.

        }
        return end; // here start == end
    }
