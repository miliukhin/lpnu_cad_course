#include<iostream>
#include <vector>
using namespace std;

struct Node
{
	int key;
	unsigned char height;
	Node* left;
	Node* right;
	Node(int k) { key = k; left = right = NULL; height = 1; }
};

unsigned char height(Node* p) // обгортка для поля height
{
	return p?p->height:0;
}

int b_factor(Node* p) // працює тільки з ненульовими вказівниками
{
	return height(p->right)-height(p->left);
}

void fix_height(Node* p) //фіксить висоту, якщо вона правильна в дочірніх вузлах
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl>hr?hl:hr)+1;
}

Node* rotate_right(Node* p) // правий поворот навколо p
{
	Node* q = p->left;
	p->left = q->right;
	q->right = p;
	fix_height(p);
	fix_height(q);
	return q;
}

Node* rotate_left(Node* q) // лівий поворот навколо q
{
	Node* p = q->right;
	q->right = p->left;
	p->left = q;
	fix_height(q);
	fix_height(p);
	return p;
}

Node* balance(Node* p)
{
	fix_height(p);
	if( b_factor(p) == 2 )
	{
		if( b_factor(p->right) < 0 )
			p->right = rotate_right(p->right);
		return rotate_left(p);
	}
	if( b_factor(p) == -2 )
	{
		if( b_factor(p->left) > 0  )
			p->left = rotate_left(p->left);
		return rotate_right(p);
	}
	return p; // балансувати не треба
}

Node* insert(Node* p, int k) // p корінь цього дерева
{
	if( !p )
		return new Node(k);
	if( k < p->key )
		p->left = insert(p->left, k);
	else if ( k > p->key )
		p->right = insert(p->right, k);
	else
		return balance(p);
	return balance(p);
}

void print_tree(Node* Node, int level = 0)
{
	if (Node == NULL)
		return;

	print_tree(Node->right, level + 1);

	for (int i = 0; i < level; i++)
	{
		std::cout << "...";
	}
	std::cout << Node->key << std::endl;
	print_tree(Node->left, level + 1);
}

Node* find_min(Node* p)
{
	return p->left?find_min(p->left):p;
}

Node* remove_min(Node* p)
{
		if( p->left==0 )
				return p->right;
		p->left = remove_min(p->left);
		return balance(p);
}

Node* remove(Node* p, int k)
{
		if( !p ) return 0; // пошук потрібного вузла
		if( k < p->key )
				p->left = remove(p->left,k);
		else if( k > p->key )
				p->right = remove(p->right,k);
		else //  k == p->key
		{
				Node* q = p->left;
				Node* r = p->right;
				delete p;
				if( !r ) return q;
				Node* min = find_min(r);
				min->right = remove_min(r);
				min->left = q;
				return balance(min);
		}
	 return balance(p);
}

Node* delete_even(Node* root)
{
	Node* current = root;

	if (root == NULL)
		return root;
	// Рекурсивно видаляємо парні елементи з лівого і правого піддерев
	root->left = delete_even(root->left);
	root->right = delete_even(root->right);
	// Якщо поточний вузол має парний ключ, видаляємо його
	if (root->key % 2 == 0)
		root = remove(root, root->key);
	return root;
}

std::vector<int> find_even_keys (Node* root, std::vector<int> keys = {})
{
	if (root == NULL)
		return keys;

	keys = find_even_keys(root->left, keys);
	keys = find_even_keys(root->right, keys);

	if (root->key % 2 == 0)
		keys.push_back(root->key);

	return keys;
}

Node* delete_even_keys (Node* root)
{
	std::vector<int> keys = find_even_keys(root);

		for (int i = 0; i < keys.size(); i++) {
		/* std::cout << keys[i] << std::endl; */
		root = remove(root, keys[i]);
	}
	return root;
}

int main()
{
	Node* root = new Node(20);
	root = insert(root, 43);
	root = insert(root, 33);
	root = insert(root, 34);
	root = insert(root, 53);
	root = insert(root, 94);
	root = insert(root, 93);
	root = insert(root, 91);
	root = insert(root, 99);
	root = insert(root, 94);
	root = insert(root, 94);
	root = insert(root, 94);

	print_tree(root);
	std::cout << std::endl;

	root = delete_even_keys(root);

	print_tree(root);
}
