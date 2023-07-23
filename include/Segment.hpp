#pragma once
#include "Point.hpp"

class Segment {
public:
    Segment(const Point& p1, const Point& p2);
    const Point& getP1() const;
    const Point& getP2() const;

    Point vector() const;
    double operator*(const Segment& other) const; // Dot product
    double operator^(const Segment& other) const; // Cross product
    double norm() const;
    double abs() const;
    double length() const;

private:
    Point p1_;
    Point p2_;
};
