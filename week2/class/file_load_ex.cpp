#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
char terms[50][40];
char *file_name="terms.txt";
void load_data(int *number);
void search_data(char data[][40], int number);
void sort_data(char data[][40], int number);
void upper_to_lower(char str[]);
void gotoxy(int x, int y);
int main(void)
{
	int number;
	load_data(&number);
	sort_data(terms, number);
	search_data(terms, number);
	return 0;
}


void load_data(int *number)
{
	FILE *fp;
	*number=0;
	fp=fopen(file_name, "r");
	if (fp==NULL)
	{
		printf("file open error!\n");
		exit(1);
	}
	while(!feof(fp))
	{
		fgets(terms[*number], 39, fp);
		(*number)++;
	}
	fclose(fp);
}

void sort_data(char data[][40], int number)
{

	int i, j, min;
	char temp1[39], temp2[39];
	for (i=0;i<number-1;i++)
	{
		min = i;
		for (j=i+1; j < number; j++)
		{
			strcpy(temp1, data[j]);
			strcpy(temp2, data[min]);
			upper_to_lower(temp1);
			upper_to_lower(temp2);
			if (strcmp(temp1, temp2)<=0)
				min = j;
		}
			strcpy(temp1, data[min]);
			strcpy(data[min], data[i]);
			strcpy(data[i], temp1);
	}
}

void search_data(char data[][40], int number)
{

	char input[40]={'\0'}, temp[40]={'\0'};
	int i, length, count1=0, count2=0;
	do
	{
		gotoxy(1,1);
		printf("용어 입력>");
		length=strlen(input);
		gotoxy(11+length,1);
		input[count1]=getch();
		system("cls");
		gotoxy(11,1);
		printf("%s", input);
		gotoxy(1,3);
		count2=0;
		for(i=0;i<number;i++)
		{
			strcpy(temp, data[i]);
			upper_to_lower(temp);
			if (strncmp(temp, input, count1+1)==0)
			{
				printf("%-40s\n", data[i]);
				count2++;
				if (count2>5)
					break;
			}
		}
		if (input[count1]==27)
			break;
		count1++;
	}while(1);
}

void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void upper_to_lower(char str[])
{
	int i, length;
	length=strlen(str);
	for(i=0; i<length; i++)
		str[i]=tolower(str[i]);
}
