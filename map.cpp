#include <cstdlib>
#include <cstdio>
#include <vector>
//#include <algorithm>
#include <cmath>
#include <time.h>

using namespace std;

int main(int argc, char** argv) {
	for (double r=0;r<10;r+=0.0001) {
		srand(time(NULL));
		double x=static_cast <double> (rand())  / static_cast <double> (RAND_MAX/10);
		//fprintf(stderr,"%f\n",x);
		for (int i=1;i<300;i++) {
			x*=exp(r*(1-x));
		//fprintf(stderr,"%f %d %f\n",r,i,x);
		}
		for (int i=301;i<600;i++) {
			x*=exp(r*(1-x));
		//fprintf(stderr,"%f %d %f\n",r,i,x);
			printf("%f %f\n",r,x);
		}
		//fprintf(stderr,"%f %f\n",r,x);
	}
}
