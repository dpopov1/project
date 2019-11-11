#pragma once
#include "molekyla.h"
#include <vector>

class Sosud_wh {
private:
	double const w, h;// начало координат находится в левом нижнем углу сосуда
	double T;
	const double R, m;
	std::vector<Molekyla> molekyls;
	int N;
	//long double t_do_stolknovenia() const;
public:
	~Sosud_wh() { molekyls.clear(); }
	Sosud_wh(const double w, const double h, const int N, const double T, const double R, const double m);
	void stolknovenie();
	void move();
	std::vector<Molekyla>& get_mass();
};