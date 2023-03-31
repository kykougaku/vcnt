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
void Atom::getcoord(Vector3d &coord) const {
	coord = this->coord;
}
Atom::Atom(Vector3d &coord){
	this->coord = coord;
}
//Bond//////////////////////////////////////////////////
void Bond::getcoord(Vector3d &coord) const {
	coord = this->coord;
}
void Bond::getangle(Vector3d &angle) const {
	angle = this->angle;
}
Bond::Bond(Vector3d &a0, Vector3d &a1){
	this->coord = (a0 + a1) / 2;
	this->angle(0) = atan( (a1(1)-a0(1)) / (a1(2)-a0(2)) );
	this->angle(1) = atan( (a1(0)-a0(0)) / (a1(2)-a0(2)) );
	this->angle(2) = 0.0;
}
