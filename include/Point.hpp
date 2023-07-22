#pragma once
class Point {
public:
    Point(double x = 0, double y = 0);
    double getX() const;
    double getY() const;

    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;
    Point operator*(double scalar) const;
    double operator*(const Point& other) const; // Dot product
    double operator^(const Point& other) const; // Cross product
    double norm() const;
    double abs() const; 
    double length() const;

private:
    double x_;
    double y_;
};

