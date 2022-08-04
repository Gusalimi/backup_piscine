/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tab.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abitonti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:20:53 by abitonti          #+#    #+#             */
/*   Updated: 2022/08/03 23:49:02 by abitonti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TAB_H
# define T_TAB_H
# define BUFFSIZE 100000

typedef struct s_obstacle
{
	int					line;
	int					col;
	struct s_obstacle	*next;
}	t_obstacle;

typedef struct s_point
{
	int				line;
	int				col;
	struct s_point	*next;
}	t_point;

typedef struct s_tab
{
	int			line;
	int			col;
	char		charset[3];
	char		**grid;
	t_obstacle	*firstobs;
}	t_tab;

#endif
