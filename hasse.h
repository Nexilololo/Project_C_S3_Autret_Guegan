#ifndef __HASSE_H__
#define __HASSE_H__

typedef struct s_class_link {
    int start_class;
    int end_class;
} t_class_link;


typedef struct s_link_array {
    t_class_link *links;
    int count;
} t_link_array;

void removeTransitiveLinks(t_link_array *p_link_array);

t_link_array getHasseLinks(t_adjlist graph, t_partition partition);
void createHasseMermaid(t_partition partition, t_link_array links, char *filename);

/**
 * @brief Creates a link array from the given partition and graph.
 *
 * @param part The partition of the graph.
 * @param graph The adjacency list representation of the graph.
 * @return The created link array.
 */

#endif