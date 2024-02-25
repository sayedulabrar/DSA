#include<iostream>
using namespace std;

class Student
{
protected:
    float CT[3];
    float mid;
    float minCT;
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

    float getMinCtMarks()
    {
      minCT=CT[0];

        for (int i=0;i<3;i++)
        {
            if(minCT>CT[i])
            minCT= CT[i];
        }
        return minCT;

    }

    float getTotalMarks()
    {
        return CT[0]+ CT[1]+ CT[2] - minCT + mid;
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

    float getProject ()
    {
        return project;
    }

    //function overriding
    //since we're trying to access Student's variable's directly in this class, it has got to be either protected (recommended) or public.
    float getTotalMarks()
    {
        return CT[0]+ CT[1]+ CT[2] - minCT + mid + project;
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
    cout<<"S1 Min CT mark: "<< s1.getMinCtMarks()<<endl;
    cout<<"\nS1 Total mark in CT and MID: : "<< s1.getTotalMarks()<<endl;


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
    cout<<"S2 Min Ct marks: "<<  s2.getMinCtMarks()<<endl;
    cout<<"\nS2 Total marks in CT+MID and project: "<<  s2.getTotalMarks()<<endl;


}
