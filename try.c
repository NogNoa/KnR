#include <stdio.h>
#include "time.lb.c"


int main(int argc, char *argv[])
{
    int year, month, day, yearday;
    
    for (year = 1970; year <= 2000; ++year) {
        for (yearday = 1; yearday < 366; ++yearday) {
            if (month_day(year, yearday, &month, &day) == 1) {
                printf("month_day failed: %d %d\n",
                    year, yearday);
            } else if (day_of_year(year, month, day) != yearday) {
                printf("bad result: %d %d\n", year, yearday);
                printf("month = %d, day = %d\n", month, day);
            }
        }
    }
    return 0;
}
