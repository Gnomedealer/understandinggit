#include <iostream>

#include "intro/mathutils.hpp"

int main() {
    std::cout << "Hello from IntroComSciStuff!\n";
    std::cout << "5! = " << intro::factorial(5) << '\n';
    std::cout << "Is 97 prime? " << (intro::is_prime(97) ? "yes" : "no") << '\n';
    std::cout << "Mean of 1, 2, 3, 4 = " << intro::mean({1, 2, 3, 4}) << '\n';
    return 0;
}
