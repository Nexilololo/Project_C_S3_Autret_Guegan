#include <malloc.h>
#include "hasse.h"


void removeTransitiveLinks(t_link_array *p_link_array)
{
    int i = 0;
    while (i < p_link_array->log_size)
    {
        t_link link1 = p_link_array->links[i];
        int j = 0;
        int to_remove = 0;
        while (j < p_link_array->log_size && !to_remove)
        {
            if (j != i)
            {
                t_link link2 = p_link_array->links[j];
                if (link1.from == link2.from)
                {
                    // look for a link from link2.to to link1.to
                    int k = 0;
                    while (k < p_link_array->log_size && !to_remove)
                    {
                        if (k != j && k != i)
                        {
                            t_link link3 = p_link_array->links[k];
                            if ((link3.from == link2.to) && (link3.to == link1.to))
                            {
                                to_remove = 1;
                            }
                        }
                        k++;
                    }
                }
            }
            j++;
        }
        if (to_remove)
        {
            // remove link1 by replacing it with the last link
            p_link_array->links[i] = p_link_array->links[p_link_array->log_size - 1];
            p_link_array->log_size--;
        }
        else
        {
            i++;
        }
    }
}

int isLinkPresent(t_link_array *link_array, int from, int to) {
    for (int i = 0; i < link_array->log_size; i++) {
        if (link_array->links[i].from == from &&
            link_array->links[i].to == to) {
            return 1;
        }
    }
    return 0;
}

t_link_array getHasseLinks(t_adjlist graph, t_partition partition) {
    t_link_array result;
    result.links = NULL;
    result.log_size = 0;

    int num_vertices = graph.list_number;
    int *vertex_to_class = (int *)malloc(num_vertices * sizeof(int));

    for(int i=0; i<num_vertices; i++) vertex_to_class[i] = -1;

    for (int i = 0; i < partition.classes_number; i++) {
        t_class current_class = partition.partition[i];
        for (int j = 0; j < current_class.vertex_number; j++) {
            int v_id = current_class.vertex[j].ID;
            if (v_id - 1 < num_vertices) {
                vertex_to_class[v_id - 1] = i;
            }
        }
    }

    for (int i = 0; i < num_vertices; i++) {
        int class_from = vertex_to_class[i];

        if (class_from == -1) continue;

        t_cell *edge = graph.list[i].head;
        while (edge != NULL) {
            int target_vertex_idx = edge->vertex - 1;
            int class_to = vertex_to_class[target_vertex_idx];

            if (class_from != class_to && class_to != -1) {

                if (!isLinkPresent(&result, class_from, class_to)) {
                    result.log_size++;
                    result.links = (t_link *)realloc(result.links, result.log_size * sizeof(t_link));

                    result.links[result.log_size - 1].from = class_from;
                    result.links[result.log_size - 1].to = class_to;
                }
            }
            edge = edge->next;
        }
    }

    free(vertex_to_class);
    return result;
}

void createHasseMermaid(t_partition partition, t_link_array links, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating Mermaid file");
        return;
    }

    fprintf(file, "graph TD\n");

    for (int i = 0; i < partition.classes_number; i++) {
        t_class c = partition.partition[i];

        fprintf(file, "    C%d[\"{", i);

        for (int j = 0; j < c.vertex_number; j++) {
            fprintf(file, "%d", c.vertex[j].ID);
            if (j < c.vertex_number - 1) {
                fprintf(file, ",");
            }
        }
        fprintf(file, "}\"]\n");
    }

    fprintf(file, "\n");

    for (int i = 0; i < links.log_size; i++) {
        fprintf(file, "    C%d --> C%d\n", links.links[i].from, links.links[i].to);
    }

    fclose(file);
}
