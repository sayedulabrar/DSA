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
    void setvalue(int v)
    {
        val=v;

    }
    void setnext(Node *t)
    {
        next=t;
    }
    Node* getnext()
    {
        return next;
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
        Node *nw;
        nw=(Node*)malloc(sizeof(Node));
        if(head==NULL)
    {
        nw->setvalue(n);
        nw->setnext(NULL);
        head=nw;
    }else
    {
	nw->setvalue(n);
    nw->setnext(head);
    head=nw;
    }
    SIZE++;
    }

    bool isEmpty(){
        if(head==NULL)
        {
            return true;
        }else
        {
            return false;
        }
    }

    int top(){
        if(head==NULL)
        {
            return -1;
        }else
        {
        int x;
        x=head->getValue();
        return x;
        }
    }

    int pop(){
        if(head==NULL)
        {
            return -1;
        }else
        {
        Node *n;
        n=head;
        head=head->getnext();
        free(n);
        SIZE--;
        return 1;
        }

    }

    int Size(){
        return SIZE;

    }

    void displaystack(){
         if(isEmpty()){
            cout<<"Stack is empty"<<endl;
	    }
	    else{
            cout<<"\nElements of Stack:"<<endl;
            Node *ni;
            ni=head;
            while(ni!=NULL)
            {
                cout<<ni->getValue()<<" " ;
                ni=ni->getnext();

            }
	    }
    }
};


int main(){
    int choice, n, value,xx,yy;
    Stack stk;

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
                 cout<<"Enter Value:\n";
                cin>>value;
                stk.push(value);
                break;

            case 2:
                yy=stk.pop();
                if(yy==-1){
                    cout<<"\nStack is empty!"<<endl;
                }
                else{
                    cout<<"value has been popped "<<endl;
                }
                break;

            case 3:
                xx=stk.top();
                cout<<"top item is "<<xx<<endl;
                break;

            case 4:
                yy=stk.Size();
                cout<<"Size of Stack is "<<yy<<endl;
                break;

            case 5:
                stk.displaystack();
                break;

            default:
                cout<<"An Invalid choice."<<endl;
        }

        cout<<endl<<endl;
    }


    return 0;
}
