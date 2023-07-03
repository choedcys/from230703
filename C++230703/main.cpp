#include<iostream>
#include<cstring>
using namespace std;

int ToDecimal(string number, long long int B, long long int pos){
    if(number.length() == 1)
        if(number.at(0) >= 48 && number.at(0) <= 57){
            return (char(number.at(0)) - 48)*(B/pos);
        }
        else{
            return (char(number.at(0)) - 55)*(B/pos);
        }
    else{
        string temp = number;
        temp.pop_back();
        if(number.at(number.length()-1) >= 48 && number.at(number.length()-1) <= 57){
            return ((char(number.at(number.length()-1)) - 48)*(B/pos)) + ToDecimal(temp, B*pos, pos);
        }
        else{
            return ((char(number.at(number.length()-1)) - 55)*(B/pos)) + ToDecimal(temp, B*pos, pos);
        }
    }
}

int main(){
    string number;
    long long int B, pos;
    cin>>number>>pos;
    B = pos;
    cout<<ToDecimal(number, B, pos);
}

