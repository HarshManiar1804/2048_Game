#include<stdio.h>
#include<conio.h>

void upKeyPress(int Grid[4][4])
{
	int i,j,li,ri;
	for(j=0;j<4;j++)
	{
		li=0,ri=j;
		for(i=1;i<4;i++)
		{
			if(Grid[i][j]!=0)
			{
				if(Grid[i-1][j]==0 || Grid[i-1][j]==Grid[i][j])
				{
					if(Grid[li][ri]==Grid[i][j])
					{
						Grid[li][ri]*=2;
						Grid[i][j]=0;
					}
					else
					{
						if(Grid[li][ri]==0)
						{
							Grid[li][ri]=Grid[i][j];
							Grid[i][j]=0;
						}
						else
						{
							Grid[++li][ri]=Grid[i][j];
							Grid[i][j]=0;
						}
					}
				}
				else li++;
			}
		}
	}
}

void downKeyPress(int Grid[4][4])
{
	int i,j,li,ri;
	for(j=0;j<4;j++)
	{
		li=3,ri=j;
		for(i=2;i>=0;i--)
		{
			if(Grid[i][j]!=0)
			{
				if(Grid[i+1][j]==0 || Grid[i+1][j]==Grid[i][j])
				{
					if(Grid[li][ri]==Grid[i][j])
					{
						Grid[li][ri]*=2;
						Grid[i][j]=0;
					}
					else
					{
						if(Grid[li][ri]==0)
						{
							Grid[li][ri]=Grid[i][j];
							Grid[i][j]=0;
						}
						else
						{
							Grid[--li][ri]=Grid[i][j];
							Grid[i][j]=0;
						}
					}
				}
				else li--;
			}
		}
	}
}

void leftKeyPress(int Grid[4][4])
{
	int i,j,li,ri;
	for(i=0;i<4;i++)
	{
		li=i,ri=0;
		for(j=1;j<4;j++)
		{
			if(Grid[i][j]!=0)
			{
				if(Grid[i][j-1]==0 || Grid[i][j-1]==Grid[i][j])
				{
					if(Grid[li][ri]==Grid[i][j])
					{
						Grid[li][ri]*=2;
						Grid[i][j]=0;
					}
					else
					{
						if(Grid[li][ri]==0)
						{
							Grid[li][ri]=Grid[i][j];
							Grid[i][j]=0;
						}
						else
						{
							Grid[li][++ri]=Grid[i][j];
							Grid[i][j]=0;
						}
					}
				}
				else ri++;
			}
		}
	}
}

void rightKeyPress(int Grid[4][4])
{
	int i,j,li,ri;
	for(i=0;i<4;i++)
	{
		li=i,ri=3;
		for(j=2;j>=0;j--)
		{
			if(Grid[i][j]!=0)
			{
				if(Grid[i][j+1]==0 || Grid[i][j+1]==Grid[i][j])
				{
					if(Grid[li][ri]==Grid[i][j])
					{
						Grid[li][ri]*=2;
						Grid[i][j]=0;
					}
					else
					{
						if(Grid[li][ri]==0)
						{
							Grid[li][ri]=Grid[i][j];
							Grid[i][j]=0;
						}
						else
						{
							Grid[li][--ri]=Grid[i][j];
							Grid[i][j]=0;
						}
					}
				}
				else ri--;
			}
		}
	}
}

void addblock(int Grid[4][4])
{
	int li,ri;
	srand(time(0));
	while(1)
	{
		li=rand()%4;
		ri=rand()%4;
		if(Grid[li][ri]==0)
		{
			Grid[li][ri]=pow(2,li%2 + 1);
			break;
		}
	}

}

void disp(int Grid[4][4])
{
	printf("\n\t\t\tPress Esc anytime to quit the game");
	printf("\n\n\n\n");
	int i,j;
	for(i=0;i<4;i++)
	{
		cout<<"\t\t\t\t-----------------\n\t\t\t\t";
		for(j=0;j<4;j++)
		{
			if(Grid[i][j]==0) cout<<"|   ";
			else
				printf("| %d ",Grid[i][j]);
		}
		printf("|\n");
	}
	printf("\t\t\t\t-----------------\n");
}

int check(int tmp[4][4],int Grid[4][4])
{
	int fl=1,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(tmp[i][j]!=Grid[i][j])
    		{
    			fl=0;
    			break;
			}
	return fl;
}

int checkGrid(int Grid[4][4])
{
	int fl=0,gl=0,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(Grid[i][j]==0)
    		{
    			fl=1;
				break;	
			}
			
	for(i=0;i<3;i++)
    	for(j=0;j<3;j++)
    		if(Grid[i+1][j]==Grid[i][j] || Grid[i][j+1]==Grid[i][j])
    		{
    			gl=1;
    			break;
			}
			
	if(fl || gl) return 1;
	else return 0;
}

int main()
{
	printf("\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key to continue");
	getch();
	system("cls");
	int i1,i2,i3,i4,i,j;
	int Grid[4][4]={0},tmp[4][4]={0};
	srand(time(0));
	i1=rand()%4;
	i2=rand()%4;
	while(1)
	{
		i3=rand()%4;
		i4=rand()%4;
		if(i3!=i1 && i4!=i2) break;
	}
	Grid[i1][i2]=2;
	Grid[i3][i4]=4;
	disp(Grid);
	
	int ch;
	while (1)
    {
    	for(i=0;i<4;i++)
    		for(j=0;j<4;j++)
    			tmp[i][j]=Grid[i][j];
    	ch=getch();
    	system("cls");
    	if(ch==72) upKeyPress(Grid);
    	else if(ch==80) downKeyPress(Grid);
    	else if(ch==75) leftKeyPress(Grid);
    	else if(ch==77) rightKeyPress(Grid);
		else printf("Click Arrow key only");
		
		if(!check(tmp,Grid))
			addblock(Grid);
		disp(Grid);
			
		if(!checkGrid(Grid))
		{
			printf("\n\n\t\t\t\tGAME OVER!!\n\n\n");
			getch();
			break;
		}	
	}
	return 0;
}
