AR        = ar -r
RANLIB    = ranlib
RM	      = rm -rf
CC 	      = gcc
LD	      = $(CC)
STRL      = esterel

CFLAGS    =  -g
CINCLUDE  = 
LIBS	  = 


COMPILE   = $(CC) $(CFLAGS) $(CINCLUDE) -c

%.o: %.c
	$(COMPILE) $<

%.c: %.strl
	$(STRL) $<
	
####################################################

CALCUL1 = calcul1.c calcul_main1.c
CALCUL2 = calcul2.c calcul_main2.c 
CALCUL3 = calcul3.c calcul_main3.c 

calcul: calcul1 calcul2 calcul3


calcul1: $(CALCUL1:.strl=.c) $(CALCUL1:.c=.o) 
	$(CC) $(CALCUL1:.c=.o) $(LIBS) -o calcul1
		
calcul2: $(CALCUL2:.strl=.c) $(CALCUL2:.c=.o)
	$(CC) $(CALCUL2:.c=.o) $(LIBS) -o calcul2

calcul3: $(CALCUL3:.strl=.c) $(CALCUL3:.c=.o)
	$(CC) $(CALCUL3:.c=.o) $(LIBS) -o calcul3
	
	
calcul1-simul: calcul1.strl
	$(STRL) -simul calcul1.strl -B calcul1-simul
	$(CC) $(CFLAGS) -c -m32 calcul1-simul.c
	xes -Xcomp -m32 calcul1-simul.o
	
calcul2-simul: calcul2.strl
	$(STRL) -simul calcul2.strl -B calcul2-simul
	$(CC) $(CFLAGS) -c -m32 calcul2-simul.c
	xes -Xcomp -m32 calcul2-simul.o
	
calcul3-simul: calcul1.strl
	$(STRL) -simul calcul3.strl -B calcul3-simul
	$(CC) $(CFLAGS) -c -m32 calcul3-simul.c
	xes -Xcomp -m32 calcul3-simul.o


clean:
	$(RM)  *.a *.o *.bak core calcul1 calcul2 calcul3

cleanall: clean
	$(RM)  calcul[1-3].c calcul1-simul*
