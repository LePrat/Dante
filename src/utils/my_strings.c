/*
** my_strlen.c for mysh2 in /root/Delivery/Prog_Shell/PSU_2016_minishell2/src/utils
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Mon Aug 21 16:32:15 2017 root
** Last update Tue Oct  3 14:15:02 2017 root
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

char	*my_strcpy(char *src, char *dest)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}

void	show_tab(t_maze *maze)
{
  int	i;
  int	j;

  i = 0;
  while (maze->tab[i])
    {
      j = 0;
      while (j < maze->width)
	{
	  write(1, &maze->tab[i][j].c, 1);
	  ++j;
	}
      if (i != maze->height - 1)
	my_putstr("\n");
      ++i;
    }
}
