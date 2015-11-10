/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

#include<stdlib.h>

int strlength(char *str) {
	int counter = 0;
	while (str[counter] != '\0')
		counter++;
	return counter;
}

int strcompare(char *s1, char *s2) {
	int n1 = strlength(s1), n2 = strlength(s2), i;
	int g, c = 0;
	if (n1<n2)
		g = n2;
	else if (n1>n2)
		g = n1;
	else
		g = n1;
	for (i = 0; i<g; i++) {
		if (s1[i] == s2[i])
			c++;
		else
			return (s1[i] - s2[i]);
	}
	if (c != 0)
		return 0;
}
char * getDate(char *dob) {
	char *dd = (char *)malloc(sizeof(char));
	dd[0] = dob[0];
	dd[1] = dob[1];
	dd[2] = '\0';
	return dd;
}
char * getmonth(char *dob) {
	char *mm = (char *)malloc(sizeof(char));
	mm[0] = dob[3];
	mm[1] = dob[4];
	mm[2] = '\0';
	return mm;
}
char * getyear(char *dob) {
	char *yyyy = (char *)malloc(sizeof(char));
	yyyy[0] = dob[6];
	yyyy[1] = dob[7];
	yyyy[2] = dob[8];
	yyyy[3] = dob[9];
	yyyy[4] = '\0';
	return yyyy;
}
int validate(char *dob) {
	int counter = 0, datetrue = 0;
	char *dd, *mm, *yyyy;
	if (strlength(dob) == 10) {
		for (counter = 0; counter < 10; counter++) {
			if ((dob[counter] >= '0' && dob[counter] <= '9') || dob[counter] == '-');
			else
			{
				return -1;
			}
		}
		dd = getDate(dob);
		mm = getmonth(dob);
		yyyy = getyear(dob);
		if (strcompare(mm, "13") < 0) {
			if (strcompare(mm, "01") == 0 || strcompare(mm, "03") == 0 || strcompare(mm, "05") == 0 || strcompare(mm, "07") == 0 || strcompare(mm, "08") == 0 || strcompare(mm, "10") == 0 || strcompare(mm, "12") == 0) {
				if (strcompare(dd, "31") <= 0) {
					datetrue = 1;
				}
			}
			else if (strcompare(mm, "04") == 0 || strcompare(mm, "06") == 0 || strcompare(mm, "09") == 0 || strcompare(mm, "11") == 0) {
				if (strcompare(dd, "30") <= 0) {
					datetrue = 1;
				}
			}
			else {
				if (atoi(yyyy) % 400 == 0 || (atoi(yyyy) % 100 != 0 && atoi(yyyy) % 4 == 0)) {
					if (strcompare(dd, "29") <= 0) {
						datetrue = 1;
					}
				}
				else
				{
					if (strcompare(dd, "28") <= 0) {
						datetrue = 1;
					}
				}
			}
		}
		else
		{
			return -1;
		}
	}
	else
		return -1;
	return datetrue;
}
int compare_2_dates(char *dob1, char *dob2) {
	if (strcompare(getyear(dob1), getyear(dob2)) == 0) {
		if (strcompare(getmonth(dob1), getmonth(dob2)) == 0) {
			if (strcompare(getDate(dob1), getDate(dob2)) == 0) {
				return 0;
			}
			else if (strcompare(getDate(dob1), getDate(dob2)) < 0)
			{
				return 1;
			}
			return 2;
		}
		else if (strcompare(getmonth(dob1), getmonth(dob2))<0)
		{
			return 1;
		}
		return 2;
	}
	else if (strcompare(getyear(dob1), getyear(dob2))<0)
	{
		return 1;
	}
	return 2;
}

int isOlder(char *dob1, char *dob2) {
	if (validate(dob1) == 1 && validate(dob2) == 1) {
		return compare_2_dates(dob1, dob2);
	}
	else
		return -1;
}
