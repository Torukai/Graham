#pragma once
class elem
{
private:
	struct point {
		int x;
		int y;
		double angle;
	};

public:
	elem(int _x, int _y, double _angle);
	void setElement(int x, int y, double angle);
	elem getElement();
	~elem();
};

