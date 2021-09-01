// Ritchie, D. and Kernighan, W. (1988) p99

static char daytab[2][13] = 
	{{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	 {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}}
;

int day_of_year(int year,unsigned int month,unsigned int day)
{  /* day_of_year: set day of year from month & day */
	int i, leap;
	if (!day || !month || year < 1582 || month > 12)
		return -1;
	leap = (!(year%4) && (year%100)) || !(year%400);
	if (day > *(*(daytab + leap) + month))
		return -1;
	for (i = 1; i < month; i++)
		day += *(*daytab + i);
	day += (leap && 2 < month);
	return day;
}

_Bool month_day(int year, int yearday, int *pmonth, int *pday)
{ /* month_day: set month, day from day of year */
	int i, leap;
	leap = (!(year%4) && (year%100)) || !(year%400);
	if (year < 1582 || yearday < 1 || yearday > 365 + leap)
		return 1;
	for (i = 1; yearday > *(*(daytab + leap)+i); i++)
		yearday -= *(*(daytab + leap)+i);
	*pmonth = i;
	*pday = yearday;
	return 0;
}
