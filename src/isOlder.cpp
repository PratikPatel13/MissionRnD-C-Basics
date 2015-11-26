#include<stdio.h>
int checkFormat(char *s);
int isLeap(int year);
int dateValid(int d, int m, int y);


int isOlder(char *dob1, char *dob2) {
	int d1, d2, m1, m2, y1, y2;

	if (!(checkFormat(dob1) && checkFormat(dob2)))
		return -1;
	sscanf(dob1, "%d-%d-%d", &d1, &m1, &y1);
	sscanf(dob2, "%d-%d-%d", &d2, &m2, &y2);

	// To check if month and date is valid or not
	if (d1 > 31 || d2 > 32 || m1 > 12 || m2 > 12)
		return -1;
	// Check if day is correct according to month
	if (!((dateValid(d1, m1, y1)) && dateValid(d2,m2,y2)))
		return -1;


	if (y1 != y2)
	{
		if (y1 < y2)
			return 1;
		else
			return 2;
	}
	else
	{
		if (m1 != m2)
		{
			if (m1 < m2)
				return 1;
			else
				return 2;
		}
		else
		{
			if (d1 != d2)
			{
				if (d1 < d2)
					return 1;
				else
					return 2;
			}
			else
			{
				return 0;
			}
		}
	}



}


// Checks the date is in the form of dd-mm-yyyy or not
int checkFormat(char *s1)
{
	int i = 0;
	if (!(s1[2] == '-' && s1[5] == '-'))
		return 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == '-')
		{
			i++;
		}
		else
		{
			if (s1[i] < '0' || s1[i] > '9')
				return 0;
			i++;
		}
	}
	return 1;
}

// Checks if the days are correct for given month.
int dateValid(int d, int m,int y)
{
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeap(y))
	{
		if (m == 2)
			if (d > 29)
				return 0;
	}
	else
	{
		if (d > days[m-1])
			return 0;
	}
	return 1;
}

// Checks if the year is leap year or not
int isLeap(int year)
{
	if (year % 400 == 0)
		return 1;
	if (year % 4 == 0)
		return 1;
	return 0;
}