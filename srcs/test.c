/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehande <ehande@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 20:16:09 by ehande            #+#    #+#             */
/*   Updated: 2021/02/15 20:27:00 by ehande           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
int creat_write_file(char *v)
{	
	int tfd;

	if (ch_op(tfd = open("ch_read_write.txt",O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)))
		return (1);
	w(tfd, v);
	w(tfd,"\n");
	ft_write(tfd, v, strlen(v));
	close(tfd);
	return(0);
}

int get_str(char **s1, char **s2)
{
	int tfd;

	if(ch_op(tfd = open("ch_read_write.txt",O_RDONLY)))
		return (1);
	get_next_line(tfd, &(*s1));
	get_next_line(tfd, &(*s2));
	close(tfd);
	return(0);
}

int ch_write(int fd, char *v)
{	
	char *s1;
	char *s2;

	if(creat_write_file(v))
		return (1);
	get_str(&s1, &s2);
	wh(fd, "ft_write");
	w(fd, s1);
	w(fd, "\n\nmy:\n");
	ft_write(fd, s2, strlen(s2));
	wk(fd, strcmp(s1, s2), 0x000001);
	w(fd, "\n\nwith fd = -5");
	wk(fd, !(write(-5, v, strlen(v)) == ft_write(-5, v, strlen(v))), 0x000001);
	w(fd, "\n\n\n");
	free(s1);
	free(s2);
	return(0);
}

void ch_strlen(int fd, char *v)
{
	char	*s1;
	char	*s2;
		
	s1 = ft_itoa(strlen(v));
	wh(fd, "ft_strlen");
	w(fd, s1);
	s2 = ft_itoa(ft_strlen(v));
	w(fd, "\n\nmy:\n");
	w(fd, s2);
	wk(fd, strcmp(s1, s2), 0b000010);
	w(fd, "\n\n\n");
	free(s1);
	free(s2);
}

void ch_strdup(int fd, char *v)
{
	char *s1;
	char *s2;

	wh(fd, "ft_strdup");
	w(fd,(s1 = strdup(v)));
	w(fd, "\n\nmy:\n");
	w(fd,(s2 = ft_strdup(v)));
	wk(fd, strcmp(s1, s2), 0b000100);
	w(fd, "\n\n\n");
	free(s1);
	free(s2);
}

void ch_strcpy(int fd, char *v)
{
	char *s1;
	char *s2;

	s1 = malloc(strlen(v));
	s2 = malloc(strlen(v));
	wh(fd, "ft_strcpy");
	w(fd,(s1 = ft_strcpy(s1, v)));
	w(fd, "\n\nmy:\n");
	w(fd,(s2 = ft_strcpy(s2, v)));
	wk(fd, strcmp(s1, s2), 0b001000);
	w(fd, "\n\n\n");
	free(s1);
	free(s2);
}

void ch_strcmp(int fd)
{
	char	*tmp;
	
	wh(fd, "ft_strcmp");
	w(fd, tmp = ft_itoa(strcmp(CMP1, CMP2)));
	free (tmp);
	w(fd, "\n\nmy:\n");
	w(fd, tmp = ft_itoa(ft_strcmp(CMP1, CMP2)));
	free (tmp);
   	wk(fd, !(strcmp(CMP1, CMP2) == ft_strcmp(CMP1,CMP2)),  0b010000);
	w(fd, "\n\n\n");
}