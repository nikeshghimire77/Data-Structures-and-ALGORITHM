
/*Name: Nikesh Ghimire

Description: Get and print functions using getter and setter. Using constructors etc.

Date: 09/04/2018

Class Section: COSC 2430 ( Data Structure and Algorithm)

Title: Extras-02

 **********************************************************************/


#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person() {
	}
	Person(const Person &w) {
		this->name = w.name;
		this->address = w.address;
	}
	~Person() {
	}
	Person(string name, string address) {
		this->name = name;
		this->address = address;
	}
	string getName() {
		return name;
	}
	string getAddress() {
		return address;
	}
private:
	string name, address;
};
int main()
{
	Person *WitArray[10];
	for (int i = 0; i < 10; i++)
		WitArray[i] = 0;
	string name, address;
	for (int index = 0; index < 3; index++)
	{
		cout << "Enter name and address: ";
		cin >> name >> address;
		WitArray[index] = new Person(name, address);
	}
	for (int index = 0; index < 10; index++)
	{
		cout << WitArray[index]->getName() << " " << WitArray[index]->getAddress();
	}
	for (int index = 0; index < 10; index++)
	{
		delete WitArray[index];
	}
	//system("pause");
	return 0;

}