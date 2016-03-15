#include "Vector2.h"
#include "Matrix3.h"
#include <iostream>

int main()
{
	COR::Vec2 a = { 2, 2 };
	COR::Mat3 b = { 2, 3, 4, 5, 6, 7, 8, 9, 1 };

	std::cout << b << std::endl;


	system("pause");
}