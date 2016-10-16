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
static integer __ELEVATOR_V10;
static integer __ELEVATOR_V11;
static integer __ELEVATOR_V12;
static integer __ELEVATOR_V13;
static integer __ELEVATOR_V14;
static boolean __ELEVATOR_V15;
static integer __ELEVATOR_V16;
static integer __ELEVATOR_V17;
static integer __ELEVATOR_V18;
static integer __ELEVATOR_V19;
static integer __ELEVATOR_V20;
static integer __ELEVATOR_V21;
static integer __ELEVATOR_V22;
static integer __ELEVATOR_V23;
static integer __ELEVATOR_V24;
static integer __ELEVATOR_V25;
static integer __ELEVATOR_V26;

static unsigned short __ELEVATOR_HaltList[36];
static unsigned short __ELEVATOR_AwaitedList[16];
static unsigned short __ELEVATOR_EmittedList[16];
static unsigned short __ELEVATOR_StartedList[1];
static unsigned short __ELEVATOR_KilledList[1];
static unsigned short __ELEVATOR_SuspendedList[1];
static unsigned short __ELEVATOR_ActiveList[1];
static unsigned short __ELEVATOR_AllAwaitedList[16]={10,0,1,2,3,4,5,6,7,8,9};


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
void ELEVATOR_I_OPENDOOR () {
__ELEVATOR_V9 = _true;
}
void ELEVATOR_IS_OPENDOOR () {
__ELEVATOR_V9 = _true;
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

/* OUTPUT ACTIONS */

static void __ELEVATOR_A11 () {
#ifdef __OUTPUT
ELEVATOR_O_DOOR_OPENED();
#endif
__AppendToList(__ELEVATOR_EmittedList,10);
}
static int __ELEVATOR_Check11 [] = {1,0,0};
static void __ELEVATOR_A12 () {
#ifdef __OUTPUT
ELEVATOR_O_DOOR_CLOSED();
#endif
__AppendToList(__ELEVATOR_EmittedList,11);
}
static int __ELEVATOR_Check12 [] = {1,0,0};
static void __ELEVATOR_A13 () {
#ifdef __OUTPUT
ELEVATOR_O_FLOORSTATE(__ELEVATOR_V10);
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
__ELEVATOR_V12 = 1;
}
static int __ELEVATOR_Check24 [] = {1,0,1,12};
static void __ELEVATOR_A25 () {
__ELEVATOR_V12 = 2;
}
static int __ELEVATOR_Check25 [] = {1,0,1,12};
static void __ELEVATOR_A26 () {
__ELEVATOR_V12 = 3;
}
static int __ELEVATOR_Check26 [] = {1,0,1,12};
static void __ELEVATOR_A27 () {
__ELEVATOR_V12 = 4;
}
static int __ELEVATOR_Check27 [] = {1,0,1,12};
static void __ELEVATOR_A28 () {
__ELEVATOR_V11 = 1;
}
static int __ELEVATOR_Check28 [] = {1,0,1,11};
static void __ELEVATOR_A29 () {
__ELEVATOR_V11 = 2;
}
static int __ELEVATOR_Check29 [] = {1,0,1,11};
static void __ELEVATOR_A30 () {
__ELEVATOR_V11 = 3;
}
static int __ELEVATOR_Check30 [] = {1,0,1,11};
static void __ELEVATOR_A31 () {
__ELEVATOR_V11 = 4;
}
static int __ELEVATOR_Check31 [] = {1,0,1,11};
static void __ELEVATOR_A32 () {
__ELEVATOR_V13 = 1;
}
static int __ELEVATOR_Check32 [] = {1,0,1,13};
static void __ELEVATOR_A33 () {
__ELEVATOR_V15 = _false;
}
static int __ELEVATOR_Check33 [] = {1,0,1,15};
static void __ELEVATOR_A34 () {
__ELEVATOR_V10 = __ELEVATOR_V13;
}
static int __ELEVATOR_Check34 [] = {1,1,13,1,10};
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
__ELEVATOR_V16 = __ELEVATOR_V14;
}
static int __ELEVATOR_Check38 [] = {1,1,14,1,16};
static void __ELEVATOR_A39 () {
__ELEVATOR_V13 = __ELEVATOR_V13-1;
}
static int __ELEVATOR_Check39 [] = {1,1,13,1,13};
static void __ELEVATOR_A40 () {
__ELEVATOR_V10 = __ELEVATOR_V13;
}
static int __ELEVATOR_Check40 [] = {1,1,13,1,10};
static void __ELEVATOR_A41 () {
__ELEVATOR_V14 = __ELEVATOR_V12-__ELEVATOR_V13;
}
static int __ELEVATOR_Check41 [] = {1,2,12,13,1,14};
static void __ELEVATOR_A42 () {
__ELEVATOR_V17 = __ELEVATOR_V14;
}
static int __ELEVATOR_Check42 [] = {1,1,14,1,17};
static void __ELEVATOR_A43 () {
__ELEVATOR_V13 = __ELEVATOR_V13+1;
}
static int __ELEVATOR_Check43 [] = {1,1,13,1,13};
static void __ELEVATOR_A44 () {
__ELEVATOR_V10 = __ELEVATOR_V13;
}
static int __ELEVATOR_Check44 [] = {1,1,13,1,10};
static void __ELEVATOR_A45 () {
__ELEVATOR_V15 = _true;
}
static int __ELEVATOR_Check45 [] = {1,0,1,15};
static void __ELEVATOR_A46 () {
__ELEVATOR_V15 = _false;
}
static int __ELEVATOR_Check46 [] = {1,0,1,15};
static void __ELEVATOR_A47 () {
__ELEVATOR_V15 = _true;
}
static int __ELEVATOR_Check47 [] = {1,0,1,15};
static void __ELEVATOR_A48 () {
__ELEVATOR_V15 = _false;
}
static int __ELEVATOR_Check48 [] = {1,0,1,15};
static void __ELEVATOR_A49 () {
__ELEVATOR_V14 = __ELEVATOR_V13-__ELEVATOR_V11;
}
static int __ELEVATOR_Check49 [] = {1,2,13,11,1,14};
static void __ELEVATOR_A50 () {
__ELEVATOR_V18 = __ELEVATOR_V14;
}
static int __ELEVATOR_Check50 [] = {1,1,14,1,18};
static void __ELEVATOR_A51 () {
__ELEVATOR_V13 = __ELEVATOR_V13-1;
}
static int __ELEVATOR_Check51 [] = {1,1,13,1,13};
static void __ELEVATOR_A52 () {
__ELEVATOR_V10 = __ELEVATOR_V13;
}
static int __ELEVATOR_Check52 [] = {1,1,13,1,10};
static void __ELEVATOR_A53 () {
__ELEVATOR_V14 = __ELEVATOR_V11-__ELEVATOR_V13;
}
static int __ELEVATOR_Check53 [] = {1,2,11,13,1,14};
static void __ELEVATOR_A54 () {
__ELEVATOR_V19 = __ELEVATOR_V14;
}
static int __ELEVATOR_Check54 [] = {1,1,14,1,19};
static void __ELEVATOR_A55 () {
__ELEVATOR_V13 = __ELEVATOR_V13+1;
}
static int __ELEVATOR_Check55 [] = {1,1,13,1,13};
static void __ELEVATOR_A56 () {
__ELEVATOR_V10 = __ELEVATOR_V13;
}
static int __ELEVATOR_Check56 [] = {1,1,13,1,10};
static void __ELEVATOR_A57 () {
__ELEVATOR_V15 = _true;
}
static int __ELEVATOR_Check57 [] = {1,0,1,15};
static void __ELEVATOR_A58 () {
__ELEVATOR_V15 = _false;
}
static int __ELEVATOR_Check58 [] = {1,0,1,15};
static void __ELEVATOR_A59 () {
__ELEVATOR_V15 = _true;
}
static int __ELEVATOR_Check59 [] = {1,0,1,15};
static void __ELEVATOR_A60 () {
__ELEVATOR_V15 = _false;
}
static int __ELEVATOR_Check60 [] = {1,0,1,15};
static void __ELEVATOR_A61 () {
__ELEVATOR_V20 = 2-1;
}
static int __ELEVATOR_Check61 [] = {1,0,1,20};
static void __ELEVATOR_A62 () {
__ELEVATOR_V21 = 2-1;
}
static int __ELEVATOR_Check62 [] = {1,0,1,21};
static void __ELEVATOR_A63 () {
__ELEVATOR_V22 = 0;
}
static int __ELEVATOR_Check63 [] = {1,0,1,22};
static void __ELEVATOR_A64 () {
__ELEVATOR_V23 = 2-1;
}
static int __ELEVATOR_Check64 [] = {1,0,1,23};
static void __ELEVATOR_A65 () {
__ELEVATOR_V24 = 2-1;
}
static int __ELEVATOR_Check65 [] = {1,0,1,24};
static void __ELEVATOR_A66 () {
__ELEVATOR_V25 = 0;
}
static int __ELEVATOR_Check66 [] = {1,0,1,25};
static void __ELEVATOR_A67 () {
__ELEVATOR_V26 = 0;
}
static int __ELEVATOR_Check67 [] = {1,0,1,26};

