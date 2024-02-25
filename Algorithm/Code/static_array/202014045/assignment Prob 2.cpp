#include<iostream>

using namespace std;


class Array_Simulation{

int A[10];
int sz;
public:
Array_Simulation(int siz)
{

    for(int i=0;i<=siz;i++){
    A[i]=0;
    }
     sz=siz;
}
void add_value_to_all(int D)
{

    for(int i=0;i<=sz;i++){
    A[i]+=D;
    }

}
 void add_value_to_index(int i,int D)
{

    A[i]+=D;

}
 void multiply_value_to_all(int D)
{

     for(int i=0;i<=sz;i++){
    A[i]*=D;
    }


}
  void divide_value_to_all(int D)
{

    for(int i=0; i<=sz; i++)
        A[i]/=D;
}
 void Swap(int Y,int Z)
{

    int temp=A[Y];
    A[Y]=A[Z],
    A[Z]=temp;
}

void print()
{

    for(int i=1;i<=sz;i++)
    {
        cout<<A[i]<< ' ';

    }
     cout<<endl;
}
void reverse()
    {
    int i,j;
    j=sz;
    for(i=0;i<sz/2;i++)
    {
        int temp;
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        j--;
    }
    }
};
int main()
{
Array_Simulation a(5),b(4);
a.add_value_to_index(1,1);
a.add_value_to_index(2,2);
a.add_value_to_index(3,3);
a.add_value_to_index(4,4);
a.add_value_to_index(5,5);
a.print();
a.Swap(1,2);

a.add_value_to_all(1);

a.reverse();
a.print();
a.multiply_value_to_all(3);
a.print();
a.divide_value_to_all(2);
a.print();
b.add_value_to_index(1,2);
b.add_value_to_index(2,7);
b.add_value_to_index(3,8);
b.add_value_to_index(4,1);
b.multiply_value_to_all(10);
b.divide_value_to_all(5);
b.print();
return 0;
}
