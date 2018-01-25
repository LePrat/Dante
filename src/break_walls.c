/*
** break_walls.c for dante in /root/Delivery/IA/dante/generator/src
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Thu Sep 28 16:07:34 2017 root
** Last update Mon Oct  2 00:27:26 2017 root
*/

#include "time.h"
#include "my.h"

int	count_wall(t_maze *maze)
{
  int	i;
  int	j;
  int	nb_wall;

  i = 0;
  nb_wall = 0;
  while (maze->tab[i])
    {
      j = 0;
      while (j < maze->width)
	{
	  if (maze->tab[i][j].c == 'X')
	    ++nb_wall;
	  ++j;
	}
      ++i;
    }
  return (nb_wall);
}

int	**create_wall_tab(t_maze *maze)
{
  int	**wall_tab;
  int	i;

  i = 0;
  if ((wall_tab = malloc(sizeof(int *) * (count_wall(maze) + 1))) == NULL)
    return (NULL);
  while (i < count_wall(maze))
    {
      if ((wall_tab[i] = malloc(sizeof(int) * 3)) == NULL)
	return (NULL);
      ++i;
    }
  wall_tab[i] = '\0';
  return (wall_tab);
}

int	**fill_wall_tab(t_maze *maze, int **wall_tab)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  k = 0;
  while (maze->tab[i])
    {
      j = 0;
      while (j < maze->width)
	{
	  if (maze->tab[i][j].c == 'X')
	    {
	      wall_tab[k][0] = i;
	      wall_tab[k][1] = j;
	      wall_tab[k][2] = '\0';
	      ++k;
	    }
	  ++j;
	}
      ++i;
    }
  wall_tab[k] = '\0';
  return (wall_tab);
}

void	free_int_tab(int **wall_tab)
{
  int	i;

  i = 0;
  while (wall_tab[i])
    {
      free(wall_tab[i]);
      ++i;
    }
  free(wall_tab);
}

void	break_walls(t_maze *maze, int p)
{
  int	**wall_tab;
  int	to_break;
  int	i;
  int	rand_wall;
  int	nb_wall;

  i = 0;
  srand(time(NULL));
  wall_tab = create_wall_tab(maze);
  wall_tab = fill_wall_tab(maze, wall_tab);
  nb_wall = count_wall(maze);
  to_break = nb_wall * p / 100;
  while (i < to_break)
    {
      rand_wall = rand() % (nb_wall);
      maze->tab[wall_tab[rand_wall][0]][wall_tab[rand_wall][1]].c = C_BOX;
      ++i;
    }
  free_int_tab(wall_tab);
}
