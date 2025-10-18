## libjdk

A C++ implementation of the Java Platform base module (java.base).

This project builds a portable C/C++ library that mirrors large parts of the Java SE "java.base" APIs and behaviors, with platform-specific pieces for Linux, macOS, and Windows.

### Status
- Target module: `java.base`
- Version: 17.35 (see top-level `CMakeLists.txt`)
- Platforms: Linux, macOS, Windows
- Outputs: shared and/or static library named `java.base` and a test runner

## Prerequisites
- CMake 3.12+
- C++17 compiler
  - Linux: GCC or Clang
  - macOS: Apple Clang
  - Windows: MSVC (VS 2019/2022)
- Optional: Ninja (`-G Ninja`) for faster builds

## Build

Basic out-of-source build (Release):

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIB=ON -DBUILD_TEST=ON
cmake --build build -j
```

Notes
- Default options (from `CMakeLists.txt`):
  - `BUILD_SHARED_LIB=ON`
  - `BUILD_TEST=ON`
  - `INSTALL_TO_REPO=OFF`
  - `ENABLE_NC=OFF` (enables null-check related macros when ON)
- The library output name is `java.base` (e.g., `libjava.base.so` on Linux, `java.base.dll` on Windows, `libjava.base.dylib` on macOS).

### Configure options
- `BUILD_SHARED_LIB` (ON/OFF): Build the shared library.
- `BUILD_TEST` (ON/OFF): Build the test runner and register tests with CTest.
- `INSTALL_TO_REPO` (ON/OFF): Install into a Maven-like layout under `JCPP_REPOSITORY_ROOT` or `${JCPP_HOME}/repository`.
- `ENABLE_NC` (ON/OFF): Define `JCPP_ENABLE_NC` for null checks.
- `CMAKE_BUILD_TYPE`: `Debug` or `Release` for single-config generators.
- `CMAKE_EXPORT_COMPILE_COMMANDS=ON`: Generate `compile_commands.json`.

### OS-specific link/runtime notes
- Linux: links `pthread` and `dl`; RPATH is set to `$ORIGIN;$ORIGIN/../lib` for installed artifacts.
- macOS: links CoreFoundation/Foundation/etc.; RPATH is set to `.;../lib` for installed artifacts.
- Windows: links common Win32 networking and system libs; post-build copy steps are configured for tests.

## Run tests
Build with `-DBUILD_TEST=ON` (default), then:

```bash
ctest --test-dir build -j --output-on-failure
```

Tips
- Use filters: `ctest --test-dir build -R String -j --output-on-failure`
- Some tests are OS-specific and only register on that platform.

## Install
Install to a standard prefix (default directories `include/`, `lib/`, `bin/`):

```bash
cmake --install build --prefix "$PWD/dist"
```

Install to a jcpp repository layout:

```bash
cmake -S . -B build -DINSTALL_TO_REPO=ON -DJCPP_REPOSITORY_ROOT="$HOME/jcpp/repository"
cmake --build build --target install -j
```

Folder layout when installing to repo (example):
- `${JCPP_REPOSITORY_ROOT}/java.base/17.35/include`
- `${JCPP_REPOSITORY_ROOT}/java.base/17.35/(debug/)lib`
- `${JCPP_REPOSITORY_ROOT}/java.base/17.35/(debug/)bin`

Environment variables recognized when `JCPP_REPOSITORY_ROOT` is not set:
- `JCPP_HOME` (defaults to `$HOME/jcpp` if unset)

## Package (CPack)
CPack is configured to emit archives named like:
- `${PACKAGE_NAME}-${PACKAGE_VERSION}-${JCPP_OS}-${JCPP_ARCH}`
- With `.repo` suffix when `INSTALL_TO_REPO=ON`

Create a package after configuring/building:

```bash
cpack --config build/CPackConfig.cmake
```

## Project structure
- `main/share/classes` and `main/<os>/classes`: C++ sources implementing Java packages (e.g., `java.lang`, `java.util`, `sun.*`, `jdk.internal.*`).
- `main/share/native` and `main/<os>/native`: Native helpers and third-party code (e.g., zlib, libffi, wepoll).
- `main/**/include`: Public headers installed with the library.
- `test/share/classes` and `test/<os>`: Test sources; the test runner is `${JCPP_PROJECT_FULL_NAME}-test`.
- `legal/`: Third-party notices.

## Using the library in another CMake project
After install to a prefix:

```cmake
# Example: simple manual linkage
find_library(JAVA_BASE NAMES java.base PATHS "/path/to/prefix/lib" REQUIRED)
add_executable(app main.cpp)
target_include_directories(app PRIVATE "/path/to/prefix/include")
target_link_libraries(app PRIVATE ${JAVA_BASE})
```

When installing to the jcpp repository layout, point `PATHS` to the appropriate `lib` directory under `java.base/17.35` (and add the corresponding `include` directory).

## License
- This project is licensed under GPL-2.0 with the Classpath Exception. See `LICENSE`.
- Third-party components and their licenses are documented under `legal/` and within subdirectories under `main/share/native/`.

## Acknowledgements
This work is inspired by the Java SE platform and re-implements behaviors in C/C++ for educational and systems-integration purposes.
