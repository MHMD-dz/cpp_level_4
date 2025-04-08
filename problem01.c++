#include<iostream>

using namespace std ;

int readNumber(string message){
    int number ;
    cout << message ;
    cin >> number ;
    return number ; 
}

string Funit( int unit , int ten){
    switch (unit)
    {
    case 0 :
        switch (ten)
        {
        case 1 : return "one " ;
        case 2 : return "two " ;
        case 3 : return "three " ;
        case 4 : return "four " ;
        case 5 : return "five " ;
        case 6 : return "six " ;
        case 7 : return "seven " ;
        case 8 : return "eight " ;
        case 9 : return "nine " ;
        default: return "" ;
        }
    case 1 :
        switch (ten)
        {
        case 1 : return "ten " ;
        case 2 : return "twenty " ;
        case 3 : return "thirty " ;
        case 4 : return "forty " ;
        case 5 : return "fifty " ;
        case 6 : return "sixty " ;
        case 7 : return "seventy " ;
        case 8 : return "eighty " ;
        case 9 : return "ninety " ;
        default: return "" ;
        }
    case 2 :
        return " hundred and " ;

    case 3 :
        return " thousand and " ;
    
    case 6 :
        return " million " ;

    case 9 :
        return " billion " ;

    default:
        break;
    }
    return "" ;
}

string numberToUnit( int unit , int number){
    string Sname ;
    switch (unit)
    {
    case 0 :
        return (Funit(unit,number));
    case 1 :
        return (Funit(unit,number));
    case 2 :
        return (to_string(number) + " " + Funit(unit,number));
    case 3 : case 4 : case 5 :
        return (to_string(number) + Funit(unit,number) );
    case 6 : case 7 : case 8 :
        return (to_string(number) + Funit(unit,number) );
    case 9 :
        return (to_string(number) + Funit(unit,number) );
        
    
    default:
        break;
    }
    return "" ;
}

string numberToLine(int number){
    string result ;
    int counter = 0 ;
    int sideNumber = 0 ;
    while (number > 0)
    {
        sideNumber = number % 10 ;
        result = numberToUnit(counter,sideNumber)+ result ;
        number /= 10 ;
        counter ++ ;
    }
    
    return result ;
}

int main(){
    int number ;
    number = readNumber("enter the number: ");
    cout << numberToLine(number);
}