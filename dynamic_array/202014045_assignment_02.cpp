#include <iostream>
#include<stdio.h>
#include<cstring>
#include<string.h>

using namespace std;
struct library
{
    char bk_name[30];
    char author[30];
    int pages;
    float price;
    int quantity;

};



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

    void printlist() {
        for (int i =0; i<length;i++)
        {
            cout<<"\nyou have entered the following information\n"<< i+1<<endl;
            printf ("\nBook name: %s, Author: %s, Pages: %d, Price:%.2f, Available copies: %d\n",list[i].bk_name,list[i].author,list[i].pages,list[i].price, list[i].quantity);

        }
    }


    // check if the list is full
    bool isFull() {
        return length == max_size;

    }
    void Delete(int position)
    {
        int i,l;
        l=length-1;
        T * temp_list = new T[l];

        for(i=0;i<position;i++)
        {
            temp_list[i] = list[i];
        }
        for(i=position;i<l;i++)
        {
            temp_list[i] = list[i+1];
        }
        delete [] list;


        list = temp_list;

        length--;



    }



    void infoaccordingtoauthor(struct library trmp)
    {
       int i,check_flag=0;
for (i=0; i<length; i++)
{
if (strcmp(trmp.author,list[i].author) == 0)
{
    printf ("\nBook name: %s, Author: %s, Pages: %d, Price:%.2f, Available copies: %d\n",list[i].bk_name,list[i].author,list[i].pages,list[i].price, list[i].quantity);
    check_flag=1;

}

}

if(check_flag==0)
    printf("No books of author %s is currently available in the library\n",trmp.author);

    }

 void infoaccordingtobook(struct library tmp)
 {
int i,check_flag=0;
for (i=0; i<length; i++)
{
if (strcmp(tmp.bk_name, list[i].bk_name) == 0)
{
   printf ("\nBook name: %s, Author: %s, Pages: %d, Price:%.2f, Available copies: %d\n",list[i].bk_name,list[i].author,list[i].pages,list[i].price, list[i].quantity);
   check_flag=1;
}

}

if(check_flag==0)
    printf("No book titled '%s' is available in the library currently\n", tmp.bk_name);



 }
 void availablebook()
 {
     printf("\n Number of total available titles in library :\n %d", length);
 }
void checkoutbook(struct library trump)
{


    int i,check_flag=0;
    for (i=0; i<length; i++)
    {
    if (strcmp(trump.bk_name, list[i].bk_name) == 0)
    {
       printf ("\nBook titled '%s' (Author: %s, Pages: %d, Price:%.2f) found. \nCurrently Available copies (before check out): %d\n",list[i].bk_name,list[i].author,list[i].pages,list[i].price, list[i].quantity);
       if(list[i].quantity>0)
        {
            list[i].quantity -= 1;
            printf("\n\nChecked out Successfully!!\n\n");
        }

       else
        printf("\nNot enough copies available to check out.  Buy more or wait for check-ins! ");

       check_flag=1;
    }

    }

    if(check_flag==0)
        printf("No book titled %s is available in the library to check out! Buy it!", trump.bk_name);

}
void checkinbook(struct library trimp)
{


    int i,check_flag=0;
    for (i=0; i<length; i++)
    {
    if (strcmp(trimp.bk_name, list[i].bk_name) == 0)
    {
       printf ("\nBook titled '%s' (Author: %s, Pages: %d, Price:%.2f) found. \nCurrently Available copies (before check out): %d\n",list[i].bk_name,list[i].author,list[i].pages,list[i].price, list[i].quantity);

            list[i].quantity += 1;
            printf("\n\nChecked in Successfully!!\n\n");
            check_flag=1;
    }


    }



    if(check_flag==0)
    {
       printf("No book titled '%s' is available in the library",trimp.bk_name);
    }



}

    ~DynamicArray() //a destructor function, deallocates memory when the program closes/object is no longer needed
    {
        delete [] list;
    }


};



int main()

{


     DynamicArray <library> list; //actually "dynamic"
    //int a [10] <- fixed size
    // int * a = new int [10] <- still tied to a pre-defined size

char ar_nm[30],bk_nm[30];
char bk_nme[30];
 char ar_nme[30];
int  keepcount,pg,qu,j;
float pr;


printf("\n\n\t\t\tLibrary Management Software\n\t\tMilitary Institute of Science and Technology\n\t\t\tDeveloped in CSE 110");
while(j!=8)
{
printf("\n\n\t\tMENU");
printf("\n\n1. Add new book to the library\n");
printf("2. Display all book info\n");
printf("3. Search Books by Author Name\n");
printf("4. Search by Book Name\n");
printf("5. Check the number of currently available titles in the library\n");
printf("6. Checkout a book from the library\n");
printf("7. Check in a book\n");
printf("8. Exit\n");

printf ("\n\nEnter one of the above : ");
scanf("%d",&j);


switch (j)

{
/* Add book */
case 1:

printf ("Enter book name = ");
getchar();
gets(bk_nm);

printf ("Enter author name = ");
gets(ar_nm);

printf ("Enter pages = ");
scanf ("%d",&pg);

printf ("Enter price = ");
scanf ("%f",&pr);

printf ("Enter quantity to add = ");
scanf ("%d",&qu);
struct library temp;
strcpy(temp.bk_name,bk_nm);
strcpy(temp.author,ar_nm);
temp.pages=pg;
temp.price=pr;
temp.quantity=qu;
list.add(temp);
break;

case 2:
printf("you have entered the following information\n");
list.printlist();
break;

case 3:
    struct library tmp;

    printf("Enter the author name of the book: ");
    getchar();
    gets(ar_nme);

    strcpy(tmp.bk_name,ar_nme);
    list.infoaccordingtoauthor(tmp);


break;

case 4:
    struct library trmp;
    printf("Enter the name of the book: ");
    getchar();
    gets(bk_nme);
    strcpy(trmp.bk_name,bk_nme);
    list.infoaccordingtobook(trmp);

break;

case 5:
 list.availablebook();
break;

case 6:
    printf("Enter the Title of the book to check out: ");
    getchar();
    gets(bk_nme);
    struct library trump;
    strcpy(trump.bk_name,bk_nme);
    list.checkoutbook(trump);

break;

case 7:
    printf("Enter the Title of the book to check in: ");
    getchar();
    gets(bk_nme);
     struct library trimp;
    strcpy(trimp.bk_name,bk_nme);
    list.checkinbook(trimp);
break;



case 8:
    {
        printf("\n\n\t\t\tThank you for using this program\n\t\t\tHave a good day!\n\n");

    }
}
}
return 0;
}
