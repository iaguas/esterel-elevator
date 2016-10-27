/* sscc : C CODE OF SORTED EQUATIONS ex3 - SIMULATION MODE */

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
#define __ex3_GENERIC_TEST(TEST) return TEST;
typedef void (*__ex3_APF)();
static __ex3_APF *__ex3_PActionArray;
static int **__ex3_PCheckArray;
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

static boolean __ex3_V0;
static integer __ex3_V1;
static boolean __ex3_V2;
static integer __ex3_V3;

static unsigned short __ex3_HaltList[6];
static unsigned short __ex3_AwaitedList[4];
static unsigned short __ex3_EmittedList[4];
static unsigned short __ex3_StartedList[1];
static unsigned short __ex3_KilledList[1];
static unsigned short __ex3_SuspendedList[1];
static unsigned short __ex3_ActiveList[1];
static unsigned short __ex3_AllAwaitedList[4]={2,0,1};


/* INPUT FUNCTIONS */

void ex3_I_SWITCH () {
__ex3_V0 = _true;
}
void ex3_IS_SWITCH () {
__ex3_V0 = _true;
}
void ex3_I_DATA_IN (integer __V) {
__WriteVariable(1);
__ex3_V1 = __V;
__ex3_V2 = _true;
}
void ex3_IS_DATA_IN (string __V) {
__WriteVariable(1);
_text_to_integer(&__ex3_V1,__V);
__ex3_V2 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int ex3_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __ex3_A1 () {
__ex3_GENERIC_TEST(__ex3_V0);
}
static int __ex3_Check1 [] = {1,0,0};
static int __ex3_A2 () {
__ex3_GENERIC_TEST(__ex3_V2);
}
static int __ex3_Check2 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __ex3_A3 () {
#ifdef __OUTPUT
ex3_O_DATA_OUT(__ex3_V3);
#endif
__AppendToList(__ex3_EmittedList,2);
}
static int __ex3_Check3 [] = {1,0,0};

/* ASSIGNMENTS */

static void __ex3_A4 () {
__ex3_V0 = _false;
}
static int __ex3_Check4 [] = {1,0,1,0};
static void __ex3_A5 () {
__ex3_V2 = _false;
}
static int __ex3_Check5 [] = {1,0,1,2};
static void __ex3_A6 () {
__ex3_V3 = __ex3_V1+1;
}
static int __ex3_Check6 [] = {1,1,1,1,3};
static void __ex3_A7 () {
__ex3_V3 = __ex3_V1-1;
}
static int __ex3_Check7 [] = {1,1,1,1,3};

/* PROCEDURE CALLS */

/* CONDITIONS */

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __ex3_A8 () {
;
__ResetVariable(1);
}
static int __ex3_Check8 [] = {1,0,0};
static void __ex3_A9 () {
;
__ResetVariable(3);
}
static int __ex3_Check9 [] = {1,0,0};

/* ACTION SEQUENCES */


static int *__ex3_CheckArray[] = {
0,
__ex3_Check1,
__ex3_Check2,
__ex3_Check3,
__ex3_Check4,
__ex3_Check5,
__ex3_Check6,
__ex3_Check7,
__ex3_Check8,
__ex3_Check9
};
static int **__ex3_PCheckArray =  __ex3_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void ex3_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __ex3_show_variable (int __V) {
extern struct __VariableEntry __ex3_VariableTable[];
struct __VariableEntry* p_var = &__ex3_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __ex3_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __ex3_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __ex3_InstanceTable [] = {
{"ex3",0,"","ex3.strl",{1,1,1,0},{1,34,1,0},{0,0,0,0}},
};

struct __SignalEntry __ex3_SignalTable [] = {
{"SWITCH",33,0,0,{1,3,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"DATA_IN",1,1,0,{1,4,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"DATA_OUT",2,3,0,{1,5,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __ex3_InputTable [] = {
{"SWITCH",62,0,0,-1,0,0,0,ex3_IS_SWITCH,0,{1,3,11,0}},
{"DATA_IN",23,"integer",0,-3,0,1,_check_integer,ex3_IS_DATA_IN,0,{1,4,11,0}}};

struct __VariableEntry __ex3_VariableTable [] = {
{"__ex3_V0","V0","boolean",-2,2,0,(char*)&__ex3_V0,"SWITCH",0,0,0,{1,3,11,0}},
{"__ex3_V1","V1","integer",-3,1,0,(char*)&__ex3_V1,"DATA_IN",0,0,0,{1,4,11,0}},
{"__ex3_V2","V2","boolean",-2,2,0,(char*)&__ex3_V2,"DATA_IN",0,0,0,{1,4,11,0}},
{"__ex3_V3","V3","integer",-3,1,0,(char*)&__ex3_V3,"DATA_OUT",0,0,0,{1,5,12,0}}
};

struct __HaltEntry __ex3_HaltTable [] = {
{{1,34,1,0}},
{{1,11,17,0}},
{{1,16,9,0}},
{{1,24,9,0}},
{{1,27,17,0}}
};


static void __ex3__reset_input () {
__ex3_V0 = _false;
__ex3_V2 = _false;
}


/* MODULE DATA FOR SIMULATION */

int ex3();
int ex3_reset();

static struct __ModuleEntry __ex3_ModuleData = {
"Simulation interface release 5","ex3",
1,0,3,2,0,0,1,0,0,0,0,4,0,5,0,0,0,
__ex3_HaltList,
__ex3_AwaitedList,
__ex3_EmittedList,
__ex3_StartedList,
__ex3_KilledList,
__ex3_SuspendedList,
__ex3_ActiveList,
0,0,
ex3_initialize,ex3,ex3_reset,
__ex3_show_variable,__ex3_set_variable,__ex3_check_value,0,
__ex3_InstanceTable,
0,
__ex3_SignalTable,__ex3_InputTable,0,
0,0,
__ex3_VariableTable,
0,
__ex3_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __ex3_R[5] = {_true,
 _false,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int ex3 () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[11];

__ex3_ModuleData.awaited_list = __ex3_AwaitedList;
__ResetModuleEntryBeforeReaction();
E[0] = __ex3_R[1]&&!(__ex3_R[0]);
E[1] = E[0]&&!((__CheckVariables(__ex3_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ex3_A1()));
E[1] = __ex3_R[1]&&E[1];
E[2] = E[1]&&(__CheckVariables(__ex3_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__ex3_A2());
if (E[2]) {
__CheckVariables(__ex3_CheckArray[6]);__ex3_A6();
#ifdef TRACE_ACTION
fprintf(stderr, "__ex3_A6\n");
#endif
}
E[3] = __ex3_R[4]&&!(__ex3_R[0]);
E[4] = E[3]&&!((__CheckVariables(__ex3_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ex3_A1()));
E[4] = __ex3_R[4]&&E[4];
E[5] = E[4]&&(__CheckVariables(__ex3_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__ex3_A2());
if (E[5]) {
__CheckVariables(__ex3_CheckArray[7]);__ex3_A7();
#ifdef TRACE_ACTION
fprintf(stderr, "__ex3_A7\n");
#endif
}
if (E[2]||E[5]) {
__AppendToList(__ex3_EmittedList,2);
}
if (E[2]||E[5]) {
__CheckVariables(__ex3_CheckArray[3]);__ex3_A3();
#ifdef TRACE_ACTION
fprintf(stderr, "__ex3_A3\n");
#endif
}
E[6] = __ex3_R[0]&&!((__CheckVariables(__ex3_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__ex3_A2()));
if (E[6]) {
__CheckVariables(__ex3_CheckArray[8]);__ex3_A8();
#ifdef TRACE_ACTION
fprintf(stderr, "__ex3_A8\n");
#endif
}
if (__ex3_R[0]) {
__CheckVariables(__ex3_CheckArray[9]);__ex3_A9();
#ifdef TRACE_ACTION
fprintf(stderr, "__ex3_A9\n");
#endif
}
E[7] = !(_true);
E[8] = __ex3_R[2]&&!(__ex3_R[0]);
E[9] = E[8]&&(__CheckVariables(__ex3_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ex3_A1());
E[1] = E[1]&&!((__CheckVariables(__ex3_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__ex3_A2()));
E[1] = __ex3_R[0]||E[9]||E[2]||(__ex3_R[1]&&E[1]);
E[0] = E[0]&&(__CheckVariables(__ex3_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ex3_A1());
E[8] = E[8]&&!((__CheckVariables(__ex3_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ex3_A1()));
E[8] = E[0]||(__ex3_R[2]&&E[8]);
E[3] = E[3]&&(__CheckVariables(__ex3_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ex3_A1());
E[0] = __ex3_R[3]&&!(__ex3_R[0]);
E[9] = E[0]&&!((__CheckVariables(__ex3_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ex3_A1()));
E[9] = __ex3_R[0]||E[3]||(__ex3_R[3]&&E[9]);
E[0] = E[0]&&(__CheckVariables(__ex3_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ex3_A1());
E[4] = E[4]&&!((__CheckVariables(__ex3_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__ex3_A2()));
E[4] = E[0]||E[5]||(__ex3_R[4]&&E[4]);
E[0] = __ex3_R[1]||__ex3_R[2];
E[3] = __ex3_R[3]||__ex3_R[4];
E[10] = E[0]||E[3];
E[3] = (E[1]||E[8]||E[9]||E[4])&&((E[10]&&!(E[0]))||E[1]||E[8])&&((E[10]&&!(E[3]))||E[9]||E[4]);
__ex3_R[0] = !(_true);
__ex3_R[1] = E[1];
if (__ex3_R[1]) { __AppendToList(__ex3_HaltList,1); }
__ex3_R[2] = E[8];
if (__ex3_R[2]) { __AppendToList(__ex3_HaltList,2); }
__ex3_R[3] = E[9];
if (__ex3_R[3]) { __AppendToList(__ex3_HaltList,3); }
__ex3_R[4] = E[4];
if (__ex3_R[4]) { __AppendToList(__ex3_HaltList,4); }
if (!E[3]) { __AppendToList(__ex3_HaltList,0); }
__ResetModuleEntryAfterReaction();
__ex3_ModuleData.awaited_list = __ex3_AllAwaitedList;
__ex3__reset_input();
return E[3];
}

/* AUTOMATON RESET */

int ex3_reset () {
__ex3_ModuleData.awaited_list = __ex3_AwaitedList;
__ResetModuleEntry();
__ex3_ModuleData.awaited_list = __ex3_AllAwaitedList;
__ex3_ModuleData.state = 0;
__ex3_R[0] = _true;
__ex3_R[1] = _false;
__ex3_R[2] = _false;
__ex3_R[3] = _false;
__ex3_R[4] = _false;
__ex3__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__ex3_ModuleData
};
