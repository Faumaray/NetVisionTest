#include <gtest/gtest.h>
#include "Polygon.hpp"
#include "Segment.hpp"

TEST(PolygonTest, ComplexPolygon) {
    std::vector<Point> vertices = {
        {0.0, 0.0},
        {4.0, 0.0},
        {3.0, 2.0},
        {4.0, 4.0},
        {2.0, 3.0},
        {0.0, 4.0}
    };

    Polygon polygon(vertices);

    Segment segment1({1.0, 1.0}, {3.0, 3.0});
    Segment segment2({2.5, 2.5}, {5.0, 5.0});
    Segment segment3({0.0, 3.0}, {5.0, 1.0});

    EXPECT_EQ(polygon.getSegmentStatus(segment1), 0); // Внутри
    EXPECT_EQ(polygon.getSegmentStatus(segment2), 2); // Частично
    EXPECT_EQ(polygon.getSegmentStatus(segment3), 2); // Частично
}

TEST(PolygonTest, SimplePolygon) {
    std::vector<Point> vertices = {
        {0.0, 0.0},
        {4.0, 0.0},
        {4.0, 4.0},
        {0.0, 4.0}
    };

    Polygon polygon(vertices);

    Segment segment1({1.0, 1.0}, {3.0, 3.0});
    Segment segment2({2.5, 2.5}, {5.0, 5.0});
    Segment segment3({0.0, 3.0}, {5.0, 1.0});

    EXPECT_EQ(polygon.getSegmentStatus(segment1), 0); // Внутри
    EXPECT_EQ(polygon.getSegmentStatus(segment2), 2); // Частично
    EXPECT_EQ(polygon.getSegmentStatus(segment3), 2); // Частично
}
TEST(PolygonTest, RegularPolygon) {
    std::vector<Point> vertices = {
        {0.0, 3.0},
        {2.598076, 1.5},
        {2.598076, -1.5},
        {0.0, -3.0},
        {-2.598076, -1.5},
        {-2.598076, 1.5}
    };

    Polygon polygon(vertices);

    // Define segments
    Segment segment1({-1.5, 0.0}, {1.5, 0.0});
    Segment segment2({-2.0, 0.0}, {2.0, 0.0});
    Segment segment3({0.0, 0.0}, {3.0, 0.0});
    Segment segment4({0.0, 0.0}, {0.0, 2.0});
    Segment segment5({-2.5, -1.0}, {2.5, -1.0});

    EXPECT_EQ(polygon.getSegmentStatus(segment1), 0); // Внутри
    EXPECT_EQ(polygon.getSegmentStatus(segment2), 0); // Внутри
    EXPECT_EQ(polygon.getSegmentStatus(segment3), 2); // Частично
    EXPECT_EQ(polygon.getSegmentStatus(segment4), 0); // Внутри
    EXPECT_EQ(polygon.getSegmentStatus(segment5), 0); // Внутри на границе
}

TEST(PolygonTest, ConcavePolygon) {
    std::vector<Point> vertices = {
        {0.0, 0.0},
        {4.0, 0.0},
        {2.0, 4.0},
        {1.0, 2.0},
        {3.0, 2.0}
    };

    Polygon polygon(vertices);

    Segment segment1({1.0, 1.0}, {3.0, 3.0});
    Segment segment2({2.5, 2.5}, {5.0, 5.0});
    Segment segment3({0.0, 3.0}, {5.0, 1.0});

    EXPECT_EQ(polygon.getSegmentStatus(segment1), 1); // Пересекает
    EXPECT_EQ(polygon.getSegmentStatus(segment2), 2); // Частично
    EXPECT_EQ(polygon.getSegmentStatus(segment3), 1); // Пересекает
}

TEST(PolygonTest, EmptyPolygon) {
    std::vector<Point> vertices = {};

    Polygon polygon(vertices);

    // Define segments
    Segment segment1({1.0, 1.0}, {3.0, 3.0});
    Segment segment2({2.5, 2.5}, {5.0, 5.0});

    EXPECT_EQ(polygon.getSegmentStatus(segment1), 3); 
    EXPECT_EQ(polygon.getSegmentStatus(segment2), 3);
}


// INFO: особенный случай т.к. все это можно определить и как внутри и как частичное пересечение
TEST(PolygonTest, DegeneratePolygon) {
    std::vector<Point> vertices = {
        {0.0, 0.0},
        {2.0, 0.0},
        {4.0, 0.0},
        {6.0, 0.0}
    };

    Polygon polygon(vertices);

    Segment segment1({1.0, 0.0}, {3.0, 0.0});
    Segment segment2({0.0, 0.0}, {4.0, 0.0});
    Segment segment3({3.0, 0.0}, {6.0, 0.0});

    EXPECT_EQ(polygon.getSegmentStatus(segment1), 0); // Частично
    EXPECT_EQ(polygon.getSegmentStatus(segment2), 0); // Внутри
    EXPECT_EQ(polygon.getSegmentStatus(segment3), 0); // Частично
}


// INFO: особенный случай т.к. все это можно определить и как внутри и как частичное пересечение
TEST(PolygonTest, CollinPolygon) {
    std::vector<Point> vertices = {
        {0.0, 3.0},
        {2.6, 1.5},
        {2.6, -1.5},
        {0.0, -3.0},
        {-2.6, -1.5},
        {-2.6, 1.5}
    };

    Polygon polygon(vertices);

    Segment segment1({2.6, 1.8}, {2.6, -1.8});
    Segment segment2({2.6, 1.8}, {2.6, -1.5});
    Segment segment3({-1.0, 3.2}, {2.6, 1.5});
    Segment segment4({-1.0, 3.2}, {3.0, 1.3});
    Segment segment5({-1.0, 4.2}, {4.0, 1.3});

    EXPECT_EQ(polygon.getSegmentStatus(segment1), 1); // Частично
    EXPECT_EQ(polygon.getSegmentStatus(segment2), 2); // Внутри
    EXPECT_EQ(polygon.getSegmentStatus(segment3), 2); // Частично
    EXPECT_EQ(polygon.getSegmentStatus(segment4), 1); // Частично
    EXPECT_EQ(polygon.getSegmentStatus(segment5), 3); // Частично
}
