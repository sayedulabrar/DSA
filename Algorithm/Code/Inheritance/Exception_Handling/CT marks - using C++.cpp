#include<iostream>
using namespace std;

class Student
{
protected:
    float CT[3];
    float mid;
    int ID;
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
    void setID(int a)
    {
        ID=a;
    }

    int getID()
    {
        return ID;
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


int main()
{

    int num;
    cout<<"Enter the number of students in this class: ";
    cin>>num;

    Student s1[num];

    float CTmarks[3], mid;
    int Id;

    for(int j=0;j<num;j++)
    {

        cout<<"\n\nEntering data for student number "<<j+1;
        cout<<"\nEnter Student ID: ";
        cin>>Id;
        s1[j].setID(Id);

        for(int i=0;i<3;i++)
        {
            cout<<"\nEnter mark for CT "<<i+1<<" :";
            cin>>CTmarks[i];
        }

        cout<<"\nEnter mark for Midterm: ";
        cin>>mid;

        s1[j].setMarks(CTmarks,mid);

        float * ct;
        ct=s1[j].getCTmarks();

        cout<<"\n\nShowing data for Student ID: "<<s1[j].getID()<<endl;
        cout<<"\nMidterm marks: "<< s1[j].getMid()<<endl;
        cout<<"Min CT mark: "<< s1[j].getMinCtMarks()<<endl;
        cout<<"Total mark in CT and MID: : "<< s1[j].getTotalMarks()<<endl;

    }

}
