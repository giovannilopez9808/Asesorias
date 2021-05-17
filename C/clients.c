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