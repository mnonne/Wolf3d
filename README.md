# Wolf3d
This is a simple ray-casting pseudo 3d game engine like worldwide famous "Wolfenstein 3d" written in C.
Video link: https://www.youtube.com/watch?v=K2ZPBAwb63Q

Runs on MacOS X using minilibix library.

Usage:
./wolf3d [path to map file]

Example of map file:

1 1 1 1 1 1 1
1 0 0 0 3 3 1
1 0 0 p 3 0 1
1 0 0 1 3 0 1
1 0 0 3 0 0 1
1 0 0 2 0 0 1
1 1 1 1 1 1 1

Legend:
1 - wall, 2 - obstacle with collision, 3 - obstacle without collision, p - player character

Game controls:
WASD - move character
Arrows left and right - turn around
Spb - shoot
LShift - run
Tab - show minimap.
