#include<bits/stdc++.h>
using namespace std;

class Node{
private:
    char val;
    Node *next;

public:
    Node(){
        next = NULL;
    }

    char getValue(){
        return val;
    }
    void setvalue(char v)
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

    void push(char n){
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

    char top(){
        if(head==NULL)
        {
            return -1;
        }else
        {
        char x;
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
        char x=head->getValue();
        head=head->getnext();
        free(n);
        SIZE--;
        return x;
        }

    }

    int Size(){
        return SIZE;

    }

    void displaystack(){
         if(isEmpty()){
            cout<<"Stack is empty: 0"<<endl;
	    }
	    else{
            Node *ni;
            ni=head;
            while(ni!=NULL)
            {
                cout<<ni->getValue()<<" " ;
                ni=ni->getnext();

            }
            cout<<endl;
	    }
    }
};

void sortstack(Stack st)
    {
        Stack tmp;
        int b;
        while(st.isEmpty()==false)
    {
        b=st.top();
        st.pop();
        while(tmp.isEmpty()==false && tmp.top()<b)
        {
            st.push(tmp.top());
            tmp.pop();
        }
        tmp.push(b);

    }
    cout<<"Sorted Stack is :"<<endl;
    tmp.displaystack();
    }

bool balance(string st)
{
    Stack ss;
    char ch;


    for (int i = 0; i < st.length(); i++)
    {
        if (st[i]== '(' || st[i]=='[' || st[i] == '{')
        {
            ss.push(st[i]);
        }

       else if(st[i]== ')' || st[i]==']' || st[i] == '}')
       {
           if(st[i]==')')
           {
              ch = ss.top();
            if(ch=='(')
            {
                ss.pop();
            }else if (ch == '{' || ch == '[')
            {
                return false;
            }

           }
           else if(st[i]=='}')
           {
               ch = ss.top();
            if(ch=='{')
            {
                ss.pop();
            }else if (ch == '(' || ch == '[')
                      {
                          return false;
                      }



           }
           else if(st[i]==']')
           {
               ch = ss.top();
            if(ch=='[')
            {
                ss.pop();
            }else if (ch == '(' || ch == '{')
                      {
                         return false;
                      }

           }



        }
    }
    ss.displaystack();



    return (ss.isEmpty());
}





int main(){
    int choice, n, value,xx,yy;
    Stack stk;
    string sp;
    cin>>sp;
    cout<<sp;

    bool s=balance(sp);
    if(s==true)
     {
         cout<<"balanced"<<endl;
     }else{

     cout<<"not balanced"<<endl;
     }
    //unsigned num_of_disks = 4;

    //Stack src, dest, aux;
    //Iterative(num_of_disks, src, aux, dest);

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
                    cout<<"value has been popped "<<yy<<endl;
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

//////////////////////////////
void moveDisksBetweenTwoPoles( Stack &srcc,
             Stack &destt)
{
    int pole1TopDisk = srcc.pop();
    int pole2TopDisk = destt.pop();


    int j;


    if (pole1TopDisk == -1)
    {
        srcc.push(pole2TopDisk);


    }


    else if (pole2TopDisk == -1)
    {
        destt.push(pole1TopDisk);


    }


    else if (pole1TopDisk > pole2TopDisk)
    {
        srcc.push(pole1TopDisk);
        srcc.push(pole2TopDisk);


    }

    else
    {
        destt.push(pole2TopDisk);
        destt.push(pole1TopDisk);


    }

}



 void Iterative(int num_of_disks, Stack src,Stack aux,Stack dest)
{
    int i, total_num_of_moves;



    total_num_of_moves = pow(2, num_of_disks) - 1;


      for (i = num_of_disks; i >= 1; i--)
      {
          src.push(i);
      }
      src.displaystack();
     aux.displaystack();
     dest.displaystack();
      cout<<endl;
     cout<<endl;



    for (i = 1; i <= total_num_of_moves; i++)
    {
        if (i % 3 == 1){
            moveDisksBetweenTwoPoles(src, dest);
        }

        else if (i % 3 == 2)
        {
            moveDisksBetweenTwoPoles(src, aux);
        }

        else if (i % 3 == 0)
        {
         moveDisksBetweenTwoPoles(aux, dest);
        }
     src.displaystack();
     aux.displaystack();
     dest.displaystack();
     cout<<endl;
     cout<<endl;



    }
}


