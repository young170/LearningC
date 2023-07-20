#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* NOFIX --- */

typedef enum {
	start,
	left,
	right,
	up,
	down,
	quit,
	N_op 
} commands ;

typedef enum {
	vertical,
	horizontal 
} direction ;

typedef struct {
	int id ;
	int y1, y2 ;	// y1: the minimum of y, y2: the maximum of y
	int x1, x2 ;	// x1: the minimum of x, x2: the maximum of x
	int span ;		// the number of cells 
	direction dir ;	// the direction of the car
} car_t ;

char * op_str[N_op] = {
	"start",
	"left",
	"right",
	"up",
	"down",
	"quit"
} ;

int n_cars = 0 ;
car_t * cars = 0x0 ;
int cells[6][6] ; // cells[Y][X]
// A6 -> cells[5][0]
// F4 -> cells[3][5]
// F1 -> cells[0][5]

/* --- NOFIX */
#define BOARD_SIZE 6

commands
get_op_code (char * s)
{
	// return the corresponding number for the command given as s.
	// FIXME
    for (int i = 0; i < N_op; i++) {
        if (0 == strcmp(s, op_str[i])) {
            return i;
        }
    }

    printf("invalid command\n");
    return -1;
}

int
load_game (char * filename)
{
	//FIXME
	// load_game returns 0 for a success, or return 1 for a failure.
	// Use fopen, getline, strtok, atoi, strcmp
	// Note that the last character of a line obtained by getline may be '\n'.
    FILE *fp = fopen(filename, "r");
    char buf[1024];
    char n_buf[1024];

    fscanf(fp, "%s", &n_cars); // first line, number of cars
    cars = (car_t *) malloc(sizeof(car_t) * (n_cars + 1)); // cars in list + red car

    int len;
    for (int i = 0; i < n_cars; i++) {
        char *sep = ":";
        char *token;

        len = getline(&buf, &n_buf, fp);
        cars[i].id = i + 1; // id, 1-n_cars

        token = strtok(buf, sep);
        cars[i].x1 = token[0] - 'A'; // x1 col
        cars[i].y1 = token[1] - '1'; // y1 row

        token = strtok(0x0, sep);
        direction dir_car;
        if (0 == strcmp(token, "vertical")) {
            dir_car = vertical;
        } else if (0 == strcmp(token, "horizontal")) {
            dir_car = horizontal;
        } else {
            fprintf(stderr, "file data incorrect\n");
            return 1;
        }
        cars[i].dir = dir_car; // dir

        token = strtok(0x0, sep);
        int tmp = atoi(token); // span
        if (0 == tmp) {
            fprintf(stderr, "file data incorrect\n");
            return 1;
        }
        cars[i].span = tmp;

        if (vertical == dir_car) { // y2 row
            cars[i].x2 = cars[i].x1;
            cars[i].y2 = cars[i].y1 + cars[i].span;
        } else if (horizontal == dir_car) { // x2 col
            cars[i].x2 = cars[i].x1 + cars[i].span;
            cars[i].y2 = cars[i].y1;
        } else {
            fprintf(stderr, "file data incorrect\n");
            return 1;
        }

        return 0;
    }
}

void
display ()
{
	/* The beginning state of board1.txt must be shown as follows: 
 	 + + 2 + + +
 	 + + 2 + + +
	 1 1 2 + + +
	 3 3 3 + + 4
	 + + + + + 4
	 + + + + + 4
	*/

	//FIXME
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (0 == cells[i][j]) {
                printf("+");
            } else {
                printf("%d", cells[i][j]);
            }

            printf(" ");
        }

        printf("\n");
    }
}

int 
update_cells ()
{
	memset(cells, 0, sizeof(int) * 36) ; // clear cells before the write.

	//FIXME
	// return 0 for sucess
	// return 1 if the given car information (cars) has a problem
    for (int i = 0; i < n_cars; i++) {

    }
}

int
move (int id, int op) 
{
	//FIXME
	// move returns 1 when the given input is invalid.
	// or return 0 for a success.

	// Update cars[id].x1, cars[id].x2, cars[id].y1 and cars[id].y2
	//   according to the given command (op) if it is possible.

	// The condition that car_id can move left is when 
	//  (1) car_id is horizontally placed, and
	//  (2) the minimum x value of car_id is greather than 0, and
	//  (3) no car is placed at cells[cars[id].y1][cars[id].x1-1].
	// You can find the condition for moving right, up, down as
	//   a similar fashion.
}

int
main ()
{
	char buf[128] ;
	int op ;
	int id ;

	while (1) {
		scanf("%s", buf) ;

		switch (op = get_op_code(buf)) {
			case start:
				scanf("%s", buf) ;
				load_game(buf) ;
				update_cells() ;
				display() ;

			case left:
			case right:
			case up:
			case down:
				scanf("%d", &id) ;
				move(id, op) ;
				update_cells() ;
				display() ;
			//FIXME
            default:
                return EXIT_FAILURE;
		}
	}
}
