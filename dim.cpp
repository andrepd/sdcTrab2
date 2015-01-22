#include <cstdlib>
#include <cstdio>
#include <vector>
//#include <algorithm>
//#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

//const int N=1000000;

int main(int argc, char** argv) {
	vector< vector <double> > d(3);
		
	if (argc != 4) {
		fprintf(stderr,"Usage: dim N emax ef <in >out\n");
		return -1;
	}
	const int N=atoi(argv[1]);
	const double emax=atof(argv[2]),ef=atof(argv[3]);
	
	double a,b,c;
	while(scanf("%*lf %lf %lf %lf",&a,&b,&c) != EOF) {
		d[0].push_back(a);
		d[1].push_back(b);
		d[2].push_back(c);
	}
	int l=d[0].size();
	
	int x,y;
	srand(time(NULL));
	for (double e=0.1;e<emax;e*=ef) {
		int q=0;
		for (int i=0;i<N;i++) {
			int x = rand() % l; int y= rand() % l;
			if (pow(d[0][x]-d[0][y],2) + pow(d[1][x]-d[1][y],2) + pow(d[2][x]-d[2][y],2) < e*e) q++;
		}
		//double g=q/N/N;
		printf("%f %d\n",e,q);
		//fprintf(stderr,"%f %d\n",e,q);
	}
}
