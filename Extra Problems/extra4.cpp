#include<iostream>
#include<string>
using namespace std;

struct Node {
	int data;
	Node *next;
};

class Linkedlist
{
private:
	Node*head;
public:
	Linkedlist() { head = NULL; }
	void insertatBeg(int x);
	void insertatLast(int x);
	void insertafter(int x, int y);
	void deleteatbeg();
	void deleteatlast();
	void print();
};

void Linkedlist::insertatBeg(int x)
{
	Node * temp = new Node;
	temp->data = x;
	temp->next = head;
	head = temp;
}
void Linkedlist::insertatLast(int x)
{
	Node *p = new Node;
	Node * temp = new Node;
	p->data = x;
	temp = head;
	if (head == NULL)
	{
		p->next = NULL;
		head = p;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		p->next = NULL;
		temp->next = p;
		
	}
}

void Linkedlist::insertafter(int y, int x)
{
	Node * temp = new Node;
	temp = head;
	while (temp != NULL)
	{
		if (temp->data = y) 
		{
			Node *p = new Node;
			p->data = x;
			p->next = temp->next;
			temp->next = p;
			return;
		}
			temp = temp->next;
	}
		if(temp==NULL) { cout << "Link is not found"; }
}
void Linkedlist::deleteatbeg()
{
	Node *temp = new Node;
	temp = head;
	head = head->next;
	delete temp;
}
void Linkedlist::deleteatlast()
{
	Node *temp = head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = NULL;
}
void Linkedlist::print()
{
	Node *temp = head;
	if (temp == NULL)
	{
		cout << "The linkedlist is empty" << endl;
	}
	cout << "The linked list are: ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main(int argc, char * argv[])
{
	Linkedlist L;
	L.insertatBeg(3);
	L.insertatLast(4);
	L.insertatBeg(5);
	L.insertatLast(10);
	L.insertatBeg(7);
	L.print();
	L.insertatBeg(7);
	L.insertafter(3, 11);
	L.print();
	L.deleteatbeg();
	L.print();
	//system("pause");
	return 0;
}