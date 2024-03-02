//
//  charts.cpp
//  chapter_7_exercises
//
//  Created by Sebastian Cordoba on 06/02/2024.
//

#include "charts.h"
#include "stdafx.h"

using namespace std;

static void topBoilerPlate(ostream& out) {
    
    out << "<html>\n";
    out << "<head>\n";
    out << "<script type=\"text/javascript\" src=\"https://www.gstatic.com/charts/loader.js\"></script>\n";
    out << "<script type=\"text/javascript\">\n";
    out << "google.charts.load('current', {'packages':['corechart', 'line']});\n";
    out << "google.charts.setOnLoadCallback(drawChart);\n";
    out << "\n";
    out << "function drawChart() {\n";
    out << "\n";
    out << "var data = new google.visualization.DataTable();\n";
    out << "data.addColumn('number', 'x');\n";
    out << "data.addColumn('number', 'y');\n";
    out << "data.addRows([\n";
    
}

static void writeDataOfLineChart(ostream& out,
                                 const vector<double>& labels,
                                 const vector<double>& values) {
    
    //out << "['" << header << "', '" << units << "'],\n";
    
    int nLabels = (int)labels.size();
    for (int i=0; i<nLabels; i++) {
        double label = labels[i];
        double value = values[i];
        out << "[" << label << ", " << value << "]";
        if (i != nLabels - 1) {
            out << ",";
        }
        out << "\n";
    }
    out << "]);\n";
    out << "\n";
    
}

static void bottomBoilerPlate(ostream& out) {
    
    out << "var options = {\n";
    out << "hAxis: { title: 'x-Axis' },\n";
    out << "vAxis: { title: 'y-Axis' },\n";
    out << "};\n";
    out << "\n";
    out << "var chart = new google.visualization.LineChart(document.getElementById('chart_div'));\n";
    out << "\n";
    out << "chart.draw(data, options);\n";
    out << "}\n";
    out << "</script>\n";
    out << "</head>\n";
    out << "<body>\n";
    out << "<div id=\"chart_div\" style=\"width: 900px; height: 500px;\"></div>\n";
    out << "</body>\n";
    out << "</html>\n";
    
}

/*
static void testLineChartData() {
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
    writeDataOfLineChart(out, labels, vals);
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
*/

void lineChart(const string& file,
               const vector<double>& labels,
               const vector<double>& values) {
    
    ofstream out;
    out.open(file.c_str());
    topBoilerPlate(out);
    writeDataOfLineChart(out, labels, values);
    bottomBoilerPlate(out);
    out.close();
    
}

// Below is a slight modification to above which creates a
// column chart instead:

static void bottomBoilerPlate2(ostream& out) {
    
    out << "var options = {\n";
    out << "title: 'Histogram',\n";
    out << "hAxis: { title: 'x-Axis' },\n";
    out << "vAxis: { title: 'y-Axis' },\n";
    out << "};\n";
    out << "\n";
    out << "var chart = new google.visualization.ColumnChart(document.getElementById('chart_div'));\n";
    out << "\n";
    out << "chart.draw(data, options);\n";
    out << "}\n";
    out << "</script>\n";
    out << "</head>\n";
    out << "<body>\n";
    out << "<div id=\"chart_div\" style=\"width: 900px; height: 500px;\"></div>\n";
    out << "</body>\n";
    out << "</html>\n";
    
}

void columnChart(const string& file,
               const vector<double>& labels,
               const vector<double>& values) {
    
    ofstream out;
    out.open(file.c_str());
    topBoilerPlate(out);
    writeDataOfLineChart(out, labels, values);
    bottomBoilerPlate2(out);
    out.close();
    
}

//void testChart() {
  //  TEST(testLineChartData);
//}
