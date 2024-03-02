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
#include "testing.h"
#include "charts.h"

using namespace std;


int main() {
    
    string header = "Countries";
    string units = "Population in millions";
    string file = "/Users/seb/Desktop/C++/MyLib developing/MyLib/test.html";
    vector<string> labels({"España","México","Reino Unido"});
    vector<double> values({47.42, 126.7, 67.33});
    
    /*
    double r;
    cout << "normcdf(1.96)=" << normcdf(1.96) << "\n";
    cout << "norminv(0.975)=" << norminv(0.975) << "\n";
    cout << "Give me a radius:\n";
    cin >> r;
    cout << "Area of your circle: " << area(r) << "\n";
    cout << "Circumference of your circle: " << circumference(r) << "\n";
    */
    //testMatlib();
    //testGeometry();
    //testCharts();
    //testUsageExamples();
    
    pieChart(header, units, file, labels, values);
    
    return 0;
}
