/*Name: Nikesh Ghimire
Description: Using struct, pointers to display students data
Date: 09/03/2018
Class Section: COSC 2430 ( Data Structure and Algorithm)
Title: Extras-03
 **********************************************************************/

#include <iostream>
using namespace std;
struct student {
	int id;
	char name[30];
	double gpa;
};
void readValue(student *ptr[]) {

	for (int i = 0; i < 4; i++) {
		cout << "Enter student" << i + 1 << "'s id: ";
		cin >> ptr[i]->id;
		cout << "Enter student" << i + 1 << "'s name: ";
		cin.ignore();
		cin.getline(ptr[i]->name, 30);
		cout << "Enter student" << i + 1 << "'s GPA: ";
		cin >> ptr[i]->gpa;
	}
}
void displayValue(student *ptr[]) {
	for (int i = 0; i < 4; i++) {

		cout << "Student" << i + 1 << "'s id: " << ptr[i]->id << endl;
		cout << "Student" << i + 1 << "'s name: " << ptr[i]->name << endl;
		cout << "Student" << i + 1 << "'s GPA: " << ptr[i]->gpa << endl;
	}
}
int main() {
	student data1;
	student data2;
	student *ptr[4];
	ptr[0] = &data1;
	ptr[1] = &data2;
	ptr[2] = new student;
	ptr[3] = new student;
	readValue(ptr);
	displayValue(ptr);
	return 0;
}