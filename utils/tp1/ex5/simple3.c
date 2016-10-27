/* sscc : C CODE OF SORTED EQUATIONS simple3 - INLINE MODE */

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
#define _true 1
#define _false 0
#define __simple3_GENERIC_TEST(TEST) return TEST;
typedef void (*__simple3_APF)();
static __simple3_APF *__simple3_PActionArray;

                     
/* EXTERN DECLARATIONS */

#ifndef _NO_EXTERN_DEFINITIONS
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static integer __simple3_V0;
static boolean __simple3_V1;
static integer __simple3_V2;


/* INPUT FUNCTIONS */

void simple3_I_IN (integer __V) {
__simple3_V0 = __V;
__simple3_V1 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __simple3_A1 \
__simple3_V1

/* OUTPUT ACTIONS */

#define __simple3_A2 \
simple3_O_OUT(__simple3_V2)

/* ASSIGNMENTS */

#define __simple3_A3 \
__simple3_V1 = _false
#define __simple3_A4 \
__simple3_V2 = __simple3_V0

/* PROCEDURE CALLS */

/* CONDITIONS */

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __simple3_A5 \

#define __simple3_A6 \


/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int simple3_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



static void __simple3__reset_input () {
__simple3_V1 = _false;
}

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __simple3_R[2] = {_true,
 _false};

/* AUTOMATON ENGINE */

int simple3 () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[4];
E[0] = __simple3_R[1]&&!(__simple3_R[0]);
E[1] = E[0]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__simple3_A1);
if (E[1]) {
__simple3_A4;
#ifdef TRACE_ACTION
fprintf(stderr, "__simple3_A4\n");
#endif
}
if (E[1]) {
__simple3_A2;
#ifdef TRACE_ACTION
fprintf(stderr, "__simple3_A2\n");
#endif
}
E[2] = __simple3_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__simple3_A1));
if (E[2]) {
__simple3_A5;
#ifdef TRACE_ACTION
fprintf(stderr, "__simple3_A5\n");
#endif
}
if (__simple3_R[0]) {
__simple3_A6;
#ifdef TRACE_ACTION
fprintf(stderr, "__simple3_A6\n");
#endif
}
E[3] = !(_true);
E[0] = E[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__simple3_A1));
__simple3_R[1] = __simple3_R[0]||E[1]||(__simple3_R[1]&&E[0]);
E[0] = __simple3_R[1];
__simple3_R[0] = !(_true);
__simple3__reset_input();
return E[0];
}

/* AUTOMATON RESET */

int simple3_reset () {
__simple3_R[0] = _true;
__simple3_R[1] = _false;
__simple3__reset_input();
return 0;
}
