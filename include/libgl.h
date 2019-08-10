/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidqi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:43:22 by msidqi            #+#    #+#             */
/*   Updated: 2019/05/10 05:31:38 by msidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGL_H
# define LIBGL_H

# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include <time.h>
# include <stdio.h>
# include <fcntl.h>

# define ABS(Value) (Value >= 0) ? (Value) : -(Value)
# define STATIC_ARRAY_SIZE(ptr) (sizeof(ptr) / sizeof(ptr[0]))
# define MAX_ITER 30
# define VERTEX 0
# define VECTOR 1
# define DIRECTION 2
# define MATRIX 3
# define TRANSLATION_MATRIX 0
# define ROTATION_MATRIX 1
# define SCALING_MATRIX 2
# define NEAR 1e-6
# define FAR 1e+6
# define DISTANT_LIGHT 1e+6
# define RED 0xFF0000
# define GREEN 0xFF00
# define BLUE 0xFF
# define BLACK 0x0
# define WHITE 0xFFFFFF
# define AMBIENT_R 0.4
# define AMBIENT_G 0.4
# define AMBIENT_B 0.4
# define SPECULAR_POW 30
# define HEIGHT 720
# define WIDTH 1280
# define ASPECT_RATIO HEIGHT / WIDTH
# define MAX_ITER 30

typedef struct		t_vec2
{
	double			x;
	double			y;
}					t_vec2;

typedef struct		s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef struct		s_matrix
{
	int	cols;
	int	rows;
	double			**v;
}					t_matrix;

typedef struct		s_vec4
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vec4;


/*
** Homogenous Coordinates
**   F U R  T   (Forward/Up/Right/Translation Vector)
** [[1 0 0] 0]
** [[0 1 0] 0]
** [[0 0 1] 0]
** [ 0 0 0  1] 0 Direction Vector 1 Position Vector
** FUR == unit vectors describing object orientation. aka vector basis
**
*/
typedef struct		s_matrix4
{
	short			type;
	double			v[4][4];
}					t_matrix4;

typedef enum		e_bool
{
	false, true
}					t_bool;
 
double				lerp(double x1, double x2, double lerp);
void				ft_create_vec2(t_vec2 *a, double x, double y);
void				ft_create_vec3(t_vec3 *a, double x, double y, double z);
t_vec2				ft_vec2_add(t_vec2 a, t_vec2 b);
t_vec3				ft_vec3_add(t_vec3 a, t_vec3 b);
t_vec2				ft_vec2_sub(t_vec2 a, t_vec2 b);
t_vec3				ft_vec3_sub(t_vec3 a, t_vec3 b);
t_vec2				ft_vec2_scalar(t_vec2 a, double factor);
t_vec3				ft_vec3_scalar(t_vec3 a, double factor);
double				ft_vec2_mag(t_vec2 a);
double				ft_vec3_mag(t_vec3 a);
double				ft_vec2_mag_cmp(t_vec2 a, t_vec2 b);
double				ft_vec3_mag_cmp(t_vec3 a, t_vec3 b);
t_vec2				ft_vec2_normalize(t_vec2 a);
t_vec3				ft_vec3_normalize(t_vec3 a);
double				ft_vec2_dot_product(t_vec2 a, t_vec2 b);
double				ft_vec3_dot_product(t_vec3 a, t_vec3 b);
t_vec2				ft_vec2_rotate_byangle(t_vec2 a, double angle);
t_vec2				ft_vec2_rotate_byaxis(t_vec2 a, t_vec2 x_axis, t_vec2 y_axis);
t_matrix			*ft_create_matrix(int rows, int cols);
t_matrix4			ft_create_matrix4();
int					ft_destroy_matrix(t_matrix *mat);
t_matrix4			ft_get_translation_matrix4(t_matrix4 mat, double x, double y, double z);
t_vec4				ft_create_vec4(double x, double y, double z, double w) ;
t_vec4				ft_matrix_x_vector(t_matrix4 mat, t_vec4 vec);
t_vec4				ft_vec4_sub(t_vec4 vec1, t_vec4 vec2);
t_vec4    			ft_vec4_normalize(t_vec4 a);
double    			ft_vec4_mag(t_vec4 a);
double				ft_vec4_dot_product(t_vec4 a, t_vec4 b);
t_vec4 	   			ft_vec4_cross_product(t_vec4 vec1, t_vec4 vec2);
t_vec4				ft_vec4_add(t_vec4 vec1, t_vec4 vec2);
t_vec4				ft_vec4_scalar(t_vec4 a, double factor);
double				ft_min(double val, double min);
double				ft_max(double val, double max);

#endif
