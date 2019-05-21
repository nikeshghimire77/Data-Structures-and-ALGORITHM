
/*Name: Nikesh Ghimire

Description: Finding factors of any number in descending order uisng Stack

Date: 10/20/2018

Class Section: COSC 2430 ( Data Structure and Algorithm)

Title: Extras-09

 **********************************************************************/


#include <iostream>
#include <cmath>
using namespace std;
void factor(int c, int n);
int stack[10000];
int top = 0;
void push(int x)
{
	stack[top++] = x;
}
int pop()
{
	if (top == 0)
		return -1;
	else
	{
		top--;
		return stack[top];
	}
	return -1;
}
void factor_r(int x)
{
	int i;
	int c;
	c = x;
	if ((c % 2) == 0)
	{
		push(2);
		c = c / 2;
		factor_r(c);
	}
	else
		factor(x, 3);
}

void factor(int c, int n)
{
	int i;
	i = n;
	if (n == 1)
		return;
	if (c == n)
	{
		push(n);
		return;
	}
	if (i <= c)
	{
		if ((c%i) == 0)
		{//cout<<"2nd"<<endl;
			push(i);
			c = c / i;
			factor(c, i);
		}
		else
		{
			i = i + 2;
			factor(c, i);
		}
	}
}
int main()
{
	int p;
	cout << "Enter number: ";
	cin >> p;
	cout << "\nPrime factors of " << p << ": ";
	factor_r(p);
	while ((p = pop()) != -1)
		cout << p << " ";
	cout << endl;
	return 0;
}