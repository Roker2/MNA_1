#include "CommonFunctions.h"

void MinMaxY(double *minY, double *maxY, QVector<double> y)
{
    *minY = y[0], *maxY = y[0];
    for(int i = 1; i < y.length(); i++)
    {
        if (y[i] < *minY)
            *minY = y[i];
        if (y[i] > *maxY)
            *maxY = y[i];
    }
}
