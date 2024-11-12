#include "MyCode.h"
#include <iostream>

int main() {
    // Example usage of the Calculator class
    try {
        std::cout << "10 + 5 = " << Calculator::add(10, 5) << std::endl;
        std::cout << "10 - 5 = " << Calculator::subtract(10, 5) << std::endl;
        std::cout << "10 * 5 = " << Calculator::multiply(10, 5) << std::endl;
        std::cout << "10 / 5 = " << Calculator::divide(10, 5) << std::endl;
        
        std::cout << "Is 17 prime? " << (Calculator::isPrime(17) ? "Yes" : "No") << std::endl;
        
        auto fib = Calculator::generateFibonacci(5);
        std::cout << "First 5 Fibonacci numbers: ";
        for (int num : fib) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Reverse of 'Hello': " << Calculator::reverseString("Hello") << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}



