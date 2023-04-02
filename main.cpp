#include <Eigen/Dense>
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"cnt.hpp"
#include"timer_m.hpp"

using namespace Eigen;
using namespace std;

int main(){
    int n,m;
    cout<<"input chilarity as nM"<<endl;
    cin>>n>>m;

    timer::timemeasurer timer;
    timer.timerstart();

    //NanoTube *test = new NanoTube(n,m);
    NanoTube test(n,m);
    test.graphene();
    test.tube();
    test.csv();

    timer.timerend();
	std::cout << timer.result() << "ms"<<std::endl;

    return 0;
}