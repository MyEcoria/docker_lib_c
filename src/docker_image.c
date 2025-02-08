/*
** EPITECH PROJECT, 2025
** docker_api.c
** File description:
** This code is used to make a request to the Docker API
*/
#include "docker.h"

bool pull_image(char *image)
{
    char pull_url[256];
    char *buffer;

    sprintf(pull_url, "http://localhost/images/create?fromImage=%s", image);
    buffer = make_api_request_post(pull_url, "");
    if (!buffer || strstr(buffer, "error")) {
        printf("%s", buffer);
        return false;
    } else {
        return true;
    }
}
