/*Diseñe una función recursiva que calcule la suma de todos los elementos de un vector A de n enteros
que cumplen la siguiente propiedad: (...)*/

#include <stdio.h>
#include <stdlib.h>
#define N 20

void leer_vector(int v[], int i);
int sum_vect(int v[], int j, int suma);

int main()
{
    int v[N];
    int i = 1, j = 1, suma = 0;

    leer_vector(v, i);
    suma = sum_vect(v, j, suma);

    printf("La suma es: %d", suma);

    return 0;
}

void leer_vector(int v[], int i)
{
    if (i< ((N/2)-1))
    {
        printf("Introduce el valor de la posición %i del vector: ", i);
        fflush(stdin);
        scanf("%i", &v[i]);

        leer_vector(v, i+1);
    }
}

int sum_vect(int v[], int j, int suma)
{
    if (j<((N/2)-1))
    {
        if (v[j] >= v[2*j] && v[j] > v[2*j+1])
        {
            suma = suma + v[j];
            sum_vect(v, j+1, suma);
        }
        else
            sum_vect(v, j+1, suma);
    }
    else
        return suma;
}
