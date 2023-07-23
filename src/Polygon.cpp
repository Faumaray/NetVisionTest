#include "Polygon.hpp"

#include <cmath>
#include <ranges>
#include <algorithm>

Polygon::Polygon(const std::vector<Point>& vertices) : vertices_(vertices) {
}


bool Polygon::isInside(const Point& p) const {
    int n = vertices_.size();
    if (n < 3)
        return false;

    bool isInside = false;

    for (int i = 0; i < n; i++) {
        const Point& vertexI = vertices_[i];
        const Point& vertexJ = vertices_[(i+1)%n];

        auto isYBetweenVertices = ((vertexI.getY() > p.getY()) != (vertexJ.getY() > p.getY()));
        auto isXToTheLeft = (p.getX() < (vertexJ.getX() - vertexI.getX()) * (p.getY() - vertexI.getY()) /
                          (vertexJ.getY() - vertexI.getY()) + vertexI.getX());

        if (isYBetweenVertices && isXToTheLeft) {
            isInside = !isInside;
        }
    }

    for (int i = 0; i < n; i++) {
        Segment edge(vertices_[i], vertices_[(i + 1) % n]);

        double cross = (p - edge.getP1()) ^ edge.vector();
        double dot = (p - edge.getP1()) * edge.vector();

        auto isOnEdge = std::abs(cross) < std::numeric_limits<double>::epsilon();
        auto isDotProductInRange = dot >= -std::numeric_limits<double>::epsilon() &&
                                   dot <= edge.norm() + std::numeric_limits<double>::epsilon();

        if (isOnEdge && isDotProductInRange) {

            return true;
        }
    }

    return isInside;
}




int Polygon::getSegmentStatus(const Segment& segment) const {
    bool p1Inside = isInside(segment.getP1());
    bool p2Inside = isInside(segment.getP2());

    if (p1Inside && p2Inside)
        return 0;
    else if (!p1Inside && !p2Inside) {
        auto n = vertices_.size();
        for (std::vector<Point>::size_type i = 0; i < n; i++) {
            Segment edge(vertices_[i], vertices_[(i + 1) % n]);

            double crossP1 = (segment.getP1() - edge.getP1()) ^ edge.vector();
            double crossP2 = (segment.getP2() - edge.getP1()) ^ edge.vector();
            double crossEdgeStart = (edge.getP1() - segment.getP1()) ^ segment.vector();
            double crossEdgeEnd = (edge.getP2() - segment.getP1()) ^ segment.vector();

            auto isSegmentCrossing = (crossP1 * crossP2) <= -std::numeric_limits<double>::epsilon()
                && (crossEdgeStart * crossEdgeEnd) <= -std::numeric_limits<double>::epsilon();

            auto isSegmentOnEdge = std::abs(crossP1) <= std::numeric_limits<double>::epsilon() 
                && std::abs(crossP2) <= std::numeric_limits<double>::epsilon() 
                && std::abs(crossEdgeStart) <= std::numeric_limits<double>::epsilon() 
                && std::abs(crossEdgeEnd) <= std::numeric_limits<double>::epsilon();
            
            if (isSegmentCrossing || isSegmentOnEdge) {
                    return 1;
            }
        }
        return 3;
    } else {
        return 2;
    }
}
