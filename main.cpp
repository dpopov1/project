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

int main() {
	double w = 1000;
	double h = 1000;//100;
	int N = 200;//1000;
	double T = 400;
	double R = 20;
	double m = 1;
	std::cout << '[' << w << ',' << h << ','<< R << ']' << std::endl;
	Sosud_wh a(w, h, N, T, R, m);
	for (int i = 0; true; i++) {
		a.stolknovenie();
		out(a.get_mass(), N);
		a.move();
	}
	system("pause");
	return 0;
}