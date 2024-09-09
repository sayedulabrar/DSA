#include <iostream>
#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;

struct student {

    int ID;
    float gpa;
    char name[20];

};

int main()

{
    vector <student> a;

    //this is a DAL (using vector) of type "student"
    //similarly take a vector of type "library" for the assignment

    //declare variables as required for each of the attributes of the structure
    int num, choice, ID1;
    float gpa1;
    char name1[20];

    //a temp variable of "Student" type, we'll use it store values and then pass it in the push_back() function of vector.
    student temp_student;


    printf("\tImplementation of Dynamic Arrays with Vectors (STL) with User-def Data Types\n");

while (1)
{

    printf("\n1.Add an element\n2.See current Elements\n3.Delete element from a particular position\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);



    if(choice==1)
    {
        /*take inputs in variables as required for each of the attributes of the structure
          then assign the vars in a temporary object of "student"
          for library, declare 5 vars as needed and a temp object of library type */

        printf("\nEnter student ID: ");
        scanf("%d", &ID1);
        printf("\nEnter gpa: ");
        scanf("%f", &gpa1);
        printf("\nEnter Name of Student: ");
        getchar();
        gets(name1);
        temp_student.ID = ID1;
        temp_student.gpa = gpa1;
        strcpy(temp_student.name, name1);


        //now, let's insert this new student into our DAL
        //for the assignment, push the library object accordingly
        a.push_back(temp_student);
    }

    if (choice==2)
    {
        cout<<"The current dynamic array is: "<<endl;
        for (int i =0; i<a.size();i++)
        {
            printf("\nStudent %d info: ", i+1);
            printf("\nID: %d, Name: %s, GPA: %.2f \n", a[i].ID,a[i].name, a[i].gpa);

            //similarly print the library object's info.
            //As expected, we can access it exactly like an array using "a[i]" using the DAL vector after we push_back()
        }
    }

     if (choice==3)
    {
       printf("\nEnter a position to delete from: ");
        scanf("%d", &num);
        //we can also delete using the built-in vector functions.
        //for erase(), we have to iterate to the required position in the Dynamic array

        a.erase(a.begin() + (num-1));
        cout<<"Deleted the student from position no: "<<num<<endl;
    }
}
}
