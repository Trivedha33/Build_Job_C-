i#include <gtest/gtest.h>
#include "MyCode.h"
#include <stdexcept>

// Basic arithmetic tests
TEST(CalculatorTest, Addition) {
    EXPECT_EQ(Calculator::add(2, 3), 5);
    EXPECT_EQ(Calculator::add(-2, 3), 1);
    EXPECT_EQ(Calculator::add(0, 0), 0);
}

TEST(CalculatorTest, Subtraction) {
    EXPECT_EQ(Calculator::subtract(5, 3), 2);
    EXPECT_EQ(Calculator::subtract(-2, 3), -5);
    EXPECT_EQ(Calculator::subtract(0, 0), 0);
}

TEST(CalculatorTest, Multiplication) {
    EXPECT_EQ(Calculator::multiply(2, 3), 6);
    EXPECT_EQ(Calculator::multiply(-2, 3), -6);
    EXPECT_EQ(Calculator::multiply(0, 5), 0);
}

TEST(CalculatorTest, Division) {
    EXPECT_DOUBLE_EQ(Calculator::divide(6, 2), 3.0);
    EXPECT_DOUBLE_EQ(Calculator::divide(-6, 2), -3.0);
    EXPECT_THROW(Calculator::divide(5, 0), std::invalid_argument);
}

// Prime number tests
TEST(CalculatorTest, IsPrime) {
    EXPECT_FALSE(Calculator::isPrime(1));
    EXPECT_TRUE(Calculator::isPrime(2));
    EXPECT_TRUE(Calculator::isPrime(17));
    EXPECT_FALSE(Calculator::isPrime(100));
    EXPECT_FALSE(Calculator::isPrime(-5));
}

// Fibonacci tests
TEST(CalculatorTest, Fibonacci) {
    std::vector<int> expected_empty = {};
    EXPECT_EQ(Calculator::generateFibonacci(0), expected_empty);
    
    std::vector<int> expected_one = {0};
    EXPECT_EQ(Calculator::generateFibonacci(1), expected_one);
    
    std::vector<int> expected_five = {0, 1, 1, 2, 3};
    EXPECT_EQ(Calculator::generateFibonacci(5), expected_five);
}

// String reversal tests
TEST(CalculatorTest, ReverseString) {
    EXPECT_EQ(Calculator::reverseString("hello"), "olleh");
    EXPECT_EQ(Calculator::reverseString(""), "");
    EXPECT_EQ(Calculator::reverseString("a"), "a");
    EXPECT_EQ(Calculator::reverseString("12345"), "54321");
}
Last edited 17 minutes ago



