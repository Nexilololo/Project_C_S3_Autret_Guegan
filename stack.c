#include "stack.h"


st_cell* createStackCell(int value){
    st_cell* new =(st_cell*)malloc(sizeof(st_cell));
    new->value = value;
    new->next = NULL;
    return new;
}

t_stack createEmptyStack(){
    t_stack stack;
    stack.head = NULL;
    displayStack(stack);
    return stack;
}

int isEmptyStack(t_stack stack){
    if(stack.head == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(t_stack* stack, int value){
    st_cell* new = createStackCell(value);
    new->next = stack->head;
    stack->head = new;
    displayStack(*stack);
}

int pop(t_stack* stack){
    st_cell* temp = stack->head;
    int result;
    if(stack->head == NULL){
        printf("Stack is empty. Return -1 by default.\n");
        displayStack(*stack);
        return -1;
    }
    else{
        stack->head = temp->next;
        result = temp->value;
        free(temp);
        displayStack(*stack);
        return result;
    }
}

void displayStack(t_stack stack){
    st_cell* curr = stack.head;
    printf("[ @ ] -> ");
    while(curr != NULL){
        printf("[ %d | @ ] -> ", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

int top(t_stack stack){
    if (isEmptyStack(stack) == 1){
        printf("Stack is empty. Return -1 by default.\n");
        return -1;
    }
    return stack.head->value;
}