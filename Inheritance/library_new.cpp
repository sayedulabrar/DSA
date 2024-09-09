// #include<stdio.h>
// #include<conio.h>
// #include<stdlib.h>
// #include<string.h>

// /*
// check out accompanying video for explanation
// for queries:
//     Lec Raiyan
//     Dept of CSE, MIST
//     raiyan@cse.mist.ac.bd
// */

// struct library
// {
//     char bk_name[30];
//     char author[30];
//     int pages;
//     float price;
//     int quantity;

// };

// int main()
// {

//     int num;

//     printf("Enter number of book in your library: ");
//     scanf("%d", num);

//     struct library l[num];


// char ar_nm[30],bk_nm[30];
// int i,j, keepcount;
// i= j= keepcount = 0;
// int check_flag;

// system("COLOR 70");
// printf("\n\n\t\t\tLibrary Management Software\n\t\tMilitary Institute of Science and Technology\n\t\t\tDeveloped in CSE 110");

// while(j!=8)
// {
// printf("\n\n\t\tMENU");
// printf("\n\n1. Add new book to the library\n");
// printf("2. Display all book info\n");
// printf("3. Search Books by Author Name\n");
// printf("4. Search by Book Name\n");
// printf("5. Check the number of currently available titles in the library\n");
// printf("6. Checkout a book from the library\n");
// printf("7. Check in a book\n");
// printf("8. Exit\n");

// printf ("\n\nEnter one of the above : ");
// scanf("%d",&j);

// i=keepcount;

// switch (j)

// {
// /* Add book */
// case 1:

// printf ("Enter book name = ");
// getchar();
// gets(l[i].bk_name);

// printf ("Enter author name = ");
// gets(l[i].author);

// printf ("Enter pages = ");
// scanf ("%d",&l[i].pages);

// printf ("Enter price = ");
// scanf ("%f",&l[i].price);

// printf ("Enter quantity to add = ");
// scanf ("%d",&l[i].quantity);


// keepcount++;

// break;
// case 2:
// printf("you have entered the following information\n");
// for(i=0; i<keepcount; i++)
// {
// printf("\n\nTitle %d info: ", i+1);

// printf ("\nbook name = %s",l[i].bk_name);

// printf ("\t author name = %s",l[i].author);

// printf ("\t  pages = %d",l[i].pages);

// printf ("\t  price = %f",l[i].price);

// printf("\t Available Copies: %d", l[i].quantity);
// }
// break;

// case 3:
// printf ("Enter author name (don't put any leading or trailing whitespace!): ");
// getchar();
// gets(ar_nm);
// //puts(ar_nm);
// check_flag=0;
// for (i=0; i<keepcount; i++)
// {
// if (strcmp(ar_nm, l[i].author) == 0)
// {
//     printf ("\nBook name: %s, Author: %s, Pages: %d, Price:%.2f, Available copies: %d\n",l[i].bk_name,l[i].author,l[i].pages,l[i].price, l[i].quantity);
//     check_flag=1;

// }

// }

// if(check_flag==0)
//     printf("No books of author '%s' is currently available in the library", ar_nm);

// break;

// case 4:
// printf ("Enter book name (don't put any leading or trailing whitespace!): ");
// getchar();
// gets(bk_nm);
// puts(bk_nm);
// check_flag=0;
// for (i=0; i<keepcount; i++)
// {
// if (strcmp(bk_nm, l[i].bk_name) == 0)
// {
//    printf ("\nBook name: %s, Author: %s, Pages: %d, Price:%.2f, Available copies: %d\n",l[i].bk_name,l[i].author,l[i].pages,l[i].price, l[i].quantity);
//    check_flag=1;
// }

// }

// if(check_flag==0)
//     printf("No book titled '%s' is available in the library currently", bk_nm);

// break;

// case 5:
//     printf("\n Number of total available titles in library : %d", keepcount);
//     break;

// case 6:
//     printf("Enter the Title of the book to check out: ");
//     getchar();
//     gets(bk_nm);

//     check_flag=0;
//     for (i=0; i<keepcount; i++)
//     {
//     if (strcmp(bk_nm, l[i].bk_name) == 0)
//     {
//        printf ("\nBook titled '%s' (Author: %s, Pages: %d, Price:%.2f) found. \nCurrently Available copies (before check out): %d\n",l[i].bk_name,l[i].author,l[i].pages,l[i].price, l[i].quantity);
//        if(l[i].quantity>0)
//         {
//             l[i].quantity -= 1;
//             printf("\n\nChecked out Successfully!!\n\n");
//         }

//        else
//         printf("\nNot enough copies available to check out.  Buy more or wait for check-ins! ");

//        check_flag=1;
//     }

//     }

//     if(check_flag==0)
//         printf("No book titled '%s' is available in the library to check out! Buy it!", bk_nm);

// break;

// case 7:
//     printf("Enter the Title of the book to check in: ");
//     getchar();
//     gets(bk_nm);

//     check_flag=0;
//     for (i=0; i<keepcount; i++)
//     {
//     if (strcmp(bk_nm, l[i].bk_name) == 0)
//     {
//        printf ("\n\nBook titled '%s' (Author: %s, Pages: %d, Price:%.2f) found. \nCurrently Available copies (before check in): %d\n",l[i].bk_name,l[i].author,l[i].pages,l[i].price, l[i].quantity);

//         l[i].quantity += 1;
//         printf("\n\nChecked in Successfully!!\n\n");


