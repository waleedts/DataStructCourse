#include "Date.h"
#include <iomanip>

using namespace std;

void Date::setDate(int d, int m, int y) {//The set function which checks if the date is valid
    //Temp to check if valid without changing the values
    Date s;
    s.day = d;
    s.month = m;
    s.year = y;
    //The actual if statement
    if (!s.isValid()) {
        cout << "Invalid Day" << endl;
    } else {
        this->year = s.year;
        this->day = s.day;
        this->month = s.month;
    }
}
//1900 1800 1700 are NOT leap years
bool Date::isLeap() {//The helping function for checking if its a leap year
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else {
        return year % 400 == 0;
    }
}

bool Date::isValid() {//The helping functions for checking date validity
    bool s = true;
    if ((day < 1) || (month < 1) || (month > 12) || (day > 31)) {
        s = false;
    } else if (month == 2) {
        if (!isLeap() && day > 28) {
            s = false;
        } else if (isLeap() && day > 29) {
            s = false;
        }
    } else if ((month % 2 == 0 && month < 8) || (month % 2 == 1 && month > 8)) {
        if (day == 31) {
            s = false;
        }
    }
    return s;
}

Date::Date(int d, int m, int y) {//The default and parameterized constructor definition
    day = d;
    month = m;
    year = y;
    if (!isValid()) {
        day = 1;
        month = 1;
        year = 2000;
    }
}

Date operator++(Date &d, int) {//Post
    Date c = d;
    if (d.day == 31) {//The default if for all 31 months
        d.day = 1;
        if (d.month == 12) {
            d.month = 1;
            d.year++;
        } else {
            d.month++;
        }
    } else if (d.day == 30) {//The default if for all 30 months
        if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 ||
            d.month == 12) {
            d.day++;
        } else {
            d.day = 1;
            d.month++;
        }
    } else if (d.month == 2 && d.day > 27) {//The special case for Feb and checking if its a leap year
        if (d.day == 28 && d.isLeap()) {
            d.day++;
        } else {
            d.day = 1;
            d.month++;
        }
    } else {//The default case
        d.day++;
    }
    return c;
}

Date operator--(Date &d, int) {//Pre
    Date c = d;
    if (d.day == 1) {//When its the start of the month
        if (d.month == 1) {//The beginning of the year special case
            d.month = 12;
            d.day = 31;
            d.year--;
        } else if (d.month == 3) {//The feb special case
            d.month--;
            if (d.isLeap()) {
                d.day = 29;
            } else {
                d.day = 28;
            }
        } else if (d.month == 8) {//The aug special case because both aug and july are 31 days
            d.month--;
            d.day = 31;
        } else if (d.month == 5 || d.month == 7 || d.month == 10 || d.month == 12) {//General for the months which are 31
            d.day = 30;
            d.month--;
        } else {//General for the months which are 30
            d.day = 31;
            d.month--;
        }
    } else {//General case when in middle or end of month
        d.day--;
    }
    return c;
}

Date operator++(Date &d) {//Pre
    d++;//for code redundancy
    return d;
}

Date operator--(Date &d) {//Pre
    d--;//for code redundancy
    return d;
}

ostream &operator<<(ostream &output, Date &d) {//The output uses the iomanip to set the format as YYYY-MM-DD
    output << setw(4) << setfill('0') << d.year << "-" << setw(2) << setfill('0') << d.month << "-" << setw(2)<< setfill('0') << d.day;
    return output;
}

istream &operator>>(istream &input, Date &d) {//The input
    //A temp for the values from the input
    Date s;
    cout << "Enter a day:";
    input >> s.day;
    cout << "Enter a month:";
    input >> s.month;
    cout << "Enter a year:";
    input >> s.year;
    if (s.isValid()) {//Checks the validity of the inputs and moves them to the actual var
        d.setDate(s.day, s.month, s.year);
    } else {//Prints a message when the inputs are invalid
        cout << "Invalid Input" << endl;
    }
    return input;
}

bool operator==(Date &a, Date &b) {
    return (a.year == b.year) && (a.day == b.day) && (a.month == b.month);
}

bool operator!=(Date &a, Date &b) {
    return (a.year != b.year) || (a.day != b.day) || (a.month != b.month);
}

bool operator>(Date &a, Date &b) {
    if (a.year > b.year) {
        return true;
    } else if ((a.year == b.year) || (a.month > b.month)) {
        return true;
    } else {
        return (a.year == b.year) || (a.month == b.month) || (a.day > b.day);
    }
}

bool operator<(Date &a, Date &b) {
    return !(a > b && a == b);
}