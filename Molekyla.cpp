#include "molekyla.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "coordinates.h"

Coordinates Molekyla::get_coordinates() const {
	return coordinates;
}

Coordinates Molekyla::get_speedXY() const {
	Coordinates a(speedRFI.x1*cos(speedRFI.x2), speedRFI.x1*sin(speedRFI.x2));
	return a;
}

Coordinates Molekyla::get_speedRFI() const {
	return speedRFI;
}

double Molekyla::get_R() const {
	return R;
}

void Molekyla::give_speedRFI(const Coordinates a)
{
	speedRFI = a;
}

void Molekyla::give_coordinates(const Coordinates a)
{
	coordinates = a;
}

void Molekyla::give_speedXY(const Coordinates a)
{
	double k = atan(a.x2 / a.x1);
	double fi;
	if (a.x1 > 0 && a.x2 >= 0)
		fi = k;
	if (a.x1 > 0 && a.x2 <= 0)
		fi = k + 2 * M_PI;
	if (a.x1 < 0 && a.x2 <= 0)
		fi = k + M_PI;
	if (a.x1 < 0 && a.x2 >= 0)
		fi = k + M_PI;
	double v = sqrt(a.x1*a.x1 + a.x2*a.x2);
	Coordinates o(v, fi);
	speedRFI = o;
}