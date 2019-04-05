# Labyrinth
## Les	écarts
Néant.

## Bogues connus
Néant.

## Les problèmes rencontrés	et les solutions apportées
### Rotation des MazeCards
#### Problème
Les maze cards doivent pouvoir être tourner. Il faut donc représenter l'orientation des maze cards. Par exemple, pour une carte couloir de type T, on doit pouvoir représenter ses trois directions.

#### Solution
Pour repésenter l'orientation d'une maze card, on utilise l'énumération Shape. Elle fonctionne en utilisant quatre flags qui représente chacun une direction. Ainsi pour la rotation un shift ciruclaire des bits vers la gauche permet une rotation de 90 degrés.

### Implémentation du labyrinthe (```class Maze```)
#### Insertion de carte dans le labyrinthe
##### Problème
Notre implémentation doit permettre aux joueurs d'insérer les cartes couloirs dans le labyrinthe.

##### Solution
Nous avons decidé de représenté le labyrinth par un tableau à deux dimensions de MazeCard. Cette implémentation nous permet de facilement insérer les cartes couloirs sur les extrêmitées du labyrinth: il nous suffit de sauvegarder la carte éjectée, décaller l'ensemble des cartes sur la rangée/ colonne et d'insérer la carte courante.

#### Représentation des liens entre les couloirs
##### Problème
Le jeu doit être capable d'indiquer si un chemin existe d'une position à une autre afin de restreindre le joueur aux chemins qui lui sont accèssibles.

##### Solution
Nous avons représenter les relations des différents couloir par un graphe de positions. Chaque position correspond à une case du tableau à deux dimensions utilisé pour représenter le labyrinthe. Nous avons implémenté le graphe par une map de clé de type ```MazePosition``` et de valeur de type ```std::vector<MazePosition>```. Nous associons une position à l'ensemble de ses voisins.

#### Déplacement des joueurs lors du déplacement des couloirs
##### Problème
Lorsqu'un joueur insère une carte dans le labyrinthe, une ligne ou une colonne est décallée et une carte ejéctée. Lors de cette insertion, si des joueurs se trouve sur la ligne ou la colonne concernée, ils doivent suivrent le mouvement de la carte couloir sur laquelle ils se trouvent.

##### Solution
Lors de l'insertion d'une carte dans le labyrinthe, pour tous les joueurs qui se trouve sur la ligne/ colonne nous décallons leur position en suivant celle de leur carte.

## Une estimation du temps	
- Vendredi 22 février 2019 de 12h00 à 20h00: *début d'implémentation du modèle - Les classes Player et MazeCard sont implémentées et partiellement testée.*
- Samedi 23 février 2019 de 18h00 à 19h00: *ajout de la classe MazeCardShape et test unitaire.*