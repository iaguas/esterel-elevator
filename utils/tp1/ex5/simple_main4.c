#include <stdio.h>

void simple4(void);
void simple4_reset(void);
void simple4_I_IN(int a);

void simple4_O_OUT(int a) {

    printf("output signal: %d \n", a);

}

int main(int argc, char** argv) {

    int i;

    simple4_reset();
    simple4();
    for(i=0; i<10; i++) {
        simple4_I_IN(i);
        printf("Esterel program\n");

        if((i%5) == 4)
            simple4_reset();
        simple4();
    }
}
