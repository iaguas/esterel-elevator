/* sscc : C CODE OF SORTED EQUATIONS ELEVATOR - INLINE MODE */

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
#define __ELEVATOR_GENERIC_TEST(TEST) return TEST;
typedef void (*__ELEVATOR_APF)();
static __ELEVATOR_APF *__ELEVATOR_PActionArray;

                      
/* EXTERN DECLARATIONS */

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
static integer __ELEVATOR_V18;
static integer __ELEVATOR_V19;
static integer __ELEVATOR_V20;
static boolean __ELEVATOR_V21;
static boolean __ELEVATOR_V22;
static integer __ELEVATOR_V23;
static integer __ELEVATOR_V24;
static integer __ELEVATOR_V25;
static integer __ELEVATOR_V26;
static integer __ELEVATOR_V27;
static integer __ELEVATOR_V28;
static integer __ELEVATOR_V29;


/* INPUT FUNCTIONS */

void ELEVATOR_I_SECOND () {
__ELEVATOR_V0 = _true;
}
void ELEVATOR_I_CALLF1 () {
__ELEVATOR_V1 = _true;
}
void ELEVATOR_I_CALLF2 () {
__ELEVATOR_V2 = _true;
}
void ELEVATOR_I_CALLF3 () {
__ELEVATOR_V3 = _true;
}
void ELEVATOR_I_CALLF4 () {
__ELEVATOR_V4 = _true;
}
void ELEVATOR_I_GOF1 () {
__ELEVATOR_V5 = _true;
}
void ELEVATOR_I_GOF2 () {
__ELEVATOR_V6 = _true;
}
void ELEVATOR_I_GOF3 () {
__ELEVATOR_V7 = _true;
}
void ELEVATOR_I_GOF4 () {
__ELEVATOR_V8 = _true;
}
void ELEVATOR_I_OPENDOOR () {
__ELEVATOR_V9 = _true;
}

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

#define __ELEVATOR_A1 \
__ELEVATOR_V0
#define __ELEVATOR_A2 \
__ELEVATOR_V1
#define __ELEVATOR_A3 \
__ELEVATOR_V2
#define __ELEVATOR_A4 \
__ELEVATOR_V3
#define __ELEVATOR_A5 \
__ELEVATOR_V4
#define __ELEVATOR_A6 \
__ELEVATOR_V5
#define __ELEVATOR_A7 \
__ELEVATOR_V6
#define __ELEVATOR_A8 \
__ELEVATOR_V7
#define __ELEVATOR_A9 \
__ELEVATOR_V8
#define __ELEVATOR_A10 \
__ELEVATOR_V9

/* OUTPUT ACTIONS */

#define __ELEVATOR_A11 \
ELEVATOR_O_DOOROPENED()
#define __ELEVATOR_A12 \
ELEVATOR_O_DOORCLOSED()
#define __ELEVATOR_A13 \
ELEVATOR_O_CURRENTFLOOR(__ELEVATOR_V10)
#define __ELEVATOR_A14 \
ELEVATOR_O_WRONG()
#define __ELEVATOR_A15 \
ELEVATOR_O_STOP()
#define __ELEVATOR_A16 \
ELEVATOR_O_LF1()
#define __ELEVATOR_A17 \
ELEVATOR_O_LF2()
#define __ELEVATOR_A18 \
ELEVATOR_O_LF3()
#define __ELEVATOR_A19 \
ELEVATOR_O_LF4()
#define __ELEVATOR_A20 \
ELEVATOR_O_LOUT()

/* ASSIGNMENTS */

