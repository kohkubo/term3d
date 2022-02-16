#include "init.h"

t_triangle	*new_triangle(void)
{
	t_triangle	*tri;

	tri = (t_triangle *)malloc(sizeof(t_triangle));
	if (!tri)
		return (NULL);
	tri->normal = vect_new(0, 0, 0);
	tri->vert1 = vect_new(0, 0, 0);
	tri->vert2 = vect_new(0, 0, 0);
	tri->vert3 = vect_new(0, 0, 0);
	return (tri);
}

//t_circle *new_circle(void)
//t_torus *new_torus(void)
