#include "reader.h"

static bool	is_valid_ext(char *filepath) {
	char	*ext;

	if (!filepath)
		return (false);
	ext = strrchr(filepath, '.');
	if (!ext || strncmp(ext, ".rt", 4))
		return (false);
	return (true);
}

bool	read_rtfile(t_data *data, char *filepath) {
	FILE	*file;

	if (!is_valid_ext(filepath))
		return (false);
	file = fopen(filepath, "r");
	if (!file) {
		fprintf(stderr, "Error: Input filepath named \"%s\" not found.\n", filepath);
		return (false);
	}
	fclose(file);
	return (true);
}

/*
void print_vector(t_vect *vect) {
	printf("[%f][%f][%f]\n", vect->x, vect->y, vect->z);
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
*/
