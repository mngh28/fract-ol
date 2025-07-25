/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:13:44 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/07/19 14:13:44 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	type_cmp(char *av, char *str, char c, char n)
{
	int	i;

	i = 0;
	while (av[i])
	{
		av[i] = ft_tolower(av[i]);
		i++;
	}
	if (!ft_strncmp(av, str, ft_strlen(str) + 1))
		return (1);
	else if (av[1] == '\0' && (av[0] == c || av[0] == n))
		return (1);
	return (0);
}

static void	get_set(t_data *fract, char **av)
{
	if (type_cmp(av[1], "mandelbrot", 'm', '1'))
		fract->set = MANDELBROT;
	else if (type_cmp(av[1], "julia", 'j', '2'))
		fract->set = JULIA;
	else if (type_cmp(av[1], "burning ship", 'b', '3'))
		fract->set = BURNING_SHIP;
	else
		help_msg(fract);
}

static void	julia_starting_values(t_data *fract, int ac, char **av)
{
	if (fract->set != JULIA || ac == 2)
	{
		fract->k_real = -0.766667;
		fract->k_imaginary = -0.090000;
		return ;
	}
	if (ac == 3)
		help_msg(fract);
	fract->k_real = ft_atof(av[2]);
	fract->k_imaginary = ft_atof(av[3]);
	if (fract->k_real > 2.0 || fract->k_real < -2.0)
		help_msg(fract);
	if (fract->k_imaginary >= 2.0 || fract->k_imaginary <= -2.0)
		help_msg(fract);
}

static void	arg_handle(t_data *fract, int ac, char **av)
{
	get_set(fract, av);
	if (fract->set != JULIA && ac > 3)
		help_msg(fract);
	else if (fract->set == JULIA && ac > 5)
		help_msg(fract);
	julia_starting_values(fract, ac, av);
	get_color(fract, ac, av);
}

int	main(int ac, char **av)
{
	t_data	fract;

	if (ac < 2)
	{
		ft_putstr_fd("Wrong number of args!\nUsage: ./fractol <type>", 1);
		return (1);
	}
	start_init(&fract);
	arg_handle(&fract, ac, av);
	init(&fract);
	draw(&fract);
	mlx_hook(fract.win, EVENT_CLOSE_BTN, 0, close_program, &fract);
	mlx_key_hook(fract.win, key_press, &fract);
	mlx_mouse_hook(fract.win, mouse_mov, &fract);
	mlx_loop(fract.mlx);
}
