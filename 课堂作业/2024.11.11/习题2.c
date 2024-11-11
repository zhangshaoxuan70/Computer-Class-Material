#include <stdio.h>
#include <math.h>
int main()
{
	int d=300000,p=6000;
	double r=0.01;
	float m=log((double)p/(p-(double)d*r))/log(1+r);
	printf("%.1f",m);
}
