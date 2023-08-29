#


# Projet Logiciel Transversal - HIVE

[![Actions Status](https://github.com/cbares/plt/workflows/PLT%20build/badge.svg)](https://github.com/AliZhr/plt/actions)

> The goal of this project is to realize the bord game "Hive" with C++

<p align="center">
  <img src="rapport/image/Aspose.Words.d663220b-ca81-4584-8c4f-95488ddd0e67.001.jpeg">
</p>

## The team

[Ali ZOUHAIRI](https://github.com/AliZhr)

[Lavan SRISKANDARAJAH](https://github.com/Senakyw)

[Royston WINSON AROKIARAJAH](https://github.com/RoyWinson)

# Get Started

## Install dependencies

```sh
$ apt-get update
$ apt-get install -y build-essential cmake dia lcov gcovr libxml2-dev libsfml-dev libboost-test-dev libmicrohttpd-dev
```


## Clone the repository
```sh 
$ git clone https://github.com/AliZhr/plt
```

## Build
```sh
$ cd plt
$ mkdir build
$ cd build
$ cmake .. && make -j
```
## Hello World
```sh
$ ./bin/client hello
```

## Game render
```sh
$ ./bin/client render
```

## Engine - 1v1
```sh
$ ./bin/client engine
```

## Play vs random Ai without render
```sh
$ ./bin/client ai
```

## Play vs random AI with render
```sh
$ ./bin/client engine_ai
```

## Play vs Heuristic AI
```sh
$ ./bin/client engine_heur
```

## Random AI vs Heuristic AI
```sh
$ ./bin/client randomvsheur
```

## Heuristic AI vs Heuristic AI
```sh
$ ./bin/client heurvsheur
```

## Server test
```sh
$ ./bin/server
```
Client :

>POST : 

>http://localhost:8080/create-game -d hostPlayerName | will return a key for a game state

>       http://localhost:8080/create-game -d key, playerName | return succes if's ok

>GET :  

>http://localhost:8080/key | return the last key

>       http://localhost:8080/game -d key | will return some data about the state mapped with the key


# Table des matières

[**1 Objectif**](#_5vqim4b4dbvt)

[1.1 Présentation générale](#_mtmhau3gsmsu)	

[1.2 Règles du jeu](#_q837fg47fu16)	

[1.3 Conception Logiciel](#_fgoa6p6aam9g)	


[**2 Description et conception des états**](#_5vqim4b4dbvt)

[2.1 Description des états](#_mtmhau3gsmsu)	

[2.2. Conception logiciel](#_q837fg47fu16)	

# **1 Objectif**
## **1.1 – Présentation générale**
Le but de ce projet est de réaliser le jeu de plateau et de stratégie  “HIVE”.
## **1.2 – Règles du jeu**

Hive est un jeu de stratégie sur plateau à cases hexagonales où 2 adversaires s’affrontent. Chaque joueur possède 13 pions qui ont leurs propres caractéristiques. Le but du jeu étant d’encercler la **Reine Abeille** adverse.

Il y a différents pions et chacun d’entre eux peut se mouvoir selon des règles spécifiques. Voici la liste de tous les pions et de leur caractéristique:

-Reine Abeille : elle se déplace d’un espace à la fois et doit être placée avant le cinquième tour (exclu).

-L’Araignée : elle se déplace de trois espaces.

-La Fourmi : elle se déplace d’autant d’espaces que le joueur le désire mais doit obligatoirement être voisine d’un autre pion.

-Grillon : il se déplace en sautant en ligne droite par-dessus d’une ou plusieurs autres pièces, jusqu’au premier espace libre. Elle se déplace dans la direction d’un de ses côtés, et non vers ses angles.

-Le Scarabée : il se déplace d’un espace à la fois, comme la reine, mais il a la capacité de « grimper » sur les autres pièces.

-Le Moustique : il  prend le mode de déplacement de la ou des pièces adjacentes.

-La Coccinelle : elle se déplace de trois espaces à chaque tour, mais doit obligatoirement effectuer ses deux premiers déplacements en montant au-dessus des autres pièces (comme le scarabée) puis redescendre au sol lors de son troisième déplacement.

De plus, chaque pion doit obligatoirement être lié à au moins un autre : de sorte à ce qu’on ait un seul groupe d’insectes collés aux autres. On négligera la règle de liberté de mouvement.




## **1.3 – Conception Logiciel**



Voici les textures de tous les pions pour chaque joueurs:










<img src="rapport/image/Capturedécran 2022-10-23 140325.png">









Figure 1 : Représentation des pions




















## **2 – Description et conception des états**
**2.1 Description des états**

Une partie est composée de 2 joueurs chacun ayant 11 pions. L’état du jeu dépend du nombre de tours et des pions placés sur un plateau. 

Jeu :

Le jeu se déroule en plusieurs étapes. Les joueurs ont 4 tours pour placer leur pions “abeille” . Dès qu’un joueur a posé ce pion, il aura la possibilité,selon les règles, de déplacer ses pions déjà placés. Lorsqu’une des abeilles est encerclée la partie est terminée et le joueur ayant son abeille pas encerclée a gagné. 

Joueur :

Nous avons 2 joueurs. Chaque joueur à une liste de pions placés et de pions non placés.

La couleur des pions désigne le joueur qui va commencer en premier. 

Plateau :

Le plateau avec une grille hexagonale sera représenté par un tableau en 2 dimensions. Chaque case du plateau a donc une coordonnée et un état occupé ou non.

Lorsqu’un pion est placé sur une des cases, la case est alors occupée.

Insectes :

Nous avons donc au total 22  pions/insectes. Ils seront différenciés pour chaque joueur à l’aide de leur couleur. Un insecte a une position, c’est à dire ici une coordonnée sur le plateau s’il est placé ou bien “NULL” s’il ne l’est pas.


Les différents états du jeu seront :

- Player\_X\_playing : lorsque c’est le tour d’un des joueur
- Player\_X\_won : lorsque la partie est terminée, ce qui signifie qu’une des abeilles a été encerclée.













**2.2. Conception logiciel**

Après avoir décrit les différents états, nous allons aborder le diagramme de classe présenté en figure 2. On peut alors décrire plus précisément les classes que nous avons instauré pour le jeu et voir les attributs et méthodes qu’elles contiennent.

- Classe **Jeu :** 

<img src="rapport/image/Aspose.Words.d663220b-ca81-4584-8c4f-95488ddd0e67.016.png">















Cette classe permet de suivre l’état du jeu. Il est composé d’un attribut GameStatus qui renvoie l’état du jeu, d’un objet Plateau. On ajoute également le nombre de tours de type entier. On inclut la liste de tous les insectes dans le jeu avec ListAllInsect de type liste, cette liste nous permettra par la suite de récupérer la position des insectes sur le plateau. C’est dans cette classe qu’on met à jour l’état du jeu, et qu’on vérifie si une des abeilles est encerclée ou non.









- Classe **Plateau :**

Dans cette classe on pourra générer un tableau avec les dimensions souhaitées. L’attribut ListeCoordonnees sera donc rempli à l’aide du constructeur. Chaque  espace du tableau aura un objet Case associé. Chaque objet Case aura une coordonnée et un attribut “occupe”.

<img src="rapport/image/Aspose.Words.d663220b-ca81-4584-8c4f-95488ddd0e67.017.png">



















- Classe **Insect :**

C’est une classe ayant une méthode abstraite, chaque insecte aura un nom, une couleur, une position et un niveau (étage pour le scarabée qui peut rester sur une pièce).

Les classes qui héritent de cette classe devront overrider la méthode permettant de déplacer le pion selon l'insecte.

<img src="rapport/image/Aspose.Words.d663220b-ca81-4584-8c4f-95488ddd0e67.018.png">








- Classe **Joueur :**

C’est dans cette classe qu’on la couleur des pions du joueur et les différentes listes des pions. C’est à partir de ces listes que l’on va déplacer/placer les pions.


<img src="rapport/image/Aspose.Words.d663220b-ca81-4584-8c4f-95488ddd0e67.019.png">




Diagramme des classes d’état : 

<img src="rapport/image/Aspose.Words.d663220b-ca81-4584-8c4f-95488ddd0e67.020.png">
` `

Projet Logiciel Transversal – Ali ZOUHAIRI – Lavan SRISKANDARAJAH – Royston WINSON AROKIARAJAH
