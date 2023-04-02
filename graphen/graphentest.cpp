#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"timer_m.hpp"

using namespace std;

double a = 2.461;     // lattice constant

int main(void){
	timer::timemeasurer timer;
	timer.timerstart();

	vector<double> a1 = { a * 0.5 * 1.7320508, a * 0.5};
	vector<double> a2 = { a * 0.5 * 1.7320508, a * (-0.5)};
	vector<double> A ={0.0, 0.0};
	vector<double> B ={0.6666666, 0.6666666};
	int L1, L2;           // number of repitition
	double b[2], c[2];    // temporal memory

	L1 = 100;
	L2 = 100;

	ofstream outputfile("graphen.xyz");
	outputfile<<4*2*L1*L2<<endl;;
	outputfile<<"graphen_sheet"<<endl;

	for (int i = (-1*L1); i<L1; ++i)
	{
		for (int j = (-1*L2); j<L2; ++j)
		{
			// put atom A
			b[0] = i + A[0];
			b[1] = j + A[1];
			c[0] = a1[0] * b[0] + a2[0] * b[1];
			c[1] = a1[1] * b[0] + a2[1] * b[1];
			outputfile<<"C"<<" "<<c[0]<<" "<<c[1]<<" 0.0"<<endl;
			// put atom B
			b[0] = i + B[0];
			b[1] = j + B[1];
			c[0] = a1[0] * b[0] + a2[0] * b[1];
			c[1] = a1[1] * b[0] + a2[1] * b[1];
			outputfile<<"C"<<" "<<c[0]<<" "<<c[1]<<" 0.0"<<endl;
		}
	}

	timer.timerend();
	std::cout << timer.result() << "ms"<<std::endl;

	return 0;
}
