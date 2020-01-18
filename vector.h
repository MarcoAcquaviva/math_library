#pragma once

#include <iostream>
#include <string>
#include "point.h"
using namespace std;


struct vector
{
    vector() = default;

    vector(float x_, float y_, float z_) : x{x_}, y{y_},z{z_}
    {
    }

    vector(const vector &other){
        x = other.x;
        y = other.y;
        z = other.z;
    }

    ~vector(){}

    //Unary operator

    vector &operator++();

    vector operator++(int);

    vector &operator--();

    vector operator--(int);

    vector operator-() const;

    //Binary operator

    //*Arithmetic
    vector operator+(const vector &other) const;

    vector operator-(const vector &other) const;

    vector operator*(const vector &other) const;

    vector operator/(const vector &other) const;

    vector operator%(const vector &other) const;

    //POINT
    vector operator+(const point &other) const;

    vector operator-(const point &other) const;

    vector operator*(const point &other) const;

    vector operator/(const point &other) const;

    vector operator%(const point &other) const;

    //FLOAT

    vector operator+(const float n) const;

    vector operator-(const float n) const;

    vector operator*(const float n) const;

    vector operator/(const float n) const;

    vector operator%(const int n) const;

    //*Relational
    bool operator<(const vector &other) const;

    bool operator<=(const vector &other) const;

    bool operator>(const vector &other) const;

    bool operator>=(const vector &other) const;

    bool operator==(const vector &other) const;

    bool operator!=(const vector &other) const;

    // VECTOR
    bool operator< (const point &other) const;

    bool operator<=(const point &other) const;

    bool operator> (const point &other) const;

    bool operator>=(const point &other) const;

    bool operator==(const point &other) const;

    bool operator!=(const point &other) const;

    // FLOAT

    bool operator< (const float n) const;

    bool operator<=(const float n) const;

    bool operator> (const float n) const;

    bool operator>=(const float n) const;

    bool operator==(const float n) const;

    bool operator!=(const float n) const;


    //*Logical
    //Best practice is don't override this.

    //*Bitwise
    vector operator<<(size_t n) const;

    vector operator>>(size_t n) const;

    //*Assignment

    vector &operator=(const vector &other);

    vector &operator+=(const vector &other);

    vector &operator-=(const vector &other);

    vector &operator*=(const vector &other);

    vector &operator/=(const vector &other);

    vector operator%=(const vector &other);

    //POINT
    
    vector &operator=(const point &other);

    vector &operator+=(const point &other);

    vector &operator-=(const point &other);

    vector &operator*=(const point &other);

    vector &operator/=(const point &other);

    vector operator%=(const point &other);

    //FLOAT
    
    vector &operator=(const float n);

    vector &operator+=(const float n);

    vector &operator-=(const float n);

    vector &operator*=(const float n);

    vector &operator/=(const float n);

    vector operator%=(const int n);

    //other

    float operator[](int index) const;

    //method
public: 
    void print(){
        cout << ("coordinate point ") << name <<(": ")<< endl;
        cout<<("x: ")<< x << endl;
        cout<<("y: ")<< y << endl;
        cout<<("z: ")<< z << endl;
    }

    string name;
    
    float X()const{return x;}
    float Y()const{return y;}
    float Z()const{return z;}
private:
    float x;
    float y;
    float z;
};