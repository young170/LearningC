#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int n_words = 370098 ;

char ** words ;


int lookup(char * word)
{
	int begin = 0 ;
	int end = n_words -1 ;

	while (begin <= end) {
		//printf("[%d, %d]\n", begin, end) ;
		int mid = (begin + end) / 2 ;
		int c = strcmp(word, words[mid]) ;

		if (c == 0) { // identical
			return 1 ; // true
		}
		else if (c < 0) { // word comes before words[mid]
			end = mid - 1 ;
		}
		else /* c > 0 */ { // word comes after words[mid]
			begin = mid + 1 ;
		}
	}
	return 0 ;
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
