#include <benchmark/benchmark.h>

// Define benchmark
static void BM_StringCopy(benchmark::State& state) {
  std::string x = "hello";
  for (auto _ : state) {
     std::vector<int> myVec;
     for(int i = 0; i < state.range(0); i++) {
        myVec.push_back(i);
     }
  }
}

// Register the function as a benchmark
BENCHMARK(BM_StringCopy)->RangeMultiplier(2)->Range(1, 1000);

BENCHMARK_MAIN();