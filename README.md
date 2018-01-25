# Dante

A C program that generates a maze randomly everytime it is launched.
* The 'X' character is a wall
* The '*' character is an empty case

To generate the maze :
```sh
$ make
$ ./generator $width $height $format
```

width(int)
height(int)
format(char) : 'p' for a perfect maze, 'i' for an imperfect maze

Example :
```sh
$ ./generator 50 31 p
```

It follows the previous norme of Epitech.