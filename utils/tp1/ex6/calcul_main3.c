
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

/* Fonctions generees par le compilateur esterel :
	- fonction d'appel de l'automate
	- fonction d'initialisation de l'automate
	- fonctions pour les signaux d'entree
*/

void calcul3(void);
void calcul3_reset(void);
void calcul3_I_OPERANDE(int i);
void calcul3_I_ADDITION(void);
void calcul3_I_SOUSTRACTION(void);
void calcul3_I_DIVISION(void);
void calcul3_I_MULTIPLICATION(void);
void calcul3_I_RESET(void);
void calcul3_I_SWITCH(void);

/* Fonction pour le signal de sortie, a ecrire par le programmeur */
void calcul3_O_LCD(int i) {
	printf("LCD = %d\n",i);
}

/* Fonction pour ecrire */
void calcul3_O_WRITE(int i) {
    FILE *f;
    
    f = fopen("numbers.txt","a");
    fprintf(f, "%d\n", i);
    fclose(f);
}

/* Variables et fonctions necessaires pour activer 
    l'automate Esterel periodiquement */
struct itimerval delay;
struct sigaction handler;

void call_automaton(int s) {
    /* appel de l'automate */
    calcul3();
    if(setitimer(ITIMER_REAL,&delay,NULL)<0)
        perror("setitimer");
}



int main(int argc, char* argv[]) {

    /* Pour la saisie au clavier */
    int value;
    char s [100];


    /* Initialisation de l'automate */
    calcul3_reset();
    calcul3();


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
        printf("Saisir un operande ou un operateur (+/-*rs) :");
        
        while(1) {
            char* res=fgets(s,99,stdin);
            if (res!=NULL)
                break;
            else if (errno!=EINTR)
            perror("gets");
        }


        /* Positionnement des signaux d'entree selon la saisie de 
        faite par l'utilisateur */
        if(sscanf(s,"%d",&value)==1)
            calcul3_I_OPERANDE(value);
        else if(strchr(s,'+')!=NULL)
            calcul3_I_ADDITION();
        else if(strchr(s,'-')!=NULL)
            calcul3_I_SOUSTRACTION();
        else if(strchr(s,'*')!=NULL)
            calcul3_I_MULTIPLICATION();
        else if(strchr(s,'/')!=NULL)
            calcul3_I_DIVISION();
        else if(strchr(s,'r')!=NULL)
            calcul3_I_RESET();
        else if(strchr(s,'s')!=NULL)
            calcul3_I_SWITCH();
        else printf("Erreur de saisie !\n");
    }

    exit(0);
}
