#include <Eigen/Dense>
#include<iostream>
#include<vector>
#include<string>
#include"cnt.hpp"

using namespace Eigen;
using namespace std;

double pi = 3.14159;
double a = 1.461;
Vector3d a1 (a * 0.5 * 1.7320508, a * 0.5, 0.0);
Vector3d a2 (a * 0.5 * 1.7320508, a * (-0.5), 0.0);
Vector3d A (0.0, 0.0,0.0);
Vector3d B (0.6666666, 0.6666666, 0.0);

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
////////////////////////////////////////////////////////

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
NanoTube::NanoTube(const int n, const int m){
	this->n = n;
	this->m = m;
	this->ch = this->n * a1 + this->m * a2;
	this->lt << ch(1), -1*ch(0), 0;
	this->r = ch.norm() * 0.5 / pi;
	Vector3d temp0 (0.0, 0.0, 0.0);
	this->Atoms.push_back(temp0);
}
