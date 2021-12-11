#pragma once
class Integration
{

private:

	Integration() {}

public:

	static double leftRectangleIntegral(double (*function)(double ), double a, double b, double n);

	static double middleRectangleIntegral(double (*function)(double), double a, double b, double n);

	static double rightRectangleIntegral(double (*function)(double), double a, double b, double n);

	static double trapezoidalIntegral(double (*function)(double), double a, double b, int n);

	static double simpsonIntegral(double (*function)(double), double a, double b, int n);

};

