#include<bits/stdc++.h>
using namespace std;

struct Node{
    int v;
    Node *L, *R;
};

Node *head, *tail;

void init(){
    head = NULL;
    tail = NULL;
}

void createFirstElement(int x){
    head = (Node*)malloc(sizeof(Node));
    head -> v = x;
    head -> L = NULL;
    head -> R = NULL;
    tail = head;
}

void insertFirst(int x){

}

void insertLast(int x){

}

Node* findFirstOccurrence(int x){

}

Node* findLastOccurrence(int x){

}

Node* findMiddleElement(){

}

void deleteHead(){

}

void deleteTail() {

}

void deleteFirstOccurrence(int x){

}

void deleteLastOccurrence(int x){

}

void sortList(){

}

void printList(){
    /*cout<<"List is: ";
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->v<<" ";
        temp = temp->R;
    }*/
}

int length(){

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
