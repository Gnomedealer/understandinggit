#!/usr/bin/env bash
# Installs the C++ toolchain this project uses.
# Supports Debian/Ubuntu (incl. WSL), Fedora, Arch, and macOS (Homebrew).
set -euo pipefail

SUDO=""
if [ "$(id -u)" -ne 0 ]; then SUDO="sudo"; fi

if command -v apt-get >/dev/null 2>&1; then
    $SUDO apt-get update
    $SUDO apt-get install -y build-essential g++ clang libclang-rt-dev cmake ninja-build gdb valgrind \
        clang-format clang-tidy git
elif command -v dnf >/dev/null 2>&1; then
    $SUDO dnf install -y gcc-c++ clang cmake ninja-build gdb valgrind clang-tools-extra git
elif command -v pacman >/dev/null 2>&1; then
    $SUDO pacman -S --needed --noconfirm base-devel clang cmake ninja gdb valgrind git
elif command -v brew >/dev/null 2>&1; then
    xcode-select -p >/dev/null 2>&1 || xcode-select --install || true
    brew install cmake ninja llvm clang-format
else
    echo "Unsupported system. Install manually: a C++20 compiler, CMake >= 3.20, Ninja." >&2
    exit 1
fi

echo
echo "Installed versions:"
for tool in g++ clang++ cmake ninja gdb; do
    if command -v "$tool" >/dev/null 2>&1; then
        printf '  %-8s %s\n' "$tool" "$("$tool" --version | head -n 1)"
    fi
done
