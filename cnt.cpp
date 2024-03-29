#include <Eigen/Dense>
#include<iostream>
#include<vector>
#include<fstream>
#include<cmath>
#include<string>
#include"cnt.hpp"

using namespace Eigen;
using namespace std;

const double pi = 3.14159265359;
const double a = 1.461;
const double root3 = 1.73205080756;
const double c2of3 =0.66666666666666;
Vector3d a1 (a, 0.0, 0.0);
Vector3d a2 (a * 0.5, a*0.5*root3, 0.0);
Vector3d A (0.0, 0.0,0.0);
Vector3d B (c2of3, c2of3, 0.0);

const double bondl = a / root3;
const double bond_error = bondl /10;
const double judge_bondl = bondl + bond_error;
double funcx(double a, double b, double y){
	return a*y+b;
}
double funcy(double a, double b, double x){
	return a*x+b;
}
int examin_the_size(double a, double b, double vari){
	//if >>>>>>>> vari < min_of_a_or_b < max_of_a_or_b >>>>>return 0
	//if >>>>>>>> min_of_a_or_b < vari < max_of_a_or_b >>>>>return 1
	//if >>>>>>>> min_of_a_or_b < max_of_a_or_b < vari >>>>>return 0
	vector<double> temp = {a,b};
	sort(temp.begin(), temp.end());
	if (temp.at(0) < vari && vari <= temp.at(1)) return 1;
	else return 0;
}
//Atom//////////////////////////////////////////////////
double Atom::getx() const{return this->coord(0);}
double Atom::gety() const{return this->coord(1);}
double Atom::getz() const{return this->coord(2);}
string Atom::getid() const{return this->id;}
void Atom::putx(double x) {this->coord(0) = x;}
void Atom::puty(double y) {this->coord(1) = y;}
void Atom::pputz(double z) {this->coord(2) = z;}
Vector3d Atom::getcoord(void){return coord;}
Atom::Atom(Vector3d &coord, string s){
	this->coord = coord;
	this->id = s;
}
////////////////////////////////////////////////////////

//Bond//////////////////////////////////////////////////
Bond::Bond(Vector3d a0, Vector3d a1){
	this->coord = (a0 + a1) / 2;
	this->angle(0) = atan( (a1(1)-a0(1)) / (a1(2)-a0(2)) );
	this->angle(1) = atan( (a1(0)-a0(0)) / (a1(2)-a0(2)) );
	this->angle(2) = 0.0;
}
void Bond::getcoord(Vector3d &coord) const {
	coord = this->coord;
}
double Bond::getx() const{return this->coord(0);}
double Bond::gety() const{return this->coord(1);}
double Bond::getz() const{return this->coord(2);}
double Bond::getanglex() const{return this->angle(0);}
double Bond::getangley() const{return this->angle(1);}
double Bond::getanglez() const{return this->angle(2);}
////////////////////////////////////////////////////////

