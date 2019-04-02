#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "utility.h"
#include "centroide.h"

struct centroide_s
{
    double x;
    double y;
};

void allocaCentroide(Centroide *centroide, double x, double y)
{
    *centroide = malloc(sizeof(struct centroide_s));

    (*centroide)->x = x;
    (*centroide)->y = y;
}

void stampaCentroide(Centroide c)
{
    printf("Centroide: X = %lf, Y = %lf\n", c->x, c->y);
}

double distanzaCentroide(Centroide c1, Centroide c2)
{
    double deltaX = c2->x - c1->x;
    double deltaY = c2->y - c1->y;

    double doubleDist = pow(deltaX, 2) + pow(deltaY, 2);

    return sqrt(doubleDist);
}

void liberaCentroide(Centroide centroide)
{
    free(centroide);
}