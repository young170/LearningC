#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int n_words = 370098 ;

char ** words ;


int lookup(char * word)
{
	if (word == 0x0)
		return 0 ;

	for (int i = 0 ; i < n_words ; i++) {
		if (strcmp(words[i], word) == 0)
			return 1 ; // true ;
	}

	return 0 ; // false.
}


int 
main()
{
	char input[256] ;

	words = (char **) malloc(sizeof(char *) * n_words) ;

	FILE * fp ;
	int i ;
	fp = fopen("words.txt", "r") ;
    if (0x0 == fp) {
        fprintf(stderr, "file can't be read\n");
        exit(1);
    }

	for (i = 0  ; i < n_words ; i++) {
		fscanf(fp, "%ms", &(words[i])) ; // allocates memory right away
	}

	while (1) {
		printf("word: ") ;
		scanf("%255s", input) ; 

		if (lookup(input))
			printf("%s\n", input) ;
	}
}
