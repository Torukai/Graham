#pragma once
class myHeap
{
private:
	static const int SIZE = 100;
	struct point {
		int x, y;
		double angle;
	};
	point *h;
	int heapSize;

public:

	

	myHeap();
	void addElem(int x, int y, double angle);
	void outHeap();
	void out();
	int getMax();
	void heapify(int smth);
	int getX(int i);

	point popHeap() {
		point temp = h[0];
		h[0] = h[heapSize - 1];
		heapSize--;
		heapify(0);
		return temp;
	}
	myHeap fill_heap(myHeap heap) {
		
		
		return heap;
	}
	~myHeap();
};

