/*
** EPITECH PROJECT, 2025
** create.c
** File description:
** This code is used to test the Docker API
*/
#include "docker.h"

int main(void)
{
    char *image = "hashicorp/http-echo:latest";
    char *id;
    char *conteneurs;

    if (pull_image(image) == false) {
        return 84;
    }
    conteneurs = get_conteneurs();
    printf("%s\n", conteneurs);
    id = create_conteneur(image, (int[]){5678, 5678}, 2, "test");
    printf("%s\n", id);
    if (start_conteneur(id) == false) {
        return 84;
    }
    return 0;
}
