#include "Integration.h"

double Integration::leftRectangleIntegral(double(*function)(double), double a, double b, double n)
{

	double x, h;
	double sum = 0.0;
	double fx;
	h = (b - a) / n;

	for (int i = 0; i < n; i++) {
		x = a + i * h;
		fx = (*function)(x);
		sum += fx;
	}

	return (sum * h);

}

double Integration::middleRectangleIntegral(double(*function)(double), double a, double b, double n)
{

	double x, h;
	double sum = 0.0;
	double fx;
	h = (b - a) / n;

	for (int i = 0; i < n; i++) {
		x = a + i * h;
		fx = (*function)(x + h / 2);
		sum += fx;
	}

	return (sum * h);

}

double Integration::rightRectangleIntegral(double(*function)(double), double a, double b, double n)
{

	double x, h;
	double sum = 0.0;
	double fx;
	h = (b - a) / n;

	for (int i = 0; i < n; i++) {
		x = a + i * h;
		fx = (*function)(x + h);
		sum += fx;
	}

	return (sum * h);

}

double Integration::trapezoidalIntegral(double(*function)(double), double a, double b, int n)
{

	double width = (b - a) / n;

	double trapezoidal_integral = 0;

	for (int step = 0; step < n; step++) {
		const double x1 = a + step * width;
		const double x2 = a + (step + 1) * width;

		trapezoidal_integral += 0.5 * (x2 - x1) * ((*function)(x1) + (*function)(x2));
	}

	return trapezoidal_integral;

}

double Integration::simpsonIntegral(double(*function)(double), double a, double b, int n)
{

	const double width = (b - a) / n;

	double simpson_integral = 0;
	for (int step = 0; step < n; step++) {
		const double x1 = a + step * width;
		const double x2 = a + (step + 1) * width;

		simpson_integral += (x2 - x1) / 6.0 * ((*function)(x1) + 4.0 * (*function)(0.5 * (x1 + x2)) + (*function)(x2));
	}

	return simpson_integral;

}