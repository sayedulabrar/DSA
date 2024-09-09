#include<bits/stdc++.h>
using namespace std;

string add(string m, string n){
    string str1,str2;
    string result="";
    int i,j,k;
    int sizeM = m.size();
    int sizeN = n.size();
    if(sizeM>sizeN)
    {
        str1=m;
        str2=n;
    }else
    {
        str1=n;
        str2=m;
    }
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for(i=0;i<str2.length();i++)
    {
        int res=(str1[i]-'0')+(str2[i]-'0')+carry;
        result.push_back(res%10 + '0');
        carry = res/10;
    }
    for (int i=str2.length(); i<str1.length(); i++)
    {
        int sum = (str1[i]-'0')+carry;
        result.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if(carry==1)    result = "1"+result;
    return result;
}

string multiplyByDigit(string m, char d, int z){
    int len = m.size();
    int c = 0;
    string result = "";
    for(int i=len-1; i>=0; i--){
        int mm = (m[i]-'0') *(d - '0') + c;
        int mmm = mm%10;
        c = mm/10;
        char che=mmm + '0';
        result =che  + result;
    }
    if(c!=0){
            char ch= c+'0';
        result = ch + result;
    }
    for(int i=1; i<=z; i++){
        result = result + "0";
    }
    return result;
}

string multiply(string m, string n){
    int len = n.size();
    string sum = "";
    for(int i=len-1,z=0; i>=0; i--,z++){
        string x = multiplyByDigit(m,n[i],z);
        if(z==0){
            sum = x;
        }
        else{
            sum = add(sum,x);
        }
    }
    return sum;
}

string pow(string a, string b){
    string mult = "1";
    /*for(i=1; i<=b; i++){
        mult = mult*a;
    }*/
    string i = "0";
    while(i!=b){
        mult = multiply(mult,a);
        i = add(i,"1");
    }
    return mult;
}

int main(){
    cout<<multiply("999","99");
    cout<<pow(2,5);
}
