/* sscc : C CODE OF SORTED EQUATIONS ELEVATOR - SIMULATION MODE */

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
#define __ELEVATOR_GENERIC_TEST(TEST) return TEST;
typedef void (*__ELEVATOR_APF)();
static __ELEVATOR_APF *__ELEVATOR_PActionArray;
static int **__ELEVATOR_PCheckArray;
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

static boolean __ELEVATOR_V0;
static boolean __ELEVATOR_V1;
static boolean __ELEVATOR_V2;
static boolean __ELEVATOR_V3;
static boolean __ELEVATOR_V4;
static boolean __ELEVATOR_V5;
static boolean __ELEVATOR_V6;
static boolean __ELEVATOR_V7;
static boolean __ELEVATOR_V8;
static boolean __ELEVATOR_V9;
static boolean __ELEVATOR_V10;
static integer __ELEVATOR_V11;
static integer __ELEVATOR_V12;
static integer __ELEVATOR_V13;
static integer __ELEVATOR_V14;
static boolean __ELEVATOR_V15;
static integer __ELEVATOR_V16;
static integer __ELEVATOR_V17;

static unsigned short __ELEVATOR_HaltList[24];
static unsigned short __ELEVATOR_AwaitedList[16];
static unsigned short __ELEVATOR_EmittedList[16];
static unsigned short __ELEVATOR_StartedList[1];
static unsigned short __ELEVATOR_KilledList[1];
static unsigned short __ELEVATOR_SuspendedList[1];
static unsigned short __ELEVATOR_ActiveList[1];
static unsigned short __ELEVATOR_AllAwaitedList[16]={11,0,1,2,3,4,5,6,7,8,9,10};


/* INPUT FUNCTIONS */

void ELEVATOR_I_SECOND () {
__ELEVATOR_V0 = _true;
}
void ELEVATOR_IS_SECOND () {
__ELEVATOR_V0 = _true;
}
void ELEVATOR_I_CALLF1 () {
__ELEVATOR_V1 = _true;
}
void ELEVATOR_IS_CALLF1 () {
__ELEVATOR_V1 = _true;
}
void ELEVATOR_I_CALLF2 () {
__ELEVATOR_V2 = _true;
}
void ELEVATOR_IS_CALLF2 () {
__ELEVATOR_V2 = _true;
}
void ELEVATOR_I_CALLF3 () {
__ELEVATOR_V3 = _true;
}
void ELEVATOR_IS_CALLF3 () {
__ELEVATOR_V3 = _true;
}
void ELEVATOR_I_CALLF4 () {
__ELEVATOR_V4 = _true;
}
void ELEVATOR_IS_CALLF4 () {
__ELEVATOR_V4 = _true;
}
void ELEVATOR_I_GOF1 () {
__ELEVATOR_V5 = _true;
}
void ELEVATOR_IS_GOF1 () {
__ELEVATOR_V5 = _true;
}
void ELEVATOR_I_GOF2 () {
__ELEVATOR_V6 = _true;
}
void ELEVATOR_IS_GOF2 () {
__ELEVATOR_V6 = _true;
}
void ELEVATOR_I_GOF3 () {
__ELEVATOR_V7 = _true;
}
void ELEVATOR_IS_GOF3 () {
__ELEVATOR_V7 = _true;
}
void ELEVATOR_I_GOF4 () {
__ELEVATOR_V8 = _true;
}
void ELEVATOR_IS_GOF4 () {
__ELEVATOR_V8 = _true;
}
void ELEVATOR_I_OPEN_DOOR () {
__ELEVATOR_V9 = _true;
}
void ELEVATOR_IS_OPEN_DOOR () {
__ELEVATOR_V9 = _true;
}
void ELEVATOR_I_CLOSE_DOOR () {
__ELEVATOR_V10 = _true;
}
void ELEVATOR_IS_CLOSE_DOOR () {
__ELEVATOR_V10 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int ELEVATOR_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __ELEVATOR_A1 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V0);
}
static int __ELEVATOR_Check1 [] = {1,0,0};
static int __ELEVATOR_A2 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V1);
}
static int __ELEVATOR_Check2 [] = {1,0,0};
static int __ELEVATOR_A3 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V2);
}
static int __ELEVATOR_Check3 [] = {1,0,0};
static int __ELEVATOR_A4 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V3);
}
static int __ELEVATOR_Check4 [] = {1,0,0};
static int __ELEVATOR_A5 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V4);
}
static int __ELEVATOR_Check5 [] = {1,0,0};
static int __ELEVATOR_A6 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V5);
}
static int __ELEVATOR_Check6 [] = {1,0,0};
static int __ELEVATOR_A7 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V6);
}
static int __ELEVATOR_Check7 [] = {1,0,0};
static int __ELEVATOR_A8 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V7);
}
static int __ELEVATOR_Check8 [] = {1,0,0};
static int __ELEVATOR_A9 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V8);
}
static int __ELEVATOR_Check9 [] = {1,0,0};
static int __ELEVATOR_A10 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V9);
}
static int __ELEVATOR_Check10 [] = {1,0,0};
static int __ELEVATOR_A11 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V10);
}
static int __ELEVATOR_Check11 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __ELEVATOR_A12 () {
#ifdef __OUTPUT
ELEVATOR_O_DOOR_OPENED();
#endif
__AppendToList(__ELEVATOR_EmittedList,11);
}
static int __ELEVATOR_Check12 [] = {1,0,0};
static void __ELEVATOR_A13 () {
#ifdef __OUTPUT
ELEVATOR_O_DOOR_CLOSED();
#endif
__AppendToList(__ELEVATOR_EmittedList,12);
}
static int __ELEVATOR_Check13 [] = {1,0,0};

