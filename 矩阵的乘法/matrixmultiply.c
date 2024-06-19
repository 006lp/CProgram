#include <stdio.h>
#include <stdlib.h>

// 矩阵乘法函数
void matrixmultiply(double *a, double *b, double *c, int m, int n, int p) {
    // 初始化结果矩阵C为0
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            c[i * p + j] = 0;
        }
    }

    // 进行矩阵乘法计算
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i * p + j] += a[i * n + k] * b[k * p + j];
            }
        }
    }
}

// 打印矩阵函数
void printMatrix(double *matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%f\t", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

int main() {
    // 定义矩阵A, B的维度
    int m = 2, n = 3, p = 2;
    
    // 分配并初始化矩阵A (2x3)
    double a[] = {1, 2, 3, 4, 5, 6};

    // 分配并初始化矩阵B (3x2)
    double b[] = {7, 8, 9, 10, 11, 12};

    // 分配矩阵C (2x2)
    double c[m * p];

    // 进行矩阵乘法
    matrixmultiply(a, b, c, m, n, p);

    // 打印结果矩阵C
    printf("结果矩阵C:\n");
    printMatrix(c, m, p);

    return 0;
}