//NanoTube//////////////////////////////////////////////
NanoTube::NanoTube(const int n, const int m, const double length){
	this->n = n;
	this->m = m;
	this->length = length;
	this->ch = n * a1 + m * a2;
	Matrix3d ro90;
	ro90 << 0, (-1)*length/this->ch.norm(), 0,
			1*length/this->ch.norm(), 0, 0,
			0, 0, 0;
	this->lt = ro90 * ch;
	this->r = this->ch.norm() *0.5 / pi;
}
void NanoTube::graphene(string aid, string bid){
	vector<double> b(2);
	vector<double> c(2);
	int L1 = 1000;
	int L2 = 1000;
	double ac =ch(1)/ch(0);
	double al =lt(0)/lt(1);
	double thea = atan(ac);//Ch theta
	Matrix3d roma;//inverse rotation matrix
	roma << cos(thea), sin(thea), 0,
		-1 * sin(thea), cos(thea), 0,
			0,			0,			0;

	for (int i = (-1*L1); i<L1; ++i)
	{
		for (int j = (-1*L2); j<L2; ++j)
		{
			// put atom A
			b[0] = i + A[0];
			b[1] = j + A[1];
			c[0] = a1[0] * b[0] + a2[0] * b[1];//carbon cluster type A in graphen posX
			c[1] = a1[1] * b[0] + a2[1] * b[1];//carbon cluster type A in graphen posY
			//add type A carbon cluster only in selected area
			vector<double> llt = {funcx(al, 0.0, c.at(0)), funcx(al, ch(1)-(lt(1)/lt(0) * ch(0)), c.at(0))};
			if(examin_the_size(funcy(ac, 0.0, c.at(0)), funcy(ac, lt(1)-(ac*lt(0)), c.at(0)), c.at(1))
			 && examin_the_size(funcx(al, 0.0, c.at(1)), funcx(al, ch(0)-(al*ch(1)), c.at(1)), c.at(0)) 
			 ){
				Vector3d tempa(c.at(0), c.at(1), 0.0);
				Atom tempaa(tempa, aid);
				this->Atoms.push_back(tempaa);
			}

			// put atom B
			b[0] = i + B[0];
			b[1] = j + B[1];
			c[0] = a1[0] * b[0] + a2[0] * b[1];//carbon cluster type B in graphen posX
			c[1] = a1[1] * b[0] + a2[1] * b[1];//carbon cluster type B in graphen posY
			//add type B carbon cluster only in selected area
			vector<double> chh = {funcy(ac, 0.0, c.at(0)), funcy(ac, lt(1)-(ch(1)/ch(0) * lt(0)), c.at(0))};
			vector<double> ltt = {funcx(al, 0.0, c.at(0)), funcx(al, ch(1)-(lt(1)/lt(0) * ch(0)), c.at(0))};
			sort(chh.begin(), chh.end());
			sort(ltt.begin(), ltt.end());
			if(chh.at(0) <= c.at(1) && c.at(1)<= chh.at(1) && ltt.at(0) <= c.at(1) && c.at(1) <= ltt.at(1)){
				Vector3d tempb(c.at(0), c.at(1), 0.0);
				Atom tempba(tempb, bid);
				this->Atoms.push_back(tempba);
			}
		}
	}
	//rotate graphen sheet
	for(int i=0; i<Atoms.size(); i++){
		Vector3d tempp (Atoms.at(i).getx(), Atoms.at(i).gety(), Atoms.at(i).getz());
		tempp = roma*tempp;
		Atoms.at(i).putx(tempp(0)); Atoms.at(i).puty(tempp(1)); Atoms.at(i).pputz(tempp(2));
	}
}
void NanoTube::tube(void){
	for(int i=0; i<Atoms.size(); i++){
		double thea = Atoms.at(i).getx()/this->r;
		Atoms.at(i).putx(this->r * cos(thea));
		Atoms.at(i).pputz(this->r * sin(thea));
	}
}
void NanoTube::bond(void){
	for(int i = 0; i<Atoms.size()-1; i++){
		for(int j = i+1; j<Atoms.size(); j++){
			Vector3d bondvec;
			bondvec = Atoms.at(i).getcoord() - Atoms.at(j).getcoord();
			if(bondvec.norm() <= judge_bondl){
				Bond tempbond (Atoms.at(i).getcoord(), Atoms.at(j).getcoord());
				this->Bonds.push_back(tempbond);
			}			
		}
	}
}
void NanoTube::xyz(void){
	ofstream outputxyz("graphen_cuted.xyz");
	outputxyz<<this->Atoms.size()<<endl;;
	outputxyz<<"id,posx,posy,posz"<<endl;
	for(Atom temp : this->Atoms){
		outputxyz<<temp.getid()<<" "<<temp.getx()<<" "<<temp.gety()<<" "<<temp.getz()<<endl;
	}
}
void NanoTube::csv(void){
	ofstream outputcsv("graphen_cuted.csv");
	outputcsv<<"id,posx,posy,posz,angx,angy,angz"<<endl;
	for(Atom temp : this->Atoms){//////////////////////id0...carbon clusters
		outputcsv<<temp.getid()<<","<<temp.getx()<<","<<temp.gety()<<","<<temp.getz()<<",0,0,0"<<endl;
	}
	for(Bond temp : this->Bonds){//////////////////////id1...bond between clusters
		outputcsv<<"bond"<<","<<temp.getx()<<","<<temp.gety()<<","<<temp.getz()<<","<<temp.getanglex()<<","<<temp.getangley()<<","<<temp.getanglez()<<endl;
	}
}