/* ASSIGNMENTS */

static void __ELEVATOR_A14 () {
__ELEVATOR_V0 = _false;
}
static int __ELEVATOR_Check14 [] = {1,0,1,0};
static void __ELEVATOR_A15 () {
__ELEVATOR_V1 = _false;
}
static int __ELEVATOR_Check15 [] = {1,0,1,1};
static void __ELEVATOR_A16 () {
__ELEVATOR_V2 = _false;
}
static int __ELEVATOR_Check16 [] = {1,0,1,2};
static void __ELEVATOR_A17 () {
__ELEVATOR_V3 = _false;
}
static int __ELEVATOR_Check17 [] = {1,0,1,3};
static void __ELEVATOR_A18 () {
__ELEVATOR_V4 = _false;
}
static int __ELEVATOR_Check18 [] = {1,0,1,4};
static void __ELEVATOR_A19 () {
__ELEVATOR_V5 = _false;
}
static int __ELEVATOR_Check19 [] = {1,0,1,5};
static void __ELEVATOR_A20 () {
__ELEVATOR_V6 = _false;
}
static int __ELEVATOR_Check20 [] = {1,0,1,6};
static void __ELEVATOR_A21 () {
__ELEVATOR_V7 = _false;
}
static int __ELEVATOR_Check21 [] = {1,0,1,7};
static void __ELEVATOR_A22 () {
__ELEVATOR_V8 = _false;
}
static int __ELEVATOR_Check22 [] = {1,0,1,8};
static void __ELEVATOR_A23 () {
__ELEVATOR_V9 = _false;
}
static int __ELEVATOR_Check23 [] = {1,0,1,9};
static void __ELEVATOR_A24 () {
__ELEVATOR_V10 = _false;
}
static int __ELEVATOR_Check24 [] = {1,0,1,10};
static void __ELEVATOR_A25 () {
__ELEVATOR_V12 = 1;
}
static int __ELEVATOR_Check25 [] = {1,0,1,12};
static void __ELEVATOR_A26 () {
__ELEVATOR_V12 = 2;
}
static int __ELEVATOR_Check26 [] = {1,0,1,12};
static void __ELEVATOR_A27 () {
__ELEVATOR_V12 = 3;
}
static int __ELEVATOR_Check27 [] = {1,0,1,12};
static void __ELEVATOR_A28 () {
__ELEVATOR_V12 = 4;
}
static int __ELEVATOR_Check28 [] = {1,0,1,12};
static void __ELEVATOR_A29 () {
__ELEVATOR_V11 = 1;
}
static int __ELEVATOR_Check29 [] = {1,0,1,11};
static void __ELEVATOR_A30 () {
__ELEVATOR_V11 = 2;
}
static int __ELEVATOR_Check30 [] = {1,0,1,11};
static void __ELEVATOR_A31 () {
__ELEVATOR_V11 = 3;
}
static int __ELEVATOR_Check31 [] = {1,0,1,11};
static void __ELEVATOR_A32 () {
__ELEVATOR_V11 = 4;
}
static int __ELEVATOR_Check32 [] = {1,0,1,11};
static void __ELEVATOR_A33 () {
__ELEVATOR_V13 = 1;
}
static int __ELEVATOR_Check33 [] = {1,0,1,13};
static void __ELEVATOR_A34 () {
__ELEVATOR_V15 = _false;
}
static int __ELEVATOR_Check34 [] = {1,0,1,15};
static void __ELEVATOR_A35 () {
__ELEVATOR_V15 = _true;
}
static int __ELEVATOR_Check35 [] = {1,0,1,15};
static void __ELEVATOR_A36 () {
__ELEVATOR_V15 = _false;
}
static int __ELEVATOR_Check36 [] = {1,0,1,15};
static void __ELEVATOR_A37 () {
__ELEVATOR_V14 = __ELEVATOR_V13-__ELEVATOR_V12;
}
static int __ELEVATOR_Check37 [] = {1,2,13,12,1,14};
static void __ELEVATOR_A38 () {
__ELEVATOR_V14 = __ELEVATOR_V12-__ELEVATOR_V13;
}
static int __ELEVATOR_Check38 [] = {1,2,12,13,1,14};
static void __ELEVATOR_A39 () {
__ELEVATOR_V16 = 4*__ELEVATOR_V14;
}
static int __ELEVATOR_Check39 [] = {1,1,14,1,16};
static void __ELEVATOR_A40 () {
__ELEVATOR_V15 = _true;
}
static int __ELEVATOR_Check40 [] = {1,0,1,15};
static void __ELEVATOR_A41 () {
__ELEVATOR_V13 = __ELEVATOR_V12;
}
static int __ELEVATOR_Check41 [] = {1,1,12,1,13};
static void __ELEVATOR_A42 () {
__ELEVATOR_V15 = _false;
}
static int __ELEVATOR_Check42 [] = {1,0,1,15};
static void __ELEVATOR_A43 () {
__ELEVATOR_V14 = __ELEVATOR_V13-__ELEVATOR_V11;
}
static int __ELEVATOR_Check43 [] = {1,2,13,11,1,14};
static void __ELEVATOR_A44 () {
__ELEVATOR_V14 = __ELEVATOR_V11-__ELEVATOR_V13;
}
static int __ELEVATOR_Check44 [] = {1,2,11,13,1,14};
static void __ELEVATOR_A45 () {
__ELEVATOR_V17 = 4*__ELEVATOR_V14;
}
static int __ELEVATOR_Check45 [] = {1,1,14,1,17};
static void __ELEVATOR_A46 () {
__ELEVATOR_V15 = _true;
}
static int __ELEVATOR_Check46 [] = {1,0,1,15};
static void __ELEVATOR_A47 () {
__ELEVATOR_V13 = __ELEVATOR_V11;
}
static int __ELEVATOR_Check47 [] = {1,1,11,1,13};
static void __ELEVATOR_A48 () {
__ELEVATOR_V15 = _false;
}
static int __ELEVATOR_Check48 [] = {1,0,1,15};

