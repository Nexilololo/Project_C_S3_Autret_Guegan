#include "stack.h"

//Funcion para crear un stack vacio
t_cell* createCell(int value){
    t_cell* new =(t_cell*)malloc(sizeof(t_cell));
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

//Funcion para verificar si es un stack vacion 
int isEmptyStack(t_stack stack){
    if(stack.head == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//Funcion para agregar un valor al stack 
void push(t_stack* stack, int value){
    t_cell* new = createCell(value);
    new->next = stack->head;
    stack->head = new;
    displayStack(*stack);
}

//Funcion para quitar un valor al stack
int pop(t_stack* stack){
    t_cell* temp = stack->head;
    int result;
    if(stack->head == NULL){
        printf("El stack esta vacion (retornando -1 como valor predeterminado)\n");
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

//Funcion para imprimir el stack
void displayStack(t_stack stack){
    t_cell* curr = stack.head;
    printf("[ @ ] -> ");
    while(curr != NULL){
        printf("[ %d | @ ] -> ", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

//Funcion para consultar un valor 
int top(t_stack stack){
    if (isEmptyStack(stack) == 1){
        printf("Stack vacio retornando -1 como valor predeterminado\n");
        return -1;
    }
    return stack.head->value;
}