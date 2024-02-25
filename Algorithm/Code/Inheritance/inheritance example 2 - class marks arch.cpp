#include<iostream>
using namespace std;


class Student
{
protected:
    float CT[3];
    float mid;
public:
    void setMarks(float a[], float b)
    {
        for (int i=0; i<3;i++)
        {
            CT[i]=a[i];
        }
        mid=b;
    }

    float * getCTmarks()
    {
        return CT;
    }

    float getMid()
    {
        return mid;
    }
};

class ArchiStudent : public Student
{
private:
    float project;
public:
    void setProject(float p)
    {
        project = p;
    }

    /* Can be done only if mid was declared as "protected" in the base class student.
    void midBonus(float p)
    {
        mid = p+5;
    }*/



    float getProject ()
    {
        return project;
    }

};
int main()
{

    Student s1;

    float CTmarks[3]={5,10,20};
    s1.setMarks(CTmarks,40);

    float * ct;
    ct=s1.getCTmarks();

    for(int i=0;i<3;i++)
    {
        cout<<"S1 CT " <<i+1<< " marks: "<<*(ct+i)<<endl;
    }
    cout<<"S1 Midterm marks: "<< s1.getMid()<<endl;


    cout<<"\nNow for an archi student, let's say that they have an extra project for each theory course, \neverything else is same";
    cout<<"\nWe can just add another class. It'll be a derived/child class of base class 'Student'\n\n"<<endl;

    ArchiStudent s2;
    s2.setMarks(CTmarks,42);
    s2.setProject(25);

    float * ct2;
    ct2= s2.getCTmarks();

     for(int i=0;i<3;i++)
    {
        cout<<"S2 CT " <<i+1<< " marks: "<< *(ct2+i)<<endl;
    }

    cout<<"S2 Midterm marks: "<< s2.getMid()<<endl;
    cout<<"S2 Project marks: "<< s2.getProject()<<endl;


}
