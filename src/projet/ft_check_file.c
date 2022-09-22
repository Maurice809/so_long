/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Maurice809 <maurice809@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:37:44 by Maurice809        #+#    #+#             */
/*   Updated: 2022/09/12 19:06:34 by tmoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_guru(t_Game *info)
{
	if (info->colone == 0)
		ft_error(2);
	info->ligne = info->carater / info->colone;
}

void	ft_check_file(int fd, t_Game *info)
{
	char	c;
	char	*line;

	line = (char *)malloc(sizeof(char));
	line[0] = '\0';
	while ((read(fd, &c, 1)) > 0)
	{
		if (info->ligne == 1 && c == '1')
			info->colone++;
		if (c == '\n')
			info->ligne++;
		else
			info->colone_temp++;
		if (info->colone != info->colone_temp && c == '\n')
			info->erreur++;
		if (info->colone_temp == info->colone && c == '\n')
			info->colone_temp = 0;
		if (c != '\n')
			line = ft_strjoin1(line, c);
	}
	while (line[++info->carater])
		;
	info->map = ft_strdup(line);
	free (line);
	ft_guru(info);
}
