/*Name: Nikesh Ghimire
  Description : Printing the AVL tree using all the rotation
  Date: 11/02/2018
  Class Section: COSC 2430 ( Data Structure and Algorithm)
  Title: Extras-14
 **********************************************************************/

#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
using namespace std;

struct AVL_NODE
{
	int data;
	struct AVL_NODE *left;
	struct AVL_NODE *right;
}*root;

class avlTree
{
public:
	int height(AVL_NODE *);
	int diff(AVL_NODE *);
	AVL_NODE *rr_rotation(AVL_NODE *);
	AVL_NODE *ll_rotation(AVL_NODE *);
	AVL_NODE *lr_rotation(AVL_NODE *);
	AVL_NODE *rl_rotation(AVL_NODE *);
	AVL_NODE* balance(AVL_NODE *);
	AVL_NODE* insert(AVL_NODE *, int);
	void display(AVL_NODE *, int);
	avlTree()
	{
		root = NULL;
	}
};

int main()
{
	int item, n;
	avlTree avl;
	cout << "How many numbers do you want to print: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Insert Element into the tree: ";
		cin >> item;
		root = avl.insert(root, item);
		if (root == NULL)
		{
			cout << "Tree is Empty" << endl;
			continue;
		}
		avl.display(root, 1);
		cout << "\n";
	}
	
	system("pause");
	return 0;
}

int avlTree::height(AVL_NODE *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

int avlTree::diff(AVL_NODE *temp)
{
	int l_height = height(temp->left);
	int r_height = height(temp->right);
	int b_factor = l_height - r_height;
	return b_factor;
}

AVL_NODE *avlTree::rr_rotation(AVL_NODE *parent)
{
	AVL_NODE *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

AVL_NODE *avlTree::ll_rotation(AVL_NODE *parent)
{
	AVL_NODE *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

AVL_NODE *avlTree::lr_rotation(AVL_NODE *parent)
{
	AVL_NODE *temp;
	temp = parent->left;
	parent->left = rr_rotation(temp);
	return ll_rotation(parent);
}

AVL_NODE *avlTree::rl_rotation(AVL_NODE *parent)
{
	AVL_NODE *temp;
	temp = parent->right;
	parent->right = ll_rotation(temp);
	return rr_rotation(parent);
}

AVL_NODE *avlTree::balance(AVL_NODE *temp)
{
	int bal_factor = diff(temp);
	if (bal_factor > 1)
	{
		if (diff(temp->left) > 0)
			temp = ll_rotation(temp);
		else
			temp = lr_rotation(temp);
	}
	else if (bal_factor < -1)
	{
		if (diff(temp->right) > 0)
			temp = rl_rotation(temp);
		else
			temp = rr_rotation(temp);
	}
	return temp;
}

AVL_NODE *avlTree::insert(AVL_NODE *root, int value)
{
	if (root == NULL)
	{
		root = new AVL_NODE;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (value < root->data)
	{
		root->left = insert(root->left, value);
		root = balance(root);
	}
	else if (value >= root->data)
	{
		root->right = insert(root->right, value);
		root = balance(root);
	}
	return root;
}

void avlTree::display(AVL_NODE *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		printf("\n");
		if (ptr == root)
			cout << "Root -> ";
		for (i = 0; i < level && ptr != root; i++)
			cout << "        ";
		cout << ptr->data;
		display(ptr->left, level + 1);
	}
}
