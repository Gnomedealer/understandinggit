// Minimal test program: no framework to install. Exits non-zero on failure.
#include <cmath>
#include <iostream>
#include <stdexcept>

#include "intro/mathutils.hpp"

static int failures = 0;

#define CHECK(expr)                                                              \
    do {                                                                         \
        if (!(expr)) {                                                           \
            std::cerr << __FILE__ << ':' << __LINE__ << ": FAILED: " #expr "\n"; \
            ++failures;                                                          \
        }                                                                        \
    } while (false)

#define CHECK_THROWS(expr, exception_type)                                              \
    do {                                                                                \
        bool threw = false;                                                             \
        try {                                                                           \
            (void)(expr);                                                               \
        } catch (const exception_type&) {                                               \
            threw = true;                                                               \
        }                                                                               \
        if (!threw) {                                                                   \
            std::cerr << __FILE__ << ':' << __LINE__                                    \
                      << ": FAILED: expected " #expr " to throw " #exception_type "\n"; \
            ++failures;                                                                 \
        }                                                                               \
    } while (false)

int main() {
    using namespace intro;

    CHECK(factorial(0) == 1);
    CHECK(factorial(5) == 120);
    CHECK(factorial(20) == 2432902008176640000ULL);
    CHECK_THROWS(factorial(-1), std::out_of_range);
    CHECK_THROWS(factorial(21), std::out_of_range);

    CHECK(!is_prime(0));
    CHECK(!is_prime(1));
    CHECK(is_prime(2));
    CHECK(is_prime(97));
    CHECK(!is_prime(91));
    CHECK(is_prime(2147483647));

    CHECK(std::abs(mean({1, 2, 3, 4}) - 2.5) < 1e-12);
    CHECK_THROWS(mean({}), std::invalid_argument);

    if (failures == 0) {
        std::cout << "All tests passed\n";
        return 0;
    }
    std::cerr << failures << " check(s) failed\n";
    return 1;
}
