# Elevator Project
Project for the subject "Critical Application Development" of ESIEE Paris. It implements the controller of an elevator.

## Project information
All the information about the project can be discovered [here](https://github.com/iaguas/esterel-elevator/blob/master/doc/Project.pdf)

## Compilation and simulation
```
esterel -simul cabin.strl
gcc -c -m32 cabin.c
xes -Xcomp -m32 cabin.o

```
In the 32 bits version tags `-m32` and `-Xcomp` can be omited.
