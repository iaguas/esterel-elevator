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
static boolean __ELEVATOR_V12;
static boolean __ELEVATOR_V13;
static boolean __ELEVATOR_V14;
static boolean __ELEVATOR_V15;
static boolean __ELEVATOR_V16;
static boolean __ELEVATOR_V17;
static boolean __ELEVATOR_V18;
static boolean __ELEVATOR_V19;
static boolean __ELEVATOR_V20;
static boolean __ELEVATOR_V21;
static integer __ELEVATOR_V22;
static boolean __ELEVATOR_V23;
static integer __ELEVATOR_V24;
static integer __ELEVATOR_V25;
static boolean __ELEVATOR_V26;
static boolean __ELEVATOR_V27;
static integer __ELEVATOR_V28;
static integer __ELEVATOR_V29;
static integer __ELEVATOR_V30;
static integer __ELEVATOR_V31;
static integer __ELEVATOR_V32;
static integer __ELEVATOR_V33;
static integer __ELEVATOR_V34;
static integer __ELEVATOR_V35;

static unsigned short __ELEVATOR_HaltList[31];
static unsigned short __ELEVATOR_AwaitedList[23];
static unsigned short __ELEVATOR_EmittedList[23];
static unsigned short __ELEVATOR_StartedList[1];
static unsigned short __ELEVATOR_KilledList[1];
static unsigned short __ELEVATOR_SuspendedList[1];
static unsigned short __ELEVATOR_ActiveList[1];
static unsigned short __ELEVATOR_AllAwaitedList[23]={10,0,1,2,3,4,5,6,7,8,9};


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
ELEVATOR_O_DOOROPENED();
#endif
__AppendToList(__ELEVATOR_EmittedList,10);
}
static int __ELEVATOR_Check11 [] = {1,0,0};
static void __ELEVATOR_A12 () {
#ifdef __OUTPUT
ELEVATOR_O_DOORCLOSED();
#endif
__AppendToList(__ELEVATOR_EmittedList,11);
}
static int __ELEVATOR_Check12 [] = {1,0,0};
static void __ELEVATOR_A13 () {
#ifdef __OUTPUT
ELEVATOR_O_CURRENTFLOOR(__ELEVATOR_V10);
#endif
__AppendToList(__ELEVATOR_EmittedList,12);
}
static int __ELEVATOR_Check13 [] = {1,0,0};
static void __ELEVATOR_A14 () {
#ifdef __OUTPUT
ELEVATOR_O_WRONG();
#endif
__AppendToList(__ELEVATOR_EmittedList,13);
}
static int __ELEVATOR_Check14 [] = {1,0,0};
static void __ELEVATOR_A15 () {
#ifdef __OUTPUT
ELEVATOR_O_LF1();
#endif
__AppendToList(__ELEVATOR_EmittedList,14);
}
static int __ELEVATOR_Check15 [] = {1,0,0};
static void __ELEVATOR_A16 () {
#ifdef __OUTPUT
ELEVATOR_O_LF2();
#endif
__AppendToList(__ELEVATOR_EmittedList,15);
}
static int __ELEVATOR_Check16 [] = {1,0,0};
static void __ELEVATOR_A17 () {
#ifdef __OUTPUT
ELEVATOR_O_LF3();
#endif
__AppendToList(__ELEVATOR_EmittedList,16);
}
static int __ELEVATOR_Check17 [] = {1,0,0};
static void __ELEVATOR_A18 () {
#ifdef __OUTPUT
ELEVATOR_O_LF4();
#endif
__AppendToList(__ELEVATOR_EmittedList,17);
}
static int __ELEVATOR_Check18 [] = {1,0,0};
static void __ELEVATOR_A19 () {
#ifdef __OUTPUT
ELEVATOR_O_LOUT();
#endif
__AppendToList(__ELEVATOR_EmittedList,18);
}
static int __ELEVATOR_Check19 [] = {1,0,0};

/* ASSIGNMENTS */

