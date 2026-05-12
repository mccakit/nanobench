#include <doctest/doctest.h>
#include "test_macros.hpp"
import std;
import nanobench;

// NOLINTNEXTLINE
TEST_CASE("tutorial_fast_v1") {
    uint64_t x = 1;
    ankerl::nanobench::Bench().run("++x", [&]() {
        ++x;
    });
}
