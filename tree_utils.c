/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:09:33 by tdeliot           #+#    #+#             */
/*   Updated: 2025/03/13 15:26:13 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

DIR	*open_directory(void)
{
	DIR	*my_dir;

	my_dir = opendir("/proc/");
	if (!my_dir)
	{
		perror("opendir");
		return (NULL);
	}
	return (my_dir);
}

//create the path to each processus.
char	*path_generator(char *entry_name)
{
	char	*new;
	char	*temp;

	temp = ft_strjoin("/proc/", entry_name);
	new = ft_strjoin(temp, "/status");
	free(temp);
	return (new);
}

//we create the command which search usefull information and store them
// into temp.txt one information by line.
int	print_info(char *path_to_status)
{
	char	*command;
	char	*command2;
	int		uid;

	command = ft_strjoin("awk ' NR == 6 || NR == 7 || NR == 1  { print $2 }' ", path_to_status);
	command2 = ft_strjoin(command, " > /home/tdeliot/Desktop/exercice/exercice2/temp.txt");
	free(command);
	if (!access(path_to_status, R_OK))
	{
		system(command2);
		free(command2);
		return (0);
	}
	return (-1);
}

//verify that the name correspond to a process
int	only_number(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] < '0' || arg[i] > '9'))
			return (-1);
		i++;
	}
	return (0);
}

//initialate the structure reading each line.
t_tree	*get_info(void)
{
	t_tree	*new;
	int		fd;
	char	*ppid;
	char	*pid;

	new = malloc(sizeof(t_tree));
	if (!new)
		return NULL;
	fd = open("temp.txt", O_RDONLY);
	if (fd == -1)
	{
		free(new);
		return NULL;
	}
	new->name = get_next_line(fd);
	pid = get_next_line(fd);
	ppid = get_next_line(fd);
	get_next_line(fd);
	new->pid = atoi(pid);
	new->ppid = atoi(ppid);
	new->already_print = 0;
	free(ppid);
	free(pid);
	close(fd);
	unlink("temp.txt");
	return (new);
}

// we use recurvicity to insure that the children 
// are printed before the rest of the list
void	print_tree(t_tree *content, int i, int indent_lvl)
{
	int	j;

	j = 0;
	while (j++ < indent_lvl)
	{
		printf("\t");
	}
	if (content->already_print == 0)
	{
		printf("%s", content->name);
		content->already_print = 1;
		while (content->children[i])
		{
			print_tree(content->children[i], 0, indent_lvl + 1);
			i++;
		}
	}
}
