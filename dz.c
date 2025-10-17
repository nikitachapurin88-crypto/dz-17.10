#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplyMatrices(int n, int m, int k, float** output, float** MatA, float** MatB){

    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < k ; ++j){
            float sum = 0;
            for(int t = 0; t < m ; ++t){
                sum += MatA[i][t]*MatB[t][j];
            }
        output[i][j] = sum;
        }
    }
}

void fillMat(float** mat, int rows, int cols){
    for( int i = 0 ; i < rows ; ++i){
        for(int j = 0 ; j < cols ; ++j){
            mat[i][j] = (rand() %10)+1;
        }
    }
}

void printMat( float** op, int n, int k){
    for(int i = 0; i < n ; ++i){
        for(int j = 0 ; j < k ; ++j){
            printf("%8.2f", op[i][j]);
        }
        printf("\n");
    }
}
void enterMat(int* n, int* m, int* k, float*** MatA, float*** MatB){

    printf("Enter N, M, K:\n");
    scanf("%d%d%d", n,m,k);

    *MatA = (float**)malloc(sizeof(float*)* *n);
    for(int i = 0; i < *n; ++i){
       (*MatA)[i] = (float*)malloc(sizeof(float)* *m);
    }

    *MatB = (float**)malloc(sizeof(float*)* *m);
    for(int i = 0; i < *m; ++i){
        (*MatB)[i] = (float*)malloc(sizeof(float)* *k);
    }
}

int main(){

    srand(time(NULL));

    int n, m, k;
    float** MatA;
    float** MatB;

    enterMat(&n, &m, &k, &MatA, &MatB);

    float** output = (float**)malloc(sizeof(float*) * n);
    for (int i = 0; i < n; ++i) output[i] = malloc(sizeof(float) * k);

    fillMat(MatA, n, m);
    fillMat(MatB, m, k);

    printf("\nMatrix A (%dx%d):\n", n, m);
    printMat(MatA, n, m);

    printf("\nMatrix B (%dx%d):\n", m, k);
    printMat(MatB, m, k);

    multiplyMatrices( n, m, k, output, MatA, MatB);

    printf("\nMatrix C (%dx%d):\n", n, k);
    printMat(output, n, k);



    for (int i = 0; i < n; ++i) free(MatA[i]);
    free(MatA);

    for (int i = 0; i < m; ++i) free(MatB[i]);
    free(MatB);

    for (int i = 0; i < n; ++i) free(output[i]);
    free(output);


    return 0;
}