#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define box_length 15 //게임의 영역(좌우 길이) 
#define box_height 15 //바닥의 높이(상하 길이) 

void intro_game(void);
void game_control(void);
void gotoxy(int x, int y);
int left_right_move(void);
void move_down(int x);
void draw_rectangle(int c, int r);
int max_block(void);

int block_stack[box_length*2+1]={0}; //해당위치의 값을 0으로 초기화

int main(void)
{
	intro_game();
	game_control();
	gotoxy(1, box_height+3);
	printf("game이 종료되었습니다.                 \n");
	return 0;
}

void intro_game(void)
{
	system("cls");
	printf("블록 쌓기 \n\n");
	printf("블록이 좌우로 움직일때 스페이스키를 누르면\n");
	printf("블록이 떨어져 바닥에 쌓입니다.\n\n");
	printf("아무키나 누르면 게임을 시작합니다. \n");
	getch();
}
void game_control(void)
{
	int x, count=0;
	system("cls");
	draw_rectangle(box_length, box_height);
	gotoxy(box_length*2+5,3);
	printf("블록의 개수: %2d", box_height);
	gotoxy(1, box_height+3);
	printf("스페이스키를 누르면 블록이 떨어지고\n");
	printf("바닥에 쌓입니다. \n");
	while(count<box_height)
	{
		gotoxy(box_length*2+5,4);
		printf("시도한 횟수: %2d", count+1);
		gotoxy(box_length*2+5,5);
		printf("쌓인 블록수: %2d", max_block());
		x=left_right_move();
		move_down(x);
		count++;
		getch();
	}

}
void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int left_right_move(void)
{
	int x=3, y=2, temp=2;
	do
	{
		x+=temp;
		if (x>(box_length*2)) //x방향 최대값 설정
			temp=-2;
		if (x<3)
		{
			x=3;
			temp=2;
		}

		gotoxy(x, y);
		printf("□");
		Sleep(50); //블록이 좌우로 움직이는 속도를 조절
		gotoxy(x, y);
		printf("  ");

	}while(!kbhit());
	block_stack[x]+=1;
	return x;
}
void move_down(int x)
{
	int y;
	for(y=2;y<box_height+2-block_stack[x];y+=1)
	{
		gotoxy(x, y);
		printf("□");
		Sleep(20);
		gotoxy(x, y);
		printf("  ");
		Sleep(10);
	}
	gotoxy(x,box_height+2-block_stack[x]);
	printf("□");
}
void draw_rectangle(int c, int r)
{
    int i, j;
    unsigned char a=0xa6;
    unsigned char b[7]; 
    for(i=1;i<7;i++)
   	b[i]=0xa0+i;

    printf("%c%c",a, b[3]);
    for(i=0;i<c;i++)
  	printf("%c%c", a, b[1]);
    printf("%c%c", a, b[4]);
    printf("\n");
    for(i=0;i<r;i++)
    {
	printf("%c%c", a, b[2]);
	for(j=0;j<c;j++)
		printf("  ");
	printf("%c%c",a, b[2]);
	printf("\n");
    }
    printf("%c%c", a, b[6]);
    for(i=0;i<c;i++)
	printf("%c%c", a, b[1]);
    printf("%c%c", a, b[5]);
    printf("\n");
}
int max_block(void)
{
	int i, max=0;
	for(i=1;i<box_height*2+1;i++)
	{
		if (max<=block_stack[i])
			max=block_stack[i];
	}
	return max;
}
