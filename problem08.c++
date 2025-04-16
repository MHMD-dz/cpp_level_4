#include <iostream>
#include <iomanip>
using namespace std;

enum eMonths {
    January = 1, February = 2, March = 3, April = 4, May = 5, June = 6,
    July = 7, August = 8, September = 9, October = 10, November = 11, December = 12
};
string arrDaysName[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
string arrMonthName[12] = { "January" , "February", "March", "April" , "May" , "June" ,
                           "July", "August", "September", "October" , "November" ,"December" };

int ReadNumber(string Message) {
    int N;
    cout << Message << "\n";
    cin >> N;
    return N;
}

short ReadYear(string Message) {
    short N;
    do {
        cout << Message << "\n";
        cin >> N;
    } while (N < 0 || N > 2025);
    return N;
}

short ReadMonth(string Message) {
    short N;
    do {
        cout << Message << "\n";
        cin >> N;
    } while (N < 1 || N > 12); 
    return N;
}

short ReadDay(string Message) {
    short N;
    do {
        cout << Message << "\n";
        cin >> N;
    } while (N < 0 || N > 31);
    return N;
}

bool IsALeapYear(short Year) {
    return ((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Year, short Month) {
    if (Month < 1 || Month > 12)
        return 0;
    else if (Month == 2) {
        return IsALeapYear(Year) ? 29 : 28;
    }
    short arr31Days[7] = { 1, 3, 5, 7, 8, 10, 12 };
    for (short i = 0; i < 7; i++) {
        if (arr31Days[i] == Month) {
            return 31;
        }
    }
    return 30;
}

short WhatDay(short Year, short Month, int Day) {
    int a = (14 - Month) / 12;
    int y = Year - a;
    int m = Month + (12 * a) - 2;
    short d = int(Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    return d;
}

string Monthname(short MonthOrder) {
    if (MonthOrder < 1 || MonthOrder > 12)
        return "Invalid Month";
    return arrMonthName[MonthOrder - 1];  
}

string DayName(short DayOrder) {
    if (DayOrder < 0 || DayOrder > 6) 
        return "Invalid Day";
    return arrDaysName[DayOrder];
}

short WhenTheMonthStart(short Year, short Month) {
    return WhatDay(Year, Month, 1);
}

void space(short N) {
    for (short i = 0; i < N; i++) {
        cout << setw(10) << "";
    }
}

void monthCalendrier(short year, short month) {
    cout << "-------------------------------" << arrMonthName[month - 1] << "-----------------------------------" << endl;
    cout << setw(10) << "Sunday" << setw(10) << "Monday"  << setw(10) << "Tuesday" << setw(12) << "Wednesday" << setw(10) << "Thursday" << setw(10) << "Friday" << setw(10) << "Saturday";
    short monthstartday = WhenTheMonthStart(year, month);
    short monthends = NumberOfDaysInMonth(year, month);
    short counter = monthstartday;
    cout << endl;
    space(monthstartday);
    for (int i = 1; i <= monthends; i++) {
        cout << setw(10) << i ;
        counter++;
        if (counter == 7) {
            cout << endl;
            counter = 0;
        }
    }
}

int main() {
    short DayOrder = 0;
    int Year = ReadYear("Please enter the year :");
    int month = ReadMonth("Please enter the month: ");
    cout << "\n\n";
    monthCalendrier(Year, month);
}