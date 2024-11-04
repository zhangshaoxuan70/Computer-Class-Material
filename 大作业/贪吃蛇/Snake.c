#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <pthread.h>
int map[100005][100005];
int length=3;
int rotate=0;//0 for right, 1 for down, 2 for left, 3 for up.
int x,y;//head position.
int is_exit;
int has_food;

int width=40;
int height=20;

void output()
{
	system("cls");
	int i,j;
	for(i=0;i<=height;i++)
	{
		for(j=0;j<=width;j++)
		{
			switch(map[i][j])
			{
				case -2:
				{
					printf("¡ô");
					break;
				}
				case -1:
				{
					printf("¡õ");
					break;
				}
				case 0:
				{
					printf("  ");
					break;
				}
				case 1:
				{
					printf("¡ö");
					break;
				}
				default:
				{
					printf("¡õ");
					break;
				}
			}
		}
		printf("\n");
	}
}

void* move()
{
	while(1)
	{
		if(is_exit)
		{
			break;
		}
		Sleep(300);
		int i,j;
		for(i=0;i<=height;i++)
		{
			for(j=0;j<=width;j++)
			{
				if(map[i][j]>0)
					map[i][j]++;
				if(map[i][j]>length)
					map[i][j]=0;
			}
		}
		switch(rotate)
		{
			case 0:
			{
				y++;
				break;
			}
			case 1:
			{
				x++;
				break;
			}
			case 2:
			{
				y--;
				break;
			}
			case 3:
			{
				x--;
				break;
			}
		}
		if(has_food==0)
		{
			while(1)
			{
				int rand_x=rand()%height;
				int rand_y=rand()%width;
				if(map[rand_x][rand_y]==0)
				{
					has_food=1;
					map[rand_x][rand_y]=-2;
					break;
				}
			}
		}
		if(map[x][y]==0)
		{
			map[x][y]=1;
			output();
		}
		else if(map[x][y]==-2)
		{
			map[x][y]=1;
			has_food=0;
			length++;
			output();
		}
		else
		{
			map[x][y]=1;
			output();
			is_exit=1;
			break;
		}
	}
}

int main()
{
	int i,j;
	for(i=0;i<=height;i++)
	{
		for(j=0;j<=width;j++)
		{
			if(i==0||j==0||i==height||j==width)
				map[i][j]=-1;
			else
				map[i][j]=0;
		}
	}
	x=6;y=5;
	
	pthread_t thread;
	if (pthread_create(&thread, NULL, move, NULL))
	{
		fprintf(stderr, "Error creating thread\n");
		return 1;
	}
	
	int ch;
	//char buff[10] = {0};
    while (1){
        if (_kbhit())
		{
            ch = _getch();
            switch(ch)
			{
            	case 27:
            	{
            		is_exit=1;
					break;
				}
            	case 77:
            	{
            		rotate=0;
            		break;
            	}
            	case 80:
            	{
            		rotate=1;
            		break;
            	}
            	case 75:
            	{
            		rotate=2;
            		break;
            	}
            	case 72:
            	{
            		rotate=3;
            		break;
            	}
        	}
    		//itoa(rotate,buff,10);
    		//printf("%s\n", buff);   
        }
        if(is_exit)
        {
        	pthread_join(thread, NULL);
        	break;
		}
    }
}

