//
//  charts.h
//  chapter_7_exercises
//
//  Created by Sebastian Cordoba on 06/02/2024.
//

#pragma once


#include <stdio.h>
#include "stdafx.h"

//void testChart();

void lineChart(const std::string& file,
               const std::vector<double>& labels,
               const std::vector<double>& values);

void columnChart(const std::string& file,
                 const std::vector<double>& labels,
                 const std::vector<double>& values);
