#pragma once
#include <vector>
#include "Point.hpp"
#include "Segment.hpp"

class Polygon {
public:
    Polygon(const std::vector<Point>& vertices);
    bool isInside(const Point& p) const;
    int getSegmentStatus(const Segment& segment) const;

private:
    std::vector<Point> vertices_;
};