static void __ELEVATOR_A20 () {
__ELEVATOR_V0 = _false;
}
static int __ELEVATOR_Check20 [] = {1,0,1,0};
static void __ELEVATOR_A21 () {
__ELEVATOR_V1 = _false;
}
static int __ELEVATOR_Check21 [] = {1,0,1,1};
static void __ELEVATOR_A22 () {
__ELEVATOR_V2 = _false;
}
static int __ELEVATOR_Check22 [] = {1,0,1,2};
static void __ELEVATOR_A23 () {
__ELEVATOR_V3 = _false;
}
static int __ELEVATOR_Check23 [] = {1,0,1,3};
static void __ELEVATOR_A24 () {
__ELEVATOR_V4 = _false;
}
static int __ELEVATOR_Check24 [] = {1,0,1,4};
static void __ELEVATOR_A25 () {
__ELEVATOR_V5 = _false;
}
static int __ELEVATOR_Check25 [] = {1,0,1,5};
static void __ELEVATOR_A26 () {
__ELEVATOR_V6 = _false;
}
static int __ELEVATOR_Check26 [] = {1,0,1,6};
static void __ELEVATOR_A27 () {
__ELEVATOR_V7 = _false;
}
static int __ELEVATOR_Check27 [] = {1,0,1,7};
static void __ELEVATOR_A28 () {
__ELEVATOR_V8 = _false;
}
static int __ELEVATOR_Check28 [] = {1,0,1,8};
static void __ELEVATOR_A29 () {
__ELEVATOR_V9 = _false;
}
static int __ELEVATOR_Check29 [] = {1,0,1,9};
static void __ELEVATOR_A30 () {
__ELEVATOR_V12 = _false;
}
static int __ELEVATOR_Check30 [] = {1,0,1,12};
static void __ELEVATOR_A31 () {
__ELEVATOR_V13 = _false;
}
static int __ELEVATOR_Check31 [] = {1,0,1,13};
static void __ELEVATOR_A32 () {
__ELEVATOR_V14 = _false;
}
static int __ELEVATOR_Check32 [] = {1,0,1,14};
static void __ELEVATOR_A33 () {
__ELEVATOR_V15 = _false;
}
static int __ELEVATOR_Check33 [] = {1,0,1,15};
static void __ELEVATOR_A34 () {
__ELEVATOR_V16 = _false;
}
static int __ELEVATOR_Check34 [] = {1,0,1,16};
static void __ELEVATOR_A35 () {
__ELEVATOR_V17 = _false;
}
static int __ELEVATOR_Check35 [] = {1,0,1,17};
static void __ELEVATOR_A36 () {
__ELEVATOR_V18 = _false;
}
static int __ELEVATOR_Check36 [] = {1,0,1,18};
static void __ELEVATOR_A37 () {
__ELEVATOR_V19 = _false;
}
static int __ELEVATOR_Check37 [] = {1,0,1,19};
static void __ELEVATOR_A38 () {
__ELEVATOR_V20 = _true;
}
static int __ELEVATOR_Check38 [] = {1,0,1,20};
static void __ELEVATOR_A39 () {
__ELEVATOR_V21 = _true;
}
static int __ELEVATOR_Check39 [] = {1,0,1,21};
static void __ELEVATOR_A40 () {
__ELEVATOR_V22 = 1;
}
static int __ELEVATOR_Check40 [] = {1,0,1,22};
static void __ELEVATOR_A41 () {
__ELEVATOR_V23 = _true;
}
static int __ELEVATOR_Check41 [] = {1,0,1,23};
static void __ELEVATOR_A42 () {
__ELEVATOR_V12 = _true;
}
static int __ELEVATOR_Check42 [] = {1,0,1,12};
static void __ELEVATOR_A43 () {
__ELEVATOR_V16 = _true;
}
static int __ELEVATOR_Check43 [] = {1,0,1,16};
static void __ELEVATOR_A44 () {
__ELEVATOR_V13 = _true;
}
static int __ELEVATOR_Check44 [] = {1,0,1,13};
static void __ELEVATOR_A45 () {
__ELEVATOR_V17 = _true;
}
static int __ELEVATOR_Check45 [] = {1,0,1,17};
static void __ELEVATOR_A46 () {
__ELEVATOR_V14 = _true;
}
static int __ELEVATOR_Check46 [] = {1,0,1,14};
static void __ELEVATOR_A47 () {
__ELEVATOR_V18 = _true;
}
static int __ELEVATOR_Check47 [] = {1,0,1,18};
static void __ELEVATOR_A48 () {
__ELEVATOR_V15 = _true;
}
static int __ELEVATOR_Check48 [] = {1,0,1,15};
static void __ELEVATOR_A49 () {
__ELEVATOR_V19 = _true;
}
static int __ELEVATOR_Check49 [] = {1,0,1,19};
static void __ELEVATOR_A50 () {
__ELEVATOR_V12 = _false;
}
static int __ELEVATOR_Check50 [] = {1,0,1,12};
static void __ELEVATOR_A51 () {
__ELEVATOR_V16 = _false;
}
static int __ELEVATOR_Check51 [] = {1,0,1,16};
static void __ELEVATOR_A52 () {
__ELEVATOR_V13 = _false;
}
static int __ELEVATOR_Check52 [] = {1,0,1,13};
static void __ELEVATOR_A53 () {
__ELEVATOR_V17 = _false;
}
static int __ELEVATOR_Check53 [] = {1,0,1,17};
static void __ELEVATOR_A54 () {
__ELEVATOR_V14 = _false;
}
static int __ELEVATOR_Check54 [] = {1,0,1,14};
static void __ELEVATOR_A55 () {
__ELEVATOR_V18 = _false;
}
static int __ELEVATOR_Check55 [] = {1,0,1,18};
static void __ELEVATOR_A56 () {
__ELEVATOR_V15 = _false;
}
static int __ELEVATOR_Check56 [] = {1,0,1,15};
static void __ELEVATOR_A57 () {
__ELEVATOR_V19 = _false;
}
static int __ELEVATOR_Check57 [] = {1,0,1,19};
static void __ELEVATOR_A58 () {
__ELEVATOR_V20 = _true;
}
static int __ELEVATOR_Check58 [] = {1,0,1,20};
static void __ELEVATOR_A59 () {
__ELEVATOR_V11 = 4;
}
static int __ELEVATOR_Check59 [] = {1,0,1,11};
static void __ELEVATOR_A60 () {
__ELEVATOR_V22 = 4;
}
static int __ELEVATOR_Check60 [] = {1,0,1,22};
static void __ELEVATOR_A61 () {
__ELEVATOR_V11 = 3;
}
static int __ELEVATOR_Check61 [] = {1,0,1,11};
static void __ELEVATOR_A62 () {
__ELEVATOR_V22 = 3;
}
static int __ELEVATOR_Check62 [] = {1,0,1,22};
static void __ELEVATOR_A63 () {
__ELEVATOR_V21 = _false;
}
static int __ELEVATOR_Check63 [] = {1,0,1,21};
static void __ELEVATOR_A64 () {
__ELEVATOR_V11 = 1;
}
static int __ELEVATOR_Check64 [] = {1,0,1,11};
static void __ELEVATOR_A65 () {
__ELEVATOR_V22 = 1;
}
static int __ELEVATOR_Check65 [] = {1,0,1,22};
static void __ELEVATOR_A66 () {
__ELEVATOR_V11 = 2;
}
static int __ELEVATOR_Check66 [] = {1,0,1,11};
static void __ELEVATOR_A67 () {
__ELEVATOR_V22 = 2;
}
static int __ELEVATOR_Check67 [] = {1,0,1,22};
static void __ELEVATOR_A68 () {
__ELEVATOR_V11 = 3;
}
static int __ELEVATOR_Check68 [] = {1,0,1,11};
static void __ELEVATOR_A69 () {
__ELEVATOR_V22 = 3;
}
static int __ELEVATOR_Check69 [] = {1,0,1,22};
static void __ELEVATOR_A70 () {
__ELEVATOR_V11 = 1;
}
static int __ELEVATOR_Check70 [] = {1,0,1,11};
static void __ELEVATOR_A71 () {
__ELEVATOR_V22 = 1;
}
static int __ELEVATOR_Check71 [] = {1,0,1,22};
static void __ELEVATOR_A72 () {
__ELEVATOR_V11 = 2;
}
static int __ELEVATOR_Check72 [] = {1,0,1,11};
static void __ELEVATOR_A73 () {
__ELEVATOR_V22 = 2;
}
static int __ELEVATOR_Check73 [] = {1,0,1,22};
static void __ELEVATOR_A74 () {
__ELEVATOR_V21 = _true;
}
static int __ELEVATOR_Check74 [] = {1,0,1,21};
static void __ELEVATOR_A75 () {
__ELEVATOR_V11 = 4;
}
static int __ELEVATOR_Check75 [] = {1,0,1,11};
static void __ELEVATOR_A76 () {
__ELEVATOR_V22 = 4;
}
static int __ELEVATOR_Check76 [] = {1,0,1,22};
static void __ELEVATOR_A77 () {
__ELEVATOR_V11 = 3;
}
static int __ELEVATOR_Check77 [] = {1,0,1,11};
static void __ELEVATOR_A78 () {
__ELEVATOR_V22 = 3;
}
static int __ELEVATOR_Check78 [] = {1,0,1,22};
static void __ELEVATOR_A79 () {
__ELEVATOR_V11 = 2;
}
static int __ELEVATOR_Check79 [] = {1,0,1,11};
static void __ELEVATOR_A80 () {
__ELEVATOR_V22 = 2;
}
static int __ELEVATOR_Check80 [] = {1,0,1,22};
static void __ELEVATOR_A81 () {
__ELEVATOR_V20 = _false;
}
static int __ELEVATOR_Check81 [] = {1,0,1,20};
static void __ELEVATOR_A82 () {
__ELEVATOR_V23 = _false;
}
static int __ELEVATOR_Check82 [] = {1,0,1,23};
static void __ELEVATOR_A83 () {
__ELEVATOR_V23 = _true;
}
static int __ELEVATOR_Check83 [] = {1,0,1,23};
static void __ELEVATOR_A84 () {
__ELEVATOR_V24 = 1;
}
static int __ELEVATOR_Check84 [] = {1,0,1,24};
static void __ELEVATOR_A85 () {
__ELEVATOR_V26 = _false;
}
static int __ELEVATOR_Check85 [] = {1,0,1,26};
static void __ELEVATOR_A86 () {
__ELEVATOR_V27 = _true;
}
static int __ELEVATOR_Check86 [] = {1,0,1,27};
static void __ELEVATOR_A87 () {
__ELEVATOR_V10 = __ELEVATOR_V24;
}
static int __ELEVATOR_Check87 [] = {1,1,24,1,10};
static void __ELEVATOR_A88 () {
__ELEVATOR_V26 = _true;
}
static int __ELEVATOR_Check88 [] = {1,0,1,26};
static void __ELEVATOR_A89 () {
__ELEVATOR_V26 = _false;
}
static int __ELEVATOR_Check89 [] = {1,0,1,26};
static void __ELEVATOR_A90 () {
__ELEVATOR_V26 = _false;
}
static int __ELEVATOR_Check90 [] = {1,0,1,26};
static void __ELEVATOR_A91 () {
__ELEVATOR_V27 = _false;
}
static int __ELEVATOR_Check91 [] = {1,0,1,27};
static void __ELEVATOR_A92 () {
__ELEVATOR_V25 = __ELEVATOR_V24-__ELEVATOR_V11;
}
static int __ELEVATOR_Check92 [] = {1,2,24,11,1,25};
static void __ELEVATOR_A93 () {
__ELEVATOR_V28 = __ELEVATOR_V25;
}
static int __ELEVATOR_Check93 [] = {1,1,25,1,28};
static void __ELEVATOR_A94 () {
__ELEVATOR_V24 = __ELEVATOR_V24-1;
}
static int __ELEVATOR_Check94 [] = {1,1,24,1,24};
static void __ELEVATOR_A95 () {
__ELEVATOR_V10 = __ELEVATOR_V24;
}
static int __ELEVATOR_Check95 [] = {1,1,24,1,10};
static void __ELEVATOR_A96 () {
__ELEVATOR_V26 = _true;
}
static int __ELEVATOR_Check96 [] = {1,0,1,26};
static void __ELEVATOR_A97 () {
__ELEVATOR_V26 = _false;
}
static int __ELEVATOR_Check97 [] = {1,0,1,26};
static void __ELEVATOR_A98 () {
__ELEVATOR_V27 = _true;
}
static int __ELEVATOR_Check98 [] = {1,0,1,27};
static void __ELEVATOR_A99 () {
__ELEVATOR_V25 = __ELEVATOR_V11-__ELEVATOR_V24;
}
static int __ELEVATOR_Check99 [] = {1,2,11,24,1,25};
static void __ELEVATOR_A100 () {
__ELEVATOR_V29 = __ELEVATOR_V25;
}
static int __ELEVATOR_Check100 [] = {1,1,25,1,29};
static void __ELEVATOR_A101 () {
__ELEVATOR_V24 = __ELEVATOR_V24+1;
}
static int __ELEVATOR_Check101 [] = {1,1,24,1,24};
static void __ELEVATOR_A102 () {
__ELEVATOR_V10 = __ELEVATOR_V24;
}
static int __ELEVATOR_Check102 [] = {1,1,24,1,10};
static void __ELEVATOR_A103 () {
__ELEVATOR_V26 = _true;
}
static int __ELEVATOR_Check103 [] = {1,0,1,26};
static void __ELEVATOR_A104 () {
__ELEVATOR_V26 = _false;
}
static int __ELEVATOR_Check104 [] = {1,0,1,26};
static void __ELEVATOR_A105 () {
__ELEVATOR_V26 = _true;
}
static int __ELEVATOR_Check105 [] = {1,0,1,26};
static void __ELEVATOR_A106 () {
__ELEVATOR_V26 = _false;
}
static int __ELEVATOR_Check106 [] = {1,0,1,26};
static void __ELEVATOR_A107 () {
__ELEVATOR_V30 = 3;
}
static int __ELEVATOR_Check107 [] = {1,0,1,30};
static void __ELEVATOR_A108 () {
__ELEVATOR_V31 = 16-1;
}
static int __ELEVATOR_Check108 [] = {1,0,1,31};
static void __ELEVATOR_A109 () {
__ELEVATOR_V32 = 3;
}
static int __ELEVATOR_Check109 [] = {1,0,1,32};
static void __ELEVATOR_A110 () {
__ELEVATOR_V33 = 16-1;
}
static int __ELEVATOR_Check110 [] = {1,0,1,33};
static void __ELEVATOR_A111 () {
__ELEVATOR_V34 = 3;
}
static int __ELEVATOR_Check111 [] = {1,0,1,34};
static void __ELEVATOR_A112 () {
__ELEVATOR_V35 = 3;
}
static int __ELEVATOR_Check112 [] = {1,0,1,35};

