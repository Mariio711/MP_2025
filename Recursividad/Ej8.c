/*Dado un vector A[1..n] de n enteros estrictamente positivos, siendo n ≥ 1, diseñe una función
recursiva que obtenga el número de parejas (j, k) que cumplan:*/

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
    
    if (sum_vec_rec(A, j, 0, 0) == sum_vec_rec(A, n, k, 0))
    {
        cont++;
    }

    return parejas(A, n, j, k + 1, cont);
}