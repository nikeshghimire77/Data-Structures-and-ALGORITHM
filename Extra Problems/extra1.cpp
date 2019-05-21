#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;
class Student {
private:
	string name;
	double GPA;

public:
	Student(string name = "not intialized", double GPA = 0.0);
	void SetName(string studentName);
	void SetGPA(double personName);
	string ToString() const;
};
Student::Student(string initialName, double initialGPA) {
	name = initialName;
	GPA = initialGPA;
}
void Student::SetName(string inputName) {
	name = inputName;
}
void Student::SetGPA(double newGPA) {
	GPA = newGPA;
}
string Student::ToString() const {
	stringstream sstr;
	sstr << GPA;
	return name + " has a GPA of " + sstr.str();;
}

int main() {
	vector<Student*> students;
	string option;
	string name;
	double GPA;
	int index;
	cout << "Menu:\n";
	cout << " add\n";
	cout << " drop\n";
	cout << " print\n";
	cout << " quit\n";

	while (true)
	{
		cout << "\n\nEnter option : ";
		cin >> option;
		if (option == "add")
		{
			cout << "Student name: ";
			cin >> name;

			cout << name << "'s GPA: ";
			cin >> GPA;
			students.push_back(new Student(name, GPA));
		}
		else if (option == "drop")
		{
			cout << "Index of student to drop: ";
			cin >> index;

			if (students.size() != 0 && index < students.size())
			{
				students.erase(students.begin() + index);
			}
			else
			{
				cout << "Invalid index!" << endl;
			}
		}
		else if (option == "print")
		{
			for (int i = 0; i < students.size(); ++i)
			{
				cout << i << ": " << students[i]->ToString() << endl;
			}
		}
		else if (option == "quit")
		{
			break;
		}
		else
		{
			cout << "Invalid option\n";
		}
	}
	return 0;
}