/* PROCEDURE CALLS */

/* CONDITIONS */

static int __ELEVATOR_A113 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V10==1);
}
static int __ELEVATOR_Check113 [] = {1,1,10,0};
static int __ELEVATOR_A114 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V12);
}
static int __ELEVATOR_Check114 [] = {1,1,12,0};
static int __ELEVATOR_A115 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V16);
}
static int __ELEVATOR_Check115 [] = {1,1,16,0};
static int __ELEVATOR_A116 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V10==2);
}
static int __ELEVATOR_Check116 [] = {1,1,10,0};
static int __ELEVATOR_A117 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V13);
}
static int __ELEVATOR_Check117 [] = {1,1,13,0};
static int __ELEVATOR_A118 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V17);
}
static int __ELEVATOR_Check118 [] = {1,1,17,0};
static int __ELEVATOR_A119 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V10==3);
}
static int __ELEVATOR_Check119 [] = {1,1,10,0};
static int __ELEVATOR_A120 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V14);
}
static int __ELEVATOR_Check120 [] = {1,1,14,0};
static int __ELEVATOR_A121 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V18);
}
static int __ELEVATOR_Check121 [] = {1,1,18,0};
static int __ELEVATOR_A122 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V10==4);
}
static int __ELEVATOR_Check122 [] = {1,1,10,0};
static int __ELEVATOR_A123 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V15);
}
static int __ELEVATOR_Check123 [] = {1,1,15,0};
static int __ELEVATOR_A124 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V19);
}
static int __ELEVATOR_Check124 [] = {1,1,19,0};
static int __ELEVATOR_A125 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V10==__ELEVATOR_V22);
}
static int __ELEVATOR_Check125 [] = {1,2,10,22,0};
static int __ELEVATOR_A126 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V20&&__ELEVATOR_V23&&(__ELEVATOR_V12||__ELEVATOR_V13||__ELEVATOR_V14||__ELEVATOR_V15));
}
static int __ELEVATOR_Check126 [] = {1,6,20,23,12,13,14,15,0};
static int __ELEVATOR_A127 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V21);
}
static int __ELEVATOR_Check127 [] = {1,1,21,0};
static int __ELEVATOR_A128 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V15&&(__ELEVATOR_V22<4));
}
static int __ELEVATOR_Check128 [] = {1,2,15,22,0};
static int __ELEVATOR_A129 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V14&&(__ELEVATOR_V22<3));
}
static int __ELEVATOR_Check129 [] = {1,2,14,22,0};
static int __ELEVATOR_A130 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V12);
}
static int __ELEVATOR_Check130 [] = {1,1,12,0};
static int __ELEVATOR_A131 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V13);
}
static int __ELEVATOR_Check131 [] = {1,1,13,0};
static int __ELEVATOR_A132 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V14);
}
static int __ELEVATOR_Check132 [] = {1,1,14,0};
static int __ELEVATOR_A133 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V12&&(__ELEVATOR_V22>1));
}
static int __ELEVATOR_Check133 [] = {1,2,12,22,0};
static int __ELEVATOR_A134 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V13&&(__ELEVATOR_V22>2));
}
static int __ELEVATOR_Check134 [] = {1,2,13,22,0};
static int __ELEVATOR_A135 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V15);
}
static int __ELEVATOR_Check135 [] = {1,1,15,0};
static int __ELEVATOR_A136 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V13);
}
static int __ELEVATOR_Check136 [] = {1,1,13,0};
static int __ELEVATOR_A137 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V14);
}
static int __ELEVATOR_Check137 [] = {1,1,14,0};
static int __ELEVATOR_A138 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V24==__ELEVATOR_V11);
}
static int __ELEVATOR_Check138 [] = {1,2,24,11,0};
static int __ELEVATOR_A139 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V26==_false);
}
static int __ELEVATOR_Check139 [] = {1,1,26,0};
static int __ELEVATOR_A140 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V26==_true);
}
static int __ELEVATOR_Check140 [] = {1,1,26,0};
static int __ELEVATOR_A141 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V24>__ELEVATOR_V11);
}
static int __ELEVATOR_Check141 [] = {1,2,24,11,0};
static int __ELEVATOR_A142 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V28>0);
}
static int __ELEVATOR_Check142 [] = {1,1,28,0};
static int __ELEVATOR_A143 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V29>0);
}
static int __ELEVATOR_Check143 [] = {1,1,29,0};
static int __ELEVATOR_A144 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V26==_false);
}
static int __ELEVATOR_Check144 [] = {1,1,26,0};
static int __ELEVATOR_A145 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V30>0);
}
static int __ELEVATOR_Check145 [] = {1,1,30,0};
static int __ELEVATOR_A146 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V31>0);
}
static int __ELEVATOR_Check146 [] = {1,1,31,0};
static int __ELEVATOR_A147 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V32>0);
}
static int __ELEVATOR_Check147 [] = {1,1,32,0};
static int __ELEVATOR_A148 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V33>0);
}
static int __ELEVATOR_Check148 [] = {1,1,33,0};
static int __ELEVATOR_A149 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V34>0);
}
static int __ELEVATOR_Check149 [] = {1,1,34,0};
static int __ELEVATOR_A150 () {
__ELEVATOR_GENERIC_TEST(__ELEVATOR_V35>0);
}
static int __ELEVATOR_Check150 [] = {1,1,35,0};

/* DECREMENTS */

