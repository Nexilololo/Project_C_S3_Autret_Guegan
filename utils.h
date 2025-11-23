#ifndef __UTILS_H__
#define __UTILS_H__

#include "stack.h"

struct s_cell {
    int vertex;
    float weight;
    struct s_cell * next;
};
typedef struct s_cell t_cell;

struct s_list {
    t_cell * head;
};
typedef struct s_list t_list;


typedef struct adjlist{
    t_list* list;
    int list_number;
}t_adjlist;

typedef struct tarjan_vertex {
    int ID;
    int number;
    int access_number;
    int indicator;
}t_tarjan_vertex;

typedef struct tarjan_class {
    t_tarjan_vertex * vertex;
    int vertex_number;
    char name[10];
}t_class;

typedef struct tarjan_partition {
    t_class * partition;
    int classes_number;
}t_partition;


t_cell* createCell(int vertex, float weight);
t_list CreateEmptyList();
void addcell(t_list* l,t_cell* c);
void display_list(t_list l,int num);
void display_adjlist(t_adjlist l);
t_adjlist createEmptyAdjlist(int num);
t_adjlist readGraph(const char *filename);
void checkMarkovGraph(t_adjlist* adjlist);
void createMermaidFile(t_adjlist graph, char *filename);

t_partition tarjanAlgorithm(t_adjlist graph);
t_tarjan_vertex * createTarjanList(t_adjlist graph);
void parcoursTarjan(int *num, t_adjlist *graph, t_stack *stack, t_tarjan_vertex *vertex, t_partition *partition);

int findClassOfVertex(t_partition *partition, int vertexID);
void analyzeGraphProperties(t_adjlist graph, t_partition partition);

#endif