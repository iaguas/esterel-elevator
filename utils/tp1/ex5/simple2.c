/* sscc : C CODE OF SORTED EQUATIONS simple2 - INLINE MODE */

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
#define __simple2_GENERIC_TEST(TEST) return TEST;
typedef void (*__simple2_APF)();
static __simple2_APF *__simple2_PActionArray;

                     
/* EXTERN DECLARATIONS */

#ifndef _NO_EXTERN_DEFINITIONS
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static integer __simple2_V0;
static boolean __simple2_V1;
static integer __simple2_V2;


/* INPUT FUNCTIONS */

void simple2_I_IN (integer __V) {
__simple2_V0 = __V;
__simple2_V1 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __simple2_A1 \
__simple2_V1

/* OUTPUT ACTIONS */

#define __simple2_A2 \
simple2_O_OUT(__simple2_V2)

/* ASSIGNMENTS */

#define __simple2_A3 \
__simple2_V1 = _false
#define __simple2_A4 \
__simple2_V2 = __simple2_V0
#define __simple2_A5 \
__simple2_V2 = __simple2_V0
#define __simple2_A6 \
__simple2_V2 = __simple2_V0

/* PROCEDURE CALLS */

/* CONDITIONS */

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __simple2_A7 \

#define __simple2_A8 \


/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int simple2_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



static void __simple2__reset_input () {
__simple2_V1 = _false;
}

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __simple2_R[4] = {_true,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int simple2 () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[10];
E[0] = __simple2_R[1]&&!(__simple2_R[0]);
E[1] = E[0]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__simple2_A1);
if (E[1]) {
__simple2_A4;
#ifdef TRACE_ACTION
fprintf(stderr, "__simple2_A4\n");
#endif
}
E[2] = __simple2_R[2]&&!(__simple2_R[0]);
E[3] = E[2]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__simple2_A1);
if (E[3]) {
__simple2_A5;
#ifdef TRACE_ACTION
fprintf(stderr, "__simple2_A5\n");
#endif
}
E[4] = __simple2_R[3]&&!(__simple2_R[0]);
E[5] = E[4]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__simple2_A1);
if (E[5]) {
__simple2_A6;
#ifdef TRACE_ACTION
fprintf(stderr, "__simple2_A6\n");
#endif
}
if (E[1]||E[3]||E[5]) {
__simple2_A2;
#ifdef TRACE_ACTION
fprintf(stderr, "__simple2_A2\n");
#endif
}
E[6] = __simple2_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__simple2_A1));
if (E[6]) {
__simple2_A7;
#ifdef TRACE_ACTION
fprintf(stderr, "__simple2_A7\n");
#endif
}
if (__simple2_R[0]) {
__simple2_A8;
#ifdef TRACE_ACTION
fprintf(stderr, "__simple2_A8\n");
#endif
}
E[7] = E[5];
E[0] = E[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__simple2_A1));
E[0] = __simple2_R[0]||(__simple2_R[1]&&E[0]);
E[2] = E[2]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__simple2_A1));
E[2] = E[1]||(__simple2_R[2]&&E[2]);
E[4] = E[4]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__simple2_A1));
E[4] = E[3]||(__simple2_R[3]&&E[4]);
E[8] = E[0]||E[2]||E[4];
E[9] = __simple2_R[1]||__simple2_R[2]||__simple2_R[3];
__simple2_R[0] = !(_true);
__simple2_R[1] = E[0];
__simple2_R[2] = E[2];
__simple2_R[3] = E[4];
__simple2__reset_input();
return E[8];
}

/* AUTOMATON RESET */

int simple2_reset () {
__simple2_R[0] = _true;
__simple2_R[1] = _false;
__simple2_R[2] = _false;
__simple2_R[3] = _false;
__simple2__reset_input();
return 0;
}
