#ifndef CNT_H_
#define CNT_H_

#include <Eigen/Dense>
#include<vector>
#include<string>

using namespace Eigen;
using namespace std;

class Atom{
	private:
		Vector3d coord;
	public:
		double getx() const;
		double gety() const;
		double getz() const;
		void getcoord(Vector3d &coord) const;
		//void tubize(const vector<double>);
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
		vector<double> Ch;
		int dR;
		vector<Atom> Atoms;
		vector<Bond> Bonds;

	public:
		NanoTube(const int, const int, const string);
		void csv() const;
};

#endif