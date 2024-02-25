#include<bits/stdc++.h>
using namespace std;

///In this biSection method the process ends after the high-low is set to a value less than 0.0001
double biSection(double low, double high, double x){
    double mid = (high+low)/2.0;
    if(high-low<0.0001) return mid;

    if(mid*mid==x)  return mid;
    if(mid*mid>x)   return biSection(low,mid,x);
    return biSection(mid,high,x);

    ///if you set the difference from 0.0001 to 0.00000001 you will find that the output is more correct
    ///Means the more the difference is the result is more accurate
    ///The more the difference is the more steps are required to generate the solution
    ///The Next function deals with the fixed number of steps, not on the difference
}




///In this biSection method the process ends after completing total "step" number of recursive calls
double biSection(double low, double high, double x, int step){
    double mid = (high+low)/2.0;
    if(step==0) return mid;
    if(mid*mid==x)  return mid;
    if(mid*mid>x)   return biSection(low,mid,x,step-1);
    return biSection(mid,high,x,step-1);

    ///This function deals with the fixed number of steps, not on the difference of high and low
    ///The process runs for a fixed number of steps
    ///The more the step, the result will be more accurate
}

int main(){
    double x=25.0; ///We will calculate the square root of x

    cout<<"Square root of "<<x<<" is (by Method-1): "<<biSection(0.0, x, x)<<endl;
    cout<<"Square root of "<<x<<" is (by Method-2): "<<biSection(0.0, x, x, 30)<<endl;

    ///If you see the output of Method-2, this is very much close to the correct output
    ///So it took only 30 steps to get close to the correct solution
    ///Means bisection method can generate correct output after a very less number of steps
    ///Because it keeps dividing by 2 at every step and that sets the difference (high-low) at a constant value after a certain number of steps
}
