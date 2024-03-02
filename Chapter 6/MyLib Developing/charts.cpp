//
//  charts.cpp
//  MyLib
//
//  Created by Sebastian Cordoba on 01/02/2024.
//

#include "charts.h"
#include "stdafx.h"
using namespace std;


static void writeTopBoilerPlateOfPieChart(ostream& out) {
    
    out << "<html>\n";
    out << "<head>\n";
    out << "<script type=\"text/javascript\" src=\"https://www.gstatic.com/charts/loader.js\"></script>\n";
    out << "<script type=\"text/javascript\">\n";
    out << "google.charts.load('current', {'packages':['corechart']});\n";
    out << "google.charts.setOnLoadCallback(drawChart);\n";
    out << "\n";
    out << "function drawChart() {\n";
    out << "\n";
    
}

static void writeFixedPieChartData(ostream& out) {
    
    out << "var data = google.visualization.arrayToDataTable([\n";
    out << "['Task', 'Hours per Day'],\n";
    out << "['Work',     1],\n";
    out << "['Eat',      2],\n";
    out << "['Fuck',    10],\n";
    out << "['Commute',  2],\n";
    out << "['Watch TV', 2],\n";
    out << "['Sleep',    7]\n";
    out << "]);\n";
    out << "\n";
    
}

static void writeBottomBoilerPlateOfPieChart(ostream& out) {
    
    out << "var options = {\n";
    out << "title: 'My Daily Activities'\n";
    out << "};\n";
    out << "\n";
    out << "var chart = new google.visualization.PieChart(document.getElementById('piechart'));\n";
    out << "\n";
    out << "chart.draw(data, options);\n";
    out << "}\n";
    out << "</script>\n";
    out << "</head>\n";
    out << "<body>\n";
    out << "<div id=\"piechart\" style=\"width: 900px; height: 500px;\"></div\n";
    out << "</body>\n";
    out << "</html>\n";

}

static void writeDataOfPieChart(const string& header,
                                const string& units,
                                ostream& out,
                                const vector<string>& labels,
                                const vector<double>& values) {
        
    out << "var data = google.visualization.arrayToDataTable([\n";
    out << "['" << header << "', '" << units << "'],\n";
    int nLabels = (int)labels.size();
    for (int i=0; i<nLabels; i++) {
        string label = labels[i];
        double value = values[i];
        out << "['" << label << "', " << value << "]";
        if (i != nLabels - 1) {
            out << ",";
        }
        out << "\n";
    }
    out << "]);\n";
    out << "\n";
}

static void testPieChartData() {
    string header = "A header" ;
    string units =  "Some units";
    stringstream out;
    vector<string> labels(3);
    vector<double> vals(3);
    
    for (int i=0; i<3; i++) {
        stringstream ss;
        ss << "A Label " << i;
        labels[i] = ss.str();
        //INFO(labels[i]);
        vals[i] = (double)i;
    }
    writeDataOfPieChart(header, units, out, labels, vals);
    string asString = out.str();
    
    stringstream expected;
    expected << "var data = google.visualization.arrayToDataTable([\n";
    expected << "['" << header << "', '" << units << "'],\n";
    expected << "['A label 0', 0],\n";
    expected << "['A label 1', 1],\n";
    expected << "['A label 2', 2]\n";
    expected << "]);\n";
    expected << "\n";
    string expectedStr = expected.str();
    ASSERT(asString == expectedStr);

}

static void testFixedPieChart() {
    ofstream out;
    out.open("/Users/seb/Desktop/C++/MyLib developing/MyLib/FixedPieChart.html");
    writeTopBoilerPlateOfPieChart(out);
    writeFixedPieChartData(out);
    writeBottomBoilerPlateOfPieChart(out);
    out.close();
}

void pieChart(const string& header,
              const string& units,
              const string& file,
              const vector<string>& labels,
              const vector<double>& values) {
    
    ofstream out;
    out.open(file.c_str());
    writeTopBoilerPlateOfPieChart(out);
    writeDataOfPieChart(header, units, out, labels, values);
    writeBottomBoilerPlateOfPieChart(out);
    out.close();
    
}

void testCharts() {
    TEST(testFixedPieChart);
    TEST(testPieChartData);
}

