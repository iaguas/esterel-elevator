
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

// GLOBAL VARIABLES
int lightout = 0;
int lightf1 = 0;
int lightf2 = 0;
int lightf3 = 0;
int lightf4 = 0;
int opendoor = 0;
int floor = 1;



/* Fonctions generees par le compilateur esterel :
	- fonction d'appel de l'automate
	- fonction d'initialisation de l'automate
	- fonctions pour les signaux d'entree
*/

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
/*
void ELEVATOR_O_DOOROPENED(void);
void ELEVATOR_O_DOORCLOSED(void);
void ELEVATOR_O_CURRENTFLOOR(int);
void ELEVATOR_O_LF1(void);
void ELEVATOR_O_LF2(void);
void ELEVATOR_O_LF3(void);
void ELEVATOR_O_LF4(void);
void ELEVATOR_O_LOUT(void);
void ELEVATOR_O_WRONG(void);
void ELEVATOR_O_STOP(void);*/

void ELEVATOR_O_DOOROPENED(void){
    opendoor = 1;
    printf("puertas abiertas\n");
}

void ELEVATOR_O_DOORCLOSED(void){
    opendoor = 0;
    printf("puertas cerradas\n");
}

void ELEVATOR_O_CURRENTFLOOR(int i){
    floor = i;
    printf("el piso actual es %d\n", i);
}

void ELEVATOR_O_LF1(void){
    lightf1 != lightf1;
    /*if (lightf1)
        printf("Luz f1 apagada");
    else
        printf("Luz f1 encendida");*/
}

void ELEVATOR_O_LF2(void){
    lightf2 != lightf2;
    /*if (lightf2)
        printf("Luz f2 apagada");
    else
        printf("Luz f2 encendida");*/
}

void ELEVATOR_O_LF3(void){
    lightf3 != lightf3;
    /*if (lightf3)
        printf("Luz f3 apagada");
    else
        printf("Luz f3 encendida");*/
}

void ELEVATOR_O_LF4(void){
    lightf4 != lightf4;
    /*if (lightf4)
        printf("Luz f4 apagada");
    else
        printf("Luz f4 encendida");*/
}
void ELEVATOR_O_LOUT(void){
    lightout != lightout;
    /*if (lightout)
        printf("Luz fuera apagada");
    else
        printf("Luz fuera encendida");*/
}
void ELEVATOR_O_WRONG(void){
    printf("wrong");
}
void ELEVATOR_O_STOP(void){
    printf("stop");
}

/* Variables et fonctions necessaires pour activer 
    l'automate Esterel periodiquement */
struct itimerval delay;
struct sigaction handler;

void call_automaton(int s) {
    /* appel de l'automate */
    ELEVATOR();
    if(setitimer(ITIMER_REAL,&delay,NULL)<0)
        perror("setitimer");
}



int main(int argc, char* argv[]) {

    /* Pour la saisie au clavier */
    int value;
    char str [100];


    /* Initialisation de l'automate */
    ELEVATOR_reset();
    ELEVATOR();


    /* Mise en place de l'activation periodique de l'automate */
    handler.sa_handler=call_automaton;
    if(sigaction(SIGALRM,&handler,NULL)<0)
        perror("sigaction");

    delay.it_interval.tv_sec=0;
    delay.it_interval.tv_usec=0;
    delay.it_value.tv_sec=0;
    delay.it_value.tv_usec=1000;
    
    if(setitimer(ITIMER_REAL,&delay,NULL)<0)
        perror("setitimer");


    /* Saisie par l'utilisateur de la calculatrice */
    while(1) {
        sleep(10);
        printf("Put the next command/s (+/-*rs) :");
        
        while(1) {
            char* res=fgets(str,99,stdin);
            if (res!=NULL)
                break;
            else if (errno!=EINTR)
            perror("gets");
        }


        /* Positionnement des signaux d'entree selon la saisie de 
        faite par l'utilisateur */
        if(str[0]=='s'){
            printf("second\n");
            ELEVATOR_I_SECOND();
        }
        else if(str[0]=='c')
            if(str[1]=='1'){
                printf("c1\n");
                ELEVATOR_I_CALLF1();
            }
            else if(str[1]=='2'){
                printf("c2\n");
                ELEVATOR_I_CALLF2();
            }
            else if(str[1]=='3'){
                printf("c3\n");
                ELEVATOR_I_CALLF3();
            }
            else if(str[1]=='4'){
                printf("c4\n");
                ELEVATOR_I_CALLF4();
            }
            else 
                printf("bad command\n");
        else if(str[0]=='b')
            if(str[1]=='1'){
                printf("b1\n");
                ELEVATOR_I_GOF1();
            }
            else if(str[1]=='2'){
                printf("b2\n");
                ELEVATOR_I_GOF2();
            }
            else if(str[1]=='3'){
                printf("b3\n");
                ELEVATOR_I_GOF3();
            }
            else if(str[1]=='4'){
                printf("b4\n");
                ELEVATOR_I_GOF4();
            }
            else 
                printf("bad command\n");
        else if((str[0]=='o') && (str[1]=='d')){
            printf("op\n");
            ELEVATOR_I_OPENDOOR();
        }
        else if(str[0]=='q')
            exit(0);
        else
            printf("bad command\n");
    }

    exit(0);
}
