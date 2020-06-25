#include "Date.h"
#include<iostream>

using namespace std;

int main() {//The testing main function
    Date date1(31, 1, 2019);
    Date date2(1, 3, 2019);
    Date date3(15, 4, 2019);
    Date date4(15, 4, 2019);
    Date date5;
    cout << "date1 :";
    cout << "Day =" << date1.getDay();
    cout << " , Month = " << date1.getMonth();
    cout << " , Year = " << date1.getYear() << endl;
    cout << "date1 : " << date1 << endl;
    cout << "date2 : " << date2 << endl;
    cout << "date3 : " << date3 << endl;
    cout << "date4 : " << date4 << endl;
    if (date1 == date2) cout << "date1 is equal to date2" << endl;
    if (date1 != date2) cout << "date1 is not equal to date2" << endl;
    if (date3 == date4) cout << "date3 is equal to date4" << endl;
    if (date3 != date4) cout << "date3 is not equal to date4" << endl;
    if (date1 < date2) cout << "date1 is before date2" << endl;
    if (date3 > date1) cout << "date3 is after date1" << endl;
    cout << "date1 before auto-increment:" << date1 << endl;
    date1++;
    cout << "date1 after auto-increment:" << date1 << endl;
    cout << "date2 before auto-decrement:" << date2 << endl;
    date2--;
    cout << "date2 after auto-decrement:" << date2 << endl;
    cin >> date5;
    cout << "date5 :" << date5 << endl;
    date1.setDate(1, 12, 2020);
    cout << "date1 : " << date1 << endl;
    date1.setDate(29, 2, 2019); //invalid day
    cout << "date1 : " << date1 << endl;
    return 0;
}
