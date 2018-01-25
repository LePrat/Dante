/*
** create_tab.c for dante in /root/Delivery/IA/dante/generator/src
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Fri Sep 22 18:04:15 2017 root
** Last update Tue Sep 26 13:59:35 2017 root
*/

#include "my.h"

int		create_tab(t_maze *maze)
{
  int		i;
  t_box		**tab;

  i = 0;
  if ((tab = malloc(sizeof(t_box *) * (maze->height + 1))) == NULL)
    return (84);
  while (i < maze->height)
    {
      if ((tab[i] = malloc(sizeof(t_box) * (maze->width + 1))) == NULL)
	return (84);
      ++i;
    }
  maze->tab = tab;
  return (0);
}

void	fill_tab(t_maze *maze)
{
  int	i;
  int	j;
  char	c;

  i = 0;
  c = C_BOX;
  while (i < maze->height)
    {
      j = 0;
      while (j < maze->width)
	{
	  if (i % 2 == 0)
	    maze->tab[i][j].c = (j % 2 == 0) ? c : 'X';
	  else
	    maze->tab[i][j].c = 'X';
	  maze->tab[i][j].v = 0;
	  ++j;
	}
      maze->tab[i][j].c = '\0';
      ++i;
    }
  maze->tab[i] = '\0';
}

void	free_maze(t_maze *maze)
{
  int	i;

  i = 0;
  while (maze->tab[i])
    {
      free(maze->tab[i]);
      ++i;
    }
  free(maze->tab);
  free(maze);
}
