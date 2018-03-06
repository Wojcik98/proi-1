//
// Created by chiemsee on 06.03.18.
//

#ifndef INC_1PRJ_VECTOR_H
#define INC_1PRJ_VECTOR_H

#include <ostream>

class Vector {
public:
    Vector();
    ~Vector();

    void set(int dim, double value);
    double at(int dim);

    Vector operator+(const Vector & v);
    Vector & operator+=(const Vector & v);
    Vector operator-(const Vector & v);
    Vector & operator-=(const Vector & v);
    Vector operator*(const Vector & v);
    Vector & operator*=(const Vector & v);

    bool operator==(const Vector & v);
    bool operator!=(const Vector & v);

    friend std::ostream & operator<<(std::ostream &stream, const Vector & v);
    friend std::ostream & operator>>(const Vector & v, std::ostream &stream);
};


#endif //INC_1PRJ_VECTOR_H
