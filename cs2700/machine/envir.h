#include "globals.h"
#include "instr.h"
#include "spaces.h"

extern Quad PC, SP, FP[], q0, q1, q2, q4, q8;
extern word stack[];
extern Instr instrs[];
Quad symb_value();
void init_load();
