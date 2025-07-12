/*Dado un vector A de n enteros, diseñe una función recursiva que determine si el vector cumple la
siguiente propiedad:

1 < i ≤ ⌊n/2⌋ : A[i] = ∑(α=1 hasta i-1) A[α] · A[n - α + 1]
*/
#include <stdio.h>
#include <stdlib.h>

int llamada_prop(int *v, int n);
int prop(int *v, int n, int i, int suma_actual, int flag);
int suma_vecrec(int *v, int n, int i, int alpha, int res);


// Aquí está el problema - la indexación debe ajustarse correctamente
int suma_vecrec(int *v, int n, int i, int alpha, int res)
{
    if (alpha >= i) // Terminar cuando alpha >= i
    {
        return res;
    }
    else
    {
        // Corregir la fórmula usando correctamente n-alpha en indexación 0
        return suma_vecrec(v, n, i, alpha + 1, 
                          res + (v[alpha-1] * v[(n-1) - (alpha-1)]));
    }
}

int prop(int *v, int n, int i, int suma_actual, int flag)
{
    if (i > n / 2 || flag == 0) // Terminar cuando i > n/2 o falla
    {
        return flag;
    }
    
    suma_actual = suma_vecrec(v, n, i, 1, 0); // Alpha comienza en 1
    
    if (suma_actual == v[i-1]) // Ajustar índice
    {
        return prop(v, n, i + 1, 0, 1);
    }
    else
    {
        return 0;
    }
}

int llamada_prop(int *v, int n)
{
    return prop(v, n, 2, 0, 1); // Empezar con i=2 (1<i) y flag=1
}

int main() {
    // Vector que realmente cumple la propiedad
    int vector1[] = {1, 2, 5, 9, 8};
    int n1 = 5;
    
    // Para i=2: A[2] = A[1]·A[5] → v[1] = v[0]·v[4] → 2 = 1·8 → 2 = 8 ❌
    
    // Vector alternativo que sí cumple
    int vector_correcto[] = {1, 4, 5, 10, 4};
    int n_correcto = 5;
    // Para i=2: A[2] = A[1]·A[5] → v[1] = v[0]·v[4] → 4 = 1·4 → 4 = 4 ✅
    
    printf("Vector 1 cumple la propiedad: %s\n", 
           llamada_prop(vector1, n1) ? "SI" : "NO");
    
    printf("Vector correcto cumple la propiedad: %s\n", 
           llamada_prop(vector_correcto, n_correcto) ? "SI" : "NO");
    
    // Vector pequeño
    int vector3[] = {1, 2};
    int n3 = 2;
    
    printf("Vector 3 cumple la propiedad: %s\n", 
           llamada_prop(vector3, n3) ? "SI" : "NO");

    // Mostrar cálculos para vector correcto
    printf("\nComprobación para vector [1, 4, 5, 10, 4]:\n");
    int i = 2;
    int suma = suma_vecrec(vector_correcto, n_correcto, i, 1, 0);
    printf("Para i=%d: v[%d] = %d, sumatoria = %d\n", 
           i, i-1, vector_correcto[i-1], suma);
    
    system("pause");
    return 0;
}