//        check_flag=1;
//     }

//     }

//     if(check_flag==0)
//         printf("No record of a book titled '%s' in the library", bk_nm);

//     break;



// case 8:
//     {
//         printf("\n\n\t\t\tThank you for using this program\n\t\t\tHave a good day!\n\n");
//         exit (0);
//     }
// }
// }
// return 0;

// }











#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Library {
    string bk_name;
    string author;
    int pages;
    float price;
    int quantity;
};

int main() {
    vector<Library> library;
    int keepcount = 0;

    cout << "Enter number of books in your library: ";
    int num;
    cin >> num;

    library.resize(num);

    cout << "\n\n\t\t\tLibrary Management Software\n\t\tMilitary Institute of Science and Technology\n\t\t\tDeveloped in CSE 110";

    int choice;
    while (true) {
        cout << "\n\n\t\tMENU";
        cout << "\n\n1. Add new book to the library\n";
        cout << "2. Display all book info\n";
        cout << "3. Search Books by Author Name\n";
        cout << "4. Search by Book Name\n";
        cout << "5. Check the number of currently available titles in the library\n";
        cout << "6. Checkout a book from the library\n";
        cout << "7. Check in a book\n";
        cout << "8. Exit\n";
        cout << "\n\nEnter one of the above : ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter book name = ";
                cin.ignore(); // number er por string cin nile 
                getline(cin, library[keepcount].bk_name);

                cout << "Enter author name = ";
                getline(cin, library[keepcount].author);

                cout << "Enter pages = ";
                cin >> library[keepcount].pages;

                cout << "Enter price = ";
                cin >> library[keepcount].price;

                cout << "Enter quantity to add = ";
                cin >> library[keepcount].quantity;

                keepcount++;
                break;
            }
            case 2: {
                cout << "You have entered the following information:" << endl;
                for (int i = 0; i < keepcount; i++) {
                    cout << "\n\nTitle " << i+1 << " info: ";
                    cout << "\nBook name: " << library[i].bk_name;
                    cout << "\tAuthor name: " << library[i].author;
                    cout << "\tPages: " << library[i].pages;
                    cout << "\tPrice: " << library[i].price;
                    cout << "\tAvailable Copies: " << library[i].quantity;
                }
                break;
            }
            case 3: {
                cout << "Enter author name: ";
                cin.ignore();
                string authorName;
                getline(cin, authorName);
                bool found = false;
                for (int i = 0; i < keepcount; i++) {
                    if (library[i].author == authorName) {
                        cout << "\nBook name: " << library[i].bk_name << ", Author: " << library[i].author << ", Pages: " << library[i].pages << ", Price: " << library[i].price << ", Available copies: " << library[i].quantity << endl;
                        found = true;
                    }
                }
                if (!found)
                    cout << "No books of author '" << authorName << "' are currently available in the library" << endl;
                break;
            }
            case 4: {
                cout << "Enter book name: ";
                cin.ignore();
                string bookName;
                getline(cin, bookName);
                bool found = false;
                for (int i = 0; i < keepcount; i++) {
                    if (library[i].bk_name == bookName) {
                        cout << "\nBook name: " << library[i].bk_name << ", Author: " << library[i].author << ", Pages: " << library[i].pages << ", Price: " << library[i].price << ", Available copies: " << library[i].quantity << endl;
                        found = true;
                    }
                }
                if (!found)
                    cout << "No book titled '" << bookName << "' is available in the library currently" << endl;
                break;
            }
            case 5: {
                cout << "\nNumber of total available titles in library: " << keepcount << endl;
                break;
            }
            case 6: {
                cout << "Enter the Title of the book to check out: ";
                cin.ignore();
                string bookName;
                getline(cin, bookName);
                bool found = false;
                for (int i = 0; i < keepcount; i++) {
                    if (library[i].bk_name == bookName) {
                        cout << "\nBook titled '" << library[i].bk_name << "' (Author: " << library[i].author << ", Pages: " << library[i].pages << ", Price: " << library[i].price << ") found." << endl;
                        if (library[i].quantity > 0) {
                            library[i].quantity -= 1;
                            cout << "\n\nChecked out Successfully!!\n\n";
                        } else {
                            cout << "\nNot enough copies available to check out. Buy more or wait for check-ins! " << endl;
                        }
                        found = true;
                    }
                }
                if (!found)
                    cout << "No book titled '" << bookName << "' is available in the library to check out! Buy it!" << endl;
                break;
            }
            case 7: {
                cout << "Enter the Title of the book to check in: ";
                cin.ignore();
                string bookName;
                getline(cin, bookName);
                bool found = false;
                for (int i = 0; i < keepcount; i++) {
                    if (library[i].bk_name == bookName) {
                        cout << "\n\nBook titled '" << library[i].bk_name << "' (Author: " << library[i].author << ", Pages: " << library[i].pages << ", Price: " << library[i].price << ") found." << endl;
                        library[i].quantity += 1;
                        cout << "\n\nChecked in Successfully!!\n\n";
                        found = true;
                    }
                }
                if (!found)
                    cout << "No record of a book titled '" << bookName << "' in the library" << endl;
                break;
            }
            case 8: {
                cout << "\n\n\t\t\tThank you for using this program\n\t\t\tHave a good day!\n\n";
                return 0;
            }
            default: {
                cout << "Invalid choice! Please enter a valid option." << endl;
                break;
            }
        }
    }

    return 0;
}
