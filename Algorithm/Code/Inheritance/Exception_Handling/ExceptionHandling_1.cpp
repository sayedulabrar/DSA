#include<bits/stdc++.h>
using namespace std;

double divide(double a, double b){
    if(b==0)
    {
        throw 1;
    }
 	 double result=a/b;
	 return result;
}

int main(){
    double a,b,c;
    cin>>a>>b;
    try
    {
        c=divide(a,b);//exception may arise
        cout<<c;
    }
    catch(int a){
        cout<<"Division by zero is not possible "<<a;
    }




}
