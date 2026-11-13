// Lab 01: input and output.
// Copy this file (e.g. labs/lab02_loops.cpp) to start a new program;
// each .cpp file in labs/ is built as its own executable.
#include <iostream>
#include <string>

int main() {
    std::cout << "What is your name? ";
    std::string name;
    if (!std::getline(std::cin, name) || name.empty()) {
        name = "world";
    }
    std::cout << "Hello, " << name << "!\n";
    return 0;
}
