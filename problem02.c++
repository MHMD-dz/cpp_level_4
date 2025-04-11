#include<iostream>

using namespace std ;

bool isLeapYear(int year){
    if (year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0))
    {
        return true ;
    }
    return false ;
}

int main (){
    int year ;
    cout << "ENTER THE YEAR: ";
    cin >> year ;
    if (isLeapYear(year))
    {
        cout << "\t" << year << " is a leap year .";
    }else cout << "\t" << year << " is not a leap year .";
    
}