/* sscc : C CODE OF SORTED EQUATIONS calcul3 - INLINE MODE */

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
#define __calcul3_GENERIC_TEST(TEST) return TEST;
typedef void (*__calcul3_APF)();
static __calcul3_APF *__calcul3_PActionArray;

                     
/* EXTERN DECLARATIONS */

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


/* INPUT FUNCTIONS */

void calcul3_I_OPERANDE (integer __V) {
__calcul3_V0 = __V;
__calcul3_V1 = _true;
}
void calcul3_I_ADDITION () {
__calcul3_V2 = _true;
}
void calcul3_I_SOUSTRACTION () {
__calcul3_V3 = _true;
}
void calcul3_I_DIVISION () {
__calcul3_V4 = _true;
}
void calcul3_I_MULTIPLICATION () {
__calcul3_V5 = _true;
}
void calcul3_I_RESET () {
__calcul3_V6 = _true;
}
void calcul3_I_SWITCH () {
__calcul3_V7 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __calcul3_A1 \
__calcul3_V1
#define __calcul3_A2 \
__calcul3_V2
#define __calcul3_A3 \
__calcul3_V3
#define __calcul3_A4 \
__calcul3_V4
#define __calcul3_A5 \
__calcul3_V5
#define __calcul3_A6 \
__calcul3_V6
#define __calcul3_A7 \
__calcul3_V7

/* OUTPUT ACTIONS */

#define __calcul3_A8 \
calcul3_O_LCD(__calcul3_V8)
#define __calcul3_A9 \
calcul3_O_WRITE(__calcul3_V9)

/* ASSIGNMENTS */

#define __calcul3_A10 \
__calcul3_V1 = _false
#define __calcul3_A11 \
__calcul3_V2 = _false
#define __calcul3_A12 \
__calcul3_V3 = _false
#define __calcul3_A13 \
__calcul3_V4 = _false
#define __calcul3_A14 \
__calcul3_V5 = _false
#define __calcul3_A15 \
__calcul3_V6 = _false
#define __calcul3_A16 \
__calcul3_V7 = _false
#define __calcul3_A17 \
__calcul3_V10 = 0
#define __calcul3_A18 \
__calcul3_V11 = 0
#define __calcul3_A19 \
__calcul3_V12 = 0
#define __calcul3_A20 \
__calcul3_V13 = 0
#define __calcul3_A21 \
__calcul3_V12 = __calcul3_V0
#define __calcul3_A22 \
__calcul3_V13 = __calcul3_V0
#define __calcul3_A23 \
__calcul3_V11 = __calcul3_V12+__calcul3_V13
#define __calcul3_A24 \
__calcul3_V11 = __calcul3_V12-__calcul3_V13
#define __calcul3_A25 \
__calcul3_V11 = __calcul3_V12/__calcul3_V13
#define __calcul3_A26 \
__calcul3_V11 = __calcul3_V12*__calcul3_V13
#define __calcul3_A27 \
__calcul3_V8 = __calcul3_V11
#define __calcul3_A28 \
__calcul3_V9 = __calcul3_V11
#define __calcul3_A29 \
__calcul3_V8 = 0
#define __calcul3_A30 \
__calcul3_V10 = 1
#define __calcul3_A31 \
__calcul3_V10 = 0

/* PROCEDURE CALLS */

/* CONDITIONS */

#define __calcul3_A32 \
__calcul3_V10==1

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __calcul3_A33 \

#define __calcul3_A34 \

#define __calcul3_A35 \

#define __calcul3_A36 \

#define __calcul3_A37 \

#define __calcul3_A38 \


/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int calcul3_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



static void __calcul3__reset_input () {
__calcul3_V1 = _false;
__calcul3_V2 = _false;
__calcul3_V3 = _false;
__calcul3_V4 = _false;
__calcul3_V5 = _false;
__calcul3_V6 = _false;
__calcul3_V7 = _false;
}

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
E[0] = __calcul3_R[1]||__calcul3_R[2]||__calcul3_R[3];
E[1] = E[0]&&!(__calcul3_R[0]);
E[2] = E[1]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__calcul3_A6);
if (E[2]) {
__calcul3_A29;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A29\n");
#endif
}
E[1] = E[1]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__calcul3_A6));
E[3] = __calcul3_R[3]&&E[1];
E[4] = E[3]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__calcul3_A2);
if (E[4]) {
__calcul3_A23;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A23\n");
#endif
}
E[3] = E[3]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__calcul3_A2));
E[5] = E[3]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__calcul3_A3);
if (E[5]) {
__calcul3_A24;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A24\n");
#endif
}
E[3] = E[3]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__calcul3_A3));
E[6] = E[3]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__calcul3_A4);
if (E[6]) {
__calcul3_A25;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A25\n");
#endif
}
E[3] = E[3]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__calcul3_A4));
E[7] = E[3]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__calcul3_A5);
if (E[7]) {
__calcul3_A26;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A26\n");
#endif
}
E[8] = E[4]||E[5]||E[6]||E[7];
if (E[8]) {
__calcul3_A27;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A27\n");
#endif
}
if (E[2]||E[8]) {
__calcul3_A8;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A8\n");
#endif
}
E[9] = __calcul3_R[4]&&!(__calcul3_R[0]);
E[10] = E[9]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__calcul3_A7);
if (E[10]) {
__calcul3_A30;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A30\n");
#endif
}
E[11] = __calcul3_R[5]&&!(__calcul3_R[0]);
E[12] = E[11]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__calcul3_A7);
if (E[12]) {
__calcul3_A31;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A31\n");
#endif
}
E[13] = E[8]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 32\n"),
#endif
__calcul3_A32);
if (E[13]) {
__calcul3_A28;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A28\n");
#endif
}
if (E[13]) {
__calcul3_A9;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A9\n");
#endif
}
E[14] = E[10]||E[12];
E[15] = __calcul3_R[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul3_A1));
if (E[15]) {
__calcul3_A33;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A33\n");
#endif
}
if (__calcul3_R[0]) {
__calcul3_A34;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A34\n");
#endif
}
if (__calcul3_R[0]) {
__calcul3_A35;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A35\n");
#endif
}
E[16] = !(_true);
if (__calcul3_R[0]) {
__calcul3_A17;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A17\n");
#endif
}
if (__calcul3_R[0]) {
__calcul3_A36;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A36\n");
#endif
}
if (__calcul3_R[0]) {
__calcul3_A37;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A37\n");
#endif
}
if (__calcul3_R[0]) {
__calcul3_A38;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A38\n");
#endif
}
E[17] = __calcul3_R[0]||E[2]||E[13]||(E[8]&&!(E[13]));
if (E[17]) {
__calcul3_A18;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A18\n");
#endif
}
if (E[17]) {
__calcul3_A19;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A19\n");
#endif
}
if (E[17]) {
__calcul3_A20;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A20\n");
#endif
}
E[18] = __calcul3_R[1]&&E[1];
E[19] = E[18]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul3_A1));
__calcul3_R[1] = E[17]||(__calcul3_R[1]&&E[19]);
E[18] = E[18]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul3_A1);
if (E[18]) {
__calcul3_A21;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A21\n");
#endif
}
E[1] = __calcul3_R[2]&&E[1];
E[19] = E[1]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul3_A1));
__calcul3_R[2] = E[18]||(__calcul3_R[2]&&E[19]);
E[1] = E[1]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__calcul3_A1);
if (E[1]) {
__calcul3_A22;
#ifdef TRACE_ACTION
fprintf(stderr, "__calcul3_A22\n");
#endif
}
E[3] = E[3]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__calcul3_A5));
__calcul3_R[3] = E[1]||(__calcul3_R[3]&&E[3]);
E[9] = E[9]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__calcul3_A7));
E[9] = __calcul3_R[0]||E[12]||(__calcul3_R[4]&&E[9]);
E[11] = E[11]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__calcul3_A7));
E[11] = E[10]||(__calcul3_R[5]&&E[11]);
E[3] = __calcul3_R[4]||__calcul3_R[5];
E[19] = E[0]||E[3];
E[3] = (__calcul3_R[1]||__calcul3_R[2]||__calcul3_R[3]||E[9]||E[11])&&((E[19]&&!(E[0]))||__calcul3_R[1]||__calcul3_R[2]||__calcul3_R[3])&&((E[19]&&!(E[3]))||E[9]||E[11]);
__calcul3_R[0] = !(_true);
__calcul3_R[4] = E[9];
__calcul3_R[5] = E[11];
__calcul3__reset_input();
return E[3];
}

/* AUTOMATON RESET */

int calcul3_reset () {
__calcul3_R[0] = _true;
__calcul3_R[1] = _false;
__calcul3_R[2] = _false;
__calcul3_R[3] = _false;
__calcul3_R[4] = _false;
__calcul3_R[5] = _false;
__calcul3__reset_input();
return 0;
}
