#include "SosudWh.h"
#include "constants.h"
#include "binary.h"
#define _USE_MATH_DEFINES
#include <math.h>
#define koef 1

double squre_abs(Coordinates a) {
	return a * a;
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
}

void stolk_stenky(int &i, Molekyla &a, double w, double h){
	if (a.get_coordinates().x1 + a.get_speedXY().x1*constants::dt / koef > w-a.get_R())//там чего-то всё трудно
	{
		Coordinates o(a.get_speedRFI().x1, M_PI-a.get_speedRFI().x2);
		a.give_speedRFI(o);
	}
	if (a.get_coordinates().x1 + a.get_speedXY().x1*constants::dt / koef < a.get_R())
	{
		Coordinates o(a.get_speedRFI().x1, -a.get_speedRFI().x2 + M_PI);
		a.give_speedRFI(o);
	}
	if (a.get_coordinates().x2 + a.get_speedXY().x2*constants::dt/koef > h-a.get_R()) {
		Coordinates o(a.get_speedRFI().x1, -a.get_speedRFI().x2);
		a.give_speedRFI(o);
	}
	if (a.get_coordinates().x2 + a.get_speedXY().x2*constants::dt/koef < a.get_R()) {
		Coordinates o(a.get_speedRFI().x1, -a.get_speedRFI().x2);
		a.give_speedRFI(o);
	}
}

void Sosud_wh::stolknovenie(){
	double r = 1.01*4*R*R;
	for (int i = 0; i < N; i++) {
		stolk_stenky(i, molekyls[i], w, h);
		for (int j = i + 1; j < N; j++)
		{
			Coordinates v = (molekyls[i].get_speedXY() - molekyls[j].get_speedXY());
			Coordinates l = (molekyls[j].get_coordinates() - molekyls[i].get_coordinates());
			double v2 = squre_abs(v);
			double l2 = squre_abs(l);
			double cos2 = (v*l)*(v*l) / v2 / l2;
			if (l2<r&&v*l>0){//v*l>0 && 1-r/l2<cos2) {//если тип столкнется (когда-нибудь)
				//if ((l2-r)/v2 < constants::dt*constants::dt) {
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