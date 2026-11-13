#pragma once

#include <cstdint>
#include <vector>

namespace intro {

// n! for n in [0, 20]. Throws std::out_of_range outside that range.
std::uint64_t factorial(int n);

// True if n is a prime number.
bool is_prime(std::uint64_t n);

// Arithmetic mean. Throws std::invalid_argument if values is empty.
double mean(const std::vector<double>& values);

}  // namespace intro
