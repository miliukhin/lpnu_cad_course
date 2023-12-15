#include<iostream>

struct Node
{
	char data;
	Node* left{};
	Node* right{};
};

Node* new_node(char data)
{
	Node* node = new Node;
	node->data = data;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

void print_tree(Node* node, int level = 0) {
	if (node == nullptr)
	{
		return;
	}
	print_tree(node->right, level + 1);

	for (int i = 0; i < level; i++)
	{
		std::cout << "\033[31;1;1m...\033[0m";
	}
	std::cout << node->data << std::endl;
	print_tree(node->left, level + 1);
}

Node* tree(Node* root)
{
	root = new_node('+');
	root->left = new_node('a');
	root->right = new_node('*');
	root->right->left = new_node('b');
	root->right->right = new_node('-');
	root->right->right->left = new_node('b');
	root->right->right->right = new_node('d');

	return root;
}

int main()
{
	Node* root = nullptr;
	root = tree(root);


	print_tree(root);
	root->left->left = new_node('-');
	std::cout<<'\n';
	print_tree(root);
}
