#include <stdio.h>
int main()
{
	char input;
	int Etext=0;
	int space=0;
	int number=0;
	int other=0;
	while(1)
	{
		input=getchar();
		int exit=0;
		switch(input)
		{
			case 'a' ... 'z':
				Etext++;
				break;
			case 'A' ... 'Z':
				Etext++;
				break;
			case ' ':
				space++;
				break;
			case '0' ... '9':
				number++;
				break;
			case '\n':
				exit=1;
				break;
			default:
				other++;
				break;
			
		}
		if(exit==1)
			break;
	}
	printf("��ĸ��%d\n�ո�%d\n���֣�%d\n������%d",Etext,space,number,other);
}
