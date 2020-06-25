#ifndef HW1_DATE_H
#define HW1_DATE_H
#include <iostream>

class Date {
private:
    int day,month,year;//The three main private members
    //Some helping functions for code readability and to cut on redundant code
    bool isLeap();
    bool isValid();
public:
    //(1)The default and parameterized constructor
    Date(int =1,int  =1,int =2000);
    //(2)The only set function with the default date 2000-01-01
    void setDate(int =1,int  =1,int =2000);
    //(3)Inline definition for the getters
    int getDay(){return day;}
    int getMonth(){return month;}
    int getYear(){return year;}
    //(4+5)The overloaded extraction and insertion
    friend std::ostream &operator <<(std::ostream &output,Date&);
    friend std::istream &operator >>(std::istream &output,Date&);
    //(6+7)The overloaded increment/decrement
    friend Date operator ++ (Date&,int);//Post
    friend Date operator --(Date&,int);//Post
    friend Date operator ++(Date& d);//Pre
    friend Date operator --(Date& d);//Pre
    //(8)The overloaded logical operators
    friend bool operator ==(Date&,Date&);
    friend bool operator !=(Date&,Date&);
    friend bool operator >(Date&,Date&);
    friend bool operator <(Date&,Date&);
};


#endif //HW1_DATE_H
