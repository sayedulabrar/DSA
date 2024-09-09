#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class electronics
{
private:
    int product_ID;
protected:
    int power_watt;
    int voltage_intake;
    float frquency;
    float price;

public:
    electronics (int a, int b, int c, float d, float e)
    {
        product_ID=a;
        power_watt=b;
        voltage_intake=c;
        frquency=d;
        price=e;
    }

    int getProductID()
    {
        return product_ID;
    }
};

class AirConditioner : public electronics
{
protected:
    float AC_capcity_ton;
    string brand_name;
    string AC_type;

public:
    AirConditioner (float a1, string b1, string c1, int a, int b, int c, float d, float e) : electronics(a,b,c,d,e)
    {
        AC_capcity_ton=a1;
        //brand_name.assign(b1);
        brand_name=b1;
        AC_type=c1;
    }

};


class AC_inverter : public AirConditioner
{
protected:
    string inverter_type;
    float power_savings;

public:
    AC_inverter(string a2, float b2, float a1, string b1, string c1, int a, int b, int c, float d, float e) : AirConditioner(a1, b1,c1,a,b,c,d,e)
    {
        inverter_type = a2;
        power_savings = b2;
    }

    display()
    {
        //displaying just a few info for example.
        printf("Brand:%s\nProduct ID: %d\nPower Savings: %.2f %%\nPrice:%.2f, \nCapacity(ton): %.2f \n", brand_name.c_str(), getProductID(), power_savings, price, AC_capcity_ton);
    }

};


class TVDisplay
{
protected:
    string Display_type;
    int refresh_rate;

public:
    TVDisplay(string aa, int bb)
    {
        Display_type=aa;
        refresh_rate=bb;
    }
};


class TeleVision : public electronics, public TVDisplay
{
protected:
    string TV_brand;
    float screen_size;
    float TV_weight;

public:
    TeleVision(string aaa, float bbb, float ccc, int a, int b, int c, float d, float e,string aa, int bb) : electronics(a,b,c,d,e), TVDisplay(aa,bb)
    {
        TV_brand = aaa;
        screen_size = bbb;
        TV_weight = ccc;
    }

    display()
    {
        //displaying just a few info for example.
        printf("TV Brand: %s, ProductID: %d, Display Type: %s", TV_brand.c_str(), getProductID(), Display_type.c_str());
    }
} ;

int main()
{

    AC_inverter AC1 ("Dual Inverter", 55.5, 1.5,"GREE","split",25512,1200,250,85.0,56500);

    cout<<"Inverter AC (multilevel inheritance):\n\n";
    AC1.display();

    TeleVision T1("SONY",55,23.5,25513,600,250,55.5,85000,"Edge LED",120);

    cout<<"\n\nTV (multiple inheritance):\n"<<endl;
    T1.display();
    cout<<"\n\n";

}
