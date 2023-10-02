#include <stdio.h>
#include <conio.h>
int main(void)
{
   char chr;
   do
   {
	printf("해당 키를 누르시오>");
	chr=getch();
	printf("\n키: %c, ASCII(10):%d, (16):%x\n", chr, chr, chr);
   }while(chr!='0');
   return 0;
}
