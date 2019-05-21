
/*Name: Nikesh Ghimire
Description: Check for palindrome using Stack and Queue
Date: 10/04/2018
Class Section: COSC 2430 ( Data Structure and Algorithm)
Title: Extras-08
 **********************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

bool is_palindrome(string str) {
	stack<int> st;
	queue<int> q;
	for (int i = 0; i < str.size(); i++) {
		st.push(str[i] - 'a');
		q.push(str[i] - 'a');
	}
	while (!st.empty() && !q.empty()) {
		int tp = st.top();
		st.pop();
		int frnt = q.front();
		q.pop();
		if (tp != frnt)
			return false;
	}
	return true;
}

int main() {
	string str, processed_string;
	cout << "Enter any string: ";
	getline(cin, str);
	if (is_palindrome(str)) {
		cout << "Given string is plaindrome" << endl;
	}
	else {
		cout << "Given string is not palindrome" << endl;
	}
	return 0;
}