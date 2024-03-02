//
//  geometry.cpp
//  MyLib
//
//  Created by Sebastian Cordoba on 31/01/2024.
//

#include "geometry.h"
#include "stdafx.h"
using namespace std;

static const double PI = 3.141592653589793;

double circumference(double r) {
    if (r < 0) {
        cout << "Radius must be non-negative.\n";
        return 0;
    } else {
        double circumference = 2 * PI * r;
        return circumference;
    }
}

double area(double r) {
    if (r < 0) {
        cout << "Radius must be non-negative.\n";
        return 0;
    } else {
        double area = PI * r * r;
        return area;
    }
}


static void testCircumference() {
    //test bounds
    ASSERT(circumference(2.0)>0);
    ASSERT(circumference(0.0) = 0.0);
    //test increasing
    ASSERT(circumference(2)<circumference(3));
    //test extreme value
    ASSERT_APPROX_EQUAL(1e-10, 0.0, 0.0001);
    //known value
    ASSERT_APPROX_EQUAL(circumference(3), 6.0*PI, 0.001);
}

static void testArea() {
    //bounds
    ASSERT(area(0.0)=0.0);
    ASSERT(area(1.0)>0);
    //increasing
    ASSERT(area(2)<area(3));
    //extreme value
    ASSERT_APPROX_EQUAL(1e-10, 0.0, 0.0001);
    //known value
    ASSERT_APPROX_EQUAL(area(3), 9.0*PI, 0.001);
}

void testGeometry() {
    setDebugEnabled(true);
    TEST(testCircumference);
    setDebugEnabled(true);
    TEST(testArea);
}

