/*
** intlen.c for generator in /root/Delivery/IA/dante/generator/src/utils
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Sat Sep 23 22:47:44 2017 root
** Last update Sat Sep 23 22:50:15 2017 root
*/

#include "my.h"

int	my_inttablen(int *tab)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (tab[i])
    {
      if (tab[i] != -1)
	++j;
      ++i;
    }
  return (j);
}
