# $@ The name of the EXEC file (the one before the colon)
# $< The name of the first (or only) prerequisite file (the first one after the colon)
# $^ The names of all the prerequisite files (space separated)
# $* The stem (the bit which matches the % wildcard in the rule definition.
#
CC = gcc
EXE = run
INCDIR = ./include

SRC1 = rushhour.c
OBJ1 = $(SRC1:.c=.o) # rushhour.c -> rushhour.o
EXE1 = rushhour

# rule for link
all: $(EXE1)
$(EXE1): $(OBJ1)
	$(CC) -o $@ $^

# rule for compilation
%.o: %.c
	$(CC) -c -I$(INCDIR) $<

