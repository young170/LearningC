#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
match (char * prefix, char * verse)
{
	while (*prefix != 0x0) { // check until end of prefix
		if (*prefix != *verse) 
			return 0 ;
		prefix++ ;
		verse++ ;
	}
	return 1 ;
}

int 
main ()
{
	char prefix[16] ;
	int  prefix_len ; 

	char book[4] ;
	int chapter ;
	int verse ;

	scanf("%3s", book) ;
	scanf("%d", &chapter) ;
	scanf("%d", &verse) ;
	
	snprintf(prefix, 16, "%s %d:%d ", book, chapter, verse) ;
	prefix_len = strlen(prefix) ;

	FILE * fp = fopen("NIV.txt", "r") ;

	char * v = (char *) malloc(sizeof(char) * 1024) ;
	size_t v_len = 1024 ;

	while (!feof(fp)) {
		int t ;
		getline(&v, &v_len, fp) ;

        // use match()
        if (match(prefix, v)) {
            printf("%s", v);
            exit(0);
        }

		// if (strncmp(prefix, v, strlen(prefix)) == 0) {
		// 	printf("%s", v) ;
		// 	exit(0) ;
		// }
	}

	return 0 ;
}
