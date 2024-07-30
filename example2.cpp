#include "benchmark/benchmark.h"
#include <iostream>
#include <string>

// Adds value n times and returns the result
unsigned long AddByValue(unsigned long n, unsigned long value) {
  unsigned long sum = 0;
  for (unsigned long i = 0; i < n; i++) {
    sum += value;
  }
  return sum;
}

// A Benchmark for AddByValue
static void BM_AddByValue(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    AddByValue(state.range(0), state.range(1));
  }
}

// Register the function as a benchmark
BENCHMARK(BM_AddByValue)->RangeMultiplier(2)->RangePair(1, 100, 256, 1024);  

// Increments n times and returns the value
unsigned long Increment(unsigned long n) {
  unsigned long sum = 0;
  for (unsigned long i = 0; i < n; i++) {
    benchmark::DoNotOptimize(sum++);
    benchmark::ClobberMemory();
  }
  return sum;
}

// A Benchmark for Increment
static void BM_Increment(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    Increment(state.range(0));
  }
}

// Register the function as a benchmark
BENCHMARK(BM_Increment)->RangeMultiplier(2)->Range(256, 1024);

// Run the benchmark
BENCHMARK_MAIN();