/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:09:41 by tdeliot           #+#    #+#             */
/*   Updated: 2025/03/13 10:05:28 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

//get_next_line.c
char	*get_next_line(int fd);
char	*ft_read(char *static_str, int fd);
char	*ft_get_line(char *static_str);
char	*ft_update_leftover(char *static_str);

//get_next_line_utils.c
int		ft_strlen_2(const char *str);
char	*ft_strchr_2(const char *s, int c);
char	*ft_strjoin_2(char *str1, char *str2);

#endif
