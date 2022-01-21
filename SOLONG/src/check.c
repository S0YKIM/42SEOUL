/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:14:54 by sokim             #+#    #+#             */
/*   Updated: 2022/01/21 20:51:16 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	sl_is_rectangle(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		if ((int)ft_strlen(map->map[i]) != map->width)
			return (0);
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (map->map[0][j])
	{
		if (map->map[0][j] != '1' || map->map[map->height - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	sl_check_size(t_map *map)
{
	if (map->width < 3 || map->height < 3
		|| map->width * map->height < 15)
		return (0);
	return (1);
}

static int	count_letters(t_map *map, char letter)
{
	int		i;
	int		j;
	int		cnt;

	cnt = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == letter)
				cnt++;
			j++;
		}
		i++;
	}
	return (cnt);
}

static int	sl_check_elements(t_map *map)
{
	if (count_letters(map, 'P') != 1)
		return (0);
	if (count_letters(map, 'E') < 1)
		return (0);
	if (count_letters(map, 'C') < 1)
		return (0);
	return (1);
}

int	sl_is_validate_map(t_data *data)
{
	if (sl_is_rectangle(&(data->map)) == 0)
		sl_exit_with_message("The map is not rectangle.", data);
	if (sl_check_size(&(data->map)) == 0)
		sl_exit_with_message("Invalid map size.", data);
	if (sl_check_elements(&(data->map)) == 0)
		sl_exit_with_message("Invalid number of elements.", data);
	return (1);
}
