#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
#define MAX 3
class StackFull { }; // empty class body
class StackEmpty{ };  //empty class body
class Stack
{
      int S[MAX], top;
      public:
	Stack()
	{
	    top= -1;
    }
    void push(int v){
		if (top>= MAX-1)
            throw StackFull();
		S[++top] = v;
		}
    int pop(){
        if (top<0)
            throw StackEmpty();
		return S[top--];
		}
};
int main(){
    Stack st;
try{
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
cout<<st.pop()<<endl;
cout<<st.pop()<<endl;
cout<<st.pop()<<endl;
cout<<st.pop()<<endl;
}
catch(StackFull  F){
    cout<<"Exception: Stack is Full" <<endl;     }
catch(StackEmpty  E){
    cout<<"Exception: Stack is Empty" <<endl;      }
}
