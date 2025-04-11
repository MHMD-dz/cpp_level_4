#include <iostream>

using namespace std ;

int getYear(string message){
    int year = 0 ;
    do
    {
        if (year < 0)
        {
            cout << "ERROR enter a valid number !"<< endl ;
        }
        cout << message ;
        cin >> year ;
    } while (year < 0);
    return year ;
}

short getMonth(string message){
    int month = 0 ;
    do
    {
        if (month < 1)
        {
            cout << "ERROR inter a valid number !"<< endl ;
        }
        cout << message ;
        cin >> month ;
    } while (month < 1 || month > 12 );
    return month ;
}

bool IsLeap(int year){
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));}

short NumberOfDays(int year , short month){
    switch (month)
    {
    case 1 : case 3 : case 7 : case 8 : case 10 : case 12:
        return 31 ;
        break;
    case 4 : case 5 : case 6 : case 9 : case 11 :
        return 30 ;
    case 2 :
        if (IsLeap(year))
        {
            return 29 ;
        }
        return 28 ;
    default:
        break;
    }
    return 0 ;
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