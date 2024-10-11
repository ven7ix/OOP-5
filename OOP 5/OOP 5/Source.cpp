#include <iostream>
#include <vector>
#include <string>

//dynamic_cast & friend func & class
class Point {
	friend class Circle;
	int _x;
	int _y;
public:
	Point(int x, int y) : _x(x), _y(y) {}
};

class Shape {
	virtual void PrintShape() {
		std::cout << "no Shape";
	}
};

class Circle : public Shape {
	Point _center;
	int _radius;

	friend void ChangeScale(const int scaleFactor, Circle* circle);
public:
	Circle(Point center, int radius) : _center(center), _radius(radius) {}

	void Relocate(Point moveVector) {
		_center._x += moveVector._x;
		_center._y += moveVector._y;
	}

	void PrintShape() {
		std::cout << "Center: " << _center._x << ", " << _center._y << " Radius: " << _radius << "\n";
	}
};

void ChangeScale(const int scaleFactor, Circle* circle) {
	circle->_radius *= scaleFactor;
}

//try catch
void checkPos(std::vector<std::string> list, int position) {
	if (position >= (int)list.size()) {
		throw "Index Out Of Range\n";
	}
	if (position < 0) {
		throw - 1;
	}
	return;
}

float division(float a, float b) {
	if (b == 0) {
		throw "You Cannot Divide By 0\n";
	}
	return a / b;
}

int main() {
	//dynamic_cast & friend func & class
	Shape* shapeD = new Circle(Point(0, 1), 10);

	Circle* circleD = dynamic_cast<Circle*>(shapeD);

	if (circleD == nullptr)
		std::cout << "Error" << std::endl;
	else
		circleD->PrintShape();
	circleD->Relocate(Point(1, 1));
	circleD->PrintShape();

	Circle circle = Circle(Point(0, 0), 10);
	circle.PrintShape();
	ChangeScale(10, &circle);
	circle.PrintShape();

	//try catch 1 (index)
	std::vector<std::string> list;
	int position;
	bool loop = true;
	char choice;
	while (loop) {
		std::cout << "1 - enter in list,\n2 - print on pos,\n3 - break\n";
		std::cin >> choice;
		std::string number;
		switch (choice)
		{
		case '1':
			std::cin >> number;
			list.push_back(number);
			break;
		case '2':
			std::cin >> position;
			try {
				checkPos(list, position);
				std::cout << list[position] << "\n";
			}
			catch (char* error) {
				std::cout << error;
			}
			catch (...) {
				std::cout << "Error" << std::endl;
			}
			break;
		case '3':
			loop = false;
			break;
		default:
			break;
		}
	}

	//try catch 2 (division)
	loop = true;
	float a;
	float b;
	float c;
	while (loop) {
		std::cout << "1 - enter nums,\n2 - break\n";
		std::cin >> choice;
		switch (choice) {
		case '1':
			std::cin >> a >> b;
			try {
				c = division(a, b);
				std::cout << c << "\n";
			}
			catch (char* error) {
				std::cout << error;
			}
			break;
		case '2':
			loop = false;
			break;
		}
	}
}