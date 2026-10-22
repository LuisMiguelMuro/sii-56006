#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>




int main(int argc, char **argv) {
    int fd;
    char buffer[1024];

    // borrar FIFO por si existiera previamente
    unlink("my_fifo");

    /* crear el FIFO */
    if (mkfifo("my_fifo", 0600)<0) {
        perror("No puede crearse el FIFO");
        return(1);
    }
    /* Abrir el FIFO */
    if ((fd = open("my_fifo",O_RDONLY)) < 0) {
        perror("Error de apertura del FIFO");
        return(1);
    }
    /* Leer de la FIFO */
    while ((read(fd, buffer, sizeof(buffer))) > 0) {
	// X5: Imprimir el texto en la pantalla
	printf("%s\n",buffer);
    }
    close(fd);
    unlink("my_fifo");
    return(0);
}
