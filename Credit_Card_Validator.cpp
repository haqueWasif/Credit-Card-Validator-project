#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(){
    long long int ccn;
    int lastNum;
    int sum=0;
    // Valid Card Example
    // 4847352989263094
    cin>>ccn;
    
    long long int cardNum = ccn;
    int count = to_string(cardNum).size();
    int f_digit = cardNum / pow(10, count-1);
    int f_2digit = cardNum / pow(10, count-2);
    // For odd place 
    while(cardNum > 0){
        lastNum = cardNum % 10;
        sum += lastNum;
        cardNum = cardNum / 100;
    }
    // For even place
    cardNum = ccn / 10;
    while(cardNum > 0){
        lastNum = cardNum % 10;
        lastNum *= 2;
        if(lastNum >= 10){
            lastNum = 1 + (lastNum % 10);
        }
        sum += lastNum;
        cardNum = cardNum / 100;
    }
    if(!(sum % 10)){
        cout << "Valid" << endl;
        if(f_digit == 4 && count == 16){
            cout << "CARD TYPE: ";
            cout << "VISA " << endl;
        }
        else if(f_2digit == 34 || f_2digit == 37 && count == 15){
            cout << "CARD TYPE: ";
            cout << "AMERICAN EXPRESS " << endl;
        }
        else if(50 < f_2digit < 56  && count == 16){
            cout << "CARD TYPE: ";
            cout << "MASTERCARD " << endl;
        }
    }
    else{
        cout<<"Invalid";
    }
    return 0;
}   