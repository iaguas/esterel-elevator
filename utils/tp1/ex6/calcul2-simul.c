/* sscc : C CODE OF SORTED EQUATIONS calcul2 - SIMULATION MODE */

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
#define __calcul2_GENERIC_TEST(TEST) return TEST;
typedef void (*__calcul2_APF)();
static __calcul2_APF *__calcul2_PActionArray;
static int **__calcul2_PCheckArray;
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

static integer __calcul2_V0;
static boolean __calcul2_V1;
static boolean __calcul2_V2;
static boolean __calcul2_V3;
static boolean __calcul2_V4;
static boolean __calcul2_V5;
static boolean __calcul2_V6;
static integer __calcul2_V7;
static integer __calcul2_V8;
static integer __calcul2_V9;
static integer __calcul2_V10;

static unsigned short __calcul2_HaltList[5];
static unsigned short __calcul2_AwaitedList[8];
static unsigned short __calcul2_EmittedList[8];
static unsigned short __calcul2_StartedList[1];
static unsigned short __calcul2_KilledList[1];
static unsigned short __calcul2_SuspendedList[1];
static unsigned short __calcul2_ActiveList[1];
static unsigned short __calcul2_AllAwaitedList[8]={6,0,1,2,3,4,5};


/* INPUT FUNCTIONS */

