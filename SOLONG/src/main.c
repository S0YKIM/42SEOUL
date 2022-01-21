/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:10:29 by sokim             #+#    #+#             */
/*   Updated: 2022/01/21 21:38:26 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = 0;
	data->count = 0;
	data->map.map = 0;
	data->map.height = 0;
	data->map.width = 0;
	data->imgs.back.img = 0;
	data->imgs.wall.img = 0;
	data->imgs.player.img = 0;
	data->imgs.collects.img = 0;
	data->imgs.exit.img = 0;
}

void	so_long(char *filename)
{
	t_data	data;

	/* 데이터 초기화 */
	sl_init_data(&data);

	/* 파일을 읽어서 맵 파싱*/
	sl_parse_map(&(data.map), filename, &data);

	/* 맵 유효성 검사 */
	sl_is_validate_map(&data);

	/* 새 창 띄우기 */
	sl_new_window(&(data.mlx), &(data.map), &data);

	/* 이미지 띄우기*/
	sl_new_image(&data);

	/* 이벤트 후킹 */
	/* sl_event_hook(&data); */

	/* 루프 돌리기 */
	mlx_loop(data.mlx);
}

int     main(int argc, char **argv)
{
	if (argc != 2)
		printf("Invalid number of arguments.");
	else if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber") != 0)
		printf("Invalid file format.");
	else
		so_long(argv[1]);
	return (0);
}
