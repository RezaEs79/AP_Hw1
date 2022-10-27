#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#include "gtest/gtest.h"

using Data = std::vector<std::vector<double>>;

namespace regression {
Data read_database(std::string);
double hypothesis(std::vector<double>, std::vector<double>);
std::vector<double> update(Data, std::vector<double>, double);
double cost_function(Data, std::vector<double>);
std::vector<double> linear_regression(Data, std::vector<double>, double);
}