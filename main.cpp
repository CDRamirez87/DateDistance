#include <iostream>
#include <cmath>
#include "./includes/datestruct.h"
#include "./includes/funcdefs.h"

//Originally written June, 29, 2015
using namespace std;

//used in Date getSplitDate()
int getMonthOfSplit(int numberOfDays)
{
    int monthNumber(0);

    if (numberOfDays <= 31)
        monthNumber = 1;

    else if (numberOfDays > 31 && numberOfDays <= 59)
        monthNumber = 2;

    else if (numberOfDays > 59 && numberOfDays <= 90)
        monthNumber = 3;

    else if (numberOfDays > 90 && numberOfDays <= 120)
        monthNumber = 4;

    else if (numberOfDays > 120 && numberOfDays <= 151)
        monthNumber = 5;

    else if (numberOfDays > 150 && numberOfDays <= 181)
        monthNumber = 6;

    else if (numberOfDays > 181 && numberOfDays <= 212)
        monthNumber = 7;

    else if (numberOfDays > 212 && numberOfDays <= 243)
        monthNumber = 8;

    else if (numberOfDays > 243 && numberOfDays <= 273)
        monthNumber = 9;

    else if (numberOfDays > 273 && numberOfDays <= 304)
        monthNumber = 10;

    else if (numberOfDays > 304 && numberOfDays <= 334)
        monthNumber = 11;

    else if (numberOfDays > 334)
        monthNumber = 12;

    return monthNumber;
}


Date getSplitDate(Date date1, long numberOfDays)
{
    //Splits the number of days between dates
    long splitDate = ( numberOfDays / 2 );

    //Finds the number of years between the first and the split date
    long yearCounter = ( splitDate / 365 );
    //Locks in the Year for the MidDate (unless an extra is when date1POS and remaining SDD are added
    date1.year += yearCounter;
    //Finds the number of days after the years have been cancelled out
    //This plus the first Month/Date should provide the mid date, provided it resets at 365
    int dayCounter = (splitDate % 365);

    //Shows how many days into the year Date 1 is
    int depthInYearDate1 = (( getDaysUntilMonth(date1.month) + date1.day )) + dayCounter;

    //if result > 365, ++year and -=365,
    if( date1.isLeap && ( depthInYearDate1 > 366))
    {
        depthInYearDate1 -= 366;
        ++date1.year;
    }

    else if (( !date1.isLeap ) && depthInYearDate1 > 365 )
    {
        depthInYearDate1 -=365;
        ++date1.year;
    }

    //find the month dayCounter is in
    date1.month = getMonthOfSplit( depthInYearDate1 );
    int extraDaysInYear = getDaysUntilMonth(getMonthOfSplit( depthInYearDate1 ));
    date1.day = ( depthInYearDate1 - extraDaysInYear );

    return date1;
}
/*
  //Original (before switched statements learned)
 int getDaysUntilMonth(int month)
 {
    int daysUntilMonth(0);

    if (month == 1)
        daysUntilMonth = 0;
    else if (month == 2)
        daysUntilMonth = 31;
    else if (month == 3)
        daysUntilMonth = 59;
    else if (month == 4)
        daysUntilMonth = 90;
    else if (month == 5)
        daysUntilMonth = 120;
    else if (month == 6)
        daysUntilMonth = 151;
    else if (month == 7)
        daysUntilMonth = 181;
    else if (month == 8)
        daysUntilMonth = 212;
    else if (month == 9)
        daysUntilMonth = 243;
    else if (month == 10)
        daysUntilMonth = 273;
    else if (month == 11)
        daysUntilMonth = 304;
    else if (month == 12)
        daysUntilMonth = 334;

        return daysUntilMonth;
 }
*/

//used in findDifference()
 int getDaysUntilMonth(int month)
 {
    switch (month)
    {
    case MONTH_JANUARY:
        return 0;
    case MONTH_FEBRUARY:
        return 31;
    case MONTH_MARCH:
        return 59;
    case MONTH_APRIL:
        return 90;
    case MONTH_MAY:
        return 120;
    case MONTH_JUNE:
        return 151;
    case MONTH_JULY:
        return 181;
    case MONTH_AUGUST:
        return 212;
    case MONTH_SEPTEMBER:
        return 243;
    case MONTH_OCTOBER:
        return 273;
    case MONTH_NOVEMBER:
        return 304;
    case MONTH_DECEMBER:
        return 334;
    default:
        return -10000;
    }


 }
long findDifference(Date date1, Date date2)
{

    //totalDifference is in days
    long totalDifference(0);
    long yearDifference = date1.year - date2.year;

    totalDifference += (yearDifference * 365);

    int daysIntoYear1(0), daysIntoYear2(0);
    daysIntoYear1 = getDaysUntilMonth(date1.month);
    daysIntoYear2 = getDaysUntilMonth(date2.month);
    if (date1.month > date2.month)
        (daysIntoYear1 * -1);

    int daysWithinYear1(0), daysWithinYear2(0);
    daysWithinYear1 = (daysIntoYear1 + date1.day);
    daysWithinYear2 = (daysIntoYear2 + date2.day);

    totalDifference += (daysWithinYear1 - daysWithinYear2);

    return totalDifference;
}

