///This is the simple binary search algorithm to find the first occurrence of x in an array
#include<bits/stdc++.h>
using namespace std;

int bsIterative(int a[], int n, int x){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(x==a[mid]){
            if(mid==0)  return mid;
            if(x!=a[mid-1]) return mid;
            high = mid-1;
        }
        else if(x<a[mid])   high=mid-1;
        else    low=mid+1;
    }
    return -1;
}

int bsRecursive(int a[], int low, int high, int x){
    if(low>high)    return -1;
    int mid = (low+high)/2;
    if(x==a[mid]){
        if(mid==0)  return mid;
        if(x!=a[mid-1]) return mid;
        return bsRecursive(a,low,mid-1,x);
    }
    else if(x<a[mid])   return bsRecursive(a, low, mid-1, x);
    else return bsRecursive(a, mid+1, high, x);
}

int main(){
    int a[10] = {0,5,5,5,5,16,25,25,25,52};
    int SIZE = 10;
    int x = 25; ///We will find first occurrence of x

    int index = bsIterative(a, SIZE, x);
    cout<<"Index of "<<x<<" is: "<<index<<" (Iterative)"<<endl;

    index = bsRecursive(a, 0, SIZE-1, x);
    cout<<"Index of "<<x<<" is: "<<index<<" (Recursive)"<<endl;
}