/* PROCEDURE CALLS */

/* CONDITIONS */

static int __ELEVATOR_A49 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V13==__ELEVATOR_V12);
}
static int __ELEVATOR_Check49 [] = {1,2,13,12,0};
static int __ELEVATOR_A50 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V15==_false);
}
static int __ELEVATOR_Check50 [] = {1,1,15,0};
static int __ELEVATOR_A51 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V15==_true);
}
static int __ELEVATOR_Check51 [] = {1,1,15,0};
static int __ELEVATOR_A52 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V13>__ELEVATOR_V12);
}
static int __ELEVATOR_Check52 [] = {1,2,13,12,0};
static int __ELEVATOR_A53 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V16>0);
}
static int __ELEVATOR_Check53 [] = {1,1,16,0};
static int __ELEVATOR_A54 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V15==_true);
}
static int __ELEVATOR_Check54 [] = {1,1,15,0};
static int __ELEVATOR_A55 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V13>__ELEVATOR_V11);
}
static int __ELEVATOR_Check55 [] = {1,2,13,11,0};
static int __ELEVATOR_A56 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V17>0);
}
static int __ELEVATOR_Check56 [] = {1,1,17,0};

/* DECREMENTS */

static int __ELEVATOR_A57 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V16));
}
static int __ELEVATOR_Check57 [] = {1,1,16,1,16};
static int __ELEVATOR_A58 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V17));
}
static int __ELEVATOR_Check58 [] = {1,1,17,1,17};

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __ELEVATOR_A59 () {
;
__ResetVariable(11);
}
static int __ELEVATOR_Check59 [] = {1,0,0};
static void __ELEVATOR_A60 () {
;
__ResetVariable(12);
}
static int __ELEVATOR_Check60 [] = {1,0,0};
static void __ELEVATOR_A61 () {
;
__ResetVariable(14);
}
static int __ELEVATOR_Check61 [] = {1,0,0};

/* ACTION SEQUENCES */


