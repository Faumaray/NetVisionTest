#include "Segment.hpp"
#include <cmath>

Segment::Segment(const Point& p1, const Point& p2) : p1_(p1), p2_(p2) {}

const Point& Segment::getP1() const {
    return p1_;
}

const Point& Segment::getP2() const {
    return p2_;
}

Point Segment::vector() const {
    return p2_ - p1_;
}

double Segment::norm() const {
    return vector().norm();
}

double Segment::abs() const {
    return std::sqrt(norm());
}

double Segment::length() const {
    return abs();
}

double Segment::operator*(const Segment& other) const {
    return vector() * other.vector();
}

double Segment::operator^(const Segment& other) const {
    return vector() ^ other.vector();
}
