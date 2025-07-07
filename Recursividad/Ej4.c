/*Dado un vector ordenado crecientemente A[1..n], siendo n ≥ 1, diseñe una función recursiva que
calcule la longitud de la escalera más larga, es decir, la longitud de la secuencia más larga de valores
consecutivos que se encuentre en A.*/
int llamada_escalera(int *v, int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return escalera(v, n, 1, 1);
}


int escalera(int *v, int n, int i, int res, int actual)
{
    if (i >= n)
    {
        return res;
    }

    if(v[i] == v[i+1])
    {
        res++;
    }
}