/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:09:33 by tdeliot           #+#    #+#             */
/*   Updated: 2025/03/13 15:26:43 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

// create a tree of process. The indent show the relation beetween the process
// usage cc tree.c tree_utils.c libft.a
int	main(void)
{
	t_list	*first;

	first = NULL;
	init_list(&first);
	who_is_my_sons(first);
	print_tree_list(first);
	ft_lstclear(&first, &free_list);
	return (0);
}

// open the directory in /proc/ enerate the path for each process
// print the infos in a temp.txt get the information 
// for each node and add the node to the list. 
void	init_list(t_list **first)
{
	DIR				*my_dir;
	struct dirent	*entry;
	t_tree			*new;
	char			*path;

	my_dir = open_directory();
	while ((entry = readdir(my_dir)) != NULL)
	{
		if (only_number(entry->d_name) == 0)
		{
			path = path_generator(entry->d_name);
			print_info(path);
			free(path);
			new = get_info();
			ft_lstadd_back(first, ft_lstnew(new));
		}
	}
	closedir(my_dir);
}

//look for each process which are his prossess children
// and add them into the children array. the array is nulterminated.
void	who_is_my_sons(t_list *first)
{
	t_list	*ptr;
	t_list	*iterator;
	t_tree	*content;
	t_tree	*content_it;
	int		i;

	ptr = first;
	while (ptr)
	{
		i = 0;
		content = ptr->content;
		content->children[i] = NULL;
		iterator = ptr->next;
		while (iterator)
		{
			content_it = iterator->content;
			if (content_it->ppid == content->pid)
			{
				content->children[i] = content_it;
				if (i < 9998)
				{
					i++;
					content->children[i] = NULL;
				}
			}
			iterator = iterator->next;
		}
		ptr = ptr->next;
	}
}

//pass by all the list to print the tree.
void	print_tree_list(t_list *first)
{
	t_list	*ptr;
	t_tree	*current;

	ptr = first;
	while (ptr)
	{
		current = ptr->content;
		print_tree(current, 0, 0);
		ptr = ptr->next;
	}
}

void	free_list(void *content)
{
	t_tree	*ptr;

	ptr = content;
	free(ptr->name);
	free(content);
}
