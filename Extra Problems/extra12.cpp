
/*Name: Nikesh Ghimire

Description: Write a function split, which keeps splitting the array from the mid.

Date: 10/04/2018

Class Section: COSC 2430 ( Data Structure and Algorithm)

Title: Extras-07

 **********************************************************************/
#include <iostream>
using namespace std;

void split(int a[], int low, int high);

void split(int a[], int low, int high)
{
	if (high >= low)
	{
		int mid= low + (high - low) / 2;


		split(a, low, mid - 1);


		split(a, mid + 1, high);
	}
	cout << "bye-bye" << endl;

}

int main(void)
{
	int a[] = {5,6,3,6,3,8,5,4,1,2};
	int n = sizeof(a) / sizeof(a[0]);
	split(a, 0, n - 1);
	return 0;
}