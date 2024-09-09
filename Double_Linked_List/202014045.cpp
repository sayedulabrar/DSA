#include<bits/stdc++.h>
using namespace std;

struct Node{
    int v;
    Node *L, *R;
}*head,*tail;


void init(){
    head = NULL;
    tail = NULL;
}


void createFirstElement(int x){
    head=(Node*)malloc(sizeof(Node));
    head->v=x;
    head->R=NULL;
    head->L=NULL;
    tail=head;

}

void insertFirst(int x){
    if(head==NULL)
    {
        createFirstElement(x);
    }else
    {
    struct Node * newNode ;
	newNode = (struct Node*) malloc (sizeof(struct Node)) ;
	newNode-> v = x ;
	newNode->L=NULL;
	head->L=newNode;
	newNode->R=head;
	head=newNode;
    }
}

void insertLast(int x){
    struct Node * newNode ;
	newNode = (struct Node*) malloc (sizeof(struct Node)) ;
	newNode-> v = x ;
	tail->R=newNode;
	newNode->L=tail;
	tail=newNode;
	tail->R=NULL;

}

Node* findFirstOccurrence(int x){
    struct Node *n;
    n=head;
    while(n!=NULL && n->v!= x)
    {
        n=n->R;
    }
    if(n==NULL)
    {
        cout<<"Not present in the list"<<endl;
    }
    else
    {
        return n;
    }

}

Node* findLastOccurrence(int x){
    struct Node *n;
    n=tail;
    while(n!=NULL && n->v!= x)
    {
        n=n->L;
    }
    if(n==NULL)
    {
        cout<<"Not present in the list"<<endl;
        return 0;
    }
    else
    {
        return n;
    }

}



Node* findMiddleElement()
{
 struct Node *slow = head;
 struct Node *fast = tail;

 struct Node *tempslow = head;
while(slow!=fast || tempslow==fast){
    tempslow=slow;
    slow=slow->R;
    fast=fast->L;


}
return fast;

}

void deleteHead(){
    struct Node *n;
    if(head!=NULL)
    {
        n=head;
        head=head->R;
        if(head!=NULL)
        {
           head->L=NULL;
        }

    free(n);
    }

}

void deleteTail() {
    struct Node *n;
    if(tail!=NULL)//**
    {
        n=tail;
        tail=tail->L;
        if(tail!=NULL)
        {
         tail->R=NULL;
        }

        free(n);
    }

}

void deleteFirstOccurrence(int x){
    struct Node *temp,*temp1,*temp2;
    temp=findFirstOccurrence(x);
    if(temp==head)
    {
        deleteHead();
    }
    else if(temp==tail)
    {
        deleteTail();
    }else
    {
        temp1=temp->L;
        temp2=temp->R;
        temp1->R=temp->R;
        temp2->L=temp->L;
        free(temp);
    }


}

void deleteLastOccurrence(int x){
    struct Node *temp,*temp1,*temp2;
    temp=findLastOccurrence(x);
    if(temp==head)//***
    {
        deleteHead();
    }
    else if(temp==tail)//***
    {
        deleteTail();
    }else
    {
        temp1=temp->L;
        temp2=temp->R;
        temp1->R=temp->R;
        temp2->L=temp->L;
        free(temp);
    }



}

void sortList(){
    struct Node *ptr1, *lptr;

    if (head == NULL || head->R == NULL) {
        return; // If the list is empty or has only one node, it is already sorted
    }
    else {
        for (ptr1 = head; ptr1->R->R != NULL; ptr1 = ptr1->R) {
            for (lptr = ptr1->R; lptr!= NULL; lptr = lptr->R) {
                if (ptr1->v > lptr->v) {
                    swap(ptr1->v, lptr->v);
                }
            }
        }
    }
}


void printList(){
    cout<<"List is: ";
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->v<<" ";
        temp = temp->R;
    }
}

int length(){
    int l=0;
    Node *temp = head;
    while(temp!=NULL){
        temp = temp->R;
        l++;

    }
    return l;


}

void printMessage(){
    cout<<"1. Insert first"<<endl;
    cout<<"2. Insert last"<<endl;
    cout<<"3. Delete head"<<endl;
    cout<<"4. Delete tail"<<endl;
    cout<<"5. Delete first occurrence"<<endl;
    cout<<"6. Delete last occurrence"<<endl;
    cout<<"7. Find middle element"<<endl;
    cout<<"8. Sort list"<<endl;
    cout<<"9. Print list"<<endl;
    cout<<"10. Length"<<endl;
    cout<<"11. Exit"<<endl<<endl;
}

int main(){
    init();
    printMessage();
    while(1){
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;

        if(choice==1){
            cout<<"Enter the value: ";
            int x;
            cin>>x;
            insertFirst(x);
        }
        else if(choice==2){
            int x;
            cin>>x;
            insertLast(x);
        }
        else if(choice==3){
            deleteHead();
        }
        else if(choice==4){
            deleteTail();
        }
        else if(choice==5){
            int x;
            cin>>x;
            deleteFirstOccurrence(x);
        }
        else if(choice==6){
            int x;
            cin>>x;
            deleteLastOccurrence(x);
        }
        else if(choice==7){
            Node *p = findMiddleElement();
            cout<<"Middle element is: "<<p->v;
        }
        else if(choice==8){
            sortList();
        }
        else if(choice==9){
            printList();
        }
        else if(choice==10){
            int l = length();
            cout<<"Length of the list is: "<<l;
        }
        else if (choice == 11){
            break;
        }
        else{
            cout<<"Invalid input";
        }
        cout<<"___________________________"<<endl<<endl;
    }
}
