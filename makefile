####### CONSTANTS ########

AR        = ar -r
RANLIB    = ranlib
RM        = rm -rf
CC        = gcc
LD        = $(CC)
STRL      = esterel
XES       = xes

CFLAGS    = -g
CINCLUDE  = -m32 -c
LIBS	  = 

STRLFLAGS = -simul

X32FLAGS  = 
X64FLAGS  = -Xcomp -m32
 
SRCSTRLDIR= ./src/strl/
SRCSIMDIR = ./src/c-simul/
SRCCDIR   = ./src/c/
BINDIR    = ./bin/

COMPILE   = $(CC) $(CFLAGS) $(CINCLUDE) -c

.PHONY: clean cleanall

FILES = $(SRCSTRLDIR)elevator.strl $(SRCSTRLDIR)buttons.strl $(SRCSTRLDIR)cabin.strl $(SRCSTRLDIR)tools.strl


####### RULES #######

simul-comp:	$(FILES:.c=.strl)
	mkdir -p $(SRCSIMDIR)
	$(STRL) $(STRLFLAGS) $(FILES) -B $(SRCSIMDIR)simul
	mv simul.c $(SRCSIMDIR)simul.c
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(CINCLUDE) $(SRCSIMDIR)simul.c $(LIBS) -o $(BINDIR)simul.o

simul32: $(BINDIR)simul.o
	$(XES) $(X32FLAGS) $(BINDIR)simul.o

simul64: $(BINDIR)simul.o
	$(XES) $(X64FLAGS) $(BINDIR)simul.o
	
c-comp:
	mkdir -p $(SRCCDIR)
	$(STRL) $(FILES) -B $(SRCCDIR)elevator
	mv elevator.c $(SRCCDIR)elevator.c
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(CINCLUDE) $(SRCCDIR)elevator.c -o $(BINDIR)elevator.o
	$(CC) $(CFLAGS) $(CINCLUDE) $(SRCCDIR)elevator_main.c -o $(BINDIR)elevator_main.o
	$(CC) $(CFLAGS) $(LIBS) $(BINDIR)elevator.o $(BINDIR)elevator_main.o -o $(BINDIR)elevator
	
c:
	$(BINDIR)elevator

clean:
	$(RM)  $(BINDIR)
	
cleanall: clean
	$(RM) $(SRCSIMDIR) $(SRCCDIR)elevator.c  
