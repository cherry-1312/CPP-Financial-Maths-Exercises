//
//  geometry.cpp
//  MyLib
//
//  Created by Sebastian Cordoba on 31/01/2024.
//

#include "geometry.h"
#include "stdafx.h"

static const double PI = 3.141592653589793;

double circumference(double r) {
    double circumference = 2 * PI * r;
    return circumference;
}

double area(double r) {
    double area = PI * r * r;
    return area;
}
