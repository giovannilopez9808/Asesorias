#include <stdbool.h>
#include <string.h>
#include <stdio.h>
struct client
{
    char *ID;
    char *name;
    char *email;
    char *calle;
    char *number;
    char *cp;
    char *colonia;
    char *municipio;
    char *estado;
    char *pais;
};
struct client clients[20];
int obtain_clients_number()
{
    return sizeof(clients) / sizeof(*clients);
}
/*
Lectura del csv
*/
void read_database()
{
    FILE *database = fopen("registros_de_cliente_base.csv",
                           "r");
    char line[1024];
    int i = 0;
    while (fgets(line, sizeof(line), database))
    {

        char *token;
        token = strtok(line, ",");
        clients[i].ID = strdup(token);
        token = strtok(NULL, ",");
        clients[i].name = strdup(token);
        token = strtok(NULL, ",");
        clients[i].email = strdup(token);
        token = strtok(NULL, ",");
        clients[i].calle = strdup(token);
        token = strtok(NULL, ",");
        clients[i].number = strdup(token);
        token = strtok(NULL, ",");
        clients[i].cp = strdup(token);
        token = strtok(NULL, ",");
        clients[i].colonia = strdup(token);
        token = strtok(NULL, ",");
        clients[i].municipio = strdup(token);
        token = strtok(NULL, ",");
        clients[i].estado = strdup(token);
        token = strtok(NULL, ",");
        clients[i].pais = strdup(token);
        i++;
    }
}

/*
 Validacion del email
*/
bool validate_at(char *email)
{
    char *p;
    int at_number = 0;

    p = email;
    while (*p != '\0')
    {
        if (*p == '@')
            at_number++;
        p++;
    }
    if (at_number == 1)
        return true;
    else
        return false;
}

bool validate_dot_com(char *email)
{
    char *com;
    com = &email[strlen(email) - 4];
    char com_true[] = ".com";
    if (strcmp(com, com_true) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool validate_email(char *email)
{
    bool isat = validate_at(email);
    bool isdotcom = validate_dot_com(email);
    if (isat && isdotcom)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int menu()
{
    bool valid_option = false;
    int option;
    while (!valid_option)
    {
        printf("MENU\n");
        printf("1.  Alta de clientes\n");
        printf("2.  Cambio de cliente\n");
        printf("3.  Borrado de clientes\n");
        printf("4.  Reportes de clientes\n");
        printf("5.  Localizar cliente\n");
        printf("6.  Manual de Usuario\n");
        printf("7.  Salir\n");
        scanf("%i", &option);
        if (option >= 1 && option <= 7)
        {
            valid_option = true;
        }
    }
    return option;
}
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
    bool validate = false;
    char *data;
    while (!validate)
    {
        printf("Escribe el numero del nuevo cliente\n");
        scanf("%s", data);
        validate = validate_client_ID(data);
    }
    clients[i].ID = data;
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
void select_option(int option)
{
    switch (option)
    {
    case 1:
        create_client();
        main();
    case 2:
        printf("Opcion 2");
        break;
    case 3:
        printf("Opcion 3");
        break;
    case 4:
        printf("Opcion 4");
        break;
    case 5:
        printf("Opcion 5");
        break;
    case 6:
        printf("Opcion 6");
        break;
    case 7:
        break;
    default:
        break;
    }
}
int main()
{
    int option;
    option = menu();
    read_database();
    select_option(option);
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
    //            clients[i].ID,
    //            clients[i].name,
    //            clients[i].email,
    //            clients[i].calle,
    //            clients[i].number,
    //            clients[i].cp,
    //            clients[i].colonia,
    //            clients[i].municipio,
    //            clients[i].estado,
    //            clients[i].pais);
    // }
    return 0;
}