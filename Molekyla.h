#pragma once
#include "coordinates.h"
#include <math.h>

//Coordinates give_coor(Coordinates a);

class Molekyla {
private:
	Coordinates coordinates;
	Coordinates speedXY;
	double R;
	double m;
	Coordinates force;
public:
	Coordinates get_coordinates() const;
	Coordinates get_speedXY() const;
	//Coordinates get_speedRFI() const;
	double get_R()const;
	void give_speedRFI(const Coordinates);
	void give_coordinates(const Coordinates);
	void give_speedXY(const Coordinates a);
	void give_forceXY(const Coordinates a) {Coordinates i(a.x1, a.x2);	force = i;}
	Coordinates get_force() { return force; }
	Molekyla(Coordinates coordinates, Coordinates speedRFI, const double R, const double m);
};