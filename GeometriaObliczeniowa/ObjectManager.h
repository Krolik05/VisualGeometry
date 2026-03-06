#pragma once
#include "General.h"
#include <sstream>
#include <fstream>

class ObjectManager
{
public:
    void loadData(const char* file);
    const std::vector<Point>& getPoints();
    const std::vector<indexLine>& getLines();
    void addPoint(Point p);
    void addLine(indexLine l);

    ObjectManager()
    {
        points.reserve(20);
        lines.reserve(20);
    }


private:
    std::vector<Point> points;
    std::vector<indexLine> lines;
};

std::unique_ptr<ObjectManager> initObjectManager();
