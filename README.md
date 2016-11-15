# Esterel Elevator Project
Project for the subject "Critical Application Development" of ESIEE Paris. It implements the controller of an elevator.

## Project description
All the information about the project can be discovered [here](https://github.com/iaguas/esterel-elevator/blob/master/doc/Project.pdf). The extra asumptions will be described now.

### Extra asumtions
* The elevator starts at 1st floor.
* The elevator starts with doors closed.
* All the lights starts off and the buttons not pushed.

### Project report
The report of the project can be discovered [here](https://github.com/iaguas/esterel-elevator/blob/master/doc/report.pdf). Inside is described all the caracteristics, comments and conclutions about this project.

## Compilation and simulation
There is a `makefile` programed to make all in a computer with esterel installed. There are several options:

* Simulation mode
 + `simul-comp`: Compilation for using the simulation mode.
 + `simul32`: Simulation mode for 32 bits core.
 + `simul64`: Simulation mode for 64 bits core.
* C interface mode
 + `c-comp`: Compilation for using the C interface mode.
 + `c`: Execution for C interface mode.
* Cleaning mode
 + `clean`: Option to remove binary files.
 + `cleanall`: Option to remove binary files and other generated files.

## Esterel instalation
All the files needed to install the esterel enviroment are [here](http://www.di.ens.fr/~pouzet/cours/mpri/esterelv5_92.linux.tar). The only thing to do is follow the README instructions.

In the `/utils` directory can be discovered a file that defines the esterel grammar to use with a GtkSourceView program. Also 

## Previous practical work
In the `/utils` directory can be discovered some exercises about esterel y lustre. 

