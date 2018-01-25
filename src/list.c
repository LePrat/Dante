/*
** list.c for generator in /root/Delivery/IA/dante/generator/src/lists
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Sat Sep 23 17:31:17 2017 root
** Last update Wed Sep 27 21:48:54 2017 root
*/

#include <stdio.h>
#include "my.h"

t_list		*initialize()
{
  t_list	*list;
  t_element	*element;

  if ((list = malloc(sizeof(*list))) == NULL)
    return (NULL);
  if ((element = malloc(sizeof(*element))) == NULL)
    return (NULL);
  element->next = NULL;
  list->first = element;
  return (list);
}

void		insert_first(t_list *list, int i, int j)
{
  t_element	*new_elem;

  if ((new_elem = malloc(sizeof(*new_elem))) == NULL)
    exit(84);
  new_elem->i = i;
  new_elem->j = j;
  new_elem->next = list->first;
  list->first = new_elem;
}

void		list_display(t_list *list)
{
  t_element	*actual;

  actual = list->first;
  while (actual != NULL)
    {
      printf("i = %d, j = %d\n", actual->i, actual->j);
      actual = actual->next;
    }
}

int		list_len(t_list *list)
{
  t_element	*actual;
  int		i;

  i = 0;
  actual = list->first;
  while (actual != NULL)
    {
      actual = actual->next;
      ++i;
    }
  return (i);
}

void		free_list(t_list *list)
{
  t_element	*actual;
  t_element	*prev;

  actual = list->first;
  while (actual != NULL)
    {
      prev = actual;
      actual = actual->next;
      free(prev);
    }
  free(actual);
}
