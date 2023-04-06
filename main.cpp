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
    string atomid0, atomid1;
    cout<<"input chilarity as n_m. n_m should be n>m or n=m"<<endl;
    cin>>n>>m;
        if(n<m){
            cout<<"error n,m should be n>m or n=m !"<<endl;
            return 0;
        }
        else if (n<=0 || m<0){
            cout<<"error n should be n>0 and m should be m=0 or m>0 !"<<endl;
            return 0;
        }
    cout<<"input first atom type"<<endl;
    cin>>atomid0;
    cout<<"input final atom type"<<endl;
    cin>>atomid1;


    timer::timemeasurer timer;
    timer.timerstart();

    double length = 30.0;
    NanoTube test(n,m,length);
    test.graphene(atomid0, atomid1);
    test.tube();
    test.bond();
    test.xyz();
    test.csv();

    timer.timerend();
	std::cout << timer.result() << "ms"<<std::endl;

    return 0;
}
