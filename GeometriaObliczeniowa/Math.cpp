#include "Math.h"

// FPoint

void FPoint::operator*=(float num)
{
    x *= num;
    y *= num;
}

FPoint operator+(const FPoint& a, const FPoint& b)
{
    return FPoint{ 0, a.x + b.x, a.y + b.y };
}

FPoint operator-(const FPoint& a, const FPoint& b)
{
    return FPoint{ 0, a.x - b.x, a.y - b.y };
}

FPoint operator*(const FPoint& a, float num)
{
    return FPoint{ 0, a.x * num, a.y * num };
}

std::ostream& operator<<(std::ostream& os, const FPoint& p)
{
    os << "id: " << p.id << " x: " << p.x << " y: " << p.y;
    return os;
}

// Point

void Point::operator*=(float num)
{
    x = static_cast<int>(x * num);
    y = static_cast<int>(y * num);
}

Point operator+(const Point& a, const Point& b)
{
    return Point{ 0, a.x + b.x, a.y + b.y };
}

Point operator-(const Point& a, const Point& b)
{
    return Point{ 0, a.x - b.x, a.y - b.y };
}

Point operator*(const Point& a, float num)
{
    return Point{ 0, static_cast<int>(a.x * num), static_cast<int>(a.y * num) };
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "id: " << p.id << " x: " << p.x << " y: " << p.y;
    return os;
}

// Lines

std::ostream& operator<<(std::ostream& os, const SegmentLine& l)
{
    os << "beginning: " << l.beginning << " end: " << l.end;
    return os;
}

std::ostream& operator<<(std::ostream& os, const indexLine& l)
{
    os << "id: " << l.id << " id_beginning: " << l.id_beginning << " id_end: " << l.id_end;
    return os;
}

//std::ostream& operator<<(std::ostream& os, const Line& l)
//{
//    os << "y = " << l.a << "x + " << l.b;
//    return os;
//}

bool isPointOnLine(Point p, SegmentLine l)
{
	return (l.end.x - l.beginning.x) * (p.y - l.beginning.y) == (l.end.y - l.beginning.y) * (p.x - l.beginning.x);
}

bool isPointOnLineSegment(Point p, SegmentLine l)
{
	return isPointOnLine(p, l)
        && p.x >= std::min(l.beginning.x, l.end.x)
        && p.x <= std::max(l.beginning.x, l.end.x) 
	    && p.y >= std::min(l.beginning.y, l.end.y)
		&& p.y <= std::max(l.beginning.y, l.end.y);
}

bool isPointOnLeftSideOfLine(Point p, SegmentLine l)
{
	float position = (l.end.x - l.beginning.x) * (p.y - l.beginning.y) - (l.end.y - l.beginning.y) * (p.x - l.beginning.x);
	return position < 0;
}

bool isPointOnRightSideOfLine(Point p, SegmentLine l)
{ 
    return !isPointOnLeftSideOfLine(p,l);
}

void moveLineByVector(SegmentLine& l, Point v)
{
    l.beginning = l.beginning + v;
	l.end = l.end + v;
}

void mirrorPointOnLine(Point& p, SegmentLine l)
{
    float a = l.end.y - l.beginning.y;
    float b = l.beginning.x - l.end.x;
    float c = l.end.x * l.beginning.y - l.beginning.x * l.end.y;
    float d = (a * p.x + b * p.y + c) / (a * a + b * b);
    p.x = static_cast<int>(p.x - 2 * a * d);
	p.y = static_cast<int>(p.y - 2 * b * d);
}

float SegmentLine::operator()(float x) const
{
	return (static_cast<float>(end.y - beginning.y) / (end.x - beginning.x)) * x + end.y - (static_cast<float>(end.y - beginning.y) / (end.x - beginning.x)) * end.x;
}

