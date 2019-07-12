#include <stdlib.h>
#include <stdio.h>

static int * stack = 0x0 ;
static int capacity = 0 ;
static int n_elem = 0 ;

void push (int a)
{
	if (capacity < n_elem + 1) {
		capacity *= 2 ;
		stack = (int *) realloc(stack, capacity * sizeof(int)) ;
	}
	stack[n_elem] = a ;	
	n_elem += 1 ;
}

int pop (int * a)
{
	if (n_elem == 0)
		return 0 ;
	*a = stack[n_elem - 1] ;
	n_elem -= 1 ;

	return 1 ;
}
