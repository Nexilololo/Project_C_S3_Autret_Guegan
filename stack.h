//Importamos las librerias que usaremos
#include <stdio.h>
#include <stdlib.h>

// Definimos las estructuras que usaremos
typedef struct s_cell{
    int value;
    struct s_cell* next;
}t_cell;

typedef struct s_stack{
    t_cell* head;
}t_stack;

//Armamos el prototipo de la funciones
//Funcion para verificar si es un stack vacion 
int isEmptyStack(t_stack stack);

//Funcion para crear un stack vacio
t_stack createEmptyStack();
t_cell* createCell(int value);

//Funcion para agregar un valor al stack 
void push(t_stack* stack, int value);

//Funcion para quitar un valor al stack
int pop(t_stack* stack);

//Funcion para imprimir el stack
void displayStack(t_stack stack);

//Funcion para consultar un valor 
int top(t_stack stack);