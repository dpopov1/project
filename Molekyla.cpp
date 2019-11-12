#include "molekyla.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "coordinates.h"

Coordinates Molekyla::get_coordinates() const {
	return coordinates;
}

Coordinates Molekyla::get_speedXY() const {
	return speedXY;
}

double Molekyla::get_R() const {
	return R;
}

void Molekyla::give_speedRFI(const Coordinates a)
{
	Coordinates i(a.x1*cos(a.x2), a.x1*sin(a.x2));
	speedXY = i;
}

void Molekyla::give_coordinates(const Coordinates a)
{
	coordinates = a;
}

Coordinates give_coor(Coordinates a)
{
	Coordinates i(a.x1*cos(a.x2), a.x1*sin(a.x2));
	return i;
}
void Molekyla::give_speedXY(const Coordinates a)
{
	speedXY = a;
}

Molekyla:: Molekyla(Coordinates coordinates, Coordinates speedRFI, const double R, const double m) :coordinates(coordinates), speedXY(give_coor(speedRFI)), R(R), m(m), force(0,0) {};