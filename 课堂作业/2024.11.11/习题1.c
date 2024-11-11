#include <stdio.h>
#include <math.h>
int main()
{
	double n;
	scanf_s("%lf%",&n);
	n=n/(double)100;
	printf("%lf",pow(1+n,10));
}
