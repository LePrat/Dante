/*
** arg.c for dante in /root/Delivery/IA/dante/generator/src/verifs
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Fri Sep 22 23:05:44 2017 root
** Last update Tue Sep 26 17:03:42 2017 root
*/

#include "my.h"

int	verif_char(char **av)
{
  if (atoi(av[1]) <= 0 || atoi(av[2]) <= 0)
    return (84);
  return (0);
}
