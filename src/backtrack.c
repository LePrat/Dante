/*
** backtrack.c for generator in /root/Delivery/IA/dante/generator/src
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Sun Sep 24 17:01:51 2017 root
** Last update Wed Oct  4 16:36:10 2017 root
*/

#include "my.h"

void		backtrack(t_list *list, int *i, int *j)
{
  t_element	*to_free;

  if (list->first != NULL)
    {
      to_free = list->first;
      *i = list->first->i;
      *j = list->first->j;
      list->first = list->first->next;
      free(to_free);
    }
}

int	*epur_int(int *coord, int coord_len)
{
  int	*epur_coord;
  int	k;
  int	l;

  k = 0;
  l = 0;
  if ((epur_coord = malloc(sizeof(int) * (coord_len + 1))) == NULL)
    return (NULL);
  while (coord[k])
    {
      if (coord[k] != -1)
	{
	  epur_coord[l] = coord[k];
	  ++l;
	}
      ++k;
    }
  epur_coord[l] = '\0';
  return (epur_coord);
}

void	exit_maze(t_maze *maze)
{
  if (maze->tab[maze->height - 1][maze->width - 1].c != C_BOX)
    {
      maze->tab[maze->height - 1][maze->width - 1].c = C_BOX;
      if (maze->width != 1)
	{
	  if (maze->tab[maze->height - 1][maze->width - 2].c != C_BOX)
	    maze->tab[maze->height - 2][maze->width - 1].c = C_BOX;
	  else
	    maze->tab[maze->height - 1][maze->width - 2].c = C_BOX;
	}
    }
}

void	rand_coord_tree(t_maze *maze, t_list *list, int *i, int *j)
{
  if (maze->rand_nb == 1)
    {
      insert_first(list, *i, *j);
      maze->tab[*i - 1][*j].c = C_BOX;
      *i = *i - 2;
    }
  else if (maze->rand_nb == 2)
    {
      insert_first(list, *i, *j);
      maze->tab[*i][*j + 1].c = C_BOX;
      *j = *j + 2;
    }
  else if (maze->rand_nb == 3)
    {
      insert_first(list, *i, *j);
      maze->tab[*i + 1][*j].c = C_BOX;
      *i = *i + 2;
    }
  else
    {
      insert_first(list, *i, *j);
      maze->tab[*i][*j - 1].c = C_BOX;
      *j = *j - 2;
    }
}
