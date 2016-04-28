###################################################################
#
# freeman.justin@gmail.com
#
##################################################################

CC=	gcc

CSRC=	./src/

CFLAGS=	-O3 -g -Wall

INC=	-I./include

LFLAGS=

COBJ=	$(CSRC)main.o \
	$(CSRC)fail.o 

OBJ=	$(COBJ)

EXEC=	./bin/colorsampler

$(EXEC):$(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(LFLAGS)

$(COBJ) : %.o : %.c
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

clean:
	rm $(COBJ)
	rm $(EXEC)
