/*
** EPITECH PROJECT, 2025
** docker_api.c
** File description:
** This code is used to make a request to the Docker API
*/
#include "docker.h"

char *get_conteneurs(void)
{
    return make_api_request("http://localhost/containers/json");
}

char *create_conteneur(char *image, int ports[], int port_count, char *name)
{
    char *create = generate_config(image, ports, port_count, name);
    char *buffer;
    char *id = GC_MALLOC(64 + 1);

    buffer = make_api_request_post("http://localhost/containers/create",
        create);
    if (strstr(buffer, "Id")) {
        sscanf(buffer, "{\"Id\":\"%[^\"]\"", id);
        return id;
    } else {
        return NULL;
    }
    return NULL;
}

bool exec_process(char *id, char *cmd)
{
    char exec_url[256];
    char *buffer;

    sprintf(exec_url, "http://localhost/exec/%s/start", id);
    buffer = make_api_request_post(exec_url, cmd);
    if (strstr(buffer, "message")) {
        return false;
    } else {
        return true;
    }
}

bool exec_process_start(char *id)
{
    char exec_url[256];
    char *buffer;
    char *cmd = "{\"Detach\": false, \"Tty\": false}";

    sprintf(exec_url, "http://localhost/exec/%s/start", id);
    buffer = make_api_request_post(exec_url, cmd);
    if (strstr(buffer, "message")) {
        return false;
    } else {
        return true;
    }
}

bool start_conteneur(char *id)
{
    char start_url[256];
    char *buffer;

    sprintf(start_url, "http://localhost/containers/%s/start", id);
    buffer = make_api_request_post(start_url, "");
    if (strstr(buffer, "message")) {
        printf("%s", buffer);
        return false;
    } else {
        return true;
    }
}

bool stop_conteneur(char *id)
{
    char start_url[256];
    char *buffer;

    sprintf(start_url, "http://localhost/containers/%s/stop", id);
    buffer = make_api_request_post(start_url, "");
    if (strstr(buffer, "message")) {
        printf("%s", buffer);
        return false;
    } else {
        return true;
    }
}

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
