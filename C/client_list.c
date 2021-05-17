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
struct client clients[256];
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
    if (isat)
        printf("Si hay @\n");
    if (isdotcom)
        printf("Si hay .com");
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

void select_option(int option)
{
    switch (option)
    {
    case 1:
        printf("Opcion 1");
        break;
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