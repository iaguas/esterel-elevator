/* sscc : C CODE OF SORTED EQUATIONS calcul3 - SIMULATION MODE */

/* AUXILIARY DECLARATIONS */

#ifndef STRLEN
#define STRLEN 81
#endif
#define _COND(A,B,C) ((A)?(B):(C))
#ifdef TRACE_ACTION
#include <stdio.h>
#endif
#ifndef NULL
#define NULL ((char*)0)
#endif

#ifndef __EXEC_STATUS_H_LOADED
#define __EXEC_STATUS_H_LOADED

typedef struct {
unsigned int start:1;
unsigned int kill:1;
unsigned int active:1;
unsigned int suspended:1;
unsigned int prev_active:1;
unsigned int prev_suspended:1;
unsigned int exec_index;
unsigned int task_exec_index;
void (*pStart)();
void (*pRet)();
} __ExecStatus;

#endif
#define __ResetExecStatus(status) {\
   status.prev_active = status.active; \
   status.prev_suspended = status.suspended; \
   status.start = status.kill = status.active = status.suspended = 0; }
#define __DSZ(V) (--(V)<=0)
#define BASIC_TYPES_DEFINED
typedef int boolean;
typedef int integer;
typedef char* string;
#define CSIMUL_H_LOADED
typedef struct {char text[STRLEN];} symbolic;
extern void _boolean(boolean*, boolean);
extern boolean _eq_boolean(boolean, boolean);
extern boolean _ne_boolean(boolean, boolean);
extern boolean _cond_boolean(boolean ,boolean ,boolean);
extern char* _boolean_to_text(boolean);
extern int _check_boolean(char*);
extern void _text_to_boolean(boolean*, char*);
extern void _integer(integer*, integer);
extern boolean _eq_integer(integer, integer);
extern boolean _ne_integer(integer, integer);
extern integer _cond_integer(boolean ,integer ,integer);
extern char* _integer_to_text(integer);
extern int _check_integer(char*);
extern void _text_to_integer(integer*, char*);
extern void _string(string, string);
extern boolean _eq_string(string, string);
extern boolean _ne_string(string, string);
extern string _cond_string(boolean ,string ,string);
extern char* _string_to_text(string);
extern int _check_string(char*);
extern void _text_to_string(string, char*);
extern void _float(float*, float);
extern boolean _eq_float(float, float);
extern boolean _ne_float(float, float);
extern float _cond_float(boolean ,float ,float);
extern char* _float_to_text(float);
extern int _check_float(char*);
extern void _text_to_float(float*, char*);
extern void _double(double*, double);
extern boolean _eq_double(double, double);
extern boolean _ne_double(double, double);
extern double _cond_double(boolean ,double ,double);
extern char* _double_to_text(double);
extern int _check_double(char*);
extern void _text_to_double(double*, char*);
extern void _symbolic(symbolic*, symbolic);
extern boolean _eq_symbolic(symbolic, symbolic);
extern boolean _ne_symbolic(symbolic, symbolic);
extern symbolic _cond_symbolic(boolean ,symbolic ,symbolic);
extern char* _symbolic_to_text(symbolic);
extern int _check_symbolic(char*);
extern void _text_to_symbolic(symbolic*, char*);
extern char* __PredefinedTypeToText(int, char*);
#define _true 1
#define _false 0
#define __calcul3_GENERIC_TEST(TEST) return TEST;
typedef void (*__calcul3_APF)();
static __calcul3_APF *__calcul3_PActionArray;
static int **__calcul3_PCheckArray;
struct __SourcePoint {
int linkback;
int line;
int column;
int instance_index;
};
struct __InstanceEntry {
char *module_name;
int father_index;
char *dir_name;
char *file_name;
struct __SourcePoint source_point;
struct __SourcePoint end_point;
struct __SourcePoint instance_point;
};
struct __TaskEntry {
char *name;
int   nb_args_ref;
int   nb_args_val;
int  *type_codes_array;
struct __SourcePoint source_point;
};
struct __SignalEntry {
char *name;
int code;
int variable_index;
int present;
struct __SourcePoint source_point;
int number_of_emit_source_points;
struct __SourcePoint* emit_source_point_array;
int number_of_present_source_points;
struct __SourcePoint* present_source_point_array;
int number_of_access_source_points;
struct __SourcePoint* access_source_point_array;
};
struct __InputEntry {
char *name;
int hash;
char *type_name;
int is_a_sensor;
int type_code;
int multiple;
int signal_index;
int (*p_check_input)(char*);
void (*p_input_function)();
int present;
struct __SourcePoint source_point;
};
struct __ReturnEntry {
char *name;
int hash;
char *type_name;
int type_code;
int signal_index;
int exec_index;
int (*p_check_input)(char*);
void (*p_input_function)();
int present;
struct __SourcePoint source_point;
};
struct __ImplicationEntry {
int master;
int slave;
struct __SourcePoint source_point;
};
struct __ExclusionEntry {
int *exclusion_list;
struct __SourcePoint source_point;
};
struct __VariableEntry {
char *full_name;
char *short_name;
char *type_name;
int type_code;
int comment_kind;
int is_initialized;
char *p_variable;
char *source_name;
int written;
unsigned char written_in_transition;
unsigned char read_in_transition;
struct __SourcePoint source_point;
};
struct __ExecEntry {
int task_index;
int *var_indexes_array;
char **p_values_array;
struct __SourcePoint source_point;
};
struct __HaltEntry {
struct __SourcePoint source_point;
};
struct __NetEntry {
int known;
int value;
int number_of_source_points;
struct __SourcePoint* source_point_array;
};
struct __ModuleEntry {
char *version_id;
char *name;
int number_of_instances;
int number_of_tasks;
int number_of_signals;
int number_of_inputs;
int number_of_returns;
int number_of_sensors;
int number_of_outputs;
int number_of_locals;
int number_of_exceptions;
int number_of_implications;
int number_of_exclusions;
int number_of_variables;
int number_of_execs;
int number_of_halts;
int number_of_nets;
int number_of_states;
int state;
unsigned short *halt_list;
unsigned short *awaited_list;
unsigned short *emitted_list;
unsigned short *started_list;
unsigned short *killed_list;
unsigned short *suspended_list;
unsigned short *active_list;
int run_time_error_code;
int error_info;
void (*init)();
int (*run)();
int (*reset)();
char *(*show_variable)(int);
void (*set_variable)(int, char*, char*);
int (*check_value)(int, char*);
int (*execute_action)();
struct __InstanceEntry* instance_table;
struct __TaskEntry* task_table;
struct __SignalEntry* signal_table;
struct __InputEntry* input_table;
struct __ReturnEntry* return_table;
struct __ImplicationEntry* implication_table;
struct __ExclusionEntry* exclusion_table;
struct __VariableEntry* variable_table;
struct __ExecEntry* exec_table;
struct __HaltEntry* halt_table;
struct __NetEntry* net_table;
};

                           
/* EXTERN DECLARATIONS */

