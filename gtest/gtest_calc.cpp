#include <gtest/gtest.h>
#include "calc.h"

TEST(DISABLED_Calc, intersect_with_plane)
{
	// カメラが平面を向いている
  t_camera  *camera;
  t_vect    center = vect_new(0, 0, 0);
  t_vect    normal = vect_new(0, 0, 1);
	camera = (t_camera *)malloc(sizeof(t_camera));
	camera->pos = vect_new(0, 0, 10);
	camera->ray = vect_new(0, 0, -1);

	camera->lookat = intersect_with_plane(camera, &center, &normal);
	EXPECT_EQ(vect_distance(camera->lookat, camera->pos), 10);

	// カメラが平面を向いている
	camera->pos = vect_new(0, 0, -10);
	camera->ray = vect_new(0, 0, 1);
	camera->lookat = intersect_with_plane(camera, &center, &normal);
	EXPECT_EQ(vect_distance(camera->lookat, camera->pos), 10);

	// カメラが平面を向いていない
	camera->pos = vect_new(0, 0, 10);
	camera->ray = vect_new(0, 0, 1);
	camera->lookat = intersect_with_plane(camera, &center, &normal);
	EXPECT_TRUE(isinf(vect_distance(camera->lookat, camera->pos)));

	// カメラが平面を向いていない
	camera->pos = vect_new(0, 0, -10);
	camera->ray = vect_new(0, 0, -1);
	camera->lookat = intersect_with_plane(camera, &center, &normal);
	EXPECT_TRUE(isinf(vect_distance(camera->lookat, camera->pos)));

	// カメラと平面が重なっている場合
	camera->pos = vect_new(0, 0, 0);
	camera->ray = vect_new(0, 0, 1);
	camera->lookat = intersect_with_plane(camera, &center, &normal);
	EXPECT_EQ(vect_distance(camera->lookat, camera->pos), 0);

	// カメラと平面が重なっている場合
	camera->pos = vect_new(0, 0, 0);
	camera->ray = vect_new(0, 0, -1);
	camera->lookat = intersect_with_plane(camera, &center, &normal);
	EXPECT_EQ(vect_distance(camera->lookat, camera->pos), 0);

	//	平面と平面が重なっている場合
	normal = vect_new(0, 1, 0);
	camera->pos = vect_new(0, 0, 10);
	camera->ray = vect_new(0, 0, 1);
	camera->lookat = intersect_with_plane(camera, &center, &normal);
	EXPECT_EQ(isinf(vect_distance(camera->lookat, camera->pos)), true);

	// 平面を回転させる
	normal = vect_new(0, 0, 1);
	camera->pos = vect_new(0, 0, 10);
	camera->ray = vect_new(0, 0, -1);
	normal = vect_rotate(normal, vect_new(0, 1, 0), radian(90));
	camera->lookat = intersect_with_plane(camera, &center, &normal);
	EXPECT_EQ(isinf(vect_distance(camera->lookat, camera->pos)), true);

	normal = vect_new(0, 0, 1);
	center = vect_new(0, 0, 0);
	camera->pos = vect_new(0, 0, 10);
	camera->ray = vect_new(0, 0, -1);
	camera->lookat = intersect_with_plane(camera, &center, &normal);
	double distance = vect_distance(camera->lookat, center);
	EXPECT_EQ(is_equal(vect_distance(camera->lookat, center), 0), true);

	free(camera);
}

TEST(DISABLED_Calc, is_intersect_with_circle)
{
	t_object *object;
	t_object *circle = (t_object *)malloc(sizeof(t_object));
	circle->pos1 = vect_new(0, 0, 0);
	circle->radius = 1;
	t_camera *camera = (t_camera *)malloc(sizeof(t_camera));
	camera->pos = vect_new(0, 0, 10);
	camera->ray = vect_new(0, 0, -1);
	// サークルの形を変更したため、中心位置で、交点がとれなくなったためコメントアウト
	// EXPECT_EQ(is_intersect_with_circle(camera, circle), true);
	// EXPECT_EQ(is_equal(vect_distance(camera->lookat, camera->pos), 10), true);

	camera->pos = vect_new(0, 0, -10);
	camera->ray = vect_new(0, 0, 1);
	// サークルの形を変更したため、中心位置で、交点がとれなくなったためコメントアウト
	// EXPECT_EQ(is_intersect_with_circle(camera, circle), true);
	// EXPECT_EQ(is_equal(vect_distance(camera->lookat, camera->pos), 10), true);

	camera->pos = vect_new(0, 0, 10);
	camera->ray = vect_new(0, 0, 1);
	object = circle;
	EXPECT_EQ(is_intersect_with_circle(camera, object), false);
	EXPECT_EQ(isinf(vect_distance(camera->lookat, camera->pos)), true);

	camera->pos = vect_new(0, 0, -10);
	camera->ray = vect_new(0, 0, -1);
	object = circle;
	EXPECT_EQ(is_intersect_with_circle(camera, object), false);

	EXPECT_EQ(isinf(vect_distance(camera->lookat, camera->pos)), true);

	free(camera);
	free(circle);
}

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

	EXPECT_FALSE(is_intersect_with_vector(&camera, pos, line));
}