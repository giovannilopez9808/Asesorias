#include <stdio.h>
#include <math.h>
float obtain_mean(float *data, int longitude)
{
    float sum = 0;
    float result;
    for (int i = 0; i < longitude; i++)
    {
        sum += data[i];
    }
    return sum / longitude;
}

float obtain_std(float *data, int longitude)
{
    float mean = obtain_mean(data, longitude);
    float sum = 0;
    for (int i = 0; i < longitude; i++)
    {
        sum += pow(data[i] - mean, 2);
    }
    sum = sum / longitude;
    return sqrtf(sum);
}

int main()
{
    int longitude;
    float data[] = {123, 1321, 1616, 1632, 12315};
    // Obtener la longitud de un array
    int size = sizeof(data);
    int size_variable = sizeof(data[0]);
    longitude = size / size_variable;
    //
    float mean = obtain_mean(data, longitude);
    float std = obtain_std(data, longitude);
    printf("EL tamaño del array es %d\n", longitude);
    printf("El promedio de los datos es %f\n", mean);
    printf("La desviacion de los datos es %f\n", std);
    return 0;
}