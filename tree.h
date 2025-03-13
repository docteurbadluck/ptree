/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:09:30 by tdeliot           #+#    #+#             */
/*   Updated: 2025/03/13 15:13:19 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"

typedef struct s_tree
{
	char			*name;
	int				pid;
	int				ppid;
	int				already_print;
	struct s_tree	*children[10000]; 
}		t_tree;

DIR		*open_directory(void);
char	*path_generator(char *entry_name);
int		print_info(char *path_to_status);
int		only_number(char *arg);
t_tree	*get_info(void);
void	init_list(t_list **first);
void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size);
void	free_list(void *content);
void	who_is_my_sons(t_list *first);
void	print_tree(t_tree *content, int i, int indent_lvl);
void	print_tree_list(t_list *first);

#endif