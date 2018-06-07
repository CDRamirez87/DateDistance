#ifndef DATESTRUCT_H_INCLUDED
#define DATESTRUCT_H_INCLUDED
//Didn't know enums completely when i wrote this
enum MonthOrder
{
    MONTH_JANUARY = 1,  //1
    MONTH_FEBRUARY,     //2
    MONTH_MARCH,        //3
    MONTH_APRIL,        //4
    MONTH_MAY,          //5
    MONTH_JUNE,         //6
    MONTH_JULY,         //7
    MONTH_AUGUST,       //8
    MONTH_SEPTEMBER,    //9
    MONTH_OCTOBER,      //10
    MONTH_NOVEMBER,     //11
    MONTH_DECEMBER      //12
};

struct Month
{
    std::string monthName;
    int numberDays;
    int orderNumber;
};

const Month january   = { "January", 31, MONTH_JANUARY };
const Month february  = { "February", 28, MONTH_FEBRUARY };
const Month march     = { "March", 31, MONTH_MARCH };
const Month april     = { "April", 30, MONTH_APRIL };
const Month may       = { "May", 31, MONTH_MAY };
const Month june      = { "June", 30, MONTH_JUNE };
const Month july      = { "July", 31, MONTH_JULY };
const Month august    = { "August", 31, MONTH_AUGUST };
const Month september = { "September", 30, MONTH_SEPTEMBER };
const Month october   = { "October", 31, MONTH_OCTOBER };
const Month november  = { "November", 30, MONTH_NOVEMBER };
const Month december  = { "December", 31, MONTH_DECEMBER };

struct Date
{
    int day;
    int month;
    int year;
    bool isLeap;
};

#endif // DATESTRUCT_H_INCLUDED
