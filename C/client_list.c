#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "clients.h"
void change_client_options();
void create_files_options();
void create_search_options();
void change_client_menu();
int search_from_client_ID();
bool does_clien_exist();
void create_menu();
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
void view_client_name(int id)
{
    printf("El nombre del cliente es: %s\n",
           clients[id]->name);
}
void change_client_name(int id)
{
    char data;
    printf("Escribe el nombre del cliente: ");
    getchar();
    scanf("%[^\n]", &data);
    clients[id]->name = strdup(&data);
}
void view_client_email(int id)
{
    printf("El email del cliente es: %s\n",
           clients[id]->email);
}
void change_client_email(int id)
{
    char data;
    bool validate = false;
    while (!validate)
    {
        printf("Escribe el email del cliente: ");
        getchar();
        scanf("%[^\n]", &data);
        validate = validate_email(&data);
    }
    clients[id]->email = &data;
}
void view_client_calle(int id)
{
    printf("La calle del cliente es: %s\n",
           clients[id]->calle);
}
void change_client_calle(int id)
{
    char data;
    printf("Escribe la calle del cliente: ");
    getchar();
    scanf("%[^\n]", &data);
    clients[id]->calle = strdup(&data);
}
void view_client_number(int id)
{
    printf("El numero del cliente es: %s\n",
           clients[id]->number);
}
void change_client_number(int id)
{
    char data;
    printf("Escribe el numero del cliente: ");
    getchar();
    scanf("%[^\n]", &data);
    clients[id]->number = strdup(&data);
}
void view_client_cp(int id)
{
    printf("El Codigo Postal del cliente es: %s\n",
           clients[id]->cp);
}
void change_client_cp(int id)
{
    char data;
    printf("Escribe el codigo postal del cliente: ");
    getchar();
    scanf("%[^\n]", &data);
    clients[id]->cp = strdup(&data);
}
void view_client_colonia(int id)
{
    printf("La colonia del cliente es: %s\n",
           clients[id]->colonia);
}
void change_client_colonia(int id)
{
    char data;
    printf("Escribe la colonia del cliente: ");
    getchar();
    scanf("%[^\n]", &data);
    clients[id]->colonia = strdup(&data);
}
void view_client_municipio(int id)
{
    printf("El municipio del cliente es: %s\n",
           clients[id]->municipio);
}
void change_client_municipio(int id)
{
    char data;
    printf("Escribe el municipio del cliente: ");
    getchar();
    scanf("%[^\n]", &data);
    clients[id]->municipio = &data;
    view_client_municipio(id);
}
void view_client_estado(int id)
{
    printf("El estado del cliente es: %s\n",
           clients[id]->estado);
}
void change_client_estado(int id)
{
    char data;
    printf("Escribe el estado del cliente: ");
    getchar();
    scanf("%[^\n]", &data);
    clients[id]->estado = strdup(&data);
}
void view_client_pais(int id)
{
    printf("El pais del cliente es: %s\n",
           clients[id]->pais);
}
void change_client_pais(int id)
{
    char data;
    printf("Escribe el pais del cliente: ");
    getchar();
    scanf("%[^\n]", &data);
    clients[id]->pais = strdup(&data);
}
void init_change_client_menu()
{
    bool client_exists = false;
    int location;
    char number;
    while (!client_exists)
    {
        printf("Introduce el ID del cliente: ");
        scanf("%s", &number);
        location = search_from_client_ID(&number);
        client_exists = does_clien_exist(location);
    }
    change_client_menu(location);
}
void change_client_menu(int location)
{
    int field;
    printf("Opciones disponibles\n");
    printf(" 1.  Nombre\n");
    printf(" 2.  Email\n");
    printf(" 3.  Calle\n");
    printf(" 4.  Numero\n");
    printf(" 5.  Codigo Postal\n");
    printf(" 6.  Municipio\n");
    printf(" 7.  Estado\n");
    printf(" 8.  Pais\n");
    printf(" 9.  Regresar al menu\n");
    printf("Escribe el campo que quieras modificar: ");
    scanf("%i", &field);
    change_client_options(location, field);
}
void change_client_options(int id, int field)
{
    switch (field)
    {
    case 1:
        view_client_name(id);
        change_client_name(id);
    case 2:
        view_client_email(id);
        change_client_email(id);
    case 3:
        view_client_calle(id);
        change_client_calle(id);
    case 4:
        view_client_number(id);
        change_client_number(id);
    case 5:
        view_client_cp(id);
        change_client_cp(id);
    case 6:
        view_client_municipio(id);
        change_client_municipio(id);
    case 7:
        view_client_estado(id);
        change_client_estado(id);
    case 8:
        view_client_pais(id);
        change_client_pais(id);
    case 9:
        create_menu();
    default:
        change_client_menu(id);
    };
}
void create_file_complete()
{
    FILE *file;
    int client_number = obtain_number_new_client();
    file = fopen("Listado_completo.csv", "w");
    for (int i = 0; i < client_number; i++)
    {
        fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s",
                clients[i].ID,
                clients[i].name,
                clients[i].email,
                clients[i].calle,
                clients[i].number,
                clients[i].cp,
                clients[i].colonia,
                clients[i].municipio,
                clients[i].estado,
                clients[i].pais);
    }
    fclose(file);
    printf("\n\n");
    printf("Archivo listo");
    printf("\n\n");
}
void create_file_sorted_by_names()
{
    int clients_number = obtain_clients_number();
    FILE *file;
    int client_number = obtain_number_new_client();
    file = fopen("Ord_ID_Cliente.csv", "w");
    for (int i = 0; i < client_number; i++)
    {
        fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s",
                clients[i].ID,
                clients[i].name,
                clients[i].email,
                clients[i].calle,
                clients[i].number,
                clients[i].cp,
                clients[i].colonia,
                clients[i].municipio,
                clients[i].estado,
                clients[i].pais);
    }
    fclose(file);
    printf("\n\n");
    printf("Archivo listo");
    printf("\n\n");
}
void create_file_sorted_by_IDs()
{
    FILE *file;
    int client_number = obtain_number_new_client();
    file = fopen("Listado_completo.csv", "w");
    for (int i = 0; i < client_number; i++)
    {
        fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s",
                clients[i].ID,
                clients[i].name,
                clients[i].email,
                clients[i].calle,
                clients[i].number,
                clients[i].cp,
                clients[i].colonia,
                clients[i].municipio,
                clients[i].estado,
                clients[i].pais);
    }
    fclose(file);
    printf("\n\n");
    printf("Archivo listo");
    printf("\n\n");
}
void select_file_option(int file_option)
{
    switch (file_option)
    {
    case 1:
        create_file_complete();
        create_files_options();
    case 2:
        create_file_sorted_by_names();
        create_files_options();
    case 3:
        break;
    case 4:
        create_menu();
    default:
        break;
    }
}
void create_files_options()
{
    int file_option;
    printf("Opciones disponibles:\n");
    printf(" 1.  Listado completo\n");
    printf(" 2.  Listado ordenado por numero de cliente\n");
    printf(" 3.  Listado ordenado por nobre de cliente\n");
    printf(" 4.  Regresar al menu\n");
    printf("Escribe la opción que deseas para los reportes de clientes: ");
    scanf("%i", &file_option);
    select_file_option(file_option);
}
int search_from_client_ID(char *id)
{
    int clients_number = obtain_clients_number();
    for (int i = 0; i < clients_number; i++)
    {
        if (clients[i].ID != NULL)
        {
            if (strcmp(clients[i].ID, id) == 0)
            {
                return i;
            }
        }
    }
    return -1;
}
int search_from_client_name(char *name)
{
    int clients_number = obtain_clients_number();
    for (int i = 0; i < clients_number - 1; i++)
    {
        if (clients[i].name != NULL)
        {
            if (strcmp(clients[i].name, name) == 0)
            {
                return i;
            }
        }
    }
    return -1;
}
bool does_clien_exist(int location)
{
    if (location == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void print_client_information_from_id(int id)
{
    if (does_clien_exist(id))
    {
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
               clients[id]->ID,
               clients[id]->name,
               clients[id]->email,
               clients[id]->calle,
               clients[id]->number,
               clients[id]->cp,
               clients[id]->colonia,
               clients[id]->municipio,
               clients[id]->estado,
               clients[id]->pais);
    }
    else
        printf("No se encuentra registrado el usuario\n\n");
}
void select_search_option(int search_option)
{
    char name_search;
    char id;
    int found;
    switch (search_option)
    {
    case 1:
        printf("Escribe el ID del cliente: ");
        scanf("%s", &id);
        found = search_from_client_ID(&id);
        print_client_information_from_id(found);
        create_search_options();
    case 2:
        printf("Escribe el nombre del cliente: ");
        getchar();
        scanf("%[^\n]", &name_search);
        found = search_from_client_name(&name_search);
        print_client_information_from_id(found);
        create_search_options();
    case 3:
        create_menu();
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
void create_client()
{
    int i = obtain_number_new_client();
    bool validate = false;
    char *data;
    while (!validate)
    {
        printf("Escribe el numero del cliente: ");
        scanf("%s", data);
        validate = validate_client_ID(data);
        if (validate)
        {
            int id = search_from_client_ID(data);
            validate = does_clien_exist(id);
            validate = !validate;
        }
    }
    clients[i].ID = strdup(data);
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
void select_menu_option(int option)
{
    switch (option)
    {
    case 1:
        create_client();
        create_menu();
    case 2:
        init_change_client_menu();
    case 3:
        printf("Opcion 3");
        create_menu();
    case 4:
        create_files_options();
    case 5:
        /*
    TERMINADO
    */
        create_search_options();
        create_menu();
    case 6:
        printf("Opcion 6");
        break;
    case 7:
        /*
    TERMINADO
    */
        exit(-1);
    default:
        create_menu();
    };
}
void create_search_options()
{
    int search_option;
    printf("Escribe la opción que deseas para buscar usuarios\n");
    printf(" 1. Por numero de cliente\n");
    printf(" 2. Por nombre de cliente\n");
    printf(" 3. Regresar al menu\n");
    scanf("%i", &search_option);
    select_search_option(search_option);
}
int menu()
{
    int option;
    printf("MENU\n");
    printf(" 1.  Alta de clientes\n");
    printf(" 2.  Cambio de cliente\n");
    printf(" 3.  Borrado de clientes\n");
    printf(" 4.  Reportes de clientes\n");
    printf(" 5.  Localizar cliente\n");
    printf(" 6.  Manual de Usuario\n");
    printf(" 7.  Salir\n");
    scanf("%i", &option);
    return option;
}
void create_menu()
{
    int option;
    option = menu();
    select_menu_option(option);
}
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
int main()
{
    read_database();
    create_menu();
    return 0;
}