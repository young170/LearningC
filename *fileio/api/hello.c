#include <stdio.h>

int main ()
{
	char buf[128] ;
	scanf("%127s", buf) ; // specify max input
	printf("Hellow, %s\n", buf) ;
	return 0 ;
}
