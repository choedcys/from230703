#include<iostream>
#include<cstring>
using namespace std;

int ToDecimal(string number, int B){
    int deci = 0;
    int pos = 1;
    for(int i = number.length()-1 ; i >= 0 ; i--){
        if(number.at(i) >= 48 && number.at(i) <= 57)
            deci+=(char(number.at(i))-48)*pos;
        else
            deci+=(char(number.at(i))-55)*pos;
        pos *= B;
    }
    return deci;
}

int main(){
    string number;
    long long int B, pos;
    cin>>number>>pos;
    B = pos;
    cout<<ToDecimal(number, B);
}
