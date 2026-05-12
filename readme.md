## API Reference

https://mccakit.github.io/nanobench/

## Documentation

https://nanobench.ankerl.com/

## Removed Stuff

### Platform / build-config gates
- `ANKERL_NANOBENCH_DISABLE_PERF_COUNTERS` opt-out — perf counters now always on for `__linux__`, always off elsewhere.
- `LINUX_VERSION_CODE >= KERNEL_VERSION(3, 3, 0)` check — Linux 3.3 is from 2012; assumed always true.
- `#include <linux/version.h>` — no longer needed without the version check.

### Diagnostic-suppression macros
- `ANKERL_NANOBENCH_PRIVATE_IGNORE_PADDED_PUSH` / `_POP` (clang `-Wpadded` suppression).
- `ANKERL_NANOBENCH_PRIVATE_IGNORE_EFFCPP_PUSH` / `_POP` (GCC `-Weffc++` suppression).
- All 28 call sites of the above.

### Compiler-attribute wrappers
- `ANKERL_NANOBENCH_PRIVATE_NOINLINE` macro — replaced with `[[gnu::noinline]]` at three call sites on `Bench::run`.

### Compatibility shims
- `ANKERL_NANOBENCH_PRIVATE_NOEXCEPT_STRING_MOVE` macro — replaced with `true` at five `noexcept(...)` sites. Worked around a fixed-long-ago GCC bug.
- `ANKERL_NANOBENCH_IS_TRIVIALLY_COPYABLE` macro — workaround for g++ < 5, was already unused.
- C++ version-detection macros (`CXX`, `CXX98`, `CXX11`, `CXX14`, `CXX17`) and the conditional around `NODISCARD` — assumed C++26.

### Versioning
- `ANKERL_NANOBENCH_VERSION_MAJOR` / `MINOR` / `PATCH` macros.
- Exported `version_major` / `version_minor` / `version_patch` constexpr ints.

### Build modes
- `ANKERL_NANOBENCH_IMPLEMENT` guard — single module unit, no header/implementation split.
- Header guards (`#ifndef ANKERL_NANOBENCH_H_INCLUDED` / `#endif`).
- `inline` keyword (12 sites) — module-internal definitions don't need it.

### Tests
- `tests/unit_templates.cpp` and its reference template files — drift-check on built-in mustache templates, no value when not editing templates.
- `tests/thirdparty/doctest/` vendored copy — doctest now consumed via pkg-config.
