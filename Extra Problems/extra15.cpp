#include <iostream>
#include <string>
using namespace std;

class Phonedirectory 
{
	private:
			int tsize;
			int nstored; 

			string *keys;
			int *values;
			int *sentinels;

			static const int curr_used = 1;
			static const int never_used = 0;
			static const int prev_used = -1;
			static const int default_size = 10000; 

			int probeFunction(int val, int iter);
			void init(int tsizei);

			int hash(string key);
			int sillyHash(string key);
			int smarterHash(string key);

		public:
			Phonedirectory();
			Phonedirectory(int nkeys);
			~Phonedirectory();

			bool insert(string key, int value);
			bool remove(string key, int value);
			bool lookup(string key, int& value);
			bool modify(string key, int value);
			void getKeys(string*& all_keys, int& nkeys);
			int numStored();
		
			void printTable();
};
Phonedirectory::Phonedirectory()
{
	init(default_size);
}
Phonedirectory::Phonedirectory(int nkeys)
{
	init(4*nkeys);
}
Phonedirectory::~Phonedirectory()
{
	delete[] keys;
	delete[] values;
	delete[] sentinels;
}
bool Phonedirectory::insert(string key, int value)
{
	int index = hash(key);

	int x = 1;
	while (index<tsize && sentinels[index] == curr_used)
	{
		index = probeFunction(index, x);
		x++;
	}
	if (index >= tsize)
	{
		return false;
	}

	keys[index] = key;
	values[index] = value;
	sentinels[index] = curr_used;
	nstored++;

	return true;
}
bool Phonedirectory::remove(string key, int value)
{
	int index = hash(key);
	
	int x = 1;
	while (index<tsize && (keys[index] != key || values[index] != value))
	{
		index = probeFunction(index, x);
		x++;
	}
	if (index >= tsize)
	{
		return false;
	}

	keys[index] = "";
	values[index] = 0;
	sentinels[index] = prev_used;
	nstored--;

	return true;
}
bool Phonedirectory::lookup(string key, int &value)
{
	int index = hash(key);
	int x = 1;

	while (index < tsize && keys[index] != key)
	{
		index = probeFunction(index, x);
		x++;
	}

	if (index >= tsize)
	{
		return false;
	}

	value = values[index];

	return true;
}
bool Phonedirectory::modify(string key, int value)
{
	int index = hash(key);
	
	int x = 1;
	while (index < tsize && keys[index] != key)
	{
		index = probeFunction(index, x);
		x++;
	}

	if (index >= tsize)
	{
		return false;
	}

	values[index]=value;

	return true;
}
void Phonedirectory::getKeys(string*& all_keys, int& nkeys)
{
	nkeys = nstored;
	int count = 0;

	for (int i = 0; count<nstored; i++)
	{
		if (sentinels[i] == curr_used)
		{
			all_keys[count] = keys[i];
			count++;
		}
	}
}
int Phonedirectory::numStored()
{
	return nstored;
}
void Phonedirectory::printTable()
{
	for (int i = 0; i < tsize; i++)
	{
		if (sentinels[i] == curr_used)
		{
			cout << "Name: "<<keys[i] << ", Phone: " << values[i] << endl;
		}
	}

}
int Phonedirectory::probeFunction(int val, int iter)
{
	return (val+(iter*2));
}
void Phonedirectory::init(int tsizei)
{
	nstored = 0;
	tsize = tsizei;

	keys = new string[tsize];
	values = new int[tsize];
	sentinels = new int[tsize];

	for (int i = 0; i < tsize; i++)
	{
		sentinels[i] = never_used;
		values[i] = 0;
	}
}
int Phonedirectory::hash(string key)
{
	int sum = 0;
	int length = key.length();

	for (int i = 0; i < length; i++)
	{
		sum = sum + key[i];
	}
	return sum % 10;
}
int Phonedirectory::sillyHash(string key)
{
	return (key[0] % 10);
}
int Phonedirectory::smarterHash(string key)
{
	int sum = 0;
	int length = key.length();
	for (int i = 0; i < length; i++)
	{
		sum=sum+key[i];
	}
	return sum % 10;
}

int main()
{
	int size = 0;
	cout << "Hello! Welcome to the Phone Directory Program!" << endl;
	cout << "Enter the size you'd like your directory to be: ";
	cin >> size;
	
	if (size < 1)
	{
		size = 1000;
	}

	Phonedirectory book(size);

	int choice=0;
	while (choice != 8)
	{
		cout << "\n1. Insert a new phone number." << endl;
		cout << "2. Remove a phone number." << endl;
		cout << "3. Lookup a person's phone number." << endl;
		cout << "4. Modify a phone number." << endl;
		cout << "5. Print the names of all people in the directory" << endl;
		cout << "6. See the number of entries in the directory." << endl;
		cout << "7. Print all the contents of the directory" << endl;
		cout << "8. Exit the program" << endl;
		cin >> choice;

		switch (choice)
		{
			case 1:
			{
				string name = "";
				int phone = 0;

				cout << "Enter the name for the phone number: ";
				cin >> name;
				cout << "\nEnter the phone number for " << name << ": ";
				cin >> phone;
				
				if (!book.insert(name, phone))
				{
					cout << "Sorry, could not add to the directory." << endl;
				}

			}
				break;
			case 2:
			{
				string name = "";
				int phone = 0;

				cout << "Enter the name for the phone number: ";
				cin >> name;
				cout << "\nEnter the phone number for " << name << ": ";
				cin >> phone;

				if (!book.remove(name, phone))
				{
					cout << "\nThe number was not found in the directory." << endl;
				}
			}
				break;
			case 3:
			{
				string name = "";
				int phone;
				cout << "Enter the name for the phone number: ";
				cin >> name;

				if (book.lookup(name, phone))
				{
					cout << "\nThe phone number for " << name << " is " << phone << endl;
				}
				else
				{
					cout << "\nSorry, the name you gave could not be found in the directory." << endl;
				}
			}
				break;
			case 4:
			{
				string name = "";
				int phone = 0;

				cout << "Enter the name for the phone number you'd like to modify: ";
				cin >> name;
				cout << "\nEnter the new phone number for " << name << ": ";
				cin >> phone;

				if (!book.modify(name, phone))
				{
					cout << "\nSorry, the name you gave could not be found in the directory." << endl;
				}
			}
				break;
			case 5:
			{
				int num = book.numStored();
				string *names = new string [num];
				int nkeys;

				book.getKeys(names, nkeys);

				for (int i = 0; i < nkeys; i++)
				{
					cout << names[i] << endl;
				}

				delete[] names;
			}
				break;
			case 6:
			{
				cout << "The number of entries in the directory is " << book.numStored() << endl;
			}
				break;
			case 7:
			{
				book.printTable();
			}
				break;
			case 8:
				continue;
				break;
			default:
				cout << "Invalid input. Try again." << endl;
				break;
		}
	}

	//system("pause");
	return 0;
}