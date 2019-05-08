#pragma once

#include <cassert> // для assert
#include <iostream>
#include <iomanip> // для setw

#define SIZE 10

template <class T>
class myStack
{
private:
	T *stackPtr;                      // указатель на стек
	//int size = 10;                   // максимальное количество элементов в стеке
	//T top;                          // номер текущего элемента стека
	int top;
	int capacity;


	//myStack(int size);                  // по умолчанию размер стека равен 10 элементам
										//Stack(const Stack<T> &);          // конструктор копирования
	~myStack();                         // деструктор
public:

	myStack(int size = SIZE);

    void push(T);     // поместить элемент в вершину стека
    T pop();
	int size();// удалить элемент из вершины стека и вернуть его
    void printStack();         // вывод стека на экран
	//inline const T &Peek(int) const; // n-й элемент от вершины стека
	//inline int getStackSize() const;  // получить размер стека
	//inline T *getPtr() const;         // получить указатель на стек
	//inline int getTop() const;        // получить номер текущего элемента в стеке
};

