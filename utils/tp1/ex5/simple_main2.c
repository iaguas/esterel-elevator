#include <stdio.h>

void simple2(void);
void simple2_reset(void);
void simple2_I_IN(int a);

void simple2_O_OUT(int a) {

    printf("output signal: %d \n", a);

}

int main(int argc, char** argv) {

    int i;

    simple2_reset();
    simple2();
    for(i=0; i<10; i++) {
        simple2_I_IN(i);
        printf("Esterel program\n");
        simple2();
    }
}
