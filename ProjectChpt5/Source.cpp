//This program inputs a date and outputs the 
//day of the week that corresponds to that date.
//March 24, 2020
//Cheron Fletcher

#include <iostream>
#include <string>
using namespace std;


void testMenu();
// post-condition: the test menu is displayed for choice
bool isLeapYear(int year);
//pre-condition: input a year
//post-condition: returns true if the year is a leap year
//returns false if year is not a leap year

int getCenturyValue(int year);
//pre-condition: input a year
//post-condition: gives corresponding century value of 0-6

int getYearValue(int year);
//pre-condition: input a year
//post-condition: computes a value based on the years since the beginning of the century

int getMonthValue(int month, int year);
//pre-condition: input month and year
//post-condition: gives corresponding month value of 0-6

int dayOfWeek(int month, int day, int year);
//pre-condition: input month, day and year in numeric form
//post-condition: gives corresponding day value of 0-6

std::string dayOfWeek(int day);
// pre-condition: day has integer value 0, 1, 2, 3, 4, 5, or 6
// post-condition: the name of the day of week is returned as a std::. If day has value 0, then SUNDAY is returned; 1, then MONDAY is returned; and so on.



int main()

{
    using namespace std;
    int choice;
    int day, month, year;
    do
    {
        testMenu();
        cout << "Please choose from menu: ";
        cin >> choice;
        switch (choice)
        {
        case 1: // check if a given year is leap year
            cout << "Please enter a year: ";
            cin >> year;
            if (isLeapYear(year))
                cout << "Year " << year << " is a leap year" << endl;
            else
                cout << "Year " << year << " is NOT a leap year" << endl;
            break;

        case 2: // calculate the century value of a given year
            cout << "Please enter a year: ";
            cin >> year;
            cout << "The century value is: " << getCenturyValue(year) << endl;
            break;

        case 3: // calculate the year value of a given year
            cout << "Please enter a year: ";
            cin >> year;
            cout << "The year value is: " << getYearValue(year) << endl;
            break;

        case 4: // calculate the month value of a given month in a given year 
            cout << "Please enter a month and year: ";
            cin >> month >> year;
            cout << "The month value is: " << getMonthValue(month, year) << endl;
            break;

        case 5: // calculate the day of week of a given date
            cout << "Please enter a month, a day, and a year : ";
            cin >> month >> day >> year;
            cout << "The day of the week is: " << dayOfWeek(month, day, year) << endl;
            break;

        case 6: // print out the name of a given day of week
            cout << "Please enter a day of week (0 for Sunday, 1 for Monday, etc): ";
            cin >> day;
            cout << "The name of the day of the week is: " << dayOfWeek(day) << endl;
            break;

        case 7:
            cout << "Did you test all the functions yet? If not, please rerun the program" << endl;
            break;

        default:
            cout << "wrong option. Please choose from menu" << endl;
            break;
        }

        system("pause");

    } while (choice != 7);
}

void testMenu() {
    cout << "*************************************" << endl;
    cout << "*             Test Menu             *" << endl;
    cout << "*                                   *" << endl;
    cout << "*    1. isLeapYear                  *" << endl;
    cout << "*    2. getCenturyValue             *" << endl;
    cout << "*    3. getYearValue                *" << endl;
    cout << "*    4. getMonthValue               *" << endl;
    cout << "*    5. dayOfWeek(month, day, year) *" << endl;
    cout << "*    6. dayOfWeek(day)              *" << endl;
    cout << "*    7. Quit                        *" << endl;
    cout << "*                                   *" << endl;
    cout << "*************************************" << endl;
}

bool isLeapYear(int year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

int getCenturyValue(int year) {
    //get first 2 digits of the year
    int century = year / 100;
    // divide century by 4
    int remainder = century % 4;
    //subtract the remainder from 3 and multiply this by 2
    return (3 - remainder) * 2;
}

int getYearValue(int year) {
    //extract the last two digits of the year
    int year2;
    if (year >= 1800 && year <= 1899)
        year2 = year - 1800;
    else if (year >= 1900 && year <= 1999)
        year2 = year - 1900;
    else if (year >= 2000 && year <= 2099)
        year2 = year - 2000;
    else if (year >= 2100 && year <= 2199)
        year2 = year - 2100;
    else if (year >= 2200 && year <= 2299)
        year2 = year - 2200;
    else if (year >= 2300 && year <= 2399)
        year2 = year - 2300;
    else if (year >= 2400 && year <= 2499)
        year2 = year - 2400;
    // factor in leap year
    int leap = year2 / 4;
    // add the 2 results
    return year2 + leap;

}

int getMonthValue(int month, int year) {
    //check for leap year
    if (isLeapYear(year) == true)
    {
        if (month == 1)
            return 6;
        else if (month == 2)
            return 2;
    }
    //not a leap year
    switch (month)
    {
    case 1: // January
        return 0;
    case 2: // February
        return 3;
    case 3: // March
        return 3;
    case 4: // April
        return 6;
    case 5: // May
        return 1;
    case 6: // June
        return 4;
    case 7: // July
        return 6;
    case 8: // August
        return 2;
    case 9: // September
        return 5;
    case 10: // October
        return 0;
    case 11: // November
        return 3;
    case 12: // December
        return 5;
    default:
        cout << "Please enter date and month as number values" << endl;
    }
}

int dayOfWeek(int month, int day, int year) {
    int date = (day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year)) % 7;
    return date;


}

std::string dayOfWeek(int day) {
    switch (day)
    {
    case 0:
        return "Sunday";
    case 1:
        return "Monday";
    case 2:
        return "Tuesday";
    case 3:
        return "Wednesday";
    case 4:
        return "Thursday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";
    default:
        return "ERROR! Please enter day numerically";
    }
}






