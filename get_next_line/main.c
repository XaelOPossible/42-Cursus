#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    char *line;

    // Ouvrir un fichier test en lecture seule
    fd = open("text2.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    // Lire les lignes avec get_next_line
    printf("Reading lines from file: test2.txt\n\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // La ligne inclut normalement le '\n'
        free(line);         // Libérez la mémoire allouée par get_next_line
    }

    // Fermer le fichier
    close(fd);

    return (0);
}
