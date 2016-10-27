/* sscc : C CODE OF SORTED EQUATIONS calcul1 - INLINE MODE */

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
#define __calcul1_GENERIC_TEST(TEST) return TEST;
typedef void (*__calcul1_APF)();
static __calcul1_APF *__calcul1_PActionArray;

                     
/* EXTERN DECLARATIONS */

#ifndef _NO_EXTERN_DEFINITIONS
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static integer __calcul1_V0;
static boolean __calcul1_V1;
static boolean __calcul1_V2;
static boolean __calcul1_V3;
static boolean __calcul1_V4;
static boolean __calcul1_V5;
static integer __calcul1_V6;
static integer __calcul1_V7;
static integer __calcul1_V8;
static integer __calcul1_V9;


/* INPUT FUNCTIONS */

void calcul1_I_OPERANDE (integer __V) {
__calcul1_V0 = __V;
__calcul1_V1 = _true;
}
void calcul1_I_ADDITION () {
__calcul1_V2 = _true;
}
void calcul1_I_SOUSTRACTION () {
__calcul1_V3 = _true;
}
void calcul1_I_DIVISION () {
__calcul1_V4 = _true;
}
void calcul1_I_MULTIPLICATION () {
__calcul1_V5 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __calcul1_A1 \
__calcul1_V1
#define __calcul1_A2 \
__calcul1_V2
#define __calcul1_A3 \
__calcul1_V3
#define __calcul1_A4 \
__calcul1_V4
#define __calcul1_A5 \
__calcul1_V5

/* OUTPUT ACTIONS */

#define __calcul1_A6 \
calcul1_O_LCD(__calcul1_V6)

/* ASSIGNMENTS */

#define __calcul1_A7 \
__calcul1_V1 = _false
#define __calcul1_A8 \
__calcul1_V2 = _false
#define __calcul1_A9 \
__calcul1_V3 = _false
#define __calcul1_A10 \
__calcul1_V4 = _false
#define __calcul1_A11 \
__calcul1_V5 = _false
#define __calcul1_A12 \
__calcul1_V7 = 0
#define __calcul1_A13 \
__calcul1_V8 = 0
#define __calcul1_A14 \
__calcul1_V9 = 0
#define __calcul1_A15 \
__calcul1_V8 = __calcul1_V0
#define __calcul1_A16 \
__calcul1_V9 = __calcul1_V0
#define __calcul1_A17 \
__calcul1_V7 = __calcul1_V8+__calcul1_V9
#define __calcul1_A18 \
__calcul1_V7 = __calcul1_V8-__calcul1_V9
#define __calcul1_A19 \
__calcul1_V7 = __calcul1_V8/__calcul1_V9
#define __calcul1_A20 \
__calcul1_V7 = __calcul1_V8*__calcul1_V9
#define __calcul1_A21 \
__calcul1_V6 = __calcul1_V7

/* PROCEDURE CALLS */

/* CONDITIONS */

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __calcul1_A22 \

#define __calcul1_A23 \

#define __calcul1_A24 \

#define __calcul1_A25 \

#define __calcul1_A26 \


/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int calcul1_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



static void __calcul1__reset_input () {
__calcul1_V1 = _false;
__calcul1_V2 = _false;
__calcul1_V3 = _false;
__calcul1_V4 = _false;
__calcul1_V5 = _false;
}

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __calcul1_R[4] = {_true,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int calcul1 () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[15];
E[0] = __calcul1_R[3]&&!(__calcul1_R[0]);
E[1] = E[0]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__calcul1_A2);
if (E[1]) {
__calcul1_A17;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul1_A17\n");
#endif
}
E[0] = E[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__calcul1_A2));
E[2] = E[0]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__calcul1_A3);
if (E[2]) {
__calcul1_A18;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul1_A18\n");
#endif
}
E[0] = E[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__calcul1_A3));
E[3] = E[0]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__calcul1_A4);
if (E[3]) {
__calcul1_A19;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul1_A19\n");
#endif
}
E[0] = E[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__calcul1_A4));
E[4] = E[0]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__calcul1_A5);
if (E[4]) {
__calcul1_A20;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul1_A20\n");
#endif
}
E[5] = E[1]||E[2]||E[3]||E[4];
if (E[5]) {
__calcul1_A21;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul1_A21\n");
#endif
}
if (E[5]) {
__calcul1_A6;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul1_A6\n");
#endif
}
E[6] = __calcul1_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul1_A1));
if (E[6]) {
__calcul1_A22;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul1_A22\n");
#endif
}
if (__calcul1_R[0]) {
__calcul1_A23;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul1_A23\n");
#endif
}
E[7] = !(_true);
if (__calcul1_R[0]) {
__calcul1_A24;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul1_A24\n");
#endif
}
if (__calcul1_R[0]) {
__calcul1_A25;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul1_A25\n");
#endif
}
if (__calcul1_R[0]) {
__calcul1_A26;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul1_A26\n");
#endif
}
E[8] = __calcul1_R[0]||E[5];
if (E[8]) {
__calcul1_A12;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul1_A12\n");
#endif
}
if (E[8]) {
__calcul1_A13;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul1_A13\n");
#endif
}
if (E[8]) {
__calcul1_A14;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul1_A14\n");
#endif
}
E[9] = __calcul1_R[1]&&!(__calcul1_R[0]);
E[10] = E[9]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul1_A1));
E[10] = E[8]||(__calcul1_R[1]&&E[10]);
E[9] = E[9]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul1_A1);
if (E[9]) {
__calcul1_A15;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul1_A15\n");
#endif
}
E[11] = __calcul1_R[2]&&!(__calcul1_R[0]);
E[12] = E[11]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul1_A1));
E[12] = E[9]||(__calcul1_R[2]&&E[12]);
E[11] = E[11]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul1_A1);
if (E[11]) {
__calcul1_A16;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul1_A16\n");
#endif
}
E[0] = E[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__calcul1_A5));
E[0] = E[11]||(__calcul1_R[3]&&E[0]);
E[13] = E[10]||E[12]||E[0];
E[14] = __calcul1_R[1]||__calcul1_R[2]||__calcul1_R[3];
__calcul1_R[0] = !(_true);
__calcul1_R[1] = E[10];
__calcul1_R[2] = E[12];
__calcul1_R[3] = E[0];
__calcul1__reset_input();
return E[13];
}

/* AUTOMATON RESET */

int calcul1_reset () {
__calcul1_R[0] = _true;
__calcul1_R[1] = _false;
__calcul1_R[2] = _false;
__calcul1_R[3] = _false;
__calcul1__reset_input();
return 0;
}
