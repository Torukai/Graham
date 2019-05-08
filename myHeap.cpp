#include "myHeap.h"
#include <iostream>

using namespace std;

myHeap::myHeap()
{
	h = new point[SIZE];   //создаём массив типа данных Point размером SIZE
	heapSize = 0;
	//point myPoint;
}

void myHeap::addElem(int _x, int _y, double _angle) {
	int i, parent;
	i = heapSize;
	h[i].x = _x;
	h[i].y = _y;
	h[i].angle = _angle;
	parent = (i - 1) / 2;
	while (parent >= 0 && i > 0) {
		if (h[i].angle > h[parent].angle) {
			point temp = h[i];
			h[i]= h[parent];
			h[parent] = temp;
		}
		i = parent;
		parent = (i - 1) / 2;
	}
	heapSize++;
}

void myHeap::outHeap(void) {
	int i = 0;
	int k = 1;
	while (i < heapSize) {
		while ((i < k) && (i < heapSize)) {
			cout << h[i].angle << " ";
			i++;
		}
		cout << endl;
		k = k * 2 + 1;
	}
}

void myHeap::out(void) {
	for (int i = 0; i < heapSize; i++) {
		cout << h[i].angle << " ";
	}
	cout << endl;
}




void myHeap::heapify(int i) {
	int left, right, temp;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < heapSize) {
		if (h[i].angle < h[left].angle) {
			point temp = h[i];
			h[i] = h[left];
			h[left] = temp;
			heapify(left);
		}
	}
	if (right < heapSize) {
		if (h[i].angle < h[right].angle) {
			point temp = h[i];
			h[i] = h[right];
			h[right] = temp;
			heapify(right);
		}
	}
}

int myHeap::getMax(void) {
	int x;
	x = h[0].angle;
	h[0] = h[heapSize - 1];
	heapSize --;
	heapify(0);
	return (x);
}

int myHeap::getX(int i) {
	int current;
	current = h[i].x;
	//cout << "x= " << current << endl;
	return (current);
}

myHeap::~myHeap()
{
}
