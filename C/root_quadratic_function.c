#include <stdio.h>
#include <math.h>
float discriminant(float a, float b, float c)
{
    float b2 = powf(b, 2);
    return b2 - 4 * a * c;
}

void calculate_values(float a, float b, float sqrt_value, float *x1, float *x2)
{
    *x1 = (-b + sqrt_value) / (2 * a);
    *x2 = (-b - sqrt_value) / (2 * a);
}

float solve(float a, float b, float c)
{
    float discriminant_value;
    float sqrt_value;
    float x1;
    float x2;
    discriminant_value = discriminant(a, b, c);
    if (discriminant_value >= 0)
    {
        sqrt_value = sqrtf(discriminant_value);
        calculate_values(a, b, sqrt_value, &x1, &x2);
        printf("Las soluciones de la ecuación son\n %f y %f",
               x1,
               x2);
    }
    else
        printf("No hay soluciones reales");
}

int main()
{
    float a = 1;
    float b = -10;
    float c = 5;
    solve(a, b, c);
    return 0;
}