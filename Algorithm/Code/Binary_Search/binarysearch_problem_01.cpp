#include <bits/stdc++.h>
using namespace std;


int FirstOccurrence(int arr[], int size, int x) {
    // If the array is empty, return -1
    if (size == 0) 
        return -1;

    // If the first element is the target, return its index
    if (arr[0] == x) 
        return 0;

    int l = 0, h = size - 1;
    while (l <= h) {
        int mid = (h + l) / 2;
        if (arr[mid] == x && arr[mid - 1] < x)
            return mid; // Found first occurrence
        else if (x > arr[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }

    return -1; // Not found
}




//number smaller than or equal x
// loop break hole h thake <x and l thake >x er paileto mid direct send.

int SmallerThanOrEqualTox(int arr[],int l,int h,int x,int n)
//Make sure target is in the l,h range before starting the search.
{   // if 1st number >x then all number >x.So not present.
    if(arr[0]>x) return -1;
    //Now 2 corner case.
    if(arr[-1]<=x) return sizeof(arr)-1; // 1 2 3 x
    if(arr[0]<=x) return 0;//x x+1 x+4 ...
    //1 2 3 x 5 9 ..
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
    else if(x<arr[mid])
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

    // If the last element is smaller than x, no element is greater than or equal to x
    if (arr[size - 1] < x) 
        return -1;

    // If the second last element is less than or equal to x and the last element is greater than or equal to x, return the last index
    if (arr[size - 2] <= x && arr[size - 1] >= x) 
        return size - 1;

    // If the first element is greater than x, return the first index
    if (arr[0] > x) 
        return 0;

    // Check each element using binary search
    int l = 0, h = size - 2; // Exclude size - 1 from the search range
    while (l <= h) {
        int mid = (h + l) / 2;
        if (arr[mid] == x)
            return mid + 1; // Return mid + 1 as it's the first index where arr[mid] >= x
        else if (x > arr[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }

    // If no exact match is found, return the index of the smallest element greater than x
    return l;
}


int last(int arr[], int size, int x) {
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
        else if (x >= arr[mid]) // Adjusted condition
            l = mid + 1;
        else
            h = mid - 1;
    }

    return -1; // Not found
}



int total(int arr[],int l,int h,int x,int n)
{
    if(l<=h)
    {
    int mid=(h+l)/2 ;
    if((arr[mid]==x&& mid==0) || (arr[mid]==x && arr[mid-1]<x))
    {
        counter=1;
        while(arr[++mid]==x && mid < n)
        {
            counter++;
        }
        return counter;
    }else if(x>arr[mid])
    {
        return total(arr,mid+1,h,x,n);
    }
    else if(x<=arr[mid])
    {
        return total(arr,l,mid-1,x,n);
    }


    }else
    {
        return -1;
    }

}
double biSection(double low, double high, double x){
    double mid = (high+low)/2.0;
    if(high-low<0.0001) return mid;

    if(mid*mid==x)  return mid;
    if(mid*mid>x)   return biSection(low,mid,x);
    return biSection(mid,high,x);
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
