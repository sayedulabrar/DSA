#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

/*
check out accompanying video for explanation
for queries:
    Lec Raiyan
    Dept of CSE, MIST
    raiyan@cse.mist.ac.bd
*/

struct library
{
    char bk_name[30];
    char author[30];
    int pages;
    float price;
    int quantity;

};

int main()
{

    int num;

    printf("Enter number of book in your library: ");
    scanf("%d", num);

    struct library l[num];


char ar_nm[30],bk_nm[30];
int i,j, keepcount;
i= j= keepcount = 0;
int check_flag;

system("COLOR 70");
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

i=keepcount;

switch (j)

{
/* Add book */
case 1:

printf ("Enter book name = ");
getchar();
gets(l[i].bk_name);

printf ("Enter author name = ");
gets(l[i].author);

printf ("Enter pages = ");
scanf ("%d",&l[i].pages);

printf ("Enter price = ");
scanf ("%f",&l[i].price);

printf ("Enter quantity to add = ");
scanf ("%d",&l[i].quantity);


keepcount++;

break;
case 2:
printf("you have entered the following information\n");
for(i=0; i<keepcount; i++)
{
printf("\n\nTitle %d info: ", i+1);

printf ("\nbook name = %s",l[i].bk_name);

printf ("\t author name = %s",l[i].author);

printf ("\t  pages = %d",l[i].pages);

printf ("\t  price = %f",l[i].price);

printf("\t Available Copies: %d", l[i].quantity);
}
break;

case 3:
printf ("Enter author name (don't put any leading or trailing whitespace!): ");
getchar();
gets(ar_nm);
//puts(ar_nm);
check_flag=0;
for (i=0; i<keepcount; i++)
{
if (strcmp(ar_nm, l[i].author) == 0)
{
    printf ("\nBook name: %s, Author: %s, Pages: %d, Price:%.2f, Available copies: %d\n",l[i].bk_name,l[i].author,l[i].pages,l[i].price, l[i].quantity);
    check_flag=1;

}

}

if(check_flag==0)
    printf("No books of author '%s' is currently available in the library", ar_nm);

break;

case 4:
printf ("Enter book name (don't put any leading or trailing whitespace!): ");
getchar();
gets(bk_nm);
puts(bk_nm);
check_flag=0;
for (i=0; i<keepcount; i++)
{
if (strcmp(bk_nm, l[i].bk_name) == 0)
{
   printf ("\nBook name: %s, Author: %s, Pages: %d, Price:%.2f, Available copies: %d\n",l[i].bk_name,l[i].author,l[i].pages,l[i].price, l[i].quantity);
   check_flag=1;
}

}

if(check_flag==0)
    printf("No book titled '%s' is available in the library currently", bk_nm);

break;

case 5:
    printf("\n Number of total available titles in library : %d", keepcount);
    break;

case 6:
    printf("Enter the Title of the book to check out: ");
    getchar();
    gets(bk_nm);

    check_flag=0;
    for (i=0; i<keepcount; i++)
    {
    if (strcmp(bk_nm, l[i].bk_name) == 0)
    {
       printf ("\nBook titled '%s' (Author: %s, Pages: %d, Price:%.2f) found. \nCurrently Available copies (before check out): %d\n",l[i].bk_name,l[i].author,l[i].pages,l[i].price, l[i].quantity);
       if(l[i].quantity>0)
        {
            l[i].quantity -= 1;
            printf("\n\nChecked out Successfully!!\n\n");
        }

       else
        printf("\nNot enough copies available to check out.  Buy more or wait for check-ins! ");

       check_flag=1;
    }

    }

    if(check_flag==0)
        printf("No book titled '%s' is available in the library to check out! Buy it!", bk_nm);

break;

case 7:
    printf("Enter the Title of the book to check in: ");
    getchar();
    gets(bk_nm);

    check_flag=0;
    for (i=0; i<keepcount; i++)
    {
    if (strcmp(bk_nm, l[i].bk_name) == 0)
    {
       printf ("\n\nBook titled '%s' (Author: %s, Pages: %d, Price:%.2f) found. \nCurrently Available copies (before check in): %d\n",l[i].bk_name,l[i].author,l[i].pages,l[i].price, l[i].quantity);

        l[i].quantity += 1;
        printf("\n\nChecked in Successfully!!\n\n");


       check_flag=1;
    }

    }

    if(check_flag==0)
        printf("No record of a book titled '%s' in the library", bk_nm);

    break;



case 8:
    {
        printf("\n\n\t\t\tThank you for using this program\n\t\t\tHave a good day!\n\n");
        exit (0);
    }
}
}
return 0;

}
