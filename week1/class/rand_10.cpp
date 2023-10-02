#include <stdio.h>
#include <math.h>

int main(void)
{
  int i;
  long unit1=1000000, unit2=100, int_temp;
  double start=1234, temp1, temp2;
  for(i=1;i<=10;i++)
  {
	temp1=pow(start, 2);
	int_temp=temp1/unit1;
	temp2=temp1-int_temp*unit1;
	int_temp=temp2/unit2;
	printf("%5d\n", int_temp);
	start=int_temp;
  }
  return 0;
}
