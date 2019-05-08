#include "myStack.h"

// реализация методов шаблона класса STack

// конструктор Стека
template <class T>
myStack < T >::myStack(int size)
{
	//stackPtr = new T[size]; // выделить память под стек
	//top = 0; // инициализируем текущий элемент нулем;
	//size = s > 0 ? s : 10;   // инициализировать размер стека
	stackPtr = new T[size]; // выделить память под стек
	capacity = size;
	top = -1; // значение -1 говорит о том, что стек пуст
}

// конструктор копирования
//template <typename T>
//myStack<T>::myStack(const myStack<T> & otherStack) :
//	size(otherStack.getStackSize()) // инициализация константы
//{
//	stackPtr = new T[size]; // выделить память под новый стек
//	top = otherStack.getTop();
//
//	for (int ix = 0; ix < top; ix++)
//		stackPtr[ix] = otherStack.getPtr()[ix];
//}

// функция деструктора Стека
template <class T>
myStack<T>::~myStack()
{
	delete[] stackPtr; // удаляем стек
}

// функция добавления элемента в стек
template <class T>
void myStack<T>::push( T value)
{
	// проверяем размер стека
	//assert(top < size); // номер текущего элемента должен быть меньше размера стека
	
	stackPtr[top++] = value; // помещаем элемент в стек
}

// функция удаления элемента из стека
template <class T>
T myStack<T>::pop()
{
	// проверяем размер стека
	assert(top > 0); // номер текущего элемента должен быть больше 0

	stackPtr[--top]; // удаляем элемент из стека
}

// функция возвращает n-й элемент от вершины стека
//template <class T>
//inline const T &Stack<T>::Peek(int nom) const
//{
//	//
//	assert(nom <= top);
//
//	return stackPtr[top - nom]; // вернуть n-й элемент стека
//}

// вывод стека на экран
template <class T>
void myStack<T>::printStack()
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}
//
//// вернуть размер стека
//template <typename T>
//int myStack<T>::getStackSize() const
//{
//	return size;
//}

// вернуть указатель на стек (для конструктора копирования)
//template <typename T>
// T *myStack<T>::getPtr() const
//{
//	return stackPtr;
//}
//
//// вернуть размер стека
//template <typename T>
//int myStack<T>::getTop() const
//{
//	return top;
//}
//
