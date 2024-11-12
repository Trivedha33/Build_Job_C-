#ifndef MYCODE_H
#define MYCODE_H

#include <string>
#include <vector>

class Calculator {
public:
    // Basic arithmetic operations
    static int add(int a, int b);
    static int subtract(int a, int b);
    static int multiply(int a, int b);
    static double divide(double a, double b);
    
    // More complex operations to demonstrate coverage
    static bool isPrime(int number);
    static std::vector<int> generateFibonacci(int n);
    static std::string reverseString(const std::string& input);
};

#endif // MYCODE_H
