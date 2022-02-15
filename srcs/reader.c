#include "../include/term3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Camera
//C x,y,z

//Light
//L x,y,z range

//Circle
//ci x,y,z x,y,z radius

//Torus
//to x,y,z x,y,z radius tube_radius


//ファイルから一行読み込み
//読み込みデータからオブジェクトの判別
//オブジェクトをt_dataに追加

//for debug
void print_vector(t_vect *vect) {
	printf("[%f][%f][%f]\n", vect->x, vect->y, vect->z);
}

void	print_data(t_data *data) {
	printf("\ncamera_pos");
	print_vector(&data->camera_pos);

	printf("light_pos");
	print_vector(&data->light_pos);
	printf("light_range[%f]\n\n", data->light_range);

	printf("circle_center");
	print_vector(&data->circle.circle_center);
	printf("circle_normal");
	print_vector(&data->circle.circle_normal);
	printf("circle_radius[%f]\n\n", data->circle.circle_radius);

	printf("torus_center");
	print_vector(&data->torus.torus_center);
	printf("torus_normal");
	print_vector(&data->torus.torus_normal);
	printf("torus_radius[%f]\ntorus_tube_radius[%f]\n\n", data->torus.torus_radius, data->torus.torus_tube_radius);
}

bool set_camera(FILE *file, t_data *data)
{
	t_vect pos;

	if (fscanf(file, "%lf,%lf,%lf", &pos.x, &pos.y, &pos.z) != 3)
		return (false);
	data->camera_pos.x = pos.x;
	data->camera_pos.y = pos.y;
	data->camera_pos.z = pos.z;
	return (true);
}


bool set_light(FILE *file, t_data *data)
{
	t_vect pos;
	double range;

	if (fscanf(file, "%lf,%lf,%lf %lf", &pos.x, &pos.y, &pos.z, &range) != 4)
		return (false);
	data->light_pos.x = pos.x;
	data->light_pos.y = pos.y;
	data->light_pos.z = pos.z;
	data->light_range = range;
	return (true);
}

bool add_circle(FILE *file, t_data *data)
{
	t_vect pos;
	t_vect normal;
	double radius;

	if (fscanf(file, "%lf,%lf,%lf %lf,%lf,%lf %lf", &pos.x, &pos.y, &pos.z, &normal.x, &normal.y, &normal.z, &radius) != 7)
		return (false);
	data->circle.circle_center.x = pos.x;
	data->circle.circle_center.y = pos.y;
	data->circle.circle_center.z = pos.z;
	data->circle.circle_normal.x = normal.x;
	data->circle.circle_normal.y = normal.y;
	data->circle.circle_normal.z = normal.z;
	data->circle.circle_radius = radius;
	return (true);
}

bool add_torus(FILE *file, t_data *data)
{
	t_vect pos;
	t_vect normal;
	double radius;
	double tube_radius;

	if (fscanf(file, "%lf,%lf,%lf %lf,%lf,%lf %lf %lf", &pos.x, &pos.y, &pos.z, &normal.x, &normal.y, &normal.z, &radius, &tube_radius) != 8)
		return (false);
	data->torus.torus_center.x = pos.x;
	data->torus.torus_center.y = pos.y;
	data->torus.torus_center.z = pos.z;
	data->torus.torus_normal.x = normal.x;
	data->torus.torus_normal.y = normal.y;
	data->torus.torus_normal.z = normal.z;
	data->torus.torus_radius = radius;
	data->torus.torus_tube_radius = tube_radius;
	return (true);
}

void read_rtfile(t_data *data, char *filepath) {
	FILE	*file;

	file = fopen(filepath, "r");
	if (!file) {
		fprintf(stderr, "Error: Input filepath named \"%s\" not found.\n", filepath);
		exit(1);
	}


	//get_identifier
	char identifier[256];
	while (fscanf(file, "%255s", identifier) != EOF) {
		//set or add object from file
		if (!strncmp(identifier, "C", 3) && set_camera(file, data))
			;
		else if (!strncmp(identifier, "L", 3) && set_light(file, data))
			;
		else if (!strncmp(identifier, "ci", 3) && add_circle(file, data))
			;
		else if (!strncmp(identifier, "to", 3) && add_torus(file, data))
			;
		else
		{
			fprintf(stderr, "Error: Invalid identifier.");
			exit(1);
		}
	}
	fclose(file);
}

int main(int argc, char **argv) {
	t_data data = {0};

	if (argc != 2) {
		fprintf(stderr, "Usage: ./term3d [filepath]");
		exit(1);
	}
	read_rtfile(&data, argv[1]);
	print_data(&data);
	return (0);
}
