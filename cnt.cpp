#include <Eigen/Dense>
#include<iostream>
#include<vector>
#include<string>
#include"cnt.hpp"

using namespace Eigen;
using namespace std;

//Atom//////////////////////////////////////////////////
double Atom::getx() const{return this->coord(0);}
double Atom::gety() const{return this->coord(1);}
double Atom::getz() const{return this->coord(2);}
void getcoord(Vector3d &coord) const {
	coord = this->coord;
}
Atom::Atom(Vector3d &coord){
	this->coord = coord;
}
//Bond//////////////////////////////////////////////////