void calcul2_I_OPERANDE (integer __V) {
__WriteVariable(0);
__calcul2_V0 = __V;
__calcul2_V1 = _true;
}
void calcul2_IS_OPERANDE (string __V) {
__WriteVariable(0);
_text_to_integer(&__calcul2_V0,__V);
__calcul2_V1 = _true;
}
void calcul2_I_ADDITION () {
__calcul2_V2 = _true;
}
void calcul2_IS_ADDITION () {
__calcul2_V2 = _true;
}
void calcul2_I_SOUSTRACTION () {
__calcul2_V3 = _true;
}
void calcul2_IS_SOUSTRACTION () {
__calcul2_V3 = _true;
}
void calcul2_I_DIVISION () {
__calcul2_V4 = _true;
}
void calcul2_IS_DIVISION () {
__calcul2_V4 = _true;
}
void calcul2_I_MULTIPLICATION () {
__calcul2_V5 = _true;
}
void calcul2_IS_MULTIPLICATION () {
__calcul2_V5 = _true;
}
void calcul2_I_RESET () {
__calcul2_V6 = _true;
}
void calcul2_IS_RESET () {
__calcul2_V6 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int calcul2_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __calcul2_A1 () {
__calcul2_GENERIC_TEST(__calcul2_V1);
}
static int __calcul2_Check1 [] = {1,0,0};
static int __calcul2_A2 () {
__calcul2_GENERIC_TEST(__calcul2_V2);
}
static int __calcul2_Check2 [] = {1,0,0};
static int __calcul2_A3 () {
__calcul2_GENERIC_TEST(__calcul2_V3);
}
static int __calcul2_Check3 [] = {1,0,0};
static int __calcul2_A4 () {
__calcul2_GENERIC_TEST(__calcul2_V4);
}
static int __calcul2_Check4 [] = {1,0,0};
static int __calcul2_A5 () {
__calcul2_GENERIC_TEST(__calcul2_V5);
}
static int __calcul2_Check5 [] = {1,0,0};
static int __calcul2_A6 () {
__calcul2_GENERIC_TEST(__calcul2_V6);
}
static int __calcul2_Check6 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __calcul2_A7 () {
#ifdef __OUTPUT
calcul2_O_LCD(__calcul2_V7);
#endif
__AppendToList(__calcul2_EmittedList,6);
}
static int __calcul2_Check7 [] = {1,0,0};

/* ASSIGNMENTS */

static void __calcul2_A8 () {
__calcul2_V1 = _false;
}
static int __calcul2_Check8 [] = {1,0,1,1};
static void __calcul2_A9 () {
__calcul2_V2 = _false;
}
static int __calcul2_Check9 [] = {1,0,1,2};
static void __calcul2_A10 () {
__calcul2_V3 = _false;
}
static int __calcul2_Check10 [] = {1,0,1,3};
static void __calcul2_A11 () {
__calcul2_V4 = _false;
}
static int __calcul2_Check11 [] = {1,0,1,4};
static void __calcul2_A12 () {
__calcul2_V5 = _false;
}
static int __calcul2_Check12 [] = {1,0,1,5};
static void __calcul2_A13 () {
__calcul2_V6 = _false;
}
static int __calcul2_Check13 [] = {1,0,1,6};
static void __calcul2_A14 () {
__calcul2_V8 = 0;
}
static int __calcul2_Check14 [] = {1,0,1,8};
static void __calcul2_A15 () {
__calcul2_V9 = 0;
}
static int __calcul2_Check15 [] = {1,0,1,9};
static void __calcul2_A16 () {
__calcul2_V10 = 0;
}
static int __calcul2_Check16 [] = {1,0,1,10};
static void __calcul2_A17 () {
__calcul2_V9 = __calcul2_V0;
}
static int __calcul2_Check17 [] = {1,1,0,1,9};
static void __calcul2_A18 () {
__calcul2_V10 = __calcul2_V0;
}
static int __calcul2_Check18 [] = {1,1,0,1,10};
static void __calcul2_A19 () {
__calcul2_V8 = __calcul2_V9+__calcul2_V10;
}
static int __calcul2_Check19 [] = {1,2,9,10,1,8};
static void __calcul2_A20 () {
__calcul2_V8 = __calcul2_V9-__calcul2_V10;
}
static int __calcul2_Check20 [] = {1,2,9,10,1,8};
static void __calcul2_A21 () {
__calcul2_V8 = __calcul2_V9/__calcul2_V10;
}
static int __calcul2_Check21 [] = {1,2,9,10,1,8};
static void __calcul2_A22 () {
__calcul2_V8 = __calcul2_V9*__calcul2_V10;
}
static int __calcul2_Check22 [] = {1,2,9,10,1,8};
static void __calcul2_A23 () {
__calcul2_V7 = __calcul2_V8;
}
static int __calcul2_Check23 [] = {1,1,8,1,7};
static void __calcul2_A24 () {
__calcul2_V7 = 0;
}
static int __calcul2_Check24 [] = {1,0,1,7};

/* PROCEDURE CALLS */

/* CONDITIONS */

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __calcul2_A25 () {
;
__ResetVariable(0);
}
static int __calcul2_Check25 [] = {1,0,0};
static void __calcul2_A26 () {
;
__ResetVariable(7);
}
static int __calcul2_Check26 [] = {1,0,0};
static void __calcul2_A27 () {
;
__ResetVariable(8);
}
static int __calcul2_Check27 [] = {1,0,0};
static void __calcul2_A28 () {
;
__ResetVariable(9);
}
static int __calcul2_Check28 [] = {1,0,0};
static void __calcul2_A29 () {
;
__ResetVariable(10);
}
static int __calcul2_Check29 [] = {1,0,0};

/* ACTION SEQUENCES */


static int *__calcul2_CheckArray[] = {
0,
__calcul2_Check1,
__calcul2_Check2,
__calcul2_Check3,
__calcul2_Check4,
__calcul2_Check5,
__calcul2_Check6,
__calcul2_Check7,
__calcul2_Check8,
__calcul2_Check9,
__calcul2_Check10,
__calcul2_Check11,
__calcul2_Check12,
__calcul2_Check13,
__calcul2_Check14,
__calcul2_Check15,
__calcul2_Check16,
__calcul2_Check17,
__calcul2_Check18,
__calcul2_Check19,
__calcul2_Check20,
__calcul2_Check21,
__calcul2_Check22,
__calcul2_Check23,
__calcul2_Check24,
__calcul2_Check25,
__calcul2_Check26,
__calcul2_Check27,
__calcul2_Check28,
__calcul2_Check29
};
static int **__calcul2_PCheckArray =  __calcul2_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void calcul2_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __calcul2_show_variable (int __V) {
extern struct __VariableEntry __calcul2_VariableTable[];
struct __VariableEntry* p_var = &__calcul2_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __calcul2_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __calcul2_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __calcul2_InstanceTable [] = {
{"calcul2",0,"","calcul2.strl",{1,1,1,0},{1,41,1,0},{0,0,0,0}},
};

struct __SignalEntry __calcul2_SignalTable [] = {
{"OPERANDE",1,0,0,{1,3,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"ADDITION",33,0,0,{1,4,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"SOUSTRACTION",33,0,0,{1,5,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"DIVISION",33,0,0,{1,6,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"MULTIPLICATION",33,0,0,{1,7,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"RESET",33,0,0,{1,8,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"LCD",2,7,0,{1,9,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __calcul2_InputTable [] = {
{"OPERANDE",85,"integer",0,-3,0,0,_check_integer,calcul2_IS_OPERANDE,0,{1,3,11,0}},
{"ADDITION",83,0,0,-1,0,1,0,calcul2_IS_ADDITION,0,{1,4,11,0}},
{"SOUSTRACTION",33,0,0,-1,0,2,0,calcul2_IS_SOUSTRACTION,0,{1,5,11,0}},
{"DIVISION",7,0,0,-1,0,3,0,calcul2_IS_DIVISION,0,{1,6,11,0}},
{"MULTIPLICATION",60,0,0,-1,0,4,0,calcul2_IS_MULTIPLICATION,0,{1,7,11,0}},
{"RESET",84,0,0,-1,0,5,0,calcul2_IS_RESET,0,{1,8,11,0}}};

struct __VariableEntry __calcul2_VariableTable [] = {
{"__calcul2_V0","V0","integer",-3,1,0,(char*)&__calcul2_V0,"OPERANDE",0,0,0,{1,3,11,0}},
{"__calcul2_V1","V1","boolean",-2,2,0,(char*)&__calcul2_V1,"OPERANDE",0,0,0,{1,3,11,0}},
{"__calcul2_V2","V2","boolean",-2,2,0,(char*)&__calcul2_V2,"ADDITION",0,0,0,{1,4,11,0}},
{"__calcul2_V3","V3","boolean",-2,2,0,(char*)&__calcul2_V3,"SOUSTRACTION",0,0,0,{1,5,11,0}},
{"__calcul2_V4","V4","boolean",-2,2,0,(char*)&__calcul2_V4,"DIVISION",0,0,0,{1,6,11,0}},
{"__calcul2_V5","V5","boolean",-2,2,0,(char*)&__calcul2_V5,"MULTIPLICATION",0,0,0,{1,7,11,0}},
{"__calcul2_V6","V6","boolean",-2,2,0,(char*)&__calcul2_V6,"RESET",0,0,0,{1,8,11,0}},
{"__calcul2_V7","V7","integer",-3,1,0,(char*)&__calcul2_V7,"LCD",0,0,0,{1,9,12,0}},
{"__calcul2_V8","V8","integer",-3,0,0,(char*)&__calcul2_V8,"resultat",0,0,0,{1,11,9,0}},
{"__calcul2_V9","V9","integer",-3,0,0,(char*)&__calcul2_V9,"op1",0,0,0,{1,11,19,0}},
{"__calcul2_V10","V10","integer",-3,0,0,(char*)&__calcul2_V10,"op2",0,0,0,{1,11,24,0}}
};

struct __HaltEntry __calcul2_HaltTable [] = {
{{1,41,1,0}},
{{1,18,17,0}},
{{1,20,17,0}},
{{1,23,17,0}}
};


static void __calcul2__reset_input () {
__calcul2_V1 = _false;
__calcul2_V2 = _false;
__calcul2_V3 = _false;
__calcul2_V4 = _false;
__calcul2_V5 = _false;
__calcul2_V6 = _false;
}


/* MODULE DATA FOR SIMULATION */

int calcul2();
int calcul2_reset();

static struct __ModuleEntry __calcul2_ModuleData = {
"Simulation interface release 5","calcul2",
1,0,7,6,0,0,1,0,0,0,0,11,0,4,0,0,0,
__calcul2_HaltList,
__calcul2_AwaitedList,
__calcul2_EmittedList,
__calcul2_StartedList,
__calcul2_KilledList,
__calcul2_SuspendedList,
__calcul2_ActiveList,
0,0,
calcul2_initialize,calcul2,calcul2_reset,
__calcul2_show_variable,__calcul2_set_variable,__calcul2_check_value,0,
__calcul2_InstanceTable,
0,
__calcul2_SignalTable,__calcul2_InputTable,0,
0,0,
__calcul2_VariableTable,
0,
__calcul2_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __calcul2_R[4] = {_true,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int calcul2 () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[13];

__calcul2_ModuleData.awaited_list = __calcul2_AwaitedList;
__ResetModuleEntryBeforeReaction();
E[0] = (__calcul2_R[1]||__calcul2_R[2]||__calcul2_R[3])&&!(__calcul2_R[0]);
E[1] = E[0]&&(__CheckVariables(__calcul2_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__calcul2_A6());
if (E[1]) {
__CheckVariables(__calcul2_CheckArray[24]);__calcul2_A24();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A24\n");
#endif
}
E[0] = E[0]&&!((__CheckVariables(__calcul2_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__calcul2_A6()));
E[2] = __calcul2_R[3]&&E[0];
E[3] = E[2]&&(__CheckVariables(__calcul2_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__calcul2_A2());
if (E[3]) {
__CheckVariables(__calcul2_CheckArray[19]);__calcul2_A19();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A19\n");
#endif
}
E[2] = E[2]&&!((__CheckVariables(__calcul2_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__calcul2_A2()));
E[4] = E[2]&&(__CheckVariables(__calcul2_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__calcul2_A3());
if (E[4]) {
__CheckVariables(__calcul2_CheckArray[20]);__calcul2_A20();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A20\n");
#endif
}
E[2] = E[2]&&!((__CheckVariables(__calcul2_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__calcul2_A3()));
E[5] = E[2]&&(__CheckVariables(__calcul2_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__calcul2_A4());
if (E[5]) {
__CheckVariables(__calcul2_CheckArray[21]);__calcul2_A21();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A21\n");
#endif
}
E[2] = E[2]&&!((__CheckVariables(__calcul2_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__calcul2_A4()));
E[6] = E[2]&&(__CheckVariables(__calcul2_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__calcul2_A5());
if (E[6]) {
__CheckVariables(__calcul2_CheckArray[22]);__calcul2_A22();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A22\n");
#endif
}
E[7] = E[3]||E[4]||E[5]||E[6];
if (E[7]) {
__CheckVariables(__calcul2_CheckArray[23]);__calcul2_A23();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A23\n");
#endif
}
if (E[1]||E[7]) {
__AppendToList(__calcul2_EmittedList,6);
}
if (E[1]||E[7]) {
__CheckVariables(__calcul2_CheckArray[7]);__calcul2_A7();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A7\n");
#endif
}
E[8] = __calcul2_R[0]&&!((__CheckVariables(__calcul2_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul2_A1()));
if (E[8]) {
__CheckVariables(__calcul2_CheckArray[25]);__calcul2_A25();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A25\n");
#endif
}
if (__calcul2_R[0]) {
__CheckVariables(__calcul2_CheckArray[26]);__calcul2_A26();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A26\n");
#endif
}
E[9] = !(_true);
if (__calcul2_R[0]) {
__CheckVariables(__calcul2_CheckArray[27]);__calcul2_A27();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A27\n");
#endif
}
if (__calcul2_R[0]) {
__CheckVariables(__calcul2_CheckArray[28]);__calcul2_A28();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A28\n");
#endif
}
if (__calcul2_R[0]) {
__CheckVariables(__calcul2_CheckArray[29]);__calcul2_A29();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A29\n");
#endif
}
E[10] = __calcul2_R[0]||E[1]||E[7];
if (E[10]) {
__CheckVariables(__calcul2_CheckArray[14]);__calcul2_A14();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A14\n");
#endif
}
if (E[10]) {
__CheckVariables(__calcul2_CheckArray[15]);__calcul2_A15();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A15\n");
#endif
}
if (E[10]) {
__CheckVariables(__calcul2_CheckArray[16]);__calcul2_A16();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A16\n");
#endif
}
E[11] = __calcul2_R[1]&&E[0];
E[12] = E[11]&&!((__CheckVariables(__calcul2_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul2_A1()));
__calcul2_R[1] = E[10]||(__calcul2_R[1]&&E[12]);
E[11] = E[11]&&(__CheckVariables(__calcul2_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul2_A1());
if (E[11]) {
__CheckVariables(__calcul2_CheckArray[17]);__calcul2_A17();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A17\n");
#endif
}
E[0] = __calcul2_R[2]&&E[0];
E[12] = E[0]&&!((__CheckVariables(__calcul2_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul2_A1()));
__calcul2_R[2] = E[11]||(__calcul2_R[2]&&E[12]);
E[0] = E[0]&&(__CheckVariables(__calcul2_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul2_A1());
if (E[0]) {
__CheckVariables(__calcul2_CheckArray[18]);__calcul2_A18();
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A18\n");
#endif
}
E[2] = E[2]&&!((__CheckVariables(__calcul2_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__calcul2_A5()));
__calcul2_R[3] = E[0]||(__calcul2_R[3]&&E[2]);
E[2] = __calcul2_R[1]||__calcul2_R[2]||__calcul2_R[3];
__calcul2_R[0] = !(_true);
if (__calcul2_R[1]) { __AppendToList(__calcul2_HaltList,1); }
if (__calcul2_R[2]) { __AppendToList(__calcul2_HaltList,2); }
if (__calcul2_R[3]) { __AppendToList(__calcul2_HaltList,3); }
if (!E[2]) { __AppendToList(__calcul2_HaltList,0); }
__ResetModuleEntryAfterReaction();
__calcul2_ModuleData.awaited_list = __calcul2_AllAwaitedList;
__calcul2__reset_input();
return E[2];
}

/* AUTOMATON RESET */

int calcul2_reset () {
__calcul2_ModuleData.awaited_list = __calcul2_AwaitedList;
__ResetModuleEntry();
__calcul2_ModuleData.awaited_list = __calcul2_AllAwaitedList;
__calcul2_ModuleData.state = 0;
__calcul2_R[0] = _true;
__calcul2_R[1] = _false;
__calcul2_R[2] = _false;
__calcul2_R[3] = _false;
__calcul2__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__calcul2_ModuleData
};
