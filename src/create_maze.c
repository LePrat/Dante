/*
** create_maze.c for generator in /root/Delivery/IA/dante/generator/src
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Sat Sep 23 16:39:21 2017 root
** Last update Wed Sep 27 22:23:04 2017 root
*/

#include <time.h>
#include "my.h"

int	random_between(int min, int max)
{
  return (rand() % (max - min + 1) + min);
}

int	*count_unvisited_box(t_maze *maze, int i, int j)
{
  int	*coord;

  if ((coord = malloc(sizeof(int) * (4 + 1))) == NULL)
    return (NULL);
  coord[0] = (i > 0 && maze->tab[i - 2][j].v == 0) ? 1 : -1;
  coord[1] = (j < maze->width - 2 && maze->tab[i][j + 2].v == 0) ? 2 : -1;
  coord[2] = (i < maze->height - 2 && maze->tab[i + 2][j].v == 0) ? 3 : -1;
  coord[3] = (j > 0 && maze->tab[i][j - 2].v == 0) ? 4 : -1;
  coord[4] = '\0';
  return (coord);
}

int	select_rand_box(t_maze *maze, int i, int j)
{
  int	*coord;
  int	*epur_coord;
  int	coord_len;
  int	rand_array;
  int	rand_nb;

  coord = count_unvisited_box(maze, i, j);
  coord_len = my_inttablen(coord);
  epur_coord = epur_int(coord, coord_len);
  free(coord);
  if (coord_len == 0)
    {
      free(epur_coord);
      return (0);
    }
  rand_array = random_between(0, coord_len - 1);
  rand_nb = epur_coord[rand_array];
  free(epur_coord);
  return (rand_nb);
}

int	random_coord(t_maze *maze, t_list *list, int *i, int *j)
{
  maze->tab[*i][*j].v = 1;
  if ((maze->rand_nb = select_rand_box(maze, *i, *j)) == 0)
    return (1);
  rand_coord_tree(maze, list, i, j);
  return (0);
}

int		depth_first(t_maze *maze)
{
  int		i;
  int		j;
  t_list	*list;
  int		c;

  i = 0;
  j = 0;
  c = 0;
  list = initialize();
  list->first->i = 0;
  list->first->j = 0;
  srand(time(NULL));
  while (list_len(list) > 3 || c < 2)
    {
      while (random_coord(maze, list, &i, &j) != 1);
      backtrack(list, &i, &j);
      ++c;
    }
  exit_maze(maze);
  free_list(list);
  free(list);
  return (0);
}
