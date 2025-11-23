#include <stdio.h>

#include "utils.h"
#include "hasse.h"
#include "matrix.h"

int main() {

    // PART 1:
    printf("\n PART 1:\n");

    t_adjlist g = readGraph("../data/exemple_valid_step3.txt");
    display_adjlist(g);
    createMermaidFile(g, "../data/mermaid_file.txt");


    // PART 2:
    printf("\n PART 2:\n");

    t_partition p = tarjanAlgorithm(g);
    printf("Found %d connected components.\n", p.classes_number);

    t_link_array links = getHasseLinks(g, p);
    removeTransitiveLinks(&links); // Optional
    createHasseMermaid(p, links, "../data/hasse_viz.txt");
    printf("Hasse diagram generated.\n");

    printf("\n Graph Properties \n");
    analyzeGraphProperties(g, p);


    // PART 3:
    printf("\n PART 3:\n");

    t_matrix M = createTransitionMatrix(g);
    printf("Global Transition Matrix M:\n");
    printMatrix(M);

    printf("\n Calculating Stationary Distributions: \n");

    for (int c = 0; c < p.classes_number; c++) {
        t_class *cls = &p.partition[c];

        int is_transient = 0;
        for(int v = 0; v < cls->vertex_number; v++) {
            int vertexID = cls->vertex[v].ID;
            t_cell *curr = g.list[vertexID - 1].head;
            while(curr != NULL) {
                int dest_class = findClassOfVertex(&p, curr->vertex);
                if(dest_class != c) {
                    is_transient = 1;
                    break;
                }
                curr = curr->next;
            }
            if(is_transient) break;
        }

        // Math calculations here:
        if (is_transient) {
            printf("Class %s (C%d) is TRANSIENT -> Limit is 0.\n", cls->name, c);
        } else {
            printf("Class %s (C%d) is PERSISTENT -> Calculating convergence...\n", cls->name, c);

            t_matrix sub = subMatrix(M, p, c);
            t_matrix current_pow = createZeroMatrix(sub.rows);
            copyMatrix(&current_pow, sub);

            t_matrix next_pow;
            double diff = 1.0;
            int step = 1;

            while (diff > 0.0001 && step < 1000) {
                next_pow = multiplyMatrix(current_pow, sub);
                diff = diffMatrix(current_pow, next_pow);
                freeMatrix(&current_pow);
                current_pow = next_pow;
                step++;
            }

            printf("It converged after %d steps.\n", step);
            printMatrix(current_pow);

            freeMatrix(&current_pow);
            freeMatrix(&sub);
        }
    }

    freeMatrix(&M);

    return 0;
}