/* PROCEDURE CALLS */

/* CONDITIONS */

static int __ELEVATOR_A68 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V13==__ELEVATOR_V12);
}
static int __ELEVATOR_Check68 [] = {1,2,13,12,0};
static int __ELEVATOR_A69 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V15==_false);
}
static int __ELEVATOR_Check69 [] = {1,1,15,0};
static int __ELEVATOR_A70 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V15==_true);
}
static int __ELEVATOR_Check70 [] = {1,1,15,0};
static int __ELEVATOR_A71 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V13>__ELEVATOR_V12);
}
static int __ELEVATOR_Check71 [] = {1,2,13,12,0};
static int __ELEVATOR_A72 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V16>0);
}
static int __ELEVATOR_Check72 [] = {1,1,16,0};
static int __ELEVATOR_A73 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V17>0);
}
static int __ELEVATOR_Check73 [] = {1,1,17,0};
static int __ELEVATOR_A74 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V13==__ELEVATOR_V11);
}
static int __ELEVATOR_Check74 [] = {1,2,13,11,0};
static int __ELEVATOR_A75 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V15==_false);
}
static int __ELEVATOR_Check75 [] = {1,1,15,0};
static int __ELEVATOR_A76 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V15==_true);
}
static int __ELEVATOR_Check76 [] = {1,1,15,0};
static int __ELEVATOR_A77 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V13>__ELEVATOR_V11);
}
static int __ELEVATOR_Check77 [] = {1,2,13,11,0};
static int __ELEVATOR_A78 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V18>0);
}
static int __ELEVATOR_Check78 [] = {1,1,18,0};
static int __ELEVATOR_A79 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V19>0);
}
static int __ELEVATOR_Check79 [] = {1,1,19,0};
static int __ELEVATOR_A80 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V15==_false);
}
static int __ELEVATOR_Check80 [] = {1,1,15,0};
static int __ELEVATOR_A81 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V20>0);
}
static int __ELEVATOR_Check81 [] = {1,1,20,0};
static int __ELEVATOR_A82 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V21>0);
}
static int __ELEVATOR_Check82 [] = {1,1,21,0};
static int __ELEVATOR_A83 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V22>0);
}
static int __ELEVATOR_Check83 [] = {1,1,22,0};
static int __ELEVATOR_A84 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V23>0);
}
static int __ELEVATOR_Check84 [] = {1,1,23,0};
static int __ELEVATOR_A85 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V24>0);
}
static int __ELEVATOR_Check85 [] = {1,1,24,0};
static int __ELEVATOR_A86 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V25>0);
}
static int __ELEVATOR_Check86 [] = {1,1,25,0};
static int __ELEVATOR_A87 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V26>0);
}
static int __ELEVATOR_Check87 [] = {1,1,26,0};

/* DECREMENTS */

