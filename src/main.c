/*
** main.c for generator in /root/Delivery/IA/dante/generator
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Thu Sep 14 15:37:16 2017 root
** Last update Tue Oct  3 14:12:28 2017 root
*/

#include "my.h"

int		perfect_maze(char **av, char c)
{
  t_maze	*maze;

  if ((maze = malloc(sizeof(*maze))) == NULL)
    return (84);
  maze->width = atoi(av[1]);
  maze->height = atoi(av[2]);
  if (create_tab(maze) != 0)
    return (84);
  fill_tab(maze);
  depth_first(maze);
  if (c == 'i')
    break_walls(maze, 40);
  show_tab(maze);
  free_maze(maze);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac == 3 && verif_char(av) == 0)
    {
      if (perfect_maze(av, 'i') != 0)
	return (84);
    }
  else if (ac == 4 && verif_char(av) == 0)
    {
      if (perfect_maze(av, 'p') != 0)
	return (84);
    }
  else
    my_putstr(ARG_ERROR);
  return (0);
}
