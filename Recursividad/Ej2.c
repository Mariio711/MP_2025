/*Diseñe una función que localice de forma recursiva, en la misma pasada, el máximo y el mínimo de
un vector dado no vacío.*/

void minmax(int *v, int n, int *min, int *max, int auxmin, int auxmax);
void llamada_minmax(int *v, int n, int *min, int *max);

void llamada_minmax(int *v, int n, int *min, int *max)
{
    *min = n-1;
    *max = n-1;
    minmax(v, n-2, min, max, v[n-1], v[n-1]);
}

void minmax(int *v, int n, int *min, int *max, int auxmin, int auxmax)
{
    if (n < 0)
    {
        return;
    }else
    {
        if (v[n] < auxmin)
        {
            auxmin = v[n];
            *min = n;
        }
        if (v[n] > auxmax)
        {
            auxmax = v[n];
            *max = n;
        }
    }
    minmax(v, n-1, min, max, auxmin, auxmax);
}

