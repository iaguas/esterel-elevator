/* sscc : C CODE OF SORTED EQUATIONS calcul2 - INLINE MODE */

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
#define __calcul2_GENERIC_TEST(TEST) return TEST;
typedef void (*__calcul2_APF)();
static __calcul2_APF *__calcul2_PActionArray;

                     
/* EXTERN DECLARATIONS */

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


/* INPUT FUNCTIONS */

void calcul2_I_OPERANDE (integer __V) {
__calcul2_V0 = __V;
__calcul2_V1 = _true;
}
void calcul2_I_ADDITION () {
__calcul2_V2 = _true;
}
void calcul2_I_SOUSTRACTION () {
__calcul2_V3 = _true;
}
void calcul2_I_DIVISION () {
__calcul2_V4 = _true;
}
void calcul2_I_MULTIPLICATION () {
__calcul2_V5 = _true;
}
void calcul2_I_RESET () {
__calcul2_V6 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __calcul2_A1 \
__calcul2_V1
#define __calcul2_A2 \
__calcul2_V2
#define __calcul2_A3 \
__calcul2_V3
#define __calcul2_A4 \
__calcul2_V4
#define __calcul2_A5 \
__calcul2_V5
#define __calcul2_A6 \
__calcul2_V6

/* OUTPUT ACTIONS */

#define __calcul2_A7 \
calcul2_O_LCD(__calcul2_V7)

/* ASSIGNMENTS */

#define __calcul2_A8 \
__calcul2_V1 = _false
#define __calcul2_A9 \
__calcul2_V2 = _false
#define __calcul2_A10 \
__calcul2_V3 = _false
#define __calcul2_A11 \
__calcul2_V4 = _false
#define __calcul2_A12 \
__calcul2_V5 = _false
#define __calcul2_A13 \
__calcul2_V6 = _false
#define __calcul2_A14 \
__calcul2_V8 = 0
#define __calcul2_A15 \
__calcul2_V9 = 0
#define __calcul2_A16 \
__calcul2_V10 = 0
#define __calcul2_A17 \
__calcul2_V9 = __calcul2_V0
#define __calcul2_A18 \
__calcul2_V10 = __calcul2_V0
#define __calcul2_A19 \
__calcul2_V8 = __calcul2_V9+__calcul2_V10
#define __calcul2_A20 \
__calcul2_V8 = __calcul2_V9-__calcul2_V10
#define __calcul2_A21 \
__calcul2_V8 = __calcul2_V9/__calcul2_V10
#define __calcul2_A22 \
__calcul2_V8 = __calcul2_V9*__calcul2_V10
#define __calcul2_A23 \
__calcul2_V7 = __calcul2_V8
#define __calcul2_A24 \
__calcul2_V7 = 0

/* PROCEDURE CALLS */

/* CONDITIONS */

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __calcul2_A25 \

#define __calcul2_A26 \

#define __calcul2_A27 \

#define __calcul2_A28 \

#define __calcul2_A29 \


/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int calcul2_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



static void __calcul2__reset_input () {
__calcul2_V1 = _false;
__calcul2_V2 = _false;
__calcul2_V3 = _false;
__calcul2_V4 = _false;
__calcul2_V5 = _false;
__calcul2_V6 = _false;
}

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
E[0] = (__calcul2_R[1]||__calcul2_R[2]||__calcul2_R[3])&&!(__calcul2_R[0]);
E[1] = E[0]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__calcul2_A6);
if (E[1]) {
__calcul2_A24;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A24\n");
#endif
}
E[0] = E[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__calcul2_A6));
E[2] = __calcul2_R[3]&&E[0];
E[3] = E[2]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__calcul2_A2);
if (E[3]) {
__calcul2_A19;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A19\n");
#endif
}
E[2] = E[2]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__calcul2_A2));
E[4] = E[2]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__calcul2_A3);
if (E[4]) {
__calcul2_A20;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A20\n");
#endif
}
E[2] = E[2]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__calcul2_A3));
E[5] = E[2]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__calcul2_A4);
if (E[5]) {
__calcul2_A21;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A21\n");
#endif
}
E[2] = E[2]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__calcul2_A4));
E[6] = E[2]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__calcul2_A5);
if (E[6]) {
__calcul2_A22;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A22\n");
#endif
}
E[7] = E[3]||E[4]||E[5]||E[6];
if (E[7]) {
__calcul2_A23;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A23\n");
#endif
}
if (E[1]||E[7]) {
__calcul2_A7;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A7\n");
#endif
}
E[8] = __calcul2_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul2_A1));
if (E[8]) {
__calcul2_A25;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A25\n");
#endif
}
if (__calcul2_R[0]) {
__calcul2_A26;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A26\n");
#endif
}
E[9] = !(_true);
if (__calcul2_R[0]) {
__calcul2_A27;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A27\n");
#endif
}
if (__calcul2_R[0]) {
__calcul2_A28;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A28\n");
#endif
}
if (__calcul2_R[0]) {
__calcul2_A29;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A29\n");
#endif
}
E[10] = __calcul2_R[0]||E[1]||E[7];
if (E[10]) {
__calcul2_A14;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A14\n");
#endif
}
if (E[10]) {
__calcul2_A15;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A15\n");
#endif
}
if (E[10]) {
__calcul2_A16;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A16\n");
#endif
}
E[11] = __calcul2_R[1]&&E[0];
E[12] = E[11]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul2_A1));
__calcul2_R[1] = E[10]||(__calcul2_R[1]&&E[12]);
E[11] = E[11]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul2_A1);
if (E[11]) {
__calcul2_A17;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A17\n");
#endif
}
E[0] = __calcul2_R[2]&&E[0];
E[12] = E[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul2_A1));
__calcul2_R[2] = E[11]||(__calcul2_R[2]&&E[12]);
E[0] = E[0]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul2_A1);
if (E[0]) {
__calcul2_A18;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul2_A18\n");
#endif
}
E[2] = E[2]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__calcul2_A5));
__calcul2_R[3] = E[0]||(__calcul2_R[3]&&E[2]);
E[2] = __calcul2_R[1]||__calcul2_R[2]||__calcul2_R[3];
__calcul2_R[0] = !(_true);
__calcul2__reset_input();
return E[2];
}

/* AUTOMATON RESET */

int calcul2_reset () {
__calcul2_R[0] = _true;
__calcul2_R[1] = _false;
__calcul2_R[2] = _false;
__calcul2_R[3] = _false;
__calcul2__reset_input();
return 0;
}
