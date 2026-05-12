#include <doctest/doctest.h>
#include "test_macros.hpp"
import std;
import nanobench;

// NOLINTNEXTLINE
TEST_CASE("tutorial_slow_v2") {
    ankerl::nanobench::Bench().epochs(3).run("sleep 100ms", [&] {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    });
}
