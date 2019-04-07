# Labyrinth
Assignment submitted by Anthony (49737) and Logan Farci (47923) to Mr Beleho (BEJ).

## How to install
1. ```cd <path to folder>/DEV4_Labyrinth```: go to the folder of the project you just downloaded.
2. ```qmake Labyrinth.pro```: generate the make file.
3. ```make```: build the project.

## How to play 
### Start a game
1. ```cd <path to folder>/DEV4_Labyrinth```: be sure to be in the project folder.
2. ```./build/labyrinth <number of players> [simplfied]```: run the project with the options of your choice.

#### Command line arguments
- **number of players:** is the number of players taking part to the game.
- **simplified:** when set, the game does not require a player that has found all of his objectives to return to his initial position.

### Commands
- ```help```: prints the list of commands.
- ```move <row> <column>```: moves the current player to the given row and column. The current player should have inserted the maze card before moving his piece.
- ```pass```: pass the current player move.
- ```insert <row> <column>```: inserts the current maze card at the given row and column.
- ```rotate <n>```: rotates the current maze card n times (n is an unsigned between 1 and 10).
- ```show players```: shows the list of the players of the game.
- ```show mazecard```: shows the current maze card (to one about to be inserted).
- ```show objectives```: shows the list of objectives and their positions in the maze.
- ```show objective```: shows the current objective.
- ```exit```: exits the game.