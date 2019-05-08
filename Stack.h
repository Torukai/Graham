#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

// define default capacity of stack
#define SIZE 20

// Class for stack
template <class X>
class stack
{
	X *arr;
	int top;
	int capacity;

public:
	stack(int size = SIZE);	// constructor

	void push(X);
	X pop();
	X peek();
	X Top();
	X NextToTop();

	int size();
	bool isEmpty();
	bool isFull();
};

// Constructor to initialize stack
template <class X>
stack<X>::stack(int size)
{
	arr = new X[size];
	capacity = size;
	top = -1;
}

// function to add an element x in the stack
template <class X>
void stack<X>::push(X x)
{
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	//cout << "Inserting " << x << endl;
	arr[++top] = x;
}

template <class X>
X stack<X>::Top() {
	return arr[top];
}

template <class X>
X stack<X>::NextToTop() {
	int temp = top - 1;
	return arr[temp];
}


// function to pop top element from the stack
template <class X>
X stack<X>::pop()
{
	// check for stack underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	//cout << "Removing " << peek() << endl;

	// decrease stack size by 1 and (optionally) return the popped element
	return arr[top--];
}

// function to return top element in a stack
template <class X>
X stack<X>::peek()
{
	if (!isEmpty())
		return arr[top];
	else
		cout << "stack is empty!" << endl;
		//exit(EXIT_FAILURE);
}

// Utility function to return the size of the stack
template <class X>
int stack<X>::size()
{
	return top + 1;
}

// Utility function to check if the stack is empty or not
template <class X>
bool stack<X>::isEmpty()
{
	return top == -1;	// or return size() == 0;
}

// Utility function to check if the stack is full or not
template <class X>
bool stack<X>::isFull()
{
	return top == capacity - 1;	// or return size() == capacity;
}