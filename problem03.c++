#include<iostream>

using namespace std ;

bool isLeapYear(int year){
    return (year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0)) ;
}

int main (){
    int year ;
    cout << "ENTER THE YEAR: ";
    cin >> year ;
    isLeapYear(year)?  cout << "\t" << year << " is a leap year ." : cout << "\t" << year << " is not a leap year .";

}