extern int __CheckVariables(int*);
extern void __ResetInput();
extern void __ResetExecs();
extern void __ResetVariables();
extern void __ResetVariableStatus();
extern void __AppendToList(unsigned short*, unsigned short);
extern void __ListCopy(unsigned short*, unsigned short**);
extern void __WriteVariable(int);
extern void __ResetVariable(int);
extern void __ResetModuleEntry();
extern void __ResetModuleEntryBeforeReaction();
extern void __ResetModuleEntryAfterReaction();
#ifndef _NO_EXTERN_DEFINITIONS
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static integer __calcul3_V0;
static boolean __calcul3_V1;
static boolean __calcul3_V2;
static boolean __calcul3_V3;
static boolean __calcul3_V4;
static boolean __calcul3_V5;
static boolean __calcul3_V6;
static boolean __calcul3_V7;
static integer __calcul3_V8;
static integer __calcul3_V9;
static integer __calcul3_V10;
static integer __calcul3_V11;
static integer __calcul3_V12;
static integer __calcul3_V13;

static unsigned short __calcul3_HaltList[7];
static unsigned short __calcul3_AwaitedList[11];
static unsigned short __calcul3_EmittedList[11];
static unsigned short __calcul3_StartedList[1];
static unsigned short __calcul3_KilledList[1];
static unsigned short __calcul3_SuspendedList[1];
static unsigned short __calcul3_ActiveList[1];
static unsigned short __calcul3_AllAwaitedList[11]={7,0,1,2,3,4,5,6};


