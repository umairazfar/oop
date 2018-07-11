#pragma once

struct Point
{
    int x;
    int y;

    Point()
    {
        this->x = 0;
        this->y = 0;
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point(const Point& point)
    {
        x = point.x;
        y = point.y;
    }

};
