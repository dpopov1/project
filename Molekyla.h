#pragma once
#include "coordinates.h"

class Molekyla {
private:
	Coordinates coordinates;
	Coordinates speedRFI;
	double R;
	double m;
public:
	Coordinates get_coordinates() const;
	Coordinates get_speedXY() const;
	Coordinates get_speedRFI() const;
	double get_R()const;
	void give_speedRFI(const Coordinates);
	void give_coordinates(const Coordinates);
	void give_speedXY(const Coordinates a);
	Molekyla(Coordinates coordinates, Coordinates speedRFI, const double R, const double m) :coordinates(coordinates), speedRFI(speedRFI), R(R), m(m) {}
};