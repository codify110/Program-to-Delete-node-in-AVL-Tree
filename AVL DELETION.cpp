#include <iostream>
using namespace std;
class AVL {
private:
	struct node {

		int key;
		node *left;
		node *right;
		int height;
	}*root;
public:
	AVL() {
		root = NULL;
	}
	int max(int a, int b)
	{
		if (a > b)
			return a;
		else
			return b;
	}
	int height(node *N)
	{
		if (N == NULL)
			return 0;
		return N->height;
	}

	int getBalance(node *N)
	{
		if (N == NULL)
			return 0;
		return height(N->left) - height(N->right);
	}

	node* newnode(int key)
	{
		node* new_node = new node;
		new_node->key = key;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->height = 1;
		return(new_node);
	}
	node *rightRotate(node *b)
	{
		node *a = b->left;
		node *rotate = a->right;


		a->right = b;
		b->left = rotate;
		b->height = max(height(b->left),
			height(b->right)) + 1;
		a->height = max(height(a->left),
			height(a->right)) + 1;


		return a;
	}
	node *leftRotate(node *a)
	{
		node *b = a->right;
		node *T2 = b->left;

		b->left = a;
		a->right = T2;

		a->height = max(height(a->left),
			height(a->right)) + 1;
		b->height = max(height(b->left),
			height(b->right)) + 1;

		return b;
	}




	node* insert(node* node, int key)
	{
		if (node == NULL)
			return(newnode(key));

		if (key < node->key)
			node->left = insert(node->left, key);
		else if (key > node->key)
			node->right = insert(node->right, key);
		else
			return node;

		node->height = 1 + max(height(node->left),
			height(node->right));
		int balance = getBalance(node);

		if (balance > 1 && key < node->left->key)
			return rightRotate(node);

		if (balance < -1 && key > node->right->key)
			return leftRotate(node);

		if (balance > 1 && key > node->left->key)
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		if (balance < -1 && key < node->right->key)
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		return node;
	}

	void preOrder(node *root)
	{
		if (root != NULL)
		{
			cout << root->key << " ";
			preOrder(root->left);
			preOrder(root->right);
		}

	}
	void inOrder(node *root)
	{
		if (root != NULL)
		{
			inOrder(root->left);
			cout << root->key << " ";
			inOrder(root->right);
		}

	}
	void postOrder(node *root)
	{
		if (root != NULL)
		{
			postOrder(root->left);
			postOrder(root->right);
			cout << root->key << " ";
		}

	}

	void insert_node() {
		int key;
		cout << "Enter Key to Insert: ";
		cin >> key;
		root = insert(root, key);
	}
	void display()
	{
		int y;
		cout << "In which order you want to print " << endl;
		cout << "1) Pre order" << endl;
		cout << "2) Post order" << endl;
		cout << "3) In order" << endl;
		cin >> y;
		if (y == 1)
		{
			preOrder(root);
		}
		if (y == 2)
		{
			postOrder(root);
		}
		if (y == 3)
		{
			inOrder(root);
		}
		cout << endl;
	}
	node * minValuenode(node* N)
	{
		node* current = N;
		while (current->left != NULL)
			current = current->left;

		return current;
	}
	node* deletenode(node* root, int key)
	{
		if (root == NULL)
			return root;
		if (key < root->key)
			root->left = deletenode(root->left, key);
		else if (key > root->key)
			root->right = deletenode(root->right, key);
		else
		{

			if ((root->left == NULL) ||
				(root->right == NULL))
			{
				node *temp = root->left ?
					root->left :
					root->right;
				if (temp == NULL)
				{
					temp = root;
					root = NULL;
				}
				else
					*root = *temp;
				free(temp);
			}
			else
			{
				node* temp = minValuenode(root->right);
				root->key = temp->key;
				root->right = deletenode(root->right,
					temp->key);
			}
		}

		if (root == NULL)
			return root;
		root->height = 1 + max(height(root->left),
			height(root->right));
		int balance = getBalance(root);
		if (balance > 1 &&
			getBalance(root->left) >= 0)
			return rightRotate(root);
		if (balance > 1 &&
			getBalance(root->left) < 0)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		if (balance < -1 &&
			getBalance(root->right) <= 0)
			return leftRotate(root);
		if (balance < -1 &&
			getBalance(root->right) > 0)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}


	void delete_node()
	{
		int key;
		cout << "Enter Key to Delete: ";
		cin >> key;
		root = deletenode(root, key);
	}
	};
	int main()
	{
		AVL tree;
		AVL *Root = NULL;
		int x, y;
		cout << "How many node you want to make:" << endl;
		cin >> x;
		for (int i = 0; i < x; i++)
		{
			tree.insert_node();
		}
		tree.delete_node();
		tree.display();
		system("pause");
	}

