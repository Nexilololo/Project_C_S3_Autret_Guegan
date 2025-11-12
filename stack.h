#include <stdio.h>
#include <stdlib.h>

typedef struct s_cell{
    int value;
    struct s_cell* next;
}t_cell;

typedef struct s_stack{
    t_cell* head;
}t_stack;

int isEmptyStack(t_stack stack);
t_stack createEmptyStack();
t_cell* createCell(int value);
void push(t_stack* stack, int value);
int pop(t_stack* stack);
void displayStack(t_stack stack);
int top(t_stack stack);