#include <iostream>
#include <sstream>
#include <cassert>
#include <memory>
#include <cmath>

#include "test.h"
#include "Vector.h"

#define FEQUAL(a, b) (std::fabs((a) - (b)) < 0.000001)  //compares two floating point numbers

int main() {
    std::cout << "Running tests...\n";
    testCreation();
    testAccess();

    testAdding();
    testSubtracting();
    testMultiplication();
    testEquality();

    testInput();
    testOutput();

    std::cout << "All tests passed!\n";

    return 0;
}

void testCreation() {
    std::cout << "Running testCreation...";

    std::unique_ptr<Vector> v(new Vector(3));
    assert(v != nullptr);

    std::cout << "passed!\n";
}

void testAccess(){
    std::cout << "Running testAccess...";

    Vector v(3);
    v.set(1, 5.);
    assert(FEQUAL(v.at(1), 5.));    //it's not good idea to compare floating point numbers with ==

    bool caughtException = false;
    try {
        v.set(5, 5.);
    } catch(...){
        caughtException = true;
    }
    assert(caughtException);

    caughtException = false;
    try {
        v.at(5);
    } catch(...){
        caughtException = true;
    }
    assert(caughtException);

    std::cout << "passed!\n";
}

void testAdding() {
    std::cout << "Running testAdding...";

    Vector v(3), u(3);
    v.set(0, 1); v.set(1, 2); v.set(2, 3);
    u.set(0, 10); u.set(1, 11); u.set(2, 12);

    Vector sum(3);
    sum = u + v;
    assert(FEQUAL(sum.at(0), 11.) && FEQUAL(sum.at(1), 13.) && FEQUAL(sum.at(2), 15.));

    sum += v;
    assert(FEQUAL(sum.at(0), 12.) && FEQUAL(sum.at(1), 15.) && FEQUAL(sum.at(2), 18.));

    std::cout << "passed!\n";
}

void testSubtracting() {
    std::cout << "Running testSubtracting...";

    Vector v(3), u(3);
    v.set(0, 1); v.set(1, 2); v.set(2, 3);
    u.set(0, 10); u.set(1, 9); u.set(2, 8);

    Vector sum(3);
    sum = v - u;
    assert(FEQUAL(sum.at(0), -9.) && FEQUAL(sum.at(1), -7.) && FEQUAL(sum.at(2), -5.));

    sum -= v;
    assert(FEQUAL(sum.at(0), -10.) && FEQUAL(sum.at(1), -9.) && FEQUAL(sum.at(2), -8.));

    std::cout << "passed!\n";
}

void testMultiplication() {
    std::cout << "Running testMultiplication...";

    Vector v(3), u(3);
    v.set(0, 1); v.set(1, 2); v.set(2, 3);
    u.set(0, 10); u.set(1, 9); u.set(2, 8);

    double result = u*v;

    assert(FEQUAL(result, 52.));

    std::cout << "passed!\n";
}

void testEquality() {
    std::cout << "Running testEquality...";

    Vector v(3), u(3);
    v.set(0, 1); v.set(1, 2); v.set(2, 3);
    u.set(0, 10); u.set(1, 9); u.set(2, 8);

    assert(u != v);

    u.set(0, 1); u.set(1, 2); u.set(2, 3);
    assert(u == v);

    std::cout << "passed!\n";
}

void testInput() {
    std::cout << "Running testInput...";

    Vector v(3);
    std::stringstream stream;
    stream << "1.2 3.4 5.6";
    stream >> v;
    assert(FEQUAL(v.at(0), 1.2) && FEQUAL(v.at(2), 3.4) && FEQUAL(v.at(2), 5.6));

    std::cout << "passed!\n";
}

void testOutput() {
    std::cout << "Running testOutput...";

    Vector v(3);
    v.set(0, 1.2); v.set(1, 2.3); v.set(2, 3.4);
    std::stringstream stream;
    stream << v;
    assert(stream.str() == "1.2 3.4 5.6");

    std::cout << "passed!\n";
}
