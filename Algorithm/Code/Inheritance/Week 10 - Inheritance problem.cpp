#include<iostream>
using namespace std;

class Person
{
private:
    double contact_num;
protected:
    string designation;
public:
    string full_name;
    int ID;

    Person(string name, int id, string desig, double contact)
    {
        full_name=name;
        ID=id;
        designation=desig;
        contact_num=contact;
    }

    virtual int getSal()=0;
};

class Employee : public Person
{
private:
    int basic_sal;
protected:
    int bonus;
public:
    Employee(string name, int id, string desig, double contact, int basic, int bon) : Person(name, id, desig, contact)
    {
        basic_sal=basic;
        bonus=bon;
    }

    int getBasicSal()
    {
        return basic_sal;
    }

    int getSal()
    {
        return basic_sal + bonus;
    }
};


class Operator : public Employee
{
protected:
    int overtime_rate;
    int overtime_hour;
public:
    Operator (string name, int id, string desig, double contact, int basic, int bon, int rate, int hour) : Employee(name, id, desig, contact, basic, bon)
    {
        overtime_rate = rate;
        overtime_hour = hour;
    }

    int getSal()
    {
        return (getBasicSal() + bonus + (overtime_rate*overtime_hour));
    }
};

void printSal(Person * p)
{
    cout<<"Salary of "<<p->full_name<<", ID: "<<p->ID<<" is: "<<p->getSal()<<endl;
}

class Machine
{
private:
    string machine_name;
    int ID;
protected:
    string model;
public:
    string company;

    Machine(string name, int id, string mod, string comp)
    {
        machine_name=name;
        ID=id;
        model=mod;
        company=comp;
    }

    string getMachineName()
    {
        return machine_name;
    }

    int getMachineID()
    {
        return ID;
    }

    virtual double power_consumption()=0;
    virtual void operated_by()=0;

};


class ElectricMachine : public Machine
{
protected:
    double power_rate;
    float hours_worked;

public:
    ElectricMachine(string name, int id, string mod, string comp, double power_r, float hours_w) : Machine(name, id, mod, comp)
    {
        power_rate=power_r;
        hours_worked=hours_w;
    }

    double power_consumption()
    {
        return power_rate*hours_worked;
    }

};

class Production_line_machine : public Operator, public ElectricMachine
{
public:
    Production_line_machine(string name, int id, string desig, double contact, int basic, int bon, int rate, int hour, string name1, int id1, string mod, string comp, double power_r, float hours_w) : Operator(name, id, desig, contact, basic, bon, rate, hour), ElectricMachine(name1, id1, mod, comp, power_r, hours_w)
    {

    }

    void operated_by()
    {
        cout<<"Machine ID: "<<getMachineID()<<" is operated by: "<< full_name<<", having ID: "<<Person::ID <<endl;
    }
};

void PrintPowerConsumption(Machine * m)
{
    cout<<"machine ID: "<<m->getMachineID()<<" had a power consumption of: "<<m->power_consumption()<<endl;
}

int main()
{

    //Operator (string name, int id, string desig, double contact, int basic, int bon, int rate, int hour)
    Operator Op1("Mahdi", 202014028, "Production Engineer", 0177005544, 35000, 15000, 500, 10);

    Person * ptr;
    ptr=&Op1;

    cout<<"A operator object created and printSal() called for operator\n(obj slicing, late binding and abstract class)\n"<<endl;
    printSal(ptr);



    //Production_line_machine(string name, int id, string desig, double contact, int basic, int bon, int rate, int hour, string name1, int id1, string mod, string comp, double power_r, float hours_w)
    Production_line_machine PLM1("Mahdi", 202014028, "Production Engineer", 0177005544, 35000, 15000, 500, 10, "Shouldering Machine", 14001, "MX001", "TOSHIBA", 1500, 10);


    Machine * ptr2;
    ptr2=&PLM1;

    cout<<"\n\nA Production Line Machine object created and \noperated_by() and PrintPowerConsumption(ptr2) called for it\n(multiple inheritance, late binding and abstract class)\n"<<endl;
    PLM1.operated_by();
    PrintPowerConsumption(ptr2);
}
