/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lderks <lderks@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/03 13:37:05 by lderks        #+#    #+#                 */
/*   Updated: 2026/04/21 14:07:48 by lderks        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>
# include <math.h>

# define WIDTH  1280
# define HEIGHT 720

# define RAY_T_MIN 0.001f
# define RAY_T_MAX 1.0e30f

# define MAX_SHAPES 50

# define M_PI 3.14159265358979323846

typedef struct s_shape			t_shape;
typedef struct s_intersection	t_intersection;
typedef struct s_ray			t_ray;
typedef struct s_scene			t_scene;
typedef struct s_vector			t_point;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_image	image;
}	t_mlx;

typedef struct s_parser
{
	int	sphere_count;
	int	plane_count;
	int	cylinder_count;
	int	has_ambient;
	int	has_camera;
	int	has_light;
	int	shape_count;		//added struct for overall count shapes
}	t_parser;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
	float		t_max;			//maximum length of the ray
}	t_ray;

typedef struct s_intersection
{
	t_ray	ray;
	float	length;				// -> t
	t_shape	*shape;
	t_color	color;
	t_scene	*scene;				// we need this to access light and ambient.
	int		hit_cap;
	t_point	cap_center;			// which cap center was hit for the normal dir.
}	t_intersection;

typedef enum s_shape_type
{
	PLANE = 1,
	SPHERE = 2,
	CYLINDER = 3,
}	t_shape_type;

typedef struct s_shape
{
	int	type;
	int	(*full_intersection)(t_shape *shape,
			t_intersection *intersection);
	int	(*single_intersection)(t_shape *shape, const t_ray *ray);
}	t_shape;

typedef struct s_shapeset
{
	t_shape		*shapes[MAX_SHAPES];
	int			count;
}	t_shapeset;

typedef struct s_plane
{
	t_shape		shape;
	t_point		point;			//any point on the plane
	t_vector	normal;			// normalized [-1,1]
	t_color		color;
}	t_plane;

typedef struct s_sphere
{
	t_shape		shape;
	t_point		centre;
	float		radius;			// 1/2 * the diameter
	t_color		color;
}	t_sphere;

typedef struct s_sphere_math
{
	t_ray	local_ray;
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	length_1;
	float	length_2;
}	t_sphere_math;

typedef struct s_cylinder
{
	t_shape	shape;
	t_point	center;
	t_point	axis;
	float	radius;				// 1/2 * the diameter
	float	height;
	t_color	color;
}	t_cylinder;

typedef struct s_cylinder_math
{
	t_vector	origin_to_base;
	t_vector	v_perp;
	t_vector	dp_perp;
	float		a;
	float		b;
	float		c;
	float		discriminant;
	float		t_near;
	float		t_far;
}	t_cylinder_math;

typedef struct s_screen_coordinate
{
	float	x;					//Horizontal 2D coordinate - x
	float	y;					//Vertical 2D coordinate - y
}	t_screen_coordinate;

/* A 0.2 255,255,255 — only one per scene */
typedef struct s_ambient
{
	double	ratio;			// [0.0, 1.0]
	t_color	color;
}	t_ambient;

/* stores where the camera is, where it's pointing, and the FOV.
we need this to know how to generate the rays.
only one per scene */
typedef struct t_camera
{
	t_point		pos;
	t_vector	dir;
	t_vector	right;
	t_vector	up;
	int			fov;		// [0, 180] field of view
	float		half_h;		// height scaling unit - tan(fov/2)
	float		half_w;		// width scaling unit - half_h * aspect ratio
}	t_camera;

/*only one per scene*/
typedef struct s_light
{
	t_point	pos;
	double	brightness;		// [0.0, 1.0]
	t_color	color;

}	t_light;

typedef struct s_scene
{
	t_parser	parser;
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_shapeset	shapeset;
	t_sphere	sphere[MAX_SHAPES];
	t_plane		plane[MAX_SHAPES];
	t_cylinder	cylinder[MAX_SHAPES];
}	t_scene;

#endif
