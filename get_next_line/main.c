#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return (1);
    }

    // Ouvrir le fichier en lecture seule
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    // Lire les lignes avec get_next_line
    printf("Reading lines from file: %s\n\n", argv[1]);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // La ligne inclut normalement le '\n'
        free(line);         // Libérez la mémoire allouée par get_next_line
    }

    // Fermer le fichier
    close(fd);

    return (0);
}