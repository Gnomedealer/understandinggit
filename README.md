# IntroComSciStuff

A C++20 workspace for intro computer science coursework: a ready-to-build project
with strict compiler warnings, memory-error checking, tests, formatting, and CI.

## Setup

Install the toolchain (compiler, CMake, Ninja, debugger, formatter):

```sh
./scripts/setup.sh
```

Works on Debian/Ubuntu (including WSL on Windows), Fedora, Arch, and macOS with
Homebrew. Alternatively, open the repo in GitHub Codespaces or a VS Code Dev
Container — `.devcontainer/` installs everything for you.

## Build, run, test

```sh
cmake --preset debug            # configure (once)
cmake --build --preset debug    # compile
./build/debug/app               # run the demo app
./build/debug/labs/lab01_hello  # run a lab program
ctest --preset debug            # run the tests
```

The `debug` preset turns on AddressSanitizer and UBSan, which stop the program
with a clear report on out-of-bounds access, use-after-free, leaks, and integer
overflow. Use `release` instead of `debug` for an optimized build.

## Layout

| Path | Purpose |
| --- | --- |
| `labs/` | One-file programs. Every `labs/<name>.cpp` builds to `build/<preset>/labs/<name>`. |
| `include/intro/`, `src/` | Reusable code (the `intro` library) and the demo `app`. |
| `tests/` | Tests, run with `ctest`. |
| `scripts/setup.sh` | Toolchain installer. |
| `.github/workflows/ci.yml` | Builds and tests with GCC and Clang on every push. |

## Adding a new program

Create `labs/lab02_something.cpp` with a `main()`, then rebuild. No CMake edits
needed.

## Formatting and linting

```sh
git ls-files '*.cpp' '*.hpp' | xargs clang-format -i
clang-tidy -p build/debug src/*.cpp labs/*.cpp
```

## License

This project's code is released under the [MIT License](LICENSE).

The tools themselves are free to use and carry their own licenses: GCC is
GPLv3 with the GCC Runtime Library Exception (programs you compile with it are
not subject to the GPL), Clang/LLVM is Apache 2.0 with LLVM Exceptions, and
CMake is BSD 3-Clause.
