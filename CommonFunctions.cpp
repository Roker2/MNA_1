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

//ax^2+bx+c=0
int QuadraticEquation(double a, double b, double c, int *first, int *second)
{
    double D = b*b - 4 * c * a;
    if (D > 0) {
        *first = (-b + sqrt(D)) / (2 * a);
        *second = (-b - sqrt(D)) / (2 * a);
    }
    else if (D == 0) {
        *first = (-b) / (2 * a);
    }
    else {
        return -1;//D < 0
    }
    return 0;//All done
}
