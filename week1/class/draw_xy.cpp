#include <stdio.h>
#include <windows.h>
void draw_xy_line01(int a, int b);
void gotoxy(int x, int y);
int main(void)
{
	int a, b;
	printf("y=ax+b의 직선 식을 좌표에 출력\n");
	printf("기울기 a입력>");
	scanf("%d", &a);
	printf("절편 b입력>");
	scanf("%d", &b);
	system("cls");
	draw_xy_line01(a, b);
	printf("\n");
	return 0;
}

void draw_xy_line01(int a, int b)
{
	int x, y;
	for(x=1;x<=10;x+=1)
	{
		y=a*x+b;
		gotoxy(x, y);
        printf("*");
	}
}

void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
