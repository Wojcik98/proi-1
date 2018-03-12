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

/**
 * @brief Vector::operator=
 * @param v vector
 * @return reference to *this
 * Copies vector v to this.
 */
Vector & Vector::operator=(const Vector &v) {
    if(this->length() != v.length()){
        this->resize(v.length());
    }

    for(int i = 0; i < this->length(); i++){
        this->set(i, v.at(i));
    }

    return *this;
}

/**
 * @brief Vector::operator+
 * @param v vector
 * @return vector with values added element-wise
 * @throws exception if vectors have different sizes
 */
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

/**
 * @brief Vector::operator+=
 * @param  v vector
 * @return reference to *this with values added element-wise
 * @throws exception if vectors have different sizes
 */
Vector & Vector::operator+=(const Vector & v) {
    if(this->length() != v.length()){
        throw "Different sizes!";
    }

    for(int i = 0; i < this->length(); i++){
        this->set(i, this->at(i) + v.at(i));
    }

    return *this;
}

/**
 * @brief Vector::operator-
 * @param v vector
 * @return vector with values subtracted element-wise
 * @throws exception if vectors have different sizes
 */
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

/**
 * @brief Vector::operator-=
 * @param  v vector
 * @return reference to *this with values subtracted element-wise
 * @throws exception if vectors have different sizes
 */
Vector & Vector::operator-=(const Vector & v) {
    if(this->length() != v.length()){
        throw "Different sizes!";
    }

    for(int i = 0; i < this->length(); i++){
        this->set(i, this->at(i) - v.at(i));
    }

    return *this;
}

/**
 * @brief Vector::operator*
 * @param v vector
 * @return value of dot product
 * @throws exception if vectors have different sizes
 */
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

/**
 * @brief Vector::operator==
 * @param v vector
 * @return true if vectors have equal length and elements
 */
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

/**
 * @brief Vector::operator!=
 * @param v vector
 * @return true if vectors have different length or elements
 */
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

/**
 * @brief Vector::operator<<
 * @param stream output stream
 * @param v vector
 * @return reference to output stream given in param
 * Writes elements of v to stream.
 */
std::ostream & operator<<(std::ostream &stream, const Vector & v) {
    for(int i = 0; i < v.length() - 1; i++){
        stream << v.at(i) << " ";
    }
    stream << v.at(v.length() - 1);

    return stream;
}

/**
 * @brief Vector::operator>>
 * @param stream input stream
 * @param v vector
 * @return reference to input stream given in param
 * Reads elements from stream to v.
 * Number of elements read from stream is equal to the size of vector.
 */
std::istream & operator>>(std::istream &stream, Vector & v) {
    for(int i = 0; i < v.length(); i++){
        double tmp;
        stream >> tmp;
        v.set(i, tmp);
    }

    return stream;
}
