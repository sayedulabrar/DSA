#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
    int id,age;
    Student(){
    }
    Student(int _id,int _age){
        id=_id;
        age=_age;
    }
};

bool compareStudents(Student s1, Student s2)
{
    //return s1.id<s2.id;
    if(s1.id!=s2.id){
            return (s1.id < s2.id);
    }else{
        return (s1.age<s2.age);
    }

}

void printStudents(Student* studentArray, int numberOfStudents ){
    cout<<"\n***********************************************"<<endl;
    for(int i=0;i<numberOfStudents;i++){
        cout<<"("<<studentArray[i].id<<","<<studentArray[i].age<<") ";
    }
    cout<<"\n***********************************************"<<endl;
}
int main(){
     //cin will now be taking inputs from the file
     freopen("rollNumbers.txt", "r", stdin);

     //Storing the number of student objects
     int numberOfStudents;
     cin>>numberOfStudents;
     cout<<"The total number of students is "<<numberOfStudents<<endl;

     //Declaring the student array
     Student studentArray[numberOfStudents];

     //Taking inputs from the file and creating student objects
     for (int i=0;i<numberOfStudents;i++){
        int rollNumber,age;
        cin>>rollNumber;
        cin>>age;
        studentArray[i]= Student(rollNumber,age);
     }
     printStudents(studentArray,numberOfStudents);

     //Using the sorting function
     sort(studentArray,studentArray+numberOfStudents,compareStudents);

     //printing after sorting

     cout<<"printing after sorting"<<endl;
     printStudents(studentArray,numberOfStudents);
}
