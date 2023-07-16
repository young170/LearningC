#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
string_duplicate (char * orig) 
{
	// TODO: implement here
	if (0x0 == orig) {
		return 0x0;
	}

	int length = strlen(orig);
	char *str = (char *) malloc(sizeof(char) * length + 1);

	int i = 0;
	while (orig[i] != 0x0) {
		str[i] = orig[i];

		i++;
	}

	str[i] = '\0';
	return str;
}

int 
main() 
{
	char * days[8] ;
	days[0] = string_duplicate("Sunday") ; 
	days[1] = string_duplicate("Monday") ;
	days[2] = string_duplicate("Tuesday") ;
	days[3] = string_duplicate("Wednesday") ;
	days[4] = string_duplicate("Thursday") ;
	days[5] = string_duplicate("Friday") ; 
	days[6] = string_duplicate("Saturday") ;
	days[7] = 0x0 ;

	char ** p = days ; 

	while (*p != 0x0) {
		printf("%s\n", *p) ;
		p += 1 ;
	}

	p = days;
	while (*p != 0x0) {
		free(*p);
		p += 1;
	}
}
