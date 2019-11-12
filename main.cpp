#include "SosudWh.h"
#include <vector>
#include <iostream>
#include <ctime>
#define dt 0.005
void out(const std::vector<Molekyla> &y, const int N) {
	std::cout << "[[";
	for (int i = 0; i < N - 1; i++)
		std::cout << y[i].get_coordinates().x1 << ",";
	std::cout << y[N - 1].get_coordinates().x1 << "],[";
	for(int i =0;i<N-1;i++)
		std::cout << y[i].get_coordinates().x2 << ",";
	std::cout << y[N-1].get_coordinates().x2 << "]]"<<std::endl;
}

int main() {//int main(argc, argv);
	double w = 2000;
	double h = 2000;//100;
	int N = 3000;//1000;
	double T = 600;
	double R = 10;
	int interval = 0;
	double m = 1;
	//double p=0;
	//int i = 0;
	std::cout << '[' << w << ',' << h << ','<< R <<','<<interval<< ']' << std::endl;
	Sosud_wh a(w, h, N, T, R, m);
	while (true) {
		//i++;
		a.stolknovenie();
		out(a.get_mass(), N);
		//for (int j = 0; j < N; j++)
		//	p += a.get_mass()[j].get_speedXY().x1*a.get_mass()[j].get_speedXY().x1 + a.get_mass()[j].get_speedXY().x2*a.get_mass()[j].get_speedXY().x2;
		a.move();/*
		//if (p > 7000000)
		//	p++;*/
	/*	i++;
		if(i==300)*/
		//std::cout << p << std::endl;
		//p = 0;
	}
	system("pause");
	return 0;
}