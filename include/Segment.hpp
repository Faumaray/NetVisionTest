#pragma once
#include "Point.hpp"

class Segment {
public:
    Segment(const Point& p1, const Point& p2);
    const Point& getP1() const;
    const Point& getP2() const;

    Point vector() const;
    double norm() const;
    double abs() const;
    double length() const;
    double dot(const Segment& other) const;
    double cross(const Segment& other) const;

private:
    Point p1_;
    Point p2_;
};
