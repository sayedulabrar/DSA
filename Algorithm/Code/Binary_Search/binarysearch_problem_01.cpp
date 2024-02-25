#include <bits/stdc++.h>
using namespace std;

int counter=0;
int first(int arr[],int l,int h,int x,int n)
{
    if(l<=h)
    {
    int mid=(h+l)/2 ;
    if((arr[mid]==x&& mid==0) || (arr[mid]==x && arr[mid-1]<x))
    {
        return mid;
    }else if(x>arr[mid])
    {
        return first(arr,mid+1,h,x,n);
    }
    else if(x<=arr[mid])
    {
        return first(arr,l,mid-1,x,n);
    }


    }else
    {
        return -1;
    }

}

int smaller(int arr[],int l,int h,int x,int n)
{
    if(l<=h)
    {
    int mid=(h+l)/2 ;
    if((arr[mid]==x&& mid==0) || (arr[mid]==x && arr[mid-1]<x))
    {
        return mid-1;
    }else if(x>arr[mid])
    {
        return smaller(arr,mid+1,h,x,n);
    }
    else if(x<=arr[mid])
    {
        return smaller(arr,l,mid-1,x,n);
    }


    }else
    {
        return -1;
    }

}



int last(int arr[],int l,int h,int x,int n)
{
    if(l<=h)
    {
    int mid=(h+l)/2 ;
    if((arr[mid]==x&& mid==n-1) || (arr[mid]==x && arr[mid+1]>x))
    {
        return mid;
    }else if(x>=arr[mid])
    {
        return last(arr,mid+1,h,x,n);
    }
    else if(x<arr[mid])
    {
        return last(arr,l,mid-1,x,n);
    }


    }else
    {
        return -1;
    }

}

int total(int arr[],int l,int h,int x,int n)
{
    use 1st and last Occurrence to find the total.

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
