#include<bits/stdc++.h>

using namespace std;

class Stack{
private:
    int top;
    int capacity;
    int *arr;

public:
    Stack(int n){
        top=-1;
        capacity=n;
        arr=new int[capacity];
    }

    int isStackFull(){
        if(top==capacity-1){
            return 1;
        }
        else{
            return 0;
        }
	}

	int isStackEmpty(){
        if(top==-1){
            return 1;
        }
        else{
            return 0;
        }
	}


	int push(int val){
	    if(isStackFull()){      ///top=-1; capacity=5;
            return 0;           ///push(5);
	    }
	    else{
            top++;                  ///top=0; arr[0]=5;
            arr[top]=val;           /// top=4;
            return 1;
        }                       ///push(9);
	}

	int pop(){
        if(isStackEmpty()){
            return -1;
        }
        else{
            int tmp;
            tmp=arr[top];
            top--;
            return tmp;
        }
	}



	void displaystack(){
	    if(isStackEmpty()){
            cout<<"Stack is empty"<<endl;
	    }
	    else{
            cout<<"\nElements of Stack:"<<endl;
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" "<<endl;
            }
	    }

	}

};








int main(){

    int choice, n, value,xx,yy;
    Stack stk(5);
    while(choice!=0)
    {
        cout<<endl;
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - Display Items (Print STACK)."<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 0:
                break;

            case 1:
                cout<<"Enter Value:\n";
                cin>>value;
                xx=stk.push(value);
                if(xx==0){
                    cout<<"\nStack is full (overflow)"<<endl;
                }
                else{
                    cout<<value<<" is pushed into stack"<<endl;
                }
                break;

            case 2:
                yy=stk.pop();
                if(yy==-1){
                    cout<<"\nStack is empty! (Underflow condition"<<endl;
                }
                else{
                    cout<<"Popped value is "<<yy<<endl;
                }
                break;

            case 3:

                stk.displaystack();
                break;

            default:
                cout<<"An Invalid choice."<<endl;
        }
    }


    return 0;


}

