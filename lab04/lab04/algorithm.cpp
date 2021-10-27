#include "algorithm.h"

int sign(double &x)
{
    if (x > EPS)
        return 1;
    else if (x > -EPS)
        return 0;
    return -1;
}

int sign(int &x)
{
    if (x > 0)
        return 1;
    else if (!x)
        return 0;
    return -1;
}

void drawLineBresenham(int &xStart, int &yStart, int &xEnd, int &yEnd, QPainter &painter)
{
    int dx = xEnd - xStart;
    int dy = yEnd - yStart;
    int sx = sign(dx);
    int sy = sign(dy);
    dx = abs(dx);
    dy = abs(dy);

    bool swapFlag = false;
    if (dx < dy)
    {
        int tmp = dx;
        dx = dy;
        dy = tmp;
        swapFlag = true;
    }
    int m1 = 2 * dx, m2 = 2 * dy;
    int e = 2 * dy - dx;
    int x = xStart, y = yStart;

    for (int i = 0; i < dx; ++i)
    {
        painter.drawPoint(x, y);

        if (e > 0)
        {
            if (swapFlag)
                x += sx;
            else
                y += sy;
            e -= m1;
        }
        if (swapFlag)
            y += sy;
        else
            x += sx;
        e += m2;
    }
}

void drawSector(int xCenter, int yCenter, int len, int nParts, double angleOffset, double angleSector, QPainter &painter)
{
    double rad = 180.0 / M_PI;
    double angleIncrement = (angleSector / nParts) / rad;
    double angleRad = angleOffset / rad;
    int xEnd, yEnd;

    for (int i = 0; i <= nParts; ++i)
    {
        xEnd = xCenter + std::round(len * cos(angleRad));
        yEnd = yCenter - std::round(len * sin(angleRad));
        drawLineBresenham(xCenter, yCenter, xEnd, yEnd, painter);
        angleRad += angleIncrement;
    }
}

void drawSectorMultiThread(int xCenter, int yCenter, int len, int nParts, double angleOffset, double angleSector, QPainter &painter, int nThreads)
{
    int nPart = nParts / nThreads;
    double anglePart = angleSector / nThreads;
    std::vector<std::thread> threads(nThreads);
    for (int i = 0; i < nThreads; ++i)
        threads[i] = std::thread(drawSector, xCenter, yCenter, len, nPart, angleOffset + i*anglePart, anglePart, std::ref(painter));

    for (int i = 0; i < nThreads; ++i)
        threads[i].join();
}
