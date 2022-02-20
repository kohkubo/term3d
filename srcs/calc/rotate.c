#include "calc.h"

void	rotate_triangle(t_object *triangle)
{
	triangle->pos1 = vect_rotate(triangle->pos1, vect_new(0, 1, 1), radian(3));
	triangle->pos2 = vect_rotate(triangle->pos2, vect_new(0, 1, 1), radian(3));
	triangle->pos3 = vect_rotate(triangle->pos3, vect_new(0, 1, 1), radian(3));
}