#define __ELEVATOR_A21 \
__ELEVATOR_V0 = _false
#define __ELEVATOR_A22 \
__ELEVATOR_V1 = _false
#define __ELEVATOR_A23 \
__ELEVATOR_V2 = _false
#define __ELEVATOR_A24 \
__ELEVATOR_V3 = _false
#define __ELEVATOR_A25 \
__ELEVATOR_V4 = _false
#define __ELEVATOR_A26 \
__ELEVATOR_V5 = _false
#define __ELEVATOR_A27 \
__ELEVATOR_V6 = _false
#define __ELEVATOR_A28 \
__ELEVATOR_V7 = _false
#define __ELEVATOR_A29 \
__ELEVATOR_V8 = _false
#define __ELEVATOR_A30 \
__ELEVATOR_V9 = _false
#define __ELEVATOR_A31 \
__ELEVATOR_V12 = _false
#define __ELEVATOR_A32 \
__ELEVATOR_V13 = _false
#define __ELEVATOR_A33 \
__ELEVATOR_V14 = _false
#define __ELEVATOR_A34 \
__ELEVATOR_V15 = _false
#define __ELEVATOR_A35 \
__ELEVATOR_V16 = _true
#define __ELEVATOR_A36 \
__ELEVATOR_V17 = _true
#define __ELEVATOR_A37 \
__ELEVATOR_V18 = 1
#define __ELEVATOR_A38 \
__ELEVATOR_V12 = _true
#define __ELEVATOR_A39 \
__ELEVATOR_V13 = _true
#define __ELEVATOR_A40 \
__ELEVATOR_V14 = _true
#define __ELEVATOR_A41 \
__ELEVATOR_V15 = _true
#define __ELEVATOR_A42 \
__ELEVATOR_V12 = _false
#define __ELEVATOR_A43 \
__ELEVATOR_V13 = _false
#define __ELEVATOR_A44 \
__ELEVATOR_V14 = _false
#define __ELEVATOR_A45 \
__ELEVATOR_V15 = _false
#define __ELEVATOR_A46 \
__ELEVATOR_V16 = _true
#define __ELEVATOR_A47 \
__ELEVATOR_V11 = 4
#define __ELEVATOR_A48 \
__ELEVATOR_V18 = 4
#define __ELEVATOR_A49 \
__ELEVATOR_V11 = 3
#define __ELEVATOR_A50 \
__ELEVATOR_V18 = 3
#define __ELEVATOR_A51 \
__ELEVATOR_V17 = _false
#define __ELEVATOR_A52 \
__ELEVATOR_V11 = 1
#define __ELEVATOR_A53 \
__ELEVATOR_V18 = 1
#define __ELEVATOR_A54 \
__ELEVATOR_V11 = 2
#define __ELEVATOR_A55 \
__ELEVATOR_V18 = 2
#define __ELEVATOR_A56 \
__ELEVATOR_V11 = 3
#define __ELEVATOR_A57 \
__ELEVATOR_V18 = 3
#define __ELEVATOR_A58 \
__ELEVATOR_V11 = 1
#define __ELEVATOR_A59 \
__ELEVATOR_V18 = 1
#define __ELEVATOR_A60 \
__ELEVATOR_V11 = 2
#define __ELEVATOR_A61 \
__ELEVATOR_V18 = 2
#define __ELEVATOR_A62 \
__ELEVATOR_V17 = _true
#define __ELEVATOR_A63 \
__ELEVATOR_V11 = 4
#define __ELEVATOR_A64 \
__ELEVATOR_V18 = 4
#define __ELEVATOR_A65 \
__ELEVATOR_V11 = 3
#define __ELEVATOR_A66 \
__ELEVATOR_V18 = 3
#define __ELEVATOR_A67 \
__ELEVATOR_V11 = 2
#define __ELEVATOR_A68 \
__ELEVATOR_V18 = 2
#define __ELEVATOR_A69 \
__ELEVATOR_V16 = _false
#define __ELEVATOR_A70 \
__ELEVATOR_V19 = 1
#define __ELEVATOR_A71 \
__ELEVATOR_V21 = _false
#define __ELEVATOR_A72 \
__ELEVATOR_V22 = _true
#define __ELEVATOR_A73 \
__ELEVATOR_V10 = __ELEVATOR_V19
#define __ELEVATOR_A74 \
__ELEVATOR_V21 = _true
#define __ELEVATOR_A75 \
__ELEVATOR_V21 = _false
#define __ELEVATOR_A76 \
__ELEVATOR_V22 = _false
#define __ELEVATOR_A77 \
__ELEVATOR_V20 = __ELEVATOR_V19-__ELEVATOR_V11
#define __ELEVATOR_A78 \
__ELEVATOR_V23 = __ELEVATOR_V20
#define __ELEVATOR_A79 \
__ELEVATOR_V19 = __ELEVATOR_V19-1
#define __ELEVATOR_A80 \
__ELEVATOR_V10 = __ELEVATOR_V19
#define __ELEVATOR_A81 \
__ELEVATOR_V21 = _true
#define __ELEVATOR_A82 \
__ELEVATOR_V21 = _false
#define __ELEVATOR_A83 \
__ELEVATOR_V22 = _true
#define __ELEVATOR_A84 \
__ELEVATOR_V20 = __ELEVATOR_V11-__ELEVATOR_V19
#define __ELEVATOR_A85 \
__ELEVATOR_V24 = __ELEVATOR_V20
#define __ELEVATOR_A86 \
__ELEVATOR_V19 = __ELEVATOR_V19+1
#define __ELEVATOR_A87 \
__ELEVATOR_V10 = __ELEVATOR_V19
#define __ELEVATOR_A88 \
__ELEVATOR_V21 = _true
#define __ELEVATOR_A89 \
__ELEVATOR_V21 = _false
#define __ELEVATOR_A90 \
__ELEVATOR_V21 = _true
#define __ELEVATOR_A91 \
__ELEVATOR_V21 = _false
#define __ELEVATOR_A92 \
__ELEVATOR_V25 = 2-1
#define __ELEVATOR_A93 \
__ELEVATOR_V26 = 0
#define __ELEVATOR_A94 \
__ELEVATOR_V27 = 2-1
#define __ELEVATOR_A95 \
__ELEVATOR_V28 = 0
#define __ELEVATOR_A96 \
__ELEVATOR_V29 = 0

