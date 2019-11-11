#include "SosudWh.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#define _USE_MATH_DEFINES
#include <math.h>
#include "coordinates.h"
#include "Molekyla.h"
#include "constants.h"

bool proverka(Molekyla a, std::vector<Molekyla> molekyls, double w, double h);
std::vector<Molekyla> get_molekyls(double w, double h, const int N, const double T, const double m, const double R) {
	std::vector<Molekyla> molekyls;
	srand(unsigned int(time(NULL)));
	for (int i = 0; i < N; i++)
	{
		Coordinates xy(rand()*1. / RAND_MAX * w, rand()*1. / RAND_MAX * h);
		Coordinates speed((rand()*1. / RAND_MAX+0.5)*sqrt(constants::k * 2 * T / m), rand()*1. / RAND_MAX * (2 * M_PI));
		Molekyla a(xy, speed, R, m);
		if (proverka(a, molekyls, w, h))
			molekyls.push_back(a);
		else
			i--;
	}
	return molekyls;
}

bool proverka(Molekyla a, std::vector<Molekyla> molekyls, double w, double h) {
	if (a.get_coordinates().x1 < 2 * a.get_R() || a.get_coordinates().x2 < 2 * a.get_R())
		return false;
	if (a.get_coordinates().x1 > w - 4 * a.get_R() || a.get_coordinates().x2 > h - 4 * a.get_R())
		return false;
	for (int i = 0; i < int(molekyls.size()); i++) {
		double t = molekyls[i].get_coordinates().x1 - a.get_coordinates().x1;
		double t1 = molekyls[i].get_coordinates().x2 - a.get_coordinates().x2;
		if (t*t + t1 * t1 < 4.1 * a.get_R()*a.get_R())
			return false;
	}
	return true;
}

Sosud_wh::Sosud_wh(const double w, const double h, const int N, const double T, const double R, const double m) :w(w), h(h), molekyls(get_molekyls(w, h, N, T, m, R)), N(N), T(T), R(R), m(m) {}

std::vector<Molekyla>& Sosud_wh::get_mass()
{
	return molekyls;
}