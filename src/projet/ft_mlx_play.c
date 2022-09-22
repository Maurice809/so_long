/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_play.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoret <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:45:06 by tmoret            #+#    #+#             */
/*   Updated: 2022/09/12 19:38:28 by tmoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mlx_play(int keycode, t_Game *info)
{
	int			i;
	int			j;
	void		*clear;

	clear = mlx_xpm_file_to_image (info->mlx, "./src/img/clear.xpm", &i, &j);
	mlx_put_image_to_window(info->mlx, info->mlx_win,
		clear, 70, info->ligne * 48);
	mlx_destroy_image (info->mlx, clear);
	ft_mlx_diams(info);
	if (keycode == 124 || keycode == 2 || keycode == 100)
		ft_mlx_play_124(info);
	if (keycode == 123 || keycode == 0 || keycode == 97)
		ft_mlx_play_123(info);
	if (keycode == 125 || keycode == 1 || keycode == 115)
		ft_mlx_play_125(info);
	if (keycode == 126 || keycode == 13 || keycode == 119)
		ft_mlx_play_126(info);
	if (keycode == 53 || keycode == 65307)
		exit_hook(info);
	ft_mlx_aff(info);
	return (0);
}
