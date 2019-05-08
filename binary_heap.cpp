#include "binary_heap.h"



//binary_heap::binary_heap()
//{
//}

void binary_heap::add(int data) {
	root = addNode(root, data);
}



binary_heap::Node * binary_heap::addNode(Node *root, int data) {
	if (root == nullptr) {
		root = new Node;
		root->data = data;
		root->count = 1;
		root->left = nullptr;
		root->right = nullptr;
	}
	else if (root->data > data) {
		root->left = addNode(root->left, data);
	}
	else if (root->data < data) {
		root->right = addNode(root->right, data);
	}
	else
		root->count++;

	return root;
}

int binary_heap::searchNode(Node *root, int data) {
	if (root == nullptr) {
		return 0;
	}
	else if (root->data > data) {
		return searchNode(root->left, data);
	}
	else if (root->data > data) {
		return searchNode(root->right, data);
	}
	else
		return root->count;
}

int binary_heap::countTree(Node *root) {
	if (root == nullptr) {
		return 0;
	}
	else {
		return countTree(root->left) + countTree(root->right) + 1;
	}
}

binary_heap::~binary_heap()
{
}
