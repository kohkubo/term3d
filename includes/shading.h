#ifndef SHADING_H
# define SHADING_H

# include "vect.h"
# include "data.h"
# include <string.h>

# define IA 0.1 //環境光の強度
# define KA 0.01 //環境光反射係数
# define KD 0.69 //拡散反射係数
# define KS 0.3 //鏡面反射係数
# define SHININESS 8 //光沢度

char	shading(t_camera *camera, t_light *light, t_object *hit);

#endif
