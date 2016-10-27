#include <stdio.h>

void simple3(void);
void simple3_reset(void);
void simple3_I_IN(int a);

void simple3_O_OUT(int a) {

    printf("output signal: %d \n", a);

}

int main(int argc, char** argv) {

    int i;

    simple3_reset();
    simple3();
    for(i=0; i<10; i++) {
        simple3_I_IN(i);
        printf("Esterel program\n");
        simple3();
    }
}
