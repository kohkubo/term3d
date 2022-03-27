#include <benchmark/benchmark.h>
#include "term3d.h"

#define MAX_RANGE_SIZE (1 << 22)


static void BM_DRAW(benchmark::State& state) {
	t_data		data;
	char **av = (char **)malloc(sizeof(char*) * 3);
	av[0] = "./term3d";
	av[1] = "sample/torus_lowply.tri";
	set_config(&data, 2, av);
	load_file(&data, av[1]);
	free(av);
	init_data(&data);
	data.camera.pos.z = -16;
  for (auto _ : state) {
		draw(&data);
  }
}
BENCHMARK(BM_DRAW);

BENCHMARK_MAIN();