static int __ELEVATOR_A151 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V28));
}
static int __ELEVATOR_Check151 [] = {1,1,28,1,28};
static int __ELEVATOR_A152 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V29));
}
static int __ELEVATOR_Check152 [] = {1,1,29,1,29};
static int __ELEVATOR_A153 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V30));
}
static int __ELEVATOR_Check153 [] = {1,1,30,1,30};
static int __ELEVATOR_A154 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V31));
}
static int __ELEVATOR_Check154 [] = {1,1,31,1,31};
static int __ELEVATOR_A155 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V32));
}
static int __ELEVATOR_Check155 [] = {1,1,32,1,32};
static int __ELEVATOR_A156 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V33));
}
static int __ELEVATOR_Check156 [] = {1,1,33,1,33};
static int __ELEVATOR_A157 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V34));
}
static int __ELEVATOR_Check157 [] = {1,1,34,1,34};
static int __ELEVATOR_A158 () {
__ELEVATOR_GENERIC_TEST(__DSZ(__ELEVATOR_V35));
}
static int __ELEVATOR_Check158 [] = {1,1,35,1,35};

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __ELEVATOR_A159 () {
;
__ResetVariable(10);
}
static int __ELEVATOR_Check159 [] = {1,0,0};
static void __ELEVATOR_A160 () {
;
__ResetVariable(11);
}
static int __ELEVATOR_Check160 [] = {1,0,0};
static void __ELEVATOR_A161 () {
;
__ResetVariable(25);
}
static int __ELEVATOR_Check161 [] = {1,0,0};

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
__ELEVATOR_Check102,
__ELEVATOR_Check103,
__ELEVATOR_Check104,
__ELEVATOR_Check105,
__ELEVATOR_Check106,
__ELEVATOR_Check107,
__ELEVATOR_Check108,
__ELEVATOR_Check109,
__ELEVATOR_Check110,
__ELEVATOR_Check111,
__ELEVATOR_Check112,
__ELEVATOR_Check113,
__ELEVATOR_Check114,
__ELEVATOR_Check115,
__ELEVATOR_Check116,
__ELEVATOR_Check117,
__ELEVATOR_Check118,
__ELEVATOR_Check119,
__ELEVATOR_Check120,
__ELEVATOR_Check121,
__ELEVATOR_Check122,
__ELEVATOR_Check123,
__ELEVATOR_Check124,
__ELEVATOR_Check125,
__ELEVATOR_Check126,
__ELEVATOR_Check127,
__ELEVATOR_Check128,
__ELEVATOR_Check129,
__ELEVATOR_Check130,
__ELEVATOR_Check131,
__ELEVATOR_Check132,
__ELEVATOR_Check133,
__ELEVATOR_Check134,
__ELEVATOR_Check135,
__ELEVATOR_Check136,
__ELEVATOR_Check137,
__ELEVATOR_Check138,
__ELEVATOR_Check139,
__ELEVATOR_Check140,
__ELEVATOR_Check141,
__ELEVATOR_Check142,
__ELEVATOR_Check143,
__ELEVATOR_Check144,
__ELEVATOR_Check145,
__ELEVATOR_Check146,
__ELEVATOR_Check147,
__ELEVATOR_Check148,
__ELEVATOR_Check149,
__ELEVATOR_Check150,
__ELEVATOR_Check151,
__ELEVATOR_Check152,
__ELEVATOR_Check153,
__ELEVATOR_Check154,
__ELEVATOR_Check155,
__ELEVATOR_Check156,
__ELEVATOR_Check157,
__ELEVATOR_Check158,
__ELEVATOR_Check159,
__ELEVATOR_Check160,
__ELEVATOR_Check161
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
{"ELEVATOR",0,"./src/strl","elevator.strl",{1,1,1,0},{1,24,1,0},{0,0,0,0}},
{"BUTTONS",0,"./src/strl","buttons.strl",{1,1,1,1},{1,149,1,1},{1,16,9,0}},
{"CABIN",0,"./src/strl","cabin.strl",{1,1,1,2},{1,82,1,2},{1,20,9,0}},
{"OpenDoor",2,"./src/strl","tools.strl",{1,1,1,3},{1,9,1,3},{1,18,21,2}},
{"DoorAwaitingTime",2,"./src/strl","tools.strl",{1,34,1,4},{1,41,1,4},{1,20,21,2}},
{"CloseDoor",2,"./src/strl","tools.strl",{1,12,1,5},{1,20,1,5},{1,21,21,2}},
{"CloseDoor",2,"./src/strl","tools.strl",{1,12,1,6},{1,20,1,6},{1,28,21,2}},
{"FloorProcessingTime",2,"./src/strl","tools.strl",{1,23,1,7},{1,31,1,7},{1,36,25,2}},
{"OpenDoor",2,"./src/strl","tools.strl",{1,1,1,8},{1,9,1,8},{1,40,29,2}},
{"DoorAwaitingTime",2,"./src/strl","tools.strl",{1,34,1,9},{1,41,1,9},{1,42,29,2}},
{"CloseDoor",2,"./src/strl","tools.strl",{1,12,1,10},{1,20,1,10},{1,43,29,2}},
{"FloorProcessingTime",2,"./src/strl","tools.strl",{1,23,1,11},{1,31,1,11},{1,51,25,2}},
{"OpenDoor",2,"./src/strl","tools.strl",{1,1,1,12},{1,9,1,12},{1,55,29,2}},
{"DoorAwaitingTime",2,"./src/strl","tools.strl",{1,34,1,13},{1,41,1,13},{1,57,29,2}},
{"CloseDoor",2,"./src/strl","tools.strl",{1,12,1,14},{1,20,1,14},{1,58,29,2}},
{"OpenDoor",2,"./src/strl","tools.strl",{1,1,1,15},{1,9,1,15},{1,69,17,2}},
{"DoorAwaitingTime",2,"./src/strl","tools.strl",{1,34,1,16},{1,41,1,16},{1,71,17,2}},
{"CloseDoor",2,"./src/strl","tools.strl",{1,12,1,17},{1,20,1,17},{1,72,17,2}},
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
{"DOOROPENED",34,0,0,{1,8,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"DOORCLOSED",34,0,0,{1,8,24,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CURRENTFLOOR",2,10,0,{1,9,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"WRONG",34,0,0,{1,10,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"LF1",34,0,0,{1,11,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"LF2",34,0,0,{1,11,17,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"LF3",34,0,0,{1,11,22,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"LF4",34,0,0,{1,11,27,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"LOUT",34,0,0,{1,11,32,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"STOP",40,0,0,{1,14,12,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"ENDPROCESS",40,0,0,{1,14,18,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TARGET",8,11,0,{1,14,30,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

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
{"__ELEVATOR_V10","V10","integer",-3,1,0,(char*)&__ELEVATOR_V10,"CURRENTFLOOR",0,0,0,{1,9,12,0}},
{"__ELEVATOR_V11","V11","integer",-3,1,0,(char*)&__ELEVATOR_V11,"TARGET",0,0,0,{1,14,30,0}},
{"__ELEVATOR_V12","V12","boolean",-2,0,0,(char*)&__ELEVATOR_V12,"stateF1",0,0,0,{1,14,10,1}},
{"__ELEVATOR_V13","V13","boolean",-2,0,0,(char*)&__ELEVATOR_V13,"stateF2",0,0,0,{1,14,34,1}},
{"__ELEVATOR_V14","V14","boolean",-2,0,0,(char*)&__ELEVATOR_V14,"stateF3",0,0,0,{1,14,58,1}},
{"__ELEVATOR_V15","V15","boolean",-2,0,0,(char*)&__ELEVATOR_V15,"stateF4",0,0,0,{1,14,82,1}},
{"__ELEVATOR_V16","V16","boolean",-2,0,0,(char*)&__ELEVATOR_V16,"lightF1",0,0,0,{1,14,106,1}},
{"__ELEVATOR_V17","V17","boolean",-2,0,0,(char*)&__ELEVATOR_V17,"lightF2",0,0,0,{1,14,130,1}},
{"__ELEVATOR_V18","V18","boolean",-2,0,0,(char*)&__ELEVATOR_V18,"lightF3",0,0,0,{1,14,154,1}},
{"__ELEVATOR_V19","V19","boolean",-2,0,0,(char*)&__ELEVATOR_V19,"lightF4",0,0,0,{1,14,178,1}},
{"__ELEVATOR_V20","V20","boolean",-2,0,0,(char*)&__ELEVATOR_V20,"elevatorFree",0,0,0,{1,14,202,1}},
{"__ELEVATOR_V21","V21","boolean",-2,0,0,(char*)&__ELEVATOR_V21,"elevatorUpState",0,0,0,{1,14,230,1}},
{"__ELEVATOR_V22","V22","integer",-3,0,0,(char*)&__ELEVATOR_V22,"nextFloor",0,0,0,{1,14,261,1}},
{"__ELEVATOR_V23","V23","boolean",-2,0,0,(char*)&__ELEVATOR_V23,"endprocess",0,0,0,{1,14,283,1}},
{"__ELEVATOR_V24","V24","integer",-3,0,0,(char*)&__ELEVATOR_V24,"floor",0,0,0,{1,9,9,2}},
{"__ELEVATOR_V25","V25","integer",-3,0,0,(char*)&__ELEVATOR_V25,"duration",0,0,0,{1,9,27,2}},
{"__ELEVATOR_V26","V26","boolean",-2,0,0,(char*)&__ELEVATOR_V26,"doorOpenState",0,0,0,{1,9,45,2}},
{"__ELEVATOR_V27","V27","boolean",-2,0,0,(char*)&__ELEVATOR_V27,"elevatorUpState",0,0,0,{1,9,75,2}},
{"__ELEVATOR_V28","V28","integer",-3,3,0,(char*)&__ELEVATOR_V28,"0",0,0,0,{1,35,28,2}},
{"__ELEVATOR_V29","V29","integer",-3,3,0,(char*)&__ELEVATOR_V29,"0",0,0,0,{1,50,28,2}},
{"__ELEVATOR_V30","V30","integer",-3,3,0,(char*)&__ELEVATOR_V30,"0",0,0,0,{1,37,12,4}},
{"__ELEVATOR_V31","V31","integer",-3,3,0,(char*)&__ELEVATOR_V31,"0",0,0,0,{1,27,14,7}},
{"__ELEVATOR_V32","V32","integer",-3,3,0,(char*)&__ELEVATOR_V32,"0",0,0,0,{1,37,12,9}},
{"__ELEVATOR_V33","V33","integer",-3,3,0,(char*)&__ELEVATOR_V33,"0",0,0,0,{1,27,14,11}},
{"__ELEVATOR_V34","V34","integer",-3,3,0,(char*)&__ELEVATOR_V34,"0",0,0,0,{1,37,12,13}},
{"__ELEVATOR_V35","V35","integer",-3,3,0,(char*)&__ELEVATOR_V35,"0",0,0,0,{1,37,12,16}}
};

struct __HaltEntry __ELEVATOR_HaltTable [] = {
{{1,24,1,0}},
{{1,145,9,1}},
{{1,13,6,2}},
{{1,78,9,2}},
{{1,5,5,3}},
{{1,6,5,3}},
{{1,38,9,4}},
{{1,16,5,5}},
{{1,17,5,5}},
{{1,16,5,6}},
{{1,17,5,6}},
{{1,26,5,7}},
{{1,28,9,7}},
{{1,5,5,8}},
{{1,6,5,8}},
{{1,38,9,9}},
{{1,16,5,10}},
{{1,17,5,10}},
{{1,26,5,11}},
{{1,28,9,11}},
{{1,5,5,12}},
{{1,6,5,12}},
{{1,38,9,13}},
{{1,16,5,14}},
{{1,17,5,14}},
{{1,5,5,15}},
{{1,6,5,15}},
{{1,38,9,16}},
{{1,16,5,17}},
{{1,17,5,17}}
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
18,0,22,10,0,0,9,3,0,0,0,36,0,30,0,0,0,
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

static __SSC_BIT_TYPE __ELEVATOR_R[30] = {_true,
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

static __SSC_BIT_TYPE E[88];

__ELEVATOR_ModuleData.awaited_list = __ELEVATOR_AwaitedList;
__ResetModuleEntryBeforeReaction();
E[0] = __ELEVATOR_R[5]&&!(__ELEVATOR_R[0]);
E[1] = E[0]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[2] = __ELEVATOR_R[14]&&!(__ELEVATOR_R[0]);
E[3] = E[2]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[4] = __ELEVATOR_R[21]&&!(__ELEVATOR_R[0]);
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
if (E[1]||E[3]||E[5]||E[7]) {
__AppendToList(__ELEVATOR_EmittedList,10);
}
if (E[1]||E[3]||E[5]||E[7]) {
__CheckVariables(__ELEVATOR_CheckArray[11]);__ELEVATOR_A11();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A11\n");
#endif
}
E[8] = __ELEVATOR_R[8]&&!(__ELEVATOR_R[0]);
E[9] = E[8]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[10] = __ELEVATOR_R[10]&&!(__ELEVATOR_R[0]);
E[11] = E[10]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[12] = __ELEVATOR_R[17]&&!(__ELEVATOR_R[0]);
E[13] = E[12]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[14] = __ELEVATOR_R[24]&&!(__ELEVATOR_R[0]);
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
if (E[9]||E[11]||E[13]||E[15]||E[17]) {
__AppendToList(__ELEVATOR_EmittedList,11);
}
if (E[9]||E[11]||E[13]||E[15]||E[17]) {
__CheckVariables(__ELEVATOR_CheckArray[12]);__ELEVATOR_A12();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A12\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[159]);__ELEVATOR_A159();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A159\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[160]);__ELEVATOR_A160();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A160\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[84]);__ELEVATOR_A84();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A84\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[161]);__ELEVATOR_A161();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A161\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[85]);__ELEVATOR_A85();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A85\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[86]);__ELEVATOR_A86();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A86\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[87]);__ELEVATOR_A87();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A87\n");
#endif
}
E[18] = __ELEVATOR_R[12]&&!(__ELEVATOR_R[0]);
E[19] = E[18]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[20] = E[19]&&(__CheckVariables(__ELEVATOR_CheckArray[154]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 154\n"),
#endif
__ELEVATOR_A154());
E[21] = __ELEVATOR_R[11]&&!(__ELEVATOR_R[0]);
E[22] = E[21]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
if (E[22]) {
__CheckVariables(__ELEVATOR_CheckArray[108]);__ELEVATOR_A108();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A108\n");
#endif
}
E[23] = E[22]&&(__CheckVariables(__ELEVATOR_CheckArray[146]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 146\n"),
#endif
__ELEVATOR_A146());
E[24] = E[20]||(E[22]&&!(E[23]));
if (E[24]) {
__CheckVariables(__ELEVATOR_CheckArray[94]);__ELEVATOR_A94();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A94\n");
#endif
}
if (E[24]) {
__CheckVariables(__ELEVATOR_CheckArray[95]);__ELEVATOR_A95();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A95\n");
#endif
}
E[25] = __ELEVATOR_R[19]&&!(__ELEVATOR_R[0]);
E[26] = E[25]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[27] = E[26]&&(__CheckVariables(__ELEVATOR_CheckArray[156]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 156\n"),
#endif
__ELEVATOR_A156());
E[28] = __ELEVATOR_R[18]&&!(__ELEVATOR_R[0]);
E[29] = E[28]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
if (E[29]) {
__CheckVariables(__ELEVATOR_CheckArray[110]);__ELEVATOR_A110();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A110\n");
#endif
}
E[30] = E[29]&&(__CheckVariables(__ELEVATOR_CheckArray[148]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 148\n"),
#endif
__ELEVATOR_A148());
E[31] = E[27]||(E[29]&&!(E[30]));
if (E[31]) {
__CheckVariables(__ELEVATOR_CheckArray[101]);__ELEVATOR_A101();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A101\n");
#endif
}
if (E[31]) {
__CheckVariables(__ELEVATOR_CheckArray[102]);__ELEVATOR_A102();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A102\n");
#endif
}
E[32] = __ELEVATOR_R[0]||E[24]||E[31];
if (E[32]) {
__AppendToList(__ELEVATOR_EmittedList,12);
}
if (E[32]) {
__CheckVariables(__ELEVATOR_CheckArray[13]);__ELEVATOR_A13();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A13\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[30]);__ELEVATOR_A30();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A30\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[31]);__ELEVATOR_A31();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A31\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[32]);__ELEVATOR_A32();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A32\n");
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
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[35]);__ELEVATOR_A35();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A35\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[36]);__ELEVATOR_A36();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A36\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[37]);__ELEVATOR_A37();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A37\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[38]);__ELEVATOR_A38();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A38\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[39]);__ELEVATOR_A39();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A39\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[40]);__ELEVATOR_A40();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A40\n");
#endif
}
if (__ELEVATOR_R[0]) {
__CheckVariables(__ELEVATOR_CheckArray[41]);__ELEVATOR_A41();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A41\n");
#endif
}
E[33] = (__ELEVATOR_R[1]&&!(__ELEVATOR_R[0]))||__ELEVATOR_R[0];
E[34] = (__CheckVariables(__ELEVATOR_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__ELEVATOR_A2())||(__CheckVariables(__ELEVATOR_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__ELEVATOR_A6());
E[35] = E[33]&&E[34];
if (E[35]) {
__CheckVariables(__ELEVATOR_CheckArray[42]);__ELEVATOR_A42();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A42\n");
#endif
}
E[36] = E[35]&&(__CheckVariables(__ELEVATOR_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__ELEVATOR_A6());
if (E[36]) {
__CheckVariables(__ELEVATOR_CheckArray[43]);__ELEVATOR_A43();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A43\n");
#endif
}
E[37] = E[35]&&!((__CheckVariables(__ELEVATOR_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__ELEVATOR_A6()));
E[34] = E[36]||E[37]||(E[33]&&!(E[34]));
E[33] = (__CheckVariables(__ELEVATOR_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__ELEVATOR_A3())||(__CheckVariables(__ELEVATOR_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__ELEVATOR_A7());
E[37] = E[34]&&E[33];
if (E[37]) {
__CheckVariables(__ELEVATOR_CheckArray[44]);__ELEVATOR_A44();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A44\n");
#endif
}
E[38] = E[37]&&(__CheckVariables(__ELEVATOR_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__ELEVATOR_A7());
if (E[38]) {
__CheckVariables(__ELEVATOR_CheckArray[45]);__ELEVATOR_A45();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A45\n");
#endif
}
E[39] = E[37]&&!((__CheckVariables(__ELEVATOR_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__ELEVATOR_A7()));
E[33] = E[38]||E[39]||(E[34]&&!(E[33]));
E[34] = (__CheckVariables(__ELEVATOR_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__ELEVATOR_A4())||(__CheckVariables(__ELEVATOR_CheckArray[8]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__ELEVATOR_A8());
E[39] = E[33]&&E[34];
if (E[39]) {
__CheckVariables(__ELEVATOR_CheckArray[46]);__ELEVATOR_A46();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A46\n");
#endif
}
E[40] = E[39]&&(__CheckVariables(__ELEVATOR_CheckArray[8]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__ELEVATOR_A8());
if (E[40]) {
__CheckVariables(__ELEVATOR_CheckArray[47]);__ELEVATOR_A47();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A47\n");
#endif
}
E[41] = E[39]&&!((__CheckVariables(__ELEVATOR_CheckArray[8]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__ELEVATOR_A8()));
E[34] = E[40]||E[41]||(E[33]&&!(E[34]));
E[33] = (__CheckVariables(__ELEVATOR_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__ELEVATOR_A5())||(__CheckVariables(__ELEVATOR_CheckArray[9]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__ELEVATOR_A9());
E[41] = E[34]&&E[33];
if (E[41]) {
__CheckVariables(__ELEVATOR_CheckArray[48]);__ELEVATOR_A48();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A48\n");
#endif
}
E[42] = E[41]&&(__CheckVariables(__ELEVATOR_CheckArray[9]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__ELEVATOR_A9());
if (E[42]) {
__CheckVariables(__ELEVATOR_CheckArray[49]);__ELEVATOR_A49();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A49\n");
#endif
}
E[43] = E[41]&&!((__CheckVariables(__ELEVATOR_CheckArray[9]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__ELEVATOR_A9()));
E[33] = E[42]||E[43]||(E[34]&&!(E[33]));
E[34] = E[33]&&E[32];
E[43] = E[34]&&(__CheckVariables(__ELEVATOR_CheckArray[113]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 113\n"),
#endif
__ELEVATOR_A113());
E[34] = E[34]&&!(E[43]);
E[44] = E[34]&&(__CheckVariables(__ELEVATOR_CheckArray[116]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 116\n"),
#endif
__ELEVATOR_A116());
E[34] = E[34]&&!(E[44]);
E[45] = E[34]&&(__CheckVariables(__ELEVATOR_CheckArray[119]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 119\n"),
#endif
__ELEVATOR_A119());
E[34] = E[34]&&!(E[45]);
E[46] = E[34]&&(__CheckVariables(__ELEVATOR_CheckArray[122]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 122\n"),
#endif
__ELEVATOR_A122());
E[34] = E[34]&&!(E[46]);
if (E[34]) {
__AppendToList(__ELEVATOR_EmittedList,13);
}
if (E[34]) {
__CheckVariables(__ELEVATOR_CheckArray[14]);__ELEVATOR_A14();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A14\n");
#endif
}
E[47] = E[43]&&(__CheckVariables(__ELEVATOR_CheckArray[114]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 114\n"),
#endif
__ELEVATOR_A114());
if (E[47]) {
__CheckVariables(__ELEVATOR_CheckArray[50]);__ELEVATOR_A50();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A50\n");
#endif
}
E[48] = E[47]&&(__CheckVariables(__ELEVATOR_CheckArray[115]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 115\n"),
#endif
__ELEVATOR_A115());
if (E[36]||E[48]) {
__AppendToList(__ELEVATOR_EmittedList,14);
}
if (E[36]||E[48]) {
__CheckVariables(__ELEVATOR_CheckArray[15]);__ELEVATOR_A15();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A15\n");
#endif
}
E[49] = E[44]&&(__CheckVariables(__ELEVATOR_CheckArray[117]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 117\n"),
#endif
__ELEVATOR_A117());
if (E[49]) {
__CheckVariables(__ELEVATOR_CheckArray[52]);__ELEVATOR_A52();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A52\n");
#endif
}
E[50] = E[49]&&(__CheckVariables(__ELEVATOR_CheckArray[118]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 118\n"),
#endif
__ELEVATOR_A118());
if (E[38]||E[50]) {
__AppendToList(__ELEVATOR_EmittedList,15);
}
if (E[38]||E[50]) {
__CheckVariables(__ELEVATOR_CheckArray[16]);__ELEVATOR_A16();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A16\n");
#endif
}
E[51] = E[45]&&(__CheckVariables(__ELEVATOR_CheckArray[120]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 120\n"),
#endif
__ELEVATOR_A120());
if (E[51]) {
__CheckVariables(__ELEVATOR_CheckArray[54]);__ELEVATOR_A54();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A54\n");
#endif
}
E[52] = E[51]&&(__CheckVariables(__ELEVATOR_CheckArray[121]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 121\n"),
#endif
__ELEVATOR_A121());
if (E[40]||E[52]) {
__AppendToList(__ELEVATOR_EmittedList,16);
}
if (E[40]||E[52]) {
__CheckVariables(__ELEVATOR_CheckArray[17]);__ELEVATOR_A17();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A17\n");
#endif
}
E[53] = E[46]&&(__CheckVariables(__ELEVATOR_CheckArray[123]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 123\n"),
#endif
__ELEVATOR_A123());
if (E[53]) {
__CheckVariables(__ELEVATOR_CheckArray[56]);__ELEVATOR_A56();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A56\n");
#endif
}
E[54] = E[53]&&(__CheckVariables(__ELEVATOR_CheckArray[124]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 124\n"),
#endif
__ELEVATOR_A124());
if (E[42]||E[54]) {
__AppendToList(__ELEVATOR_EmittedList,17);
}
if (E[42]||E[54]) {
__CheckVariables(__ELEVATOR_CheckArray[18]);__ELEVATOR_A18();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A18\n");
#endif
}
E[55] = __ELEVATOR_R[2]&&!(__ELEVATOR_R[0]);
if (E[48]) {
__CheckVariables(__ELEVATOR_CheckArray[51]);__ELEVATOR_A51();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A51\n");
#endif
}
E[56] = E[48]||(E[47]&&!(E[48]));
if (E[50]) {
__CheckVariables(__ELEVATOR_CheckArray[53]);__ELEVATOR_A53();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A53\n");
#endif
}
E[57] = E[50]||(E[49]&&!(E[50]));
if (E[52]) {
__CheckVariables(__ELEVATOR_CheckArray[55]);__ELEVATOR_A55();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A55\n");
#endif
}
E[58] = E[52]||(E[51]&&!(E[52]));
if (E[54]) {
__CheckVariables(__ELEVATOR_CheckArray[57]);__ELEVATOR_A57();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A57\n");
#endif
}
E[59] = E[54]||(E[53]&&!(E[54]));
E[46] = E[56]||(E[43]&&!(E[47]))||E[57]||(E[44]&&!(E[49]))||E[58]||(E[45]&&!(E[51]))||E[59]||(E[46]&&!(E[53]))||E[34];
E[45] = E[46]&&(__CheckVariables(__ELEVATOR_CheckArray[125]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 125\n"),
#endif
__ELEVATOR_A125());
if (E[45]) {
__CheckVariables(__ELEVATOR_CheckArray[58]);__ELEVATOR_A58();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A58\n");
#endif
}
E[33] = E[45]||(E[46]&&!(E[45]))||(E[33]&&!(E[32]));
E[46] = E[33]&&(__CheckVariables(__ELEVATOR_CheckArray[126]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 126\n"),
#endif
__ELEVATOR_A126());
E[44] = E[46]&&(__CheckVariables(__ELEVATOR_CheckArray[127]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 127\n"),
#endif
__ELEVATOR_A127());
E[43] = E[44]&&(__CheckVariables(__ELEVATOR_CheckArray[128]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 128\n"),
#endif
__ELEVATOR_A128());
E[60] = E[44]&&!(E[43]);
E[61] = E[60]&&(__CheckVariables(__ELEVATOR_CheckArray[129]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 129\n"),
#endif
__ELEVATOR_A129());
E[60] = E[60]&&!(E[61]);
if (E[60]) {
__CheckVariables(__ELEVATOR_CheckArray[63]);__ELEVATOR_A63();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A63\n");
#endif
}
E[62] = E[60]&&(__CheckVariables(__ELEVATOR_CheckArray[130]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 130\n"),
#endif
__ELEVATOR_A130());
E[63] = E[60]&&!(E[62]);
E[64] = E[63]&&(__CheckVariables(__ELEVATOR_CheckArray[131]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 131\n"),
#endif
__ELEVATOR_A131());
E[63] = E[63]&&!(E[64]);
E[65] = E[63]&&(__CheckVariables(__ELEVATOR_CheckArray[132]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 132\n"),
#endif
__ELEVATOR_A132());
E[44] = E[46]&&!(E[44]);
E[66] = E[44]&&(__CheckVariables(__ELEVATOR_CheckArray[133]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 133\n"),
#endif
__ELEVATOR_A133());
E[44] = E[44]&&!(E[66]);
E[67] = E[44]&&(__CheckVariables(__ELEVATOR_CheckArray[134]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 134\n"),
#endif
__ELEVATOR_A134());
E[44] = E[44]&&!(E[67]);
if (E[44]) {
__CheckVariables(__ELEVATOR_CheckArray[74]);__ELEVATOR_A74();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A74\n");
#endif
}
E[68] = E[44]&&(__CheckVariables(__ELEVATOR_CheckArray[135]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 135\n"),
#endif
__ELEVATOR_A135());
E[69] = E[44]&&!(E[68]);
E[70] = E[69]&&(__CheckVariables(__ELEVATOR_CheckArray[136]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 136\n"),
#endif
__ELEVATOR_A136());
E[69] = E[69]&&!(E[70]);
E[71] = E[69]&&(__CheckVariables(__ELEVATOR_CheckArray[137]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 137\n"),
#endif
__ELEVATOR_A137());
E[72] = E[43]||E[61]||E[62]||E[64]||E[65]||E[66]||E[67]||E[68]||E[70]||E[71];
if (E[72]) {
__AppendToList(__ELEVATOR_EmittedList,21);
}
E[73] = E[55]&&E[72];
if (E[9]) {
__CheckVariables(__ELEVATOR_CheckArray[89]);__ELEVATOR_A89();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A89\n");
#endif
}
if (E[43]) {
__CheckVariables(__ELEVATOR_CheckArray[59]);__ELEVATOR_A59();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A59\n");
#endif
}
if (E[61]) {
__CheckVariables(__ELEVATOR_CheckArray[61]);__ELEVATOR_A61();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A61\n");
#endif
}
if (E[62]) {
__CheckVariables(__ELEVATOR_CheckArray[64]);__ELEVATOR_A64();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A64\n");
#endif
}
if (E[64]) {
__CheckVariables(__ELEVATOR_CheckArray[66]);__ELEVATOR_A66();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A66\n");
#endif
}
if (E[65]) {
__CheckVariables(__ELEVATOR_CheckArray[68]);__ELEVATOR_A68();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A68\n");
#endif
}
if (E[66]) {
__CheckVariables(__ELEVATOR_CheckArray[70]);__ELEVATOR_A70();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A70\n");
#endif
}
if (E[67]) {
__CheckVariables(__ELEVATOR_CheckArray[72]);__ELEVATOR_A72();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A72\n");
#endif
}
if (E[68]) {
__CheckVariables(__ELEVATOR_CheckArray[75]);__ELEVATOR_A75();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A75\n");
#endif
}
if (E[70]) {
__CheckVariables(__ELEVATOR_CheckArray[77]);__ELEVATOR_A77();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A77\n");
#endif
}
if (E[71]) {
__CheckVariables(__ELEVATOR_CheckArray[79]);__ELEVATOR_A79();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A79\n");
#endif
}
E[74] = E[73]&&(__CheckVariables(__ELEVATOR_CheckArray[138]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 138\n"),
#endif
__ELEVATOR_A138());
E[75] = E[74]&&(__CheckVariables(__ELEVATOR_CheckArray[139]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 139\n"),
#endif
__ELEVATOR_A139());
if (E[13]) {
__CheckVariables(__ELEVATOR_CheckArray[97]);__ELEVATOR_A97();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A97\n");
#endif
}
E[59] = E[56]||E[57]||E[58]||E[59];
if (E[59]) {
__AppendToList(__ELEVATOR_EmittedList,19);
}
E[58] = E[13]||(E[24]&&!(E[59]));
E[57] = E[58]&&(__CheckVariables(__ELEVATOR_CheckArray[151]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 151\n"),
#endif
__ELEVATOR_A151());
if (E[11]) {
__CheckVariables(__ELEVATOR_CheckArray[90]);__ELEVATOR_A90();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A90\n");
#endif
}
E[56] = E[73]&&!(E[74]);
E[76] = E[56]&&(__CheckVariables(__ELEVATOR_CheckArray[140]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 140\n"),
#endif
__ELEVATOR_A140());
E[56] = E[11]||(E[56]&&!(E[76]));
E[77] = E[56]&&(__CheckVariables(__ELEVATOR_CheckArray[141]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 141\n"),
#endif
__ELEVATOR_A141());
if (E[77]) {
__CheckVariables(__ELEVATOR_CheckArray[91]);__ELEVATOR_A91();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A91\n");
#endif
}
if (E[77]) {
__CheckVariables(__ELEVATOR_CheckArray[92]);__ELEVATOR_A92();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A92\n");
#endif
}
if (E[77]) {
__CheckVariables(__ELEVATOR_CheckArray[93]);__ELEVATOR_A93();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A93\n");
#endif
}
E[78] = E[77]&&(__CheckVariables(__ELEVATOR_CheckArray[142]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 142\n"),
#endif
__ELEVATOR_A142());
if (E[15]) {
__CheckVariables(__ELEVATOR_CheckArray[104]);__ELEVATOR_A104();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A104\n");
#endif
}
E[79] = E[15]||(E[31]&&!(E[59]));
E[80] = E[79]&&(__CheckVariables(__ELEVATOR_CheckArray[152]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 152\n"),
#endif
__ELEVATOR_A152());
E[56] = E[56]&&!(E[77]);
if (E[56]) {
__CheckVariables(__ELEVATOR_CheckArray[98]);__ELEVATOR_A98();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A98\n");
#endif
}
if (E[56]) {
__CheckVariables(__ELEVATOR_CheckArray[99]);__ELEVATOR_A99();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A99\n");
#endif
}
if (E[56]) {
__CheckVariables(__ELEVATOR_CheckArray[100]);__ELEVATOR_A100();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A100\n");
#endif
}
E[81] = E[56]&&(__CheckVariables(__ELEVATOR_CheckArray[143]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 143\n"),
#endif
__ELEVATOR_A143());
if (E[17]) {
__CheckVariables(__ELEVATOR_CheckArray[106]);__ELEVATOR_A106();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A106\n");
#endif
}
E[72] = E[55]&&!(E[72]);
E[55] = E[72]&&(__CheckVariables(__ELEVATOR_CheckArray[10]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 10\n"),
#endif
__ELEVATOR_A10());
E[82] = E[55]&&(__CheckVariables(__ELEVATOR_CheckArray[144]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 144\n"),
#endif
__ELEVATOR_A144());
E[74] = E[9]||(E[74]&&!(E[75]))||E[57]||(E[77]&&!(E[78]))||E[80]||(E[56]&&!(E[81]))||E[17]||(E[55]&&!(E[82]));
if (E[73]||E[74]||E[55]) {
__AppendToList(__ELEVATOR_EmittedList,18);
}
if (E[73]||E[74]||E[55]) {
__CheckVariables(__ELEVATOR_CheckArray[19]);__ELEVATOR_A19();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A19\n");
#endif
}
E[83] = __ELEVATOR_R[0]||(__ELEVATOR_R[3]&&!(__ELEVATOR_R[0]));
if (E[83]) {
__AppendToList(__ELEVATOR_EmittedList,20);
}
E[84] = !(_true);
if (E[43]) {
__CheckVariables(__ELEVATOR_CheckArray[60]);__ELEVATOR_A60();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A60\n");
#endif
}
if (E[61]) {
__CheckVariables(__ELEVATOR_CheckArray[62]);__ELEVATOR_A62();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A62\n");
#endif
}
if (E[62]) {
__CheckVariables(__ELEVATOR_CheckArray[65]);__ELEVATOR_A65();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A65\n");
#endif
}
if (E[64]) {
__CheckVariables(__ELEVATOR_CheckArray[67]);__ELEVATOR_A67();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A67\n");
#endif
}
if (E[65]) {
__CheckVariables(__ELEVATOR_CheckArray[69]);__ELEVATOR_A69();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A69\n");
#endif
}
if (E[66]) {
__CheckVariables(__ELEVATOR_CheckArray[71]);__ELEVATOR_A71();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A71\n");
#endif
}
if (E[67]) {
__CheckVariables(__ELEVATOR_CheckArray[73]);__ELEVATOR_A73();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A73\n");
#endif
}
if (E[68]) {
__CheckVariables(__ELEVATOR_CheckArray[76]);__ELEVATOR_A76();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A76\n");
#endif
}
if (E[70]) {
__CheckVariables(__ELEVATOR_CheckArray[78]);__ELEVATOR_A78();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A78\n");
#endif
}
if (E[71]) {
__CheckVariables(__ELEVATOR_CheckArray[80]);__ELEVATOR_A80();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A80\n");
#endif
}
E[69] = E[43]||E[61]||E[62]||E[64]||E[65]||(E[63]&&!(E[65]))||E[66]||E[67]||E[68]||E[70]||E[71]||(E[69]&&!(E[71]));
if (E[69]) {
__CheckVariables(__ELEVATOR_CheckArray[81]);__ELEVATOR_A81();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A81\n");
#endif
}
if (E[69]) {
__CheckVariables(__ELEVATOR_CheckArray[82]);__ELEVATOR_A82();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A82\n");
#endif
}
E[46] = E[69]||(E[33]&&!(E[46]));
E[33] = E[46]&&E[83];
if (E[33]) {
__CheckVariables(__ELEVATOR_CheckArray[83]);__ELEVATOR_A83();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A83\n");
#endif
}
E[46] = E[33]||(E[46]&&!(E[83]));
E[72] = E[72]&&!((__CheckVariables(__ELEVATOR_CheckArray[10]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 10\n"),
#endif
__ELEVATOR_A10()));
E[72] = E[83]||(__ELEVATOR_R[2]&&E[72]);
E[83] = __ELEVATOR_R[4]&&!(__ELEVATOR_R[0]);
E[63] = E[83]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[63] = E[75]||(__ELEVATOR_R[4]&&E[63]);
E[83] = E[83]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[0] = E[0]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[0] = E[83]||(__ELEVATOR_R[5]&&E[0]);
if (E[1]) {
__CheckVariables(__ELEVATOR_CheckArray[88]);__ELEVATOR_A88();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A88\n");
#endif
}
if (E[1]) {
__CheckVariables(__ELEVATOR_CheckArray[107]);__ELEVATOR_A107();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A107\n");
#endif
}
E[83] = E[1]&&(__CheckVariables(__ELEVATOR_CheckArray[145]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 145\n"),
#endif
__ELEVATOR_A145());
E[75] = __ELEVATOR_R[6]&&!(__ELEVATOR_R[0]);
E[85] = E[75]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[86] = E[85]&&(__CheckVariables(__ELEVATOR_CheckArray[153]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 153\n"),
#endif
__ELEVATOR_A153());
E[75] = E[75]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[75] = E[83]||(E[85]&&!(E[86]))||(__ELEVATOR_R[6]&&E[75]);
E[85] = __ELEVATOR_R[7]&&!(__ELEVATOR_R[0]);
E[87] = E[85]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[87] = E[86]||(E[1]&&!(E[83]))||(__ELEVATOR_R[7]&&E[87]);
E[85] = E[85]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[8] = E[8]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[8] = E[85]||(__ELEVATOR_R[8]&&E[8]);
E[85] = __ELEVATOR_R[9]&&!(__ELEVATOR_R[0]);
E[83] = E[85]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[83] = E[76]||(__ELEVATOR_R[9]&&E[83]);
E[85] = E[85]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[10] = E[10]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[10] = E[85]||(__ELEVATOR_R[10]&&E[10]);
E[21] = E[21]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[21] = E[78]||(E[58]&&!(E[57]))||(__ELEVATOR_R[11]&&E[21]);
E[18] = E[18]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[18] = E[23]||(E[19]&&!(E[20]))||(__ELEVATOR_R[12]&&E[18]);
E[20] = __ELEVATOR_R[13]&&!(__ELEVATOR_R[0]);
E[19] = E[20]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[19] = (E[24]&&E[59])||(__ELEVATOR_R[13]&&E[19]);
E[20] = E[20]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[2] = E[2]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[2] = E[20]||(__ELEVATOR_R[14]&&E[2]);
if (E[3]) {
__CheckVariables(__ELEVATOR_CheckArray[96]);__ELEVATOR_A96();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A96\n");
#endif
}
if (E[3]) {
__CheckVariables(__ELEVATOR_CheckArray[109]);__ELEVATOR_A109();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A109\n");
#endif
}
E[20] = E[3]&&(__CheckVariables(__ELEVATOR_CheckArray[147]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 147\n"),
#endif
__ELEVATOR_A147());
E[23] = __ELEVATOR_R[15]&&!(__ELEVATOR_R[0]);
E[57] = E[23]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[58] = E[57]&&(__CheckVariables(__ELEVATOR_CheckArray[155]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 155\n"),
#endif
__ELEVATOR_A155());
E[23] = E[23]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[23] = E[20]||(E[57]&&!(E[58]))||(__ELEVATOR_R[15]&&E[23]);
E[57] = __ELEVATOR_R[16]&&!(__ELEVATOR_R[0]);
E[78] = E[57]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[78] = E[58]||(E[3]&&!(E[20]))||(__ELEVATOR_R[16]&&E[78]);
E[57] = E[57]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[12] = E[12]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[12] = E[57]||(__ELEVATOR_R[17]&&E[12]);
E[28] = E[28]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[28] = E[81]||(E[79]&&!(E[80]))||(__ELEVATOR_R[18]&&E[28]);
E[25] = E[25]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[25] = E[30]||(E[26]&&!(E[27]))||(__ELEVATOR_R[19]&&E[25]);
E[27] = __ELEVATOR_R[20]&&!(__ELEVATOR_R[0]);
E[26] = E[27]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[26] = (E[31]&&E[59])||(__ELEVATOR_R[20]&&E[26]);
E[27] = E[27]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[4] = E[4]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[4] = E[27]||(__ELEVATOR_R[21]&&E[4]);
if (E[5]) {
__CheckVariables(__ELEVATOR_CheckArray[103]);__ELEVATOR_A103();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A103\n");
#endif
}
if (E[5]) {
__CheckVariables(__ELEVATOR_CheckArray[111]);__ELEVATOR_A111();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A111\n");
#endif
}
E[27] = E[5]&&(__CheckVariables(__ELEVATOR_CheckArray[149]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 149\n"),
#endif
__ELEVATOR_A149());
E[59] = __ELEVATOR_R[22]&&!(__ELEVATOR_R[0]);
E[30] = E[59]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[80] = E[30]&&(__CheckVariables(__ELEVATOR_CheckArray[157]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 157\n"),
#endif
__ELEVATOR_A157());
E[59] = E[59]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[59] = E[27]||(E[30]&&!(E[80]))||(__ELEVATOR_R[22]&&E[59]);
E[30] = __ELEVATOR_R[23]&&!(__ELEVATOR_R[0]);
E[79] = E[30]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[79] = E[80]||(E[5]&&!(E[27]))||(__ELEVATOR_R[23]&&E[79]);
E[30] = E[30]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[14] = E[14]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[14] = E[30]||(__ELEVATOR_R[24]&&E[14]);
E[30] = __ELEVATOR_R[25]&&!(__ELEVATOR_R[0]);
E[27] = E[30]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[27] = E[82]||(__ELEVATOR_R[25]&&E[27]);
E[30] = E[30]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[6] = E[6]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[6] = E[30]||(__ELEVATOR_R[26]&&E[6]);
if (E[7]) {
__CheckVariables(__ELEVATOR_CheckArray[105]);__ELEVATOR_A105();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A105\n");
#endif
}
if (E[7]) {
__CheckVariables(__ELEVATOR_CheckArray[112]);__ELEVATOR_A112();
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A112\n");
#endif
}
E[30] = E[7]&&(__CheckVariables(__ELEVATOR_CheckArray[150]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 150\n"),
#endif
__ELEVATOR_A150());
E[82] = __ELEVATOR_R[27]&&!(__ELEVATOR_R[0]);
E[80] = E[82]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[81] = E[80]&&(__CheckVariables(__ELEVATOR_CheckArray[158]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 158\n"),
#endif
__ELEVATOR_A158());
E[82] = E[82]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[82] = E[30]||(E[80]&&!(E[81]))||(__ELEVATOR_R[27]&&E[82]);
E[80] = __ELEVATOR_R[28]&&!(__ELEVATOR_R[0]);
E[57] = E[80]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[57] = E[81]||(E[7]&&!(E[30]))||(__ELEVATOR_R[28]&&E[57]);
E[80] = E[80]&&(__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1());
E[16] = E[16]&&!((__CheckVariables(__ELEVATOR_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1()));
E[16] = E[80]||(__ELEVATOR_R[29]&&E[16]);
E[80] = __ELEVATOR_R[2]||__ELEVATOR_R[4]||__ELEVATOR_R[5]||__ELEVATOR_R[6]||__ELEVATOR_R[7]||__ELEVATOR_R[8]||__ELEVATOR_R[3]||__ELEVATOR_R[9]||__ELEVATOR_R[10]||__ELEVATOR_R[11]||__ELEVATOR_R[12]||__ELEVATOR_R[13]||__ELEVATOR_R[14]||__ELEVATOR_R[15]||__ELEVATOR_R[16]||__ELEVATOR_R[17]||__ELEVATOR_R[18]||__ELEVATOR_R[19]||__ELEVATOR_R[20]||__ELEVATOR_R[21]||__ELEVATOR_R[22]||__ELEVATOR_R[23]||__ELEVATOR_R[24]||__ELEVATOR_R[25]||__ELEVATOR_R[26]||__ELEVATOR_R[27]||__ELEVATOR_R[28]||__ELEVATOR_R[29];
E[30] = __ELEVATOR_R[1]||E[80];
E[80] = (E[46]||E[72]||E[63]||E[0]||E[75]||E[87]||E[8]||E[74]||E[83]||E[10]||E[21]||E[18]||E[19]||E[2]||E[23]||E[78]||E[12]||E[28]||E[25]||E[26]||E[4]||E[59]||E[79]||E[14]||E[27]||E[6]||E[82]||E[57]||E[16])&&((E[30]&&!(__ELEVATOR_R[1]))||E[46])&&((E[30]&&!(E[80]))||E[72]||E[63]||E[0]||E[75]||E[87]||E[8]||E[74]||E[83]||E[10]||E[21]||E[18]||E[19]||E[2]||E[23]||E[78]||E[12]||E[28]||E[25]||E[26]||E[4]||E[59]||E[79]||E[14]||E[27]||E[6]||E[82]||E[57]||E[16]);
__ELEVATOR_R[0] = !(_true);
__ELEVATOR_R[1] = E[46];
if (__ELEVATOR_R[1]) { __AppendToList(__ELEVATOR_HaltList,1); }
__ELEVATOR_R[2] = E[72];
if (__ELEVATOR_R[2]) { __AppendToList(__ELEVATOR_HaltList,2); }
__ELEVATOR_R[3] = E[74];
if (__ELEVATOR_R[3]) { __AppendToList(__ELEVATOR_HaltList,3); }
__ELEVATOR_R[4] = E[63];
if (__ELEVATOR_R[4]) { __AppendToList(__ELEVATOR_HaltList,4); }
__ELEVATOR_R[5] = E[0];
if (__ELEVATOR_R[5]) { __AppendToList(__ELEVATOR_HaltList,5); }
__ELEVATOR_R[6] = E[75];
if (__ELEVATOR_R[6]) { __AppendToList(__ELEVATOR_HaltList,6); }
__ELEVATOR_R[7] = E[87];
if (__ELEVATOR_R[7]) { __AppendToList(__ELEVATOR_HaltList,7); }
__ELEVATOR_R[8] = E[8];
if (__ELEVATOR_R[8]) { __AppendToList(__ELEVATOR_HaltList,8); }
__ELEVATOR_R[9] = E[83];
if (__ELEVATOR_R[9]) { __AppendToList(__ELEVATOR_HaltList,9); }
__ELEVATOR_R[10] = E[10];
if (__ELEVATOR_R[10]) { __AppendToList(__ELEVATOR_HaltList,10); }
__ELEVATOR_R[11] = E[21];
if (__ELEVATOR_R[11]) { __AppendToList(__ELEVATOR_HaltList,11); }
__ELEVATOR_R[12] = E[18];
if (__ELEVATOR_R[12]) { __AppendToList(__ELEVATOR_HaltList,12); }
__ELEVATOR_R[13] = E[19];
if (__ELEVATOR_R[13]) { __AppendToList(__ELEVATOR_HaltList,13); }
__ELEVATOR_R[14] = E[2];
if (__ELEVATOR_R[14]) { __AppendToList(__ELEVATOR_HaltList,14); }
__ELEVATOR_R[15] = E[23];
if (__ELEVATOR_R[15]) { __AppendToList(__ELEVATOR_HaltList,15); }
__ELEVATOR_R[16] = E[78];
if (__ELEVATOR_R[16]) { __AppendToList(__ELEVATOR_HaltList,16); }
__ELEVATOR_R[17] = E[12];
if (__ELEVATOR_R[17]) { __AppendToList(__ELEVATOR_HaltList,17); }
__ELEVATOR_R[18] = E[28];
if (__ELEVATOR_R[18]) { __AppendToList(__ELEVATOR_HaltList,18); }
__ELEVATOR_R[19] = E[25];
if (__ELEVATOR_R[19]) { __AppendToList(__ELEVATOR_HaltList,19); }
__ELEVATOR_R[20] = E[26];
if (__ELEVATOR_R[20]) { __AppendToList(__ELEVATOR_HaltList,20); }
__ELEVATOR_R[21] = E[4];
if (__ELEVATOR_R[21]) { __AppendToList(__ELEVATOR_HaltList,21); }
__ELEVATOR_R[22] = E[59];
if (__ELEVATOR_R[22]) { __AppendToList(__ELEVATOR_HaltList,22); }
__ELEVATOR_R[23] = E[79];
if (__ELEVATOR_R[23]) { __AppendToList(__ELEVATOR_HaltList,23); }
__ELEVATOR_R[24] = E[14];
if (__ELEVATOR_R[24]) { __AppendToList(__ELEVATOR_HaltList,24); }
__ELEVATOR_R[25] = E[27];
if (__ELEVATOR_R[25]) { __AppendToList(__ELEVATOR_HaltList,25); }
__ELEVATOR_R[26] = E[6];
if (__ELEVATOR_R[26]) { __AppendToList(__ELEVATOR_HaltList,26); }
__ELEVATOR_R[27] = E[82];
if (__ELEVATOR_R[27]) { __AppendToList(__ELEVATOR_HaltList,27); }
__ELEVATOR_R[28] = E[57];
if (__ELEVATOR_R[28]) { __AppendToList(__ELEVATOR_HaltList,28); }
__ELEVATOR_R[29] = E[16];
if (__ELEVATOR_R[29]) { __AppendToList(__ELEVATOR_HaltList,29); }
if (!E[80]) { __AppendToList(__ELEVATOR_HaltList,0); }
__ResetModuleEntryAfterReaction();
__ELEVATOR_ModuleData.awaited_list = __ELEVATOR_AllAwaitedList;
__ELEVATOR__reset_input();
return E[80];
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
__ELEVATOR__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__ELEVATOR_ModuleData
};
