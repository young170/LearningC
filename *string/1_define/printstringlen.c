#include <stdio.h>

int
string_length(char *s) {
	//TODO: Implement here
	int length = 0;

	while (*s != 0x0) {
		length++;
		s += 1;
	}

	return length ;
}


int 
main () 
{
	char a[6] = {'H', 'e', 'l', 'l', 'o', 0x0} ;
	char * b = "Good Bye" ;
	char c[20] = "Halla, Heba, Helloa" ;

	printf("%s (%d)\n", a, string_length(a)) ;
	printf("%s (%d)\n", b, string_length(b)) ;
	printf("%s (%d)\n", c, string_length(c)) ;
}
