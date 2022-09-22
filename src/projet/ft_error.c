/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Maurice809 <maurice809@hotmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:54:19 by Maurice809        #+#    #+#             */
/*   Updated: 2022/09/13 22:41:05 by tmoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(int nbr)
{
	ft_printf("Error\n");
	if (nbr == 0)
		ft_printf("\nError : no argument or wrong file name\n");
	if (nbr == 1)
		ft_printf("\nError : your map contains one or more errors\n");
	if (nbr == 2)
		ft_printf("\nError : your file is empty or invalid\n");
	ft_printf("\nMore information : so_long game.ber\n\n");
	exit (1);
}
