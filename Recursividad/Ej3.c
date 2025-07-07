/*Diseñe una función recursiva que devuelva el producto escalar de dos vectores de n elementos
enteros, n ≥ 0.*/

int escalar(int *v1, int *v2, int n, int res);
int llamada_escalar(int *v1, int *v2, int n);

int llamada_escalar(int *v1, int *v2, int n)
{
    return escalar(v1, v2, n-1, 0);
}

int escalar(int *v1, int *v2, int n, int res)
{
    if (n < 0)
    {
        return res;
    }
    else
    {
        res += (v1[n] * v2[n]);
        return escalar(v1, v2, n - 1, res);
    }
}