/*
** my.h for generator in /root/Delivery/IA/dante/generator
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Sat Sep 23 17:29:07 2017 root
** Last update Mon Oct  2 00:37:16 2017 root
*/

#ifndef MY_H_
# define MY_H_

# include <unistd.h>
# include <stdlib.h>

# define ARG_ERROR "Error of argument, the input must be \"./generator $width $height\"\n"
# define C_BOX '*'

typedef struct	s_box
{
  char		c;
  int		v;
}		t_box;

typedef struct	s_maze
{
  int		width;
  int		height;
  int		rand_nb;
  t_box		**tab;
}		t_maze;

typedef struct		s_element
{
  int			i;
  int			j;
  struct s_element	*next;
}			t_element;

typedef struct	s_list
{
  t_element	*first;
}		t_list;

int	my_strlen(char *);
int	my_tablen(char **);
void	my_putstr(char *);
void	show_tab(t_maze *);
char	*my_strcpy(char *, char *);
int	my_inttablen(int *);

int	create_tab(t_maze *);
void	fill_tab(t_maze *);
void	free_maze(t_maze *);
int	depth_first(t_maze *);
void	backtrack(t_list *, int *, int *);
void	exit_maze(t_maze *);
void	rand_coord_tree(t_maze *, t_list *, int *, int *);
void	break_walls(t_maze *, int);

t_list	*initialize();
void	insert_first(t_list *, int, int);
void	list_display(t_list *);
int	list_len(t_list *);
void	free_list(t_list *);
int	*epur_int(int *, int);

int	verif_char(char **);

#endif /*MY_H_*/
