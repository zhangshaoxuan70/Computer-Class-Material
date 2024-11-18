#include <stdio.h>
#include <math.h>
int main()
{
	int i;
	int bai,shi,ge;
	for(i=100;i<=999;i++) 
	{
		bai=i/100;
		shi=(i%100)/10;
		ge=(i%100)%10;
		if(i==(pow(bai,3)+pow(shi,3)+pow(ge,3)))
			printf("%d\n",i);
	}
}
