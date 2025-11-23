#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"

typedef struct s_matrix{
    int rows;
    int cols;
    double **data;
} t_matrix;

t_matrix createZeroMatrix(int n);
t_matrix createTransitionMatrix(t_adjlist graph);
void copyMatrix(t_matrix *dest, t_matrix src);
t_matrix multiplyMatrix(t_matrix A, t_matrix B);
double diffMatrix(t_matrix A, t_matrix B);
void printMatrix(t_matrix M);
void freeMatrix(t_matrix *M);
/**
* @brief Extracts a submatrix corresponding to a specific
component of a graph partition.
*
* @param matrix The original adjacency matrix of the graph.
* @param part The partition of the graph into strongly
connected components.
* @param compo_index The index of the component to extract.
* @return t_matrix The submatrix corresponding to the
specified component.
*/
t_matrix subMatrix(t_matrix matrix, t_partition part, int compo_index);
#endif