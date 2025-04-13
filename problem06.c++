#include <iostream>

using namespace std ;

int getYear(string message){
    int year = 0 ;
    do
    { 
        cout << message ;
        cin >> year ;

        if (year < 0)
        {
            cout << "ERROR enter a valid number !"<< endl ;
        }
        
    } while (year < 0);
    return year ;
}

short getMonth(string message){
    int month = 0 ;
    do
    {   
        cout << message ;
        cin >> month ;
        if (month < 1)
        {
            cout << "ERROR inter a valid number !"<< endl ;
        }
        
    } while (month < 1 || month > 12 );
    return month ;
}

bool IsLeap(int year){
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));}

short NumberOfDays(int year , short month){
    short monthArr[12] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30, 31 } ;
    return (month == 2) ? (IsLeap(year) ? 29 : 28 ) : monthArr[month-1] ;
}

int main(){
    int year ;
    short month ;
    short days ;
    year = getYear("Enter the year: ") ;
    month = getMonth("Enter the month: ") ;
    days = NumberOfDays(year,month) ;
        cout << "number of the day     in the month [" << month << "] : " << days << endl ;
        cout << "number of the hours   in the month [" << month << "] : " << days * 24 << endl ;
        cout << "number of the minutes in the month [" << month << "] : " << days * 24 * 60 << endl ;
        cout << "number of the seconds in the month [" << month << "] : " << days * 24 * 60 * 60 << endl ;
}