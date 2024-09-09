#include<iostream>
#include<string.h>
using namespace std;
class MyException{
    char message[30];
    public:
    MyException ( char* m)
    {
        strcpy(message, m);
    }
  char* getMessage(){ return message; }
};
double divide(double a, double b){
    if(b==0)
    {
        MyException ex("Division By Zero Exception");
        throw ex;
    }
 	 double result=a/b;
	 return result;
}
int main(){
   double a,b,c;
   cin>>a>>b;
   try{
	   c=divide(a,b);
	   cout<<c;
   }
   catch (MyException e){
       cout << "Code: ";
       cout << e.getMessage();
   }
}
