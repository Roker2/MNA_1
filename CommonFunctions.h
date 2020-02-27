#ifndef COMMONFUNCTIONS_H
#define COMMONFUNCTIONS_H

#include <QVector>
#include <cmath>

void MinMaxY(double *minY, double *maxY, QVector<double> y);
int QuadraticEquation(double a, double b, double c, int *first, int *second);

#endif // COMMONFUNCTIONS_H
