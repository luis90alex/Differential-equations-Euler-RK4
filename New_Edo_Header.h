#ifndef NEW_EDO_HEADER_H_INCLUDED
#define NEW_EDO_HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <locale.h>

void EULER(double sigma, double b, double r, double x0, double y0, double z0);
void RK4(double sigma, double b, double r, double x0, double y0, double z0);

double dx(double x, double y);
double dy(double x, double y, double z);
double dz(double x, double y, double z);


#endif // NEW_EDO_HEADER_H_INCLUDED
