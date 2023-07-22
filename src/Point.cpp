#include "Point.hpp"
#include <cmath>

Point::Point(double x, double y) : x_(x), y_(y) {}

double Point::getX() const {
    return x_;
}

double Point::getY() const {
    return y_;
}

Point Point::operator+(const Point& other) const {
    return Point(x_ + other.x_, y_ + other.y_);
}

Point Point::operator-(const Point& other) const {
    return Point(x_ - other.x_, y_ - other.y_);
}

Point Point::operator*(double scalar) const {
    return Point(x_ * scalar, y_ * scalar);
}

double Point::operator*(const Point& other) const {
    return x_ * other.x_ + y_ * other.y_;
}

double Point::operator^(const Point& other) const {
    return x_ * other.y_ - y_ * other.x_;
}

double Point::norm() const {
    return x_ * x_ + y_ * y_;
}

double Point::abs() const {
    return std::sqrt(norm());
}

double Point::length() const {
    return abs();
}
