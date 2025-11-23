#include "matrix.h"

t_matrix createZeroMatrix(int n){
    t_matrix M;
    M.rows = n;
    M.cols = n;
    M.data = (double**)calloc(n, sizeof(double*));
    for(int i = 0; i < n; i++){
        M.data[i] = (double*)calloc(n, sizeof(double));
    }
    return M;
}

t_matrix createTransitionMatrix(t_adjlist graph){
    int n = graph.list_number;
    t_matrix M =  createZeroMatrix(n);
    for(int i = 0; i < n; i++){
        t_cell *curr = graph.list[i].head;
        while(curr != NULL){
            int j = curr->vertex -1;
            M.data[i][j] = curr -> weight;
            curr = curr->next;
        }
    }
    return M;
}

void copyMatrix(t_matrix *new, t_matrix old){
    for(int i = 0; i < old.rows; i++){
        for(int j = 0; j < old.cols; j++){
            new->data[i][j] = old.data[i][j];
        }
    }
}

t_matrix multiplyMatrix(t_matrix A, t_matrix B){
    int n = A.rows;
    t_matrix result = createZeroMatrix(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                result.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
    return result;
}

double diffMatrix(t_matrix A, t_matrix B){
    double result = 0.0;
    for(int i = 0; i < A.rows; i++){
        for(int j = 0; j < A.cols; j++){
            result += fabs(A.data[i][j] - B.data[i][j]);
        }
    }
    return result;
}

void printMatrix(t_matrix M){
    for(int i = 0; i < M.rows; i++){
        for(int j = 0; j < M.cols; j++){
            printf("%.4f ", M.data[i][j]);
        }
        printf("\n");
    }
}

t_matrix subMatrix(t_matrix matrix, t_partition part, int compo_index){
    t_class currclass = part.partition[compo_index];
    int n =currclass.vertex_number;
    t_matrix sub = createZeroMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float original_row_index = currclass.vertex[i].ID;
            double original_col_index = currclass.vertex[j].ID;


            sub.data[i][j] = matrix.data[original_row_index][original_col_index];
        }
    }

    return sub;
}
