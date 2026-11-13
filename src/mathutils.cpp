#include "intro/mathutils.hpp"

#include <numeric>
#include <stdexcept>

namespace intro {

std::uint64_t factorial(int n) {
    if (n < 0 || n > 20) {
        throw std::out_of_range("factorial: n must be between 0 and 20");
    }
    std::uint64_t result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= static_cast<std::uint64_t>(i);
    }
    return result;
}

bool is_prime(std::uint64_t n) {
    if (n < 2) {
        return false;
    }
    for (std::uint64_t d = 2; d <= n / d; ++d) {
        if (n % d == 0) {
            return false;
        }
    }
    return true;
}

double mean(const std::vector<double>& values) {
    if (values.empty()) {
        throw std::invalid_argument("mean: values must not be empty");
    }
    return std::accumulate(values.begin(), values.end(), 0.0) / static_cast<double>(values.size());
}

}  // namespace intro
