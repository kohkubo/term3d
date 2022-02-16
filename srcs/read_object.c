#include "reader.h"

//FORMAT "tr [normal] [vert1] [vert2] [vert3]"
t_triangle *read_triangle(FILE *file)
{
	t_triangle *tri;
	char identifier[4];
	t_vect v[4];
	int read;

	read = fscanf(file, "%3s %lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf %lf,%lf,%lf ",
				  identifier, &v[0].x, &v[0].y, &v[0].z,
				  &v[1].x, &v[1].y, &v[1].z,
				  &v[2].x, &v[2].y, &v[2].z,
				  &v[3].x, &v[3].y, &v[3].z);
	if (read == EOF && feof(file)) //ファイル終端まで読んだ
		return (new_triangle());
	if (read != 13 || strncmp(identifier, "tr", 3)) //フォーマットチェック
		return (NULL);
	tri = new_triangle();
	if (!tri)
		return (NULL);
	tri->normal = v[0];
	tri->vert1 = v[1];
	tri->vert2 = v[2];
	tri->vert3 = v[3];
	return (tri);
}

//t_circle *read_circle(FILE *file)
//t_torus *read_torus(FILE *file)
