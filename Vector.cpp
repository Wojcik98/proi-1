//
// Created by Wojcik98 on 06.03.18.
//

#include "Vector.h"
#include <iostream>

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
    if(dim < size){
        elements[dim] = value;
    } else{
        throw "Range exceeded!";
    }
}

/**
 * @brief Vector::at
 * @param dim position
 * @return value at the given position
 */
double Vector::at(int dim) const {
    if(dim < size){
        return elements[dim];
    } else{
        throw "Range exceeded!";
    }
}

/**
 * @brief Vector::length
 * @return size of vector
 */
int Vector::length() const {
    return size;
}

/**
 * @brief Vector::resize
 * @param newSize new size of vector
 * Resizes vector to given size deleting all existing elements.
 */
void Vector::resize(int newSize) {
    delete[] elements;
    elements = new double[newSize];
    size = newSize;
}

Vector & Vector::operator=(const Vector &v) {
    if(this->length() != v.length()){
        this->resize(v.length());
    }

    for(int i = 0; i < this->length(); i++){
        this->set(i, v.at(i));
    }

    return *this;
}

Vector Vector::operator+(const Vector & v) {
    if(this->length() != v.length()){
        throw "Different sizes!";
    }

    Vector u(this->length());
    for(int i = 0; i < this->length(); i++){
        u.set(i, this->at(i) + v.at(i));
    }

    return u;
}

Vector & Vector::operator+=(const Vector & v) {
    if(this->length() != v.length()){
        throw "Different sizes!";
    }

    for(int i = 0; i < this->length(); i++){
        this->set(i, this->at(i) + v.at(i));
    }

    return *this;
}

Vector Vector::operator-(const Vector & v) {
    if(this->length() != v.length()){
        throw "Different sizes!";
    }

    Vector u(this->length());
    for(int i = 0; i < this->length(); i++){
        u.set(i, this->at(i) - v.at(i));
    }

    return u;
}

Vector & Vector::operator-=(const Vector & v) {
    if(this->length() != v.length()){
        throw "Different sizes!";
    }

    for(int i = 0; i < this->length(); i++){
        this->set(i, this->at(i) - v.at(i));
    }

    return *this;
}

double Vector::operator*(const Vector & v) {
    if(this->length() != v.length()){
        throw "Different sizes!";
    }

    double result = 0.;
    for(int i = 0; i < this->length(); i++){
        result += this->at(i) * v.at(i);
    }

    return result;
}

bool Vector::operator==(const Vector & v) {
    if(this->length() != v.length()){
        return false;
    }
    const double EPS = 0.000000001;
    for(int i = 0; i < this->length(); i++){
        double value = this->at(i) - v.at(i);
        if(!(-EPS < value && value < EPS)){
            return false;
        }
    }

    return true;
}

bool Vector::operator!=(const Vector & v) {
    if(this->length() != v.length()){
        return true;
    }
    const double EPS = 0.000000001;
    for(int i = 0; i < this->length(); i++){
        double value = this->at(i) - v.at(i);
        if(-EPS < value && value < EPS){
            return false;
        }
    }

    return true;
}

std::ostream & operator<<(std::ostream &stream, const Vector & v) {
    for(int i = 0; i < v.length() - 1; i++){
        stream << v.at(i) << " ";
    }
    stream << v.at(v.length() - 1);
}

std::istream & operator>>(std::istream &stream, const Vector & v) {

}
