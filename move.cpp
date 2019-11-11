#include "SosudWh.h"
#include "constants.h"


void Sosud_wh::move()
{
	for (int i = 0; i < N; i++)
	{
		Coordinates a(molekyls[i].get_coordinates().x1 + constants::dt*molekyls[i].get_speedXY().x1, molekyls[i].get_coordinates().x2 + constants::dt*molekyls[i].get_speedXY().x2);
		molekyls[i].give_coordinates(a);
	}
}