// C++ implementation of Dynamic Array
#include <iostream>
#include <algorithm>
#include<stdio.h>
using namespace std;

template <class T> // this is a template class. It's helpful since we don't know what's the data of of the DAL that the user wants (int, float or some user-def Data type
class DynamicArray {
private:
    T * list; //a pointer that we'll use to store whatever data we need
    int max_size; //to store the current array's max possible size (it doubles, remember?)
    int length; //to store array's current length
public:
    DynamicArray() //a constructor function, it's called whenever a object of this class is created

    {
        // initially allocate a single memory block
        max_size = 2;
        list = new T[max_size];   // like int * a = new int [10], this is static
        length = 0;
    }

    // insert a new item to the end of the list
    void add(T item) {
        if (isFull()) {
            // create temporary list with double size
            max_size = 2 * max_size;
            T * temp_list = new T[max_size];
            cout<<"\nDAL Limit reached, new array created, values copied\n"<<endl;
            // move all the elements to the temporary list
            for (int i = 0; i < length; i++) {
                temp_list[i] = list[i];
            }

            // delete the old list
            delete [] list;

            // rename temp list
            list = temp_list;
        }

        // add the new item at the end of the list
        //the following portion is out of the if condition, since this will happen for both the cases
        //the if portion contains only the new array declaration and copying portion
        list[length] = item;

        length++;
    }

    void printList() {
        for (int i = 0; i < length; i++) {
            cout<<list[i]<<' ';
        }
        cout<<endl;
    }


    // check if the list is full
    bool isFull() {
        return length == max_size;

    }



    void Delete(int position)
{
    if (position < 0 || position >= length) {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = position + 1; i < length; i++) {
        list[i - 1] = list[i];
    }

    length--;
}

    void Insert(int position,T value)
    {
        int i;
        T * temp_list;
        if (isFull()) {
            max_size = 2 * max_size;
            temp_list = new T[max_size];
            cout<<"\nDAL Limit reached, new array created, values copied\n"<<endl;
            }else
            {
            temp_list=new T[max_size];
            }



            for ( i = 0; i < position; i++) {
                temp_list[i] = list[i];
            }
            temp_list[position]=value;
            for ( i=position;i<length;i++)
            {
                temp_list[i+1]=list[i];
            }


            delete [] list;

            list = temp_list;
            length++;


    }
   void deleteall(T value)
   {
       int l,n,i,k=0;
       T * temp_list;
       l=length;
       for(i=0;i<l;i++)
       {
           if(list[i]==value)
           {
              k++;
           }
       }

       temp_list=new T[l-k];


   int nextWrite = 0;
   for ( int nextRead = 0; nextRead < l; nextRead++ )
   {
      while ( list[nextRead] == value )
      {
          nextRead++;
      }
      if(nextWrite<l-k)
      {
      temp_list[nextWrite]=list[nextRead];
      nextWrite++;
      }

   }
   length=l-k;
    delete [] list;

    list = temp_list;
   }

   void replacevalue(T value,T it)
   {
       int bol=0;
       int i,k=0;
       for(i=0;i<length;i++)
       {
           if(list[i]==value)
           {
               list[i]=it;
               bol=1;
               k++;
           }
       }
       cout<<length<<endl;
       if(bol=0)
       {
           cout<<"No occurrence of"<<value<< "was found. No Items replaced."<<endl;

       }else
       {
           cout<<value<<" replaced with "<<it<<" Total "<<k<<" replacements."<<endl;
       }
   }


 void distinct_elements(){
     int n=length;
   // Sorting the array
   sort(list, list + n);
   // Traverse the sorted array
   int cnt = 0;
   for (int i = 0; i < n; i++){
      // Moving the index when duplicate is found
      while (i < n - 1 && list[i] == list[i + 1]){
         i++;
      }
      cnt++;
   }
   cout<<cnt<<endl;
}

    ~DynamicArray() //a destructor function, deallocates memory when the program closes/object is no longer needed
    {
        delete [] list;
    }


};

int main() {

    DynamicArray <int> list;

    int a, choice,pos,value,it;
    printf("\t\tDynamic Array List Implementation using Template Class.\n\t\t\tDo menu options 3-7 on your own.");


   while (1)
{


    printf("\n1.Add an element\n2.See current Elements\n3.Delete element from a particular position\n4.Insert at a particular position\n5.Delete matching values\n6.Replace matching values\n7. A unique function that you think can be beneficial for DALs\n\nPress any other key to terminate the program. ");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);



    if(choice==1)
    {
        printf("\nEnter a num to add: ");
        scanf("%d", &a);
        list.add(a);
    }

    else if (choice==2)
    {
        cout<<"The current dynamic array is: "<<endl;
        list.printList();
    }

     else if (choice==3)
    {
       cout<<"Enter Position to Delete from:"<<endl;
       cin>>pos;
       list.Delete(pos);

    }

    else if (choice==4)
    {
       cout<<"Enter Position to Insert Into: "<<endl;
       cin>>pos;
       cout<<"Enter the Value to insert:"<<endl;
       cin>>value;
       list.Insert(pos,value);
    }
    else if (choice==5)
    {
       cout<<"Enter the value to delete:"<<endl;
       cin>>value;
       list.deleteall(value);
    }
    else if (choice==6)
    {
       cout<<"Enter the value to replace:"<<endl;
       cin>>value;
       cout<<"Enter the value to be replaced by:"<<endl;
       cin>>it;
       list.replacevalue(value,it);
    }
    else if (choice==7)
    {
       /* Function to find number of unique elements in list*/

       list.distinct_elements();


    }

    else
    {
        printf("\n\t\tProgram Terminated\n\n");
    }


}

}
