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
	printf("字母：%d\n空格：%d\n数字：%d\n其他：%d",Etext,space,number,other);
}
