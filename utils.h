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
};

#endif