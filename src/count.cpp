/*
OVERVIEW:  Given 2 integers (num1, num2), write a function that returns the count of numbers between the num1..num2 that are divisible by num1.
		E.g.: count(3, 15) returns 5 (3, 6, 9, 12, 15).

INPUTS:  Two numbers num1, num2.
		num1, num2 >= 0.

OUTPUT: Return the count of numbers between the num1..num2 that are divisible by num1.

ERROR CASES: Return -1 in error cases.

NOTES:
*/
int count(int num1, int num2) {
	int i, count= 0;
	if (num1 >= 1&&num2>=0)
	{
		if (num1<=num2)
		{
			for (i = num1; i <= num2; i++)
			{
				if (i%num1 == 0)
					count++;
			}
			return count;
		}
		else
			return 0;
	}
	else
		return -1;
}