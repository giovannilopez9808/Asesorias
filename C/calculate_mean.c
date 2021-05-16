#include <stdio.h>

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

int main()
{
    int longitude;
    float mean;
    float data[] = {123, 1321, 1616, 1632};
    // Obtener la longitud de un array
    int size = sizeof(data);
    int size_variable = sizeof(data[0]);
    longitude = size / size_variable;
    //
    mean = obtain_mean(data, longitude);
    printf("%f", mean);
    return 0;
}