#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <random>
#include "binary_heap.h"
#include "myHeap.h"
#include <math.h>
//#include "myStack.h"
#include <SFML\Graphics.hpp>
#include "Stack.h"

using namespace std;

struct point {
	int x, y;
	double angle = 0;
};


double getAngle(point a, point b, point c) {
	double x1 = a.x - b.x, x2 = c.x - b.x;

	double y1 = a.y - b.y, y2 = c.y - b.y;

	double d1 = sqrt(x1 * x1 + y1 * y1);

	double d2 = sqrt(x2 * x2 + y2 * y2);

	return acos((x1 * x2 + y1 * y2) / (d1 * d2));
}

//вычисление угла между тремя точками (исправить, неправильный знак при вычислении
double getAngle2(point a, point b, point c) {

	double abx = b.x - a.x;
	double aby = b.y - a.y;

	double cbx = b.x - c.x;
	double cby = b.y - c.y;

	double dot = (abx * cbx + aby * cby); // dot product
	double cross = (abx * cby - aby * cbx); // cross product

	double alpha = atan2(cross, dot);

	return (int)floor(alpha * 180. / M_PI + 0.5);
}

bool Check(point minPoint, point Top, point NextToTop) {
	int u_x = Top.x - minPoint.x;
	int u_y = Top.y - minPoint.y;
	int v_x = NextToTop.x - Top.x;
	int v_y = NextToTop.y - Top.y;
	int check = u_x*v_y - u_y*v_x;
	return check >= 0;
}


int main() {
	//Часть 1. Первоначальная обработка множества точек. Поиск самой левой точки.
	//создаём массив рандомных точек и ищем точку с самым наименьшим значением X

	vector<point> points(15);
	point dot;
	int size = 7;
	for (int i = 0; i < size; ++i) {
		
		dot.x = rand() % 32 + 1;
		dot.y = rand() % 30 + 1;
		points[i] = dot;
		
		cout << points[i].x << ' ' << points[i].y << endl;
	}
	//ищем самую левую точку в векторе точек
	int minX = points[0].x;
	int minY = 0;
	int minIndex = 0;
	point minPoint;

	for (int i = 0; i < size; ++i) {
		if (minX > points[i].x) {
			minX = points[i].x;
			minIndex = i;
			minY = points[i].y;
			minPoint = points[i];
		}
	}

	cout << "minimal ELEMENT " << minIndex << " value: " << minX << endl; //индекс минимального элемента и значение
	
	
	point controlPoint;
	controlPoint.x = minX+2;
	controlPoint.y = minY;

	//удаляем из массива самую левую точку
	for (int i = minIndex; i < size; i++) {
		points[i] = points[i+1];
	}
	--size;


	//Устанавливаем значение angle для каждой точки массива.
	for (int i = 0; i < size; i++) {
		points[i].angle = getAngle2(points[i], minPoint, controlPoint);
	}


	//Часть 2. Сканирование массива точек, заполнение кучи
	myHeap heap;									//создаём объект бинарной кучи
	int k;
	
	//todo: реализовать заполнение x и y из файла
	for (int i = 0; i < size; i++) {
		heap.addElem(points[i].x, points[i].y, points[i].angle);
	}

	//cout << "current= " << heap.getX(5) << endl;
	heap.outHeap();
	cout << endl;
	heap.out();
	/*cout << endl << "max elem : " << heap.getMax();
	cout << endl << "new heap : " << endl;
	heap.outHeap();
	cout << endl;
	heap.out();
	cout << endl << "max elem : " << heap.getMax();
	cout << endl << "new heap : " << endl;
	heap.outHeap();
	cout << endl;
	heap.out();*/
	

	//Заполнение стека
	//	auto test = myStak.peek();	
	stack<point> myStak;

	//заносим первую точку в стек
	myStak.push(minPoint);
	point test = myStak.Top();
	//заносим в стек вторую и третью точки из приоритетной очереди
	myStak.push(points[0]);
	test = myStak.Top();
	test = myStak.NextToTop();
	myStak.push(points[1]);
	test = myStak.Top();
	test = myStak.NextToTop();
	//переменные для определения левого поворота
	

	//Если check >= 0 то точка minPoint, points[i] и points[i+1] образуют левый поворот
	
	
	//проходим по всем точкам приоритетной очереди и заполняем ими стек
	for (int i = 2; i < size; size++) {
		//пока 3 последние точки образуют левый поворот, мы добавляем в стек элемент с наибольшим приоритетом 
		//и делаем проверку на левый поворот заного
		while (Check(minPoint, myStak.Top(), myStak.NextToTop())) {
			
			myStak.push(points[i]);
			return 0;
		}
		myStak.pop();
	}

	heap.popHeap();
	




	//Рисование
	//sf::RenderWindow window(sf::VideoMode(800, 600), "My window");


	cout << "count "<< endl;

	system("pause");
	return 0;
}
