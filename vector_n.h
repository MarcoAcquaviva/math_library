#pragma once

#include <iostream>
#include <string>
#include "point.h"
using namespace std;


struct vector_n
{
    vector_n() = default;

    vector_n(int n,float initial)
    {
        cout<< ("Instantiate ") <<  name <<(" of ") << n << (" elements")<<endl;
        if(n>= 0){
            size = n;
            float* new_array = new float[n];
            for (size_t i = 0; i < n; i++)
            {
                new_array[i] = initial;                
            }            
            if(!memcpy(v_array, new_array, size*sizeof(float)))
            cout<< ("Error copy value btw array during initialization")<<endl;
        }
    }

    vector_n(const vector_n &other){
        size = other.size;
        float* new_array = new float[other.size];
        for (size_t i = 0; i < sizeof(other.v_array); i++)
        {
            v_array[i] = other.v_array[i];
        }
          if(!memcpy(v_array, new_array, size*sizeof(float)))
            cout<< ("Error copy value btw array during initialization")<<endl;
    }

    ~vector_n(){}

    //Unary operator

    vector_n &operator++();

    vector_n &operator++(int);

    vector_n &operator--();

    vector_n &operator--(int);

    vector_n operator-() const;

    //Binary operator

    //*Arithmetic
    vector_n operator+(const vector_n &other) const;

    vector_n operator-(const vector_n &other) const;

    vector_n operator*(const vector_n &other) const;

    vector_n operator/(const vector_n &other) const;

    vector_n operator%(const vector_n &other) const;

    //FLOAT

    vector_n operator+(const float n) const;

    vector_n operator-(const float n) const;

    vector_n operator*(const float n) const;

    vector_n operator/(const float n) const;

    vector_n operator%(const int n) const;

    //*Relational
    bool operator<(const vector_n &other) const;

    bool operator<=(const vector_n &other) const;

    bool operator>(const vector_n &other) const;

    bool operator>=(const vector_n &other) const;

    bool operator==(const vector_n &other) const;

    bool operator!=(const vector_n &other) const;

    // vector_n
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
    vector_n operator<<(size_t n) const;

    vector_n operator>>(size_t n) const;

    //*Assignment

    vector_n &operator=(const vector_n &other);

    vector_n &operator+=(const vector_n &other);

    vector_n &operator-=(const vector_n &other);

    vector_n &operator*=(const vector_n &other);

    vector_n &operator/=(const vector_n &other);

    vector_n operator%=(const vector_n &other);

    //FLOAT
    
    vector_n &operator=(const float n);

    vector_n &operator+=(const float n);

    vector_n &operator-=(const float n);

    vector_n &operator*=(const float n);

    vector_n &operator/=(const float n);

    vector_n operator%=(const int n);

    //other

    float operator[](int index) const;

    //method
public: 
    void print(){
        cout << ("Vector ") << name << (" size of")<< size<< (": ") <<endl;
        for (size_t i = 0; i < size; i++)
        {
            cout << v_array[i]<<endl;
        }
        
    }

    string name;
    int length(){return size;}

private:
    float v_array[100];
    int size;
};