//#include <Eigen/Dense>
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
//#include"cnt.hpp"

using namespace Eigen;
using namespace std;

/*
int main(){

return 0;
}
*/
const double a = 2.461;     // lattice constant
 
int main(void){
    double a1[2], a2[2];  // basis vectors
    double A[2], B[2];    // atom positions;
    int L1, L2;           // number of repitition
    double b[2], c[2];    // temporal memory
    int i, j;

    a1[0] = a * 0.5 * 1.7320508;
    a1[1] = a * 0.5;
    a2[0] = a * 0.5 * 1.7320508;
    a2[1] = a * (-0.5);
    A[0] = 0.0;
    A[1] = 0.0;
    B[0] = 2.0 / 3.0;
    B[1] = 2.0 / 3.0;
    L1 = 10;
    L2 = 10;

    //fopen_s(&amp;amp;fp,"graphen.xyz","wt");
    ofstream outputfile("graphen.xyz");
    //fprintf(fp, "%d\n", 2 * L1 * L2);
    outputfile<<2*L1*L2<<endl;;
    //fprintf(fp, "graphen sheet\n");
    outputfile<<"graphen_sheet"<<endl;

    for (i = 0; i & amp; lt; L1; ++i)
    {
        for (j = 0; j & amp; lt; L2; ++j)
        {
            // put atom A
            b[0] = (double)i + A[0];
            b[1] = (double)j + A[1];
            c[0] = a1[0] * b[0] + a2[0] * b[1];
            c[1] = a1[1] * b[0] + a2[1] * b[1];
            //fprintf(fp, "C %f %f 0.0\n", c[0], c[1]);
            outputfile<<"C"<<" "<<c[0]<<" "<<c[1]<<" 0.0"<<endl;
                        // put atom B
            b[0] = (double)i + B[0];
            b[1] = (double)j + B[1];
            c[0] = a1[0] * b[0] + a2[0] * b[1];
            c[1] = a1[1] * b[0] + a2[1] * b[1];
            fprintf(fp, "C %f %f 0.0\n", c[0], c[1]);
            outputfile<<"C"<<" "<<c[0]<<" "<<c[1]<<" 0.0"<<endl;
        }
    }
    return 0;
}