/* PROCEDURE CALLS */

/* CONDITIONS */

#define __ELEVATOR_A97 \
__ELEVATOR_V10==1
#define __ELEVATOR_A98 \
__ELEVATOR_V12
#define __ELEVATOR_A99 \
__ELEVATOR_V10==2
#define __ELEVATOR_A100 \
__ELEVATOR_V13
#define __ELEVATOR_A101 \
__ELEVATOR_V10==3
#define __ELEVATOR_A102 \
__ELEVATOR_V14
#define __ELEVATOR_A103 \
__ELEVATOR_V10==4
#define __ELEVATOR_A104 \
__ELEVATOR_V15
#define __ELEVATOR_A105 \
__ELEVATOR_V10==__ELEVATOR_V18
#define __ELEVATOR_A106 \
__ELEVATOR_V16&&(__ELEVATOR_V12||__ELEVATOR_V13||__ELEVATOR_V14||__ELEVATOR_V15)
#define __ELEVATOR_A107 \
__ELEVATOR_V17
#define __ELEVATOR_A108 \
__ELEVATOR_V15&&(__ELEVATOR_V18<4)
#define __ELEVATOR_A109 \
__ELEVATOR_V14&&(__ELEVATOR_V18<3)
#define __ELEVATOR_A110 \
__ELEVATOR_V12
#define __ELEVATOR_A111 \
__ELEVATOR_V13
#define __ELEVATOR_A112 \
__ELEVATOR_V14
#define __ELEVATOR_A113 \
__ELEVATOR_V12&&(__ELEVATOR_V18>1)
#define __ELEVATOR_A114 \
__ELEVATOR_V13&&(__ELEVATOR_V18>2)
#define __ELEVATOR_A115 \
__ELEVATOR_V15
#define __ELEVATOR_A116 \
__ELEVATOR_V13
#define __ELEVATOR_A117 \
__ELEVATOR_V14
#define __ELEVATOR_A118 \
__ELEVATOR_V19==__ELEVATOR_V11
#define __ELEVATOR_A119 \
__ELEVATOR_V21==_false
#define __ELEVATOR_A120 \
__ELEVATOR_V21==_true
#define __ELEVATOR_A121 \
__ELEVATOR_V19>__ELEVATOR_V11
#define __ELEVATOR_A122 \
__ELEVATOR_V23>0
#define __ELEVATOR_A123 \
__ELEVATOR_V24>0
#define __ELEVATOR_A124 \
__ELEVATOR_V21==_false
#define __ELEVATOR_A125 \
__ELEVATOR_V25>0
#define __ELEVATOR_A126 \
__ELEVATOR_V26>0
#define __ELEVATOR_A127 \
__ELEVATOR_V27>0
#define __ELEVATOR_A128 \
__ELEVATOR_V28>0
#define __ELEVATOR_A129 \
__ELEVATOR_V29>0

/* DECREMENTS */

#define __ELEVATOR_A130 \
__DSZ(__ELEVATOR_V23)
#define __ELEVATOR_A131 \
__DSZ(__ELEVATOR_V24)
#define __ELEVATOR_A132 \
__DSZ(__ELEVATOR_V25)
#define __ELEVATOR_A133 \
__DSZ(__ELEVATOR_V26)
#define __ELEVATOR_A134 \
__DSZ(__ELEVATOR_V27)
#define __ELEVATOR_A135 \
__DSZ(__ELEVATOR_V28)
#define __ELEVATOR_A136 \
__DSZ(__ELEVATOR_V29)

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

#define __ELEVATOR_A137 \

#define __ELEVATOR_A138 \

#define __ELEVATOR_A139 \


