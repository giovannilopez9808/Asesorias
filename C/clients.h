#include <stddef.h>
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
struct client *clients[20];
int obtain_clients_number()
{
    return sizeof(clients) / sizeof(*clients);
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