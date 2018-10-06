#include<iostream>
#include<unistd.h>
#include<windows.h>
using namespace std;
int main()
{
	system("color f3");
	cout<<"\n===================================================== TIC-TAC-TOE =====================================================\n";
	int x,y,move,i,hum_win_move;
	int board[9]={8,3,4,1,5,9,6,7,2};
	int corner_no[4]={0,2,6,8};
	int corner[4]={8,4,6,2};
	int middle_no[4]={1,3,5,7};
	int middle[4]={3,1,9,7};
	char disp_board[9];
	int system[5];
	int human[5];
	string name;
	cout<<"\nEnter your name: ";
	cin>>name;
	cout<<"\nPlayer 1: "<<name<<"\nPlayer 2: Machine\n";
	Sleep(2000);
	cout<<"\n\n\t\t\t\t\t\t\t ** Game Began **\n\n\n";
	Beep(2000,500);
	Sleep(1000);
	for(i=0;i<9;i++)
	{
		disp_board[i]='-';
	}

		cout<<"\n\t==================\n";
		cout<<"\t "<<disp_board[0]<<"\t"<<disp_board[1]<<"\t"<<disp_board[2]<<"\n";
		cout<<"\t "<<disp_board[3]<<"\t"<<disp_board[4]<<"\t"<<disp_board[5]<<"\n";
		cout<<"\t "<<disp_board[6]<<"\t"<<disp_board[7]<<"\t"<<disp_board[8]<<"\n";
		cout<<"\t==================\n";
	
	for(i=0;i<5;i++)
	{
		int flag=0,MW=0;
		cout<<"\n Player 1 Move: ";
		cin>>move;
		move=move-1;
		if(disp_board[move]!='-')
		{
			Beep(2000,800);
			cout<<"\n Wrong Move, Try Again...\n";
			cout<<"\n Player 1 Move: ";
			cin>>move;	
		}
		if(move<0&&move>8)
		{
			Beep(2200,800);
			cout<<"\n Wrong Move, Try Again...\n";
			cout<<"\n Player 1 Move: ";
			cin>>move;
		}
		
		disp_board[move]='X';
		human[i]=board[move];
		cout<<"\n\t==================\n";
		cout<<"\t "<<disp_board[0]<<"\t"<<disp_board[1]<<"\t"<<disp_board[2]<<"\n";
		cout<<"\t "<<disp_board[3]<<"\t"<<disp_board[4]<<"\t"<<disp_board[5]<<"\n";
		cout<<"\t "<<disp_board[6]<<"\t"<<disp_board[7]<<"\t"<<disp_board[8]<<"\n";
		cout<<"\t==================\n";
		if(hum_win_move==move)
		{
			cout<<"\n***************************** Human Win *****************************\n";
			Beep(2200,500);
			return 0;
		}
		cout<<"\nThinking...\n";
		Sleep(1000);
		
		if(i<1)
		{
			if(disp_board[4]=='-')
			{
				int result=disp_board[4]='0';
				system[i]=board[4];
			}
			
			else
			{				
				for(int j=0;j<4;j++)
				{
					if(disp_board[corner_no[j]]=='-')
					{
						disp_board[corner_no[j]]='0';
						system[i]=corner[j];
						break;
					}
				}
			}
		}
		
		else
		{
			int sum=0,j,k,diff=0,sum1=0,diff1=0;
			for(j=i;j>0;j--)
			{
				if(j>1)
					{
						sum1=system[i-1]+system[j-2]; //Problem
						diff1=15-sum1;
						if(diff1>0&&diff1<=9)
						{
							for(k=0;k<9;k++)
							{
								if(board[k]==diff1)
								{
									break;
								}
							}
							if(disp_board[k]=='-')
							{
								hum_win_move=k;
								disp_board[k]='0';
								system[i]=board[k];
								flag=1;
								MW=1;
								break;
							}
						}
					}
				
				if(flag==0)
				{
					sum=human[i]+human[j-1];
					diff=15-sum;
					if(diff>0&&diff<=9)
					{
						for(k=0;k<9;k++)
						{
							if(board[k]==diff)
							{
								break;
							}
						}
						if(disp_board[k]=='-')
						{
							disp_board[k]='0';
							system[i]=board[k];
							flag=1;
							break;
						}
						else
						{
							continue;
						}
						
					}	
				}
			}
			if(flag==0)
			{
				int check=0;
				
				if(disp_board[4]=='-')
				{
					disp_board[4]='0';
					system[i]=board[4];
					break;
				}		
				else
				{
					if(disp_board[4]=='X')
					{
						for(int j=0;j<4;j++)
						{
							if(disp_board[corner_no[j]]=='-')
							{
								disp_board[corner_no[j]]='0';
								system[i]=corner[j];
								check=check+1;
								break;
							}
						}
						if(check==0)
						{
							for(int j=0;j<4;j++)
							{
								if(disp_board[middle_no[j]]=='-')
								{
									disp_board[middle_no[j]]='0';
									system[i]=middle[j];
									break;
								}
							}
						}		
					}
					else
					{
						for(int j=0;j<4;j++)
						{
							if(disp_board[middle_no[j]]=='-')
							{
								disp_board[middle_no[j]]='0';
								system[i]=middle[j];
								check=check+1;
								break;
							}
						}
						if(check==0)
						{
							for(int j=0;j<4;j++)
							{
								if(disp_board[corner_no[j]]=='-')
								{
									disp_board[corner_no[j]]='0';
									system[i]=corner[j];
									break;
								}
							}
						}
						
					}
					
				}
			}
		}
		cout<<"\n\t==================\n";
		cout<<"\t "<<disp_board[0]<<"\t"<<disp_board[1]<<"\t"<<disp_board[2]<<"\n";
		cout<<"\t "<<disp_board[3]<<"\t"<<disp_board[4]<<"\t"<<disp_board[5]<<"\n";
		cout<<"\t "<<disp_board[6]<<"\t"<<disp_board[7]<<"\t"<<disp_board[8]<<"\n";
		cout<<"\t==================\n";
		if(MW==1)
		{
			cout<<"\n***************************** Machine Win *****************************\n";
			Beep(2200,500);
			return 0;
		}
	}
	cout<<"\n**************************** Match Draw ****************************\n";
	Beep(2200,800);
}
