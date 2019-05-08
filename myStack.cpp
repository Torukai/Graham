#include "myStack.h"

// ���������� ������� ������� ������ STack

// ����������� �����
template <class T>
myStack < T >::myStack(int size)
{
	//stackPtr = new T[size]; // �������� ������ ��� ����
	//top = 0; // �������������� ������� ������� �����;
	//size = s > 0 ? s : 10;   // ���������������� ������ �����
	stackPtr = new T[size]; // �������� ������ ��� ����
	capacity = size;
	top = -1; // �������� -1 ������� � ���, ��� ���� ����
}

// ����������� �����������
//template <typename T>
//myStack<T>::myStack(const myStack<T> & otherStack) :
//	size(otherStack.getStackSize()) // ������������� ���������
//{
//	stackPtr = new T[size]; // �������� ������ ��� ����� ����
//	top = otherStack.getTop();
//
//	for (int ix = 0; ix < top; ix++)
//		stackPtr[ix] = otherStack.getPtr()[ix];
//}

// ������� ����������� �����
template <class T>
myStack<T>::~myStack()
{
	delete[] stackPtr; // ������� ����
}

// ������� ���������� �������� � ����
template <class T>
void myStack<T>::push( T value)
{
	// ��������� ������ �����
	//assert(top < size); // ����� �������� �������� ������ ���� ������ ������� �����
	
	stackPtr[top++] = value; // �������� ������� � ����
}

// ������� �������� �������� �� �����
template <class T>
T myStack<T>::pop()
{
	// ��������� ������ �����
	assert(top > 0); // ����� �������� �������� ������ ���� ������ 0

	stackPtr[--top]; // ������� ������� �� �����
}

// ������� ���������� n-� ������� �� ������� �����
//template <class T>
//inline const T &Stack<T>::Peek(int nom) const
//{
//	//
//	assert(nom <= top);
//
//	return stackPtr[top - nom]; // ������� n-� ������� �����
//}

// ����� ����� �� �����
template <class T>
void myStack<T>::printStack()
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}
//
//// ������� ������ �����
//template <typename T>
//int myStack<T>::getStackSize() const
//{
//	return size;
//}

// ������� ��������� �� ���� (��� ������������ �����������)
//template <typename T>
// T *myStack<T>::getPtr() const
//{
//	return stackPtr;
//}
//
//// ������� ������ �����
//template <typename T>
//int myStack<T>::getTop() const
//{
//	return top;
//}
//