/* ACTION SEQUENCES */

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int ELEVATOR_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */



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

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __ELEVATOR_R[27] = {_true,
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

static __SSC_BIT_TYPE E[77];
E[0] = __ELEVATOR_R[5]&&!(__ELEVATOR_R[0]);
E[1] = E[0]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[2] = __ELEVATOR_R[11]&&!(__ELEVATOR_R[0]);
E[3] = E[2]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[4] = __ELEVATOR_R[18]&&!(__ELEVATOR_R[0]);
E[5] = E[4]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[6] = __ELEVATOR_R[23]&&!(__ELEVATOR_R[0]);
E[7] = E[6]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
if (E[1]||E[3]||E[5]||E[7]) {
__ELEVATOR_A11;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A11\n");
#endif
}
E[8] = __ELEVATOR_R[7]&&!(__ELEVATOR_R[0]);
E[9] = E[8]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[10] = __ELEVATOR_R[14]&&!(__ELEVATOR_R[0]);
E[11] = E[10]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[12] = __ELEVATOR_R[21]&&!(__ELEVATOR_R[0]);
E[13] = E[12]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[14] = __ELEVATOR_R[26]&&!(__ELEVATOR_R[0]);
E[15] = E[14]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
if (E[9]||E[11]||E[13]||E[15]) {
__ELEVATOR_A12;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A12\n");
#endif
}
if (__ELEVATOR_R[0]) {
__ELEVATOR_A137;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A137\n");
#endif
}
if (__ELEVATOR_R[0]) {
__ELEVATOR_A138;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A138\n");
#endif
}
if (__ELEVATOR_R[0]) {
__ELEVATOR_A70;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A70\n");
#endif
}
if (__ELEVATOR_R[0]) {
__ELEVATOR_A139;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A139\n");
#endif
}
if (__ELEVATOR_R[0]) {
__ELEVATOR_A71;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A71\n");
#endif
}
if (__ELEVATOR_R[0]) {
__ELEVATOR_A72;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A72\n");
#endif
}
if (__ELEVATOR_R[0]) {
__ELEVATOR_A73;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A73\n");
#endif
}
E[16] = __ELEVATOR_R[9]&&!(__ELEVATOR_R[0]);
E[17] = E[16]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[18] = E[17]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 132\n"),
#endif
__ELEVATOR_A132);
E[19] = __ELEVATOR_R[8]&&!(__ELEVATOR_R[0]);
E[20] = E[19]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
if (E[20]) {
__ELEVATOR_A92;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A92\n");
#endif
}
E[21] = E[20]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 125\n"),
#endif
__ELEVATOR_A125);
E[22] = E[18]||(E[20]&&!(E[21]));
if (E[22]) {
__ELEVATOR_A79;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A79\n");
#endif
}
if (E[22]) {
__ELEVATOR_A80;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A80\n");
#endif
}
E[23] = __ELEVATOR_R[16]&&!(__ELEVATOR_R[0]);
E[24] = E[23]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[25] = E[24]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 134\n"),
#endif
__ELEVATOR_A134);
E[26] = __ELEVATOR_R[15]&&!(__ELEVATOR_R[0]);
E[27] = E[26]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
if (E[27]) {
__ELEVATOR_A94;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A94\n");
#endif
}
E[28] = E[27]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 127\n"),
#endif
__ELEVATOR_A127);
E[29] = E[25]||(E[27]&&!(E[28]));
if (E[29]) {
__ELEVATOR_A86;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A86\n");
#endif
}
if (E[29]) {
__ELEVATOR_A87;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A87\n");
#endif
}
E[30] = __ELEVATOR_R[0]||E[22]||E[29];
if (E[30]) {
__ELEVATOR_A13;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A13\n");
#endif
}
if (__ELEVATOR_R[0]) {
__ELEVATOR_A31;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A31\n");
#endif
}
if (__ELEVATOR_R[0]) {
__ELEVATOR_A32;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A32\n");
#endif
}
if (__ELEVATOR_R[0]) {
__ELEVATOR_A33;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A33\n");
#endif
}
if (__ELEVATOR_R[0]) {
__ELEVATOR_A34;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A34\n");
#endif
}
if (__ELEVATOR_R[0]) {
__ELEVATOR_A35;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A35\n");
#endif
}
if (__ELEVATOR_R[0]) {
__ELEVATOR_A36;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A36\n");
#endif
}
if (__ELEVATOR_R[0]) {
__ELEVATOR_A37;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A37\n");
#endif
}
E[31] = (__ELEVATOR_R[1]&&!(__ELEVATOR_R[0]))||__ELEVATOR_R[0];
E[32] = (
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__ELEVATOR_A2)||(
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__ELEVATOR_A6);
E[33] = E[31]&&E[32];
if (E[33]) {
__ELEVATOR_A38;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A38\n");
#endif
}
E[34] = E[33]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__ELEVATOR_A6);
E[35] = E[33]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__ELEVATOR_A6));
E[32] = E[34]||E[35]||(E[31]&&!(E[32]));
E[31] = (
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__ELEVATOR_A3)||(
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__ELEVATOR_A7);
E[35] = E[32]&&E[31];
if (E[35]) {
__ELEVATOR_A39;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A39\n");
#endif
}
E[36] = E[35]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__ELEVATOR_A7);
E[37] = E[35]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__ELEVATOR_A7));
E[31] = E[36]||E[37]||(E[32]&&!(E[31]));
E[32] = (
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__ELEVATOR_A4)||(
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__ELEVATOR_A8);
E[37] = E[31]&&E[32];
if (E[37]) {
__ELEVATOR_A40;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A40\n");
#endif
}
E[38] = E[37]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__ELEVATOR_A8);
E[39] = E[37]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__ELEVATOR_A8));
E[32] = E[38]||E[39]||(E[31]&&!(E[32]));
E[31] = (
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__ELEVATOR_A5)||(
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__ELEVATOR_A9);
E[39] = E[32]&&E[31];
if (E[39]) {
__ELEVATOR_A41;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A41\n");
#endif
}
E[40] = E[39]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__ELEVATOR_A9);
E[41] = E[39]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__ELEVATOR_A9));
E[31] = E[40]||E[41]||(E[32]&&!(E[31]));
E[32] = E[31]&&E[30];
E[41] = E[32]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 97\n"),
#endif
__ELEVATOR_A97);
E[32] = E[32]&&!(E[41]);
E[42] = E[32]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 99\n"),
#endif
__ELEVATOR_A99);
E[32] = E[32]&&!(E[42]);
E[43] = E[32]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 101\n"),
#endif
__ELEVATOR_A101);
E[32] = E[32]&&!(E[43]);
E[44] = E[32]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 103\n"),
#endif
__ELEVATOR_A103);
E[32] = E[32]&&!(E[44]);
if (E[32]) {
__ELEVATOR_A14;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A14\n");
#endif
}
E[45] = E[41]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 98\n"),
#endif
__ELEVATOR_A98);
if (E[45]) {
__ELEVATOR_A42;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A42\n");
#endif
}
E[46] = E[42]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 100\n"),
#endif
__ELEVATOR_A100);
if (E[46]) {
__ELEVATOR_A43;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A43\n");
#endif
}
E[47] = E[43]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 102\n"),
#endif
__ELEVATOR_A102);
if (E[47]) {
__ELEVATOR_A44;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A44\n");
#endif
}
E[48] = E[44]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 104\n"),
#endif
__ELEVATOR_A104);
if (E[48]) {
__ELEVATOR_A45;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A45\n");
#endif
}
E[49] = E[45]||E[46]||E[47]||E[48];
if (E[49]) {
__ELEVATOR_A15;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A15\n");
#endif
}
if (E[34]||E[45]) {
__ELEVATOR_A16;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A16\n");
#endif
}
if (E[36]||E[46]) {
__ELEVATOR_A17;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A17\n");
#endif
}
if (E[38]||E[47]) {
__ELEVATOR_A18;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A18\n");
#endif
}
if (E[40]||E[48]) {
__ELEVATOR_A19;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A19\n");
#endif
}
E[44] = E[45]||(E[41]&&!(E[45]))||E[46]||(E[42]&&!(E[46]))||E[47]||(E[43]&&!(E[47]))||E[48]||(E[44]&&!(E[48]))||E[32];
E[43] = E[44]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 105\n"),
#endif
__ELEVATOR_A105);
if (E[43]) {
__ELEVATOR_A46;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A46\n");
#endif
}
E[31] = E[43]||(E[44]&&!(E[43]))||(E[31]&&!(E[30]));
E[44] = E[31]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 106\n"),
#endif
__ELEVATOR_A106);
E[42] = E[44]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 107\n"),
#endif
__ELEVATOR_A107);
E[41] = E[42]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 108\n"),
#endif
__ELEVATOR_A108);
if (E[41]) {
__ELEVATOR_A47;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A47\n");
#endif
}
if (E[41]) {
__ELEVATOR_A48;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A48\n");
#endif
}
E[50] = E[42]&&!(E[41]);
E[51] = E[50]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 109\n"),
#endif
__ELEVATOR_A109);
if (E[51]) {
__ELEVATOR_A49;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A49\n");
#endif
}
if (E[51]) {
__ELEVATOR_A50;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A50\n");
#endif
}
E[50] = E[50]&&!(E[51]);
if (E[50]) {
__ELEVATOR_A51;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A51\n");
#endif
}
E[52] = E[50]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 110\n"),
#endif
__ELEVATOR_A110);
if (E[52]) {
__ELEVATOR_A52;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A52\n");
#endif
}
if (E[52]) {
__ELEVATOR_A53;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A53\n");
#endif
}
E[53] = E[50]&&!(E[52]);
E[54] = E[53]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 111\n"),
#endif
__ELEVATOR_A111);
if (E[54]) {
__ELEVATOR_A54;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A54\n");
#endif
}
if (E[54]) {
__ELEVATOR_A55;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A55\n");
#endif
}
E[53] = E[53]&&!(E[54]);
E[55] = E[53]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 112\n"),
#endif
__ELEVATOR_A112);
if (E[55]) {
__ELEVATOR_A56;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A56\n");
#endif
}
if (E[55]) {
__ELEVATOR_A57;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A57\n");
#endif
}
E[42] = E[44]&&!(E[42]);
E[56] = E[42]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 113\n"),
#endif
__ELEVATOR_A113);
if (E[56]) {
__ELEVATOR_A58;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A58\n");
#endif
}
if (E[56]) {
__ELEVATOR_A59;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A59\n");
#endif
}
E[42] = E[42]&&!(E[56]);
E[57] = E[42]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 114\n"),
#endif
__ELEVATOR_A114);
if (E[57]) {
__ELEVATOR_A60;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A60\n");
#endif
}
if (E[57]) {
__ELEVATOR_A61;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A61\n");
#endif
}
E[42] = E[42]&&!(E[57]);
if (E[42]) {
__ELEVATOR_A62;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A62\n");
#endif
}
E[58] = E[42]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 115\n"),
#endif
__ELEVATOR_A115);
if (E[58]) {
__ELEVATOR_A63;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A63\n");
#endif
}
if (E[58]) {
__ELEVATOR_A64;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A64\n");
#endif
}
E[59] = E[42]&&!(E[58]);
E[60] = E[59]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 116\n"),
#endif
__ELEVATOR_A116);
if (E[60]) {
__ELEVATOR_A65;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A65\n");
#endif
}
if (E[60]) {
__ELEVATOR_A66;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A66\n");
#endif
}
E[59] = E[59]&&!(E[60]);
E[61] = E[59]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 117\n"),
#endif
__ELEVATOR_A117);
if (E[61]) {
__ELEVATOR_A67;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A67\n");
#endif
}
if (E[61]) {
__ELEVATOR_A68;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A68\n");
#endif
}
E[59] = E[41]||E[51]||E[52]||E[54]||E[55]||(E[53]&&!(E[55]))||E[56]||E[57]||E[58]||E[60]||E[61]||(E[59]&&!(E[61]));
if (E[59]) {
__ELEVATOR_A69;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A69\n");
#endif
}
E[44] = E[31]&&!(E[44]);
if (E[59]||E[44]) {
__ELEVATOR_A20;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A20\n");
#endif
}
E[31] = E[41]||E[51]||E[52]||E[54]||E[55]||E[56]||E[57]||E[58]||E[60]||E[61];
E[53] = !(_true);
E[62] = E[59]||E[44];
E[63] = __ELEVATOR_R[2]&&!(__ELEVATOR_R[0]);
E[64] = E[63]&&!(E[31]);
E[65] = E[64]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 10\n"),
#endif
__ELEVATOR_A10));
E[65] = __ELEVATOR_R[0]||(__ELEVATOR_R[3]&&!(__ELEVATOR_R[0]))||(__ELEVATOR_R[2]&&E[65]);
E[31] = E[63]&&E[31];
E[63] = E[31]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 118\n"),
#endif
__ELEVATOR_A118);
E[66] = E[63]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 119\n"),
#endif
__ELEVATOR_A119);
E[67] = __ELEVATOR_R[4]&&!(__ELEVATOR_R[0]);
E[68] = E[67]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[68] = E[66]||(__ELEVATOR_R[4]&&E[68]);
E[67] = E[67]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[0] = E[0]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[0] = E[67]||(__ELEVATOR_R[5]&&E[0]);
if (E[1]) {
__ELEVATOR_A74;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A74\n");
#endif
}
if (E[11]) {
__ELEVATOR_A82;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A82\n");
#endif
}
E[67] = E[11]||(E[22]&&!(E[49]));
E[69] = E[67]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 130\n"),
#endif
__ELEVATOR_A130);
if (E[9]) {
__ELEVATOR_A75;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A75\n");
#endif
}
E[31] = E[31]&&!(E[63]);
E[70] = E[31]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 120\n"),
#endif
__ELEVATOR_A120);
E[31] = E[9]||(E[31]&&!(E[70]));
E[71] = E[31]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 121\n"),
#endif
__ELEVATOR_A121);
if (E[71]) {
__ELEVATOR_A76;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A76\n");
#endif
}
if (E[71]) {
__ELEVATOR_A77;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A77\n");
#endif
}
if (E[71]) {
__ELEVATOR_A78;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A78\n");
#endif
}
E[72] = E[71]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 122\n"),
#endif
__ELEVATOR_A122);
if (E[13]) {
__ELEVATOR_A89;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A89\n");
#endif
}
E[73] = E[13]||(E[29]&&!(E[49]));
E[74] = E[73]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 131\n"),
#endif
__ELEVATOR_A131);
E[31] = E[31]&&!(E[71]);
if (E[31]) {
__ELEVATOR_A83;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A83\n");
#endif
}
if (E[31]) {
__ELEVATOR_A84;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A84\n");
#endif
}
if (E[31]) {
__ELEVATOR_A85;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A85\n");
#endif
}
E[75] = E[31]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 123\n"),
#endif
__ELEVATOR_A123);
if (E[15]) {
__ELEVATOR_A91;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A91\n");
#endif
}
E[64] = E[64]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 10\n"),
#endif
__ELEVATOR_A10);
E[76] = E[64]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 124\n"),
#endif
__ELEVATOR_A124);
E[64] = E[1]||(E[63]&&!(E[66]))||E[69]||(E[71]&&!(E[72]))||E[74]||(E[31]&&!(E[75]))||E[15]||(E[64]&&!(E[76]));
E[66] = __ELEVATOR_R[6]&&!(__ELEVATOR_R[0]);
E[63] = E[66]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[63] = E[70]||(__ELEVATOR_R[6]&&E[63]);
E[66] = E[66]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[8] = E[8]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[8] = E[66]||(__ELEVATOR_R[7]&&E[8]);
E[19] = E[19]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[19] = E[72]||(E[67]&&!(E[69]))||(__ELEVATOR_R[8]&&E[19]);
E[16] = E[16]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[16] = E[21]||(E[17]&&!(E[18]))||(__ELEVATOR_R[9]&&E[16]);
E[18] = __ELEVATOR_R[10]&&!(__ELEVATOR_R[0]);
E[17] = E[18]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[17] = (E[22]&&E[49])||(__ELEVATOR_R[10]&&E[17]);
E[18] = E[18]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[2] = E[2]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[2] = E[18]||(__ELEVATOR_R[11]&&E[2]);
if (E[3]) {
__ELEVATOR_A81;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A81\n");
#endif
}
if (E[3]) {
__ELEVATOR_A93;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A93\n");
#endif
}
E[18] = E[3]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 126\n"),
#endif
__ELEVATOR_A126);
E[21] = __ELEVATOR_R[12]&&!(__ELEVATOR_R[0]);
E[69] = E[21]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[67] = E[69]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 133\n"),
#endif
__ELEVATOR_A133);
E[21] = E[21]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[21] = E[18]||(E[69]&&!(E[67]))||(__ELEVATOR_R[12]&&E[21]);
E[69] = __ELEVATOR_R[13]&&!(__ELEVATOR_R[0]);
E[72] = E[69]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[72] = E[67]||(E[3]&&!(E[18]))||(__ELEVATOR_R[13]&&E[72]);
E[69] = E[69]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[10] = E[10]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[10] = E[69]||(__ELEVATOR_R[14]&&E[10]);
E[26] = E[26]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[26] = E[75]||(E[73]&&!(E[74]))||(__ELEVATOR_R[15]&&E[26]);
E[23] = E[23]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[23] = E[28]||(E[24]&&!(E[25]))||(__ELEVATOR_R[16]&&E[23]);
E[25] = __ELEVATOR_R[17]&&!(__ELEVATOR_R[0]);
E[24] = E[25]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[24] = (E[29]&&E[49])||(__ELEVATOR_R[17]&&E[24]);
E[25] = E[25]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[4] = E[4]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[4] = E[25]||(__ELEVATOR_R[18]&&E[4]);
if (E[5]) {
__ELEVATOR_A88;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A88\n");
#endif
}
if (E[5]) {
__ELEVATOR_A95;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A95\n");
#endif
}
E[25] = E[5]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 128\n"),
#endif
__ELEVATOR_A128);
E[28] = __ELEVATOR_R[19]&&!(__ELEVATOR_R[0]);
E[74] = E[28]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[73] = E[74]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 135\n"),
#endif
__ELEVATOR_A135);
E[28] = E[28]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[28] = E[25]||(E[74]&&!(E[73]))||(__ELEVATOR_R[19]&&E[28]);
E[74] = __ELEVATOR_R[20]&&!(__ELEVATOR_R[0]);
E[75] = E[74]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[75] = E[73]||(E[5]&&!(E[25]))||(__ELEVATOR_R[20]&&E[75]);
E[74] = E[74]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[12] = E[12]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[12] = E[74]||(__ELEVATOR_R[21]&&E[12]);
E[74] = __ELEVATOR_R[22]&&!(__ELEVATOR_R[0]);
E[25] = E[74]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[25] = E[76]||(__ELEVATOR_R[22]&&E[25]);
E[74] = E[74]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[6] = E[6]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[6] = E[74]||(__ELEVATOR_R[23]&&E[6]);
if (E[7]) {
__ELEVATOR_A90;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A90\n");
#endif
}
if (E[7]) {
__ELEVATOR_A96;
#ifdef TRACE_ACTION
fprintf(stderr, "__ELEVATOR_A96\n");
#endif
}
E[74] = E[7]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 129\n"),
#endif
__ELEVATOR_A129);
E[76] = __ELEVATOR_R[24]&&!(__ELEVATOR_R[0]);
E[73] = E[76]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[69] = E[73]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 136\n"),
#endif
__ELEVATOR_A136);
E[76] = E[76]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[76] = E[74]||(E[73]&&!(E[69]))||(__ELEVATOR_R[24]&&E[76]);
E[73] = __ELEVATOR_R[25]&&!(__ELEVATOR_R[0]);
E[18] = E[73]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[18] = E[69]||(E[7]&&!(E[74]))||(__ELEVATOR_R[25]&&E[18]);
E[73] = E[73]&&(
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1);
E[14] = E[14]&&!((
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__ELEVATOR_A1));
E[14] = E[73]||(__ELEVATOR_R[26]&&E[14]);
E[73] = __ELEVATOR_R[2]||__ELEVATOR_R[4]||__ELEVATOR_R[5]||__ELEVATOR_R[3]||__ELEVATOR_R[6]||__ELEVATOR_R[7]||__ELEVATOR_R[8]||__ELEVATOR_R[9]||__ELEVATOR_R[10]||__ELEVATOR_R[11]||__ELEVATOR_R[12]||__ELEVATOR_R[13]||__ELEVATOR_R[14]||__ELEVATOR_R[15]||__ELEVATOR_R[16]||__ELEVATOR_R[17]||__ELEVATOR_R[18]||__ELEVATOR_R[19]||__ELEVATOR_R[20]||__ELEVATOR_R[21]||__ELEVATOR_R[22]||__ELEVATOR_R[23]||__ELEVATOR_R[24]||__ELEVATOR_R[25]||__ELEVATOR_R[26];
E[74] = __ELEVATOR_R[1]||E[73];
E[73] = (E[62]||E[65]||E[68]||E[0]||E[64]||E[63]||E[8]||E[19]||E[16]||E[17]||E[2]||E[21]||E[72]||E[10]||E[26]||E[23]||E[24]||E[4]||E[28]||E[75]||E[12]||E[25]||E[6]||E[76]||E[18]||E[14])&&((E[74]&&!(__ELEVATOR_R[1]))||E[62])&&((E[74]&&!(E[73]))||E[65]||E[68]||E[0]||E[64]||E[63]||E[8]||E[19]||E[16]||E[17]||E[2]||E[21]||E[72]||E[10]||E[26]||E[23]||E[24]||E[4]||E[28]||E[75]||E[12]||E[25]||E[6]||E[76]||E[18]||E[14]);
__ELEVATOR_R[0] = !(_true);
__ELEVATOR_R[1] = E[62];
__ELEVATOR_R[2] = E[65];
__ELEVATOR_R[3] = E[64];
__ELEVATOR_R[4] = E[68];
__ELEVATOR_R[5] = E[0];
__ELEVATOR_R[6] = E[63];
__ELEVATOR_R[7] = E[8];
__ELEVATOR_R[8] = E[19];
__ELEVATOR_R[9] = E[16];
__ELEVATOR_R[10] = E[17];
__ELEVATOR_R[11] = E[2];
__ELEVATOR_R[12] = E[21];
__ELEVATOR_R[13] = E[72];
__ELEVATOR_R[14] = E[10];
__ELEVATOR_R[15] = E[26];
__ELEVATOR_R[16] = E[23];
__ELEVATOR_R[17] = E[24];
__ELEVATOR_R[18] = E[4];
__ELEVATOR_R[19] = E[28];
__ELEVATOR_R[20] = E[75];
__ELEVATOR_R[21] = E[12];
__ELEVATOR_R[22] = E[25];
__ELEVATOR_R[23] = E[6];
__ELEVATOR_R[24] = E[76];
__ELEVATOR_R[25] = E[18];
__ELEVATOR_R[26] = E[14];
__ELEVATOR__reset_input();
return E[73];
}

/* AUTOMATON RESET */

int ELEVATOR_reset () {
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
__ELEVATOR__reset_input();
return 0;
}
