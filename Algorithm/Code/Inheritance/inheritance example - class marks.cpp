#include<iostream>
using namespace std;


class Student
{
private:
    int theory;
    int sessional;
public:
    void setMarks(int a, int b)
    {
        theory=a;
        sessional=b;
    }

    int getTheory()
    {
        return theory;
    }

    int getSessional()
    {
        return sessional;
    }
};

class L4Student : public Student
{
private:
    int thesis;
public:
    void setThesis(int t)
    {
        thesis = t;
    }

    int getThesis ()
    {
        return thesis;
    }


};
int main()
{

    Student s1;
    s1.setMarks(10,20);
    cout<<"S1 Theo marks: "<< s1.getTheory()<<endl;
    cout<<"S1 Sessional marks: "<< s1.getSessional()<<endl;

    cout<<"\nS2 is a level 4 student. He is exactly the same as other students,\nexcept the thesis mark needs to be reported as well.\n";
    cout<<"So we make it a derived class of base class student and just add the additional 'features' to it\n\n"<<endl;
    L4Student s2;
    s2.setMarks(15,20);
    s2.setThesis(30);
    cout<<"S2 Theo marks: "<< s2.getTheory()<<endl;
    cout<<"S2 Sessional marks: "<< s2.getSessional()<<endl;
    cout<<"S2 Thesis marks: "<< s2.getThesis()<<endl;

}
