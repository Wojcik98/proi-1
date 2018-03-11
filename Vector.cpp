//
// Created by Wojcik98 on 06.03.18.
//

#include "Vector.h"

/**
 * @brief Vector::Vector
 * @param dim dimension of vector
 * Constructor.
 */
Vector::Vector(int dim) {
    elements = new double[dim];
    size = dim;
}

/**
 * @brief Vector::~Vector
 * Destructor.
 */
Vector::~Vector() {
    delete[] elements;
}

/**
 * @brief Vector::set
 * @param dim position
 * @param value value to set on position
 * Sets given value on given position.
 */
void Vector::set(int dim, double value) {

}

/**
 * @brief Vector::at
 * @param dim position
 * @return value at the given position
 */
double Vector::at(int dim) {

}

Vector Vector::operator+(const Vector & v) {

}

Vector & Vector::operator+=(const Vector & v) {

}

Vector Vector::operator-(const Vector & v) {

}

Vector & Vector::operator-=(const Vector & v) {

}

double Vector::operator*(const Vector & v) {

}

bool Vector::operator==(const Vector & v) {

}

bool Vector::operator!=(const Vector & v) {

}

std::ostream & operator<<(std::ostream &stream, const Vector & v) {

}

std::istream & operator>>(std::istream &stream, const Vector & v) {

}
