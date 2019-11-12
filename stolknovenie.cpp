#include "SosudWh.h"
#include "constants.h"
#include "binary.h"
#define _USE_MATH_DEFINES
#include <math.h>
//#define koef 1

double squre_abs(Coordinates a) {
	return a * a;
}
void potery(Molekyla &a, Molekyla &b)
{
	Coordinates o(a.get_speedXY().x1*(1 - constants::poteri), a.get_speedXY().x2*(1 - constants::poteri));
	Coordinates o1(b.get_speedXY().x1*(1 - constants::poteri), b.get_speedXY().x2*(1 - constants::poteri));
	a.give_speedXY(o);
	b.give_speedXY(o1);
}
void stolk_molekyl(Molekyla &a, Molekyla &b)
{
	Coordinates p = a.get_coordinates() - b.get_coordinates();
	double k = p.x1*p.x1 + p.x2*p.x2;
	double i = (b.get_speedXY() - a.get_speedXY())*p;
	p.x1 = p.x1 / k*i;
	p.x2 = p.x2 / k*i;
	Coordinates va = a.get_speedXY() + p;
	Coordinates vb = b.get_speedXY() - p;
	p = a.get_speedXY();
	a.give_speedXY(va);
	b.give_speedXY(vb);
	potery(a, b);
}

void stolk_stenky(Molekyla &a, double w, double h){
	double u = a.get_coordinates().x1 + a.get_speedXY().x1*constants::dt + constants::dt*constants::dt*a.get_force().x1 / 2;
	double o1 = a.get_coordinates().x2 + a.get_speedXY().x2*constants::dt + constants::dt*constants::dt*a.get_force().x2 / 2;
	if (u> w-a.get_R())//там чего-то всё трудно
	{
		Coordinates o(-a.get_speedXY().x1, a.get_speedXY().x2);
		a.give_speedXY(o);
	}
	if (u < a.get_R())
	{
		Coordinates o(-a.get_speedXY().x1, a.get_speedXY().x2);
		a.give_speedXY(o);
	}
	if (o1 > h-a.get_R()) {
		Coordinates o(a.get_speedXY().x1, -a.get_speedXY().x2);
		a.give_speedXY(o);
	}
	if (o1 < a.get_R()) {
		Coordinates o(a.get_speedXY().x1, -a.get_speedXY().x2);
		a.give_speedXY(o);
	}
}

void vzaim(Molekyla& a, Molekyla& b, double l2, Coordinates l, double r) {
	if (l2 > r) {
		double p = constants::kf / sqrt(l2) / l2;
		Coordinates i(p * l.x1, p * l.x2);
		Coordinates i1(-i.x1, -i.x2);
		i1 = i1 + b.get_force();
		i = i + a.get_force();
		b.give_forceXY(i1);
		a.give_forceXY(i);
	}
}

void Sosud_wh::stolknovenie(){
	double r = 4*R*R;
	for (int i = 0; i < N; i++) {
		stolk_stenky(molekyls[i], w, h);
		for (int j = i + 1; j < N; j++)
		{
			Coordinates v = (molekyls[i].get_speedXY() - molekyls[j].get_speedXY());
			Coordinates l = (molekyls[j].get_coordinates() - molekyls[i].get_coordinates());
			//double v2 = squre_abs(v);
			double l2 = squre_abs(l);
			vzaim(molekyls[i], molekyls[j], l2, l, r);
			//double cos2 = (v*l)*(v*l) / v2 / l2;
			if (l2<r&&v*l>0){//v*l>0 && 1-r/l2<cos2) {//если тип столкнется (когда-нибудь)
				//if ((l2-r)/v2 < constants::dt*constants::dt)
					stolk_molekyl(molekyls[i], molekyls[j]);
					/*long double k = b/c;
					if (k < dt2)
						dt2 = k;*/
				//}
			}
		}
	}
	//return sqrt(dt2);
}