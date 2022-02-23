#include <gtest/gtest.h>
#include "calc.h"
#include "init.h"

TEST(DISABLED_Calc, is_intersect_with_triangle)
{
	t_object triangle;

	triangle.pos1 = vect_new(0, 2, 0);
	triangle.pos2 = vect_new(-2, -2, 0);
	triangle.pos3 = vect_new(2, -2, 0);

	t_camera *camera = (t_camera *)malloc(sizeof(t_camera));
	camera->pos = vect_new(0, 0, 15); // プラス方向から、マイナスに向くと交点あり
	camera->ray = vect_new(0, 0, -1);
	EXPECT_EQ(intersect_with_triangle_surface(camera, &triangle), 15);
	EXPECT_EQ(is_equal(vect_distance(camera->lookat, camera->pos), 15), true);
	EXPECT_NEAR(vect_distance(camera->pos, camera->lookat), 15, EPSILON);

	camera->pos = vect_new(0, 0, 15); // プラス方向から、マイナスに向くと交点あり
	camera->ray = vect_new(0, 0, -1);
	EXPECT_EQ(intersect_with_triangle_surface(camera, &triangle), 15);
	EXPECT_EQ(is_equal(vect_distance(camera->lookat, camera->pos), 15), true);
	EXPECT_NEAR(vect_distance(camera->pos, camera->lookat), 15, EPSILON);
	free(camera);
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

// デバッカーを動かすためのテストケース。テストとしては意味あることしてない。
TEST(DISABLED_Calc, is_intersect_with_vector)
{
	t_camera camera;
	camera.pos = vect_new(0, 0, 0);
	camera.ray = vect_new(0, 0, 1);
	t_vect pos = vect_new(-1, 0, 0);
	t_vect line = vect_new(1, 0, 0);
}

TEST(Calc, intersect_with_sphere)
{
	t_camera camera;

	camera.pos = vect_new(0, 0, -150);
	camera.ray = vect_new(0, 0, 1);
	t_vect pos = vect_new(0, 0, 0);
	double radius = 1;
	EXPECT_EQ(intersect_with_sphere(&camera, pos, radius), 149);
}