#include <stdio.h>
int main()
{
	int n,i,j;
	scanf_s("%d",&n);
	for(i=n/2+1;i>=1;i--)
	{
		for(j=1;j<=n;j++)
		{
			if(i>j || n-j+1<i)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
	for(i=1;i<=n/2;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i>=j || n-j<i)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
}
