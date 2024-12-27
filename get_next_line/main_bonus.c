#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd1, fd2;
    char *line;

    // Ouvrir plusieurs fichiers en lecture seule
    fd1 = open("text1.txt", O_RDONLY);
    fd2 = open("text2.txt", O_RDONLY);
    if (fd1 < 0 || fd2 < 0)
    {
        perror("Error opening files");
        return (1);
    }

    // Lire et afficher les lignes des deux fichiers
    printf("Reading lines from multiple files:\n\n");

    for (int i = 0; i < 5; i++) // Lire 5 lignes pour tester le multi-descripteur
    {
        line = get_next_line(fd1);
        if (line)
        {
            printf("FD1: %s", line);
            free(line);
        }

        line = get_next_line(fd2);
        if (line)
        {
            printf("FD2: %s", line);
            free(line);
        }
    }

    // Fermer les fichiers
    close(fd1);
    close(fd2);

    return (0);
}
