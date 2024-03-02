//
//  main.cpp
//  MyLib
//
//  Created by Sebastian Cordoba on 31/01/2024.
//

//angled brackets means the given file won't have changed. Slightly faster.
//quotations means the file may have changed.

#include <iostream>
#include "matlib.h"
#include "geometry.h"

using namespace std;


int main() {
    double r;
    cout << "normcdf(1.96)=" << normcdf(1.96) << "\n";
    cout << "norminv(0.975)=" << norminv(0.975) << "\n";
    cout << "Give me a radius:\n";
    cin >> r;
    cout << "Area of your circle: " << area(r) << "\n";
    cout << "Circumference of your circle: " << circumference(r) << "\n";
    
    return 0;
}
