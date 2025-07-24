/*Dado un vector A[1..n] de n enteros estrictamente positivos, siendo n ≥ 1, diseñe una función
recursiva que obtenga el número de parejas (j, k) que cumplan:*/

#include <stdio.h>

int llamada_parejas(int *A, int n);
int parejas(int *A, int n, int j, int k, int cont);
int sum_vec_rec(int *A, int n, int i, int sum);

int llamada_parejas(int *A, int n)
{
    return parejas(A, n, 0, 0, 0);
}

int parejas(int *A, int n, int j, int k, int cont)
{
    if (j >= n)
    {
        return cont;
    }

    if(k >= n)
    {
        return parejas(A, n, j + 1, 0, cont);
    }
    
    // Suma desde A[0] hasta A[j] (inclusive)
    int suma_j = sum_vec_rec(A, j + 1, 0, 0);
    // Suma desde A[k] hasta A[n-1] (inclusive)
    int suma_k = sum_vec_rec(A, n, k, 0);
    
    if (suma_j == suma_k)
    {
        cont++;
        printf("cumple la condicion para j = %i y k = %i\n", j, k);
    }

    return parejas(A, n, j, k + 1, cont);
}

int sum_vec_rec(int *A, int n, int i, int sum)
{
    if (i >= n)
    {
        return sum;
    }

    return sum_vec_rec(A, n, i + 1, sum += A[i]);
}

int main() {
    // Ejemplo: A = {2, 1, 3, 2}
    // Hay al menos una pareja (j=2, k=1) que cumple la condición
    int A[] = {2, 1, 3, 2};
    int n = sizeof(A) / sizeof(A[0]);
    int resultado = llamada_parejas(A, n);
    printf("Numero de parejas (j, k) que cumplen la condicion: %d\n", resultado);
    system("pause");
    return 0;
}