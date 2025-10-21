#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

static char *getID(int i)
{
    // translate from 1,2,3, .. ,500+ to A,B,C,..,Z,AA,AB,...
    static char buffer[10];
    char temp[10];
    int index = 0;

    i--; // Adjust to 0-based index
    while (i >= 0)
    {
        temp[index++] = 'A' + (i % 26);
        i = (i / 26) - 1;
    }

    // Reverse the string to get the correct order
    for (int j = 0; j < index; j++)
    {
        buffer[j] = temp[index - j - 1];
    }
    buffer[index] = '\0';

    return buffer;
}

t_cell* createCell(int vertex, float weight) {
    t_cell* cell = (t_cell*)malloc(sizeof(t_cell));
    cell->vertex = vertex;
    cell->weight = weight;
    cell->next = NULL;
    return cell;
}

t_list CreateEmptyList(){
    t_list newList;
    newList.head = NULL;
    return newList;
}

void addcell(t_list* l,t_cell* c){
    if (l->head==NULL) {
        l->head = c;
    }
    else {
        c->next=l->head;
        l->head=c;
    }
};

