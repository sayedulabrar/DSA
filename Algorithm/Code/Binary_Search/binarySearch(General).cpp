///This is the simple binary search algorithm to find x from an array
#include<bits/stdc++.h>
using namespace std;

int bsIterative(int a[], int n, int x){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(x==a[mid])   return mid;
        else if(x<a[mid])    high=mid-1;
        else    low=mid+1;
    }
    return -1;
}

int bsRecursive(int a[], int low, int high, int x){
    if(low>high)    return -1;
    int mid = (low+high)/2;
    if(x==a[mid])  return mid;
    else if(x<a[mid])   return bsRecursive(a, low, mid-1, x);
    else return bsRecursive(a, mid+1, high, x);
}

int main(){
    int a[10] = {0,5,8,9,10,16,25,26,29,52};
    int x = 25;
    int SIZE = 10;
    int index = bsIterative(a, SIZE, x);
    cout<<"Index of "<<x<<" is: "<<index<<" (Iterative)"<<endl;

    index = bsRecursive(a, 0, SIZE-1, x);
    cout<<"Index of "<<x<<" is: "<<index<<" (Recursive)"<<endl;
}
