#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <math.h>
#include <cmath>
#include <thread>
#include <QPainter>
#include <QDebug>

#define _USE_MATH_DEFINES
#define EPS 1e-6

int sign(double &x);
int sign(int &x);

void drawLineBresenham(int &xStart, int &yStart, int &xEnd, int &yEnd, QPainter &painter);
void drawSector(int xCenter, int yCenter, int len, int nParts, double angleOffset, double angleSector, QPainter &painter);
void drawSectorMultiThread(int xCenter, int yCenter, int len, int nParts, double angleOffset, double angleSector, QPainter &painter, int nThreads);

#endif // ALGORITHM_H
