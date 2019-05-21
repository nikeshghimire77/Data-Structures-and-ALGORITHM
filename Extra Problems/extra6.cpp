/*Name: Nikesh Ghimire
Description: Checking for Palindrome using stack and queue
Date: 09/13/2018
Class Section: COSC 2430 ( Data Structure and Algorithm)
Title: Extras-06
 **********************************************************************/

#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main()
{
	queue<char> MyQueue;
	stack<char> MyStack;
	string input;
	cout << "Enter a string: ";
	getline(cin, input, '\n');
	for (int i = 0; i < input.size(); i++)
	{
		MyQueue.push(input.at(i));
		MyStack.push(input.at(i));
	}
	bool isPalindrome = true;
	while (!MyStack.empty() && !MyQueue.empty())
	{
		if (MyStack.top() == MyQueue.front())
		{
			MyStack.pop();
			MyQueue.pop();
		}
		else
		{
			isPalindrome = false;
			break;
		}
	}
	if (isPalindrome)
		cout << "Given string \"" << input << "\" is Palindrome" << endl;
	else
		cout << "Given string \"" << input << "\" is Not palindrome" << endl;
	//system("pause");
	return 0;
}