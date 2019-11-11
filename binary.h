#pragma once
#include "coordinates.h"

Coordinates operator-(Coordinates a, Coordinates b)
{
	Coordinates c(a.x1 - b.x1, a.x2 - b.x2);
	return c;
}

double operator*(Coordinates a, Coordinates b)
{
	return a.x1*b.x1 + a.x2* b.x2;
}

Coordinates operator+(Coordinates a, Coordinates b)
{
	Coordinates c(a.x1 + b.x1, a.x2 + b.x2);
	return c;
}
