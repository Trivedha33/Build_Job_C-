#include "MyCode.h"
#include <stdexcept>

int Calculator::add(int a, int b) {
    return a + b;
}

int Calculator::subtract(int a, int b) {
    return a - b;
}

int Calculator::multiply(int a, int b) {
    return a * b;
}

double Calculator::divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}

bool Calculator::isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

std::vector<int> Calculator::generateFibonacci(int n) {
    if (n <= 0) {
        return std::vector<int>();
    }
    
    std::vector<int> result;
    result.push_back(0);
    
    if (n == 1) {
        return result;
    }
    
    result.push_back(1);
    for (int i = 2; i < n; i++) {
        result.push_back(result[i-1] + result[i-2]);
    }
    return result;
}

std::string Calculator::reverseString(const std::string& input) {
    return std::string(input.rbegin(), input.rend());
}
