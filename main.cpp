/* Program for integration of differential equations using the fourth
   order Runge-Kutta method.
*/

#include <cstdlib>
#include <cstdio>
//#include <string>
#include <valarray>
#include <vector>
#include <algorithm>
//#include <iostream>
#include <cmath>

//using namespace std;


//////////////////////////////////////////////////////
// Begin user area

// Time interval and step
const double tf=2000,h=0.004;

// Number of dependent variables
const int N=3;

// Initial values
double init[]={2,0,0};

// User constants
const double s = 10;
const double b = 8/3;
double r = 24.4;

// Function definitions
//   d/dt (x[n]) = fn
double f1(std::valarray<double> xx) {
    return s*(xx[1]-xx[0]);
}

double f2(std::valarray<double> xx) {
    return (r-xx[2])*xx[0]-xx[1];
}

double f3(std::valarray<double> xx) {
    return xx[0]*xx[1]-b*xx[2];
}

// End user area
//////////////////////////////////////////////////////


int main(int argc, char** argv) {
	std::valarray<double> x(init,N);

	typedef double (*f_T)(std::valarray<double>);
	std::vector<f_T> f {f1,f2,f3};

    std::valarray<double> k1 (0.,N);
    std::valarray<double> k2 (0.,N);
    std::valarray<double> k3 (0.,N);
    std::valarray<double> k4 (0.,N);

    std::valarray<double> a (0.,N);
	
    for (double t=0;t<tf;t+=h) {
		r=24.4+sin(0.1*t);
        for(int i=0;i<N;i++) {
            k1[i] = f[i](x);
        }

        for(int i=0;i<N;i++) {
            a=h*k1/2;
            k2[i] = f[i](x+a);
        }

        for(int i=0;i<N;i++) {
            a=h/2*k2;
            k3[i] = f[i](x+a);
        }

        for(int i=0;i<N;i++) {
            a=h*k3;
            k4[i] = f[i](x+a);
        }

        for(int i=0;i<N;i++) {
            x[i] += h / 6 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
        }

        std::printf("%f ",t);
		for(int i=0;i<N-1;i++) {
            std::printf("%f ", x[i]);
        }
        std::printf("%f\n",x[N]);

    }

    return 0;
}

