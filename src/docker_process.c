/*
** EPITECH PROJECT, 2025
** docker_api.c
** File description:
** This code is used to make a request to the Docker API
*/
#include "docker.h"

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
