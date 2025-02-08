# Documentation Technique - Docker Lib C

Ce document présente la documentation technique des fonctions majeures réparties dans les fichiers suivants :  
- **docker_process.c**  
- **docker_containers.c**  
- **docker_image.c**

---

## 1. Fichier: docker_process.c

### Fonction: exec_process

**Description :**  
Exécute une commande au sein d'un processus Docker existant.  
Elle construit une requête POST vers l'API Docker pour démarrer le processus identifié par l'ID fourni en utilisant la commande donnée en format JSON.

**Paramètres :**  
- **id** : Chaîne de caractères représentant l'identifiant du processus Docker.  
- **cmd** : Chaîne JSON contenant la commande à exécuter.

**Retour :**  
- `true` si la requête d'exécution est réussie (c'est-à-dire si la réponse ne contient pas de message d'erreur).  
- `false` sinon.

**Exemple d'utilisation :**  
```c
bool success = exec_process("container123", "{\"Cmd\":\"ls -la\"}");
```

---

### Fonction: exec_process_start

**Description :**  
Démarre un processus Docker en utilisant une configuration de commande prédéfinie, où le mode TTY est désactivé et le processus n'est pas détaché.  
Elle envoie une commande de démarrage à l'API Docker pour l'ID spécifié.

**Paramètres :**  
- **id** : Chaîne de caractères représentant l'identifiant du processus Docker.

**Retour :**  
- `true` si le démarrage du processus se fait sans erreur.  
- `false` en cas d'erreur.

**Exemple d'utilisation :**  
```c
bool started = exec_process_start("container123");
```

---

## 2. Fichier: docker_containers.c

### Fonction: get_conteneurs

**Description :**  
Récupère la liste des conteneurs Docker en effectuant une requête GET vers l'API Docker.

**Retour :**  
- Une chaîne en format JSON contenant la liste des conteneurs.

**Exemple d'utilisation :**  
```c
char *containers = get_conteneurs();
```

---

### Fonction: create_conteneur

**Description :**  
Crée un nouveau conteneur Docker basé sur une image spécifiée, avec des mappages de ports et un nom de conteneur fourni.  
Elle génère une configuration via la fonction `generate_config` et envoie une requête POST pour créer le conteneur.

**Paramètres :**  
- **image** : Nom de l'image Docker à utiliser.  
- **ports** : Tableau d'entiers représentant les ports à mapper.  
- **port_count** : Nombre d'éléments dans le tableau `ports`.  
- **name** : Nom à attribuer au conteneur créé.

**Retour :**  
- Une chaîne allouée dynamiquement contenant l'identifiant du conteneur en cas de succès.  
- `NULL` en cas d'erreur lors de la création.

**Exemple d'utilisation :**  
```c
int ports[] = {80, 443};
char *container_id = create_conteneur("nginx:latest", ports, 2, "web_server");
```

---

### Fonction: start_conteneur

**Description :**  
Démarre un conteneur Docker en utilisant son identifiant unique.  
Envoie une requête POST à l'API Docker pour démarrer le conteneur et affiche un message d'erreur si la réponse en contient un.

**Paramètres :**  
- **id** : Identifiant unique du conteneur à démarrer.

**Retour :**  
- `true` si le conteneur démarre avec succès.  
- `false` si le démarrage échoue ou si une erreur est détectée.

**Exemple d'utilisation :**  
```c
bool success = start_conteneur("container123");
```

---

### Fonction: stop_conteneur

**Description :**  
Arrête un conteneur Docker en cours d'exécution spécifié par son identifiant.  
Elle envoie une requête POST à l'API Docker et affiche un message d'erreur si nécessaire.

**Paramètres :**  
- **id** : Identifiant unique du conteneur à arrêter.

**Retour :**  
- `true` si l'arrêt du conteneur est réussi.  
- `false` en cas d'erreur lors de l'opération.

**Exemple d'utilisation :**  
```c
bool stopped = stop_conteneur("container123");
```

---

## 3. Fichier: docker_image.c

### Fonction: pull_image

**Description :**  
Télécharge une image Docker depuis le dépôt officiel.  
Elle envoie une requête POST à l'API Docker avec le nom de l'image en paramètre de la requête.  
En cas d'erreur (détectée par la présence du mot "error" dans la réponse), l'erreur est affichée.

**Paramètres :**  
- **image** : Chaîne de caractères représentant le nom de l'image Docker à télécharger.

**Retour :**  
- `true` si l'image est téléchargée avec succès.  
- `false` en cas d'erreur ou si la réponse est invalide.

**Exemple d'utilisation :**  
```c
bool pulled = pull_image("ubuntu:latest");
```
