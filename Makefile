CC		=	gcc
CFLAGS		=	`sdl-config --cflags` -W -Wall -ansi -pedantic
LDFLAGS		=	`sdl-config --libs`
RM		=	/bin/rm
SRC		=	./src/main.c	\
			./src/conf.c	\
			./src/grid.c	\
			./src/display.c	\
			./src/events.c	\
			./src/help.c
INC		=	-I./include/
OBJ		=	$(SRC:.c=.o)
PROG		=	lifescope

all: $(PROG)

$(PROG): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

.c.o:
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -f $(OBJ)

distclean: clean
	$(RM) -f $(TARGET)

re: distclean all

