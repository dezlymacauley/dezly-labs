#include <print>
using std::println;

int main() {

    int num1 = 11;

    // Pass by value
    // num2 gets its own copy of the value of num1.
    int num2 = num1;

    println("num1: {}", num1);
    println("num2: {}", num2);
    // num1: 11
    // num2: 11

    return 0;
}
