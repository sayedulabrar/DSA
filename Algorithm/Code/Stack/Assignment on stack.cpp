#include<bits/stdc++.h>
using namespace std;

class Node{
private:
    int val;
    Node *next;

public:
    Node(){
        next = NULL;
    }

    int getValue(){
        return val;
    }
};

class Stack{
private:
    Node *head;
    int SIZE;
public:
    Stack(){
        head = NULL;
        SIZE = 0;
    }

    void push(int n){
        ///Stack functionality: Inserts n in the stack
        ///Linked list functionality: Creates a node and inserts at the head of the list
    }

    bool isEmpty(){
        ///Stack functionality: Returns true if the stack is empty, otherwise returns false
    }

    int top(){
        ///Stack functionality: Returns the last inserted value/top value of the stack (doesn't remove from stack)
        ///Linked list functionality: Returns the value located at head
        ///If the user calls this function for an empty stack, it will generate runtime error
    }

    void pop(){
        ///Stack functionality: Removes the top value of the stack
        ///Linked list functionality: if the list is not empty then removes the node under head and declares new head
        ///If the user calls this function for an empty stack, it will generate runtime error
    }

    int size(){
        ///Returns the size of stack
    }

    void displaystack(){
        ///Prints the stack
    }
};


int main(){
    int choice;

    while(choice!=0)
    {
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - View Top Item."<<endl;
        cout<<"4 - Size of Stack."<<endl;
        cout<<"5 - Display Items (Print STACK)."<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 0:
                break;

            case 1:
                break;

            case 2:
                ///Must check whether the stack is empty or not before popping
                break;

            case 3:
                ///Must check whether the stack is empty or not before viewing top item
                break;

            case 4:
                break;

            case 5:
                break;

            default:
                cout<<"An Invalid choice."<<endl;
        }

        cout<<endl<<endl;
    }


    return 0;
}
