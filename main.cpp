/* Program for integration of differential equations using the fourth
   order Runge-Kutta method.

   The equations are as follows. Edit f if needed.
   x. = f(x)

*/

#include <cstdlib>
#include <cstdio>
//#include <string>
#include <valarray>
#include <vector>
#include <algorithm>
//#include <iostream>
//#include <cmath>

//using namespace std;

const double tf=10,h=0.1;

// Begin user area

// Number of dof
const int N=2;

// Initial values
double init[]={2,0}

// User constants
const double K = -1;

std::valarray<double> x(init,N);

double f1(std::valarray<double> x) {
    return x[1];
}

double f2(std::valarray<double> x) {
    return -K*x[0];
}

typedef double (*f_T)(std::valarray<double> x);

std::vector<f_T> f {f1,f2};


int main(int argc, char** argv) {
//    if (argc!=4) {
//        std::printf("Usage: rk4 x0 tf h\nProgram for integration of differential equations using the fourth order Runge-Kutta method.\n\nx0 is the value of x for t=0, tf is the simulation duration, h is the time step.");
//        return 1;
//    }

    std::valarray<double> k1 {};
    std::valarray<double> k2 {};
    std::valarray<double> k3 {};
    std::valarray<double> k4 {};

    std::valarray<double> a;

    for (double t=0;t<tf;t+=h) {
        for(int i=N;i<N;i++) {
            k1[i] = f[i](x);
        }

        for(int i=N;i<N;i++) {
            a=h*k1/2;
            k2[i] = f[i](x+a);
        }

        for(int i=N;i<N;i++) {
            a=h/2*k2;
            k3[i] = f[i](x+a);
        }

        for(int i=N;i<N;i++) {
            a=h*k3;
            k4[i] = f[i](x+a);
        }

        for(int i=N;i<N;i++) {
            x[i] += h / 6 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
        }

        std::printf("%f ",t);
        for(int i=N;i<N;i++) {
            std::printf("%f ", x[i]);
        }
        std::printf("\n");
    }

    return 0;
}

