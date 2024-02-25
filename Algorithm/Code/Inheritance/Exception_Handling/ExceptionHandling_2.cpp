#include<iostream>
using namespace std;
void test(int test){
    cout<<"inside Xtest: "<<test<<endl;
    if(test>4)
        throw test;
}
int main (){
    cout<<"start\n";
    try{
        cout<<"inside a try block\n";
        test(0);
        test(5);
        test(2);
    }
    catch(int i){
        cout<<"caught number: ";
        cout<<i<<endl;
    }

    cout<<"end";
}
