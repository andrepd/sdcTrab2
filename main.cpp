/* Programa para integrar equacoes diferenciais ordinarias usando o metodo
   Runge-Kutta de 4a ordem.
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
const long double tf=2000,h=0.008;

// Number of dependent variables
const int N=3;

// Initial values
long double init[]={2,0,0};

// User constants
const long double s = 10;
const long double b = 8/3;
long double r = 24.4;	//para o exercicio 1.a)
//long double r = 28;		//para o exercicio 1.b)

// Function definitions
//   d/dt (x[n]) = fn
long double f1(std::valarray<long double> x) {
    return s*(x[1]-x[0]);
}

long double f2(std::valarray<long double> x) {
	//return r*xx[0]-xx[1]-xx[0]*x[2];
    return (r-x[2])*x[0]-x[1];
}

long double f3(std::valarray<long double> x) {
    return x[0]*x[1]-b*x[2];
}

// End user area
//////////////////////////////////////////////////////

int main(int argc, char** argv) {
	std::valarray<long double> x(init,N);

	typedef long double (*f_T)(std::valarray<long double>);
	std::vector<f_T> f {f1,f2,f3};

	std::valarray<long double> k1 (0.,N);
    std::valarray<long double> k2 (0.,N);
    std::valarray<long double> k3 (0.,N);
    std::valarray<long double> k4 (0.,N);

    std::valarray<long double> a (0.,N);

    for (long double t=0;t<tf;t+=h) {
		r=24.4+sin(0.1*t);	//para o exercicio 1.a)
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

        std::printf("%Lf ",t);
		for(int i=0;i<N-1;i++) {
            std::printf("%Lf ", x[i]);
        }
        std::printf("%Lf\n",x[N-1]);

    }

    return 0;
}
