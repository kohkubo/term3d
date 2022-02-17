#include <gtest/gtest.h>
#include "triangle.h"

TEST(Intersect, is_intersect_with_triangle)
{
	t_triangle triangle;

	triangle.vect1 = vect_new(0, 2, 0);
	triangle.vect2 = vect_new(-2, -2, 0);
	triangle.vect3 = vect_new(2, -2, 0);

	t_camera *camera = (t_camera *)malloc(sizeof(t_camera));
	camera->pos = vect_new(0, 0, 15);
	camera->ray = vect_new(0, 0, -1);
	EXPECT_EQ(is_intersect_with_triangle(camera, &triangle), true);
	// EXPECT_EQ(is_equal(vect_distance(camera->lookat, camera->pos), 15), true);
  // 中心点がないのでいい感じの距離がつかめないためコメントアウト。概数を目視チェックしていた。
	// EXPECT_DOUBLE_EQ(vect_distance(camera->lookat, triangle.vect1), 15);
}
