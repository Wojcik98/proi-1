//
// Created by Wojcik98 on 06.03.18.
//

#ifndef INC_1PRJ_VECTOR_H
#define INC_1PRJ_VECTOR_H

#include <iostream>

class Vector {
public:
    explicit Vector(int dim);
    ~Vector();

    void set(int dim, double value);
    double at(int dim) const;

    int length() const;
    void resize(int newSize);

    Vector & operator=(const Vector & v);
    Vector operator+(const Vector & v);
    Vector & operator+=(const Vector & v);
    Vector operator-(const Vector & v);
    Vector & operator-=(const Vector & v);
    double operator*(const Vector & v);

    bool operator==(const Vector & v);
    bool operator!=(const Vector & v);

    friend std::ostream & operator<<(std::ostream &stream, const Vector & v);
    friend std::istream & operator>>(std::istream &stream, Vector & v);

private:
    int size;
    double* elements;
};


#endif //INC_1PRJ_VECTOR_H
