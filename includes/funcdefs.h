#ifndef FUNCDEFS_H_INCLUDED
#define FUNCDEFS_H_INCLUDED

int getDaysUntilMonth(int month);
int getMonthOfSplit(int numberOfDays);
Date getSplitDate(Date date1, long numberOfDays);
long findDifference(Date date1, Date date2);
Month fetchMonthInfo(int userMonth);
int checkMaxDays(int month);
Date userInput(Date userDate);
void printDate(Date userDate, Month userMonth);
void printDifference (long daysDifference, int leapDays, long yearsDifference, int yearsDifferenceRemainder, Date splitD);

#endif // FUNCDEFS_H_INCLUDED
