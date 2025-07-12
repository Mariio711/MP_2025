/*Diseñe una función recursiva que determine si en un vector A de n enteros existen dos parejas
consecutivas de elementos tales que sus sumas sean idénticas.*/

int llamada_parejasum(int *v, int n)
{
    return parejasum(v, n, 0);
}

int parejasum(int *v, int n, int i)
{
    if (i > (n - 3))
    {
        return 0;
    }

    if ((v[i] + v[i + 1]) == (v[i + 2] + v[i + 3]))
    {
        return 1;
    }

    return parejasum(v, n, i + 1);
}