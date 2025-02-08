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

- `.gitignore`: Specifies files and directories to be ignored by Git.
- `Makefile`: Contains the build instructions for the project.
- `README.md`: This file.
- `examples/create.c`: An example usage of the library.
- `include/docker.h`: Header file containing function declarations and macros.
- `src/docker_api.c`: Implementation of API request functions.
- `src/docker_config.c`: Implementation of Docker container configuration functions.

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