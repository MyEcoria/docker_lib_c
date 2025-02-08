/*
** EPITECH PROJECT, 2024
** my
** File description:
** my
*/

#ifndef DOCKER_H
    #define DOCKER_H
    #define SOCKET_ADDRESS "/var/run/docker.sock"
    #include <stdbool.h>
    #include <curl/curl.h>
    #include <json-c/json.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <gc.h>

struct MemoryBuffer {
    char *data;
    size_t size;
};

void fonction_initiale(void) __attribute__((constructor));
char *make_api_request(char *url);
char *make_api_request_post(char *url, char *json_data);
char *get_conteneurs(void);
char *create_conteneur(char *image, int ports[], int port_count, char *name);
bool start_conteneur(char *id);
bool allow_more_space(char **json, size_t *json_size);
void generate_ports_boucle(int ports[], int count,
    struct json_object *port_bindings);
struct json_object *generate_ports_config(int ports[], int count);
void generate_exposed_ports_boucle(int ports[], int count,
    struct json_object *exposed_ports);
struct json_object *generate_exposed_ports_config(int ports[], int count);
char *generate_config(char *image, int ports[], int port_count, char *name);
int int_len(long long int nb);
bool exec_process_start(char *id);
bool pull_image(char *image);
bool exec_process(char *id, char *cmd);
bool exec_process_start(char *id);
#endif
