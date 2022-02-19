#include "vect.h"

t_vect vect_move(t_vect pos, t_vect dir, double len)
{
	return (vect_add(pos, vect_scalar_mul(dir, len)));
}
