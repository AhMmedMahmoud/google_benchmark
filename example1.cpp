#include <benchmark/benchmark.h>

// Define benchmark
static void BM_StringCopy(benchmark::State& state) {
  std::string x = "hello";
  for (auto _ : state)
    std::string copy(x);
}

// Register the function as a benchmark
BENCHMARK(BM_StringCopy);

BENCHMARK_MAIN();