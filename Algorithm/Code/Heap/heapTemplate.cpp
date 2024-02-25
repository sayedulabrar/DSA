#include<bits/stdc++.h>
using namespace std;

int a[101];
int n = 0;

void print(){
    cout<<endl;
    int newLine = 2;
    for(int i=1; i<=n; i++){
        cout<<a[i]<<" ";
        if(i==newLine-1){
            cout<<endl;
            newLine*=2;
        }
    }
    cout<<endl<<endl;
}

void printArray(){
    for(int i=1; i<=n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

bool heapInsert(int v){
    if(n==100)    return false;

}

int extractMax(){
    if(n==0)    return -9999;

}

void sort(){

}



void buildHeap(){

}

void increaseKey(int v1, int v2){

}

int size(){

}

int main(){
    cout<<"1. Insert\n2. Extract max\n3. Sort\n4. Increase Key\n5. Size\n6. Print\n7. Exit"<<endl;
    int choice;
    while(1){
        cin>>choice;
        if(choice==1){
            int v;
            cin>>v;
            heapInsert(v);
        }
        else if(choice == 2){
            int v = extractMax();
            cout<<v<<endl;
        }
        else if(choice==3){
            sort();
            printArray();
            buildHeap();
        }

        else if(choice==4){
            int v1, v2;
            cin>>v1>>v2;
            increaseKey(v1,v2);
        }
        else if(choice==5){
            int s = size();
            cout<<s<<endl;
        }
        else if(choice==6){
            print();
        }
        else{
            break;
        }
    }
}

/*
1 2
1 9
1 8
1 16
1 3
1 7
1 10
1 1
1 4
1 14
6
3
6
*/

