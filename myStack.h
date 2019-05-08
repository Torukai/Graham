#pragma once

#include <cassert> // ��� assert
#include <iostream>
#include <iomanip> // ��� setw

#define SIZE 10

template <class T>
class myStack
{
private:
	T *stackPtr;                      // ��������� �� ����
	//int size = 10;                   // ������������ ���������� ��������� � �����
	//T top;                          // ����� �������� �������� �����
	int top;
	int capacity;


	//myStack(int size);                  // �� ��������� ������ ����� ����� 10 ���������
										//Stack(const Stack<T> &);          // ����������� �����������
	~myStack();                         // ����������
public:

	myStack(int size = SIZE);

    void push(T);     // ��������� ������� � ������� �����
    T pop();
	int size();// ������� ������� �� ������� ����� � ������� ���
    void printStack();         // ����� ����� �� �����
	//inline const T &Peek(int) const; // n-� ������� �� ������� �����
	//inline int getStackSize() const;  // �������� ������ �����
	//inline T *getPtr() const;         // �������� ��������� �� ����
	//inline int getTop() const;        // �������� ����� �������� �������� � �����
};

