

#include "get_next_line.h"

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    if (!str)
        return i;
    while (str[i])
        i++;
    return i;
}
char *join(char *line, char a)
{
    char *aux;
     
    int i = 0;
    aux = malloc((ft_strlen(line) + 2) * sizeof(char));
    while (line[i])
    {
        aux[i] = line[i];
        i++;
    }
    aux[i] = a;
    aux[i + 1] = '\0';
    free(line);
    line = aux;
    return aux;
}
int get_next_line(char **line)
{
    char buffer[1];
    int bytes = 1;
    int i;

    *line = malloc(1);
    *line[0] = '\0';
    buffer[0] = '\0';
    while ((bytes = read(0, buffer, 1)) != -1 && bytes != 0 )
    {
        i = 0;
        if (buffer[0] == '\n')
            break;
        *line = join(*line, buffer[0]);
    }
    if (bytes == -1)
        return -1;
    return (bytes == 0) ? 0 : 1;
}