#include "SosudWh.h"
#include "constants.h"

void Sosud_wh::move()
{
	for (int i = 0; i < N; i++)
	{
		Coordinates a1(constants::dt*molekyls[i].get_force().x1, constants::dt*molekyls[i].get_force().x2);
		a1.x1 = a1.x1 + molekyls[i].get_speedXY().x1;
		a1.x2 = a1.x2 + molekyls[i].get_speedXY().x2;
		molekyls[i].give_speedXY(a1);
		Coordinates a(molekyls[i].get_coordinates().x1 + constants::dt*molekyls[i].get_speedXY().x1, molekyls[i].get_coordinates().x2 + constants::dt*molekyls[i].get_speedXY().x2);
		molekyls[i].give_coordinates(a);
		Coordinates ooo(0, 0);
		molekyls[i].give_forceXY(ooo);
	}
}