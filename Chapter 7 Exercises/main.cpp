//
//  main.cpp
//  chapter_7_exercises
//
//  Created by Sebastian Cordoba on 01/02/2024.
//

#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include <iostream>
#include "maincode.h"
#include "charts.h"
#include "matlib copy.h"

using namespace std;


int main() {
    //testAll();
    //testChart();
    
    /*
    
    string file1 = "/Users/seb/Desktop/C++/Chapter 7/chapter_7_exercises/lineChart.html";
    string file2 = "/Users/seb/Desktop/C++/Chapter 7/chapter_7_exercises/callOption.html";
    string directory = "/Users/seb/Desktop/Web_Scraper/VSCode Projects/Time Series Classifier/AAPL_prices copy.json";

    vector<double> prices = stockHighPrices(directory);
    
    vector<double> callOption;
    
    for (int i=0; i<(int)prices.size(); i++) {
        callOption.push_back(euroCallBlackScholes(0.2, 1.0, 100, prices[i], 0.05));
        cout << callOption[i] << "\n";
    }
    
    */
    
    //lineChart(file2, prices, callOption);
    
    /*
    vector<double> xcoords;
    vector<double> ycoords;
    int n = 10000;
    
    for (int i=-n; i<=n; ++i) {
        xcoords.push_back(i);
    //}
    
    for (int i=-n; i<=n; ++i) {
        ycoords.push_back(i*i);
    }
    
    
    
    lineChart(file1, xcoords, ycoords);
    */
    
    string histogram = "/Users/seb/Desktop/histogram_test.html";
    
    vector<double> values = randn(30000);
    
    hist(histogram, values, 30);
    
}
    
