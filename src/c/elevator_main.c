
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

/* Global variables */
int lightout = 0;
int lightf1 = 0;
int lightf2 = 0;
int lightf3 = 0;
int lightf4 = 0;
int opendoor = 0;
int floornumber = 1;
int s = 1;


/* Fucntions for esterel signals */

void ELEVATOR(void);
void ELEVATOR_reset(void);
void ELEVATOR_I_SECOND(void);
void ELEVATOR_I_CALLF1(void);
void ELEVATOR_I_CALLF2(void);
void ELEVATOR_I_CALLF3(void);
void ELEVATOR_I_CALLF4(void);
void ELEVATOR_I_GOF1(void);
void ELEVATOR_I_GOF2(void);
void ELEVATOR_I_GOF3(void);
void ELEVATOR_I_GOF4(void);
void ELEVATOR_I_OPENDOOR(void);

void ELEVATOR_O_DOOROPENED(void){
    opendoor = 1;
    printf("Doors opened\n");
}

void ELEVATOR_O_DOORCLOSED(void){
    opendoor = 0;
    printf("Doors closed\n");
}

void ELEVATOR_O_CURRENTFLOOR(int i){
    floornumber = i;
    printf("The current floor is %d\n", i);
}

void ELEVATOR_O_LF1(void){
    lightf1 = !lightf1;
    if (lightf1)
        printf("Light f1 turn on\n");
    else
        printf("Light f1 turn off\n");
}

void ELEVATOR_O_LF2(void){
    lightf2 = !lightf2;
    if (lightf2)
        printf("Light f2 turn on\n");
    else
        printf("Light f2 turn off\n");
}

void ELEVATOR_O_LF3(void){
    lightf3 = !lightf3;
    if (lightf3)
        printf("Light f3 turn on\n");
    else
        printf("Light f3 turn off\n");
}

void ELEVATOR_O_LF4(void){
    lightf4 = !lightf4;
    if (lightf4)
        printf("Light f4 turn on\n");
    else
        printf("Light f4 turn off\n");
}

void ELEVATOR_O_LOUT(void){
    lightout = !lightout;
    if (lightout)
        printf("Extern light turn on\n");
    else
        printf("Extern light turn off\n");
}
void ELEVATOR_O_WRONG(void){
    printf("wrong");
}

/* Function to print report */
void printReport(){
    printf(">> State of elevator in second %d <<\n",s);
    printf("\t * The current floor is %d\n", floornumber);
    opendoor ? printf("\t * Doors opened\n") : printf("\t * Doors closed\n");
    lightf1 ? printf("\t * Light f1 turn on\n") : printf("\t * Light f1 turn off\n");
    lightf2 ? printf("\t * Light f2 turn on\n") : printf("\t * Light f2 turn off\n");
    lightf3 ? printf("\t * Light f3 turn on\n") : printf("\t * Light f3 turn off\n");
    lightf4 ? printf("\t * Light f4 turn on\n") : printf("\t * Light f4 turn off\n");
    lightout ? printf("\t * Extern light turn on\n") : printf("\t * Extern light turn off\n");
}


/* Variables and function to mateint the automaton working */
struct itimerval delay;
struct sigaction handler;

void call_automaton(int s) {
    /* call to the automaton */
    ELEVATOR();
    if(setitimer(ITIMER_REAL,&delay,NULL)<0)
        perror("setitimer");
}


int main(int argc, char* argv[]) {

    /* Variables */
    int value;
    char str [100];


    /* Automata inicialization */
    ELEVATOR_reset();
    ELEVATOR();


    /* Configuration */
    handler.sa_handler=call_automaton;
    if(sigaction(SIGALRM,&handler,NULL)<0)
        perror("sigaction");

    delay.it_interval.tv_sec=0;
    delay.it_interval.tv_usec=0;
    delay.it_value.tv_sec=0;
    delay.it_value.tv_usec=1000;
    
    if(setitimer(ITIMER_REAL,&delay,NULL)<0)
        perror("setitimer");


    /* Commands loop */
    while(1) {
        sleep(10);
        printf("Put the next command (s-bx-cx-rep-q) : ");
        
        while(1) {
            char* res=fgets(str,99,stdin);
            if (res!=NULL)
                break;
            else if (errno!=EINTR)
            perror("gets");
        }

        /* Command reading */
        if(str[0]=='s'){
            printf("Second %d\n", ++s);
            ELEVATOR_I_SECOND();
        }
        else if(str[0]=='c')
            if(str[1]=='1'){
                //printf("c1\n");
                ELEVATOR_I_CALLF1();
            }
            else if(str[1]=='2'){
                //printf("c2\n");
                ELEVATOR_I_CALLF2();
            }
            else if(str[1]=='3'){
                //printf("c3\n");
                ELEVATOR_I_CALLF3();
            }
            else if(str[1]=='4'){
                //printf("c4\n");
                ELEVATOR_I_CALLF4();
            }
            else 
                printf("bad command\n");
        else if(str[0]=='b')
            if(str[1]=='1'){
                //printf("b1\n");
                ELEVATOR_I_GOF1();
            }
            else if(str[1]=='2'){
                //printf("b2\n");
                ELEVATOR_I_GOF2();
            }
            else if(str[1]=='3'){
                //printf("b3\n");
                ELEVATOR_I_GOF3();
            }
            else if(str[1]=='4'){
                //printf("b4\n");
                ELEVATOR_I_GOF4();
            }
            else 
                printf("bad command\n");
        else if((str[0]=='o') && (str[1]=='d')){
            //printf("op\n");
            ELEVATOR_I_OPENDOOR();
        }
        else if(str[0]=='q')
            exit(0);
        else if((str[0]=='r') && (str[1]=='e') && (str[2]=='p'))
            printReport();
        else
            printf("bad command\n");
    }

    exit(0);
}
