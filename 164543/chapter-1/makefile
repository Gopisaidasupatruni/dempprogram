
CC=cc
CFLAGS=-c 
COMPILER_CALL=$(CC) $(CFLAGS)
COBJECTS=164543_Gopi_ex1-1.o 164543_Gopi_ex1-3.o

final: $(COBJECTS)
	$(CC) $(COBJECTS) -o final
164543_Gopi_ex1-1.o: 164543_Gopi_ex1-1.c
	$(CC) $(CFLAGS) 164543_Gopi_ex1-1.c
164543_Gopi_ex1-3.o: 164543_Gopi_ex1-3.c
	$(COMPILER_CALL) 164543_Gopi_ex1-3.c
clean:
	rm -f *.o
