#include <gtest/gtest.h>
#include "calc.h"

TEST(DISABLED_Calc, is_intersect_with_triangle)
{
	t_object triangle;

	triangle.pos1 = vect_new(0, 2, 0);
	triangle.pos2 = vect_new(-2, -2, 0);
	triangle.pos3 = vect_new(2, -2, 0);

	t_camera *camera = (t_camera *)malloc(sizeof(t_camera));
	camera->pos = vect_new(0, 0, 15); // プラス方向から、マイナスに向くと交点あり
	camera->ray = vect_new(0, 0, -1);
	EXPECT_EQ(is_intersect_with_triangle(camera, &triangle), true);
	EXPECT_EQ(is_equal(vect_distance(camera->lookat, camera->pos), 15), true);
	EXPECT_NEAR(vect_distance(camera->pos, camera->lookat), 15, EPSILON);

	camera->pos = vect_new(0, 0, -15); // プラス方向から、マイナスに向くと交点あり
	camera->ray = vect_new(0, 0, 1);
	EXPECT_EQ(is_intersect_with_triangle(camera, &triangle), true);
	EXPECT_EQ(is_equal(vect_distance(camera->lookat, camera->pos), 15), true);
	EXPECT_NEAR(vect_distance(camera->pos, camera->lookat), 15, EPSILON);
	free(camera);
}

TEST(Calc, camera_ray)
{
	int x = WIDTH / 2;
	int y = HEIGHT / 2;
	t_camera camera;
	camera.pos = vect_new(0,0,-15);
	camera.normal = vect_new(0,0,-1);
	t_vect ray = camera_ray(&camera, x, y);
	VECTOR_EQ(ray, vect_new(0,0,-1));
}

// デバッカーを動かすためのテストケース。テストとしては意味あることしてない。
TEST(Calc, is_intersect_with_vector)
{
	t_camera camera;
	camera.pos = vect_new(0, 0, 0);
	camera.ray = vect_new(0, 0, 1);
	t_vect pos = vect_new(-1, 0, 0);
	t_vect line = vect_new(1, 0, 0);
}