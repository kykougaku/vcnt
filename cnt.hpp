#ifndef CNT_H_
#define CNT_H_

#include <Eigen/Dense>
#include<vector>

using namespace Eigen;
using namespace std;

double func1(double a, double b, double x);

class Atom{
	private:
		Vector3d coord;
	public:
		double getx() const;
		double gety() const;
		double getz() const;
		void putx(double x);
		void puty(double y);
		void pputz(double z);
		Vector3d getcoord(void);
		Atom(Vector3d &coord);
};

class Bond{
	private:
		Vector3d coord;
		Vector3d angle;
	public:
		Bond(Vector3d a0, Vector3d a1);
		void getcoord(Vector3d &coord) const;
		double getx() const;
		double gety() const;
		double getz() const;
		double getanglex() const;
		double getangley() const;
		double getanglez() const;
};

class NanoTube{
	private:
		int n, m;
		Vector3d ch;
		Vector3d lt; 
		double r,length;
		vector<Atom> Atoms;
		vector<Bond> Bonds;
	public:
		NanoTube(const int, const int, const double);
		void graphene(void);
		void tube(void);
		void bond(void);
		void xyz(void);
		void csv(void);
};

#endif