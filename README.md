# docker_lib_c

This project provides a C library to interact with the Docker API.

## Installation

To install the required dependencies, run the following commands:
```
sudo apt-get install libcurl4-openssl-dev
sudo apt-get install libgc-dev
```

## Usage

An example of how to use this library can be found in the `examples/create.c` file. Below is a brief example:

```c
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
```

## Files

- `.gitignore`: Spécifie les fichiers et dossiers à ignorer par Git.
- `Makefile`: Contient les instructions de compilation du projet.
- `README.md`: Ce fichier.
- `examples/create.c`: Exemple d'utilisation de la bibliothèque.
- `include/docker.h`: Fichier d'en-tête contenant les déclarations de fonctions et macros.
- `src/docker_api.c`: Implémentation des fonctions de requête vers l'API Docker.
- `src/docker_config.c`: Implémentation des fonctions de configuration des conteneurs Docker.
- `src/docker_image.c`: Implémentation des fonctions de gestion des images Docker.
- `src/docker_utils.c`: Implémentation des fonctions utilitaires.
- `src/docker_containers.c`: Implémentation des fonctions de gestion des conteneurs Docker.
- `src/docker_process.c`: Implémentation des fonctions de gestion de processus Docker.

## Building

To build the project, run:
```
make
```

To clean the build files, run:
```
make clean
```

To clean all files including the binary, run:
```
make fclean
```

To run tests, run:
```
make test
```

## Contributing

Feel free to contribute by opening issues or submitting pull requests.

## License

This project is licensed under the MIT License.