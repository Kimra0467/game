#include <stdio.h>
#include <windows.h>

void intro_color_set(void);
void text_color(char attr[]);
int main(void)
{
	char attr[3];
	intro_color_set();
	printf("입력 후 Enter>");
	scanf("%s", attr);
	text_color(attr);
	printf("바탕색과 문자색의 변경을 확인합니다.\n");
	return 0;
}

void intro_color_set(void)
{
	printf("텍스트화면의 색상변경\n\n");
	printf("0: 검정색, 1: 파랑색, 2: 초록색\n");
	printf("3: 옥색,   4: 빨강색, 5: 자주색\n");
	printf("6: 노란색, 7: 흰색,   8: 회색\n");
	printf("9: 연한 파랑색,  A: 연한 초록색 \n");
	printf("B: 연한 옥색,    C: 연한 빨강색\n");
	printf("D: 연한 자주색,  E: 연한 노란색\n");
	printf("F: 밝은 흰색\n\n");
	printf("예를 들어 fc를 입력하면 밝은 흰색바탕에\n");
	printf("연한 빨간색의 문자를 출력합니다.\n\n");
}

void text_color(char attr[])
{
	char dos_command[9];
	sprintf(dos_command,"color %s",attr);
	system("cls");
	system(dos_command);
}
