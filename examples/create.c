#include "docker.h"

int main(void)
{
    char *image = "ubuntu:latest";
    char *id;
    char *conteneurs;

    if (pull_image(image) == false) {
        return 84;
    }
    conteneurs = get_conteneurs();
    printf("%s\n", conteneurs);
    id = create_conteneur("ubuntu", (int[]){80, 8080}, 2, "test");
    printf("%s\n", id);
    return 0;
}
