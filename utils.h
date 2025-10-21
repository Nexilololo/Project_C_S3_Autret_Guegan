#ifndef __UTILS_H__
#define __UTILS_H__

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

t_cell* createCell(int vertex, float weight);
t_list CreateEmptyList();
void addcell(t_list* l,t_cell* c);
void display_list(t_list l,int num);
void display_adjlist(t_adjlist l);

#endif