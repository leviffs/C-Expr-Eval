/**
 *  Generic Stack ADT : public interface
 *    Dependency: LinkedList with data type defined by gentype.h
 *
 *  Author:  Joseph Fall
 *  Date:    Mar. 1, 2018
 */

#include "linkedlist.h"

/*********************
 *  PUBLIC INTERFACE
 *********************/
 
typedef LinkedList_t Stack_t;

Stack_t stackCreate();

void stackDestroy(Stack_t* stack);

void stackPrint(const Stack_t stack);

bool stackIsEmpty(const Stack_t stack);

void stackPopAll(Stack_t* stack);

int stackSize(const Stack_t stack);

void stackPush(Stack_t* stack, ItemType value);

ItemType stackTop(const Stack_t stack);

ItemType stackPop(Stack_t* stack);
