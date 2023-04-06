#ifndef CNT_H_
#define CNT_H_

#include <Eigen/Dense>
#include<vector>

using namespace Eigen;
using namespace std;

double funcx(double a, double b, double y);
double funcy(double a, double b, double x);
int examin_the_size(double a, double b, double vari);

class Atom{
	private:
		Vector3d coord;
		string id;
	public:
		double getx() const;
		double gety() const;
		double getz() const;
		string getid() const;
		void putx(double x);
		void puty(double y);
		void pputz(double z);
		Vector3d getcoord(void);
		Atom(Vector3d &coord, string s);
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
		void graphene(string aid, string bid);
		void tube(void);
		void bond(void);
		void xyz(void);
		void csv(void);
};

#endif