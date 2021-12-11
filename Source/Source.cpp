#include <cmath>
#include <iostream>
#include <fstream>

#include "Integration.h"

void fillParametres(double& a, double& b, double& eps) {
	std::cout << "Введите левую границу интегрирования a = ";
	std::cin >> a;
	std::cout << "\nВведите правую границу интегрирования b = ";
	std::cin >> b;
	std::cout << "\nВведите требуемую точность eps = ";
	std::cin >> eps;
}

double myFunction(double x) {
	return (sqrt(0.4 * x + 1.7)) / (1.5 + sqrt(pow(x, 2) + 1.3));
}

int main() {

	setlocale(LC_ALL, "Russian");

	//Создаем и инициализируем указатель на функцию
	double (*ptrMyFunction)(double) = NULL;
	ptrMyFunction = &myFunction;

	//Метод левых прямоугольников

	double a, b, eps;
	double s1, s;
	int n = 1; //начальное число шагов

	fillParametres(a, b, eps);

	std::ofstream foutRk("leftRectangleRk.txt");
	std::ofstream foutnk("leftRectangleNk.txt");
	std::ofstream foutvk("leftRectangleVk.txt");

	double Rk = 0;
	double Vk = 0;
	double Nk = 0;

	s1 = Integration::leftRectangleIntegral(ptrMyFunction ,a, b, n); //первое приближение для интеграла
	do {
		s = s1;     //второе приближение
		n = 2 * n;  //увеличение числа шагов в два раза, 
					//т.е. уменьшение значения шага в два раза

		//Расчеты для построения зависимости
		Vk = log(Rk - (s1 - Integration::leftRectangleIntegral(ptrMyFunction, a, b, n)));
		Rk = s1 - Integration::leftRectangleIntegral(ptrMyFunction, a, b, n);
		Nk++;

		s1 = Integration::leftRectangleIntegral(ptrMyFunction, a, b, n); // Значение на текущем шаге

		foutRk << Rk << "\n";
		foutvk << Vk << "\n";
		foutnk << Nk << "\n";

	} while (fabs(s1 - s) > eps);  //сравнение приближений с заданной точностью
	std::cout << "\n\t Метод левых прямоугольников = " << s1 << std::endl;
	std::cout << "\t Кол-во разбиений = " << Nk << std::endl;

	foutRk.close();
	foutvk.close();
	foutnk.close();


	//Метод правых прямоугольников

	Rk = 0;
	Vk = 0;
	Nk = 0;

	foutRk.open("rightRectangleRk.txt");
	foutnk.open("rightRectangleNk.txt");
	foutvk.open("rightRectangleVk.txt");

	fillParametres(a, b, eps);

	n = 1;
	s1 = Integration::rightRectangleIntegral(ptrMyFunction, a, b, n); //первое приближение для интеграла
	do {
		s = s1;     //второе приближение
		n = 2 * n;  //увеличение числа шагов в два раза, 
					//т.е. уменьшение значения шага в два раза

		Vk = log(Rk - (s1 - Integration::rightRectangleIntegral(ptrMyFunction, a, b, n)));
		Rk = s1 - Integration::rightRectangleIntegral(ptrMyFunction, a, b, n);
		Nk++;

		s1 = Integration::rightRectangleIntegral(ptrMyFunction, a, b, n);

		foutRk << Rk << "\n";
		foutvk << Vk << "\n";
		foutnk << Nk << "\n";

	} while (fabs(s1 - s) > eps);  //сравнение приближений с заданной точностью
	std::cout << "\n\t Метод правых прямоугольников = " << s1 << std::endl;
	std::cout << "\t Кол-во разбиений = " << Nk << std::endl;

	foutRk.close();
	foutvk.close();
	foutnk.close();


	//Метод центральных прямоугольников

	Rk = 0;
	Vk = 0;
	Nk = 0;

	fillParametres(a, b, eps);

	foutRk.open("middleRectangleRk.txt");
	foutnk.open("middleRectangleNk.txt");
	foutvk.open("middleRectangleVk.txt");

	n = 1;
	s1 = Integration::middleRectangleIntegral(ptrMyFunction, a, b, n); //первое приближение для интеграла
	do {
		s = s1;     //второе приближение
		n = 2 * n;  //увеличение числа шагов в два раза, 
					//т.е. уменьшение значения шага в два раза

		Vk = log(Rk - (s1 - Integration::middleRectangleIntegral(ptrMyFunction, a, b, n)));
		Rk = s1 - Integration::middleRectangleIntegral(ptrMyFunction, a, b, n);
		Nk++;

		s1 = Integration::middleRectangleIntegral(ptrMyFunction, a, b, n);

		foutRk << Rk << "\n";
		foutvk << Vk << "\n";
		foutnk << Nk << "\n";

	} while (fabs(s1 - s) > eps);  //сравнение приближений с заданной точностью
	std::cout << "\n\t Метод центральных прямоугольников = " << s1 << std::endl;
	std::cout << "\t Кол-во разбиений = " << Nk << std::endl;

	foutRk.close();
	foutvk.close();
	foutnk.close();


	//Метод трапеций

	Rk = 0;
	Vk = 0;
	Nk = 0;
	
	fillParametres(a, b, eps);

	foutRk.open("trapezoidalRk.txt");
	foutnk.open("trapezoidalNk.txt");
	foutvk.open("trapezoidalVk.txt");

	n = 1;
	s1 = Integration::trapezoidalIntegral(ptrMyFunction, a, b, n); //первое приближение для интеграла
	do {
		s = s1;     //второе приближение
		n = 2 * n;  //увеличение числа шагов в два раза, 
					//т.е. уменьшение значения шага в два раза

		Vk = log(Rk - (s1 - Integration::trapezoidalIntegral(ptrMyFunction, a, b, n))) / log(2);
		Rk = s1 - Integration::trapezoidalIntegral(ptrMyFunction, a, b, n);
		Nk++;

		s1 = Integration::trapezoidalIntegral(ptrMyFunction, a, b, n);

		foutRk << Rk << "\n";
		foutvk << Vk << "\n";
		foutnk << Nk << "\n";

	} while (fabs(s1 - s) > eps);  //сравнение приближений с заданной точностью
	std::cout << "\n\t Метод трапеций = " << s1 << std::endl;
	std::cout << "\t Кол-во разбиений = " << Nk << std::endl;

	foutRk.close();
	foutvk.close();
	foutnk.close();


	//Метод парабол

	Rk = 0;
	Vk = 0;
	Nk = 0;
	
	fillParametres(a, b, eps);

	foutRk.open("simpsonRk.txt");
	foutnk.open("simpsonNk.txt");
	foutvk.open("simpsonVk.txt");

	n = 1;
	s1 = Integration::simpsonIntegral(ptrMyFunction, a, b, n); //первое приближение для интеграла
	do {
		s = s1;     //второе приближение
		n = 2 * n;  //увеличение числа шагов в два раза, 
					//т.е. уменьшение значения шага в два раза
		Vk = log(Rk - (s1 - Integration::simpsonIntegral(ptrMyFunction, a, b, n))) / log(4);
		Rk = s1 - Integration::simpsonIntegral(ptrMyFunction, a, b, n);
		Nk++;

		s1 = Integration::simpsonIntegral(ptrMyFunction, a, b, n);

		foutRk << Rk << "\n";
		foutvk << Vk << "\n";
		foutnk << Nk << "\n";

	} while (fabs(s1 - s) > eps);  //сравнение приближений с заданной точностью
	std::cout << "\n\t Метод парабол = " << s1 << std::endl;
	std::cout << "\t Кол-во разбиений = " << Nk << std::endl;

	foutRk.close();
	foutvk.close();
	foutnk.close();

	return 1;

}