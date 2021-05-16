#include <stdio.h>
float suma(float a, float b)
{
    return a + b;
}
float multiplicacion(float a, float b)
{
    return a * b;
}
int main()
{
    float a = -5.0;
    float b = 2.0;
    printf("El resultado de sumar %f y %f es:\n%f\n\n",
           a,
           b,
           suma(a, b));
    printf("El resultado de multiplicar %f y %f es:\n%f\n\n",
           a,
           b,
           multiplicacion(a, b));
    return 0;
}
