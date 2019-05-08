#pragma once
class binary_heap
{
private:
	//структура описывающая узел
	struct Node {
		int data;
		Node *left;
		Node *right;
		int count;
	};
	Node *root;
	Node *addNode(Node *root, int data);
	Node *delNode(Node *root, int data);
	int searchNode(Node *root, int data);
	int heightTree(Node *root);
	int countTree(Node *root);
	void printTree(Node *root);
	void clearTree(Node *root);

public:
	binary_heap() : root{ nullptr } {};
	~binary_heap();

	//пользовательские методы
	void add(int data);
	void del(int data);
	int search(int data);
	int height();
	int count();
	void print();
	void clear();
};

