#include <benchmark/benchmark.h>
#include <string>
#include <algorithm>

using std::string;

template <typename T>
inline bool s_contains(const string &str, const T &find_val) {
    return str.find(find_val) != string::npos;
}

//* Check if string <str> contains string <find_val>, while ignoring case
inline bool s_contains_ic(const string &str, const string &find_val) {
    auto it = std::search(str.begin(), str.end(), find_val.begin(),
                          find_val.end(), [](char ch1, char ch2) {
                              return std::toupper(ch1) == std::toupper(ch2);
                          });
    return it != str.end();
}

template <class ...Args>
static void bench_s_contains(benchmark::State &state, Args&&... args) {
    auto args_tuple = std::make_tuple(std::move(args)...);
    auto haystack = std::get<0>(args_tuple), neddle = std::get<1>(args_tuple);

    for (auto _ : state) {
        auto found = s_contains(haystack, neddle);
        benchmark::DoNotOptimize(found);
    }
}

template <class ...Args>
static void bench_s_contains_ic(benchmark::State &state, Args&&... args) {
    auto args_tuple = std::make_tuple(std::move(args)...);
    auto haystack = std::get<0>(args_tuple), neddle = std::get<1>(args_tuple);

    for (auto _ : state) {
        auto found = s_contains_ic(haystack, neddle);
        benchmark::DoNotOptimize(found);
    }
}

BENCHMARK_CAPTURE(bench_s_contains, cmd_filter,
                  string("/Applications/iTerm.app/Contents/MacOS/iTerm2"),
                  string("iterm"));

BENCHMARK_CAPTURE(bench_s_contains_ic, cmd_filter,
                  string("/Applications/iTerm.app/Contents/MacOS/iTerm2"),
                  string("iterm"));

BENCHMARK_MAIN();