static int *__ELEVATOR_CheckArray[] = {
0,
__ELEVATOR_Check1,
__ELEVATOR_Check2,
__ELEVATOR_Check3,
__ELEVATOR_Check4,
__ELEVATOR_Check5,
__ELEVATOR_Check6,
__ELEVATOR_Check7,
__ELEVATOR_Check8,
__ELEVATOR_Check9,
__ELEVATOR_Check10,
__ELEVATOR_Check11,
__ELEVATOR_Check12,
__ELEVATOR_Check13,
__ELEVATOR_Check14,
__ELEVATOR_Check15,
__ELEVATOR_Check16,
__ELEVATOR_Check17,
__ELEVATOR_Check18,
__ELEVATOR_Check19,
__ELEVATOR_Check20,
__ELEVATOR_Check21,
__ELEVATOR_Check22,
__ELEVATOR_Check23,
__ELEVATOR_Check24,
__ELEVATOR_Check25,
__ELEVATOR_Check26,
__ELEVATOR_Check27,
__ELEVATOR_Check28,
__ELEVATOR_Check29,
__ELEVATOR_Check30,
__ELEVATOR_Check31,
__ELEVATOR_Check32,
__ELEVATOR_Check33,
__ELEVATOR_Check34,
__ELEVATOR_Check35,
__ELEVATOR_Check36,
__ELEVATOR_Check37,
__ELEVATOR_Check38,
__ELEVATOR_Check39,
__ELEVATOR_Check40,
__ELEVATOR_Check41,
__ELEVATOR_Check42,
__ELEVATOR_Check43,
__ELEVATOR_Check44,
__ELEVATOR_Check45,
__ELEVATOR_Check46,
__ELEVATOR_Check47,
__ELEVATOR_Check48,
__ELEVATOR_Check49,
__ELEVATOR_Check50,
__ELEVATOR_Check51,
__ELEVATOR_Check52,
__ELEVATOR_Check53,
__ELEVATOR_Check54,
__ELEVATOR_Check55,
__ELEVATOR_Check56,
__ELEVATOR_Check57,
__ELEVATOR_Check58,
__ELEVATOR_Check59,
__ELEVATOR_Check60,
__ELEVATOR_Check61
};
static int **__ELEVATOR_PCheckArray =  __ELEVATOR_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void ELEVATOR_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __ELEVATOR_show_variable (int __V) {
extern struct __VariableEntry __ELEVATOR_VariableTable[];
struct __VariableEntry* p_var = &__ELEVATOR_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __ELEVATOR_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __ELEVATOR_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __ELEVATOR_InstanceTable [] = {
{"ELEVATOR",0,"./src/strl","elevator.strl",{1,1,1,0},{1,20,1,0},{0,0,0,0}},
{"BUTTONS",0,"./src/strl","buttons.strl",{1,1,1,1},{1,36,1,1},{1,12,3,0}},
{"CABIN",0,"./src/strl","cabin.strl",{1,1,1,2},{1,92,1,2},{1,16,3,0}},
};

struct __SignalEntry __ELEVATOR_SignalTable [] = {
{"SECOND",33,0,0,{1,2,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CALLF1",33,0,0,{1,3,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CALLF2",33,0,0,{1,3,16,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CALLF3",33,0,0,{1,3,24,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CALLF4",33,0,0,{1,3,32,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"GOF1",33,0,0,{1,4,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"GOF2",33,0,0,{1,4,14,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"GOF3",33,0,0,{1,4,20,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"GOF4",33,0,0,{1,4,26,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"OPEN_DOOR",33,0,0,{1,5,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CLOSE_DOOR",33,0,0,{1,5,19,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"DOOR_OPENED",34,0,0,{1,8,9,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"DOOR_CLOSED",34,0,0,{1,8,22,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TARGET",8,11,0,{1,10,9,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CALLED",8,12,0,{1,10,25,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __ELEVATOR_InputTable [] = {
{"SECOND",40,0,0,-1,0,0,0,ELEVATOR_IS_SECOND,0,{1,2,8,0}},
{"CALLF1",100,0,0,-1,0,1,0,ELEVATOR_IS_CALLF1,0,{1,3,8,0}},
{"CALLF2",0,0,0,-1,0,2,0,ELEVATOR_IS_CALLF2,0,{1,3,16,0}},
{"CALLF3",1,0,0,-1,0,3,0,ELEVATOR_IS_CALLF3,0,{1,3,24,0}},
{"CALLF4",2,0,0,-1,0,4,0,ELEVATOR_IS_CALLF4,0,{1,3,32,0}},
{"GOF1",67,0,0,-1,0,5,0,ELEVATOR_IS_GOF1,0,{1,4,8,0}},
{"GOF2",68,0,0,-1,0,6,0,ELEVATOR_IS_GOF2,0,{1,4,14,0}},
{"GOF3",69,0,0,-1,0,7,0,ELEVATOR_IS_GOF3,0,{1,4,20,0}},
{"GOF4",70,0,0,-1,0,8,0,ELEVATOR_IS_GOF4,0,{1,4,26,0}},
{"OPEN_DOOR",2,0,0,-1,0,9,0,ELEVATOR_IS_OPEN_DOOR,0,{1,5,8,0}},
{"CLOSE_DOOR",70,0,0,-1,0,10,0,ELEVATOR_IS_CLOSE_DOOR,0,{1,5,19,0}}};

struct __VariableEntry __ELEVATOR_VariableTable [] = {
{"__ELEVATOR_V0","V0","boolean",-2,2,0,(char*)&__ELEVATOR_V0,"SECOND",0,0,0,{1,2,8,0}},
{"__ELEVATOR_V1","V1","boolean",-2,2,0,(char*)&__ELEVATOR_V1,"CALLF1",0,0,0,{1,3,8,0}},
{"__ELEVATOR_V2","V2","boolean",-2,2,0,(char*)&__ELEVATOR_V2,"CALLF2",0,0,0,{1,3,16,0}},
{"__ELEVATOR_V3","V3","boolean",-2,2,0,(char*)&__ELEVATOR_V3,"CALLF3",0,0,0,{1,3,24,0}},
{"__ELEVATOR_V4","V4","boolean",-2,2,0,(char*)&__ELEVATOR_V4,"CALLF4",0,0,0,{1,3,32,0}},
{"__ELEVATOR_V5","V5","boolean",-2,2,0,(char*)&__ELEVATOR_V5,"GOF1",0,0,0,{1,4,8,0}},
{"__ELEVATOR_V6","V6","boolean",-2,2,0,(char*)&__ELEVATOR_V6,"GOF2",0,0,0,{1,4,14,0}},
{"__ELEVATOR_V7","V7","boolean",-2,2,0,(char*)&__ELEVATOR_V7,"GOF3",0,0,0,{1,4,20,0}},
{"__ELEVATOR_V8","V8","boolean",-2,2,0,(char*)&__ELEVATOR_V8,"GOF4",0,0,0,{1,4,26,0}},
{"__ELEVATOR_V9","V9","boolean",-2,2,0,(char*)&__ELEVATOR_V9,"OPEN_DOOR",0,0,0,{1,5,8,0}},
{"__ELEVATOR_V10","V10","boolean",-2,2,0,(char*)&__ELEVATOR_V10,"CLOSE_DOOR",0,0,0,{1,5,19,0}},
{"__ELEVATOR_V11","V11","integer",-3,1,0,(char*)&__ELEVATOR_V11,"TARGET",0,0,0,{1,10,9,0}},
{"__ELEVATOR_V12","V12","integer",-3,1,0,(char*)&__ELEVATOR_V12,"CALLED",0,0,0,{1,10,25,0}},
{"__ELEVATOR_V13","V13","integer",-3,0,0,(char*)&__ELEVATOR_V13,"floor",0,0,0,{1,6,6,2}},
{"__ELEVATOR_V14","V14","integer",-3,0,0,(char*)&__ELEVATOR_V14,"duration",0,0,0,{1,6,24,2}},
{"__ELEVATOR_V15","V15","boolean",-2,0,0,(char*)&__ELEVATOR_V15,"doorstate",0,0,0,{1,6,42,2}},
{"__ELEVATOR_V16","V16","integer",-3,3,0,(char*)&__ELEVATOR_V16,"0",0,0,0,{1,33,12,2}},
{"__ELEVATOR_V17","V17","integer",-3,3,0,(char*)&__ELEVATOR_V17,"0",0,0,0,{1,69,11,2}}
};

struct __HaltEntry __ELEVATOR_HaltTable [] = {
{{1,20,1,0}},
{{1,9,4,1}},
{{1,24,4,1}},
{{1,8,3,2}},
{{1,11,5,2}},
{{1,12,5,2}},
{{1,21,5,2}},
{{1,22,5,2}},
{{1,34,5,2}},
{{1,40,4,2}},
{{1,41,4,2}},
{{1,47,4,2}},
{{1,48,4,2}},
{{1,49,4,2}},
{{1,56,3,2}},
{{1,58,4,2}},
{{1,59,4,2}},
{{1,70,4,2}},
{{1,76,3,2}},
{{1,77,3,2}},
{{1,83,3,2}},
{{1,84,3,2}},
{{1,85,3,2}}
};


static void __ELEVATOR__reset_input () {
__ELEVATOR_V0 = _false;
__ELEVATOR_V1 = _false;
__ELEVATOR_V2 = _false;
__ELEVATOR_V3 = _false;
__ELEVATOR_V4 = _false;
__ELEVATOR_V5 = _false;
__ELEVATOR_V6 = _false;
__ELEVATOR_V7 = _false;
__ELEVATOR_V8 = _false;
__ELEVATOR_V9 = _false;
__ELEVATOR_V10 = _false;
}


/* MODULE DATA FOR SIMULATION */

int ELEVATOR();
int ELEVATOR_reset();

static struct __ModuleEntry __ELEVATOR_ModuleData = {
"Simulation interface release 5","ELEVATOR",
3,0,15,11,0,0,2,2,0,0,0,18,0,23,0,0,0,
__ELEVATOR_HaltList,
__ELEVATOR_AwaitedList,
__ELEVATOR_EmittedList,
__ELEVATOR_StartedList,
__ELEVATOR_KilledList,
__ELEVATOR_SuspendedList,
__ELEVATOR_ActiveList,
0,0,
ELEVATOR_initialize,ELEVATOR,ELEVATOR_reset,
__ELEVATOR_show_variable,__ELEVATOR_set_variable,__ELEVATOR_check_value,0,
__ELEVATOR_InstanceTable,
0,
__ELEVATOR_SignalTable,__ELEVATOR_InputTable,0,
0,0,
__ELEVATOR_VariableTable,
0,
__ELEVATOR_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __ELEVATOR_R[23] = {_true,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int ELEVATOR () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[48];

__ELEVATOR_ModuleData.awaited_list = __ELEVATOR_AwaitedList;
__ResetModuleEntryBeforeReaction();
E[0] = __ELEVATOR_R[5]&&!(__ELEVATOR_R[0]);
E[1] = E[0]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[2] = __ELEVATOR_R[19]&&!(__ELEVATOR_R[0]);
E[3] = E[2]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[4] = __ELEVATOR_R[10]&&!(__ELEVATOR_R[0]);
E[5] = E[4]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
if (E[1]||E[3]||E[5]) {
__AppendToList(__ELEVATOR_EmittedList,11);
}
if (E[1]||E[3]||E[5]) {
__CheckVariables(__ELEVATOR_CheckArray[12]);__ELEVATOR_A12();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A12\n");
#endif
}
E[6] = __ELEVATOR_R[16]&&!(__ELEVATOR_R[0]);
E[7] = E[6]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[8] = __ELEVATOR_R[22]&&!(__ELEVATOR_R[0]);
E[9] = E[8]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[10] = __ELEVATOR_R[7]&&!(__ELEVATOR_R[0]);
E[11] = E[10]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[12] = __ELEVATOR_R[13]&&!(__ELEVATOR_R[0]);
E[13] = E[12]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
if (E[7]||E[9]||E[11]||E[13]) {
__AppendToList(__ELEVATOR_EmittedList,12);
}
if (E[7]||E[9]||E[11]||E[13]) {
__CheckVariables(__ELEVATOR_CheckArray[13]);__ELEVATOR_A13();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A13\n");
#endif
}
E[14] = __ELEVATOR_R[2]&&!(__ELEVATOR_R[0]);
E[15] = E[14]&&(__CheckVariables(__ELEVATOR_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__ELEVATOR_A6());
E[14] = E[14]&&!((__CheckVariables(__ELEVATOR_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__ELEVATOR_A6()));
E[16] = E[14]&&(__CheckVariables(__ELEVATOR_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__ELEVATOR_A7());
E[14] = E[14]&&!((__CheckVariables(__ELEVATOR_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__ELEVATOR_A7()));
E[17] = E[14]&&(__CheckVariables(__ELEVATOR_CheckArray[8]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__ELEVATOR_A8());
E[14] = E[14]&&!((__CheckVariables(__ELEVATOR_CheckArray[8]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__ELEVATOR_A8()));
E[18] = E[14]&&(__CheckVariables(__ELEVATOR_CheckArray[9]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__ELEVATOR_A9());
E[19] = E[15]||E[16]||E[17]||E[18];
if (E[19]) {
__AppendToList(__ELEVATOR_EmittedList,13);
}
if (E[15]) {
__CheckVariables(__ELEVATOR_CheckArray[29]);__ELEVATOR_A29();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A29\n");
#endif
}
if (E[16]) {
__CheckVariables(__ELEVATOR_CheckArray[30]);__ELEVATOR_A30();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A30\n");
#endif
}
if (E[17]) {
__CheckVariables(__ELEVATOR_CheckArray[31]);__ELEVATOR_A31();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A31\n");
#endif
}
if (E[18]) {
__CheckVariables(__ELEVATOR_CheckArray[32]);__ELEVATOR_A32();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A32\n");
#endif
}
E[20] = __ELEVATOR_R[1]&&!(__ELEVATOR_R[0]);
E[21] = E[20]&&(__CheckVariables(__ELEVATOR_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__ELEVATOR_A2());
E[20] = E[20]&&!((__CheckVariables(__ELEVATOR_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__ELEVATOR_A2()));
E[22] = E[20]&&(__CheckVariables(__ELEVATOR_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__ELEVATOR_A3());
E[20] = E[20]&&!((__CheckVariables(__ELEVATOR_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__ELEVATOR_A3()));
E[23] = E[20]&&(__CheckVariables(__ELEVATOR_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__ELEVATOR_A4());
E[20] = E[20]&&!((__CheckVariables(__ELEVATOR_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__ELEVATOR_A4()));
E[24] = E[20]&&(__CheckVariables(__ELEVATOR_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__ELEVATOR_A5());
E[25] = E[21]||E[22]||E[23]||E[24];
if (E[25]) {
__AppendToList(__ELEVATOR_EmittedList,14);
}
if (E[21]) {
__CheckVariables(__ELEVATOR_CheckArray[25]);__ELEVATOR_A25();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A25\n");
#endif
}
if (E[22]) {
__CheckVariables(__ELEVATOR_CheckArray[26]);__ELEVATOR_A26();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A26\n");
#endif
}
if (E[23]) {
__CheckVariables(__ELEVATOR_CheckArray[27]);__ELEVATOR_A27();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A27\n");
#endif
}
if (E[24]) {
__CheckVariables(__ELEVATOR_CheckArray[28]);__ELEVATOR_A28();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A28\n");
#endif
}
E[26] = !(_true);
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[60]);__ELEVATOR_A60();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A60\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[59]);__ELEVATOR_A59();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A59\n");
#endif
}
E[20] = E[20]&&!((__CheckVariables(__ELEVATOR_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__ELEVATOR_A5()));
E[20] = __ELEVATOR_R[0]||E[21]||E[22]||E[23]||E[24]||(__ELEVATOR_R[1]&&E[20]);
E[14] = E[14]&&!((__CheckVariables(__ELEVATOR_CheckArray[9]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__ELEVATOR_A9()));
E[14] = __ELEVATOR_R[0]||E[15]||E[16]||E[17]||E[18]||(__ELEVATOR_R[2]&&E[14]);
E[27] = __ELEVATOR_R[1]||__ELEVATOR_R[2];
E[28] = (E[20]||E[14])&&((E[27]&&!(__ELEVATOR_R[1]))||E[20])&&((E[27]&&!(__ELEVATOR_R[2]))||E[14]);
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[33]);__ELEVATOR_A33();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A33\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[61]);__ELEVATOR_A61();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A61\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[34]);__ELEVATOR_A34();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A34\n");
#endif
}
if (E[9]) {
__CheckVariables(__ELEVATOR_CheckArray[48]);__ELEVATOR_A48();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A48\n");
#endif
}
E[29] = __ELEVATOR_R[3]&&!(__ELEVATOR_R[0]);
E[30] = __ELEVATOR_R[0]||E[9]||(__ELEVATOR_R[3]&&E[29]&&!(E[25]));
E[25] = E[29]&&E[25];
E[29] = E[25]&&(__CheckVariables(__ELEVATOR_CheckArray[49]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 49\n"),
#endif
__ELEVATOR_A49());
E[31] = E[29]&&(__CheckVariables(__ELEVATOR_CheckArray[50]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 50\n"),
#endif
__ELEVATOR_A50());
E[32] = __ELEVATOR_R[4]&&!(__ELEVATOR_R[0]);
E[33] = E[32]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[33] = E[31]||(__ELEVATOR_R[4]&&E[33]);
E[32] = E[32]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[0] = E[0]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[0] = E[32]||(__ELEVATOR_R[5]&&E[0]);
if (E[1]) {
__CheckVariables(__ELEVATOR_CheckArray[35]);__ELEVATOR_A35();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A35\n");
#endif
}
E[32] = __ELEVATOR_R[14]&&!(__ELEVATOR_R[0]);
if (E[13]) {
__CheckVariables(__ELEVATOR_CheckArray[42]);__ELEVATOR_A42();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A42\n");
#endif
}
E[31] = E[1]||(__ELEVATOR_R[14]&&E[32]&&!(E[19]))||(E[29]&&!(E[31]))||E[13];
E[19] = E[32]&&E[19];
E[32] = E[19]&&(__CheckVariables(__ELEVATOR_CheckArray[54]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 54\n"),
#endif
__ELEVATOR_A54());
E[34] = __ELEVATOR_R[15]&&!(__ELEVATOR_R[0]);
E[35] = E[34]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[35] = E[32]||(__ELEVATOR_R[15]&&E[35]);
E[34] = E[34]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[6] = E[6]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[6] = E[34]||(__ELEVATOR_R[16]&&E[6]);
E[32] = E[7]||(E[19]&&!(E[32]));
E[19] = E[32]&&(__CheckVariables(__ELEVATOR_CheckArray[55]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 55\n"),
#endif
__ELEVATOR_A55());
if (E[19]) {
__CheckVariables(__ELEVATOR_CheckArray[43]);__ELEVATOR_A43();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A43\n");
#endif
}
E[32] = E[32]&&!(E[19]);
if (E[32]) {
__CheckVariables(__ELEVATOR_CheckArray[44]);__ELEVATOR_A44();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A44\n");
#endif
}
E[34] = E[19]||E[32];
if (E[34]) {
__CheckVariables(__ELEVATOR_CheckArray[45]);__ELEVATOR_A45();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A45\n");
#endif
}
E[36] = E[34]&&(__CheckVariables(__ELEVATOR_CheckArray[56]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 56\n"),
#endif
__ELEVATOR_A56());
E[37] = __ELEVATOR_R[17]&&!(__ELEVATOR_R[0]);
E[38] = E[37]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[39] = E[38]&&(__CheckVariables(__ELEVATOR_CheckArray[58]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 58\n"),
#endif
__ELEVATOR_A58());
E[37] = E[37]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[37] = E[36]||(E[38]&&!(E[39]))||(__ELEVATOR_R[17]&&E[37]);
E[38] = __ELEVATOR_R[18]&&!(__ELEVATOR_R[0]);
E[40] = E[38]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[36] = E[39]||(__ELEVATOR_R[18]&&E[40])||(E[34]&&!(E[36]));
E[38] = E[38]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[2] = E[2]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[2] = E[38]||(__ELEVATOR_R[19]&&E[2]);
if (E[3]) {
__CheckVariables(__ELEVATOR_CheckArray[46]);__ELEVATOR_A46();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A46\n");
#endif
}
if (E[3]) {
__CheckVariables(__ELEVATOR_CheckArray[47]);__ELEVATOR_A47();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A47\n");
#endif
}
E[38] = __ELEVATOR_R[20]&&!(__ELEVATOR_R[0]);
E[40] = E[38]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[40] = E[3]||(__ELEVATOR_R[20]&&E[40]);
E[38] = E[38]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[39] = __ELEVATOR_R[21]&&!(__ELEVATOR_R[0]);
E[41] = E[39]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[41] = E[38]||(__ELEVATOR_R[21]&&E[41]);
E[39] = E[39]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[8] = E[8]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[8] = E[39]||(__ELEVATOR_R[22]&&E[8]);
E[29] = E[25]&&!(E[29]);
E[25] = E[29]&&(__CheckVariables(__ELEVATOR_CheckArray[51]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 51\n"),
#endif
__ELEVATOR_A51());
E[39] = __ELEVATOR_R[6]&&!(__ELEVATOR_R[0]);
E[38] = E[39]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[38] = E[25]||(__ELEVATOR_R[6]&&E[38]);
E[39] = E[39]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[10] = E[10]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[10] = E[39]||(__ELEVATOR_R[7]&&E[10]);
if (E[11]) {
__CheckVariables(__ELEVATOR_CheckArray[36]);__ELEVATOR_A36();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A36\n");
#endif
}
E[25] = E[11]||(E[29]&&!(E[25]));
E[29] = E[25]&&(__CheckVariables(__ELEVATOR_CheckArray[52]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 52\n"),
#endif
__ELEVATOR_A52());
if (E[29]) {
__CheckVariables(__ELEVATOR_CheckArray[37]);__ELEVATOR_A37();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A37\n");
#endif
}
E[25] = E[25]&&!(E[29]);
if (E[25]) {
__CheckVariables(__ELEVATOR_CheckArray[38]);__ELEVATOR_A38();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A38\n");
#endif
}
E[39] = E[29]||E[25];
if (E[39]) {
__CheckVariables(__ELEVATOR_CheckArray[39]);__ELEVATOR_A39();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A39\n");
#endif
}
E[42] = E[39]&&(__CheckVariables(__ELEVATOR_CheckArray[53]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 53\n"),
#endif
__ELEVATOR_A53());
E[43] = __ELEVATOR_R[8]&&!(__ELEVATOR_R[0]);
E[44] = E[43]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[45] = E[44]&&(__CheckVariables(__ELEVATOR_CheckArray[57]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 57\n"),
#endif
__ELEVATOR_A57());
E[43] = E[43]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[43] = E[42]||(E[44]&&!(E[45]))||(__ELEVATOR_R[8]&&E[43]);
E[44] = __ELEVATOR_R[9]&&!(__ELEVATOR_R[0]);
E[46] = E[44]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[42] = E[45]||(__ELEVATOR_R[9]&&E[46])||(E[39]&&!(E[42]));
E[44] = E[44]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[4] = E[4]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[4] = E[44]||(__ELEVATOR_R[10]&&E[4]);
if (E[5]) {
__CheckVariables(__ELEVATOR_CheckArray[40]);__ELEVATOR_A40();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A40\n");
#endif
}
if (E[5]) {
__CheckVariables(__ELEVATOR_CheckArray[41]);__ELEVATOR_A41();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A41\n");
#endif
}
E[44] = __ELEVATOR_R[11]&&!(__ELEVATOR_R[0]);
E[46] = E[44]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[46] = E[5]||(__ELEVATOR_R[11]&&E[46]);
E[44] = E[44]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[45] = __ELEVATOR_R[12]&&!(__ELEVATOR_R[0]);
E[47] = E[45]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[47] = E[44]||(__ELEVATOR_R[12]&&E[47]);
E[45] = E[45]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[12] = E[12]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[12] = E[45]||(__ELEVATOR_R[13]&&E[12]);
E[45] = __ELEVATOR_R[3]||__ELEVATOR_R[4]||__ELEVATOR_R[5]||__ELEVATOR_R[14]||__ELEVATOR_R[15]||__ELEVATOR_R[16]||__ELEVATOR_R[17]||__ELEVATOR_R[18]||__ELEVATOR_R[19]||__ELEVATOR_R[20]||__ELEVATOR_R[21]||__ELEVATOR_R[22]||__ELEVATOR_R[6]||__ELEVATOR_R[7]||__ELEVATOR_R[8]||__ELEVATOR_R[9]||__ELEVATOR_R[10]||__ELEVATOR_R[11]||__ELEVATOR_R[12]||__ELEVATOR_R[13];
E[44] = E[27]||E[45];
E[45] = (E[28]||E[30]||E[33]||E[0]||E[31]||E[35]||E[6]||E[37]||E[36]||E[2]||E[40]||E[41]||E[8]||E[38]||E[10]||E[43]||E[42]||E[4]||E[46]||E[47]||E[12])&&((E[44]&&!(E[27]))||E[28])&&((E[44]&&!(E[45]))||E[30]||E[33]||E[0]||E[31]||E[35]||E[6]||E[37]||E[36]||E[2]||E[40]||E[41]||E[8]||E[38]||E[10]||E[43]||E[42]||E[4]||E[46]||E[47]||E[12]);
__ELEVATOR_R[0] = !(_true);
__ELEVATOR_R[1] = E[20];
if (__ELEVATOR_R[1]) { __AppendToList(__ELEVATOR_HaltList,1); }
__ELEVATOR_R[2] = E[14];
if (__ELEVATOR_R[2]) { __AppendToList(__ELEVATOR_HaltList,2); }
__ELEVATOR_R[3] = E[30];
if (__ELEVATOR_R[3]) { __AppendToList(__ELEVATOR_HaltList,3); }
__ELEVATOR_R[4] = E[33];
if (__ELEVATOR_R[4]) { __AppendToList(__ELEVATOR_HaltList,4); }
__ELEVATOR_R[5] = E[0];
if (__ELEVATOR_R[5]) { __AppendToList(__ELEVATOR_HaltList,5); }
__ELEVATOR_R[6] = E[38];
if (__ELEVATOR_R[6]) { __AppendToList(__ELEVATOR_HaltList,6); }
__ELEVATOR_R[7] = E[10];
if (__ELEVATOR_R[7]) { __AppendToList(__ELEVATOR_HaltList,7); }
__ELEVATOR_R[8] = E[43];
if (__ELEVATOR_R[8]) { __AppendToList(__ELEVATOR_HaltList,8); }
__ELEVATOR_R[9] = E[42];
if (__ELEVATOR_R[9]) { __AppendToList(__ELEVATOR_HaltList,9); }
__ELEVATOR_R[10] = E[4];
if (__ELEVATOR_R[10]) { __AppendToList(__ELEVATOR_HaltList,10); }
__ELEVATOR_R[11] = E[46];
if (__ELEVATOR_R[11]) { __AppendToList(__ELEVATOR_HaltList,11); }
__ELEVATOR_R[12] = E[47];
if (__ELEVATOR_R[12]) { __AppendToList(__ELEVATOR_HaltList,12); }
__ELEVATOR_R[13] = E[12];
if (__ELEVATOR_R[13]) { __AppendToList(__ELEVATOR_HaltList,13); }
__ELEVATOR_R[14] = E[31];
if (__ELEVATOR_R[14]) { __AppendToList(__ELEVATOR_HaltList,14); }
__ELEVATOR_R[15] = E[35];
if (__ELEVATOR_R[15]) { __AppendToList(__ELEVATOR_HaltList,15); }
__ELEVATOR_R[16] = E[6];
if (__ELEVATOR_R[16]) { __AppendToList(__ELEVATOR_HaltList,16); }
__ELEVATOR_R[17] = E[37];
if (__ELEVATOR_R[17]) { __AppendToList(__ELEVATOR_HaltList,17); }
__ELEVATOR_R[18] = E[36];
if (__ELEVATOR_R[18]) { __AppendToList(__ELEVATOR_HaltList,18); }
__ELEVATOR_R[19] = E[2];
if (__ELEVATOR_R[19]) { __AppendToList(__ELEVATOR_HaltList,19); }
__ELEVATOR_R[20] = E[40];
if (__ELEVATOR_R[20]) { __AppendToList(__ELEVATOR_HaltList,20); }
__ELEVATOR_R[21] = E[41];
if (__ELEVATOR_R[21]) { __AppendToList(__ELEVATOR_HaltList,21); }
__ELEVATOR_R[22] = E[8];
if (__ELEVATOR_R[22]) { __AppendToList(__ELEVATOR_HaltList,22); }
if (!E[45]) { __AppendToList(__ELEVATOR_HaltList,0); }
__ResetModuleEntryAfterReaction();
__ELEVATOR_ModuleData.awaited_list = __ELEVATOR_AllAwaitedList;
__ELEVATOR__reset_input();
return E[45];
}

/* AUTOMATON RESET */

int ELEVATOR_reset () {
__ELEVATOR_ModuleData.awaited_list = __ELEVATOR_AwaitedList;
__ResetModuleEntry();
__ELEVATOR_ModuleData.awaited_list = __ELEVATOR_AllAwaitedList;
__ELEVATOR_ModuleData.state = 0;
__ELEVATOR_R[0] = _true;
__ELEVATOR_R[1] = _false;
__ELEVATOR_R[2] = _false;
__ELEVATOR_R[3] = _false;
__ELEVATOR_R[4] = _false;
__ELEVATOR_R[5] = _false;
__ELEVATOR_R[6] = _false;
__ELEVATOR_R[7] = _false;
__ELEVATOR_R[8] = _false;
__ELEVATOR_R[9] = _false;
__ELEVATOR_R[10] = _false;
__ELEVATOR_R[11] = _false;
__ELEVATOR_R[12] = _false;
__ELEVATOR_R[13] = _false;
__ELEVATOR_R[14] = _false;
__ELEVATOR_R[15] = _false;
__ELEVATOR_R[16] = _false;
__ELEVATOR_R[17] = _false;
__ELEVATOR_R[18] = _false;
__ELEVATOR_R[19] = _false;
__ELEVATOR_R[20] = _false;
__ELEVATOR_R[21] = _false;
__ELEVATOR_R[22] = _false;
__ELEVATOR__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__ELEVATOR_ModuleData
};
