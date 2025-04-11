#include <iostream>

using namespace std ;

int getYear(string message){
    int year = 0 ;
    do
    {
        if (year < 0)
        {
            cout << "ERROR inter a valid number !"<< endl ;
        }
        cout << message ;
        cin >> year ;
    } while (year < 0);
    return year ;
}

bool IsLeap(int year){
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));}

int main(){
    int year ;
    year = getYear("Enter the year: ") ;
    if (IsLeap(year))
    {
        cout << "number of the day     in the year [" << year << "] : " << 366 << endl ;
        cout << "number of the hours   in the year [" << year << "] : " << 366 * 24 << endl ;
        cout << "number of the minutes in the year [" << year << "] : " << 366 * 24 * 60 << endl ;
        cout << "number of the seconds in the year [" << year << "] : " << 366 * 24 * 60 * 60 << endl ;
    }else
    {
        cout << "number of the day     in the year [" << year << "] : " << 365 << endl ;
        cout << "number of the hours   in the year [" << year << "] : " << 365 * 24 << endl ;
        cout << "number of the minutes in the year [" << year << "] : " << 365 * 24 * 60 << endl ;
        cout << "number of the seconds in the year [" << year << "] : " << 365 * 24 * 60 * 60 << endl ;
    }
    
    
}