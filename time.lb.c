// Ritchie, D. and Kernighan, W. (1988) p99

static char daytab[13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day)
{  /* day_of_year: set day of year from month & day */
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[i];
	day += (leap && 2 < month)
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{ /* month_day: set month, day from day of year */
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	yearday -= (leap && yearday >= 60)
	for (i = 1; yearday > daytab[i]; i++)
		yearday -= daytab[i];
	*pmonth = i;
	*pday = yearday;
}