Month fetchMonthInfo(int userMonth)
{
    if (userMonth == 1)
        return january;
    else if (userMonth == 2)
        return february;
    else if (userMonth == 3)
        return march;
    else if (userMonth == 4)
        return april;
    else if (userMonth == 5)
        return may;
    else if (userMonth == 6)
        return june;
    else if (userMonth == 7)
        return july;
    else if (userMonth == 8)
        return august;
    else if (userMonth == 9)
        return september;
    else if (userMonth == 10)
        return october;
    else if (userMonth == 11)
        return november;
    else if (userMonth == 12)
        return december;
    else
        return january;
}

/* These were a relic of a bad algorithm. Take heed of their failure!
Date makeDate1Highest(Date date1, Date date2)
{

    if (date1.year < date2.year)
        date1.year = date2.year;

    if (date1.month < date2.month)
        date1.month = date2.month;

    if (date1.day < date2.day)
        date1.day = date2.day;

        return date1;
}

Date makeDate2Lowest(Date date1, Date date2)
{
   if (date1.year < date2.year)
        date2.year = date1.year;

    if (date1.month < date2.month)
        date2.month = date1.month;

    if (date1.day < date2.day)
        date2.day = date1.day;

        return date2;
}
*/

// used in userInput()
int checkMaxDays(int month)
{
    int maxDays(0);

    if (month == MONTH_JANUARY || month == MONTH_MARCH || month == MONTH_MAY || month == MONTH_JULY ||
        month == MONTH_AUGUST || month == MONTH_OCTOBER || month == MONTH_DECEMBER )
            maxDays = 31;

    else if (month ==  MONTH_SEPTEMBER || month == MONTH_APRIL || month == MONTH_JUNE || month == MONTH_NOVEMBER )
            maxDays = 30;

    else
            maxDays = 28;

    return maxDays;


}

Date userInput(Date userDate)
{
    cout << "Please enter a Month (number from 1-12): ";
    cin >> userDate.month;

    if ((userDate.month > 12) || (userDate.month < 1))
        userDate.month = 1;
    int maxDays = checkMaxDays(userDate.month);

    cout << "Please enter a Day: ";
    cin >> userDate.day;

    if (userDate.day > maxDays)
            userDate.day = maxDays;

    cout << "Please enter a Year: ";
    cin >> userDate.year;

    if (userDate.year > 32500)
        userDate.year = 32500;

    if ((userDate.year % 4) == 0)
        userDate.isLeap = 1;

    cout << "\n";

    return userDate;

}

void printDate(Date userDate, Month userMonth)
{
    cout << "You chose:\n";
    cout << "\n" << userDate.month << "-" << userDate.day << "-" << userDate.year << "\n";

    cout << userMonth.monthName << " " << userDate.day << ", " << userDate.year << "\n";

    cout << "This month has " << userMonth.numberDays << " days and is month number " <<
            userMonth.orderNumber << ".\n";

    if ( userDate.isLeap == true )
            cout << "This year is a leap year." << "\n";
    else
            cout << "This year is not a leap year.\n";
}

void printDifference (long daysDifference, int leapDays, long yearsDifference, int yearsDifferenceRemainder, Date splitD)
{
    Month splitDMonth = fetchMonthInfo(splitD.month);
    cout << "\nThere are " << daysDifference << " days between these two dates.\n";
    cout << leapDays << " of these are leap year days.\n";
    cout << "That's " << yearsDifference << " years and " << yearsDifferenceRemainder << " days.\n\n";
    cout << "The date in the middle of these is " << splitDMonth.monthName << " " << splitD.day << ", " << splitD.year << ".\n";
}

int main()
{
    Date userDate1 = { 0, 0, 0, 0 };
    Date userDate2 = { 0, 0, 0, 0 };

    userDate1 = userInput(userDate1);
    userDate2 = userInput(userDate2);

    // RELIC OF BAD PLANNING:
    // Swtiches Dates so makeDate1 is highest
    // Date userDate1Temp = makeDate1Highest(userDate1, userDate2);
    // Date userDate2Copy = makeDate2Lowest(userDate1, userDate2);
    // Date userDate1Copy  = userDate1Temp;

    long daysDifference = abs(findDifference(userDate1, userDate2)); //user data copies were here

    //find number of leap year days
    int leapYearDays = ((abs(userDate1.year - userDate2.year) / 4)); //user data copies were here
    daysDifference += leapYearDays;

    //Find number of years from days
    long yearsDifference = ((daysDifference - leapYearDays) / 365);
    long yearsDifferenceRemainder = (daysDifference % 365);

    Date midDate = getSplitDate(userDate1, daysDifference);

    Month userMonth1 = fetchMonthInfo(userDate1.month);
    Month userMonth2 = fetchMonthInfo(userDate2.month);

    printDate(userDate1, userMonth1);
    cout << "\nand\n\n";
    printDate(userDate2, userMonth2);

    printDifference(daysDifference, leapYearDays, yearsDifference, yearsDifferenceRemainder, midDate);

    cout << "\nPress Enter to continue";
    cin.clear(); // reset any error flags
    cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
    cin.get(); // get one more char from the user

    return 0;
}
