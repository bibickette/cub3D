🇬🇧 English version available [here](README.md)
* * *
# Présentation du projet `cub3D`
**Introduction**

*Ce projet a été réalisé en **binôme avec [Naphiye](https://github.com/Naphiye)***

## Description

Ce projet est un **projet graphique 3D** inspiré du jeu classique *Wolfenstein 3D*.
L’objectif est de créer un **rendu 3D en vue à la première personne** à l’aide du **raycasting**, permettant au joueur de se déplacer librement dans un labyrinthe rendu en temps réel.

Ce projet introduit des concepts fondamentaux de **programmation graphique**, de **géométrie** et de **gestion des événements**, en utilisant la bibliothèque graphique **MiniLibX**.

Le projet comprend :
- L’implémentation d’un moteur de raycasting depuis zéro
- Le rendu d’un environnement 3D à partir d’une carte 2D
- La gestion des déplacements du joueur et de la rotation de la caméra
- La gestion des textures, des couleurs et des collisions
- Le parsing et la validation des fichiers de configuration
- La création d’une expérience graphique fluide et réactive

![Gameplay](textures/gif/gameplay.gif)

* * *
## Langages & Technologies

**Langage**
- C (standard C99)

**Technologies**
- Makefile
- MiniLibX
- Algorithmes de raycasting
- Trigonométrie
- Gestion des événements
- Gestion dynamique de la mémoire

* * *
## Règles du jeu

L’exécutable `cub3D` prend unique argument : une carte au format `.cub`.

### Déplacements du joueur

| Touche |             Action             |
|:------:|:------------------------------:|
|   W    |            Avancer             |
|   S    |            Reculer             |
|   A    |         Aller à gauche         |
|   D    |         Aller à droite         |
| ← / →  |     Rotation de la caméra      |
|  ESC   |      Quitter le programme      |
|   E    | Ouvrir / fermer portes (bonus) |

### Gameplay
`cub3D` n’est pas un jeu traditionnel avec des conditions de victoire ou de défaite. Son objectif est de démontrer un moteur de **rendu 3D en temps réel**, permettant au joueur d’explorer librement un labyrinthe en vue subjective.

Le joueur peut se déplacer dans l’environnement, observer les textures des murs, interagir avec des portes (bonus) et profiter d’une rotation fluide de la caméra ainsi que d’une gestion des collisions.

Le programme peut être fermé en cliquant sur la croix de la fenêtre ou en appuyant sur `Échap`.

### Règles de la carte

La carte doit respecter les règles suivantes :
- Chemins vers les textures des murs (NO, SO, WE, EA)
- Couleurs du sol et du plafond
- Carte valide (fermée et entourée de murs)
- Position initiale et orientation du joueur

Caractères autorisés :
- **N**, **W**, **S**, **E** (*joueur et orientation*)
- **1** (*mur*)
- **0** (*espace vide*)
- **D** (*porte - **bonus** uniquement*)

*Exemple :*
```
NO ./textures/wall_north.xpm
SO ./textures/wall_south.xpm
WE ./textures/wall_west.xpm
EA ./textures/wall_east.xpm

F 220,100,0
C 225,30,0

111111
100001
101101
1000N1
111111
```

* * *
## Bonus

La version bonus inclut :
- Gestion des collisions avec les murs
- Minimap
- Sprites animés
- Portes ouvrables et fermables

L’exécutable bonus est nommé `./cub3D_bonus`.

![hearts](textures/gif/animation_sprites.gif)
![map](textures/gif/map.gif)
![door](textures/gif/door.gif)

* * *
## Ressources & Crédits

- Les sprites proviennent d’un **[pack de ressources Minecraft](https://www.minecraft-france.fr/resources-pack/textures-256x256/)**.
- Toute l’édition d’images, la composition et le montage ont été réalisés par **moi-même**

*Ce projet est strictement à des fins éducatives et non commerciales.*

* * *
# Utilisation de `cub3D`

## **Règles du Makefile**
1. **all** comme *règle par défaut* : compile le projet, transforme tous les fichiers `.c` en `.o` et **construit** le programme  (`cub3D`)
2. **clean** : supprime les fichiers objets compilés (`.o`)
3. **fclean** : exécute la règle *clean* et supprime l'éxecutable (`cub3D`)
4. **re** : exécute *fclean* puis *all*
5. **bonus** : compile le projet avec les fonctionnalités bonus activées
6. **rebonus** : exécute *fclean* puis *bonus*


* * *

## **Comment utiliser `cub3D`**
*Note : le projet `cub3D` fonctionne de manière autonome et utilise les bibliothèques [libft](https://github.com/bibickette/libft) et [minilibx-linux](https://github.com/42Paris/minilibx-linux). Celles-ci étant ajoutées comme sous-modules, il est nécessaire de cloner le dépôt avec.*
1. Clonez `cub3D` dans un dossier : `git clone --recurse-submodules https://github.com/bibickette/cub3D.git`
2. Accédez au dossier `cub3D` et compilez le projet : `cd cub3D && make`
3. Lancer le jeu avec une carte : `./cub3D maps/tuto_map.cub`. *Le dossier `maps/` contient des cartes pouvant être utilisées*

Vous pouvez maintenant tester mon jeu `cub3D` !

* * *

*Date de validation du projet : 30 janvier 2025*