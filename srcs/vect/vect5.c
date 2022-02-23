#include "vect.h"

t_vect	vect_move(const t_vect *pos, const t_vect *dir, double len)
{
	return (vect_add(*pos, vect_scalar_mul(dir, len)));
}
