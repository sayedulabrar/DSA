#include <iostream>
#include<stdio.h>
#include<vector>
using namespace std;

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


int getlength()
{
    return length;
}

    ~DynamicArray() //a destructor function, deallocates memory when the program closes/object is no longer needed
    {
        delete [] list;
    }


};

int main()
{
    char f,m,x;
    int l,p;
    DynamicArray <char> list;
    vector<int>v2;
    vector<char>v1;
    int i,j;

    ///Take one array for storing the original message and one for storing the coded message.
    ///decide whether to use DAL or SAL for each array

    int choice;

    cout<<"\t\t\tCSE 204 Online 1 Q1 - My Enigma Machine"<<endl;
    cout<<"\t\t\tCoded by Your StudentID HERE"<<endl;

    while (1)
    {
        cout<<"\n1. Enter Message to be sent \n2. Delete a letter from your message \n3. Cipher (code) the message \n4. Show both arrays (c=original and coded message) \n5.Exit "<<endl;
        cout<<"\nEnter Choice:";

        cin>>choice;

        if(choice==1)
        {
            cin>>p;
            getchar();

            for(i=0;i<p;i++)
    {
        cin>>f;
        list.add(f);
        v1.push_back(f);
    }
    for(i=p;i<8;i++)
    {
        f='-1';
        list.add(f);
        v1.push_back(f);
    }




        }

        else if(choice==2)
        {
            char c;
            cout<<"Enter the char to delete all occurrences of: ";
            cin>>c;
            list.deleteall(c);
            for(i=0;i<p;i++)
            {
                if(v1[i]==c)
                {
                    v1[i]='0';
                }
            }


            ///find all occurrences of of input char in the original message's array and delete them

        }

        else if(choice==3)
        {
            for(i=0;i<v1.size();i++)
    {
        if(v1[i]=='0')
        {
            i++;
        }
        m=v1[i];
        l=m;
        v2.push_back(l);
    }
            ///cipher the current message after taking input using option 1.
            ///append it into the coded message's array.

        }

        else if(choice==4)
        {
            for(j=0;j<v2.size();j++)
            {
                cout<<v2[j];
            }
            cout<<endl;
            list.printList();
            ///show the full coded msg array and current original message array

        }
        else if(choice==5)
        {
            break;
        }

        else
            cout<<"\n\nInvalid choice, enter again\n\n";

    }
}
