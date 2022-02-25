#ifndef SHADING_H
# define SHADING_H

# include "vect.h"
# include "data.h"
# include <string.h>

# define IA 0.1 //環境光の強度
# define KA 0.01 //環境光反射係数
# define KD 0.4 //拡散反射係数
# define KS 0.4 //鏡面反射係数
# define SHININESS 32 //光沢度

double	shading(t_camera *camera, t_light *light, t_object *hit);
char	radiance_to_density(t_config *conf, double radiance);

#endif
