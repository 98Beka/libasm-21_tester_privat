#include "test.h"

int call_fs(int fd, char *v)
{
	if (ch_write(fd, v))
		return (1);
	ch_strlen(fd, v);
	ch_strdup(fd, v);
	ch_strcpy(fd, v);
	if(ch_read(fd))
		return (1);
	ch_strcmp(fd);
	return (0);
}

int loop(t_all *all)
{
	int i;

	all->s = strdup(lngstr());
	if(all->v != NULL)
		call_fs(all->fd, all->v);
	call_fs(all->fd, all->s);
	call_fs(all->fd, strdup(""));
	i = strlen(all->s);
	res_out(0b100000, "ft_read", i);
	res_out(0b010000, "ft_strcmp", i);
	res_out(0b001000, "ft_strcpy", i);
	res_out(0b000100, "ft_strdup", i);
	res_out(0b000010, "ft_strlen", i);
	res_out(0b000001, "ft_write", i);
	coffee(all->fd);
	return (0);
}

int	main(int c, char **v)
{
	int		fd;
	t_all	all;

	all.v = NULL;
	if (c > 3)
		printf("elot of arguments\n");

	if(ch_op(fd = open("results.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH )))
	{
		close(fd);
		return (0);
	}
	all.v = v[1];
	all.fd = fd;
	if (loop(&all))
		return (0);
	printf("check file - results.txt\n");
	return (1);
}