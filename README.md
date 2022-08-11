# Cub3d
Mon premier RayCaster avec la minilibX.
## Table of Contents
1. [Summary](#Raycasting)
2. [Raycasting](#netmask)
3. [Resources](#Sitographie)


  
## Summary
 > Ce projet est inspiré du jeu Wolfeinstein3D, considéré comme le premier FPS
jamais développé. Il vous permettra d’explorer la technique du ray-casting. Votre objectif
est de faire une ```vue dynamique et subjective``` au sein d’un labyrinthe, dans lequel vous devrez trouver
votre chemin.

<details>
    <summary>Rules</summary>  
  
 - [x] Couleurs différentes pour le sol et le plafond.
 - [x] Le programme affiche l’image dans une fenêtre et respecte les règles suivantes :  
    - [x] Flèches du gauche et droite du clavier pour la rotation de caméra
    - [x] ```W, A, S et D``` pour se déplacer  
    - [x] ESC et la croix rouge doivent fermer la fenêtre et quitter le programme proprement  
    - [x] utilisation d’```images de la minilibX``` (= recoder my_put_pixel)
 - [x] Votre programme doit prendre en premier argument un fichier de description avec extension .cub
    - [x] La map est composée d’uniquement: ```0 pour les espaces vides, 1 pour les murs, et N,S,E ou W qui indique la position de départ
du joueur et son orientation.```
    - [x] La map doit être fermée/entourée de murs, sinon renvoyer une erreur.
    - [x] Mis à part la description de la map, chaque type d’élément peut être séparée
par une ou plusieurs lignes vides.
    - [x] La description de la carte sera toujours en dernier dans le fichier, le reste des
éléments peut être dans n’importe quel ordre.
    - [x] Sauf pour la map elle-même, les informations de chaque élément peuvent être
séparées par un ou plusieurs espace(s).
    - [x] Le premier caractère est l’identifiant, suivi de toutes les informations spécifiques à l’élément dans un ordre:   
           -  ```NO ./path_to_the_texture``` (same pour SO WE EA)  
           -  ```F 0,255,255 (R,G,B)``` (same pour C)  
  -> renvoyer ```"Error\n"``` sinon
        

</details>

#### Bonus
- [x] ombres
- [x] textures FLOOR and CEILING
- [x] colisions
- [x] armes avec recul et munitions
- [x] bruitages / musique



## Raycasting 

> Ray casting is capable of ```transforming a limited form of data into a three-dimensional projection``` with the help of ```tracing rays from the view point``` into the viewing volume. 
> The main principle behind ray casting is that rays can be cast and traced in groups based
>  on certain geometric constraints.  
> The first game built on a ray casting engine to achieve massive success was Wolfenstein 3D, which was released on May 5, 1992.  
> Modern video games have advanced significantly, with faster CPUs, more memory, and the availability of GPUs to accelerate the computation of 3D graphics. 
> However, most modern video game 3D engines still use an advanced form of ray casting,
> because it ```remains the most efficient method to render a 3D image```.
<details>
    <summary>Schéma</summary>  
  
 ![image](https://user-images.githubusercontent.com/85625233/174494615-ce9ef8f3-6858-47d3-8c08-7ff33cb50ff6.png)
 ![image](https://user-images.githubusercontent.com/85625233/174496417-18539e8c-364f-4c3e-b418-6e8446d6c98e.png)
  ![image](https://user-images.githubusercontent.com/85625233/174496873-7cc5d1cf-2ef3-45ee-801b-a06e0b777bc2.png)


  > In CGI (computer-generated imagery), ray casting ```is the most basic form of raytracing```. 
  Unlike other forms of ray tracing, where rays originate from a light source and bounce 
  off objects to arrive at the observer, in ray casting, they're ```"cast" directly from the viewpoint```. 
  When cast rays ```intersect an object```, the object's color and brightness at ```that point determines the value of one pixel in the final image```.
  A ```direction vector``` represents the orientation of the observer extending forward. A ```camera plan```perpendicular to the direction vector,
  representing the shape of the final rendered image, is also required in most types of ray casting.
</details>
 
## Final result
  
<img src="https://user-images.githubusercontent.com/85625233/184053891-376e6b61-5319-4a0c-a7d0-cf53d026dcc9.gif" width="600" height="400"/>
<img src="https://user-images.githubusercontent.com/85625233/184053924-2359497a-05e8-4735-9366-8fb0dd9cfd07.gif" width="600" height="400"/>

## Sitographie!
* ![Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)
* ![Youtube raycasting tutorial](https://www.youtube.com/watch?v=gYRrGTC7GtA)
* ![Explanations of raycasting](https://www.youtube.com/watch?v=js7HW65MmNw&list=PL0H9-oZl_QOHM34HvD3DiGmwmj5X7GvTW)
* ![Other tutorial](https://permadi.com/1996/05/ray-casting-tutorial-1/#A%20BRIEF%20HISTORY)


## 42 Project 121/100

Réalisé avec Lee Francesco
