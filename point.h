#pragma once

#include <iostream>
#include <string>
using namespace std;

struct point
{
    point() = default;

    point(float x_, float y_) : x{x_}, y{y_}
    {
    }

    point(const point &other){
        x = other.x;
        y = other.y;
    }

    ~point(){}

    //Unary operator

    point &operator++();

    point operator++(int);

    point &operator--();

    point operator--(int);

    point operator-() const;

    //Binary operator

    //*Arithmetic
    point operator+(const point &other) const;

    point operator-(const point &other) const;

    point operator*(const point &other) const;

    point operator/(const point &other) const;

    point operator%(const point &other) const;

    // FLOAT

    point operator+(const float n) const;

    point operator-(const float n) const;

    point operator*(const float n) const;

    point operator/(const float n) const;

    point operator%(const int n) const;

    //*Relational
    bool operator<(const point &other) const;

    bool operator<=(const point &other) const;

    bool operator>(const point &other) const;

    bool operator>=(const point &other) const;

    bool operator==(const point &other) const;

    bool operator!=(const point &other) const;

    //FLOAT

    bool operator<(const float n) const;

    bool operator<=(const float n) const;

    bool operator>(const float n) const;

    bool operator>=(const float n) const;

    bool operator==(const float n) const;

    bool operator!=(const float n) const;

    //*Logical
    //Best practice is don't override this.

    //*Bitwise
    point operator<<(size_t n) const;

    point operator>>(size_t n) const;

    //*Assignment

    point &operator=(const point &other);

    point &operator+=(const point &other);

    point &operator-=(const point &other);

    point &operator*=(const point &other);

    point &operator/=(const point &other);

    point operator%=(const point &other);

    //FLOAT

    point &operator=(const float n);

    point &operator+=(const float n);

    point &operator-=(const float n);

    point &operator*=(const float n);

    point &operator/=(const float n);

    point operator%=(const int n);

    //other

    float operator[](int index) const;

    //method

public:
    void print()
    {   
        cout << ("coordinate point ") << name <<(": ")<<endl;
        cout << ("X: ") << x <<endl;
        cout << (" Y: ") << y << endl;
    }

    string name;

    float X()const{return x;}
    float Y()const{return y;}

private:
    float x;
    float y;
};