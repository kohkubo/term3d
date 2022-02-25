#include <gtest/gtest.h>
#include "ray.h"
#include "init.h"

static void VECTOR_EQ(t_vect act, t_vect exp) {
	EXPECT_EQ(act.x, exp.x);
	EXPECT_EQ(act.y, exp.y);
	EXPECT_EQ(act.z, exp.z);
}

TEST(Calc, camera_ray)
{
	t_data	data;
	int x = 50;
	int y = 50;

	data.camera.pos = vect_new(0, 0, -150);
	data.camera.up = vect_new(0, 1, 0);
	data.camera.right = vect_new(1, 0, 0);
	data.camera.normal = vect_new(0, 0, 1);
	data.camera.normal_axis = vect_normalize(vect_new(0, 1, 0));
	data.camera.rotate_angle = radian(1);
	data.camera.height = 100;
	data.camera.width = 100;
	t_vect ray = camera_ray(&data.camera, x, y);
	VECTOR_EQ(ray, vect_new(0, 0, 1));
}
