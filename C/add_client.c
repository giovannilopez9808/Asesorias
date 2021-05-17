#include <stdbool.h>
#include <string.h>
#include <stdio.h>
int obtain_number_new_client()
{
    int clients_number = obtain_clients_number();
    int j;
    for (int i = 0; i < clients_number; i++)
    {
        if (clients[i].ID == NULL)
        {
            j = i;
            break;
        }
    }
}
bool validate_client_ID(char *id)
{
    if (strlen(id) >= 4 && strlen(id) <= 6)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void change_client_id(int id)
{
    bool validate = false;
    char *data;
    while (!validate)
    {
        printf("Escribe el numero del nuevo cliente\n");
        scanf("%s", data);
        validate = validate_client_ID(data);
    }
    clients[id].ID = data;
}
void change_client_name(int id)
{
    char *data;
    printf("Escribe el nombre del nuevo cliente\n");
    scanf("%s", data);
    clients[id].name = data;
}
void change_client_email(int id)
{
    char *data;
    bool validate = false;
    while (!validate)
    {
        printf("Escribe el email del nuevo cliente\n");
        scanf("%s", data);
        validate = validate_email(data);
    }
    clients[id].email = data;
}
void change_client_calle(int id)
{
    char *data;
    printf("Escribe la calle del nuevo cliente\n");
    scanf("%s", data);
    clients[id].calle = data;
}
void change_client_number(int id)
{
    char *data;
    printf("Escribe el numero del nuevo cliente\n");
    scanf("%s", data);
    clients[id].number = data;
}
void change_client_cp(int id)
{
    char *data;
    printf("Escribe el Codigo Postal del nuevo cliente\n");
    scanf("%s", data);
    clients[id].cp = data;
}
void change_client_colonia(int id)
{
    char *data;
    printf("Escribe la colonia del nuevo cliente\n");
    scanf("%s", data);
    clients[id].colonia = data;
}
void change_client_estado(int id)
{
    char *data;
    printf("Escribe el estado del nuevo cliente\n");
    scanf("%s", data);
    clients[id].estado = data;
}
void change_client_pais(int id)
{
    char *data;
    printf("Escribe el pais del nuevo cliente\n");
    scanf("%s", data);
    clients[id].pais = data;
}
void create_client()
{
    int i = obtain_number_new_client();
    change_client_id(i);
    change_client_name(i);
    change_client_email(i);
    change_client_calle(i);
    change_client_number(i);
    change_client_cp(i);
    change_client_colonia(i);
    change_client_estado(i);
    change_client_pais(i);
    printf("\n\n");
    printf("Cliente añadido");
    printf("\n\n");
}