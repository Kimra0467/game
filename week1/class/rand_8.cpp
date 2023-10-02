#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
   int i;
   double rnd;
   srand(time(NULL));
   for(i=1;i<=5;i++)
   {
	rnd=rand()/RAND_MAX;
	printf("%6.4f\n", rnd);
   }
   return 0;
}
