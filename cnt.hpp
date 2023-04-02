#ifndef CNT_H_
#define CNT_H_

#include <Eigen/Dense>
#include<vector>
#include<string>

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
		void putz(double z);
		Atom(Vector3d &coord);
};

class Bond{
	private:
		Vector3d coord;
		Vector3d angle;

	public:
		Bond(Vector3d &a0, Vector3d &a1);
		void getcoord(Vector3d &coord) const;
		void getangle(Vector3d &angle) const;
};


class NanoTube{
	private:
		int n, m;
		Vector3d ch;
		Vector3d lt; 
		int r;
		vector<Atom> Atoms;
		vector<Bond> Bonds;

	public:
		NanoTube(const int, const int);
		void graphene(void);
		void tube(void);
		void csv(void);
};

#endif