/*
 *  Generic Stack ADT: private implementation
 *
 *  Author:  Levi Holmes
 *  Date:    Mar. 8, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "istack.h"

Node2_t* NodeCreat(int value) {
    Node2_t* node = malloc(sizeof(Node2_t));
    node->data = value;
    node->next = NULL;
    return node;
}
void node2Print(Node2_t node) {
    printf("|\t%d\t|\n", node.data);
}

/*
 * Constructor - return a new, empty stack 
 * POST: istackIsEmpty(stack)
 */
IntStack_t istackCreate( ){
   Node2_t* Dummy = NodeCreat(-1);
  IntStack_t stack = {Dummy};
}

/*
 * Destructor - empty stack and free all associated memory
 */
 void istackDestroy( IntStack_t *stack ){
     while (stack->head->next != NULL) {
     istackPop(stack);
   }
 }

/*
 * Print a text representation of this stack on STDOUT
 */
void istackPrint( IntStack_t stack  ){
   Node2_t* cur = stack.head->next;
   printf("\nStack:\n");
   while (cur != NULL) {
       node2Print(*cur);
       cur = cur->next;
   }
   printf("\n\n");
} 

/*
 * Return true iff the stack is empty
 */
bool istackIsEmpty( IntStack_t stack ){
   return stack.head->next == NULL;
   
}

/*
 * Examine the item at the top of the stack
 * PRE: ! istackIsEmpty( stack )
 */
int istackTop( IntStack_t stack ){
   assert(istackIsEmpty(stack) == false);
   return stack.head->next->data;
}

/*
 * Pop the item from the top of the stack 
 * PRE: ! istackIsEmpty( stack )
 */
int istackPop( IntStack_t *stack ){
   assert(!istackIsEmpty(*stack));
   Node2_t* node = stack->head->next;
   stack->head->next = node->next;
   int value = node->data;
   free(node);
   return value;
}


/*
 * Push given item on the top of the stack 
 * PRE: ! istackIsFull( stack )
 * POST: istackTop( stack ) == item
 */
void istackPush( IntStack_t *stack, int item){
   Node2_t* newNode = NodeCreat(item);
     newNode->next = stack->head->next;
     stack->head->next = newNode;
   
}
