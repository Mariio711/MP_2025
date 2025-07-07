/*Diseñe una función recursiva que calcule la i-ésima cifra de un entero n. No se debe hacer uso de
un vector.*/

int iesima(int num, int i)
{
    if (i == 1)
    {
        return num % 10; //aislamos la cifra requerida y la devolvemos
    }else
    {
        return iesima(num / 10, i - 1); //eliminamos la ultima cifra hasta llegar a la cifra requerida
    }
}