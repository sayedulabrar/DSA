#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Customer {
private:
    string name;
    int vault_no;
    double interest_rate;
    double vault_balance;
    static int counter;

public:
    Customer(const string& n, int r, double bal)
        : name(n), vault_balance(bal), vault_no(++counter) {
        setInterestRate(r);
    }

    ~Customer() {}

    void setInterestRate(int r) {
        switch (r) {
            case 1:
                interest_rate = 0.07;
                break;
            case 2:
                interest_rate = 0.05;
                break;
            case 3:
                interest_rate = 0.035;
                break;
        }
    }

    double total_balance(int year) {
        return vault_balance * pow(1 + interest_rate, year);
    }

    double interest(int year) {
        return total_balance(year) - vault_balance;
    }

    void display(int year) {
        cout << "Name: " << name << endl;
        cout << "Vault No: " << vault_no << endl;
        cout << "Total Balance: " << total_balance(year) << " Gold Coins" << endl;
    }

};



class Goblin {
private:
    string name;
    string designation;
    double salary;
    Customer* customer;

public:
    Goblin(const string& n, const string& d,Customer* c) : name(n), designation(d), customer(c) {
        setSalary();
        
    }

    ~Goblin() {
        delete customer;
    }

    void setSalary() {
        if (designation == "manager")
            salary = 1000;
        else if (designation == "accountant")
            salary = 600;
        else
            salary = 300;
    }



    double total_income(int year) {
        double income = salary * year;
        if (customer)
            income += customer->interest(year);
        return income;
    }

    void display(int year) {
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
        cout << "Total Income: " << total_income(year) << " Gold Coins" << endl;
    }
};

Customer* find_customer(vector<Customer>& customers, const string& name) {
    for (int i=0;i<customers.size();i++) {
        if (customers[i].name == name)
            return customers[i];
    }
    return nullptr;
}

Goblin* find_goblin(vector<Goblin>& goblins, const string& name) {
    for (int i=0;i<goblins.size();i++) {
        if (goblins[i].name == name)
            return goblins[i];
    }
    return nullptr;
}


int Customer::counter=0;


int main() {
    int n_customers, n_goblins;
    cout << "Enter number of Customers: ";
    cin >> n_customers;

    vector<Customer> customers;
    cout << "Enter Details:" << endl;
    for (int i = 0; i < n_customers; i++) {
        string name;
        int rank;
        double vault_balance;
        cout << "Name: ";
        cin >> name;
        cout << "Rank: ";
        cin >> rank;
        cout << "Vault Balance: ";
        cin >> vault_balance;
        customers.push_back(Customer(name, rank, vault_balance));
    }

    cout << "Enter number of Goblins: ";
    cin >> n_goblins;

    vector<Goblin> goblins;
    cout << "Enter Details:" << endl;
    for (int i = 0; i < n_goblins; i++) {
        string name, designation;
        cout << "Name: ";
        cin >> name;
        cout << "Designation: ";
        cin >> designation;
        if (designation != "coiner") {
            Customer* c = find_customer(customers, name);
            if (c){
                goblins.push_back(Goblin(name,designation,c));
            }
            else{
                goblins.push_back(Goblin(name,designation,nullptr));
                cout << "Customer not found" << endl;
            }
        }
    }

    char choice;
    do {
        string name;
        int year;
        cout << "See details of a Goblin/Customer: ";
        cin >> choice;
        if (choice == 'G' || choice == 'g') {
            cout << "Enter Name: ";
            cin >> name;
            Goblin* g = find_goblin(goblins, name);
            if (g) {
                cout << "Enter Year: ";
                cin >> year;
                g->display(year);
            } else {
                cout << "Goblin not found" << endl;
            }
        } else if (choice == 'C' || choice == 'c') {
            cout << "Enter Name: ";
            cin >> name;
            Customer* c = find_customer(customers, name);
            if (c) {
                cout << "Enter Year: ";
                cin >> year;
                c->display(year);
            } else {
                cout << "Customer not found" << endl;
            }
        } else {
            cout << "Invalid choice" << endl;
        }
    } while (choice == 'G' || choice == 'g' || choice == 'C' || choice == 'c');

    return 0;
}