static int __ELEVATOR_A88 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V16));
}
static int __ELEVATOR_Check88 [] = {1,1,16,1,16};
static int __ELEVATOR_A89 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V17));
}
static int __ELEVATOR_Check89 [] = {1,1,17,1,17};
static int __ELEVATOR_A90 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V18));
}
static int __ELEVATOR_Check90 [] = {1,1,18,1,18};
static int __ELEVATOR_A91 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V19));
}
static int __ELEVATOR_Check91 [] = {1,1,19,1,19};
static int __ELEVATOR_A92 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V20));
}
static int __ELEVATOR_Check92 [] = {1,1,20,1,20};
static int __ELEVATOR_A93 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V21));
}
static int __ELEVATOR_Check93 [] = {1,1,21,1,21};
static int __ELEVATOR_A94 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V22));
}
static int __ELEVATOR_Check94 [] = {1,1,22,1,22};
static int __ELEVATOR_A95 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V23));
}
static int __ELEVATOR_Check95 [] = {1,1,23,1,23};
static int __ELEVATOR_A96 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V24));
}
static int __ELEVATOR_Check96 [] = {1,1,24,1,24};
static int __ELEVATOR_A97 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V25));
}
static int __ELEVATOR_Check97 [] = {1,1,25,1,25};
static int __ELEVATOR_A98 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V26));
}
static int __ELEVATOR_Check98 [] = {1,1,26,1,26};

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __ELEVATOR_A99 () {
;
__ResetVariable(10);
}
static int __ELEVATOR_Check99 [] = {1,0,0};
static void __ELEVATOR_A100 () {
;
__ResetVariable(11);
}
static int __ELEVATOR_Check100 [] = {1,0,0};
static void __ELEVATOR_A101 () {
;
__ResetVariable(12);
}
static int __ELEVATOR_Check101 [] = {1,0,0};
static void __ELEVATOR_A102 () {
;
__ResetVariable(14);
}
static int __ELEVATOR_Check102 [] = {1,0,0};

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
__ELEVATOR_Check61,
__ELEVATOR_Check62,
__ELEVATOR_Check63,
__ELEVATOR_Check64,
__ELEVATOR_Check65,
__ELEVATOR_Check66,
__ELEVATOR_Check67,
__ELEVATOR_Check68,
__ELEVATOR_Check69,
__ELEVATOR_Check70,
__ELEVATOR_Check71,
__ELEVATOR_Check72,
__ELEVATOR_Check73,
__ELEVATOR_Check74,
__ELEVATOR_Check75,
__ELEVATOR_Check76,
__ELEVATOR_Check77,
__ELEVATOR_Check78,
__ELEVATOR_Check79,
__ELEVATOR_Check80,
__ELEVATOR_Check81,
__ELEVATOR_Check82,
__ELEVATOR_Check83,
__ELEVATOR_Check84,
__ELEVATOR_Check85,
__ELEVATOR_Check86,
__ELEVATOR_Check87,
__ELEVATOR_Check88,
__ELEVATOR_Check89,
__ELEVATOR_Check90,
__ELEVATOR_Check91,
__ELEVATOR_Check92,
__ELEVATOR_Check93,
__ELEVATOR_Check94,
__ELEVATOR_Check95,
__ELEVATOR_Check96,
__ELEVATOR_Check97,
__ELEVATOR_Check98,
__ELEVATOR_Check99,
__ELEVATOR_Check100,
__ELEVATOR_Check101,
__ELEVATOR_Check102
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
{"ELEVATOR",0,"./src/strl","elevator.strl",{1,1,1,0},{1,21,1,0},{0,0,0,0}},
{"BUTTONS",0,"./src/strl","buttons.strl",{1,1,1,1},{1,35,1,1},{1,13,9,0}},
{"CABIN",0,"./src/strl","cabin.strl",{1,1,1,2},{1,106,1,2},{1,17,9,0}},
{"OpenDoor",2,"./src/strl","tools.strl",{1,1,1,3},{1,9,1,3},{1,15,21,2}},
{"CloseDoor",2,"./src/strl","tools.strl",{1,12,1,4},{1,20,1,4},{1,22,21,2}},
{"FloorProcessingTime",2,"./src/strl","tools.strl",{1,23,1,5},{1,31,1,5},{1,29,25,2}},
{"FloorProcessingTime",2,"./src/strl","tools.strl",{1,23,1,6},{1,31,1,6},{1,36,25,2}},
{"OpenDoor",2,"./src/strl","tools.strl",{1,1,1,7},{1,9,1,7},{1,42,17,2}},
{"DoorAwaitingTime",2,"./src/strl","tools.strl",{1,34,1,8},{1,41,1,8},{1,45,17,2}},
{"CloseDoor",2,"./src/strl","tools.strl",{1,12,1,9},{1,20,1,9},{1,47,17,2}},
{"OpenDoor",2,"./src/strl","tools.strl",{1,1,1,10},{1,9,1,10},{1,55,21,2}},
{"CloseDoor",2,"./src/strl","tools.strl",{1,12,1,11},{1,20,1,11},{1,62,21,2}},
{"FloorProcessingTime",2,"./src/strl","tools.strl",{1,23,1,12},{1,31,1,12},{1,69,25,2}},
{"FloorProcessingTime",2,"./src/strl","tools.strl",{1,23,1,13},{1,31,1,13},{1,76,25,2}},
{"OpenDoor",2,"./src/strl","tools.strl",{1,1,1,14},{1,9,1,14},{1,82,17,2}},
{"DoorAwaitingTime",2,"./src/strl","tools.strl",{1,34,1,15},{1,41,1,15},{1,85,17,2}},
{"CloseDoor",2,"./src/strl","tools.strl",{1,12,1,16},{1,20,1,16},{1,87,17,2}},
{"OpenDoor",2,"./src/strl","tools.strl",{1,1,1,17},{1,9,1,17},{1,93,17,2}},
{"DoorAwaitingTime",2,"./src/strl","tools.strl",{1,34,1,18},{1,41,1,18},{1,96,17,2}},
{"CloseDoor",2,"./src/strl","tools.strl",{1,12,1,19},{1,20,1,19},{1,98,17,2}},
};

