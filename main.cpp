/* Program for integration of differential equations using the fourth
   order Runge-Kutta method.

   The equations are as follows. Edit f if needed.
   x. = f(x)

*/

#include <cstdlib>
#include <cstdio>
//#include <string>
//#include <vector>
//#include <iostream>
//#include <cmath>

//using namespace std;

const double K=-1,tf=10,h=0.1;

const int N=2;

double x[]={2,0};

double f1(double x[]) {
    return x[1];
}

double f2(double x[]) {
    return -K*x[0];
}

typedef double (*f_T)(double x[]);

f_T f[N];

f[0] = f1;
f[1] = f2;

operator*(double a, double* b) {
    for(int i=0;i<N;i++) {
        b[i]*=a;
    }

}

int main(int argc, char** argv) {
//    if (argc!=4) {
//        std::printf("Usage: rk4 x0 tf h\nProgram for integration of differential equations using the fourth order Runge-Kutta method.\n\nx0 is the value of x for t=0, tf is the simulation duration, h is the time step.");
//        return 1;
//    }

    double k1[N] = {};
    double k2[N] = {};
    double k3[N] = {};
    double k4[N] = {};

    for (double t=0;t<tf;t+=h) {
        for(int i=N;i<N;i++) {
            k1[i] = f[i](x[i][i]);
        }

        for(int i=N;i<N;i++) {
            k2[i] = f[i](x[i]+h/2*k1[i]);
        }

        for(int i=N;i<N;i++) {
            k3[i] = f[i](x[i]+h/2*k2[i]);
        }

        for(int i=N;i<N;i++) {
            k4[i] = f[i](x[i]+h*k3[i]);
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

