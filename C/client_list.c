#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main();
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
void change_client_options();
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
        printf(" 1.  Alta de clientes\n");
        printf(" 2.  Cambio de cliente\n");
        printf(" 3.  Borrado de clientes\n");
        printf(" 4.  Reportes de clientes\n");
        printf(" 5.  Localizar cliente\n");
        printf(" 6.  Manual de Usuario\n");
        printf(" 7.  Salir\n");
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
void view_client_name(int id)
{
    printf("El nombre del cliente es:\n%s\n",
           clients[id].name);
}
void change_client_name(int id)
{
    char *data;
    printf("Escribe el nombre del cliente\n");
    scanf("%s", data);
    clients[id].name = data;
}
void view_client_email(int id)
{
    printf("El email del cliente es:\n%s\n",
           clients[id].email);
}
void change_client_email(int id)
{
    char *data;
    bool validate = false;
    while (!validate)
    {
        printf("Escribe el email del cliente\n");
        scanf("%s", data);
        validate = validate_email(data);
    }
    clients[id].email = data;
}
void view_client_calle(int id)
{
    printf("La calle del cliente es:\n%s\n",
           clients[id].calle);
}
void change_client_calle(int id)
{
    char *data;
    printf("Escribe la calle del cliente\n");
    scanf("%s", data);
    clients[id].calle = data;
}
void view_client_number(int id)
{
    printf("El numero del cliente es:\n%s\n",
           clients[id].number);
}
void change_client_number(int id)
{
    char *data;
    printf("Escribe el numero del cliente\n");
    scanf("%s", data);
    clients[id].number = data;
}
void view_client_cp(int id)
{
    printf("El Codigo Postal del cliente es:\n%s\n",
           clients[id].cp);
}
void change_client_cp(int id)
{
    char *data;
    printf("Escribe el Codigo Postal del cliente\n");
    scanf("%s", data);
    clients[id].cp = data;
}
void view_client_colonia(int id)
{
    printf("La colonia del cliente es:\n%s\n",
           clients[id].colonia);
}
void change_client_colonia(int id)
{
    char *data;
    printf("Escribe la colonia del cliente\n");
    scanf("%s", data);
    clients[id].colonia = data;
}
void view_client_municipio(int id)
{
    printf("El municipio del cliente es:\n%s\n",
           clients[id].municipio);
}
void change_client_municipio(int id)
{
    char *data;
    printf("Escribe el municipio del cliente\n");
    scanf("%s", data);
    clients[id].municipio = data;
}
void view_client_estado(int id)
{
    printf("El estado del cliente es:\n%s\n",
           clients[id].estado);
}
void change_client_estado(int id)
{
    char *data;
    printf("Escribe el estado del cliente\n");
    scanf("%s", data);
    clients[id].estado = data;
}
void view_client_pais(int id)
{
    printf("El pais del cliente es:\n%s\n",
           clients[id].pais);
}
void change_client_pais(int id)
{
    char *data;
    printf("Escribe el pais del cliente\n");
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
        printf("Escribe el numero del cliente\n");
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
    change_client_municipio(i);
    change_client_estado(i);
    change_client_pais(i);
    printf("\n\n");
    printf("Cliente añadido");
    printf("\n\n");
}
void change_client_menu()
{
    bool finish = false;
    int id, field;
    printf("Introduce el ID del cliente\n");
    scanf("%i", &id);
    while (!finish)
    {

        printf("Escribe el campo que quieras modificar\n");
        printf("Opciones disponibles\n");
        printf(" 1.  Nombre\n");
        printf(" 2.  Email\n");
        printf(" 3.  Calle\n");
        printf(" 4.  Numero\n");
        printf(" 5.  Codigo Postal\n");
        printf(" 6.  Municipio\n");
        printf(" 7.  Estado\n");
        printf(" 8.  Pais\n");
        printf(" 9.  Salir\n");
        scanf("%i", &field);
        change_client_options(id, field);
    }
}
void change_client_options(int id, int field)
{
    switch (field)
    {
    case 1:
        view_client_name(id);
        change_client_name(id);
        change_client_menu();
    case 2:
        view_client_email(id);
        change_client_email(id);
        change_client_menu();
    case 3:
        view_client_calle(id);
        change_client_calle(id);
        change_client_menu();
    case 4:
        view_client_number(id);
        change_client_number(id);
        change_client_menu();
    case 5:
        view_client_cp(id);
        change_client_cp(id);
        change_client_menu();
    case 6:
        view_client_municipio(id);
        change_client_municipio(id);
        change_client_menu();
    case 7:
        view_client_estado(id);
        change_client_estado(id);
        change_client_menu();
    case 8:
        view_client_pais(id);
        change_client_pais(id);
        change_client_menu();
    case 9:
        exit(-1);
    default:
        break;
    }
}
void select_menu_option(int option)
{
    switch (option)
    {
    case 1:
        create_client();
        main();
    case 2:
        change_client_menu();
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
        exit(-1);
    default:
        break;
    };
}
int main()
{
    int option;
    option = menu();
    read_database();
    select_menu_option(option);
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