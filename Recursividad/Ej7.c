/*Diseñe una función recursiva que devuelva cuántos elementos de una matriz A de nxm elementos
enteros cumplen que es mayor que el resto de los elementos de su fila y menor que el resto de
elementos de su columna o viceversa, es decir, es menor que el resto de los elementos de su fila y
mayor que el resto de los elementos de su columna.*/

#include <stdio.h>

// Declaraciones de funciones
int llamada_matriz(int *A[], int n, int m);
int matriz(int *A[], int n, int m, int i, int j, int cont);
int es_mayor_fila_menor_columna(int *A[], int n, int m, int i, int j, int k);
int es_menor_fila_mayor_columna(int *A[], int n, int m, int i, int j, int k);

int llamada_matriz(int *A[], int n, int m)
{
    return matriz(A, n, m, 0, 0, 0);
}

int matriz(int *A[], int n, int m, int i, int j, int cont)
{
    if (i >= n)
    {
        return cont;
    }

    if (j < m)
    {
        cont += es_mayor_fila_menor_columna(A, n, m, i, j, 0);
        cont += es_menor_fila_mayor_columna(A, n, m, i, j, 0);
        return matriz(A, n, m, i, j + 1, cont);
    }

    return matriz(A, n, m, i + 1, 0, cont);
}

int es_mayor_fila_menor_columna(int *A[], int n, int m, int i, int j, int k)
{
    if (k >= m + n)
    {
        return 1;
    }
    if (k < m)
    {
        if (k == j)
        {
            return es_mayor_fila_menor_columna(A, n, m, i, j, k + 1);
        }
        if (A[i][j] <= A[i][k])
        {
            return 0;
        }
        else
        {
            return es_mayor_fila_menor_columna(A, n, m, i, j, k + 1);
        }
    }
    if (k >= m) 
    {
        if (k - m == i)
        {
            return es_mayor_fila_menor_columna(A, n, m, i, j, k + 1);
        }
        if (A[i][j] >= A[k - m][j])
        {
            return 0;
        }
        else
        {
            return es_mayor_fila_menor_columna(A, n, m, i, j, k + 1);
        }
    }
    
    return 0; // Por seguridad, aunque no deberíamos llegar aquí
}

int es_menor_fila_mayor_columna (int *A[], int n, int m, int i, int j, int k)
{
    if (k >= m + n)
    {
        return 1;
    }
    if (k < m)
    {
        if (k == j)
        {
            return es_menor_fila_mayor_columna(A, n, m, i, j, k + 1);
        }
        if (A[i][j] >= A[i][k])
        {
            return 0;
        }
        else
        {
            return es_menor_fila_mayor_columna(A, n, m, i, j, k + 1);
        }
    }
    if (k >= m) 
    {
        if (k - m == i)
        {
            return es_menor_fila_mayor_columna(A, n, m, i, j, k + 1);
        }
        if (A[i][j] <= A[k - m][j])
        {
            return 0;
        }
        else
        {
            return es_menor_fila_mayor_columna(A, n, m, i, j, k + 1);
        }
    }
    
    return 0; // Por seguridad, aunque no deberíamos llegar aquí
}

// Función principal para probar el código
int main()
{
    // Ejemplo 1: Matriz 3x3
    printf("Ejemplo 1: Matriz 3x3\n");
    int fila1_1[] = {1, 1, 3};
    int fila1_2[] = {4, 2, 6};
    int fila1_3[] = {7, 1, 9};
    
    int *matriz1[] = {fila1_1, fila1_2, fila1_3};
    
    printf("Matriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%2d ", matriz1[i][j]);
        }
        printf("\n");
    }
    
    int resultado1 = llamada_matriz(matriz1, 3, 3);
    printf("Elementos que cumplen la condición: %d\n\n", resultado1);
    
    // Ejemplo 2: Matriz 2x4
    printf("Ejemplo 2: Matriz 2x4\n");
    int fila2_1[] = {5, 2, 9, 1};
    int fila2_2[] = {7, 3, 8, 4};
    
    int *matriz2[] = {fila2_1, fila2_2};
    
    printf("Matriz:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", matriz2[i][j]);
        }
        printf("\n");
    }
    
    int resultado2 = llamada_matriz(matriz2, 2, 4);
    printf("Elementos que cumplen la condición: %d\n", resultado2);
    
    system ("pause");
    return 0;
}