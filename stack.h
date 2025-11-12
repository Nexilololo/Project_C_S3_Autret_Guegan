#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct st_cell{
    int value;
    struct s_cell* next;
}st_cell;

typedef struct s_stack{
    st_cell* head;
}t_stack;

int isEmptyStack(t_stack stack);
t_stack createEmptyStack();
st_cell* createCell(int value);
void push(t_stack* stack, int value);
int pop(t_stack* stack);
void displayStack(t_stack stack);
int top(t_stack stack);

#endif