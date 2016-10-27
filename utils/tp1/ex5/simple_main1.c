#include <stdio.h>

void simple1(void);
void simple1_reset(void);
void simple1_I_IN(int a);

void simple1_O_OUT(int a) {

    printf("output signal: %d \n", a);

}

int main(int argc, char** argv) {

    int i;

    simple1_reset();
    simple1();
    for(i=0; i<10; i++) {
        simple1_I_IN(i);
        printf("Esterel program\n");
        simple1();
    }
}
