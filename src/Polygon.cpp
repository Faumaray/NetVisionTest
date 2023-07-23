#include "Polygon.hpp"

#include <cmath>
#include <ranges>


Polygon::Polygon(const std::vector<Point>& vertices) : vertices_(vertices) {}

bool Polygon::isInside(const Point& p) const {
    auto n = vertices_.size();
    if (n < 3)
        return false;

    int windingNumber = 0;
    for (std::vector<Point>::size_type i = 0, j = n - 1; i < n; j = i++) {
        const Point& vertexI = vertices_[i];
        const Point& vertexJ = vertices_[j];

        // Проверка если на границе
        if ((p - vertexI).norm() <= std::numeric_limits<double>::epsilon() || (p - vertexJ).norm() <= std::numeric_limits<double>::epsilon()) {
            return true;  
        }

        // Восходящее пересечение
        if (vertexI.getY() <= p.getY()) {
            if (vertexJ.getY() > p.getY() && ((vertexJ - vertexI) ^ (p - vertexI)) > 0) {
                windingNumber++;
            }
        }
        // Нисходящее пересечение
        else {
            if (vertexJ.getY() <= p.getY() && ((vertexJ - vertexI) ^ (p - vertexI)) < 0) {
                windingNumber--;
            }
        }
    }

    return windingNumber != 0;
}

int Polygon::getSegmentStatus(const Segment& segment) const {
    bool p1Inside = isInside(segment.getP1());
    bool p2Inside = isInside(segment.getP2());

    if (p1Inside && p2Inside)
        return 0;
    else if (!p1Inside && !p2Inside) {
        auto n = vertices_.size();
        for (std::vector<Point>::size_type i = 0; i < n; i++) {
            Segment polySegment(vertices_[i], vertices_[(i + 1) % n]);

            // Проверка на коллинеарность
            double cross1 = (segment.getP1() - polySegment.getP1()) ^ polySegment.vector();
            double cross2 = (segment.getP2() - polySegment.getP1()) ^ polySegment.vector();
            if (std::abs(cross1) < std::numeric_limits<double>::epsilon() && std::abs(cross2) < std::numeric_limits<double>::epsilon()) {
                return 2;
            }

            if (cross1 * cross2 < -std::numeric_limits<double>::epsilon()) {
                double cross3 = (polySegment.getP1() - segment.getP1()) ^ segment.vector();
                double cross4 = (polySegment.getP2() - segment.getP1()) ^ segment.vector();
                if (cross3 * cross4 < -std::numeric_limits<double>::epsilon()) {
                    return 1;
                }
            }
        }
        return 3;
    } else {
        return 2;
    }
}