struct __SignalEntry __ELEVATOR_SignalTable [] = {
{"SECOND",33,0,0,{1,2,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CALLF1",33,0,0,{1,3,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CALLF2",33,0,0,{1,3,19,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CALLF3",33,0,0,{1,3,27,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CALLF4",33,0,0,{1,3,35,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"GOF1",33,0,0,{1,4,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"GOF2",33,0,0,{1,4,17,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"GOF3",33,0,0,{1,4,23,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"GOF4",33,0,0,{1,4,29,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"OPENDOOR",33,0,0,{1,5,11,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"DOOR_OPENED",34,0,0,{1,8,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"DOOR_CLOSED",34,0,0,{1,8,25,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"FLOORSTATE",2,10,0,{1,9,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TARGET",8,11,0,{1,11,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CALL",8,12,0,{1,11,28,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __ELEVATOR_InputTable [] = {
{"SECOND",40,0,0,-1,0,0,0,ELEVATOR_IS_SECOND,0,{1,2,11,0}},
{"CALLF1",100,0,0,-1,0,1,0,ELEVATOR_IS_CALLF1,0,{1,3,11,0}},
{"CALLF2",0,0,0,-1,0,2,0,ELEVATOR_IS_CALLF2,0,{1,3,19,0}},
{"CALLF3",1,0,0,-1,0,3,0,ELEVATOR_IS_CALLF3,0,{1,3,27,0}},
{"CALLF4",2,0,0,-1,0,4,0,ELEVATOR_IS_CALLF4,0,{1,3,35,0}},
{"GOF1",67,0,0,-1,0,5,0,ELEVATOR_IS_GOF1,0,{1,4,11,0}},
{"GOF2",68,0,0,-1,0,6,0,ELEVATOR_IS_GOF2,0,{1,4,17,0}},
{"GOF3",69,0,0,-1,0,7,0,ELEVATOR_IS_GOF3,0,{1,4,23,0}},
{"GOF4",70,0,0,-1,0,8,0,ELEVATOR_IS_GOF4,0,{1,4,29,0}},
{"OPENDOOR",8,0,0,-1,0,9,0,ELEVATOR_IS_OPENDOOR,0,{1,5,11,0}}};

struct __VariableEntry __ELEVATOR_VariableTable [] = {
{"__ELEVATOR_V0","V0","boolean",-2,2,0,(char*)&__ELEVATOR_V0,"SECOND",0,0,0,{1,2,11,0}},
{"__ELEVATOR_V1","V1","boolean",-2,2,0,(char*)&__ELEVATOR_V1,"CALLF1",0,0,0,{1,3,11,0}},
{"__ELEVATOR_V2","V2","boolean",-2,2,0,(char*)&__ELEVATOR_V2,"CALLF2",0,0,0,{1,3,19,0}},
{"__ELEVATOR_V3","V3","boolean",-2,2,0,(char*)&__ELEVATOR_V3,"CALLF3",0,0,0,{1,3,27,0}},
{"__ELEVATOR_V4","V4","boolean",-2,2,0,(char*)&__ELEVATOR_V4,"CALLF4",0,0,0,{1,3,35,0}},
{"__ELEVATOR_V5","V5","boolean",-2,2,0,(char*)&__ELEVATOR_V5,"GOF1",0,0,0,{1,4,11,0}},
{"__ELEVATOR_V6","V6","boolean",-2,2,0,(char*)&__ELEVATOR_V6,"GOF2",0,0,0,{1,4,17,0}},
{"__ELEVATOR_V7","V7","boolean",-2,2,0,(char*)&__ELEVATOR_V7,"GOF3",0,0,0,{1,4,23,0}},
{"__ELEVATOR_V8","V8","boolean",-2,2,0,(char*)&__ELEVATOR_V8,"GOF4",0,0,0,{1,4,29,0}},
{"__ELEVATOR_V9","V9","boolean",-2,2,0,(char*)&__ELEVATOR_V9,"OPENDOOR",0,0,0,{1,5,11,0}},
{"__ELEVATOR_V10","V10","integer",-3,1,0,(char*)&__ELEVATOR_V10,"FLOORSTATE",0,0,0,{1,9,12,0}},
{"__ELEVATOR_V11","V11","integer",-3,1,0,(char*)&__ELEVATOR_V11,"TARGET",0,0,0,{1,11,12,0}},
{"__ELEVATOR_V12","V12","integer",-3,1,0,(char*)&__ELEVATOR_V12,"CALL",0,0,0,{1,11,28,0}},
{"__ELEVATOR_V13","V13","integer",-3,0,0,(char*)&__ELEVATOR_V13,"floor",0,0,0,{1,8,9,2}},
{"__ELEVATOR_V14","V14","integer",-3,0,0,(char*)&__ELEVATOR_V14,"duration",0,0,0,{1,8,27,2}},
{"__ELEVATOR_V15","V15","boolean",-2,0,0,(char*)&__ELEVATOR_V15,"doorstate",0,0,0,{1,8,45,2}},
{"__ELEVATOR_V16","V16","integer",-3,3,0,(char*)&__ELEVATOR_V16,"0",0,0,0,{1,28,28,2}},
{"__ELEVATOR_V17","V17","integer",-3,3,0,(char*)&__ELEVATOR_V17,"0",0,0,0,{1,35,28,2}},
{"__ELEVATOR_V18","V18","integer",-3,3,0,(char*)&__ELEVATOR_V18,"0",0,0,0,{1,68,28,2}},
{"__ELEVATOR_V19","V19","integer",-3,3,0,(char*)&__ELEVATOR_V19,"0",0,0,0,{1,75,28,2}},
{"__ELEVATOR_V20","V20","integer",-3,3,0,(char*)&__ELEVATOR_V20,"0",0,0,0,{1,27,13,5}},
{"__ELEVATOR_V21","V21","integer",-3,3,0,(char*)&__ELEVATOR_V21,"0",0,0,0,{1,27,13,6}},
{"__ELEVATOR_V22","V22","integer",-3,3,0,(char*)&__ELEVATOR_V22,"0",0,0,0,{1,37,12,8}},
{"__ELEVATOR_V23","V23","integer",-3,3,0,(char*)&__ELEVATOR_V23,"0",0,0,0,{1,27,13,12}},
{"__ELEVATOR_V24","V24","integer",-3,3,0,(char*)&__ELEVATOR_V24,"0",0,0,0,{1,27,13,13}},
{"__ELEVATOR_V25","V25","integer",-3,3,0,(char*)&__ELEVATOR_V25,"0",0,0,0,{1,37,12,15}},
{"__ELEVATOR_V26","V26","integer",-3,3,0,(char*)&__ELEVATOR_V26,"0",0,0,0,{1,37,12,18}}
};

struct __HaltEntry __ELEVATOR_HaltTable [] = {
{{1,21,1,0}},
{{1,8,9,1}},
{{1,23,9,1}},
{{1,11,6,2}},
{{1,5,5,3}},
{{1,6,5,3}},
{{1,16,5,4}},
{{1,17,5,4}},
{{1,26,5,5}},
{{1,28,9,5}},
{{1,26,5,6}},
{{1,28,9,6}},
{{1,5,5,7}},
{{1,6,5,7}},
{{1,38,9,8}},
{{1,16,5,9}},
{{1,17,5,9}},
{{1,5,5,10}},
{{1,6,5,10}},
{{1,16,5,11}},
{{1,17,5,11}},
{{1,26,5,12}},
{{1,28,9,12}},
{{1,26,5,13}},
{{1,28,9,13}},
{{1,5,5,14}},
{{1,6,5,14}},
{{1,38,9,15}},
{{1,16,5,16}},
{{1,17,5,16}},
{{1,5,5,17}},
{{1,6,5,17}},
{{1,38,9,18}},
{{1,16,5,19}},
{{1,17,5,19}}
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
}


/* MODULE DATA FOR SIMULATION */

int ELEVATOR();
int ELEVATOR_reset();

static struct __ModuleEntry __ELEVATOR_ModuleData = {
"Simulation interface release 5","ELEVATOR",
20,0,15,10,0,0,3,2,0,0,0,27,0,35,0,0,0,
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

static __SSC_BIT_TYPE __ELEVATOR_R[35] = {_true,
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

static __SSC_BIT_TYPE E[75];

__ELEVATOR_ModuleData.awaited_list = __ELEVATOR_AwaitedList;
__ResetModuleEntryBeforeReaction();
E[0] = __ELEVATOR_R[5]&&!(__ELEVATOR_R[0]);
E[1] = E[0]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[2] = __ELEVATOR_R[13]&&!(__ELEVATOR_R[0]);
E[3] = E[2]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[4] = __ELEVATOR_R[18]&&!(__ELEVATOR_R[0]);
E[5] = E[4]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[6] = __ELEVATOR_R[26]&&!(__ELEVATOR_R[0]);
E[7] = E[6]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[8] = __ELEVATOR_R[31]&&!(__ELEVATOR_R[0]);
E[9] = E[8]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
if (E[1]||E[3]||E[5]||E[7]||E[9]) {
__AppendToList(__ELEVATOR_EmittedList,10);
}
if (E[1]||E[3]||E[5]||E[7]||E[9]) {
__CheckVariables(__ELEVATOR_CheckArray[11]);__ELEVATOR_A11();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A11\n");
#endif
}
E[10] = __ELEVATOR_R[7]&&!(__ELEVATOR_R[0]);
E[11] = E[10]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[12] = __ELEVATOR_R[16]&&!(__ELEVATOR_R[0]);
E[13] = E[12]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[14] = __ELEVATOR_R[20]&&!(__ELEVATOR_R[0]);
E[15] = E[14]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[16] = __ELEVATOR_R[29]&&!(__ELEVATOR_R[0]);
E[17] = E[16]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[18] = __ELEVATOR_R[34]&&!(__ELEVATOR_R[0]);
E[19] = E[18]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
if (E[11]||E[13]||E[15]||E[17]||E[19]) {
__AppendToList(__ELEVATOR_EmittedList,11);
}
if (E[11]||E[13]||E[15]||E[17]||E[19]) {
__CheckVariables(__ELEVATOR_CheckArray[12]);__ELEVATOR_A12();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A12\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[99]);__ELEVATOR_A99();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A99\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[101]);__ELEVATOR_A101();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A101\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[100]);__ELEVATOR_A100();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A100\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[32]);__ELEVATOR_A32();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A32\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[102]);__ELEVATOR_A102();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A102\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[33]);__ELEVATOR_A33();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A33\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[34]);__ELEVATOR_A34();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A34\n");
#endif
}
E[20] = __ELEVATOR_R[9]&&!(__ELEVATOR_R[0]);
E[21] = E[20]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[22] = E[21]&&(__CheckVariables(__ELEVATOR_CheckArray[92]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 92\n"),
#endif
__ELEVATOR_A92());
E[23] = __ELEVATOR_R[8]&&!(__ELEVATOR_R[0]);
E[24] = E[23]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
if (E[24]) {
__CheckVariables(__ELEVATOR_CheckArray[61]);__ELEVATOR_A61();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A61\n");
#endif
}
E[25] = E[24]&&(__CheckVariables(__ELEVATOR_CheckArray[81]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 81\n"),
#endif
__ELEVATOR_A81());
E[26] = E[22]||(E[24]&&!(E[25]));
if (E[26]) {
__CheckVariables(__ELEVATOR_CheckArray[39]);__ELEVATOR_A39();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A39\n");
#endif
}
if (E[26]) {
__CheckVariables(__ELEVATOR_CheckArray[40]);__ELEVATOR_A40();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A40\n");
#endif
}
E[27] = __ELEVATOR_R[11]&&!(__ELEVATOR_R[0]);
E[28] = E[27]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[29] = E[28]&&(__CheckVariables(__ELEVATOR_CheckArray[93]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 93\n"),
#endif
__ELEVATOR_A93());
E[30] = __ELEVATOR_R[10]&&!(__ELEVATOR_R[0]);
E[31] = E[30]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
if (E[31]) {
__CheckVariables(__ELEVATOR_CheckArray[62]);__ELEVATOR_A62();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A62\n");
#endif
}
E[32] = E[31]&&(__CheckVariables(__ELEVATOR_CheckArray[82]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 82\n"),
#endif
__ELEVATOR_A82());
E[33] = E[29]||(E[31]&&!(E[32]));
if (E[33]) {
__CheckVariables(__ELEVATOR_CheckArray[43]);__ELEVATOR_A43();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A43\n");
#endif
}
if (E[33]) {
__CheckVariables(__ELEVATOR_CheckArray[44]);__ELEVATOR_A44();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A44\n");
#endif
}
E[34] = __ELEVATOR_R[22]&&!(__ELEVATOR_R[0]);
E[35] = E[34]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[36] = E[35]&&(__CheckVariables(__ELEVATOR_CheckArray[95]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 95\n"),
#endif
__ELEVATOR_A95());
E[37] = __ELEVATOR_R[21]&&!(__ELEVATOR_R[0]);
E[38] = E[37]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
if (E[38]) {
__CheckVariables(__ELEVATOR_CheckArray[64]);__ELEVATOR_A64();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A64\n");
#endif
}
E[39] = E[38]&&(__CheckVariables(__ELEVATOR_CheckArray[84]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 84\n"),
#endif
__ELEVATOR_A84());
E[40] = E[36]||(E[38]&&!(E[39]));
if (E[40]) {
__CheckVariables(__ELEVATOR_CheckArray[51]);__ELEVATOR_A51();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A51\n");
#endif
}
if (E[40]) {
__CheckVariables(__ELEVATOR_CheckArray[52]);__ELEVATOR_A52();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A52\n");
#endif
}
E[41] = __ELEVATOR_R[24]&&!(__ELEVATOR_R[0]);
E[42] = E[41]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[43] = E[42]&&(__CheckVariables(__ELEVATOR_CheckArray[96]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 96\n"),
#endif
__ELEVATOR_A96());
E[44] = __ELEVATOR_R[23]&&!(__ELEVATOR_R[0]);
E[45] = E[44]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
if (E[45]) {
__CheckVariables(__ELEVATOR_CheckArray[65]);__ELEVATOR_A65();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A65\n");
#endif
}
E[46] = E[45]&&(__CheckVariables(__ELEVATOR_CheckArray[85]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 85\n"),
#endif
__ELEVATOR_A85());
E[47] = E[43]||(E[45]&&!(E[46]));
if (E[47]) {
__CheckVariables(__ELEVATOR_CheckArray[55]);__ELEVATOR_A55();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A55\n");
#endif
}
if (E[47]) {
__CheckVariables(__ELEVATOR_CheckArray[56]);__ELEVATOR_A56();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A56\n");
#endif
}
if (__ELEVATOR_R[0]||E[26]||E[33]||E[40]||E[47]) {
__AppendToList(__ELEVATOR_EmittedList,12);
}
if (__ELEVATOR_R[0]||E[26]||E[33]||E[40]||E[47]) {
__CheckVariables(__ELEVATOR_CheckArray[13]);__ELEVATOR_A13();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A13\n");
#endif
}
E[48] = __ELEVATOR_R[2]&&!(__ELEVATOR_R[0]);
E[49] = E[48]&&(__CheckVariables(__ELEVATOR_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__ELEVATOR_A6());
E[48] = E[48]&&!((__CheckVariables(__ELEVATOR_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__ELEVATOR_A6()));
E[50] = E[48]&&(__CheckVariables(__ELEVATOR_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__ELEVATOR_A7());
E[48] = E[48]&&!((__CheckVariables(__ELEVATOR_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__ELEVATOR_A7()));
E[51] = E[48]&&(__CheckVariables(__ELEVATOR_CheckArray[8]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__ELEVATOR_A8());
E[48] = E[48]&&!((__CheckVariables(__ELEVATOR_CheckArray[8]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__ELEVATOR_A8()));
E[52] = E[48]&&(__CheckVariables(__ELEVATOR_CheckArray[9]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__ELEVATOR_A9());
E[53] = E[49]||E[50]||E[51]||E[52];
if (E[53]) {
__AppendToList(__ELEVATOR_EmittedList,13);
}
if (E[49]) {
__CheckVariables(__ELEVATOR_CheckArray[28]);__ELEVATOR_A28();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A28\n");
#endif
}
if (E[50]) {
__CheckVariables(__ELEVATOR_CheckArray[29]);__ELEVATOR_A29();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A29\n");
#endif
}
if (E[51]) {
__CheckVariables(__ELEVATOR_CheckArray[30]);__ELEVATOR_A30();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A30\n");
#endif
}
if (E[52]) {
__CheckVariables(__ELEVATOR_CheckArray[31]);__ELEVATOR_A31();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A31\n");
#endif
}
E[54] = __ELEVATOR_R[1]&&!(__ELEVATOR_R[0]);
E[55] = E[54]&&(__CheckVariables(__ELEVATOR_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__ELEVATOR_A2());
E[54] = E[54]&&!((__CheckVariables(__ELEVATOR_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__ELEVATOR_A2()));
E[56] = E[54]&&(__CheckVariables(__ELEVATOR_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__ELEVATOR_A3());
E[54] = E[54]&&!((__CheckVariables(__ELEVATOR_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__ELEVATOR_A3()));
E[57] = E[54]&&(__CheckVariables(__ELEVATOR_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__ELEVATOR_A4());
E[54] = E[54]&&!((__CheckVariables(__ELEVATOR_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__ELEVATOR_A4()));
E[58] = E[54]&&(__CheckVariables(__ELEVATOR_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__ELEVATOR_A5());
E[59] = E[55]||E[56]||E[57]||E[58];
if (E[59]) {
__AppendToList(__ELEVATOR_EmittedList,14);
}
if (E[55]) {
__CheckVariables(__ELEVATOR_CheckArray[24]);__ELEVATOR_A24();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A24\n");
#endif
}
if (E[56]) {
__CheckVariables(__ELEVATOR_CheckArray[25]);__ELEVATOR_A25();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A25\n");
#endif
}
if (E[57]) {
__CheckVariables(__ELEVATOR_CheckArray[26]);__ELEVATOR_A26();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A26\n");
#endif
}
if (E[58]) {
__CheckVariables(__ELEVATOR_CheckArray[27]);__ELEVATOR_A27();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A27\n");
#endif
}
E[60] = !(_true);
E[54] = E[54]&&!((__CheckVariables(__ELEVATOR_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__ELEVATOR_A5()));
E[54] = __ELEVATOR_R[0]||E[55]||E[56]||E[57]||E[58]||(__ELEVATOR_R[1]&&E[54]);
E[48] = E[48]&&!((__CheckVariables(__ELEVATOR_CheckArray[9]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__ELEVATOR_A9()));
E[48] = __ELEVATOR_R[0]||E[49]||E[50]||E[51]||E[52]||(__ELEVATOR_R[2]&&E[48]);
E[61] = __ELEVATOR_R[1]||__ELEVATOR_R[2];
E[62] = (E[54]||E[48])&&((E[61]&&!(__ELEVATOR_R[1]))||E[54])&&((E[61]&&!(__ELEVATOR_R[2]))||E[48]);
if (E[1]) {
__CheckVariables(__ELEVATOR_CheckArray[35]);__ELEVATOR_A35();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A35\n");
#endif
}
E[63] = __ELEVATOR_R[3]&&!(__ELEVATOR_R[0]);
E[64] = E[63]&&E[59];
E[65] = E[64]&&(__CheckVariables(__ELEVATOR_CheckArray[68]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 68\n"),
#endif
__ELEVATOR_A68());
E[66] = E[65]&&(__CheckVariables(__ELEVATOR_CheckArray[69]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 69\n"),
#endif
__ELEVATOR_A69());
if (E[13]) {
__CheckVariables(__ELEVATOR_CheckArray[46]);__ELEVATOR_A46();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A46\n");
#endif
}
if (E[5]) {
__CheckVariables(__ELEVATOR_CheckArray[47]);__ELEVATOR_A47();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A47\n");
#endif
}
E[59] = E[63]&&!(E[59]);
E[63] = E[59]&&E[53];
E[67] = E[63]&&(__CheckVariables(__ELEVATOR_CheckArray[74]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 74\n"),
#endif
__ELEVATOR_A74());
E[68] = E[67]&&(__CheckVariables(__ELEVATOR_CheckArray[75]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 75\n"),
#endif
__ELEVATOR_A75());
if (E[17]) {
__CheckVariables(__ELEVATOR_CheckArray[58]);__ELEVATOR_A58();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A58\n");
#endif
}
if (E[19]) {
__CheckVariables(__ELEVATOR_CheckArray[60]);__ELEVATOR_A60();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A60\n");
#endif
}
E[53] = E[59]&&!(E[53]);
E[59] = E[53]&&(__CheckVariables(__ELEVATOR_CheckArray[10]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 10\n"),
#endif
__ELEVATOR_A10());
E[69] = E[59]&&(__CheckVariables(__ELEVATOR_CheckArray[80]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 80\n"),
#endif
__ELEVATOR_A80());
E[53] = E[53]&&!((__CheckVariables(__ELEVATOR_CheckArray[10]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 10\n"),
#endif
__ELEVATOR_A10()));
E[53] = __ELEVATOR_R[0]||E[1]||(E[65]&&!(E[66]))||E[13]||E[5]||(E[67]&&!(E[68]))||E[17]||E[19]||(E[59]&&!(E[69]))||(__ELEVATOR_R[3]&&E[53]);
E[59] = __ELEVATOR_R[4]&&!(__ELEVATOR_R[0]);
E[70] = E[59]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[70] = E[66]||(__ELEVATOR_R[4]&&E[70]);
E[59] = E[59]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[0] = E[0]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[0] = E[59]||(__ELEVATOR_R[5]&&E[0]);
E[65] = E[64]&&!(E[65]);
E[64] = E[65]&&(__CheckVariables(__ELEVATOR_CheckArray[70]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 70\n"),
#endif
__ELEVATOR_A70());
E[59] = __ELEVATOR_R[6]&&!(__ELEVATOR_R[0]);
E[66] = E[59]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[66] = E[64]||(__ELEVATOR_R[6]&&E[66]);
E[59] = E[59]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[10] = E[10]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[10] = E[59]||(__ELEVATOR_R[7]&&E[10]);
if (E[11]) {
__CheckVariables(__ELEVATOR_CheckArray[36]);__ELEVATOR_A36();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A36\n");
#endif
}
E[64] = E[11]||(E[65]&&!(E[64]));
E[65] = E[64]&&(__CheckVariables(__ELEVATOR_CheckArray[71]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 71\n"),
#endif
__ELEVATOR_A71());
if (E[65]) {
__CheckVariables(__ELEVATOR_CheckArray[37]);__ELEVATOR_A37();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A37\n");
#endif
}
if (E[65]) {
__CheckVariables(__ELEVATOR_CheckArray[38]);__ELEVATOR_A38();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A38\n");
#endif
}
E[59] = E[65]&&(__CheckVariables(__ELEVATOR_CheckArray[72]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 72\n"),
#endif
__ELEVATOR_A72());
E[71] = E[26]&&(__CheckVariables(__ELEVATOR_CheckArray[88]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 88\n"),
#endif
__ELEVATOR_A88());
E[23] = E[23]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[23] = E[59]||(E[26]&&!(E[71]))||(__ELEVATOR_R[8]&&E[23]);
E[20] = E[20]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[20] = E[25]||(E[21]&&!(E[22]))||(__ELEVATOR_R[9]&&E[20]);
E[22] = E[33]&&(__CheckVariables(__ELEVATOR_CheckArray[89]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 89\n"),
#endif
__ELEVATOR_A89());
E[64] = E[64]&&!(E[65]);
if (E[64]) {
__CheckVariables(__ELEVATOR_CheckArray[41]);__ELEVATOR_A41();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A41\n");
#endif
}
if (E[64]) {
__CheckVariables(__ELEVATOR_CheckArray[42]);__ELEVATOR_A42();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A42\n");
#endif
}
E[21] = E[64]&&(__CheckVariables(__ELEVATOR_CheckArray[73]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 73\n"),
#endif
__ELEVATOR_A73());
E[25] = __ELEVATOR_R[12]&&!(__ELEVATOR_R[0]);
E[72] = E[25]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[72] = E[71]||(E[65]&&!(E[59]))||E[22]||(E[64]&&!(E[21]))||(__ELEVATOR_R[12]&&E[72]);
E[25] = E[25]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[2] = E[2]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[2] = E[25]||(__ELEVATOR_R[13]&&E[2]);
if (E[3]) {
__CheckVariables(__ELEVATOR_CheckArray[45]);__ELEVATOR_A45();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A45\n");
#endif
}
if (E[3]) {
__CheckVariables(__ELEVATOR_CheckArray[63]);__ELEVATOR_A63();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A63\n");
#endif
}
E[25] = E[3]&&(__CheckVariables(__ELEVATOR_CheckArray[83]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 83\n"),
#endif
__ELEVATOR_A83());
E[59] = __ELEVATOR_R[14]&&!(__ELEVATOR_R[0]);
E[71] = E[59]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[73] = E[71]&&(__CheckVariables(__ELEVATOR_CheckArray[94]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 94\n"),
#endif
__ELEVATOR_A94());
E[59] = E[59]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[59] = E[25]||(E[71]&&!(E[73]))||(__ELEVATOR_R[14]&&E[59]);
E[71] = __ELEVATOR_R[15]&&!(__ELEVATOR_R[0]);
E[74] = E[71]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[74] = E[73]||(E[3]&&!(E[25]))||(__ELEVATOR_R[15]&&E[74]);
E[71] = E[71]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[12] = E[12]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[12] = E[71]||(__ELEVATOR_R[16]&&E[12]);
E[30] = E[30]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[30] = E[21]||(E[33]&&!(E[22]))||(__ELEVATOR_R[10]&&E[30]);
E[27] = E[27]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[27] = E[32]||(E[28]&&!(E[29]))||(__ELEVATOR_R[11]&&E[27]);
E[29] = __ELEVATOR_R[17]&&!(__ELEVATOR_R[0]);
E[28] = E[29]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[28] = E[68]||(__ELEVATOR_R[17]&&E[28]);
E[29] = E[29]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[4] = E[4]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[4] = E[29]||(__ELEVATOR_R[18]&&E[4]);
E[67] = E[63]&&!(E[67]);
E[63] = E[67]&&(__CheckVariables(__ELEVATOR_CheckArray[76]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 76\n"),
#endif
__ELEVATOR_A76());
E[29] = __ELEVATOR_R[19]&&!(__ELEVATOR_R[0]);
E[68] = E[29]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[68] = E[63]||(__ELEVATOR_R[19]&&E[68]);
E[29] = E[29]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[14] = E[14]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[14] = E[29]||(__ELEVATOR_R[20]&&E[14]);
if (E[15]) {
__CheckVariables(__ELEVATOR_CheckArray[48]);__ELEVATOR_A48();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A48\n");
#endif
}
E[63] = E[15]||(E[67]&&!(E[63]));
E[67] = E[63]&&(__CheckVariables(__ELEVATOR_CheckArray[77]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 77\n"),
#endif
__ELEVATOR_A77());
if (E[67]) {
__CheckVariables(__ELEVATOR_CheckArray[49]);__ELEVATOR_A49();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A49\n");
#endif
}
if (E[67]) {
__CheckVariables(__ELEVATOR_CheckArray[50]);__ELEVATOR_A50();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A50\n");
#endif
}
E[29] = E[67]&&(__CheckVariables(__ELEVATOR_CheckArray[78]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 78\n"),
#endif
__ELEVATOR_A78());
E[32] = E[40]&&(__CheckVariables(__ELEVATOR_CheckArray[90]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 90\n"),
#endif
__ELEVATOR_A90());
E[37] = E[37]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[37] = E[29]||(E[40]&&!(E[32]))||(__ELEVATOR_R[21]&&E[37]);
E[34] = E[34]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[34] = E[39]||(E[35]&&!(E[36]))||(__ELEVATOR_R[22]&&E[34]);
E[36] = E[47]&&(__CheckVariables(__ELEVATOR_CheckArray[91]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 91\n"),
#endif
__ELEVATOR_A91());
E[63] = E[63]&&!(E[67]);
if (E[63]) {
__CheckVariables(__ELEVATOR_CheckArray[53]);__ELEVATOR_A53();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A53\n");
#endif
}
if (E[63]) {
__CheckVariables(__ELEVATOR_CheckArray[54]);__ELEVATOR_A54();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A54\n");
#endif
}
E[35] = E[63]&&(__CheckVariables(__ELEVATOR_CheckArray[79]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 79\n"),
#endif
__ELEVATOR_A79());
E[39] = __ELEVATOR_R[25]&&!(__ELEVATOR_R[0]);
E[22] = E[39]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[22] = E[32]||(E[67]&&!(E[29]))||E[36]||(E[63]&&!(E[35]))||(__ELEVATOR_R[25]&&E[22]);
E[39] = E[39]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[6] = E[6]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[6] = E[39]||(__ELEVATOR_R[26]&&E[6]);
if (E[7]) {
__CheckVariables(__ELEVATOR_CheckArray[57]);__ELEVATOR_A57();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A57\n");
#endif
}
if (E[7]) {
__CheckVariables(__ELEVATOR_CheckArray[66]);__ELEVATOR_A66();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A66\n");
#endif
}
E[39] = E[7]&&(__CheckVariables(__ELEVATOR_CheckArray[86]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 86\n"),
#endif
__ELEVATOR_A86());
E[29] = __ELEVATOR_R[27]&&!(__ELEVATOR_R[0]);
E[32] = E[29]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[21] = E[32]&&(__CheckVariables(__ELEVATOR_CheckArray[97]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 97\n"),
#endif
__ELEVATOR_A97());
E[29] = E[29]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[29] = E[39]||(E[32]&&!(E[21]))||(__ELEVATOR_R[27]&&E[29]);
E[32] = __ELEVATOR_R[28]&&!(__ELEVATOR_R[0]);
E[71] = E[32]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[71] = E[21]||(E[7]&&!(E[39]))||(__ELEVATOR_R[28]&&E[71]);
E[32] = E[32]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[16] = E[16]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[16] = E[32]||(__ELEVATOR_R[29]&&E[16]);
E[44] = E[44]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[44] = E[35]||(E[47]&&!(E[36]))||(__ELEVATOR_R[23]&&E[44]);
E[41] = E[41]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[41] = E[46]||(E[42]&&!(E[43]))||(__ELEVATOR_R[24]&&E[41]);
E[43] = __ELEVATOR_R[30]&&!(__ELEVATOR_R[0]);
E[42] = E[43]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[42] = E[69]||(__ELEVATOR_R[30]&&E[42]);
E[43] = E[43]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[8] = E[8]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[8] = E[43]||(__ELEVATOR_R[31]&&E[8]);
if (E[9]) {
__CheckVariables(__ELEVATOR_CheckArray[59]);__ELEVATOR_A59();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A59\n");
#endif
}
if (E[9]) {
__CheckVariables(__ELEVATOR_CheckArray[67]);__ELEVATOR_A67();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A67\n");
#endif
}
E[43] = E[9]&&(__CheckVariables(__ELEVATOR_CheckArray[87]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 87\n"),
#endif
__ELEVATOR_A87());
E[69] = __ELEVATOR_R[32]&&!(__ELEVATOR_R[0]);
E[46] = E[69]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[36] = E[46]&&(__CheckVariables(__ELEVATOR_CheckArray[98]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 98\n"),
#endif
__ELEVATOR_A98());
E[69] = E[69]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[69] = E[43]||(E[46]&&!(E[36]))||(__ELEVATOR_R[32]&&E[69]);
E[46] = __ELEVATOR_R[33]&&!(__ELEVATOR_R[0]);
E[35] = E[46]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[35] = E[36]||(E[9]&&!(E[43]))||(__ELEVATOR_R[33]&&E[35]);
E[46] = E[46]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[18] = E[18]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[18] = E[46]||(__ELEVATOR_R[34]&&E[18]);
E[46] = __ELEVATOR_R[3]||__ELEVATOR_R[4]||__ELEVATOR_R[5]||__ELEVATOR_R[6]||__ELEVATOR_R[7]||__ELEVATOR_R[8]||__ELEVATOR_R[9]||__ELEVATOR_R[12]||__ELEVATOR_R[13]||__ELEVATOR_R[14]||__ELEVATOR_R[15]||__ELEVATOR_R[16]||__ELEVATOR_R[10]||__ELEVATOR_R[11]||__ELEVATOR_R[17]||__ELEVATOR_R[18]||__ELEVATOR_R[19]||__ELEVATOR_R[20]||__ELEVATOR_R[21]||__ELEVATOR_R[22]||__ELEVATOR_R[25]||__ELEVATOR_R[26]||__ELEVATOR_R[27]||__ELEVATOR_R[28]||__ELEVATOR_R[29]||__ELEVATOR_R[23]||__ELEVATOR_R[24]||__ELEVATOR_R[30]||__ELEVATOR_R[31]||__ELEVATOR_R[32]||__ELEVATOR_R[33]||__ELEVATOR_R[34];
E[43] = E[61]||E[46];
E[46] = (E[62]||E[53]||E[70]||E[0]||E[66]||E[10]||E[23]||E[20]||E[72]||E[2]||E[59]||E[74]||E[12]||E[30]||E[27]||E[28]||E[4]||E[68]||E[14]||E[37]||E[34]||E[22]||E[6]||E[29]||E[71]||E[16]||E[44]||E[41]||E[42]||E[8]||E[69]||E[35]||E[18])&&((E[43]&&!(E[61]))||E[62])&&((E[43]&&!(E[46]))||E[53]||E[70]||E[0]||E[66]||E[10]||E[23]||E[20]||E[72]||E[2]||E[59]||E[74]||E[12]||E[30]||E[27]||E[28]||E[4]||E[68]||E[14]||E[37]||E[34]||E[22]||E[6]||E[29]||E[71]||E[16]||E[44]||E[41]||E[42]||E[8]||E[69]||E[35]||E[18]);
__ELEVATOR_R[0] = !(_true);
__ELEVATOR_R[1] = E[54];
if (__ELEVATOR_R[1]) { __AppendToList(__ELEVATOR_HaltList,1); }
__ELEVATOR_R[2] = E[48];
if (__ELEVATOR_R[2]) { __AppendToList(__ELEVATOR_HaltList,2); }
__ELEVATOR_R[3] = E[53];
if (__ELEVATOR_R[3]) { __AppendToList(__ELEVATOR_HaltList,3); }
__ELEVATOR_R[4] = E[70];
if (__ELEVATOR_R[4]) { __AppendToList(__ELEVATOR_HaltList,4); }
__ELEVATOR_R[5] = E[0];
if (__ELEVATOR_R[5]) { __AppendToList(__ELEVATOR_HaltList,5); }
__ELEVATOR_R[6] = E[66];
if (__ELEVATOR_R[6]) { __AppendToList(__ELEVATOR_HaltList,6); }
__ELEVATOR_R[7] = E[10];
if (__ELEVATOR_R[7]) { __AppendToList(__ELEVATOR_HaltList,7); }
__ELEVATOR_R[8] = E[23];
if (__ELEVATOR_R[8]) { __AppendToList(__ELEVATOR_HaltList,8); }
__ELEVATOR_R[9] = E[20];
if (__ELEVATOR_R[9]) { __AppendToList(__ELEVATOR_HaltList,9); }
__ELEVATOR_R[10] = E[30];
if (__ELEVATOR_R[10]) { __AppendToList(__ELEVATOR_HaltList,10); }
__ELEVATOR_R[11] = E[27];
if (__ELEVATOR_R[11]) { __AppendToList(__ELEVATOR_HaltList,11); }
__ELEVATOR_R[12] = E[72];
if (__ELEVATOR_R[12]) { __AppendToList(__ELEVATOR_HaltList,12); }
__ELEVATOR_R[13] = E[2];
if (__ELEVATOR_R[13]) { __AppendToList(__ELEVATOR_HaltList,13); }
__ELEVATOR_R[14] = E[59];
if (__ELEVATOR_R[14]) { __AppendToList(__ELEVATOR_HaltList,14); }
__ELEVATOR_R[15] = E[74];
if (__ELEVATOR_R[15]) { __AppendToList(__ELEVATOR_HaltList,15); }
__ELEVATOR_R[16] = E[12];
if (__ELEVATOR_R[16]) { __AppendToList(__ELEVATOR_HaltList,16); }
__ELEVATOR_R[17] = E[28];
if (__ELEVATOR_R[17]) { __AppendToList(__ELEVATOR_HaltList,17); }
__ELEVATOR_R[18] = E[4];
if (__ELEVATOR_R[18]) { __AppendToList(__ELEVATOR_HaltList,18); }
__ELEVATOR_R[19] = E[68];
if (__ELEVATOR_R[19]) { __AppendToList(__ELEVATOR_HaltList,19); }
__ELEVATOR_R[20] = E[14];
if (__ELEVATOR_R[20]) { __AppendToList(__ELEVATOR_HaltList,20); }
__ELEVATOR_R[21] = E[37];
if (__ELEVATOR_R[21]) { __AppendToList(__ELEVATOR_HaltList,21); }
__ELEVATOR_R[22] = E[34];
if (__ELEVATOR_R[22]) { __AppendToList(__ELEVATOR_HaltList,22); }
__ELEVATOR_R[23] = E[44];
if (__ELEVATOR_R[23]) { __AppendToList(__ELEVATOR_HaltList,23); }
__ELEVATOR_R[24] = E[41];
if (__ELEVATOR_R[24]) { __AppendToList(__ELEVATOR_HaltList,24); }
__ELEVATOR_R[25] = E[22];
if (__ELEVATOR_R[25]) { __AppendToList(__ELEVATOR_HaltList,25); }
__ELEVATOR_R[26] = E[6];
if (__ELEVATOR_R[26]) { __AppendToList(__ELEVATOR_HaltList,26); }
__ELEVATOR_R[27] = E[29];
if (__ELEVATOR_R[27]) { __AppendToList(__ELEVATOR_HaltList,27); }
__ELEVATOR_R[28] = E[71];
if (__ELEVATOR_R[28]) { __AppendToList(__ELEVATOR_HaltList,28); }
__ELEVATOR_R[29] = E[16];
if (__ELEVATOR_R[29]) { __AppendToList(__ELEVATOR_HaltList,29); }
__ELEVATOR_R[30] = E[42];
if (__ELEVATOR_R[30]) { __AppendToList(__ELEVATOR_HaltList,30); }
__ELEVATOR_R[31] = E[8];
if (__ELEVATOR_R[31]) { __AppendToList(__ELEVATOR_HaltList,31); }
__ELEVATOR_R[32] = E[69];
if (__ELEVATOR_R[32]) { __AppendToList(__ELEVATOR_HaltList,32); }
__ELEVATOR_R[33] = E[35];
if (__ELEVATOR_R[33]) { __AppendToList(__ELEVATOR_HaltList,33); }
__ELEVATOR_R[34] = E[18];
if (__ELEVATOR_R[34]) { __AppendToList(__ELEVATOR_HaltList,34); }
if (!E[46]) { __AppendToList(__ELEVATOR_HaltList,0); }
__ResetModuleEntryAfterReaction();
__ELEVATOR_ModuleData.awaited_list = __ELEVATOR_AllAwaitedList;
__ELEVATOR__reset_input();
return E[46];
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
__ELEVATOR_R[23] = _false;
__ELEVATOR_R[24] = _false;
__ELEVATOR_R[25] = _false;
__ELEVATOR_R[26] = _false;
__ELEVATOR_R[27] = _false;
__ELEVATOR_R[28] = _false;
__ELEVATOR_R[29] = _false;
__ELEVATOR_R[30] = _false;
__ELEVATOR_R[31] = _false;
__ELEVATOR_R[32] = _false;
__ELEVATOR_R[33] = _false;
__ELEVATOR_R[34] = _false;
__ELEVATOR__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__ELEVATOR_ModuleData
};
