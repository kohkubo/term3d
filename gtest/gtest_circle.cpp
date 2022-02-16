#include <gtest/gtest.h>
#include "circle.h"

TEST(Circle, intersect_with_plane)
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

}

TEST(Circle, is_intersect_with_circle)
{
	t_circle *circle = (t_circle *)malloc(sizeof(t_circle));
	circle->center = vect_new(0, 0, 0);
	circle->radius = 1;
	t_camera *camera = (t_camera *)malloc(sizeof(t_camera));
	camera->pos = vect_new(0, 0, 10);
	camera->ray = vect_new(0, 0, -1);
	EXPECT_EQ(is_intersect_with_circle(camera, circle), true);
	EXPECT_EQ(is_equal(vect_distance(camera->lookat, camera->pos), 10), true);

	camera->pos = vect_new(0, 0, -10);
	camera->ray = vect_new(0, 0, 1);
	EXPECT_EQ(is_intersect_with_circle(camera, circle), true);
	EXPECT_EQ(is_equal(vect_distance(camera->lookat, camera->pos), 10), true);

	camera->pos = vect_new(0, 0, 10);
	camera->ray = vect_new(0, 0, 1);
	EXPECT_EQ(is_intersect_with_circle(camera, circle), false);
	EXPECT_EQ(isinf(vect_distance(camera->lookat, camera->pos)), true);

	camera->pos = vect_new(0, 0, -10);
	camera->ray = vect_new(0, 0, -1);
	EXPECT_EQ(is_intersect_with_circle(camera, circle), false);
	EXPECT_EQ(isinf(vect_distance(camera->lookat, camera->pos)), true);
}
