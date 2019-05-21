
/*Name: Nikesh Ghimire

Description: Decimal to binary using stack

Date: 10/12/2018

Class Section: COSC 2430 ( Data Structure and Algorithm)

Title: Extras-10
**********************************************************************/


#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
}*top = NULL, *p = NULL, *np = NULL;
int x;
void push(int n)
{
	np = new node;
	np->data = n;
	np->next = NULL;
	if (top == NULL)
	{
		top = np;
	}
	else
	{
		np->next = top;
		top = np;
	}
}
int pop()
{
	if (top == NULL)
	{
		cout << "underflow\n";
	}
	else
	{
		p = top;
		top = top->next;
		x = p->data;
		delete(p);
		return(x);
	}
}
int main()
{
	int n, a;
	cout << "Enter the decimal number: ";
	cin >> n;
	while (n > 0)
	{
		a = n % 2;
		n = n / 2;
		push(a);
	}
	p = top;
	cout << "Equivalent binary is :";
	while (true)
	{
		if (top != NULL)
			cout << pop();
		else
			break;
	}
	
	return 0;
}