/* INPUT FUNCTIONS */

void calcul3_I_OPERANDE (integer __V) {
__WriteVariable(0);
__calcul3_V0 = __V;
__calcul3_V1 = _true;
}
void calcul3_IS_OPERANDE (string __V) {
__WriteVariable(0);
_text_to_integer(&__calcul3_V0,__V);
__calcul3_V1 = _true;
}
void calcul3_I_ADDITION () {
__calcul3_V2 = _true;
}
void calcul3_IS_ADDITION () {
__calcul3_V2 = _true;
}
void calcul3_I_SOUSTRACTION () {
__calcul3_V3 = _true;
}
void calcul3_IS_SOUSTRACTION () {
__calcul3_V3 = _true;
}
void calcul3_I_DIVISION () {
__calcul3_V4 = _true;
}
void calcul3_IS_DIVISION () {
__calcul3_V4 = _true;
}
void calcul3_I_MULTIPLICATION () {
__calcul3_V5 = _true;
}
void calcul3_IS_MULTIPLICATION () {
__calcul3_V5 = _true;
}
void calcul3_I_RESET () {
__calcul3_V6 = _true;
}
void calcul3_IS_RESET () {
__calcul3_V6 = _true;
}
void calcul3_I_SWITCH () {
__calcul3_V7 = _true;
}
void calcul3_IS_SWITCH () {
__calcul3_V7 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int calcul3_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __calcul3_A1 () {
__calcul3_GENERIC_TEST(__calcul3_V1);
}
static int __calcul3_Check1 [] = {1,0,0};
static int __calcul3_A2 () {
__calcul3_GENERIC_TEST(__calcul3_V2);
}
static int __calcul3_Check2 [] = {1,0,0};
static int __calcul3_A3 () {
__calcul3_GENERIC_TEST(__calcul3_V3);
}
static int __calcul3_Check3 [] = {1,0,0};
static int __calcul3_A4 () {
__calcul3_GENERIC_TEST(__calcul3_V4);
}
static int __calcul3_Check4 [] = {1,0,0};
static int __calcul3_A5 () {
__calcul3_GENERIC_TEST(__calcul3_V5);
}
static int __calcul3_Check5 [] = {1,0,0};
static int __calcul3_A6 () {
__calcul3_GENERIC_TEST(__calcul3_V6);
}
static int __calcul3_Check6 [] = {1,0,0};
static int __calcul3_A7 () {
__calcul3_GENERIC_TEST(__calcul3_V7);
}
static int __calcul3_Check7 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __calcul3_A8 () {
#ifdef __OUTPUT
calcul3_O_LCD(__calcul3_V8);
#endif
__AppendToList(__calcul3_EmittedList,7);
}
static int __calcul3_Check8 [] = {1,0,0};
static void __calcul3_A9 () {
#ifdef __OUTPUT
calcul3_O_WRITE(__calcul3_V9);
#endif
__AppendToList(__calcul3_EmittedList,8);
}
static int __calcul3_Check9 [] = {1,0,0};

/* ASSIGNMENTS */

static void __calcul3_A10 () {
__calcul3_V1 = _false;
}
static int __calcul3_Check10 [] = {1,0,1,1};
static void __calcul3_A11 () {
__calcul3_V2 = _false;
}
static int __calcul3_Check11 [] = {1,0,1,2};
static void __calcul3_A12 () {
__calcul3_V3 = _false;
}
static int __calcul3_Check12 [] = {1,0,1,3};
static void __calcul3_A13 () {
__calcul3_V4 = _false;
}
static int __calcul3_Check13 [] = {1,0,1,4};
static void __calcul3_A14 () {
__calcul3_V5 = _false;
}
static int __calcul3_Check14 [] = {1,0,1,5};
static void __calcul3_A15 () {
__calcul3_V6 = _false;
}
static int __calcul3_Check15 [] = {1,0,1,6};
static void __calcul3_A16 () {
__calcul3_V7 = _false;
}
static int __calcul3_Check16 [] = {1,0,1,7};
static void __calcul3_A17 () {
__calcul3_V10 = 0;
}
static int __calcul3_Check17 [] = {1,0,1,10};
static void __calcul3_A18 () {
__calcul3_V11 = 0;
}
static int __calcul3_Check18 [] = {1,0,1,11};
static void __calcul3_A19 () {
__calcul3_V12 = 0;
}
static int __calcul3_Check19 [] = {1,0,1,12};
static void __calcul3_A20 () {
__calcul3_V13 = 0;
}
static int __calcul3_Check20 [] = {1,0,1,13};
static void __calcul3_A21 () {
__calcul3_V12 = __calcul3_V0;
}
static int __calcul3_Check21 [] = {1,1,0,1,12};
static void __calcul3_A22 () {
__calcul3_V13 = __calcul3_V0;
}
static int __calcul3_Check22 [] = {1,1,0,1,13};
static void __calcul3_A23 () {
__calcul3_V11 = __calcul3_V12+__calcul3_V13;
}
static int __calcul3_Check23 [] = {1,2,12,13,1,11};
static void __calcul3_A24 () {
__calcul3_V11 = __calcul3_V12-__calcul3_V13;
}
static int __calcul3_Check24 [] = {1,2,12,13,1,11};
static void __calcul3_A25 () {
__calcul3_V11 = __calcul3_V12/__calcul3_V13;
}
static int __calcul3_Check25 [] = {1,2,12,13,1,11};
static void __calcul3_A26 () {
__calcul3_V11 = __calcul3_V12*__calcul3_V13;
}
static int __calcul3_Check26 [] = {1,2,12,13,1,11};
static void __calcul3_A27 () {
__calcul3_V8 = __calcul3_V11;
}
static int __calcul3_Check27 [] = {1,1,11,1,8};
static void __calcul3_A28 () {
__calcul3_V9 = __calcul3_V11;
}
static int __calcul3_Check28 [] = {1,1,11,1,9};
static void __calcul3_A29 () {
__calcul3_V8 = 0;
}
static int __calcul3_Check29 [] = {1,0,1,8};
static void __calcul3_A30 () {
__calcul3_V10 = 1;
}
static int __calcul3_Check30 [] = {1,0,1,10};
static void __calcul3_A31 () {
__calcul3_V10 = 0;
}
static int __calcul3_Check31 [] = {1,0,1,10};

/* PROCEDURE CALLS */

/* CONDITIONS */

static int __calcul3_A32 () {
__calcul3_GENERIC_TEST(__calcul3_V10==1);
}
static int __calcul3_Check32 [] = {1,1,10,0};

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __calcul3_A33 () {
;
__ResetVariable(0);
}
static int __calcul3_Check33 [] = {1,0,0};
static void __calcul3_A34 () {
;
__ResetVariable(8);
}
static int __calcul3_Check34 [] = {1,0,0};
static void __calcul3_A35 () {
;
__ResetVariable(9);
}
static int __calcul3_Check35 [] = {1,0,0};
static void __calcul3_A36 () {
;
__ResetVariable(11);
}
static int __calcul3_Check36 [] = {1,0,0};
static void __calcul3_A37 () {
;
__ResetVariable(12);
}
static int __calcul3_Check37 [] = {1,0,0};
static void __calcul3_A38 () {
;
__ResetVariable(13);
}
static int __calcul3_Check38 [] = {1,0,0};

/* ACTION SEQUENCES */


static int *__calcul3_CheckArray[] = {
0,
__calcul3_Check1,
__calcul3_Check2,
__calcul3_Check3,
__calcul3_Check4,
__calcul3_Check5,
__calcul3_Check6,
__calcul3_Check7,
__calcul3_Check8,
__calcul3_Check9,
__calcul3_Check10,
__calcul3_Check11,
__calcul3_Check12,
__calcul3_Check13,
__calcul3_Check14,
__calcul3_Check15,
__calcul3_Check16,
__calcul3_Check17,
__calcul3_Check18,
__calcul3_Check19,
__calcul3_Check20,
__calcul3_Check21,
__calcul3_Check22,
__calcul3_Check23,
__calcul3_Check24,
__calcul3_Check25,
__calcul3_Check26,
__calcul3_Check27,
__calcul3_Check28,
__calcul3_Check29,
__calcul3_Check30,
__calcul3_Check31,
__calcul3_Check32,
__calcul3_Check33,
__calcul3_Check34,
__calcul3_Check35,
__calcul3_Check36,
__calcul3_Check37,
__calcul3_Check38
};
static int **__calcul3_PCheckArray =  __calcul3_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void calcul3_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __calcul3_show_variable (int __V) {
extern struct __VariableEntry __calcul3_VariableTable[];
struct __VariableEntry* p_var = &__calcul3_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __calcul3_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __calcul3_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __calcul3_InstanceTable [] = {
{"calcul3",0,"","calcul3.strl",{1,1,1,0},{1,60,1,0},{0,0,0,0}},
};

struct __SignalEntry __calcul3_SignalTable [] = {
{"OPERANDE",1,0,0,{1,3,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"ADDITION",33,0,0,{1,4,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"SOUSTRACTION",33,0,0,{1,5,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"DIVISION",33,0,0,{1,6,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"MULTIPLICATION",33,0,0,{1,7,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"RESET",33,0,0,{1,8,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"SWITCH",33,0,0,{1,9,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"LCD",2,8,0,{1,10,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"WRITE",2,9,0,{1,11,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"X",8,10,0,{1,13,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __calcul3_InputTable [] = {
{"OPERANDE",85,"integer",0,-3,0,0,_check_integer,calcul3_IS_OPERANDE,0,{1,3,11,0}},
{"ADDITION",83,0,0,-1,0,1,0,calcul3_IS_ADDITION,0,{1,4,11,0}},
{"SOUSTRACTION",33,0,0,-1,0,2,0,calcul3_IS_SOUSTRACTION,0,{1,5,11,0}},
{"DIVISION",7,0,0,-1,0,3,0,calcul3_IS_DIVISION,0,{1,6,11,0}},
{"MULTIPLICATION",60,0,0,-1,0,4,0,calcul3_IS_MULTIPLICATION,0,{1,7,11,0}},
{"RESET",84,0,0,-1,0,5,0,calcul3_IS_RESET,0,{1,8,11,0}},
{"SWITCH",62,0,0,-1,0,6,0,calcul3_IS_SWITCH,0,{1,9,11,0}}};

struct __VariableEntry __calcul3_VariableTable [] = {
{"__calcul3_V0","V0","integer",-3,1,0,(char*)&__calcul3_V0,"OPERANDE",0,0,0,{1,3,11,0}},
{"__calcul3_V1","V1","boolean",-2,2,0,(char*)&__calcul3_V1,"OPERANDE",0,0,0,{1,3,11,0}},
{"__calcul3_V2","V2","boolean",-2,2,0,(char*)&__calcul3_V2,"ADDITION",0,0,0,{1,4,11,0}},
{"__calcul3_V3","V3","boolean",-2,2,0,(char*)&__calcul3_V3,"SOUSTRACTION",0,0,0,{1,5,11,0}},
{"__calcul3_V4","V4","boolean",-2,2,0,(char*)&__calcul3_V4,"DIVISION",0,0,0,{1,6,11,0}},
{"__calcul3_V5","V5","boolean",-2,2,0,(char*)&__calcul3_V5,"MULTIPLICATION",0,0,0,{1,7,11,0}},
{"__calcul3_V6","V6","boolean",-2,2,0,(char*)&__calcul3_V6,"RESET",0,0,0,{1,8,11,0}},
{"__calcul3_V7","V7","boolean",-2,2,0,(char*)&__calcul3_V7,"SWITCH",0,0,0,{1,9,11,0}},
{"__calcul3_V8","V8","integer",-3,1,0,(char*)&__calcul3_V8,"LCD",0,0,0,{1,10,12,0}},
{"__calcul3_V9","V9","integer",-3,1,0,(char*)&__calcul3_V9,"WRITE",0,0,0,{1,11,12,0}},
{"__calcul3_V10","V10","integer",-3,1,0,(char*)&__calcul3_V10,"X",0,0,0,{1,13,12,0}},
{"__calcul3_V11","V11","integer",-3,0,0,(char*)&__calcul3_V11,"resultat",0,0,0,{1,14,13,0}},
{"__calcul3_V12","V12","integer",-3,0,0,(char*)&__calcul3_V12,"op1",0,0,0,{1,14,23,0}},
{"__calcul3_V13","V13","integer",-3,0,0,(char*)&__calcul3_V13,"op2",0,0,0,{1,14,28,0}}
};

struct __HaltEntry __calcul3_HaltTable [] = {
{{1,60,1,0}},
{{1,21,21,0}},
{{1,23,21,0}},
{{1,26,21,0}},
{{1,52,13,0}},
{{1,54,13,0}}
};


static void __calcul3__reset_input () {
__calcul3_V1 = _false;
__calcul3_V2 = _false;
__calcul3_V3 = _false;
__calcul3_V4 = _false;
__calcul3_V5 = _false;
__calcul3_V6 = _false;
__calcul3_V7 = _false;
}


/* MODULE DATA FOR SIMULATION */

int calcul3();
int calcul3_reset();

static struct __ModuleEntry __calcul3_ModuleData = {
"Simulation interface release 5","calcul3",
1,0,10,7,0,0,2,1,0,0,0,14,0,6,0,0,0,
__calcul3_HaltList,
__calcul3_AwaitedList,
__calcul3_EmittedList,
__calcul3_StartedList,
__calcul3_KilledList,
__calcul3_SuspendedList,
__calcul3_ActiveList,
0,0,
calcul3_initialize,calcul3,calcul3_reset,
__calcul3_show_variable,__calcul3_set_variable,__calcul3_check_value,0,
__calcul3_InstanceTable,
0,
__calcul3_SignalTable,__calcul3_InputTable,0,
0,0,
__calcul3_VariableTable,
0,
__calcul3_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __calcul3_R[6] = {_true,
 _false,
 _false,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int calcul3 () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[20];

__calcul3_ModuleData.awaited_list = __calcul3_AwaitedList;
__ResetModuleEntryBeforeReaction();
E[0] = __calcul3_R[1]||__calcul3_R[2]||__calcul3_R[3];
E[1] = E[0]&&!(__calcul3_R[0]);
E[2] = E[1]&&(__CheckVariables(__calcul3_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__calcul3_A6());
if (E[2]) {
__CheckVariables(__calcul3_CheckArray[29]);__calcul3_A29();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A29\n");
#endif
}
E[1] = E[1]&&!((__CheckVariables(__calcul3_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__calcul3_A6()));
E[3] = __calcul3_R[3]&&E[1];
E[4] = E[3]&&(__CheckVariables(__calcul3_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__calcul3_A2());
if (E[4]) {
__CheckVariables(__calcul3_CheckArray[23]);__calcul3_A23();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A23\n");
#endif
}
E[3] = E[3]&&!((__CheckVariables(__calcul3_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__calcul3_A2()));
E[5] = E[3]&&(__CheckVariables(__calcul3_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__calcul3_A3());
if (E[5]) {
__CheckVariables(__calcul3_CheckArray[24]);__calcul3_A24();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A24\n");
#endif
}
E[3] = E[3]&&!((__CheckVariables(__calcul3_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__calcul3_A3()));
E[6] = E[3]&&(__CheckVariables(__calcul3_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__calcul3_A4());
if (E[6]) {
__CheckVariables(__calcul3_CheckArray[25]);__calcul3_A25();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A25\n");
#endif
}
E[3] = E[3]&&!((__CheckVariables(__calcul3_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__calcul3_A4()));
E[7] = E[3]&&(__CheckVariables(__calcul3_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__calcul3_A5());
if (E[7]) {
__CheckVariables(__calcul3_CheckArray[26]);__calcul3_A26();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A26\n");
#endif
}
E[8] = E[4]||E[5]||E[6]||E[7];
if (E[8]) {
__CheckVariables(__calcul3_CheckArray[27]);__calcul3_A27();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A27\n");
#endif
}
if (E[2]||E[8]) {
__AppendToList(__calcul3_EmittedList,7);
}
if (E[2]||E[8]) {
__CheckVariables(__calcul3_CheckArray[8]);__calcul3_A8();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A8\n");
#endif
}
E[9] = __calcul3_R[4]&&!(__calcul3_R[0]);
E[10] = E[9]&&(__CheckVariables(__calcul3_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__calcul3_A7());
if (E[10]) {
__CheckVariables(__calcul3_CheckArray[30]);__calcul3_A30();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A30\n");
#endif
}
E[11] = __calcul3_R[5]&&!(__calcul3_R[0]);
E[12] = E[11]&&(__CheckVariables(__calcul3_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__calcul3_A7());
if (E[12]) {
__CheckVariables(__calcul3_CheckArray[31]);__calcul3_A31();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A31\n");
#endif
}
E[13] = E[8]&&(__CheckVariables(__calcul3_CheckArray[32]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 32\n"),
#endif
__calcul3_A32());
if (E[13]) {
__AppendToList(__calcul3_EmittedList,8);
}
if (E[13]) {
__CheckVariables(__calcul3_CheckArray[28]);__calcul3_A28();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A28\n");
#endif
}
if (E[13]) {
__CheckVariables(__calcul3_CheckArray[9]);__calcul3_A9();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A9\n");
#endif
}
E[14] = E[10]||E[12];
if (E[14]) {
__AppendToList(__calcul3_EmittedList,9);
}
E[15] = __calcul3_R[0]&&!((__CheckVariables(__calcul3_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul3_A1()));
if (E[15]) {
__CheckVariables(__calcul3_CheckArray[33]);__calcul3_A33();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A33\n");
#endif
}
if (__calcul3_R[0]) {
__CheckVariables(__calcul3_CheckArray[34]);__calcul3_A34();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A34\n");
#endif
}
if (__calcul3_R[0]) {
__CheckVariables(__calcul3_CheckArray[35]);__calcul3_A35();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A35\n");
#endif
}
E[16] = !(_true);
if (__calcul3_R[0]) {
__CheckVariables(__calcul3_CheckArray[17]);__calcul3_A17();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A17\n");
#endif
}
if (__calcul3_R[0]) {
__CheckVariables(__calcul3_CheckArray[36]);__calcul3_A36();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A36\n");
#endif
}
if (__calcul3_R[0]) {
__CheckVariables(__calcul3_CheckArray[37]);__calcul3_A37();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A37\n");
#endif
}
if (__calcul3_R[0]) {
__CheckVariables(__calcul3_CheckArray[38]);__calcul3_A38();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A38\n");
#endif
}
E[17] = __calcul3_R[0]||E[2]||E[13]||(E[8]&&!(E[13]));
if (E[17]) {
__CheckVariables(__calcul3_CheckArray[18]);__calcul3_A18();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A18\n");
#endif
}
if (E[17]) {
__CheckVariables(__calcul3_CheckArray[19]);__calcul3_A19();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A19\n");
#endif
}
if (E[17]) {
__CheckVariables(__calcul3_CheckArray[20]);__calcul3_A20();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A20\n");
#endif
}
E[18] = __calcul3_R[1]&&E[1];
E[19] = E[18]&&!((__CheckVariables(__calcul3_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul3_A1()));
__calcul3_R[1] = E[17]||(__calcul3_R[1]&&E[19]);
E[18] = E[18]&&(__CheckVariables(__calcul3_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul3_A1());
if (E[18]) {
__CheckVariables(__calcul3_CheckArray[21]);__calcul3_A21();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A21\n");
#endif
}
E[1] = __calcul3_R[2]&&E[1];
E[19] = E[1]&&!((__CheckVariables(__calcul3_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul3_A1()));
__calcul3_R[2] = E[18]||(__calcul3_R[2]&&E[19]);
E[1] = E[1]&&(__CheckVariables(__calcul3_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul3_A1());
if (E[1]) {
__CheckVariables(__calcul3_CheckArray[22]);__calcul3_A22();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A22\n");
#endif
}
E[3] = E[3]&&!((__CheckVariables(__calcul3_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__calcul3_A5()));
__calcul3_R[3] = E[1]||(__calcul3_R[3]&&E[3]);
E[9] = E[9]&&!((__CheckVariables(__calcul3_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__calcul3_A7()));
E[9] = __calcul3_R[0]||E[12]||(__calcul3_R[4]&&E[9]);
E[11] = E[11]&&!((__CheckVariables(__calcul3_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__calcul3_A7()));
E[11] = E[10]||(__calcul3_R[5]&&E[11]);
E[3] = __calcul3_R[4]||__calcul3_R[5];
E[19] = E[0]||E[3];
E[3] = (__calcul3_R[1]||__calcul3_R[2]||__calcul3_R[3]||E[9]||E[11])&&((E[19]&&!(E[0]))||__calcul3_R[1]||__calcul3_R[2]||__calcul3_R[3])&&((E[19]&&!(E[3]))||E[9]||E[11]);
__calcul3_R[0] = !(_true);
if (__calcul3_R[1]) { __AppendToList(__calcul3_HaltList,1); }
if (__calcul3_R[2]) { __AppendToList(__calcul3_HaltList,2); }
if (__calcul3_R[3]) { __AppendToList(__calcul3_HaltList,3); }
__calcul3_R[4] = E[9];
if (__calcul3_R[4]) { __AppendToList(__calcul3_HaltList,4); }
__calcul3_R[5] = E[11];
if (__calcul3_R[5]) { __AppendToList(__calcul3_HaltList,5); }
if (!E[3]) { __AppendToList(__calcul3_HaltList,0); }
__ResetModuleEntryAfterReaction();
__calcul3_ModuleData.awaited_list = __calcul3_AllAwaitedList;
__calcul3__reset_input();
return E[3];
}

/* AUTOMATON RESET */

int calcul3_reset () {
__calcul3_ModuleData.awaited_list = __calcul3_AwaitedList;
__ResetModuleEntry();
__calcul3_ModuleData.awaited_list = __calcul3_AllAwaitedList;
__calcul3_ModuleData.state = 0;
__calcul3_R[0] = _true;
__calcul3_R[1] = _false;
__calcul3_R[2] = _false;
__calcul3_R[3] = _false;
__calcul3_R[4] = _false;
__calcul3_R[5] = _false;
__calcul3__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__calcul3_ModuleData
};
