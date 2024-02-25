#include<bits/stdc++.h>
using namespace std;
map<int,int>pq;

struct ar{
int id;
int value;
};

ar a[101];
int n = 0;


void print(){
    cout<<endl;
    int newLine = 2;
    for(int i=1; i<=a[0].value; i++){
        cout<<a[i].value<<" ";
        if(i==newLine-1){
            cout<<endl;
            newLine*=2;
        }
    }
    cout<<endl<<endl;
}

void printArray(){
    for(int i=1; i<=a[0].value; i++) cout<<a[i].value<<" ";
    cout<<endl;
}

void heapify(int i)
{
    int smallest = i;
    int l = 2 * i;
    int r = 2 * i + 1;


    if (l <= n && a[l].value < a[smallest].value)
        smallest = l;

    if (r <= n && a[r].value < a[smallest].value)
        smallest = r;

    if (smallest != i) {
        swap(a[i].value, a[smallest].value);
        swap(a[i].id, a[smallest].id);
        pq[a[i].id]=smallest;
        pq[a[smallest].id]=i;
        heapify(smallest);
    }
}


bool insertt(int v,int cd)
{
    if(n==100)    return false;
    n++;
    ar x;
    x.id=cd;
    x.value=v;
    a[n]=x;
    a[0].value++;
    int i=n;
    pq[cd]=n;

    while(i!=1)
    {
        int p=i/2 ;
        if(a[i].value<a[p].value)
        {
            swap(a[i].value,a[p].value);
            swap(a[i].id,a[p].id);
            pq[a[p].id]=i;
            pq[a[i].id]=p;
            i=p;
        }else
        {
            break;
        }
    }
    return true;

}

int extractmin()
{
    if(n==0)    return 9999;
    int x=a[1].value;
    swap(a[1].value,a[n].value);
    swap(a[1].id,a[n].id);
    pq[a[n].id]=1;
    pq[a[1].id]=n;
    n--;
    a[0].value--;
    heapify(1);
    return x;
}

void decreasekey(int c,int d)
{
    int xx=pq[c];
    if(d<a[xx].value)
    {
        a[xx].value=d;
        while(xx!=1)
    {
        int p=xx/2 ;
        if(a[xx].value<a[p].value)
        {
            swap(a[xx].value,a[p].value);
            swap(a[xx].id,a[p].id);
                pq[a[xx].id]=p;
                pq[a[p].id]=xx;

            xx=p;
        }else
        {
            break;
        }
    }
    }else
    {
        cout<<"the new key value is greater than current value"<<endl;
    }

    }


void buildHeap(){

for (int i = n / 2 ; i > 0; i--)
        heapify(i);
}


void sort(){

        buildHeap();
        int xx=n;
        for(int j=xx;j>=2;j--){

            swap(a[j],a[1]);
            n--;
            heapify(1);

        }
        n=a[0].value;


}

int size()
{
    return n;
}

int top()
{
    if (n==0) return 9999;
    else
    {
        return a[1].value;
    }
}

int main(){
    cout<<"1. Insert\n2. Extract min\n3. Sort\n4. decrease Key\n5. Size\n6. Print\n7. top\n8. Exit"<<endl;
    int choice;
    ar aa;
   aa.id=0;
   aa.value=0;
   a[0]=aa;
    while(1){
        cin>>choice;
        if(choice==1){
            int v,d;
            cin>>v>>d;
            bool s=insertt(v,d);
            if(s==false)
            {
                cout<<"heap is full"<<endl;
            }else
            {
                cout<<"item has been inserted"<<endl;
            }
        }
        else if(choice == 2){
            int v = extractmin();
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
            decreasekey(v1,v2);
        }
        else if(choice==5){
            int s = size();
            cout<<s<<endl;
        }
        else if(choice==6){
            print();
        }
        else if(choice==7){
            int zz=top();
        }
        else
        {
            break;
        }
    }
}
