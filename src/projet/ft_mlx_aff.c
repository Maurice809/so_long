/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_aff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoret <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:16:44 by tmoret            #+#    #+#             */
/*   Updated: 2022/09/12 19:40:38 by tmoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_aff(t_Game *info)
{
	char	*count;

	count = ft_itoa(info->erreur);
	info->colone_temp = 0;
	info->ligne_temp = 0;
	info->i = -1;
	while (info->map[++info->i])
	{
		ft_mlx_aff2(info);
		if (info->map[info->i] == 'E')
			mlx_put_image_to_window(info->mlx, info->mlx_win, info->mlx_door,
				info->colone_temp * 48, info->ligne_temp * 48);
		if (info->map[info->i] == 'S')
			mlx_put_image_to_window(info->mlx, info->mlx_win, info->mlx_door,
				info->colone_temp * 48, info->ligne_temp * 48);
		if ((info->colone -1) == info->colone_temp)
		{
			++info->ligne_temp;
			info->colone_temp = -1;
		}
		++info->colone_temp;
	}
	mlx_string_put(info->mlx, info->mlx_win, 70,
		(info->ligne * 48) + 15, 0xFFFFFF, count);
	free(count);
}

void	ft_mlx_aff2(t_Game *info)
{
	if (info->map[info->i] == '1')
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->mlx_mur,
			info->colone_temp * 48, info->ligne_temp * 48);
	if (info->map[info->i] == '0')
		mlx_put_image_to_window(info->mlx, info->mlx_win,
			info->mlx_sol, info->colone_temp * 48, info->ligne_temp * 48);
	if (info->map[info->i] == 'C')
	{
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->mlx_sol,
			info->colone_temp * 48, info->ligne_temp * 48);
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->mlx_diams,
			info->colone_temp * 48, info->ligne_temp * 48);
	}
	if (info->map[info->i] == 'P')
	{
		info->player = info->i;
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->mlx_sol,
			info->colone_temp * 48, info->ligne_temp * 48);
		mlx_put_image_to_window(info->mlx, info->mlx_win, info->mlx_player,
			info->colone_temp * 48, info->ligne_temp * 48);
	}
}
