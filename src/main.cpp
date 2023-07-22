#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>
#include "Point.hpp"
#include "Polygon.hpp"
#include "Segment.hpp"

std::vector<Point> readPointsFromFile(const std::filesystem::path& filename) {
    std::vector<Point> points;
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return points;
    }

    double x, y;
    char comma;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        while (iss >> x >> comma >> y) {
            points.emplace_back(x, y);
        }
    }

    inputFile.close();
    return points;
}

std::vector<Segment> readSegmentsFromFile(const std::filesystem::path& filename) {
    std::vector<Segment> segments;
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return segments;
    }

    double x1, y1, x2, y2;
    char comma;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        iss >> x1 >> comma >> y1 >> x2 >> comma >> y2;
        segments.emplace_back(Point(x1, y1), Point(x2, y2));
    }

    inputFile.close();
    return segments;
}

void writeResultsToFile(const std::filesystem::path& filename, const std::vector<int>& results) {
    std::ofstream outputFile(filename);
    if (!outputFile) {
        std::cerr << "Error creating file: " << filename << std::endl;
        return;
    }

    for (int result : results) {
        outputFile << result << std::endl;
    }

    outputFile.close();
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <polys_filename> <lines_filename>" << std::endl;
        return 1;
    }

    const std::filesystem::path polysFilename = argv[1];
    const std::filesystem::path linesFilename = argv[2];

    if (!std::filesystem::exists(polysFilename) || !std::filesystem::exists(linesFilename)) {
        std::cerr << "One or both files do not exist." << std::endl;
        return 1;
    }
    std::vector<Point> polygonVertices = readPointsFromFile(polysFilename);
    if (polygonVertices.empty()) {
        std::cerr << "Failed to read polygon vertices." << std::endl;
        return 1;
    }

    Polygon polygon(polygonVertices);

    std::vector<Segment> segments = readSegmentsFromFile(linesFilename);
    if (segments.empty()) {
        std::cerr << "Failed to read segments." << std::endl;
        return 1;
    }

    std::vector<int> results;
    for (const Segment& segment : segments) {
        int status = polygon.getSegmentStatus(segment);
        results.push_back(status);
    }

    writeResultsToFile("results.txt", results);

    std::cout << "Results written to results.txt" << std::endl;

    return 0;
}

