#Elevator Project
Project for the subject "Critical Application Development" of ESIEE Paris. It implements the controller of an elevator.

## Project description
All the information about the project can be discovered [here](https://github.com/iaguas/esterel-elevator/blob/master/doc/Project.pdf)

## Compilation and simulation
There is a `makefile` programed to make all in a computer with esterel installed. There are several options:

* Simulation mode
 + `simul-comp`: Compilation for using the simulation mode.
 + `simul32`: Simulation mode for 32 bits core.
 + `simul64`: Simulation mode for 64 bits core.
* Cleaning mode
 + `clean`: Option to remove binary files.
 + `cleanall`: Option to remove binary files and other generated files.

## Esterel instalation
All the files needed to install the esterel enviroment are [here](http://www.di.ens.fr/~pouzet/cours/mpri/esterelv5_92.linux.tar). The only thing to do is follow the README instructions.
